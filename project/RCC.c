#include "RCC.h"
#include "GPIO.h"

/* Clock reset*/

void SystemInit(void)
{
  RCC_CR |= (uint32_t)0x00000081; 
  //HSI CLOCK ENABLE
  
  RCC_CFGR = 0x00000000;  
  //RESET
  RCC_CR &= (uint32_t)0x0000FF83; 
  // RESET value
  
  RCC_CIR = 0x00000000;
  //RESET
  SetSysClock(); // HSE setting clock 
}

/* Clock setting*/
void SetSysClock(void)
{
  __IO uint32_t StartUpCounter =0 , HSEStatus = 0;
  
  RCC_CR |= RCC_CR_HSEON; //HSE ENABLE ON
  
  do 
  {
    HSEStatus = RCC_CR & RCC_CR_HSERDY;
    StartUpCounter ++;
  } while((HSEStatus == 0) && (StartUpCounter != 0x0500));
  

  /* HSE READY OK*/
  
  if(HSEStatus == RCC_CR_HSERDY)
  {
    RCC_CFGR |= RCC_CFGR_PLLXTPRE;
    /* */
    RCC_CR |= RCC_CR_PLLON;
    
    RCC_CFGR |= RCC_CFGR_PLLSRC;
    
    RCC_CFGR |= RCC_CFGR_PLLMUL9;
    
    while(RCC_CR & RCC_CR_PLLRDY == 0)
    {
    }
    
    RCC_CFGR |= RCC_CFGR_SWPLL;
    
    RCC_CFGR &= RCC_CFGR_ADCPRE;
    
    RCC_CFGR &= RCC_CFGR_PPRE2;
    
    RCC_CFGR &= RCC_CFGR_PPRE1;
    
    RCC_CFGR &=  RCC_CFGR_HPRE;
  }
  
  
}

void RCC_APB2_set_clock(uint32_t RCC_APB2_Value, char NewState)
{
  if(NewState == ENABLE)
  {
    RCC_APB2ENR |= RCC_APB2_Value; 
  }
  else
  {
    RCC_APB2ENR &= ~RCC_APB2_Value;
  }
}