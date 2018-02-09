/**
  ******************************************************************************
  * Ten Tep          :     user_nvic.c
  * Tac Gia          :     Nguyen Quy Nhat
  * Cong Ty          :     MinhHaGroup
  * Website          :     MinhHaGroup.com
  * Phien Ban        :     V1.0.0
  * Ngay             :     31-07-2012
  * Tom Tat          :     Dinh nghia cac ham cau hinh khoi NVIC.					          			
  *           				
  *
  ******************************************************************************
  * Chu Y						 :				
	*										+ Tuy theo muc dich su dung ma lua chon cac cau hinh cho 			
  *											phu hop.
	*										+ Phai cau hinh GPIO la cac chan USART tuong ung tai 
	*											file user_gpio.c
	*										+ Neu su dung them cac chuc nang interrupt, dma...
	*											thi ta phai cau hinh cho cac chuc nang do dua vao
	*											cac file tuong ung can su dung (user_nvic, user_interrupt
	*                     , user_dma.....);
	*										+ Mot so cau hinh, chuc nang co the khong duoc su dung trong
	*											mot bo USART, de biet chi tiet xem tai file stm32f10x_usart.c
	*										+ file nay cau hinh cho USART 1,2,3. Neu su dung cac USART
	*											khac ta se khai bao, dinh nghia tuong tu cac ham dua theo 
	*                     cac USART tuong ung.
	*
  *
  * 
  ******************************************************************************
  */
#include "user_nvic.h"
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	//Cau hinh cho nhom Uu Tien NVIC
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	//Chon kenh ngat
  NVIC_InitStructure.NVIC_IRQChannel =TIM3_IRQn ;
  //Chon Pre emption	
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	//Chon hinh Sub
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	//Enable kenh NVIC
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);  	
}
