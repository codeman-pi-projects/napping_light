/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26.7
        Device            :  PIC18F46K80
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SCREEN_RW aliases
#define SCREEN_RW_TRIS               TRISAbits.TRISA1
#define SCREEN_RW_LAT                LATAbits.LATA1
#define SCREEN_RW_PORT               PORTAbits.RA1
#define SCREEN_RW_ANS                ANCON0bits.ANSEL1
#define SCREEN_RW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SCREEN_RW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SCREEN_RW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SCREEN_RW_GetValue()           PORTAbits.RA1
#define SCREEN_RW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SCREEN_RW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SCREEN_RW_SetAnalogMode()  do { ANCON0bits.ANSEL1 = 1; } while(0)
#define SCREEN_RW_SetDigitalMode() do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set SCREEN_DI aliases
#define SCREEN_DI_TRIS               TRISAbits.TRISA2
#define SCREEN_DI_LAT                LATAbits.LATA2
#define SCREEN_DI_PORT               PORTAbits.RA2
#define SCREEN_DI_ANS                ANCON0bits.ANSEL2
#define SCREEN_DI_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SCREEN_DI_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SCREEN_DI_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SCREEN_DI_GetValue()           PORTAbits.RA2
#define SCREEN_DI_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SCREEN_DI_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SCREEN_DI_SetAnalogMode()  do { ANCON0bits.ANSEL2 = 1; } while(0)
#define SCREEN_DI_SetDigitalMode() do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set SCREEN_EN aliases
#define SCREEN_EN_TRIS               TRISAbits.TRISA3
#define SCREEN_EN_LAT                LATAbits.LATA3
#define SCREEN_EN_PORT               PORTAbits.RA3
#define SCREEN_EN_ANS                ANCON0bits.ANSEL3
#define SCREEN_EN_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SCREEN_EN_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SCREEN_EN_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SCREEN_EN_GetValue()           PORTAbits.RA3
#define SCREEN_EN_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SCREEN_EN_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SCREEN_EN_SetAnalogMode()  do { ANCON0bits.ANSEL3 = 1; } while(0)
#define SCREEN_EN_SetDigitalMode() do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set SCREEN_CS1 aliases
#define SCREEN_CS1_TRIS               TRISAbits.TRISA5
#define SCREEN_CS1_LAT                LATAbits.LATA5
#define SCREEN_CS1_PORT               PORTAbits.RA5
#define SCREEN_CS1_ANS                ANCON0bits.ANSEL4
#define SCREEN_CS1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SCREEN_CS1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SCREEN_CS1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SCREEN_CS1_GetValue()           PORTAbits.RA5
#define SCREEN_CS1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SCREEN_CS1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SCREEN_CS1_SetAnalogMode()  do { ANCON0bits.ANSEL4 = 1; } while(0)
#define SCREEN_CS1_SetDigitalMode() do { ANCON0bits.ANSEL4 = 0; } while(0)

// get/set SCREEN_CS2 aliases
#define SCREEN_CS2_TRIS               TRISAbits.TRISA6
#define SCREEN_CS2_LAT                LATAbits.LATA6
#define SCREEN_CS2_PORT               PORTAbits.RA6
#define SCREEN_CS2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define SCREEN_CS2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define SCREEN_CS2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define SCREEN_CS2_GetValue()           PORTAbits.RA6
#define SCREEN_CS2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define SCREEN_CS2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set SCREEN_CS3 aliases
#define SCREEN_CS3_TRIS               TRISAbits.TRISA7
#define SCREEN_CS3_LAT                LATAbits.LATA7
#define SCREEN_CS3_PORT               PORTAbits.RA7
#define SCREEN_CS3_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define SCREEN_CS3_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define SCREEN_CS3_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define SCREEN_CS3_GetValue()           PORTAbits.RA7
#define SCREEN_CS3_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define SCREEN_CS3_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set START_BTN aliases
#define START_BTN_TRIS               TRISBbits.TRISB0
#define START_BTN_LAT                LATBbits.LATB0
#define START_BTN_PORT               PORTBbits.RB0
#define START_BTN_WPU                WPUBbits.WPUB0
#define START_BTN_ANS                ANCON1bits.ANSEL10
#define START_BTN_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define START_BTN_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define START_BTN_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define START_BTN_GetValue()           PORTBbits.RB0
#define START_BTN_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define START_BTN_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define START_BTN_SetPullup()      do { WPUBbits.WPUB0 = 1; } while(0)
#define START_BTN_ResetPullup()    do { WPUBbits.WPUB0 = 0; } while(0)
#define START_BTN_SetAnalogMode()  do { ANCON1bits.ANSEL10 = 1; } while(0)
#define START_BTN_SetDigitalMode() do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set STOP_BTN aliases
#define STOP_BTN_TRIS               TRISBbits.TRISB1
#define STOP_BTN_LAT                LATBbits.LATB1
#define STOP_BTN_PORT               PORTBbits.RB1
#define STOP_BTN_WPU                WPUBbits.WPUB1
#define STOP_BTN_ANS                ANCON1bits.ANSEL8
#define STOP_BTN_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define STOP_BTN_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define STOP_BTN_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define STOP_BTN_GetValue()           PORTBbits.RB1
#define STOP_BTN_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define STOP_BTN_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define STOP_BTN_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define STOP_BTN_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define STOP_BTN_SetAnalogMode()  do { ANCON1bits.ANSEL8 = 1; } while(0)
#define STOP_BTN_SetDigitalMode() do { ANCON1bits.ANSEL8 = 0; } while(0)

