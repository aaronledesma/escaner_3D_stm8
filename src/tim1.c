#include "tim1.h"
#include <iostm8l152r8.h>
#include <math.h>

void TIM1_Init(void)
{
  // Se habilita el reloj del periférico "Timer 1"
  CLK_PCKENR2 |= 0x02;

  // Se establece un "prescaler" de "TIM1_PSCR + 1"
  TIM1_PSCRH = (TIM1_PSCR & 0xFF00) >> 8;
  TIM1_PSCRL = TIM1_PSCR & 0x00FF;

  // El canal 1 trabajara como "PWM"
  TIM1_CCMR1 = 0x60;
  // Canal CC1 es configurado como salida
  TIM1_CCER1 = 0x01;

  // Se habilita la salida principal
  TIM1_BKR = 0x80;
}

void TIM1_SetFreq(float freq)
{
  unsigned int ARR_Value = 1/freq*F_SYSCLK/(TIM1_PSCR+1);
  //ARR_Value--;

  TIM1_ARRH = (ARR_Value & 0xFF00) >> 8;
  TIM1_ARRL = ARR_Value & 0x00FF;
}

void TIM1_SetDC(float freq, float dutyCycle)
{
  unsigned int ARR_Value = 0, CCR_Value = 0;

  ARR_Value = TIM1_ARRL;
  ARR_Value |= TIM1_ARRH << 8;

  CCR_Value = floor((dutyCycle/100.0)*ARR_Value+0.5);

  TIM1_CCR1H = (CCR_Value & 0xFF00) >> 8;
  TIM1_CCR1L = CCR_Value & 0x00FF;
}

void TIM1_Start(unsigned char start)
{
  TIM1_CR1 = start ? 0x01 : 0x00;
}
