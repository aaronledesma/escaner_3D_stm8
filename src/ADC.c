#include "ADC.h"
#include "ioSTM8L152R8.h"

//configura el convertidor analogico-digital ADC
void ADC_config(void){
  
  CLK_PCKENR2 |= 0x01;
  ADC1_CR1 = 0x01; //12 bits, single convertion, ADC ON
  ADC1_CR2 = 0x80; //ADC a 8 MHz
  //ADC1_CR3 no se usa
  ADC1_SQR4 = 0x40; // ADC1_IN6 selected, canal PC2
}

//incicia ADC
void ADC_start(void){
  ADC1_CR1 |= 0x02; //inicia bit 1
}

//limpia registro SR bit 0
void ADC_clearEOC(void){
  ADC1_SR &= 0xFE; //Limpia EOC bit 0
}

//regresa el valor de los 12 bits del convertidor
unsigned int Read_ADC(void){
  unsigned int data;
  data = (ADC1_DRL);
  data |= (ADC1_DRH << 8);
  
  return data;
}