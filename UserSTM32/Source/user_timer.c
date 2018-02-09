/**
  ******************************************************************************
  * Ten Tep		:		    user_timer.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:       	Dinh nghia cac ham cau hinh cho Timer.           			
  *           
  *
  ******************************************************************************
  * Chu Y		:			Disable cac ham khong su dung den.
  *							Cac timer co cac chuc nang ho tro va cau hinh khac nhau,
  *							xem chi tiet tai stm32f10x_tim.c va stm32f10x_tim.h
  *							TIM_CounterMode:
								- TIM_CounterMode_Up				--> 
								- TIM_CounterMode_Down				-->
								- TIM_CounterMode_CenterAligned1	-->
								- TIM_CounterMode_CenterAligned2	-->
								- TIM_CounterMode_CenterAligned3	-->
							TIM_ClockDivision
								- TIM_CKD_DIV1						-->
								- TIM_CKD_DIV2						-->
								- TIM_CKD_DIV4						-->
  *							
  *
  *
  * 
  ******************************************************************************
  */
#include "user_timer.h"

void  TIM1_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
//	TIM_BDTRInitTypeDef TIM3_BDTRInitStructure;
/*-------------------------------------------------------------------*/
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	TIM_DeInit(TIM1);
	TIM1_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM1_TimeBaseStructure.TIM_Prescaler = 72;
	TIM1_TimeBaseStructure.TIM_Period = 50000;
	//TIM1_TimeBaseStructure.TIM_RepetitionCounter = 1;
	TIM_TimeBaseInit(TIM1, &TIM1_TimeBaseStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM1, ENABLE);
}

void TIM2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 50000;
	TIM_InitStructure.TIM_Prescaler = 72;
	TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
	//TIM_InitStructure.TIM_RepetitionCounter
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
}

void TIM3_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 50000;
	TIM_InitStructure.TIM_Prescaler = 72;
	TIM_TimeBaseInit(TIM3, &TIM_InitStructure);
	//TIM_InitStructure.TIM_RepetitionCounter
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}
