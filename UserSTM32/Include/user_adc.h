/**
  ******************************************************************************
  * Ten Tep		:		    user_adc.h
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  * Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:       	Khai bao cac ham su dung de dieu khien ADC.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y		:			Disable cac ham khong su dung den				
  *
  *
  * 
  ******************************************************************************
  */
#ifndef __USER_ADC_H
#define __USER_ADC_H
#include 	"main.h"

//++++++++++++++++++++++++++++  ADC1   ++++++++++++++++++++++++++++
//#define ADC1_DR_ADDR    ((u32)0x4001244C)	
#define ADC1_DR_ADDR    ((u32)(ADC1_BASE+0x4C))
#define ADC2_DR_ADDR	((u32)(ADC2_BASE+0x4C))
#define ADC3_DR_ADDR	((u32)(ADC3_BASE+0x4C))				  
/********************************************************/
void ADC1_Configuration(void);
void ADC2_Configuration(void);
void ADC3_Configuration(void);
uint16_t read_adc(ADC_TypeDef* ADCx,u8 ADC_Channel);
#endif
