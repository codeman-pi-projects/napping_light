/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

enum main_states {
    setRunTime=2,
    setBrightness=3,
    setStartColors=4,
    setFinishedColors=5,
    setBacklightBrightness=6,
    selectState=7    
} mainState;


enum context {
    mainMenu,
    runTime,
    brightnessMenu,
    startColorRed,
    startColorBlue,
    startColorGreen,
    endColorRed,
    endColorBlue,
    endColorGreen,
    backlightMenu,
    selectStateMenu    
} currentContext;

enum RTContext{
    runTimeSelection,
    timeAfterFinish,
    runTimeBack
} runTimeContext;

unsigned char subMenuY = 3;
unsigned char runTimeX = 10;
unsigned char timeAfterFinishX = 65;
unsigned char adjustValues = 0;

unsigned char ARROW_SIZE = 4;
unsigned char xMenuStart = 4;
unsigned char valuesXStart = 80;


unsigned char runMinutes = 0;
unsigned char afterMinutes = 0;

uint8_t  totalBrightness = 50;  //Brightness in percent
uint16_t maxBrightness = 1023;  //Max brightness, 2^9


#endif
