/**
  ******************************************************************************
  * Ten Tep		:		    user_usart.h
  * Tac Gia		:	  		Nguyen Quy Nhat
	* Cong Ty		:				MinhHaGroup
	*	Website 	:				MinhHaGroup.com
  * Phien Ban	:				V1.0.0
  * Ngay			:    		31-07-2012
  * Tom Tat   :       Khai bao cac ham duoc su dung de dieu khien khoi USART.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y			:				
  *
  *
  * 
  ******************************************************************************
  */
#ifndef __USER_USART_H
#define __USER_USART_H

//#include "main.h"
#include "stm32f10x.h"

#define BUFF_SIZE		60

void USART1_Configuration(u32 baudrate);
void USART2_Configuration(USART_TypeDef* USARTx);
void USART_SendChar(USART_TypeDef* USARTx, u8 data);
void USART_SendString(USART_TypeDef* USARTx, char*str);
/**************************************************************/
#endif
