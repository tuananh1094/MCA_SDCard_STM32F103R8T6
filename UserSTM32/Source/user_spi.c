#include "user_spi.h"

void SPI1_Configuration(void) 
{ 
	SPI_InitTypeDef   SPI_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Enable Clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	/*Cai dat GPIO*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				// SPI_CS
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_7;	// SPI_SCK, SPI_MOSI
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				// SPI_MISO
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Cai dat cac thong so cau hinh SPI1 */ 
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
	// Chon master - slaver  
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;						   
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;					   
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;						   
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;						   
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	//Chon so chia tan so  
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; 
	//Chon kieu truyen du lieu  
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   
	SPI_InitStructure.SPI_CRCPolynomial = 7;							   
	SPI_Init(SPI1, &SPI_InitStructure);

	/* SPI1 Enable*/  
	SPI_Cmd(SPI1,ENABLE);
}
//unsigned char SPI_WriteByte(SPI_TypeDef* SPIx,unsigned char data) 
//{ 
//	unsigned char Data = 0; 
//	while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_TXE)==RESET); 
//	SPI_I2S_SendData(SPIx,data); 
//	while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_RXNE)==RESET); 
//	Data = SPI_I2S_ReceiveData(SPIx); 
//	return Data; 
//}  

void SPI_WriteByte(SPI_TypeDef* SPIx,unsigned char data)
{
	while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_TXE)==RESET); 
	SPI_I2S_SendData(SPIx,data);
}

u8 SPI_ReadByte(SPI_TypeDef* SPIx)
{
	u8 Data = 0;
	while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_RXNE)==RESET); 
	Data = SPI_I2S_ReceiveData(SPIx); 
	return Data; 
}





