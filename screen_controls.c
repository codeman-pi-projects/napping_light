

#include "screen_controls.h"
#include "KS0108.h"
#include "KS0108-PIC18.h"


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
    
    GLCD_GoTo(xMenuStart, saveState);
    GLCD_WriteString("SaveState"); 
    
}

//clear all arrows, main menu and submenus, and then redraw them all
void Draw_Arrow(void)
{

    Clear_Arrow_Column();       //Clear the whole column first
    GLCD_GoTo(0, mainState);    //Set to the mainState row and Y column 0
    GLCD_WriteData(0x7E);
    GLCD_WriteData(0x3C);
    GLCD_WriteData(0x18);
    

    Clear_Submenu_Arrows();
    
    if(currentContext != mainMenu)
    {
        Draw_Submenu_Arrow();
    }
    
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


void Clear_Submenu_Arrows(void)
{
    
    
}


void Draw_Submenu_Arrow(void)
{
    
    
}