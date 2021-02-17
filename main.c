/*
 * File:   main.c
 * Author: 19179166
 *
 * Created on 4 de Fevereiro de 2021, 16:38
 */


#include <xc.h>
#include "config.h"


void semaforo_init (void)
{
    TRISDbits.TRISD1 = 1;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD2 = 0;
    PORTDbits.RD4= 0;
    PORTDbits.RD5= 0;
    PORTDbits.RD6= 0;
    PORTDbits.RD7= 0;
    PORTDbits.RD2= 0;
}

void delay( int t)
{
    while (t)
    {
        --t;
        __delay_ms(1);
    }
}

void verde (int t)
{
    PORTDbits.RD5 = t;
}

void amarelo (int t)
{
    PORTDbits.RD6 = t;
    delay(3000);
    PORTDbits.RD6 = 0;
}

void vermelho (int t)
{
    PORTDbits.RD2 = 0;
    PORTDbits.RD7 = t;
    delay(5000);
    PORTDbits.RD7 = 0;
}

int btPedestre (void)
{
    return(PORTDbits.RD1);
   
}

void verde_ped (void)
{
  
       PORTDbits.RD4 = 1;
       PORTDbits.RD2 = 0;
}

void vermelho_ped (void)
{
    
    PORTDbits.RD2 = 1;
    PORTDbits.RD4 = 0;
   

}

void main(void) 

{
    semaforo_init();
    
    while(1)
    {
        verde(1);
        vermelho_ped();
        
        if(btPedestre() == 1 )
        {
            verde (0);
            vermelho_ped();
            amarelo(1);
            verde_ped();
            vermelho(1);
            vermelho_ped();
            
            
            
            
            
        }
    }
}
