################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
cache.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/cache.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="cache.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

clock.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/am335x/clock.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="clock.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cp15.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/cgt/cp15.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="cp15.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

cpu.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/cgt/cpu.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="cpu.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

device.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/am335x/device.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="device.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

exceptionhandler.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/am335x/cgt/exceptionhandler.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="exceptionhandler.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

init.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/cgt/init.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="init.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

interrupt.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/am335x/interrupt.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="interrupt.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mmu.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/mmu.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="mmu.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup.obj: N:/ECE372/I2C_LCD/BBBStarterware/system_config/armv7a/am335x/startup.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"N:/My Documents/ti-cgt-arm_5.2.5/bin/armcl" -mv7A8 --code_state=32 --abi=eabi -me --include_path="N:/My Documents/ti-cgt-arm_5.2.5/include" --include_path="../../../../../../include/hw" --include_path="../../../../../../include/armv7a" --include_path="../../../../../../include/armv7a/am335x" -g --gcc --define=am3359 --diag_warning=225 --neon --unaligned_access=on --enum_type=packed --preproc_with_compile --preproc_dependency="startup.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


