#include "iostm8L152R8.h"
#include "UART.h"

/* Configura el puerto serie */
void UART_Config(void)
{
    CLK_PCKENR1 |= 0x20; //clock para USART1
    
    /* UART_DIV = 16 MHz / 9600 ~= 1666  = 0x0682 */
    USART1_BRR1 = 0x68;
    USART1_BRR2 = 0x02;
    
    /* USART enabled, start bit+8 data bits+stop bit */
    USART1_CR1 = 0x00;
  
    /* Transmitter and receiver enable */
    USART1_CR2 = 0x0C;

    /* 1 stop bit */
    USART1_CR3 = 0x00;
}


/* Envia una cadena por el puerto UART */
void UART_SendString(unsigned char *s)
{
  
	 while(*s)
      {
        UART_SendChar(*s);
        s++;
      }	
	
}

/* Envia un caracter por el puerto UART */
void UART_SendChar(char s) 
{
    /* Carga caracter a transmitir en registro de datos */ 
    USART1_DR = s;                   
     		
    /* Espera a que el bit TxE = 1 */
    while((USART1_SR&0x80)!=0x80)			
       	{
       	}          
}

/* Envia un CR y un LF */
void UART_Send_LFCR(void)
{
    /* Carga caracter a transmitir en registro de datos */ 
    USART1_DR = 0x0D; 
     
    /* Espera a que el bit TxE = 1 */
    while((USART1_SR&0x80)!=0x80)			
       	{
       	}          
        
   	   /* Carga caracter a transmitir en registro de datos */ 
	   USART1_DR = 0x0A; 
    
    /* Espera a que el bit TxE = 1 */
    while((USART1_SR&0x80)!=0x80)			
       	{
       	}          
}

/* REcibe un caracter del puerto serie */
char UART_RecvChar()
{
     char s;
     /* Espera a que el bit RxNE = 1 */
     if((USART1_SR&0x20)==0x20)
     {
      s=USART1_DR;	//Guarda el caracter almacenado en el registro DR.
      return s;	 //Regresa un 1, indicando que se recibió un caracter.
     }
     else{
      return 0;	//Regresa un 0, indicando que no se ha recivido un caracter.
	 }
} 