#include"stm32f4xx.h"
#include"stm32f4xx_rcc.h"
#include"stm32f4xx_gpio.h"
#include"stm32f4xx_dac.h"
#include"stm32f4xx_dma.h"
#include"stm32f4xx_tim.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rtc.h"
#include"misc.h"


void delay(int a);
void MY_DMA_initM2P(void);
void MY_DAC_init(void);
void MY_DAC_initTimerForUpdating(void);
void rcc();
void gpio();
void tim();
void usart();
void NVIC_usart();
void USART2_IRQHandler(void);
void send_char(char c);
void send_string(const char* s);

