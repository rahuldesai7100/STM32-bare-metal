
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#define AHB1_RCC 			0x40023800
#define GPIOC_address 		0x40020800
#define GPIOA_address 		0x40020000
#define GPIO_CLOCK_OFFSET 	0x30
#define GPIO_CLOCK			(GPIO_CLOCK_OFFSET + AHB1_RCC)
#define GPIO_MODER_OFFSET	0x00
#define GPIOA_MODER 		(GPIOA_address + GPIO_MODER_OFFSET)
#define GPIOC_MODER			(GPIOC_address + GPIO_MODER_OFFSET)
#define GPIO_PUPDR_OFFSET	0x0C
#define GPIOC_PUPDR			(GPIOC_address + GPIO_PUPDR_OFFSET)
#define GPIO_IDR_OFFSET		0x10
#define GPIOC_IDR			(GPIOC_address + GPIO_IDR_OFFSET)
#define GPIOA_ODR_OFFSET	0x14
#define GPIOA_ODR			(GPIOA_address + GPIOA_ODR_OFFSET)

int main(void)
{
	volatile uint32_t *p;
    p=(volatile uint32_t *)(GPIO_CLOCK);
   *p = *p | (1 << 2);
   *p = *p | (1 << 0);

   volatile uint32_t *t;
   t = (volatile uint32_t *)(GPIOA_MODER);
   *t = *t & ~(1 << 19);
   *t = *t | (1 << 18);

   volatile uint32_t *k;
   k = (volatile uint32_t *)(GPIOC_MODER);
   *k = *k & ~(1 << 14);
   *k = *k & ~(1 << 15);

   volatile uint32_t *q;
   q = (volatile uint32_t *)(GPIOC_PUPDR);
   *q = *q & ~(1 << 15);
   *q = *q | (1 << 14);

   volatile uint32_t *r;
   r = (volatile uint32_t *)(GPIOC_IDR);


   volatile uint32_t *g;
      g = (volatile uint32_t *)(GPIOA_ODR);



	for(;;){
		uint32_t val = *r;
		   if (val & (1 << 7))
		   {
			   *g &= ~(1 << 9);
		   }
		   else
		   {
			   *g = *g | (1 << 9);
		   }
	};

}
