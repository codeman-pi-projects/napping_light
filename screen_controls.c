

#include "screen_controls.h"
#include "KS0108.h"
#include "KS0108-PIC18.h"
#include "global_variables.h"


void Initialize_Menus(void) {
    //First set the x,y coordinates, then write the string
    
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
        mainMenu:
            Clear_Arrow_Column();       //Clear the whole column first
            GLCD_GoTo(0, mainState);    //Set to the mainState row and Y column 0
            Make_Arrow();
            
        runTime:
            Clear_runTime_Arrows();
            Draw_runTime_Arrow();
            
        default:
            
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

    
 void Clear_runTime_Arrows(void)   
 {
     unsigned char i;
     
     GLCD_GoTo((runTimeX - ARROW_SIZE), subMenuY);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
     
     GLCD_GoTo((timeAfterFinishX - ARROW_SIZE), subMenuY);
     for(i=0; i<ARROW_SIZE; i++)
     {
        GLCD_WriteData(0x00);   
     }
 }
    

void Draw_runTime_Arrow(void)
{
    switch(runTimeContext)
    {
        runTime:
            GLCD_GoTo((runTimeX - ARROW_SIZE), subMenuY);
            Make_Arrow();
        
        timeAfterFinish: 
            GLCD_GoTo((timeAfterFinishX - ARROW_SIZE), subMenuY);
            Make_Arrow();
        
        default:
            GLCD_GoTo((runTimeX - ARROW_SIZE), subMenuY);
            Make_Arrow();
     
    
    }
    
}
    
    
}
