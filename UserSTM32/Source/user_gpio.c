  /**
	******************************************************************************
  * Ten Tep		:		    user_gpio.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat     :           Dinh nghia ham cau hinh cac GPIO.           			
  *           
  *
  ******************************************************************************
  * Chu Y		:							
  *							GPIO_Mode:		__________________OUTPUT____________________
  *									GPIO_Mode_Out_PP 				--> Output Push Pull
  *									GPIO_Mode_Out_OD 				--> Output Open Drain
  * 								GPIO_Mode_AF_OD	 				--> Alternate Function Open Drain
  *									GPIO_Mode_AF_PP	 				--> Alternate Function Push Pull
  *											__________________INPUT_____________________
	*								GPIO_Mode_AIN					--> Input Analog
	*								GPIO_Mode_IN_FLOATING			--> Input Floating
	*								GPIO_Mode_IPD					--> Input Pull Down
	*								GPIO_Mode_IPU					--> Input Pull Up
	*						Neu su dung Alternate Function(USART, TIMER, I2C,SPI...) ta phai enable clock cho AFIO:
	*								RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	*********************************************************************************
	*	Vi du			:				Ta cau hinh GPIO su dung USART1.
	*										- Enable clock GPIOA	: 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	*										- Enable clock AFIO		:	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	*										- Cau hinh PIN TX		:	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	         		
	*																	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	*																	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	*																	GPIO_Init(GPIOA, &GPIO_InitStructure);
	*										- Cau hinh PIN RX		:	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	*																	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	*																	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	*																	GPIO_Init(GPIOA, &GPIO_InitStructure);
	*
	*									Cau hinh GPIO PINB.5 la cong ra
	*										- Enable clock GPIOB	:	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	*										- Cau hinh cong ra		:	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	         		
	*																	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	*																	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	*																	GPIO_Init(GPIOB, &GPIO_InitStructure);
	*										
	*
  ******************************************************************************
  */
#include "user_gpio.h"
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	//Enable clock AFIO
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);		
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);	
/*==================================PORTA==========================================*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//_________________________________OUTPUT__________________________________________
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	         		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

//_________________________________INPUT___________________________________________
	/*GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_14|GPIO_Pin_15;	         		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);*/
		         	 
/*==================================PORTB==========================================*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//_________________________________OUTPUT__________________________________________
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8| GPIO_Pin_9| GPIO_Pin_10| GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
//_________________________________INPUT___________________________________________	


/*==================================PORTC==========================================*/
//_________________________________OUTPUT__________________________________________
//_________________________________INPUT___________________________________________	


/*==================================PORTD==========================================*/
//_________________________________OUTPUT__________________________________________
//_________________________________INPUT___________________________________________


/*==================================PORTE==========================================*/
//_________________________________OUTPUT__________________________________________
//_________________________________INPUT___________________________________________	

		
/*==================================PORTF==========================================*/
//_________________________________OUTPUT__________________________________________
//_________________________________INPUT___________________________________________


/*==================================PORTG==========================================*/
//_________________________________OUTPUT__________________________________________
//_________________________________INPUT___________________________________________	
}
