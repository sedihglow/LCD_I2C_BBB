################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
board.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/evmAM335x/board.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="board.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cpsw.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/cpsw.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="cpsw.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ctlregcontext.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/ctlregcontext.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="ctlregcontext.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

dmtimer.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/dmtimer.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="dmtimer.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

edma.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/edma.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="edma.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

eeprom.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/eeprom.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="eeprom.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

gpio.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="gpio.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hs_mmcsd.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/hs_mmcsd.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="hs_mmcsd.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

hsi2c.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/hsi2c.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="hsi2c.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rtc.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/rtc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="rtc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sysdelay.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/sysdelay.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="sysdelay.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sysperf.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/sysperf.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="sysperf.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timertick.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/timertick.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="timertick.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uart.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/uart.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="uart.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

uartConsole.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/uartConsole.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="uartConsole.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

usb.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/usb.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="usb.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

watchdog.obj: N:/ECE372/I2C_LCD/BBBStarterware/platform/beaglebone/watchdog.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../../include/armv7a/am335x" --include_path="../../../../../../../include/hw" --include_path="../../../../../../../include" -g --gcc --define=DMA_MODE --define=am3359 --diag_warning=225 --display_error_number --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="watchdog.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


