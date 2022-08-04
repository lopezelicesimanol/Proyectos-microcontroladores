#include <16F887.h>
#device adc=10
#fuses  HS,NOWDT ,NOMCLR
#use delay( crystal=12Mhz )
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#use rs232 (BAUD=9600 , XMIT=PIN_C6, RCV=PIN_C7) 


void main()
{
   
int16 ecg=0;
float out=0;

    setup_adc(adc_clock_internal);
    setup_adc_ports(all_analog);
    SET_TRIS_B(0xff);
    set_adc_channel(0);
    delay_us(20);
         
   
   
   
  do
   {
    
     ecg=read_adc();
     out=5.0*ecg/1023.0;
    
     printf(" %Lu V  \n",ecg); 
     printf(" %1.2fv  \r",out);
     delay_ms(5);
    }
      
     while(true);
    
   }
