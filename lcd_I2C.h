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
#include "dmTimer.h"

// timer definitions
#define TIMER_1MS_COUNT (0x5DC0u)

// I2C definitions
#define SLAVE_ADDR_I2C 0x3C // salve adderss for LCD screen
#define I2C_P9_17_18   0x1  // sets the pinmux on BBB to change 12/18 on rail P9

// I2C clock requirements, Master is processor
#define SYS_CLK 		 48000000 // 48Mhz, current system clock for CPU
#define I2C_INTERNAL_CLK 12000000 // 12Mhz, internal clock used by I2C
#define I2C_OUT_CLK 	 100000   // 100kbs, required I2C bus speed/freq

#define MSG_LEN_MAX 20

/* Sets up the I2C interface so it can be used to communicate to the LCD screen.
 * The LCD screen is connected to I2C1
 */
void setupLCD_I2C(uint32_t baseAddr);

/* Sends a command to turn on the LCD screen from the I2C base addr provided */
void turnOnLCD(uint32_t baseAddr);

void sendMsg(uint32_t baseAddr, char *msg);

void transmit_I2C(uint32_t baseAddr, uint8_t *toSlave, uint32_t transLen);

void clearDisplay(uint32_t baseAddr);

void runDelay(uint32_t milliSec);

#endif
/*********** EOF **********/
