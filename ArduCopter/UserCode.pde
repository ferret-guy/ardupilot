/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

uint16_t assembleWord(uint8_t lowByte, uint8_t highByte){
	uint16_t newWord;
	newWord = highByte << 8;
	newWord += lowByte;
	return newWord;
}

#ifdef USERHOOK_INIT
void userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP
void userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void userhook_SuperSlowLoop()
{
	/*
	// put your 1Hz code here
	//hal.console->println_P(PSTR("I am and winrar"));
	//gcs_send_text_P(SEVERITY_LOW, PSTR("MAVlink winrar"));
	
	// get pointer to i2c bus semaphore
	AP_HAL::Semaphore* i2c_sem = hal.i2c->get_semaphore();
	uint8_t datastuff[16];
	// take i2c bus sempahore
	if (i2c_sem->take(HAL_SEMAPHORE_BLOCK_FOREVER)){
		hal.i2c->read(0x54,16,datastuff);
		if(datastuff[1]==0xAA && datastuff[0]==0x55){
			gcs_send_text_P(SEVERITY_HIGH,PSTR("A data is had"));
			//gcs_send_text_P(SEVERITY_MEDIUM,PSTR("Signature: "));
			//char buffer[50];
			//prog_char_t pixysig;
			//pixysig = sprintf(buffer, "Signature: %d",assembleWord(datastuff[4],datastuff[5]));
			//gcs_send_text_P(SEVERITY_MEDIUM,PSTR(std::to_string(assembleWord(datastuff[4],datastuff[5]))));
			uint16_t p_checksum = assembleWord(datastuff[4],datastuff[5]);
			uint16_t p_signature = assembleWord(datastuff[6],datastuff[7]);
			uint16_t p_x = assembleWord(datastuff[8],datastuff[9]);
			uint16_t p_y = assembleWord(datastuff[10],datastuff[11]);
			uint16_t p_w = assembleWord(datastuff[12],datastuff[13]);
			uint16_t p_h = assembleWord(datastuff[14],datastuff[15]);
			gcs_send_text_fmt(PSTR("Signature: %d"),p_signature);
			delay(15);
			gcs_send_text_fmt(PSTR("X:%d Y:%d W:%d H:%d"),p_x,p_y,p_w,p_h);
			delay(15);
			if(p_checksum==(p_signature+p_x+p_y+p_w+p_h)){
				gcs_send_text_fmt(PSTR("Checksum OK"));
			}
			//for(int i=0;i<16;i++){
			//	gcs_send_text_fmt(PSTR("Byte %d is: %d"),i,datastuff[i]);
			//	delay(25);
			//}
		}
		i2c_sem->give();
	}*/
	//AP_Pixy pixy = getPixy();
	//bool huehuehue = pixy.readPixyData();
	/*if(pixy.blockAvailable==true){
		gcs_send_text_fmt(PSTR("S:%d X:%d Y:%d W:%d H:%d"),pixy.signature,pixy.x,pixy.y,pixy.w,pixy.h);
		gcs_send_text_P(SEVERITY_MEDIUM,PSTR("Shit works, yo."));
		if(pixy.x<PIXY_X_CENTER){
			gcs_send_text_fmt(PSTR("Turning left %d points."),pixy.x_rel);
		}else if(pixy.x>PIXY_X_CENTER){
			gcs_send_text_fmt(PSTR("Turning right %d points."),pixy.x_rel);
		}
	}else if(pixy.pixyError!=PIXY_NO_ERROR){
		gcs_send_text_fmt(PSTR("Pixy error: %d"),pixy.pixyError);
		for(int i=1;i<=PIXY_WORDS;i++){
			gcs_send_text_fmt(PSTR("Word %d is: %d"),i,pixy.p_words[i]);
			delay(15);
		}
		for(int i=0;i<PIXY_BYTES;i++){
			gcs_send_text_fmt(PSTR("Byte %d is: %d"),i,pixy.p_bytes[i]);
			delay(15);
		}
	}*/
	//barometer.read();
}
#endif
