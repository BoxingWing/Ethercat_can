/*
 * Global_var.h
 *
 *  Created on: 2023年2月9日
 *      Author: kboxi
 */

#ifndef INC_GLOBAL_VAR_H_
#define INC_GLOBAL_VAR_H_

#include "stm32h7xx_hal.h"

union Byte8
{
	uint64_t udata;
	uint8_t buffer[8];
};
union Byte4
{
	uint32_t udata;
	uint8_t buffer[4];
};

union Byte4I
{
	int32_t udata;
	uint8_t buffer[4];
};

union Byte2u
{
	uint16_t udata;
	uint8_t buffer[2];
};

union Byte2
{
	int16_t udata;
	int8_t buffer[2];
};

union Byte8_int64
{
	int64_t udata;
	uint8_t buffer[8];
};

struct motor_info{
	float_t sgl_pos;
	float_t mul_pos;
	float_t loopNum;
	float_t vel;
	float_t tor;
	float_t sgl_pos_old;
	float_t out_Pos;
	float_t out_Vel;
	float_t out_Vel_fil;
	float_t pos_off;
	uint8_t iniReady;
	float_t ratio;
};

extern union Byte8 byte_8;
extern union Byte8 byte_8_reply;
extern union Byte8 byte_8_static;
extern union Byte8_int64 byte_8_int64;
extern union Byte2 byte_2_reply;
extern union Byte2u byte_2u_reply;
extern union Byte4 byte_4_reply;
extern union Byte4I byte_4_int32;

extern struct motor_info MF_1;

#endif /* INC_GLOBAL_VAR_H_ */
