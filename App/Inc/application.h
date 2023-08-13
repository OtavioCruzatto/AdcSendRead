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
	CMD_TEMPORIZATION_3 = 0x30
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
} Application;

void applicationInit(Application *application, GPIO_TypeDef* ledPort, uint16_t ledPin);
void applicationDecodeCommand(Application *application);
void applicationExecuteBlinkLed(Application *application);
uint32_t applicationGetBlinkDelay(Application *application);
void applicationSetCommand(Application *application, uint8_t command);
void applicationSetDecodeStatus(Application *application, Bool status);
Bool applicationGetDecodeStatus(Application *application);
void applicationSetData(Application *application, uint8_t *data, uint8_t dataLength);

#endif /* INC_APPLICATION_H_ */
