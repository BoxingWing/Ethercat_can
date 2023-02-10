/*
 * Motor_Untilities.h
 *
 *  Created on: 2023年2月9日
 *      Author: kboxi
 */

#ifndef INC_MOTOR_UNTILITIES_H_
#define INC_MOTOR_UNTILITIES_H_

#include "stm32h7xx_hal.h"
#include "Global_var.h"

extern union Byte8 byte_8;
extern union Byte2 byte_2_reply;


void motor_enable(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_pd0(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_pvt0(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_pd(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id);

void motor_pvt(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id);

void motor_es(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_steer_init(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_steer_enable(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id);

void motor_null(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_current(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int16_t data_in, uint32_t Id);

void motor_cmd(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint8_t cmd, uint32_t Id);

void motor_data(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint8_t cmd, uint32_t Id);

void motor_get_sglPos(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_get_mulPos(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id);

void motor_decode_pvt(uint8_t* data, float_t* pos, float_t* vel, float_t* tor);

void motor_decode_sglPos(uint8_t* data, float_t * sglPos);

void motor_decode_mulPos(uint8_t* data, float_t * mulPos);

void motor_decode_cur(uint8_t* data, float_t* pos, float_t* vel, float_t* tor);

void motor_vel(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int32_t data_in, uint32_t Id);



float_t sign_dbl(float_t data);

#endif /* INC_MOTOR_UNTILITIES_H_ */
