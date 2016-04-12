/*
To do:(wtorek)
-oddzielnie biblioteki na inity
-obsluga czujników z timerami
-glosnik (PROBLEM Z GLOSNIKIEM! Nie dziala, przetestowany na roznych kodach.)
-diody na drugiej plytce (OK!)
-stabilizacja
 */

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_tim.h"
#include "misc.h"

/*opoznienie*/
void delay(int a)
{
int i=0;
for(i;i<a;i++)
{}
}


//// DAC init
//void MY_DAC_init(void)
//{
//   	GPIO_InitTypeDef GPIO_InitStructure;
//   	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
//   	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
//   	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
//   	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//   	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//   	GPIO_Init(GPIOA, &GPIO_InitStructure);
//   	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
//   	DAC_InitTypeDef DAC_InitStructure;
//   	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T6_TRGO;
//   	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
//   	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
//   	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
//   	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
//   	DAC_SetChannel1Data(DAC_Align_12b_R, 0x000);
//   	DAC_Cmd(DAC_Channel_1, ENABLE);
//}
//
//void MY_DAC_initTimerForUpdating(void)
//{
//   	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
//   	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//   	TIM_TimeBaseStructure.TIM_Prescaler = 42-1;
//   	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//   	TIM_TimeBaseStructure.TIM_Period = 20;
//   	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//   	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
//   	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
//   	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
//   	TIM_SetCounter(TIM6, 0);
//   	TIM_Cmd(TIM6, ENABLE);
//}


int main(void)
{
	SystemInit();
	/*RCC*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE); //DAC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //ADC

	/*GPIO diody*/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);



    while(1)
    {

    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)==1)//jezeli bit na PC7=1 -> pomarañczowa dioda
    	{
    		GPIO_SetBits(GPIOD, GPIO_Pin_15);
    		GPIO_SetBits(GPIOC, GPIO_Pin_0); // tu mial byc glosnik, lecz jest popsuty
    		GPIO_SetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    		GPIO_ResetBits(GPIOC, GPIO_Pin_0); // tu mial byc glosnik, lecz jest popsuty
    		GPIO_ResetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    		GPIO_ResetBits(GPIOC, GPIO_Pin_0); // tu mial byc glosnik, lecz jest popsuty
    		GPIO_ResetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    	}

    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)==1) //jezeli bit na PC7=1 -> niebieska dioda
    	{
    	    GPIO_SetBits(GPIOD, GPIO_Pin_13);
    		GPIO_SetBits(GPIOC, GPIO_Pin_0);
    		GPIO_SetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    	    GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    	    GPIO_ResetBits(GPIOC, GPIO_Pin_0);
    	    GPIO_ResetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    		GPIO_ResetBits(GPIOC, GPIO_Pin_0);
    		GPIO_ResetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    	}
    }
}


