#include <stdint.h>
#define     __IO    volatile
//GPIO register address set start

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

//GPIO register address set end

#define RCC_CR_HSEON 0x00010000;
#define RCC_CR_HSERDY 0x00020000;
#define RCC_CR_PLLON 0x01000000;

#define RCC_CFGR_PLLXTPRE 0x00020000;
#define RCC_CFGR_PLLSRC 0x00010000;
#define RCC_CFGR_PLLMUL9 0x001C0000;