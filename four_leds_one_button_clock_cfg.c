#include <STM32F4xx.h>

#define PLL_M 					 4
#define PLL_N 					 180
#define PLL_P 					 0 // PLL_P = 2, zero to the 16th position

#define Button_GPIO_Port GPIOA
#define Leds_GPIO_Port 	 GPIOD
#define Button_Pin			 5
#define Blue_Led_Pin 		 2
#define Red_Led_Pin 		 1
#define Yellow_Led_Pin 	 4
#define Green_Led_Pin 	 6
#define GPIOA_Clock_Pin  0
#define GPIOD_Clock_Pin  3

uint32_t SystemClock_Config(void);
void Enable_GPIOD_GPIOA_Clocks(void);
int32_t  OK = 0;
int32_t  configured;
int32_t num = -1; 
int32_t dir =  1;
uint32_t State = 0;
uint32_t Configure_Led_Pins(void);
uint32_t Configure_Button_Pin(void);
void Delay_ms(uint32_t msTime);
void Blink_Four_Leds(void);
void Error_Handler(void);
void LED_On (unsigned int num);
void LED_Off (unsigned int num);
void LED_Out (unsigned int num);
uint32_t Read_Button_State(void);

const unsigned int NUM_OF_LEDS = 4;
const unsigned long Four_Leds[NUM_OF_LEDS] = {1UL << Red_Led_Pin, 1UL << Blue_Led_Pin, 1UL << Yellow_Led_Pin, 1UL << Green_Led_Pin};

