#include "EngineBySteps.h"
#include <iostm8l152r8.h>
#include "tim4.h"
#include <ADC.h>
#include <distmeter.h>

//unsigned char EBS_Sequence[EBS_STEPS] = {0x80, 0x40, 0x20, 0x10};
unsigned char EBS_Sequence[EBS_STEPS] = {0xC0, 0x60, 0x30, 0x90};
unsigned int sensorValue = 0;

/* EBS_Move2 */
void EBS_Move2(unsigned char clockwise, unsigned char reduction)
{
  unsigned int i = 0; 
  
  EBS_Move(clockwise);
  sensorValue = distmeter_start((double)4.0);
  // send x UART

  for(; i<reduction; i++){
    EBS_Move(clockwise);
    TIM4_Delay(10.0, 'm');
  }
}

/* EBS_Move */
/* Mueve el motor a pasos un paso: */
/* en sentido horario si el parametro es TRUE */
void EBS_Move(unsigned char clockwise)
{
  static char stepActual = -1;

  //unsigned char backup = PA_ODR & 0x0F;
  if(clockwise){
    stepActual = stepActual < EBS_STEPS-1 ? stepActual : -1; 
    PA_ODR = EBS_Sequence[++stepActual];
    
    //PA_ODR &= 0xF0; PA_ODR |= backup;
  }
  else{
    stepActual = stepActual ? --stepActual : EBS_STEPS-1;
    PA_ODR = EBS_Sequence[stepActual];
  }
}

/* EBS_Init */
/* Posiciona el motor a pasos en una posicion inicial (conocida) */
void EBS_Init(void)
{
  unsigned char step = 0;

  for(; step < EBS_STEPS; step++){
    EBS_Move(EBS_CLOCKWISE); TIM4_Delay(10.0, 'm');
  }

  //while(!(PB_IDR & 0x01))
    //EBS_Move(EBS_COUNTERCLOCKWISE);
}
