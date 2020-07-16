#include <xc.h>
#define KS0108_DATA_PORT	PORTC
#define KS0108_DATA_DIR		TRISC
#define KS0108_DATA_PIN		PORTC

#define KS0108_CTRL_PORT	PORTA
#define KS0108_CTRL_DIR		TRISA

#define KS0108_RS			(1 << 2)  //Also known as D/I
#define KS0108_RW			(1 << 1)
#define KS0108_EN			(1 << 3)

#define KS0108_CS2			(1 << 6)
#define KS0108_CS1			(1 << 5)
#define KS0108_CS3			(1 << 7)


#define DISPLAY_STATUS_BUSY 0x80

extern unsigned char screen_x, screen_y;
//-------------------------------------------------------------------------------------------------
// Delay function
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
    Nop();
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitializePorts(void)
{
KS0108_CTRL_PORT |= (KS0108_CS1 | KS0108_CS2 | KS0108_CS3);
KS0108_CTRL_DIR &= ~(KS0108_CS1 | KS0108_CS2 | KS0108_CS3 | KS0108_RS | KS0108_RW | KS0108_EN);
}
//-------------------------------------------------------------------------------------------------
// Enable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_PORT &= ~KS0108_CS1; break;
	case 1 : KS0108_CTRL_PORT &= ~KS0108_CS2; break;
	case 2 : KS0108_CTRL_PORT &= ~KS0108_CS3; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Disable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller)
        {
	case 0 : KS0108_CTRL_PORT |= KS0108_CS1; break;
	case 1 : KS0108_CTRL_PORT |= KS0108_CS2; break;
	case 2 : KS0108_CTRL_PORT |= KS0108_CS3; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Read Status from specified controller (0-2)
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
unsigned char status;
KS0108_DATA_DIR = 0xFF;
KS0108_CTRL_PORT |= KS0108_RW;
KS0108_CTRL_PORT &= ~KS0108_RS;
GLCD_EnableController(controller);
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
status = KS0108_DATA_PIN;
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(controller);
return status;
}
//-------------------------------------------------------------------------------------------------
// Write command to specified controller
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0x00;
KS0108_CTRL_PORT &= ~(KS0108_RW | KS0108_RS);
GLCD_EnableController(controller);
KS0108_DATA_PORT = commandToWrite;
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(controller);
}
//-------------------------------------------------------------------------------------------------
// Read data from current position
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
unsigned char data;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0xFF;
KS0108_CTRL_PORT |= (KS0108_RW | KS0108_RS);
GLCD_EnableController(screen_x / 64);
//GLCD_Delay();
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
data = KS0108_DATA_PIN;
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
return data;
}
//-------------------------------------------------------------------------------------------------
// Write data to current position
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0x00;
KS0108_CTRL_PORT &= ~KS0108_RW;
KS0108_CTRL_PORT |= KS0108_RS;
KS0108_DATA_PORT = dataToWrite;
GLCD_EnableController(screen_x / 64);
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
  return *(ptr);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------