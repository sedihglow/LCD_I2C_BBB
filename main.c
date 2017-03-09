/*******************************************************************************
 * filename: main.c
 *
 * 
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

#define L1_MSG "Hi James..!!"
#define L2_MSG "How Art though?"

int main(void)
{
	size_t msgLen = 0;
	char dataToSlave[21] = {0};

    setupLCD_I2C(SOC_I2C_1_REGS); // send base address of I2C1 for setup

    turnOnLCD(SOC_I2C_1_REGS);
    
	while(true){
        

	}
	exit(EXIT_FAILURE); // should not get to this point
}
