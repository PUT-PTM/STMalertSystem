#include"init.h"

#define DAC_CHANNEL_1_ADDRESS_BASE 0x40007400
// DAC_DHR12R1 = DAC Data Holding Register 12 bits, Right aligned channel 1
#define DAC_DHR12R1_ADDRESS_OFFSET 0x08
#define DMA_DAC_SIGNAL_SIZE 512
const uint32_t DAC_DMA_sine12bit[DMA_DAC_SIGNAL_SIZE] = {
	    2047, 2097, 2147, 2198, 2248, 2298, 2347, 2397, 2446, 2496, 2544, 2593, 2641, 2689, 2737, 2784, 2830, 2877, 2922, 2967, 3012, 3056, 3099, 3142, 3184, 3226, 3266, 3306, 3346, 3384, 3422, 3458, 3494, 3530, 3564, 3597, 3629, 3661, 3691, 3721, 3749, 3776, 3803, 3828, 3852, 3875, 3897, 3918, 3938, 3957, 3974, 3991, 4006, 4020, 4033, 4044, 4055, 4064, 4072, 4079, 4084, 4088, 4092, 4093, 4094, 4093, 4092, 4088, 4084, 4079, 4072, 4064, 4055, 4044, 4033, 4020, 4006, 3991, 3974, 3957, 3938, 3918, 3897, 3875, 3852, 3828, 3803, 3776, 3749, 3721, 3691, 3661, 3629, 3597, 3564, 3530, 3494, 3458, 3422, 3384, 3346, 3306, 3266, 3226, 3184, 3142, 3099, 3056, 3012, 2967, 2922, 2877, 2830, 2784, 2737, 2689, 2641, 2593, 2544, 2496, 2446, 2397, 2347, 2298, 2248, 2198, 2147, 2097, 2047, 1997, 1947, 1896, 1846, 1796, 1747, 1697, 1648, 1598, 1550, 1501, 1453, 1405, 1357, 1310, 1264, 1217, 1172, 1127, 1082, 1038, 995, 952, 910, 868, 828, 788, 748, 710, 672, 636, 600, 564, 530, 497, 465, 433, 403, 373, 345, 318, 291, 266, 242, 219, 197, 176, 156, 137, 120, 103, 88, 74, 61, 50, 39, 30, 22, 15, 10, 6, 2, 1, 0, 1, 2, 6, 10, 15, 22, 30, 39, 50, 61, 74, 88, 103, 120, 137, 156, 176, 197, 219, 242, 266, 291, 318, 345, 373, 403, 433, 465, 497, 530, 564, 600, 636, 672, 710, 748, 788, 828, 868, 910, 952, 995, 1038, 1082, 1127, 1172, 1217, 1264, 1310, 1357, 1405, 1453, 1501, 1550, 1598, 1648, 1697, 1747, 1796, 1846, 1896, 1947, 1997,
	    0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256, 272, 288, 304, 320, 336, 352, 368, 384, 400, 416, 432, 448, 464, 480, 496, 512, 528, 544, 560, 576, 592, 608, 624, 640, 656, 672, 688, 704, 720, 736, 752, 768, 784, 800, 816, 832, 848, 864, 880, 896, 912, 928, 944, 960, 976, 992, 1008, 1024, 1040, 1056, 1072, 1088, 1104, 1120, 1136, 1152, 1168, 1184, 1200, 1216, 1232, 1248, 1264, 1280, 1296, 1312, 1328, 1344, 1360, 1376, 1392, 1408, 1424, 1440, 1456, 1472, 1488, 1504, 1520, 1536, 1552, 1568, 1584, 1600, 1616, 1632, 1648, 1664, 1680, 1696, 1712, 1728, 1744, 1760, 1776, 1792, 1808, 1824, 1840, 1856, 1872, 1888, 1904, 1920, 1936, 1952, 1968, 1984, 2000, 2016, 2032, 2048, 2063, 2079, 2095, 2111, 2127, 2143, 2159, 2175, 2191, 2207, 2223, 2239, 2255, 2271, 2287, 2303, 2319, 2335, 2351, 2367, 2383, 2399, 2415, 2431, 2447, 2463, 2479, 2495, 2511, 2527, 2543, 2559, 2575, 2591, 2607, 2623, 2639, 2655, 2671, 2687, 2703, 2719, 2735, 2751, 2767, 2783, 2799, 2815, 2831, 2847, 2863, 2879, 2895, 2911, 2927, 2943, 2959, 2975, 2991, 3007, 3023, 3039, 3055, 3071, 3087, 3103, 3119, 3135, 3151, 3167, 3183, 3199, 3215, 3231, 3247, 3263, 3279, 3295, 3311, 3327, 3343, 3359, 3375, 3391, 3407, 3423, 3439, 3455, 3471, 3487, 3503, 3519, 3535, 3551, 3567, 3583, 3599, 3615, 3631, 3647, 3663, 3679, 3695, 3711, 3727, 3743, 3759, 3775, 3791, 3807, 3823, 3839, 3855, 3871, 3887, 3903, 3919, 3935, 3951, 3967, 3983, 3999, 4015, 4031, 4047, 4063, 4079
	};