int main(void)
{
  /* Configure the system clock */
  configured = SystemClock_Config();
	if(configured != OK){
		Error_Handler();
	}
	
	Enable_GPIOD_GPIOA_Clocks();
  /* Initialize all configured peripherals */
  configured = Configure_Led_Pins();
  if(configured != OK){
		Error_Handler();
	}
	
	configured = Configure_Button_Pin();
  if(configured != OK){
		Error_Handler();
	}
	
	while (1)
  {
		 State = Read_Button_State();                           /* Read button states         */
   if (State != (1UL << 1)) {
      num += dir;
      if (num == NUM_OF_LEDS) { dir = -1; num =  NUM_OF_LEDS-1; } 
      else if   (num < 0) { dir =  1; num =  0;         }

      LED_On (num);
      Delay_ms(100);                               /* Delay 50ms                 */
      LED_Off(num);
      Delay_ms(500);
    } else { 
			LED_Out (0x0F);
      Delay_ms(60); 
			Blink_Four_Leds();
		}
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
uint32_t SystemClock_Config(void)
{
   /* 1. enable external crystal and wait for it to become ready
	 */
	    RCC->CR |= RCC_CR_HSEON;
	    while((RCC->CR & RCC_CR_HSERDY));
	 /* 2. set the power enable clock and voltage regulator 
	 */
			RCC->APB1ENR |= RCC_APB1ENR_PWREN;
			PWR->CR |= PWR_CR_VOS; //reset value of regulator
	 /* 3. configure the flash prefetch and the latency related settings 
	 */
      FLASH->ACR |= FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY_5WS; 
	/* 4. configure the prescalars HCLK, PCLCK, PCLCK2
	 */
		  //AHB Prescalar value 2 for 180 MHz max. frequency
			RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
			//APB1 Prescalar value 4 for 180 MHz max. frequency
			RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;
	    //APB2 Prescalar value 2 for 180 MHz max. frequency
			RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;
	/* 5. configure the MAIN PLL 
	 */
	     //PLL_M is 4, PLL_N is 180, PLL_P/Q/R are 2 to yield a 180 MHz freq
			 //PPL_P can be either 2, 4, 6, or 8
			RCC->PLLCFGR = (PLL_M << 0) | (PLL_N << 6) | (PLL_P << 16) | (RCC_PLLCFGR_PLLSRC_HSE); 
			//HSE is the 8 Mhz external crystal and HSI is the 16 Mhz internal one
	
	/* 6. enable the PLL and wait for it to become ready
	 */
			RCC->CR |= RCC_CR_PLLON;
			while(!(RCC->CR & RCC_CR_PLLRDY));
	 /* 7. set the clock source and wait for it to become ready
	 */
	    RCC->CFGR |= RCC_CFGR_SW_PLL;
			while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

  /** Initializes the CPU, AHB and APB buses clocks
  */
    return 0;
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void Enable_GPIOD_GPIOA_Clocks(void)
{
  /* GPIO Ports Clock Enable */
  RCC->AHB1ENR |= (1 << GPIOA_Clock_Pin);
  RCC->AHB1ENR |= (1 << GPIOD_Clock_Pin);
 }

uint32_t Configure_Button_Pin(void)
{
	GPIOA->MODER		|= (0<<10); //pin PA5 (bits 11:10) as Input (00)
  //alternative: GPIOA->MODER    &= ~((3UL << 2*5)); where 5 stands for PA5
	GPIOA->OSPEEDR  &= ~((3UL << 2*Button_Pin)  );         /* PA.1 is 50MHz Fast Speed   */
  GPIOA->OSPEEDR  |=  ((2UL << 2*Button_Pin)  ); 
  GPIOA->PUPDR    &= ~((3UL << 2*Button_Pin)  );         /* PA.1 is no Pull up         */
	//GPIOD->MODER		|= (1<<10); //pin PA5 (bits 11:10) as Output (01)
  return 0;
}
/* USER CODE BEGIN 4 */
uint32_t Configure_Led_Pins(void)
{
	GPIOD->MODER    &= ~((3UL << 2*Red_Led_Pin) |
                       (3UL << 2*Blue_Led_Pin) |
                       (3UL << 2*Yellow_Led_Pin) |
                       (3UL << 2*Green_Led_Pin)  );   /* PD.12..15 is output               */
  
	GPIOD->MODER    |=  ((1UL << 2*Red_Led_Pin) |
                       (1UL << 2*Blue_Led_Pin) | 
                       (1UL << 2*Yellow_Led_Pin) | 
                       (1UL << 2*Green_Led_Pin)  ); 
  
	GPIOD->OTYPER   &= ~((1UL <<   Red_Led_Pin) |
                       (1UL <<   Blue_Led_Pin) |
                       (1UL <<   Yellow_Led_Pin) |
                       (1UL <<   Green_Led_Pin)  );   /* PD.12..15 is output Push-Pull     */
  
	GPIOD->OSPEEDR  &= ~((3UL << 2*Red_Led_Pin) |
                       (3UL << 2*Blue_Led_Pin) |
                       (3UL << 2*Yellow_Led_Pin) |
                       (3UL << 2*Green_Led_Pin)  );   /* PD.12..15 is 50MHz Fast Speed     */
  
	GPIOD->OSPEEDR  |=  ((2UL << 2*Red_Led_Pin) |
                       (2UL << 2*Blue_Led_Pin) | 
                       (2UL << 2*Yellow_Led_Pin) | 
                       (2UL << 2*Green_Led_Pin)  ); 
  
	GPIOD->PUPDR    &= ~((3UL << 2*Red_Led_Pin) |
                       (3UL << 2*Blue_Led_Pin) |
                       (3UL << 2*Yellow_Led_Pin) |
                       (3UL << 2*Green_Led_Pin)  );   /* PD.12..15 is Pull up              */
  
	GPIOD->PUPDR    |=  ((1UL << 2*Red_Led_Pin) |
                       (1UL << 2*Blue_Led_Pin) | 
                       (1UL << 2*Yellow_Led_Pin) | 
                       (1UL << 2*Green_Led_Pin)  );
											 
	return 0;
}

uint32_t Read_Button_State(void)
{
	return (GPIOA->IDR & (1UL << 1));
}

void Delay_ms(uint32_t msTime)
{
   uint32_t i;
	 for(i=0; i<msTime; i++){
   }
}

void Blink_Four_Leds(void)
{
	int i;
	uint32_t DELAY_TIME = 1000;
	while(DELAY_TIME >= 400){
		for(i=0; i<NUM_OF_LEDS; i++){
		   LED_On(i);
			 Delay_ms(DELAY_TIME);
		}

		for(i=NUM_OF_LEDS; i>-1; i--){
		   LED_Off(i-1);
			 Delay_ms(DELAY_TIME);
		}
		  DELAY_TIME -= 50;
	}

	if(DELAY_TIME == 400){
		DELAY_TIME = 1000;
	}
}

/*----------------------------------------------------------------------------
  Function that turns on requested LED
 *----------------------------------------------------------------------------*/
void LED_On (unsigned int num) {

  if (num < NUM_OF_LEDS) {
    GPIOD->BSRRL = Four_Leds[num];
  }
}

/*----------------------------------------------------------------------------
  Function that turns off requested LED
 *----------------------------------------------------------------------------*/
void LED_Off (unsigned int num) {

  if (num < NUM_OF_LEDS) {
    GPIOD->BSRRH = Four_Leds[num];
  }
}

/*----------------------------------------------------------------------------
  Function that outputs value to LEDs
 *----------------------------------------------------------------------------*/
void LED_Out(unsigned int value) {
	int i;
  for (i = 0; i < NUM_OF_LEDS; i++) {
    if (value & (1<<i)) {
      LED_On (i);
    } else {
      LED_Off(i);
    }
  }
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
//	  printf("Something went wrong: %s", strerror(errno));
  /* USER CODE END Error_Handler_Debug */
}

/*void Toggle_Board_Leds(void)
{
	GPIOD->ODR ^= (0xFUL << 12);
	//leds PD12, PD13, PD14, PD15
}

void Toggle_One_Led(void)
{
	GPIOA->BSRR |= (1<<5); //set 5th bit in lower part of register
	Delay_ms(10000000);
	GPIOA->BSRR |= ((1<<5) << 16); // set 21th bit in upper part
	Delay_ms(10000000);
}*/
