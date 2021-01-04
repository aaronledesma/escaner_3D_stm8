#include "gpio.h"
#include <iostm8l152r8.h>

void GPIO_Init(void)
{
  /* PA:H Control del motor a pasos */
  PA_DDR |= 0xF0; // Output mode
  PA_CR1 |= 0xF0; // Push-pull
  PA_CR2 &= 0x0F; // Output speed up to 2 MHz

  /* PB:0 Sensor de posicionamiento del motor a pasos */
  PB_DDR &= 0xFE; // Input mode
  PB_CR1 &= 0XFE; // Floating input
  PB_CR2 &= 0xFE; // External interrupt disabled
  
  /* PB:1 Salida de senial PWM @ 50% */
  PB_DDR |= 0x02;       // Output mode
  PB_CR1 |= 0X02;       // Push-pull
  PB_CR2 &= ~0x02;      // Output speed up to 2 MHz

  /* Se dedica todo el puerto D como la salida de canal 1
     del "Timer 1" (D2) para el posicionamiento del servomotor */
  PD_DDR |= 0x04; // Output mode.
  PD_CR1 |= 0x04; // Push-pull.
  PD_CR2 &= 0x04; // Output speed up to 2 MHz.

  // ADC1_IN6 PC2
  PC_DDR &= ~0x04;
  PC_CR1 |= 0x04;
  PC_CR2 &= ~0x04;
  
  // UART_TX PC3
  PC_DDR |= 0x08;
  PC_CR1 |= 0x08;
  PC_CR2 &= ~0x08;
}
