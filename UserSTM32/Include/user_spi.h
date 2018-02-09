#ifndef _USER_SPI_H_
#define _USER_SPI_H_

#include "main.h"

void SPI1_Configuration(void) ;
void SPI_WriteByte(SPI_TypeDef* SPIx,unsigned char data);
u8 SPI_ReadByte(SPI_TypeDef* SPIx);

#endif


