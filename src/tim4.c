#include "tim1.h"
#include "tim4.h"
#include <iostm8l152r8.h>

void TIM4_Init( void )
{
  // Se habilita el reloj del periférico "Timer 4".
  CLK_PCKENR1 |= 0x04;
  TIM4_CR1 |= 0x08; //Counter stops counting at the next update event (clearing the CEN bit)
  TIM4_CR1 &= ~0x01; //counter disable...
}

void TIM4_Start(unsigned char bStart)
{
  TIM4_CR1 = bStart ? 0x09 : 0x08; //Bit #4 y Bit #0... ;D
}

void TIM4_SetPrescalerARR( unsigned char ucSubmultiple, float fDeltaTime )
{
  switch(ucSubmultiple)
  {
    case 'u': // Delay mínimo de 0.0625 µs.
      TIM4_PSCR = 0x00; // Se establece un "prescaler" de 2^0 (1).
      TIM4_ARR = (unsigned char)( F_SYSCLK * 1.0E-6 * fDeltaTime );
      break;

    case 'm': // Delay máximo de ~500 ms.
      TIM4_PSCR = 0x0F; // Se establece un "prescaler" de 2^15 (32768).
      TIM4_ARR = (unsigned char)( (F_SYSCLK/32768) * 1.0E-3 * fDeltaTime );
  }
}

void TIM4_Delay( float fDeltaTime, unsigned char ucSubmultiple )
{
  TIM4_SetPrescalerARR( ucSubmultiple, fDeltaTime );
  TIM4_Start( 1 );

  // Se hace una espera ...
  while( !(TIM4_SR1 & 0x01) );
  
  TIM4_SR1 &= ~0x01;

  TIM4_CNTR = 0; //BORRAME
  TIM4_Start( 0 );
}

void TIM4_DelaySeconds( float fSeconds )
{
  unsigned char fDeltaTime = (unsigned char)(fSeconds / 0.5);

  for( ; fDeltaTime > 0; fDeltaTime-- )
    TIM4_Delay( 500, 'm' );
}
