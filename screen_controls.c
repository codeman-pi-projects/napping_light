

#include "screen_controls.h"
#include "KS0108.h"
#include "KS0108-PIC18.h"


void Initialize_Menus(void) {
    //First set the x,y coordinates, then write the string
    
    //Start all the lines at y=3, so I can draw an arrow indicator
    GLCD_GoTo(setRunTime,yMenuStart);
    GLCD_WriteString("Run Time");    
    
    GLCD_GoTo(setBrightness,yMenuStart);
    GLCD_WriteString("Brightness");    
    
    GLCD_GoTo(setStartColors,yMenuStart);
    GLCD_WriteString("Start Color");    
    
    GLCD_GoTo(setFinishedColors,yMenuStart);
    GLCD_WriteString("Finished Color");  
    
    GLCD_GoTo(setBacklightBrightness,yMenuStart);
    GLCD_WriteString("Backlight");  
    
    GLCD_GoTo(selectState,yMenuStart);
    GLCD_WriteString("Select State");  
    
    GLCD_GoTo(saveState,yMenuStart);
    GLCD_WriteString("Save State"); 
    
}

//clear all arrows, main menu and submenus, and then redraw them all
void Draw_Arrow(void)
{

    Clear_Arrow_Column();       //Clear the whole column first
    GLCD_GoTo(mainState, 0);    //Set to the mainState row and Y column 0
    GLCD_WriteData(0x7E);
    GLCD_WriteData(0x3C);
    GLCD_WriteData(0x18);
    GLCD_WriteData(0x7E);

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
        GLCD_GoTo(i, 0);
        
        for(j = 0; j < yMenuStart; j++)
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