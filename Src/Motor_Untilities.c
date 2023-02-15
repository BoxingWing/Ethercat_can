#include "Motor_Untilities.h"

void motor_enable(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	data_buffer[0] = 0xff;
	data_buffer[1] = 0xff;
	data_buffer[2] = 0xff;
	data_buffer[3] = 0xff;
	data_buffer[4] = 0xff;
	data_buffer[5] = 0xff;
	data_buffer[6] = 0xff;
	data_buffer[7] = 0xfc;
}

void motor_pd0(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	data_buffer[0] = 0xaf;
	data_buffer[1] = 0x01;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_pvt0(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	data_buffer[0] = 0xae;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_pd(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_8.udata = data_in;

	data_buffer[0] = 0xaf;
	data_buffer[1] = 0x01;
	data_buffer[2] = byte_8.buffer[0];
	data_buffer[3] = byte_8.buffer[1];
	data_buffer[4] = byte_8.buffer[2];
	data_buffer[5] = byte_8.buffer[3];
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_pd_v2(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int16_t kp, int16_t kd, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_2_reply.udata=kp;

	data_buffer[0] = 0xaf;
	data_buffer[1] = 0x01;
	data_buffer[2] = byte_2_reply.buffer[0];
	data_buffer[3] = byte_2_reply.buffer[1];

	byte_2_reply.udata=kd;
	data_buffer[4] = byte_2_reply.buffer[0];
	data_buffer[5] = byte_2_reply.buffer[1];
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_pvt(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_8.udata = data_in;

	data_buffer[0] = 0xae;
	data_buffer[1] = 0x00;
	data_buffer[2] = byte_8.buffer[0];
	data_buffer[3] = byte_8.buffer[1];
	data_buffer[4] = byte_8.buffer[2];
	data_buffer[5] = byte_8.buffer[3];
	data_buffer[6] = byte_8.buffer[4];
	data_buffer[7] = byte_8.buffer[5];
}

void motor_pvt_v2(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, float_t desP, float_t desV, int16_t desT, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0xae;
	data_buffer[1] = 0x00;
	byte_2_reply.udata=(int16_t)(desP*100+0.5);
	data_buffer[2] = byte_2_reply.buffer[0];
	data_buffer[3] = byte_2_reply.buffer[1];
	byte_2_reply.udata=(int16_t)(desV+0.5);
	data_buffer[4] = byte_2_reply.buffer[0];
	data_buffer[5] = byte_2_reply.buffer[1];
	byte_2_reply.udata=desT;
	data_buffer[6] = byte_2_reply.buffer[0];
	data_buffer[7] = byte_2_reply.buffer[1];
}

void motor_es(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0x08;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}


void motor_steer_init(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0x02;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_steer_enable(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_8.udata = data_in;

	data_buffer[0] = 0x01;
	data_buffer[1] = 0x00;
	data_buffer[2] = byte_8.buffer[0];
	data_buffer[3] = byte_8.buffer[1];
	data_buffer[4] = byte_8.buffer[2];
	data_buffer[5] = byte_8.buffer[3];
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_null(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0x00;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_current(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int16_t data_in, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_2_reply.udata = data_in;

	data_buffer[0] = 0xa1;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0;
	data_buffer[3] = 0;
	data_buffer[4] = byte_2_reply.buffer[0];
	data_buffer[5] = byte_2_reply.buffer[1];
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_cmd(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint8_t cmd, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = (uint8_t)cmd & 0x000000ff;
	data_buffer[1] = ((uint8_t)cmd >> 2UL) & 0x000000ff;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_data(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint64_t data_in, uint8_t cmd, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;
	byte_8.udata = data_in;

	data_buffer[0] = (uint8_t)cmd & 0x000000ff;
	data_buffer[1] = ((uint8_t)cmd >> 2UL) & 0x000000ff;
	data_buffer[2] = byte_8.buffer[0];
	data_buffer[3] = byte_8.buffer[1];
	data_buffer[4] = byte_8.buffer[2];
	data_buffer[5] = byte_8.buffer[3];
	data_buffer[6] = byte_8.buffer[4];
	data_buffer[7] = byte_8.buffer[5];
}

void motor_get_sglPos(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0x94;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_get_mulPos(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	data_buffer[0] = 0x92;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = 0x00;
	data_buffer[5] = 0x00;
	data_buffer[6] = 0x00;
	data_buffer[7] = 0x00;
}

void motor_decode_pvt(uint8_t* data, float_t* pos, float_t* vel, float_t* tor)
{
	byte_2_reply.buffer[0] = data[2];
	byte_2_reply.buffer[1] = data[3];
	*pos = (float_t)byte_2_reply.udata * 0.01;
	byte_2_reply.buffer[0] = data[4];
	byte_2_reply.buffer[1] = data[5];
	*vel = (float_t)byte_2_reply.udata;
	byte_2_reply.buffer[0] = data[6];
	byte_2_reply.buffer[1] = data[7];
	*tor = (float_t)byte_2_reply.udata * 66.0 / 4096;
}

void motor_decode_sglPos(uint8_t* data, float_t * sglPos)
{
	byte_4_int32.buffer[0]=data[4];
	byte_4_int32.buffer[1]=data[5];
	byte_4_int32.buffer[2]=data[6];
	byte_4_int32.buffer[3]=data[7];

	*sglPos=(float_t)byte_4_int32.udata*0.01;
}

void motor_decode_mulPos(uint8_t* data, float_t * mulPos)
{
	/*byte_8_int64.buffer[0]=0x00;
	byte_8_int64.buffer[1]=data[1];
	byte_8_int64.buffer[2]=data[2];
	byte_8_int64.buffer[3]=data[3];
	byte_8_int64.buffer[4]=data[4];
	byte_8_int64.buffer[5]=data[5];
	byte_8_int64.buffer[6]=data[6];
	byte_8_int64.buffer[7]=data[7];*/
	byte_8_int64.buffer[0]=data[1];
	byte_8_int64.buffer[1]=data[2];
	byte_8_int64.buffer[2]=data[3];
	byte_8_int64.buffer[3]=data[4];
	byte_8_int64.buffer[4]=data[5];
	byte_8_int64.buffer[5]=data[6];
	byte_8_int64.buffer[6]=data[7];
	byte_8_int64.buffer[7]=0;
	*mulPos=(float_t)byte_8_int64.udata*0.01;
}

void motor_decode_cur(uint8_t* data, float_t* pos, float_t* vel, float_t* tor)
{
	byte_2u_reply.buffer[0] = data[6];
	byte_2u_reply.buffer[1] = data[7];
	*pos = (double_t)byte_2u_reply.udata /65535.0*360.0;
	byte_2_reply.buffer[0] = data[4];
	byte_2_reply.buffer[1] = data[5];
	*vel = (float_t)byte_2_reply.udata;
	byte_2_reply.buffer[0] = data[2];
	byte_2_reply.buffer[1] = data[3];
	*tor = (float_t)byte_2_reply.udata * 66.0 / 4096;
}

float_t sign_dbl(float_t data)
{
	if (data>0)
		return 1.0;
	else if (data<0)
		return -1.0;
	else
		return 0.0;
}

void motor_vel(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int32_t data_in, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	byte_4_int32.udata=data_in;

	data_buffer[0] = 0xa2;
	data_buffer[1] = 0x00;
	data_buffer[2] = 0x00;
	data_buffer[3] = 0x00;
	data_buffer[4] = byte_4_int32.buffer[0];
	data_buffer[5] = byte_4_int32.buffer[1];
	data_buffer[6] = byte_4_int32.buffer[2];
	data_buffer[7] = byte_4_int32.buffer[3];
}

void motor_pos(FDCAN_TxHeaderTypeDef* joint_tx, uint8_t* data_buffer, int32_t pos_in, uint16_t maxSpeed, uint32_t Id)
{
	joint_tx->DataLength = FDCAN_DLC_BYTES_8;
	joint_tx->Identifier = Id + 0x140;

	byte_4_int32.udata=pos_in;

	byte_2u_reply.udata=maxSpeed;

	data_buffer[0] = 0xa4;
	data_buffer[1] = 0x00;
	data_buffer[2] = byte_2u_reply.buffer[0];
	data_buffer[3] = byte_2u_reply.buffer[1];
	data_buffer[4] = byte_4_int32.buffer[0];
	data_buffer[5] = byte_4_int32.buffer[1];
	data_buffer[6] = byte_4_int32.buffer[2];
	data_buffer[7] = byte_4_int32.buffer[3];
}
