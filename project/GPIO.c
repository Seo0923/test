#include "RCC.h"
#include "GPIO.h"


void GPIO_Init (GPIO_TypeDef* GPIOx , GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00, Speed = 0x00, CNF = 0x00;
  __IO uint32_t *configregister;
  while(pinpos < 0x10)
  {
    pos = ((uint32_t)0x01) << pinpos;
    pinpos ++;
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
    if(currentpin != 0)
    {
      configregister = (currentpin < GPIO_Pin_8) ? &GPIOx->CRL : &GPIOx->CRH;
      if((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IN))
      {
        Speed = 0x03;
        *configregister &= ~(Speed << (4*pinpos));
        if(GPIO_InitStruct->GPIO_PuPd <= GPIO_PuPd_UP)
        {
          CNF = 0x08;
          *configregister |= CNF << (4*pinpos);
          *configregister &= ~(CNF << 1);
          if(GPIO_InitStruct->GPIO_PuPd == GPIO_PuPd_UP)
          {
            GPIOx->ODR |= (1<<pinpos);
          }
          else 
          {
            GPIOx->ODR &= ~(1<<pinpos);
          }
        }
      }
      else if((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT)||(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
       Speed = GPIO_InitStruct->GPIO_Speed; 
       *configregister |= (Speed << (4*pinpos));
       CNF = (GPIO_InitStruct->GPIO_OType << 2);
       *configregister |= (CNF << (4*pinpos));
       if(GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT)
       {
         *configregister &= ~(0x08 << (4*pinpos));
       }
       else
       {
         *configregister |= 0x08 << (4*pinpos);
       }
      }
    }
  }
}