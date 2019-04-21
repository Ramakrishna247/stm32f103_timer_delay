
#include <stm32f10x.h>

void delay(void);

int main(void)
{
/*----------- I/O port C clock enable--------------*/
	RCC->APB2ENR = RCC_APB2ENR_IOPCEN;
	
	
	
	
/*----------clock for timer enable	----------------*/
	
	RCC->APB1ENR |=RCC_APB1ENR_TIM3EN;
	
  
  /*----------------- Set PC_12 to output mode------------*/
	
  GPIOC->CRH &= ~(GPIO_CRH_CNF13_0);
	GPIOC->CRH &= ~(GPIO_CRH_CNF13_1);
  GPIOC->CRH |= GPIO_CRH_MODE13_0;
	GPIOC->CRH &=~GPIO_CRH_MODE13_1;
	
/*----- timer config-----*/
	
	TIM3->SR &=~TIM_SR_UIF;     //clear the timer rollover bit
	TIM3->PSC= 0X0072;          //assign prescaler value, in this case clock frequncy is 8MHZ(HSI) so 8MHZ/114 
	TIM3->ARR =0XFFFF;          // assign ARR value is the value loaded in to counter
	TIM3->CR1 |=TIM_CR1_CEN;     // enable TIMER
	
	
	/*------ 
	
	formula for delay gneration
	
	delay (update event) = Crystal_Clock_Frequency / ((PSC + 1)*(ARR + 1))
	
	
	
	
	--------*/
	
	

	
	
	
	
  while(1)	
	{
	
	   delay();    

		    GPIOC->ODR |=GPIO_ODR_ODR13;
	
		 delay();
	
        GPIOC->ODR &=~GPIO_ODR_ODR13;   
		
  }
  
}

void delay(void)
{
  TIM3->SR &=~TIM_SR_UIF;    //WAIT UNTILL UPDATE EVENT FLAG IS SET AND CREATE DELAY
		
	  while(!(TIM3->SR & TIM_SR_UIF)){;} 
}
