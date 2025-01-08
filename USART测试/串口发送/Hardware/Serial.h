#ifndef __SERIAL_H
#define __SERIAL_h

#include <stdio.h>

void Serial_Init(void);
void Serial_SendByte(uint8_t BYTE);
void Serial_SendArray(uint8_t *Arrary,uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number,uint8_t Length);




#endif
