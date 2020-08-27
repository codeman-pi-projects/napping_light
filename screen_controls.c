

#include "screen_controls.h"
#include "KS0108.h"
#include "KS0108-PIC18.h"
#include "global_variables.h"
#include "graphic.h"
#include <stdlib.h>
#include <stdio.h>


void Initialize_Menus(void) {
    //First set the x,y coordinates, then write the string
    char display[20]; 
    
    GLCD_ClearScreen();
    
    GLCD_GoTo(xMenuStart,0);
    GLCD_WriteString("Main Menu");
    GLCD_GoTo((valuesXStart - 4), 0);
    GLCD_WriteString("Values");
    GLCD_Line(0,12,127,12);
    GLCD_Line((valuesXStart - 8),0,(valuesXStart - 8),63);
    
    //Start all the lines at y=3, so I can draw an arrow indicator
    GLCD_GoTo(xMenuStart, setRunTime);
    GLCD_WriteString("RunTime");
    GLCD_GoTo(valuesXStart, setRunTime);
    itoa(display, runMinutes, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("min");
    
    GLCD_GoTo(xMenuStart, setBrightness);
    GLCD_WriteString("Brightness");
    GLCD_GoTo(valuesXStart, setBrightness);
    itoa(display, brightnessPercent, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("%   ");    
    
    GLCD_GoTo(xMenuStart, setStartColors);
    GLCD_WriteString("StartColor");   
    GLCD_GoTo(valuesXStart, setStartColors);
    GLCD_WriteString("---");
        
    GLCD_GoTo(xMenuStart, setFinishedColors);
    GLCD_WriteString("EndColor");
    GLCD_GoTo(valuesXStart, setFinishedColors);
    GLCD_WriteString("---");
    
    GLCD_GoTo(xMenuStart, setBacklight);
    GLCD_WriteString("Backlight");
    GLCD_GoTo(valuesXStart, setBacklight);
    GLCD_WriteString("OFF");
    
    GLCD_GoTo(xMenuStart, selectState);
    GLCD_WriteString("SelState");  
    GLCD_GoTo(valuesXStart, selectState);
    GLCD_WriteString("NAP");
   
}

//clear all arrows, main menu and submenus, and then redraw them all
void Draw_Arrow(void)
{

    
    switch(currentContext)
    {
        case mainMenu:
            Clear_Arrow_Column();       //Clear the whole column first
            GLCD_GoTo(0, mainState);    //Set to the mainState row and Y column 0
            Make_Arrow();
            break;
            
        case runTime:
            Clear_runTime_Arrows();
            Draw_runTime_Arrow();
            break;
            
        case brightnessMenu:
            Clear_Brightness_Arrows();
            Draw_Brightness_Arrow();
            break;
            
        case startColors:
            Clear_startColors_Arrows();
            Draw_startColors_Arrow();
            break; 
            
        case backlightMenu:
            Clear_backlight_Arrows();
            Draw_backlight_Arrow();            
            break;
            
        default: 
            Clear_Arrow_Column();       //Clear the whole column first
            GLCD_GoTo(0, mainState);    //Set to the mainState row and Y column 0
            Make_Arrow();
            break;
    }

    
}

void Make_Arrow(void)
{
    GLCD_WriteData(0x7E);
    GLCD_WriteData(0x3C);
    GLCD_WriteData(0x18);
}

void Make_Back_Arrow(void)
{
    GLCD_WriteData(0x04);
    GLCD_WriteData(0x0E);
    GLCD_WriteData(0x95);
    GLCD_WriteData(0x84);
    GLCD_WriteData(0x84);
    GLCD_WriteData(0x44);
    GLCD_WriteData(0x38);
    GLCD_WriteData(0x00);
    
}

void Clear_Arrow_Column(void)
{
    unsigned char i, j;
    
    for(i = 0; i < KS0108_SCREEN_HEIGHT/8; i++)
    {
        GLCD_GoTo(0, i);
        
        for(j = 0; j < (xMenuStart - 1); j++)
        {
            GLCD_WriteData(0x00);
        }
        
    }
}
 
 void Draw_runTime_Menu(void)
 {
    char display[10];
    
    GLCD_ClearScreen();
    
    GLCD_GoTo(0,0);
    GLCD_WriteString("Run Times");
    GLCD_Line(0,9,127,9);
     
    GLCD_GoTo(runTimeX, 2);
    GLCD_WriteString("Run Time: ");
    GLCD_GoTo(valuesXStart, 2);
    itoa(display, runMinutes, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("min   ");
     
    GLCD_GoTo(runTimeX, 4);
    GLCD_WriteString("Time After: ");   
    GLCD_GoTo(valuesXStart, 4);
    itoa(display, afterMinutes, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("min   ");
    
    GLCD_GoTo(runTimeX, 6);
    Make_Back_Arrow();
    
    GLCD_WriteString("Back");  
 }
 
 void Draw_Brightness_Menu(void)
 {
    char display[10];
    
    GLCD_ClearScreen();
    
    GLCD_GoTo(0,0);
    GLCD_WriteString("Light Brightness (0-100%)");
    GLCD_Line(0,9,127,9);
     
    GLCD_GoTo(runTimeX, 2);
    GLCD_WriteString("Brightness: ");
    GLCD_GoTo(valuesXStart, 2);
    itoa(display, brightnessPercent, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("%  ");
    
    GLCD_GoTo(runTimeX, 6);
    Make_Back_Arrow();
    
    GLCD_WriteString("Back");  
 }
    
 
 
 void Draw_Start_Colors_Menu(void)
 {
    char display[10];
    
    GLCD_ClearScreen();
    
    GLCD_GoTo(0,0);
    GLCD_WriteString("Start Colors (0-255)");
    GLCD_Line(0,9,127,9);
     
    GLCD_GoTo(runTimeX, 2);
    GLCD_WriteString("Red: ");
    GLCD_GoTo(valuesXStart, 2);
    itoa(display, redStart, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("   ");
    
    GLCD_GoTo(runTimeX, 3);
    GLCD_WriteString("Green: ");
    GLCD_GoTo(valuesXStart, 3);
    itoa(display, greenStart, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("   ");
    
    GLCD_GoTo(runTimeX, 4);
    GLCD_WriteString("Blue: ");
    GLCD_GoTo(valuesXStart, 4);
    itoa(display, blueStart, 10);
    GLCD_WriteString(display);
    GLCD_WriteString("   ");
    
    
    GLCD_GoTo(runTimeX, 6);
    Make_Back_Arrow();
    
    GLCD_WriteString("Back");  
 }
 
 
 
 void Draw_Backlight_Menu(void)
 {
    char display[10];
    
    GLCD_ClearScreen();
    
    GLCD_GoTo(0,0);
    GLCD_WriteString("Screen Backlight");
    GLCD_Line(0,9,127,9);
     
    GLCD_GoTo(runTimeX, 2);
    GLCD_WriteString("ON");
    
    GLCD_GoTo(runTimeX, 4);
    GLCD_WriteString("OFF");    
    
    
    GLCD_GoTo(runTimeX, 6);
    Make_Back_Arrow();
    
    GLCD_WriteString("Back");  
 }
 
 
 
 void Clear_runTime_Arrows(void)   
 {
     unsigned char i=0;
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
 }
    

void Draw_runTime_Arrow(void)
{
    switch(runTimeContext)
    {
        case runTimeSelection:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
        
        case timeAfterFinish: 
            GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
            Make_Arrow();
            break;
            
        case runTimeBack:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
            Make_Arrow();
            break;
            break;
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
     
    
    }
    
}
    
 void Clear_Brightness_Arrows(void)   
 {
     unsigned char i=0;
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }

     GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
 }

 
 void Draw_startColors_Arrow(void)
{
    switch(startColorsContext)
    {
        case startRed:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
            
        case startGreen:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 3);
            Make_Arrow();
            break;
            
        case startBlue:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
            Make_Arrow();
            break;           

        case startColorsBack:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
            Make_Arrow();
            break;
            break;
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
     
    
    }
    
}
 
 
 
 
 void Clear_startColors_Arrows(void)   
 {
     unsigned char i=0;
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }

     GLCD_GoTo((runTimeX - ARROW_SIZE), 3);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
 }

 
 void Draw_Brightness_Arrow(void)
{
    switch(brightnessContext)
    {
        case brightness:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;

        case brightnessBack:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
            Make_Arrow();
            break;
            break;
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
     
    
    }
    
}
 
 
 
 void Clear_backlight_Arrows(void)   
 {
     unsigned char i=0;
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
     
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
 }
    

void Draw_runTime_Arrow(void)
{
    switch(runTimeContext)
    {
        case runTimeSelection:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
        
        case timeAfterFinish: 
            GLCD_GoTo((runTimeX - ARROW_SIZE), 4);
            Make_Arrow();
            break;
            
        case runTimeBack:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 6);
            Make_Arrow();
            break;
            break;
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
     
    
    }
    
}