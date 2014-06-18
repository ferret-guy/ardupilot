/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#ifndef __AP_PIXY_H__
#define __AP_PIXY_H__
#endif

#include <AP_Param.h>

#define PIXY_SYNC 0xAA55
#define PIXY_BYTES 16
#define PIXY_WORDS 8
#define PIXY_ADDRESS 0x54

#define PIXY_NO_ERROR 0
#define PIXY_ERROR_I2C_NOSYNC 1
#define PIXY_ERROR_I2C_CHECKSUM 2
#define PIXY_ERROR_I2C_SEMAPHORE 3
#define PIXY_ERROR_BOUNDS 4
#define PIXY_ERROR_RERUN 5

#define PIXY_SIGNATURE_MAX 7
#define PIXY_SIGNATURE_MIN 1
#define PIXY_X_MAX 640
#define PIXY_X_MIN 0
#define PIXY_Y_MAX 400
#define PIXY_Y_MIN 0
#define PIXY_W_MAX 255
#define PIXY_W_MIN 0
#define PIXY_H_MAX 255
#define PIXY_H_MIN 0

#define PIXY_X_CENTER 160
#define PIXY_Y_CENTER 100

typedef struct {
	uint16_t sig;
	uint16_t x;
	uint16_t y;
	uint16_t w;
	uint16_t h;
} pixyBlock;

class AP_Pixy
{
	public:
	bool readPixyData();
	pixyBlock getPixyBlock();
	bool blockAvailable;
	int pixyError;
	uint16_t signature;
	uint16_t x;
	int16_t x_rel;
	uint16_t abs_x_rel;
	uint16_t y;
	int16_t y_rel;
	uint16_t abs_y_rel;
	uint16_t w;
	uint16_t h;
	uint8_t a_bytes[PIXY_BYTES+1];
	uint16_t a_words[PIXY_WORDS+1];
	uint8_t *p_bytes = a_bytes;
	uint16_t *p_words = a_words;
	private:
	uint16_t newWord;
	uint16_t checksum;
	bool checkChecksum();
	bool checkBounds();
	bool checkZeros();
	uint16_t assembleWord(uint8_t lowByte, uint8_t highByte);
	bool bytesToWords(uint8_t* bytes, uint16_t* words);
};