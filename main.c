/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC18F46K80
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "KS0108.h"
#include "screen_controls.h"
#include "global_variables.h"
#include "mcc_generated_files/pwm2.h"
#include "mcc_generated_files/pwm3.h"
#include "mcc_generated_files/pwm4.h"



void Check_Buttons(void);

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

  
    
    PWM2_LoadDutyValue(0);
    SCREEN_RES_SetHigh();
    __delay_ms(10);
    GLCD_Initalize();
    GLCD_ClearScreen();
    
    //Initialize the menu line items on the screen
    Initialize_Menus();
    
    currentContext = mainMenu;
    mainState = setRunTime;    
    Draw_Arrow();
    
    while (1)
    {
        INTERRUPT_GlobalInterruptDisable();
        Check_Buttons();
        INTERRUPT_GlobalInterruptEnable();
        
        
        
    }
}



void Check_Buttons(void)
{
    //Check the start button, and the end button
    
    //If the encoder button is pressed, change the context, depending on what 
    //  the currentContext
    if(!ENCODER_BTN_GetValue())
    {
        __delay_ms(10);
        //Wait for the button to be released
        if(!ENCODER_BTN_GetValue())
        {
            while(!ENCODER_BTN_GetValue())

            if(currentContext == mainMenu)
            {
                switch(mainState)
                {
                    case setRunTime:             
                        currentContext = runTime;
                        runTimeContext = runTimeSelection;
                        Draw_runTime_Menu();
                        break;
                    case setBrightness:          
                        currentContext = brightnessMenu;
                        brightnessContext = brightness;
                        Draw_Brightness_Menu();
                        appliedBrightness = maxBrightness * (brightnessPercent/100);
                        PWM2_LoadDutyValue(appliedBrightness);
                        break;
                    case setStartColors:         
                        currentContext = startColorRed;
                        break;
                    case setFinishedColors:      
                        currentContext = endColorRed;
                        break;
                    case setBacklightBrightness: 
                        currentContext = backlightMenu;
                        break;
                    case selectState:            
                        currentContext = selectStateMenu;
                        break;
                    default:  
                        currentContext = mainMenu;
                        Initialize_Menus();
                        break;
                }
            }

            else if(currentContext == runTime)
            {
                if(runTimeContext == runTimeBack)
                {
                    //SAVE TO EEPROM HERE
                    currentContext = mainMenu;
                    Initialize_Menus();
                }
                else
                {
                    adjustValues = !adjustValues;
                    //if(adjustValues == 0) adjustValues = 1;
                    //else adjustValues = 0;
                }
            }
               
            else if(currentContext == brightnessMenu)
            {
                if(brightnessContext == brightnessBack)
                {
                    //SAVE TO EEPROM HERE
                    currentContext = mainMenu;
                    PWM2_LoadDutyValue(0);
                    Initialize_Menus();
                }
                else
                {
                    adjustValues = !adjustValues;
                }
            }
            
            else
            {
                currentContext = mainMenu;
                Initialize_Menus();
            }
        
        Draw_Arrow();
        }
    }
    
}


/**
 End of File
*/
