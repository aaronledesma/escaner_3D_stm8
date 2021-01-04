#ifndef _GPIO_H_
  #define _GPIO_H_

  #define F_SYSCLK  ((float)16.0E+6)
  #define TIM1_PSCR ((unsigned char)(31))

  void TIM1_Init(void);
  void TIM1_SetFreq(float freq);
  void TIM1_SetDC(float freq, float dutyCycle);
  void TIM1_Start(unsigned char start);

#endif
