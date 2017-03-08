################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
lcd_I2C.obj: ../lcd_I2C.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/armv7a" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/armv7a/am335x" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/hw" --advice:power=all -g --define=am3359 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="lcd_I2C.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/armv7a" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/armv7a/am335x" --include_path="N:/ECE372/I2C_LCD/BBBStarterware/include/hw" --advice:power=all -g --define=am3359 --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


