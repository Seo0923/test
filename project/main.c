#include "RCC.h"
#include "GPIO.h"

#define PORTA_IN (GPIOA->IDR)
#define PORTA_OUT (GPIOA->ODR)

uint32_t SW1 = 0x10, LED1 = 0x02, LED2 = 0x04;

void main(void)
{
  System_Init();
  PORTA_OUT |= LED1;
  while(1)
  {
    if(PORTA_IN == SW1)
    {
      PORTA_OUT |= LED2;
    }
    else
    {
      PORTA_OUT &= ~LED2;
    }
  }
}

void System_Init(void)
{
  SystemInit();
  /* GPIOx -> APB2 EN*/
  RCC_APB2_set_clock(GPIOA_Clock|GPIOC_Clock , ENABLE);
  GPIO_Config();
}

void GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  /* GPIOA INPUT*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  /* GPIOA OUTPUT*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  /* GPIOD OUTPUT*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

