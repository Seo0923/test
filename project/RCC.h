#include <stdint.h>
#define     __IO    volatile
#define ENABLE 1

void System_Init();
void SystemInit();
void SetSysClock();
void RCC_APB2_set_clock(uint32_t RCC_APB2_Value, char NewState);

/* Clock register address set start*/

#define _RCC_H
#define RCC_OFFSET 0x40021000

#define RCC_CR *(unsigned long *) (RCC_OFFSET + 0x00)
#define RCC_CFGR *(unsigned long *) (RCC_OFFSET + 0x04)
#define RCC_CIR *(unsigned long *) (RCC_OFFSET + 0x08)
#define RCC_APB2RSTR *(unsigned long *) (RCC_OFFSET + 0x0C)
#define RCC_APB1RSTR *(unsigned long *) (RCC_OFFSET + 0x10)
#define RCC_AHBENR *(unsigned long *) (RCC_OFFSET + 0x14)
#define RCC_APB2ENR *(unsigned long *) (RCC_OFFSET + 0x18)
#define RCC_APB1ENR *(unsigned long *) (RCC_OFFSET + 0x1C)
#define RCC_BDCR *(unsigned long *) (RCC_OFFSET + 0x20)
#define RCC_CSR *(unsigned long *) (RCC_OFFSET + 0x24)

/* Clock register address set end*/

#define RCC_CR_HSEON 0x00010000
#define RCC_CR_HSERDY 0x00020000
#define RCC_CR_PLLON 0x01000000
#define RCC_CR_PLLRDY 0x02000000

#define RCC_CFGR_PLLXTPRE 0x00020000
#define RCC_CFGR_PLLSRC 0x00010000
#define RCC_CFGR_PLLMUL9 0x001C0000
#define RCC_CFGR_SWPLL 0x00000002
#define RCC_CFGR_ADCPRE 0xFFFF3FFF
#define RCC_CFGR_PPRE2 0xFFFFDFFF
#define RCC_CFGR_PPRE1 0xFFFFFBFF
#define RCC_CFGR_HPRE 0xFFFFFF7F

#define GPIOA_Clock 0x00000004
#define GPIOB_Clock 0x00000008
#define GPIOC_Clock 0x00000010
#define GPIOD_Clock 0x00000020
#define GPIOE_Clock 0x00000040
