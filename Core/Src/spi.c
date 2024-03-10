/*
 * spi.c
 *
 *  Created on: Mar 9, 2024
 *      Author: trand
 */
#include "stm32f1xx.h"

#ifndef SRC_SPI_C_
#define SRC_SPI_C_

SPI_HandleTypeDef hspi1; // Change this based on your SPI peripheral

uint8_t TM_SPI_Send(uint8_t data){
	uint8_t rxData;
	HAL_SPI_TransmitReceive(&hspi1, &data, &rxData, 1 , HAL_MAX_DELAY);
	return rxData;
}


#endif /* SRC_SPI_C_ */
