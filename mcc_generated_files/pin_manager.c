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
        Product Revision  :  MPLAB(c) Code Configurator - 4.26
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
    TRISC = 0x00;
    TRISD = 0x0F;

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
    IOCB4_SetInterruptHandler(IOCB4_DefaultInterruptHandler);
    IOCB5_SetInterruptHandler(IOCB5_DefaultInterruptHandler);
   
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
    unsigned char result;
    
    __delay_ms(2);  //debounce

    currentState = (ENCODER_CHA_GetValue() << 1) | ENCODER_CHB_GetValue();
    
    GLCD_GoTo(65,3);
    
    GLCD_WriteChar((ENCODER_CHA_GetValue() + 48));
    GLCD_WriteChar((ENCODER_CHB_GetValue() + 48));
    
    //result = 1 -> CW  -> increment 
    //result = 0 -> CCW -> decrement
    result = (previousState & 0x01) ^ ((currentState >> 1) & 0x01);
    
    /*
    switch(currentContext)
    {
        mainMenu:           Main_Menu_Function(result);
        brightnessMenu:     
        startColorRed:      
        startColorBlue:     
        startColorGreen:    
        endColorRed:        
        endColorBlue:       
        endColorGreen:      
        backlightMenu:      
        selectStateMenu:        
        saveStateMenu:      
        
        default:            Main_Menu_Function(result);
        
    } 
    */
        
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
        if(mainState < saveState) mainState = mainState + 1;
    }
    else
    {
        if(mainState > setRunTime) mainState = mainState - 1;
    }
    
    //Once the state is changed be sure to update the arrow indicator
    Draw_Arrow();
    
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
   IOCB5 Interrupt Service Routine
*/
void IOCB5_ISR(void) {

    // Add custom IOCB5 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCB5_InterruptHandler)
    {
        IOCB5_InterruptHandler();
    }
}

/**
  Allows selecting an interrupt handler for IOCB5 at application runtime
*/
void IOCB5_SetInterruptHandler(void* InterruptHandler){
    IOCB5_InterruptHandler = InterruptHandler;
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