/*opoznienie*/
void delay(int a)
{
int i=0;
for(i;i<a;i++)
{}
}

void MY_DMA_initM2P(void)
{
   	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
   	DMA_InitTypeDef strukturaDoInicjalizacjiDMA;
   	// wybór kana³u DMA
   	strukturaDoInicjalizacjiDMA.DMA_Channel = DMA_Channel_7;
   	// ustalenie rodzaju transferu (memory2memory / peripheral2memory / memory2peripheral)
   	strukturaDoInicjalizacjiDMA.DMA_DIR = DMA_DIR_MemoryToPeripheral;
   	// tryb pracy - pojedynczy transfer b¹dŸ powtarzany
   	strukturaDoInicjalizacjiDMA.DMA_Mode = DMA_Mode_Circular;
   	// ustalenie priorytetu danego kana³u DMA
   	strukturaDoInicjalizacjiDMA.DMA_Priority = DMA_Priority_Medium;

   	// liczba danych do przes³ania
   	strukturaDoInicjalizacjiDMA.DMA_BufferSize = (uint32_t)DMA_DAC_SIGNAL_SIZE;
   	// adres Ÿród³owy
   	strukturaDoInicjalizacjiDMA.DMA_Memory0BaseAddr = (uint32_t)DAC_DMA_sine12bit;
   	// adres docelowy
   	strukturaDoInicjalizacjiDMA.DMA_PeripheralBaseAddr = (uint32_t)(DAC_CHANNEL_1_ADDRESS_BASE + DAC_DHR12R1_ADDRESS_OFFSET);
   	// zezwolenie na inkrementacje adresu po ka¿dej przes³anej paczce danych
   	strukturaDoInicjalizacjiDMA.DMA_MemoryInc = DMA_MemoryInc_Enable;
   	strukturaDoInicjalizacjiDMA.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
   	// ustalenie rozmiaru przesy³anych danych
   	strukturaDoInicjalizacjiDMA.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
   	strukturaDoInicjalizacjiDMA.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
   	// ustalenie trybu pracy - jednorazwe przes³anie danych
   	strukturaDoInicjalizacjiDMA.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
   	strukturaDoInicjalizacjiDMA.DMA_MemoryBurst = DMA_MemoryBurst_Single;
   	// wy³¹czenie kolejki FIFO (nie u¿ywana w tym przykadzie)
   	strukturaDoInicjalizacjiDMA.DMA_FIFOMode = DMA_FIFOMode_Disable;
   	// wype³nianie wszystkich pól struktury jest niezbêdne w celu poprawnego dzia³ania, wpisanie jednej z dozwolonych wartosci
   	strukturaDoInicjalizacjiDMA.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
   	// zapisanie wype³nionej struktury do rejestrów wybranego po³¹czenia DMA
   	DMA_Init(DMA1_Stream5, &strukturaDoInicjalizacjiDMA);
   	// uruchomienie odpowiedniego po³¹czenia DMA
   	DMA_Cmd(DMA1_Stream5, ENABLE);
   	// uruchomienie DMA dla pierwszego kana³u DAC
   	DAC_DMACmd(DAC_Channel_1, ENABLE);
}


// DAC init
void MY_DAC_init(void)
{
   	GPIO_InitTypeDef GPIO_InitStructure;
   	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA , ENABLE);
   	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
   	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
   	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
   	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
   	GPIO_Init(GPIOA, &GPIO_InitStructure);
   	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
   	DAC_InitTypeDef DAC_InitStructure;
   	DAC_InitStructure.DAC_Trigger = DAC_Trigger_T6_TRGO;
   	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
   	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
   	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
   	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
   	DAC_SetChannel1Data(DAC_Align_12b_R, 0x000);
   	DAC_Cmd(DAC_Channel_1, ENABLE);
}

void MY_DAC_initTimerForUpdating(void)
{
   	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
   	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   	TIM_TimeBaseStructure.TIM_Prescaler = 4200-1;
   	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   	TIM_TimeBaseStructure.TIM_Period = 15;
   	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
   	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
   	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);
   	TIM_SetCounter(TIM6, 0);
}

void rcc()
{
	/*RCC*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE); //DAC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //ADC
}

void gpio()
{
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
}
