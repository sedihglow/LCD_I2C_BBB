/*******************************************************************************
 * filename: lcd_I2C.c
 *
 * Implements the functions and its helpers for lcd_I2C.h
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

#define DISP_ON_LEN 2
//#define DISP_ON_CMD "\x00\x0C"

void setupLCD_I2C(uint32_t baseAddr)
{
    I2C1ModuleClkConfig(); // set with system clock

    /* sets the pins on the P8 rail to go to I2C1 in mode2.
     * SCL: mode0-spi0_cs0, mode2: I2C1_SCL, gpio0[5]
     * SDA: mode0-spi0_d1, mode2: I2C1_SDA, gpio0[4]
     */
    I2CPinMuxSetup(I2C_P9_17_18);

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

void turnOnLCD(uint32_t baseAddr)
{
	setTransmit_I2C(baseAddr, DISP_ON_LEN);

}// end turnOnLCD

void setTransmit_I2C(uint32_t baseAddr, uint32_t transLen)
{
	/* Data Count specifies the number of bytes to be transferred, acceess
	 * and fills offset: 0x98 I2C_CNT */
    I2CSetDataCount(baseAddr, transLen);

    /*
    ** Configure I2C controller in Master Transmitter mode.A stop
    ** condition will be generated after data count number of
    ** bytes are transferred.
    */
    I2CMasterControl(baseAddr, I2C_CFG_MST_TX | I2C_CFG_STOP | I2C_CFG_7BIT_SLAVE_ADDR);

    /* Generated Start Condition over I2C bus */
    I2CMasterStart(baseAddr);

    /* Wait untill I2C registers are ready to access */
    while(0 == (I2CMasterIntRawStatus(baseAddr) & I2C_INT_ADRR_READY_ACESS));
}

// namespace cleanup
#undef DISP_ON_LEN
#undef DISP_ON_CMD
/******** EOF ******/
