/*
 * File:   newmain.c
 * Author: Alex
 * PWM SN754410 motor driver demo
 * Created on 10 August 2019, 10:31 PM
 */

#include <xc.h>

#include "16F1717_internal.h"

void initMain()
{
    //run at 16 MHz
    internal_16();
    
    //Configure ports
    /////////////////
    
    //set PIN B0 as output
    TRISBbits.TRISB0 = 0;
    
    //set PIN B1 as output
    TRISBbits.TRISB1 = 0;
    
    //turn off analog
    ANSELB = 0;
    
    //Configure Timer6
    //////////////////
    
    //select PWM timer as Timer6 for CCP1 and CCP2
    CCPTMRSbits.C1TSEL = 0b10;
    CCPTMRSbits.C2TSEL = 0b10;
    
    //Enable timer increments every 250 ns (16 MHz clock) 1000/(16/4)
    //Period = 256 * 0.25 us = 64 us
    
    //crystal frequency
    //PWM frequency = (PRX+1)*(TimerX prescaler)*4
    
    //PWM frequency = 16 000 000 / 256 * 1 * 4
    //PWM frequency = 15.625 kHz
    
    //Prescale = 1
    T6CONbits.T6CKPS = 0b00;
    
    //Enable timer6
    T6CONbits.TMR6ON = 1;
    
    //set timer period
    PR6 = 255;
    
    //Configure PWM
    ///////////////
    
    //Configure CCP1
    //LSBs of PWM duty cycle = 00
    CCP1CONbits.DC1B = 00;
    
    //select PWM mode
    CCP1CONbits.CCP1M = 0b1100;
    
    //Configure CCP2
    //LSBs of PWM duty cycle = 00
    CCP2CONbits.DC2B = 00;
    
    //Select PWM mode
    CCP2CONbits.CCP2M = 0b1100;
    
    //Configure PPS
    ///////////////
    
    PPSLOCK = 0x055;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; //unlock PPS
    
    //Set RB0 to PWM1
    RB0PPSbits.RB0PPS = 0b01100;
    
    //Set RB1 to PWM2
    RB1PPSbits.RB1PPS = 0b01101;
    
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; //lock PPS
}

void main(void)
{
    initMain();
    
    while(1)
    {
        //run at approx 20% duty cycle @ 15.625 kHz for 5 s
        
        //forward
        CCPR1L = 192;
        CCPR2L = 0;
        
        __delay_ms(5000);
        
        CCPR1L = 0;
        CCPR2L = 0;
        
        __delay_ms(2000);
        
        //reverse
        CCPR1L = 0;
        CCPR2L = 192;
        
        __delay_ms(5000);
    }
    
    return;
}
