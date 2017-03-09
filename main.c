/*******************************************************************************
 * filename: main.c
 *
 * 
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

#define MSG "James"
#define L2_MSG "How Art though?"

int main(void)
{
	DelayTimerSetup();

    setupLCD_I2C(SOC_I2C_1_REGS); // send base address of I2C1 for setup

    turnOnLCD(SOC_I2C_1_REGS);
    
	while(true){
		clearDisplay(SOC_I2C_1_REGS);
		delay(1000);
		sendMsg(SOC_I2C_1_REGS, MSG);
		runDelay(3000);
	}
	exit(EXIT_FAILURE); // should not get to this point
}//end main
