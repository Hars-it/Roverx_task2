/*
 * i2c_slave.c
 *
 *  Created on: Jul 2, 2024
 *      Author: hr003
 */

#include "main.h"

extern I2C_HandleTypeDef hi2c1;

#define RxSIZE 5
uint8_t RxData[RxSIZE];
uint8_t var1, var2, var3, var4, var5;
uint8_t a, b, c, d, e;

uint8_t count = 0;

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	if (TransferDirection == I2C_DIRECTION_TRANSMIT)
	{
		HAL_I2C_Slave_Sequential_Receive_IT(hi2c, RxData, RxSIZE, I2C_FIRST_AND_LAST_FRAME);
//		HAL_I2C_Slave_Receive_IT(hi2c, RxData, RxSIZE);
	}
	else
	{
		Error_Handler();
	}
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	count++;
	if (hi2c->Instance == I2C1) {

		var1 = RxData[0];
		var2 = RxData[1];
		var3 = RxData[2];
		var4 = RxData[3];
		var5 = RxData[4];


		void incrementVar1() {
		  var1++;
		}

		void incrementVar2() {
		  var2++;
		}

		void incrementVar3() {
		  var3++;
		}

		void incrementVar4() {
		  var4++;
		}

		void incrementVar5() {
		  var5++;
		}

		incrementVar1();
		incrementVar2();
		incrementVar3();
		incrementVar4();
		incrementVar5();

	}
}



void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(hi2c);
}






