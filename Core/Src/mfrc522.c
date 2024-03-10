/*
 * mfrc522.c
 *
 *  Created on: Mar 6, 2024
 *      Author: trand
 */


#include "mfrc522.h"

void TM_MFRC522_Init(void){
	TM_MFRC522_Reset();

	TM_MFRC522_WriteRegister(MFRC522_REG_T_MODE, 0x8D);
	TM_MFRC522_WriteRegister(MFRC522_REG_T_PRESCALER, 0x3E);
	TM_MFRC522_WriteRegister(MFRC522_REG_T_RELOAD_L, 30);
	TM_MFRC522_WriteRegister(MFRC522_REG_T_RELOAD_H, 0);
}


TM_MFRC522_Status_t TM_MFRC522_Check(uint8_t* id) {

}

TM_MFRC522_Status_t TM_MFRC522_Compare(uint8_t* CardID, uint8_t* CompareID) {

}

void TM_MFRC522_WriteRegister(uint8_t addr, uint8_t value) {
    // CS low
    MFRC522_CS_LOW;

    TM_SPI_Send((addr << 1) & 0x7E);  // Address with write bit
    TM_SPI_Send(value);  // Data to write

    // CS high
    MFRC522_CS_HIGH;
}

uint8_t TM_MFRC522_ReadRegister(uint8_t addr) {
    uint8_t val;

    MFRC522_CS_LOW; //CS LOW
    // Send a command to read the specified register
    TM_SPI_Send(((addr << 1) & 0x7E) | 0x80);
    // Read the value from the register using SPI
    val = TM_SPI_Send(0xFF);
    MFRC522_CS_HIGH;  //CS HIGH

    // Return the read value from the register
    return val;
}

void TM_MFRC522_SetBitMask(uint8_t reg, uint8_t mask){
	uint8_t tmp;
	tmp = TM_MFRC522_ReadRegister(reg);
	TM_MFRC522_WriteRegister(regs, tmp);
}

void TM_MFRC522_ClearBitMask(uint8_t reg, uint8_t mask){
	uint8_t tmp;
	tmp = TM_MFRC522_ReadRegister(reg);
	TM_MFRC522_WriteRegister(reg, TM_MFRC522_ReadRegister(reg) & (~mask));
}

/**
 * Turns the antenna on by enabling pins TX1 and TX2.
 * After a reset these pins are disabled.
 */
void TM_MFRC522_AntennaOn(void){
	uint8_t tmp;
	tmp = TM_MFRC522_ReadRegister(MFRC522_REG_TX_CONTROL);
	if(!(tmp & 0x03)){
		TM_MFRC522_SetBitMask(MFRC522_REG_TX_CONTROL,tmp | 0x03);
	}
}

void TM_MFRC522_AntennaOff(void) {
	TM_MFRC522_ClearBitMask(MFRC522_REG_TX_CONTROL, 0x03);
}

void TM_MFRC522_Reset(void) {
	TM_MFRC522_WriteRegister(MFRC522_REG_COMMAND, PCD_SOFTRESET);
}

