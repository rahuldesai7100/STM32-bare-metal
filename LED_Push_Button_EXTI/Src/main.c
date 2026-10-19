#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_base	0x40023800UL
#define RCC_APB2ENR	(*(volatile uint32_t *)(RCC_base + 0x44UL))
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_base + 0x30UL))
#define GPIOA_address 0x40020000UL
#define GPIOA_MODER	(*(volatile uint32_t *)(GPIOA_address + 0x00UL))
#define GPIOA_ODR	(*(volatile uint32_t *)(GPIOA_address + 0x14UL))
#define GPIOA_IDR	(*(volatile uint32_t *)(GPIOA_address + 0x10UL))
#define GPIOA_PUPDR	(*(volatile uint32_t *)(GPIOA_address + 0x0CUL))
#define EXTI_base 0x40013C00UL
#define EXTI_FTSR	(*(volatile uint32_t *)(EXTI_base + 0x0CUL))
#define SYSCFG 0x40013800UL
#define SYSCFG_EXTICR3	(*(volatile uint32_t *)(SYSCFG + 0x10UL))
#define EXTI_IMR	(*(volatile uint32_t *)(EXTI_base + 0x00UL))
#define EXTI_PR		(*(volatile uint32_t *)(EXTI_base + 0x14UL))
#define NVIC_ISER0      (*(volatile uint32_t *)(0xE000E100UL))
int main(void)
{
   RCC_AHB1ENR |= (1U<<0);
   GPIOA_MODER &= ~(1U<<19);
   GPIOA_MODER |= (1U<<18);
   GPIOA_ODR |=(1U<<9);



   GPIOA_MODER &= ~(1U<<16);
   GPIOA_MODER &= ~(1U<<17);

   GPIOA_PUPDR |= (1U<<16);
   GPIOA_PUPDR &= ~(1U<<17);

   EXTI_FTSR |= (1U<<8);
   RCC_APB2ENR |=(1U<<14);

   SYSCFG_EXTICR3 &= ~(1<<0);
   SYSCFG_EXTICR3 &= ~(1<<1);
   SYSCFG_EXTICR3 &= ~(1<<2);
   SYSCFG_EXTICR3 &= ~(1<<3);

   EXTI_IMR |=(1U<<8);

   EXTI_PR = (1U<<8);

   NVIC_ISER0 |= (1U<<23);
	for(;;);
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI_PR & (1U<<8))
	{
		EXTI_PR = (1U << 8);
		GPIOA_ODR ^= (1U << 9);
		for(volatile uint32_t i = 0; i < 150000; i++);
	}
}

