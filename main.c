/*******************************************************************************
 * filename: main.c
 *
 * 
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

int main(void)
{
    
    setupLCD_I2C(SOC_I2C_1_REGS); // send base address of I2C1 for setup

	while(true){
        

	}
	exit(EXIT_FAILURE); // should not get to this point
}
