/*
To do:(wtorek)
-oddzielnie biblioteki na inity (OK)
-obsluga czujników z timerami (do konsultacji)
-glosnik (OK)
-diody na drugiej plytce (OK!)
-stabilizacja
 */

#include<init.h>


int main(void)
{
	SystemInit();
	rcc();
	gpio();

	MY_DAC_init();
	MY_DAC_initTimerForUpdating();
	MY_DMA_initM2P();

    while(1)
    {


    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7)==1)//jezeli bit na PC7=1 -> pomarañczowa dioda
    	{
    		GPIO_SetBits(GPIOD, GPIO_Pin_15);
    		GPIO_SetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    		TIM_Cmd(TIM6, ENABLE);
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    		GPIO_ResetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
    		GPIO_ResetBits(GPIOE, GPIO_Pin_9); // 2ga dioda
    		TIM_Cmd(TIM6, DISABLE);
    	}

    	if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6)==1) //jezeli bit na PC7=1 -> niebieska dioda
    	{
    	    GPIO_SetBits(GPIOD, GPIO_Pin_13);
    		GPIO_SetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    		TIM_Cmd(TIM6, ENABLE);
    	    GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    	    GPIO_ResetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    	}
    	else
    	{
    		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    		GPIO_ResetBits(GPIOE, GPIO_Pin_15); // 2ga dioda
    		TIM_Cmd(TIM6, DISABLE);
    	}
    }
}


