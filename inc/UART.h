#ifndef __UART_H
#define __UART_H

/* Configura el puerto serie */
void UART_Config(void);

/* Envia una cadena por el puerto UART */
void UART_SendString(unsigned char *s);

/* Envia un caracter por el puerto UART */
void UART_SendChar(char s);

/* REecibe un caracter del puerto serie */
char UART_RecvChar();

/* Envia un CR y un LF */
void UART_Send_LFCR(void);

/* Definiciones */

#endif