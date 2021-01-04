#ifndef _TIM4_H_
  #define _TIM4_H_

  void TIM4_Init( void );
  void TIM4_Start(unsigned char bStart);
  void TIM4_SetPrescalerARR( unsigned char ucSubmultiple, float fDeltaTime );
  void TIM4_Delay( float fDeltaTime, unsigned char ucSubmultiple );
  void TIM4_DelaySeconds( float fSeconds );

#endif
