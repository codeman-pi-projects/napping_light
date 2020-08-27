/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26.7
        Device            :  PIC18F46K80
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"
#include "mcc.h"
#include "../screen_controls.h"
#include "../ks0108lib/KS0108.h"
#include "../ks0108lib/KS0108-PIC18.h"
#include <stdlib.h>
#include <stdio.h>
#include "pwm2.h"
#include "pwm3.h"
#include "pwm4.h"


void (*IOCB4_InterruptHandler)(void);
void (*IOCB5_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */   
    LATE = 0x00;    
    LATD = 0x00;    
    LATA = 0x00;    
    LATB = 0x00;    
    LATC = 0x00;    

    /**
    TRISx registers
    */    
    TRISE = 0x05;
    TRISA = 0x01;
    TRISB = 0xFF;
    TRISC = 0x3A;
    TRISD = 0x00;

    /**
    ANSELx registers
    */   
    ANCON0 = 0x00;
    ANCON1 = 0x00;

    /**
    WPUx registers
    */ 
//    WPUB = 0xC8;
    WPUB = 0x00;

    

    /**
    IOCx registers
    */
    // interrupt on change for group IOCB - any
    IOCBbits.IOCB4 = 1;
    IOCBbits.IOCB5 = 1;

    // register default IOC callback functions at runtime; use these methods to register a custom function
    

    // Enable RBI interrupt 
    INTCONbits.RBIE = 1; 
    
}       

//https://www.tech-tools.com/files/picapp.pdf
/*
When the encoder shaft is turning CW, you get a different sequence of
numbers (01,00,10,11) than when it is turning CCW (01,11,10,00). You
may recognize this sequence as Gray code. It is distinguished by the fact
that only one bit changes in any transition. Gray code produces no
incorrect intermediate values when the count rolls over. In normal binary
counting, 11 rolls over to 00. If one bit changed slightly before the other,
the intermediate number value could be incorrectly read as 01 or 10
before settling into the correct state of 00.
        
Interpreting this code amounts to comparing the incoming sequence to
the known sequences for CW and CCW rotation. A lookup table would
do the trick. However, this approach, while easy to understand, is
inefficient. 

The shortcut method uses an interesting property of the twobit Gray code sequence.
Pick any pair of two-bit numbers from the CW sequence shown in figure
2; for instance, the first two: 10, 11. Compute the exclusive-OR (XOR)
of the righthand bit of the first number with the lefthand bit of the second.
In this case, that would be 0 XOR 1 = 1. Try this for any CW pair of
numbers from the table, and you?ll always get 1.
Now reverse the order of the number pair: 11, 10. XOR the right bit of the
first with the left of the second (1 XOR 1 = 0). Any CCW pair of numbers
will produce a 0.
*/

void PIN_MANAGER_IOC(void)
{   
    static unsigned char previousState;
    unsigned char currentState;
    char result;
    unsigned char CHA, CHB;
    
    CHA = ENCODER_CHA_GetValue();
    CHB = ENCODER_CHB_GetValue();
    
    currentState = (CHA << 1) | CHB;
    
    if(previousState == 3)  //If they were both 1 last time
    {
        //If previous state was both 1, then check the direction by just
        //  checking which bit is now low.  Relies on catching the first change event
        if(CHA == 0)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        
   
        switch(currentContext)
        {
            case mainMenu:           Main_Menu_Function(result); break;
            case runTime:            Run_Time_Menu_Function(result); break;
            case brightnessMenu:     Brightness_Menu_Function(result); break;
            case startColors:        Start_Color_Menu_Function(result); break;
            case endColors:        break;
            case backlightMenu:      break;
            case selectStateMenu:    break;

            default:            Main_Menu_Function(result); break;

        } 
    }
        
    previousState = currentState;



    PORTB = PORTB;  //Need to read the port to clear the interrupt on change flag
    // Clear global Interrupt-On-Change flag
    INTCONbits.RBIF = 0;

}

//Change the main menu state, and update the pointer arrow
void Main_Menu_Function(unsigned char result)
{

    if(result)  //increment or decrement mainState, be sure to check boundaries
    {
        if(mainState < selectState) mainState = mainState + 1;
    }
    else
    {
        if(mainState > setRunTime) mainState = mainState - 1;
    }
    
    //Once the state is changed be sure to update the arrow indicator
    Draw_Arrow();
    
}

