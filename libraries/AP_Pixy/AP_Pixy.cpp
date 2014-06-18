/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include <AP_Math.h>
#include <AP_Common.h>
#include <AP_Pixy.h>
#include <AP_HAL.h>

extern const AP_HAL::HAL& hal;

uint16_t AP_Pixy::assembleWord(uint8_t lowByte, uint8_t highByte){
	//uint16_t newWord;
	newWord = highByte << 8;
	newWord += lowByte;
	return newWord;
}

bool AP_Pixy::bytesToWords(uint8_t* bytes, uint16_t* words){
	for(int i=1;i<=PIXY_WORDS;i++){
		words[i]=assembleWord(bytes[(i*2)-2],bytes[(i*2)-1]);
	}
	return true;
}

bool AP_Pixy::checkChecksum(){
	bool rstate = false;
	if(checksum==(signature+x+y+w+h)){
		rstate = true;
	}
	return rstate;
}


bool AP_Pixy::checkBounds(){
	//bool rstate = false;
	//if( (signature>=PIXY_SIGNATURE_MIN && signature<=PIXY_SIGNATURE_MAX) && (x>=PIXY_X_MIN && x<=PIXY_X_MAX) && (y>=PIXY_Y_MIN && y<=PIXY_Y_MAX) && (w>=PIXY_W_MIN && w<=PIXY_W_MAX) && (h>=PIXY_H_MIN && h<=PIXY_H_MAX) ){
	//	rstate = true;
	//}
	//return rstate;
	return true;
}

// deprecated
bool AP_Pixy::checkZeros(){
	//bool rstate = true;
	//for(int i=0;i<PIXY_BYTES;i++){
	//	if(p_bytes[i]!=0){
	//		rstate = false;
	//	}
	//}
	//return rstate;
	return false;
	
}

bool AP_Pixy::readPixyData(){
	AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();
	if (i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)){
		hal.i2c->read(PIXY_ADDRESS,PIXY_BYTES,p_bytes);
		bytesToWords(p_bytes,p_words);
		if(p_words[1]==PIXY_SYNC && p_words[2]==PIXY_SYNC){
			checksum = p_words[3];
			signature = p_words[4];
			x = p_words[5];
			x_rel = x-PIXY_X_CENTER;
			//abs_x_rel = abs(x_rel);
			y = p_words[6];
			y_rel = y-PIXY_Y_CENTER;
			//abs_y_rel = abs(y_rel);
			w = p_words[7];
			h = p_words[8];
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
		}else if(checkZeros()){
			pixyError = PIXY_NO_ERROR;
			blockAvailable = false;
		}else{
			pixyError = PIXY_ERROR_I2C_NOSYNC;
			blockAvailable = false;
		}
		i2c_sem->give();
	}else{
		pixyError = PIXY_ERROR_I2C_SEMAPHORE;
		blockAvailable = false;
	}
	return blockAvailable;
}

//unused
/*pixyBlock AP_Pixy::getPixyBlock(){
	pixyBlock rblock;
	rblock.sig = signature;
	rblock.x = x;
	rblock.y = y;
	rblock.w = w;
	rblock.h = h;
	return rblock;
}*/