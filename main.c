/*******************************************************************************
 * filename: main.c
 *
 * writes a message to the the LCD through I2C
 * NHD-C0220BiZ-FSW-FBW-3v3M
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

#define MSG "James"
#define BLINK_TIME 1000 // in milliseconds

int main(void)
{
    DelayTimerSetup();// sets timer7 clock and settings used for runDelay

    setupLCD_I2C(SOC_I2C_1_REGS); // send base address of I2C1 for setup

    turnOnLCD(SOC_I2C_1_REGS);
    
	while(true){
		clearDisplay(SOC_I2C_1_REGS);
		runDelay(BLINK_TIME);
		sendMsg(SOC_I2C_1_REGS, MSG);
		runDelay(3000);
	}
}//end main
/*********** EOF *********/
