/**
  ******************************************************************************
  * Ten Tep		:		    user_exti.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:	        Dinh nghia ham cau hinh ngat ngoai.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y		:			Disable cac ham khong su dung				
  *							EXTI_Mode:
  *								- EXTI_Mode_Interrupt	: Che do xay ra ngat.
  *								- EXTI_Mode_Event		: Che do xay ra su kien.
  *							EXTI_Trigger :
  *								- EXTI_Trigger_Falling	: Khi co canh xuong.
  *								- EXTI_Trigger_Rising	: Khi co canh len.
  *								- EXTI_Trigger_Rising_Falling: Khi co canh len hoac canh xuong.
	*							Cach cau hinh:
	*								- Cau hinh Input GPIO
	*								- Cau hinh duong ngat trong user_nvic.c
	*								- Cau hinh ngat trong user_exti.c
	*								- Viet chuong trinh con phuc vu ngat trong user_interrupt.c
  *
  * 
  ******************************************************************************
  */
#include "user_exti.h"
void EXTI_Configuration(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	// Set lai EXT
	EXTI_DeInit();
	/*===========================================
		Chon PIN su dung la duong ngat.
		GPIO_PortSourceGPIOx :x la (A..G).
		GPIO_PinSourcex 	 :x la (0..15).
	 ============================================*/
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource13);
	// Chon che do.
	EXTI_InitStructure.EXTI_Mode 		= EXTI_Mode_Interrupt;
	// Chon duong ngat.
	EXTI_InitStructure.EXTI_Line 		= EXTI_Line13;							/* Select EXTI_Linex x[0..15] */
	// Chon kieu kich thich
	EXTI_InitStructure.EXTI_Trigger 	= EXTI_Trigger_Falling;
	//Enable duong ngat.
	EXTI_InitStructure.EXTI_LineCmd 	= ENABLE;
	//Cau hinh ngat.
	EXTI_Init(&EXTI_InitStructure);	
}
