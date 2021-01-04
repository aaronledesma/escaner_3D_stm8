#include "distmeter.h"
#include "ioSTM8L152R8.h"
#include "ADC.h"
#include <math.h>

unsigned int distmeter_start( double power )
{  
  float dist = 0;
  unsigned long max = (unsigned long)floor(pow((double)10,power)+0.5);
  unsigned long i;
  
  for(i=1; i <= max; i++ ){
    ADC_start();

    // Wait for "EOC = 1"
    while(ADC1_SR & 0x01 != 0x01);    

    dist += Read_ADC();
  }
  
  return (unsigned int)(dist/(double)(max));
}
