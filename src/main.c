#include "ioSTM8L152R8.h"
#include "UART.h"
#include "clock.h"
#include "gpio.h"
#include "tim1.h"
#include "tim4.h"
#include "EngineBySteps.h"
#include "ADC.h"
#include "distmeter.h"

void send_adc_value(int n);
char ntoa(char n);
int my_pow(int x, int y);
char len(int n);

unsigned int ADC_value = 0;

void main( void ){

  CLOCK_Init();
  GPIO_Init();
  TIM1_Init();
  TIM4_Init();
  ADC_config();
  UART_Config();
  
  EBS_Init();
  
  TIM1_SetFreq(50.0);
  TIM1_SetDC(50.0, 50.0);
  TIM1_Start();
  
  float dutyCycle;
  unsigned char angle; //j=59;
  
  for(angle=0; angle<=90; angle+=10){
    //EBS_Move2(EBS_COUNTERCLOCKWISE, 34);
    //send_adc_value(1000*j);
    
    dutyCycle = 100-2.5/90*angle-7.5;
    TIM1_SetFreq(50.0);
    TIM1_SetDC(50.0, dutyCycle);
    
    TIM4_Delay(500.0, 'm');
    TIM4_Delay(500.0, 'm');
  }
}

void send_adc_value(int n){
    char tam = len(n);
    int num;
    
    do{
        num = (n/my_pow(10,tam-1));
        UART_SendChar(ntoa(num));
        n -= (num*my_pow(10,tam-1));        
        
    }while(--tam);
    
    UART_Send_LFCR();
}

char ntoa(char n){
    return n+48;
}

int my_pow(int x, int y){
    
    if(y == 0)
        return 1;
    
    char i;
    int val = x;
    for(i = 0; i < y-1; i++){
        val *= x;
    }
    return val;
}

char len(int n){
    char count = 0;

    do{
        count++;
        n /= 10;
    } while(n != 0);

    return count;

}
