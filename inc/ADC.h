#ifndef __ADC_H
#define __ADC_H

//configura el convertidor analogico-digital ADC
void ADC_config(void);

//incicia ADC
void ADC_start(void);

//limpia registro SR bit 0
void ADC_clearEOC(void);

//regresa el valor de los 12 bits del convertidor
unsigned int Read_ADC(void);

#endif