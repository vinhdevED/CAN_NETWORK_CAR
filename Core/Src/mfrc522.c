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

/*This function performs a reset procedure for the MFRC522 module
 *
 */
void TM_MFRC522_Reset(void) {
	TM_MFRC522_WriteRegister(MFRC522_REG_COMMAND, PCD_RESETPHASE);
}

TM_MFRC522_Status_t TM_MFRC522_Check(uint8_t* id) {

}

TM_MFRC522_Status_t TM_MFRC522_Compare(uint8_t* CardID, uint8_t* CompareID) {

}

void TM_MFRC522_WriteRegister(uint8_t add, uint8_t val){

}

uint8_t TM_MFRC522_ReadRegister(uint8_t addr) {

}
