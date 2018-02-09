/**
  ******************************************************************************
  * Ten Tep		:		    user_delay.h
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:	        Khai bao cac ham su dung de tao tre.
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
#ifndef __USER_DELAY_H
#define __USER_DELAY_H

//#include "main.h"
#include "stm32f10x.h"

/***************************************************************/ 
//Phai goi ham nay truoc khi su dung cac ham delay khac
void delay_init(uint8_t SYSCLK);
//Tao tre ms
void delay_ms(uint16_t nms);
//Tao tre us
void delay_us(uint32_t nus);
/**************************************************************/
#endif





