// get/set ENCODER_BTN aliases
#define ENCODER_BTN_TRIS               TRISBbits.TRISB2
#define ENCODER_BTN_LAT                LATBbits.LATB2
#define ENCODER_BTN_PORT               PORTBbits.RB2
#define ENCODER_BTN_WPU                WPUBbits.WPUB2
#define ENCODER_BTN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define ENCODER_BTN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define ENCODER_BTN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define ENCODER_BTN_GetValue()           PORTBbits.RB2
#define ENCODER_BTN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define ENCODER_BTN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define ENCODER_BTN_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define ENCODER_BTN_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)

// get/set ENCODER_CHB aliases
#define ENCODER_CHB_TRIS               TRISBbits.TRISB4
#define ENCODER_CHB_LAT                LATBbits.LATB4
#define ENCODER_CHB_PORT               PORTBbits.RB4
#define ENCODER_CHB_WPU                WPUBbits.WPUB4
#define ENCODER_CHB_ANS                ANCON1bits.ANSEL9
#define ENCODER_CHB_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define ENCODER_CHB_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define ENCODER_CHB_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define ENCODER_CHB_GetValue()           PORTBbits.RB4
#define ENCODER_CHB_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define ENCODER_CHB_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define ENCODER_CHB_SetPullup()      do { WPUBbits.WPUB4 = 1; } while(0)
#define ENCODER_CHB_ResetPullup()    do { WPUBbits.WPUB4 = 0; } while(0)
#define ENCODER_CHB_SetAnalogMode()  do { ANCON1bits.ANSEL9 = 1; } while(0)
#define ENCODER_CHB_SetDigitalMode() do { ANCON1bits.ANSEL9 = 0; } while(0)

// get/set ENCODER_CHA aliases
#define ENCODER_CHA_TRIS               TRISBbits.TRISB5
#define ENCODER_CHA_LAT                LATBbits.LATB5
#define ENCODER_CHA_PORT               PORTBbits.RB5
#define ENCODER_CHA_WPU                WPUBbits.WPUB5
#define ENCODER_CHA_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define ENCODER_CHA_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define ENCODER_CHA_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define ENCODER_CHA_GetValue()           PORTBbits.RB5
#define ENCODER_CHA_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define ENCODER_CHA_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define ENCODER_CHA_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define ENCODER_CHA_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)

// get/set SCREEN_D0 aliases
#define SCREEN_D0_TRIS               TRISDbits.TRISD0
#define SCREEN_D0_LAT                LATDbits.LATD0
#define SCREEN_D0_PORT               PORTDbits.RD0
#define SCREEN_D0_ANS                ANCON1bits.ANSEL11
#define SCREEN_D0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define SCREEN_D0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define SCREEN_D0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define SCREEN_D0_GetValue()           PORTDbits.RD0
#define SCREEN_D0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define SCREEN_D0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define SCREEN_D0_SetAnalogMode()  do { ANCON1bits.ANSEL11 = 1; } while(0)
#define SCREEN_D0_SetDigitalMode() do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set SCREEN_D1 aliases
#define SCREEN_D1_TRIS               TRISDbits.TRISD1
#define SCREEN_D1_LAT                LATDbits.LATD1
#define SCREEN_D1_PORT               PORTDbits.RD1
#define SCREEN_D1_ANS                ANCON1bits.ANSEL12
#define SCREEN_D1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define SCREEN_D1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define SCREEN_D1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define SCREEN_D1_GetValue()           PORTDbits.RD1
#define SCREEN_D1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define SCREEN_D1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define SCREEN_D1_SetAnalogMode()  do { ANCON1bits.ANSEL12 = 1; } while(0)
#define SCREEN_D1_SetDigitalMode() do { ANCON1bits.ANSEL12 = 0; } while(0)

