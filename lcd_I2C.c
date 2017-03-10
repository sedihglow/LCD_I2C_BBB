/*******************************************************************************
 * filename: lcd_I2C.c
 *
 * Implements the functions and its helpers for lcd_I2C.h
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

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
#define CMD_LEN 3
	// see LCD commands in LCD_I2C.h for command details
	uint8_t dispCmd[MSG_LEN_MAX] = {'\0'};

	//dispCmd[0] = SLAVE_ADDR_I2C; // no need to send since only 1 slave
	dispCmd[0] = LCD_CMD;

	dispCmd[1] = FUNC_SET;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);
	runDelay(10);

	dispCmd[1] = SET_BIAS;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = CONTRAST_SET;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = PWR_ICON_HC;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = FOLLOWER_CTL;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = DISP_EN;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = CLR_SCRN;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);

	dispCmd[1] = ENTRY_SET;
	transmit_I2C(baseAddr, dispCmd, CMD_LEN);
	runDelay(10);
#undef CMD_LEN
}// end turnOnLCD

void clearDisplay(uint32_t baseAddr){
	uint8_t clearCmd[] = {SLAVE_ADDR_I2C, LCD_CMD, CLR_SCRN};
	transmit_I2C(baseAddr, clearCmd, 3);
}//end clearDisplay

void transmit_I2C(uint32_t baseAddr, uint8_t *toSlave, uint32_t transLen)
{
	int i = 0;

	/* Data Count specifies the number of bytes to be transferred, acceess
	 * and fills offset: 0x98 I2C_CNT */
    I2CSetDataCount(baseAddr, transLen);

    /*
    ** Configure I2C controller in Master Transmitter mode.A stop
    ** condition will be generated after data count number of
    ** bytes are transferred.
    */
    I2CMasterControl(baseAddr, I2C_CFG_MST_TX | I2C_CFG_STOP | I2C_CFG_7BIT_SLAVE_ADDR);

    // TODO: BUSY BIT IS ALWAYS BUSY, even before sending anything.??
    // wait for busy to not be busy
    //while(!(I2CMasterIntRawStatus(baseAddr) & BB_BIT));

	/* Generated Start Condition over I2C bus */
	I2CMasterStart(baseAddr);

    do{
    	if(I2CMasterIntRawStatus(baseAddr) & XRDY_BIT){
    		/* Put data to data transmit register of i2c */
    		I2CMasterDataPut(baseAddr, toSlave[i]);
    		runDelay(10);
    		++i;
    	 }
    }while(i < transLen);

    /* generate stop */
    I2CMasterStop(baseAddr);
}// end setTransmit_I2C

void sendMsg(uint32_t baseAddr, uint8_t *msg)
{
	uint8_t dataToSlave[MSG_LEN_MAX] = {'\0'};
	dataToSlave[0] = LCD_DATA;
	snprintf(dataToSlave+1, MSG_LEN_MAX-1, msg); // append msg to dataToSlave

	// TODO: if i include the slave address as dataToSlave[0], LCD crashes..why
	transmit_I2C(baseAddr, dataToSlave, strlen(dataToSlave));
}// end sendMsg

void runDelay(uint32_t milliSec)
{
    while(milliSec != 0)
    {
        // set up timer
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        // wait for time 1ms to process
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        // disable the timer
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        milliSec--; // go to next milliSec
    }
}// end runDelay
/**************** EOF *************/
