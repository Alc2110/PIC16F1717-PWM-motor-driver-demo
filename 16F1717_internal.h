/*
 * File: 16F1717_Internal.c
 * Program: library file for configuration
 * Compiler: XC8
 */

//includes and defines
//Configuration bit settings
//CONFIG1
#pragma config FOSC = INTOSC
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config BOREN = OFF
#pragma config CLKOUTEN = OFF
#pragma config IESO = ON
#pragma config FCMEN = OFF

//CONFIG2
#pragma config WRT = OFF
#pragma config PPS1WAY = ON
#pragma config ZCDDIS = ON
#pragma config PLLEN = OFF
#pragma config STVREN = ON
#pragma config BORV = LO
#pragma config LPBOR = OFF
#pragma config LVP = OFF

//XC8 standard include
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

//Other includes
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

//For delay routines
#define _XTAL_FREQ 16000000

//Set to 32 MHz
void internal_32()
{
    //Clock determined by FOSC in configuration bits
    SCS0 = 0;
    SCS1 = 0;
    
    //Frequency select bits
    IRCF0 = 0;
    IRCF1 = 1;
    IRCF2 = 1;
    IRCF3 = 1;
    
    //SET PLLx4 ON
    SPLLEN = 1;
}

void internal_16()
{
    SCS0 = 0;
    SCS0 = 0;
    
    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 1;
    IRCF3 = 1;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}

void internal_8()
{
    SCS0 = 0;
    SCS1 = 0;
    
    IRCF0 = 0;
    IRCF1 = 1;
    IRCF2 = 1;
    IRCF3 = 1;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}

void internal_4()
{
    SCS0 = 0;
    SCS1 = 0;
    
    IRCF0 = 1;
    IRCF1 = 0;
    IRCF2 = 1;
    IRCF3 = 1;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}

void internal_2()
{
    SCS0 = 0;
    SCS1 = 0;
    
    IRCF0 = 0;
    IRCF1 = 0;
    IRCF2 = 1;
    IRCF3 = 1;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}

void internal_1()
{
    SCS0 = 0;
    SCS1 = 0;
    
    IRCF0 = 1;
    IRCF1 = 1;
    IRCF2 = 0;
    IRCF3 = 1;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}

void internal_31()
{
    SCS0 = 0;
    SCS1 = 0;
    
    IRCF0 = 0;
    IRCF1 = 0;
    IRCF2 = 0;
    IRCF3 = 0;
    
    //SET PLLx4 OFF
    SPLLEN = 0;
}