// get/set SCREEN_D2 aliases
#define SCREEN_D2_TRIS               TRISDbits.TRISD2
#define SCREEN_D2_LAT                LATDbits.LATD2
#define SCREEN_D2_PORT               PORTDbits.RD2
#define SCREEN_D2_ANS                ANCON1bits.ANSEL13
#define SCREEN_D2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define SCREEN_D2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define SCREEN_D2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define SCREEN_D2_GetValue()           PORTDbits.RD2
#define SCREEN_D2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define SCREEN_D2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define SCREEN_D2_SetAnalogMode()  do { ANCON1bits.ANSEL13 = 1; } while(0)
#define SCREEN_D2_SetDigitalMode() do { ANCON1bits.ANSEL13 = 0; } while(0)

// get/set SCREEN_D3 aliases
#define SCREEN_D3_TRIS               TRISDbits.TRISD3
#define SCREEN_D3_LAT                LATDbits.LATD3
#define SCREEN_D3_PORT               PORTDbits.RD3
#define SCREEN_D3_ANS                ANCON1bits.ANSEL14
#define SCREEN_D3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define SCREEN_D3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define SCREEN_D3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define SCREEN_D3_GetValue()           PORTDbits.RD3
#define SCREEN_D3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define SCREEN_D3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define SCREEN_D3_SetAnalogMode()  do { ANCON1bits.ANSEL14 = 1; } while(0)
#define SCREEN_D3_SetDigitalMode() do { ANCON1bits.ANSEL14 = 0; } while(0)

// get/set SCREEN_D4 aliases
#define SCREEN_D4_TRIS               TRISDbits.TRISD4
#define SCREEN_D4_LAT                LATDbits.LATD4
#define SCREEN_D4_PORT               PORTDbits.RD4
#define SCREEN_D4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define SCREEN_D4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define SCREEN_D4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define SCREEN_D4_GetValue()           PORTDbits.RD4
#define SCREEN_D4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define SCREEN_D4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)

// get/set SCREEN_D5 aliases
#define SCREEN_D5_TRIS               TRISDbits.TRISD5
#define SCREEN_D5_LAT                LATDbits.LATD5
#define SCREEN_D5_PORT               PORTDbits.RD5
#define SCREEN_D5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define SCREEN_D5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define SCREEN_D5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define SCREEN_D5_GetValue()           PORTDbits.RD5
#define SCREEN_D5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define SCREEN_D5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)

// get/set SCREEN_D6 aliases
#define SCREEN_D6_TRIS               TRISDbits.TRISD6
#define SCREEN_D6_LAT                LATDbits.LATD6
#define SCREEN_D6_PORT               PORTDbits.RD6
#define SCREEN_D6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define SCREEN_D6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define SCREEN_D6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define SCREEN_D6_GetValue()           PORTDbits.RD6
#define SCREEN_D6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define SCREEN_D6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)

// get/set SCREEN_D7 aliases
#define SCREEN_D7_TRIS               TRISDbits.TRISD7
#define SCREEN_D7_LAT                LATDbits.LATD7
#define SCREEN_D7_PORT               PORTDbits.RD7
#define SCREEN_D7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define SCREEN_D7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define SCREEN_D7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define SCREEN_D7_GetValue()           PORTDbits.RD7
#define SCREEN_D7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define SCREEN_D7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)

// get/set SCREEN_RES aliases
#define SCREEN_RES_TRIS               TRISEbits.TRISE1
#define SCREEN_RES_LAT                LATEbits.LATE1
#define SCREEN_RES_PORT               PORTEbits.RE1
#define SCREEN_RES_ANS                ANCON0bits.ANSEL6
#define SCREEN_RES_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define SCREEN_RES_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define SCREEN_RES_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define SCREEN_RES_GetValue()           PORTEbits.RE1
#define SCREEN_RES_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define SCREEN_RES_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define SCREEN_RES_SetAnalogMode()  do { ANCON0bits.ANSEL6 = 1; } while(0)
#define SCREEN_RES_SetDigitalMode() do { ANCON0bits.ANSEL6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCB4 pin functionality
 * @Example
    IOCB4_ISR();
 */
void IOCB4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCB4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCB4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCB4_SetInterruptHandler(void* InterruptHandler);

/**
  @Summary
    Dynamic Interrupt Handler for IOCB4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_InterruptHandler);

*/
extern void (*IOCB4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCB4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCB4_SetInterruptHandler() method.
    This handler is called every time the IOCB4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCB4_SetInterruptHandler(IOCB4_DefaultInterruptHandler);

*/
void IOCB4_DefaultInterruptHandler(void);


void Main_Menu_Function(unsigned char result);
void Run_Time_Menu_Function(unsigned char result);
#endif // PIN_MANAGER_H
/**
 End of File
*/