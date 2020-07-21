

#include "screen_controls.h"
#include "KS0108.h"
#include "KS0108-PIC18.h"
#include "global_variables.h"
#include "graphic.h"


void Initialize_Menus(void) {
    //First set the x,y coordinates, then write the string
    
    GLCD_GoTo(xMenuStart,0);
    GLCD_WriteString("Main Menu");
    GLCD_GoTo((valuesXStart - 4), 0);
    GLCD_WriteString("Values");
    GLCD_Line(0,12,127,12);
    GLCD_Line((valuesXStart - 8),0,(valuesXStart - 8),63);
    
    //Start all the lines at y=3, so I can draw an arrow indicator
    GLCD_GoTo(xMenuStart, setRunTime);
    GLCD_WriteString("RunTime");    
    
    GLCD_GoTo(xMenuStart, setBrightness);
    GLCD_WriteString("Brightness");    
    
    GLCD_GoTo(xMenuStart, setStartColors);
    GLCD_WriteString("StartColor");    
    
    GLCD_GoTo(xMenuStart, setFinishedColors);
    GLCD_WriteString("EndColor");  
    
    GLCD_GoTo(xMenuStart, setBacklightBrightness);
    GLCD_WriteString("Backlight");  
    
    GLCD_GoTo(xMenuStart, selectState);
    GLCD_WriteString("SelState");  
   
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
    GLCD_GoTo(0,0);
    GLCD_WriteString("Run Times");
    GLCD_Line(0,9,127,9);
     
    GLCD_GoTo(runTimeX, 2);
    GLCD_WriteString("Run Time: ");
     
    GLCD_GoTo(runTimeX, 4);
    GLCD_WriteString("Time After: ");     
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
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), 2);
            Make_Arrow();
            break;
     
    
    }
    
}
    

