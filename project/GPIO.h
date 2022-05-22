#include "RCC.h"


#define GPIOA ((GPIO_TypeDef *) 0x40010800)
#define GPIOB ((GPIO_TypeDef *) 0x40010C00)
#define GPIOC ((GPIO_TypeDef *) 0x40011000)
#define GPIOD ((GPIO_TypeDef *) 0x40011400)
#define GPIOE ((GPIO_TypeDef *) 0x40011800)
#define GPIOF ((GPIO_TypeDef *) 0x40011C00)
#define GPIOG ((GPIO_TypeDef *) 0x40012000)

#define GPIO_Pin_0 0x0001
#define GPIO_Pin_1 0x0002
#define GPIO_Pin_2 0x0004
#define GPIO_Pin_3 0x0008
#define GPIO_Pin_4 0x0010
#define GPIO_Pin_5 0x0020
#define GPIO_Pin_6 0x0040
#define GPIO_Pin_7 0x0080
#define GPIO_Pin_8 0x0100
#define GPIO_Pin_9 0x0200
#define GPIO_Pin_10 0x0400
#define GPIO_Pin_11 0x0800
#define GPIO_Pin_12 0x1000
#define GPIO_Pin_13 0x2000
#define GPIO_Pin_14 0x4000
#define GPIO_Pin_15 0x8000

typedef struct
{
  __IO uint32_t CRL;    /*!< Control Register Low 0~7,                  Address offset: 0x00      */
  __IO uint32_t CRH;    /*!< Control Register High 8~15,                Address offset: 0x04      */
  __IO uint32_t IDR;    /*!< GPIO port input data register,             Address offset: 0x08      */
  __IO uint32_t ODR;    /*!< GPIO port output register,                 Address offset: 0x0C      */
  __IO uint32_t BSRR;      /*!< GPIO port output bit Set/reset,         Address offset: 0x10      */
  __IO uint32_t BRR;      /*!< GPIO port output data only reset,        Address offset: 0x14      */
  __IO uint16_t LCKR;    /*!< GPIO port bit Lock register,              Address offset: 0x18      */
} GPIO_TypeDef;



typedef enum
{
  GPIO_Mode_IN = 0x00,  //GPIO input Mode
  GPIO_Mode_OUT = 0x01, //GPIO output Mode
  GPIO_Mode_AF = 0x02,  //GPIO Alternate function Mode
  GPIO_Mode_AN = 0x03   //GPIO Analog Mode
}GPIOMode_TypeDef;


typedef enum
{
  GPIO_Speed_10Mhz = 0x01, //Medium Speed
  GPIO_Speed_2MHz = 0x02,  //Low Speed
  GPIO_Speed_50Mhz = 0x03  //Fast Speed
}GPIOSpeed_TypeDef;

typedef enum
{
  GPIO_OType_PP = 0x00,  //Push Pull Mode
  GPIO_OType_OD = 0x01  //Open drain Mode
}GPIOOType_TypeDef;

typedef enum
{
  GPIO_Analog = 0x00, //input Mode_floating
  GPIO_floating = 0x01, //input Mode_floating
  GPIO_PuPd_UP = 0x02,     //input Mode_pull_up
  GPIO_PuPd_DOWN = 0x03    //input Mode_pull_down
}GPIOPuPd_TypeDef;

typedef struct
{
  uint32_t GPIO_Pin;            
  
  GPIOMode_TypeDef GPIO_Mode;     

  GPIOSpeed_TypeDef GPIO_Speed;   

  GPIOOType_TypeDef GPIO_OType;   
  
  GPIOPuPd_TypeDef GPIO_PuPd;    
  
}GPIO_InitTypeDef;

void GPIO_Config();
void GPIO_Init (GPIO_TypeDef* GPIOx , GPIO_InitTypeDef* GPIO_InitStruct);