void Run_Time_Menu_Function(unsigned char result)
{
    char display[10];
    if(adjustValues > 0)
    {
        switch(runTimeContext)
        {
            case runTimeSelection:
                if(result)
                {
                    if(runMinutes < 255) runMinutes++;
                }
                else
                {
                    if(runMinutes > 0) runMinutes--;
                }
                GLCD_GoTo(valuesXStart, 2);
                itoa(display, runMinutes, 10);
                GLCD_WriteString(display);
                GLCD_WriteString("min   ");
                break;
            
            default: NOP();
                break;
                
        }
    }
    else
    {
        if(result)
        {
            if(runTimeContext < runTimeBack) runTimeContext++;
        }
        else 
        {
            if(runTimeContext > runTimeSelection) runTimeContext--;
        }
        //Once the state is changed be sure to update the arrow indicator
        Draw_Arrow();
    }
    
    
}


void Brightness_Menu_Function(unsigned char result)
{
    char display[10];
    if(adjustValues > 0)
    {
        switch(brightnessContext)
        {
            case brightness:
                if(result)
                {
                    if(brightnessPercent < 100) brightnessPercent++;
                }
                else
                {
                    if(brightnessPercent > 0) brightnessPercent--;
                }
                //appliedBrightness = maxBrightness * (brightnessPercent/100);
                //PWM2_LoadDutyValue((int)appliedBrightness);
                Set_Colors(redStart, greenStart, blueStart);
                GLCD_GoTo(valuesXStart, 2);
                itoa(display, brightnessPercent, 10);
                GLCD_WriteString(display);
                GLCD_WriteString("%   ");
                break;
            
            default: NOP();
                break;
                
        }
    }
    else
    {
        if(result)
        {
            if(brightnessContext < brightnessBack) brightnessContext++;
        }
        else 
        {
            if(brightnessContext > brightness) brightnessContext--;
        }
        //Once the state is changed be sure to update the arrow indicator
        Draw_Arrow();
    }
    
    
}



void Start_Color_Menu_Function(unsigned char result)
{
    char display[10];
    if(adjustValues > 0)
    {
        switch(startColorsContext)
        {
            case startRed:
                if(result)
                {
                    if(redStart < 255) redStart++;
                }
                else
                {
                    if(redStart > 0) redStart--;
                }
                
                Set_Colors(redStart, greenStart, blueStart);
                
                GLCD_GoTo(valuesXStart, 2);
                itoa(display, redStart, 10);
                GLCD_WriteString(display);
                GLCD_WriteString("   ");
                break;
            
            case startGreen:
                if(result)
                {
                    if(greenStart < 255) greenStart++;
                }
                else
                {
                    if(greenStart > 0) greenStart--;
                }
                
                Set_Colors(redStart, greenStart, blueStart);
                
                GLCD_GoTo(valuesXStart, 3);
                itoa(display, greenStart, 10);
                GLCD_WriteString(display);
                GLCD_WriteString("   ");
                break;    
            
            case startBlue:
                if(result)
                {
                    if(blueStart < 255) blueStart++;
                }
                else
                {
                    if(blueStart > 0) blueStart--;
                }
                
                Set_Colors(redStart, greenStart, blueStart);
                
                GLCD_GoTo(valuesXStart, 4);
                itoa(display, blueStart, 10);
                GLCD_WriteString(display);
                GLCD_WriteString("   ");
                break;       
                
            default: NOP();
                break;
                
        }
    }
    else
    {
        if(result)
        {
            if(startColorsContext < startColorsBack) startColorsContext++;
        }
        else 
        {
            if(startColorsContext > startRed) startColorsContext--;
        }
        //Once the state is changed be sure to update the arrow indicator
        Draw_Arrow();
    }
    
    
}




    void Set_Colors(float Red, float Green, float Blue)
    {
        float appliedRed, appliedGreen, appliedBlue;
        
        appliedRed = (maxBrightness * (Red/255)) * (brightnessPercent/100);
        appliedGreen = (maxBrightness * (Green/255)) * (brightnessPercent/100);
        appliedBlue = (maxBrightness * (Blue/255)) * (brightnessPercent/100);
        
        
        PWM2_LoadDutyValue(appliedRed);  //RED
        PWM3_LoadDutyValue(appliedBlue);  //BLUE
        PWM4_LoadDutyValue(appliedGreen);  //GREEN       
        
    }


/**
   IOCB4 Interrupt Service Routine
*/
void IOCB4_ISR(void) {

    // Add custom IOCB4 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCB4_InterruptHandler)
    {
        IOCB4_InterruptHandler();
    }
}

/**
  Allows selecting an interrupt handler for IOCB4 at application runtime
*/
void IOCB4_SetInterruptHandler(void* InterruptHandler){
    IOCB4_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCB4
*/
void IOCB4_DefaultInterruptHandler(void){
    // add your IOCB4 interrupt custom code
    // or set custom function using IOCB4_SetInterruptHandler()
}



/**
  Default interrupt handler for IOCB5
*/
void IOCB5_DefaultInterruptHandler(void){
    // add your IOCB5 interrupt custom code
    // or set custom function using IOCB5_SetInterruptHandler()
}

/**
 End of File
*/