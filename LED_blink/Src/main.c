#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#define RCC_address_AHB1 		0x40023800
#define RCC_AHB1COFFSET 		0x30
#define RCC_AHB1ENR 			(RCC_address_AHB1 + RCC_AHB1COFFSET)
#define GPIOA_address			0x40020000
#define GPIOA_MODER_OFFSET		0x00
#define GPIOA_MODER				(GPIOA_address + GPIOA_MODER_OFFSET)
#define GPIOA_ODR_OFFSET		0x14
#define GPIOA_ODR				(GPIOA_address + GPIOA_ODR_OFFSET)


int main(void)
{

volatile uint32_t *p;
p = (volatile uint32_t *)(RCC_AHB1ENR);
*p = *p | (1 << 0);

volatile uint32_t *t;
t = (volatile uint32_t*)(GPIOA_MODER);
*t = *t & ~(1 << 19);
*t = *t | (1 << 18);


volatile uint32_t *g;
g = (volatile uint32_t*)(GPIOA_ODR);
*g = *g | (1 << 9);
for(;;){}
	}
