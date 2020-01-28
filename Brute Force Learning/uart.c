#include "uart.h"


void USART2_Init(void){
 //Enable clock for UART. at APB1


  /*ENABLE clock for USART2*/	
	RCC->APB1ENR |=  0x20000;
	RCC->AHB1ENR |=  0x1; 
	
	  /* Configure PA2, PA3 for USART2 TX, RX */
  GPIOA->AFR[0] &= ~0xFF00;
  GPIOA->AFR[0] |=  0x7700;   /* alt7 for USART2 */

	GPIOA->MODER  &= ~0x00F0;
  GPIOA->MODER  |=  0x00A0;   /* enable alt. function for PA2, PA3 */

  USART2->BRR = 0x0683;       /* 9600 baud @ 16 MHz */
  USART2->CR1 = 0x000C;       /* enable Tx, Rx, 8-bit data */
  USART2->CR2 = 0x0000;       /* 1 stop bit */
  USART2->CR3 = 0x0000;       /* no flow control */
  USART2->CR1 |= 0x2000;      /* enable USART2 */

}


int USART2_write(int ch){
	while(!(USART2->SR & 0x0080)){}
	USART2->DR =(ch &0xFF);
	return ch;

}

int USART2_read(void){
	while(!(USART2->SR & 0x0020)){}
	return USART2->DR;

}

struct __FILE { int handle; };
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f) {
    int c;

    c = USART2_read();      /* read the character from console */

    if (c == '\r') {        /* if '\r', after it is echoed, a '\n' is appended*/
        USART2_write(c);    /* echo */
        c = '\n';
    }

    USART2_write(c);        /* echo */

    return c;
}

/* Called by C library console/file output */
int fputc(int c, FILE *f) {
    return USART2_write(c);  /* write the character to console */
}


int n;
char str[80];

void test_setup(void){
	
  printf("Please enter a number:");
	scanf("%d",&n);
	printf("The number you entered is : %d\r\n",n);
	printf("Please enter a character string :");
	gets(str);
	printf("The string you entered is : ");
	puts(str);
	printf("\r\n");
	 
}