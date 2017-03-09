/*******************************************************************************
 * filename: lcd_I2C.h
 *
 * defines the functions neccesary to talk to a LCD screen through I2C
 *
 * written by: James Ross
 ******************************************************************************/
#ifndef _LCD_I2C_H
#define _LCD_I2C_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "beaglebone.h"
#include "soc_AM335x.h"
#include "hsi2c.h"
#include "clock.h"
#include "delay.h"

// I2C definitions
#define SLAVE_ADDR_I2C 0x3c // salve adderss for LCD screen
#define I2C_P9_17_18   0x1  // sets the pinmux on BBB to change 12/18 on rail P9

// I2C clock requirements, Master is processor
#define SYS_CLK 		 48000000 // 48Mhz, current system clock for CPU
#define I2C_INTERNAL_CLK 12000000 // 12Mhz, internal clock used by I2C
#define I2C_OUT_CLK 	 100000   // 100kbs, required I2C bus speed/freq


/* Sets up the I2C interface so it can be used to communicate to the LCD screen.
 * The LCD screen is connected to I2C1
 */
void setupLCD_I2C(uint32_t baseAddr);

/* Sends a command to turn on the LCD screen from the I2C base addr provided */
void turnOnLCD(uint32_t baseAddr);

#endif
/*********** EOF **********/
