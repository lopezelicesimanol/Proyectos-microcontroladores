#include <18f4550.h>
#device adc=10
#fuses  HS,NOWDT ,NOMCLR
#use delay( crystal=20000000 )
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <i2c_Flex_LCD.c>
#use i2c(Master,Fast=100000, sda=PIN_B0, scl=PIN_B1,force_sw)


int16 lm35=0;
float temp=0;


void main()
 {

 lcd_init(0x4E,16,2);
 lcd_backlight_led(ON);
  setup_adc(adc_clock_internal);
  setup_adc_ports(all_analog);
  SET_TRIS_c(0xff);
 
 while(true) 
 
    { 

           lcd_clear();
           set_adc_channel(0);
           delay_us(20);
           lm35=read_adc();
           temp=(lm35*500/1024.0);
           lcd_gotoxy(1,1);
           delay_ms(200);
           
           
           if(input(PIN_A1)==0)
           {
            
           //inicializacion del LCD
           PRINTF(lcd_putc, "\f Comenzando...");
           delay_ms(2000);
           PRINTF(lcd_putc, "\f Comenzando.");
           delay_ms(2000);
           PRINTF(lcd_putc, "\f Comenzando..");
           delay_ms(2000);
           PRINTF(lcd_putc, "\f Comenzando...");
           delay_ms(2000);
           
           
           }
                   if(temp>32)
                    {
                       printf(lcd_putc,"La temperatura\nes:%1.3f C" , temp);
                       delay_ms(2000);
                       printf(lcd_putc, "\f lectura aprobada...");
                       delay_ms(2000);
                       printf(lcd_putc, "\f Desinfeccion completada");
                       output_c(0x01);
                        delay_ms(50);
                    }
                    else
                      {
                        output_c(0x00);
                        delay_ms(50);
                      }
                   if(temp<39)
                      {    printf(lcd_putc,"La temperatura\nes:%1.3f C" , temp);
                           delay_ms(2000);
                           printf(lcd_putc, "\f lectura aprobada...");
                           delay_ms(2000);
                           printf(lcd_putc, "\f Desinfeccion completada");
                           delay_ms(2000);
                          output_c(0x01);
                           delay_ms(50);
                      }
                     else
                     {
                         output_c(0x00);
                         delay_ms(50);
                     }
                          
                while(true);
         }
   }


