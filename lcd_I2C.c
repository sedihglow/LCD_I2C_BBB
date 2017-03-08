/*******************************************************************************
 * filename: lcd_I2C.c
 *
 * Implements the functions and its helpers for lcd_I2C.h
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

void clockSetupI2C(){



}


void setupLCD_I2C(uint32_t baseAddr)
{
    I2C1ModuleClkConfig(); // set with system clock

    /* sets the pins on the P8 rail to go to I2C1 in mode2.
     * SCL: mode0-spi0_cs0, mode2: I2C1_SCL, gpio0[5]
     * SDA: mode0-spi0_d1, mode2: I2C1_SDA, gpio0[4]
     */
    I2CPinMuxSetup(1);

    // TODO: Enable I2C1 clock
    //enableModuleClock(CLK_I2C1);

    /* Put i2c in reset/disabled state */
    I2CMasterDisable(baseAddr);

    /* Upon reset Auto Idel is enabled.*/
    I2CAutoIdleDisable(baseAddr);

    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(baseAddr, SYS_CLK, I2C_INTERNAL_CLK, I2C_OUT_CLK);

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(baseAddr, SLAVE_ADDR_I2C);

    /* Bring I2C module out of reset */
    I2CMasterEnable(baseAddr);
}//end setupI2C

