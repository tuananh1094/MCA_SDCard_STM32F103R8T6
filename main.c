/********************************************************************************************************
*
* File                : main.c
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 4.14
* Version             : V1.0
* By                  : xiao xian hui
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveShare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "ff.h"
#include "stm32f10x.h"
#include "SPI_MSD_Driver.h"
#include <stdio.h>
#include <string.h>
#include "user_delay.h"
#include "user_usart.h"
#include "DEF_STM32.h"

#define CS		PORTB_7
#define MOSI	PORTA_7
#define MISO	PINA_6
#define SCK 	PORTA_5

#define Ledon  GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define Ledoff GPIO_SetBits(GPIOB,GPIO_Pin_8)
#define Ledon1  GPIO_ResetBits(GPIOB,GPIO_Pin_9)
#define Ledoff1 GPIO_SetBits(GPIOB,GPIO_Pin_9)

static __IO long TimingDelay;
/* Private variables ---------------------------------------------------------*/
FATFS fs;         /* Work area (file system object) for logical drive */
FIL fsrc;         /* file objects */   
FRESULT res;
UINT bw;
BYTE work[FF_MAX_SS];

char path[512]="0:";
uint8_t textFileBuffer[] = "Thank you for using Open107V ！ \r\n";   

/* Private function prototypes -----------------------------------------------*/
int SD_TotalSize(void);
FRESULT scan_files (char* path);


/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
GPIO_InitTypeDef GPIO_InitStructure;
char str[512];
int main(void)
{
	SystemInit();
	//long i=90000000;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	delay_init(72);
	USART1_Configuration(9600);
	
//	Ledon;
//	delay_ms(500);
	Ledoff;
//	delay_ms(500);
	spi_soft_init();
	
	USART_SendString(USART1, " Init..........\n");
	MSD_Init();	
	
//	MSD_WriteSingleBlock(0, "Hello Viet Nam!\n");
//	MSD_ReadSingleBlock(0, str);
//	USART_SendString(USART1, str);

	res = f_mount(&fs,"",1);
	res = f_open(&fsrc, "test.txt", FA_CREATE_ALWAYS|FA_WRITE);
	
	f_printf(&fsrc, "Hello, khoe khong, bo lai so may qua co!\n");
	
	f_gets(str, 512, &fsrc);
	res = f_close(&fsrc);
	USART_SendString(USART1,str);

	//scan_files(path);
	//SD_TotalSize();

    /* Infinite loop */
    while (1)
	{
//		SCK = ~SCK;
//		MOSI = ~MOSI;
//		CS = ~CS;
//		Ledoff;
//		Ledon;
//		delay_ms(500);
//		Ledoff;
//		delay_ms(500);
    }
}

/*******************************************************************************
* Function Name  : scan_files
* Description    : 搜索文件目录下所有文件
* Input          : - path: 根目录
* Output         : None
* Return         : FRESULT
* Attention		 : 不支持长文件名
*******************************************************************************/
//FRESULT scan_files (char* path)
//{
//    FILINFO fno;
//    DIR dir;
//    int i;
//    char *fn;
//#if _USE_LFN
//    static char lfn[_MAX_LFN * (_DF1S ? 2 : 1) + 1];
//    fno.lfname = lfn;
//    fno.lfsize = sizeof(lfn);
//#endif

//    res = f_opendir(&dir, path);
//    if (res == FR_OK) {
//        i = strlen(path);
//        for (;;) {
//            res = f_readdir(&dir, &fno);
//            if (res != FR_OK || fno.fname[0] == 0) break;
//            if (fno.fname[0] == '.') continue;
//#if _USE_LFN
//            fn = *fno.lfname ? fno.lfname : fno.fname;
//#else
//            fn = fno.fname;
//#endif
//            if (fno.fattrib & AM_DIR) {
//                sprintf(&path[i], "/%s", fn);
//                res = scan_files(path);
//                if (res != FR_OK) break;
//                path[i] = 0;
//            } else {
//                printf("%s/%s \r\n", path, fn);
//            }
//        }
//    }

//    return res;
//}

/*******************************************************************************
* Function Name  : SD_TotalSize
* Description    : 文件空间占用情况
* Input          : None
* Output         : None
* Return         : 返回1成功 返回0失败
* Attention		 : None
*******************************************************************************/
//int SD_TotalSize(void)
//{
//    FATFS *fs;
//    DWORD fre_clust;        

//    res = f_getfree("0:", &fre_clust, &fs);  /* 必须是根目录，选择磁盘0 */
//    if ( res==FR_OK ) 
//    {
//	  /* Print free space in unit of MB (assuming 512 bytes/sector) */
//      /*printf("\r\n%d MB total drive space.\r\n"
//           "%d MB available.\r\n",
//           ( (fs->n_fatent - 2) * fs->csize ) / 2 /1024 , (fre_clust * fs->csize) / 2 /1024 );*/
//		
//	  return ENABLE;
//	}
//	else 
//	  return DISABLE;   
//}	 

//void SysTick_Handler(void)
//{
//    if(TimingDelay)  TimingDelay--; // TimingDelay giam di 1
//}
/*void delay_ms(__IO unsigned long nTime)
{
  TimingDelay = nTime;
 
  while(TimingDelay != 0);
}*/

//void delay_ms(__IO unsigned long nTime)
//{
//  TimingDelay = nTime;
//  if (SysTick_Config(SystemCoreClock / 1000))
//  { 
//    
//    NVIC_SystemReset();
//  }
//  else
//  {
//   ;
//  }
//  while(TimingDelay != 0);
//}
//void delay_us(__IO unsigned long nTime)
//{
//  TimingDelay = nTime;
//  if (SysTick_Config(SystemCoreClock / 1000000))
//  { 
//    
//    NVIC_SystemReset();
//  }
//  else
//  {
//   ;
//  }
//  while(TimingDelay != 0);
//}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
