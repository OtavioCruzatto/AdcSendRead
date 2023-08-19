/*
 * application.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Otavio
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

#include "main.h"

#define QTY_DATA_BYTES	25

typedef enum APP_COMMANDS
{
	CMD_TEMPORIZATION_1 = 0x10,
	CMD_TEMPORIZATION_2 = 0x20,
	CMD_TEMPORIZATION_3 = 0x30,
	CMD_SET_SEND_ADC_READ_STATUS = 0x40
} AppCommands;

typedef struct
{
	uint32_t blinkDelay;
	Bool blinkStatus;
	Bool decodeCommandStatus;
	uint8_t command;
	GPIO_TypeDef* ledPort;
	uint16_t ledPin;
	uint8_t data[QTY_DATA_BYTES];
	uint8_t dataLenght;

	Bool adcReadComplete;
	Bool enableSendAdcRead;
	uint16_t adcValue;
} Application;

void applicationInit(Application *application, GPIO_TypeDef* ledPort, uint16_t ledPin);
void applicationDecodeCommand(Application *application);
void applicationExecuteBlinkLed(Application *application);
uint32_t applicationGetBlinkDelay(Application *application);
void applicationSetCommand(Application *application, uint8_t command);
void applicationSetDecodeStatus(Application *application, Bool status);
Bool applicationGetDecodeStatus(Application *application);
void applicationSetData(Application *application, uint8_t *data, uint8_t dataLength);
void applicationSetAdcReadCompleteStatus(Application *application, Bool status);
Bool applicationGetAdcReadCompleteStatus(Application *application);
Bool applicationGetEnableSendAdcRead(Application *application);
void applicationSetAdcValue(Application *application, uint16_t value);
uint16_t applicationGetAdcValue(Application *application);

#endif /* INC_APPLICATION_H_ */
