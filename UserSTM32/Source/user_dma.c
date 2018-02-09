/**
  ******************************************************************************
  * Ten Tep		:		    user_dma.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  * Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:       	Dinh nghia cac ham cau hinh khoi DMA.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y		:			DMA_PeripheralBaseAddr		: Dia chi DMA ngoai vi				
  *							DMA_MemoryBaseAddr			: Dia chi DMA bo nho luu tru
  *							DMA_DIR						:
  *								- DMA_DIR_PeripheralSRC				--> Ngoai vi la nguon truyen du lieu
  *								- DMA_DIR_PeripheralDST				-->	Ngoai vi la dich truyen du lieu
  *							DMA_PeripheralDataSize		: 
  *								- DMA_PeripheralDataSize_HalfWord  	-->	1/2 Word
  *								- DMA_PeripheralDataSize_Byte		-->	1 Byte
  *								- DMA_PeripheralDataSize_Word;		-->	1 Word
  *							DMA_Mode					:
  *								- DMA_Mode_Circular
								- DMA_Mode_Normal
							DMA_Priority				:
								- DMA_Priority_VeryHigh				-->Muc uu tien rat cao
								- DMA_Priority_High					-->Muc uu tien cao
								- DMA_Priority_Medium 				-->Muc uu tien binh thuong
								- DMA_Priority_Low 					-->Muc uu tien thap
  *
  * 
  ******************************************************************************
  */
#include "user_dma.h"

void DMA1_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;
/*****************************Cau Hinh DMA1*****************************/
	//Kich hoat Clock cho DMA
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	//RESET Kenh DMA su dung
	DMA_DeInit(DMA1_Channel1);
	//chon dia chi ngoai vi su dung
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_ADDR;			         
	//chon dia chi bo nho lua tru du lieu
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC1_ConvertedValue;	            
	// chon huong truyen du lieu
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	// Chon kich thuoc bo dem DMA tinh theo word
	DMA_InitStructure.DMA_BufferSize = 1;
	// Enable - Disable chuc nang tu dong tang dia chi ngoai vi
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	// Enable - Disable chuc nang tu dong tang dia chi bo nho
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	//Chon kich thuoc du lieu cua ngoai vi
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	// Chon kich thuoc du lieu cua bo nho
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;	
	// Chon che do cho DMA
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	//Chon Muc Uu tien
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	//Enable - Disable che do truyen du lieu tu bo nho den bo nho
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	//Cau hinh kenh DMA
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);    
	//Enable - Disable Ngat hoan thanh truyen DMA
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TC, ENABLE);
	//Enable - Disable Ngat hoan thanh truyen 1/2 du lieu DMA
	DMA_ITConfig(DMA1_Channel1,DMA_IT_HT, ENABLE);
	//Enable - Disable ngat hoan truyen DMA bi loi
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TE, ENABLE);
	//Kich hoat DMA1
	DMA_Cmd(DMA1_Channel1, ENABLE);
}
