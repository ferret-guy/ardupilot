/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_Math.h>
#include <AP_Common.h>
#include <AP_Pixy.h>
#include <AP_HAL.h>

extern const AP_HAL::HAL& hal;

uint16_t AP_Pixy::assembleWord(uint8_t lowByte, uint8_t highByte){
	uint16_t newWord;
	newWord = highByte << 8;
	newWord += lowByte;
	return newWord;
}

uint16_t* AP_Pixy::bytesToWords(uint8_t* bytes){
	uint16_t words[PIXY_WORDS];
	for(int i=0;i<PIXY_WORDS;i++){
		words[i]=assembleWord(bytes[(i*2)],bytes[(i*2)+1]);
	}
	return words;
	
}

bool AP_Pixy::checkChecksum(){
	bool rstate = false;
	if(checksum==(signature+x+y+w+h)){
		rstate = true;
	}
	return rstate;
}

bool AP_Pixy::checkBounds(){
	bool rstate = false;
	if( (signature>=PIXY_SIGNATURE_MIN && signature<=PIXY_SIGNATURE_MAX) && (x>=PIXY_X_MIN && x<=PIXY_X_MAX) && (y>=PIXY_Y_MIN && y<=PIXY_Y_MAX) && (w>=PIXY_W_MIN && w<=PIXY_W_MAX) && (h>=PIXY_H_MIN && h<=PIXY_H_MAX) ){
		rstate = true;
	}
	return rstate;
}

bool AP_Pixy::readPixyData(){
	AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();
	uint8_t datastuff[16];
	if (i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)){
		hal.i2c->read(PIXY_ADDRESS,PIXY_BYTES,datastuff);
		uint16_t* datawords;
		datawords = bytesToWords(datastuff);
		if(datawords[0]==PIXY_SYNC){
			checksum = datawords[1];
			signature = datawords[2];
			x = datawords[3];
			y = datawords[4];
			w = datawords[5];
			h = datawords[6];
			if(checkChecksum()){
				if(checkBounds()){
					pixyError = PIXY_NO_ERROR;
					blockAvailable = true;
				}else{
					pixyError = PIXY_ERROR_BOUNDS;
					blockAvailable = false;
				}
			}else{
				pixyError = PIXY_ERROR_I2C_CHECKSUM;
				blockAvailable = false;
			}
		}else{
			pixyError = PIXY_ERROR_I2C_NOSYNC;
			blockAvailable = false;
		}
	}else{
		pixyError = PIXY_ERROR_I2C_SEMAPHORE;
		blockAvailable = false;
	}
	return blockAvailable;
}

pixyBlock AP_Pixy::getPixyBlock(){
	pixyBlock rblock;
	rblock.sig = signature;
	rblock.x = x;
	rblock.y = y;
	rblock.w = w;
	rblock.h = h;
	return rblock;
}