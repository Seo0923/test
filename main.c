#include "RCC.h"

void System_Init();
void SystemInit();
void SetSysClock();

void main(void)
{
  System_Init();
  
  while(1)
  {
    
  }
}

void System_Init(void)
{
  SystemInit();
}



//2.CFGR �� CR���� 3.Ŭ���� EN ����
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

void SetSysClock(void)
{
  __IO uint32_t StartUpCounter =0 , HSESTATE = 0;
  
  RCC_CR |= RCC_CR_HSEON; //HSE ENABLE ON
  
  do 
  {
    HSESTATE = RCC_CR & RCC_CR_HSERDY;
    StartUpCounter ++;
  } while((HSESTATE == 0 ) && (StartUpCounter != 0x0500));
  
  /* �ٷ� READY�� ���������Ƿ� ������� �ð��� ������� */
  
  if((RCC_CR & RCC_CR_HSERDY) != (uint32_t)0x00)
  {
    HSESTATE = 0x01;
  }
  else
  {
    HSESTATE = 0x00;
  }
  /* HSE READY OK*/
  
  if(HSESTATE == 0x01)
  {
    RCC_CFGR |= RCC_CFGR_PLLXTPRE;
    /* */
    RCC_CR |= RCC_CR_PLLON;
    
    RCC_CFGR |= RCC_CFGR_PLLSRC;
    
    RCC_CFGR |= RCC_CFGR_PLLMUL9;
    
    //PLL CLK üũ�Ŀ� ���� �����ϱ�
  }
  
  
}