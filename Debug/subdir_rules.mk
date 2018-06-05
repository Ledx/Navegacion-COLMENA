################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CC2650_LAUNCHXL.obj: ../CC2650_LAUNCHXL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=none -me --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272" --include_path="/source/ti/blestack/common/cc26xx" --include_path="/source/ti/blestack/inc" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="CC2650_LAUNCHXL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

ccfg.obj: ../ccfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=none -me --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272" --include_path="/source/ti/blestack/common/cc26xx" --include_path="/source/ti/blestack/inc" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="ccfg.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

controlPrincipal.obj: ../controlPrincipal.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=none -me --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/Users/Ledx/Documents/TI Projects/colmenav1" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272" --include_path="/source/ti/blestack/common/cc26xx" --include_path="/source/ti/blestack/inc" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="controlPrincipal.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

build-514066657:
	@$(MAKE) -Onone -f subdir_rules.mk build-514066657-inproc

build-514066657-inproc: ../controlPrincipal.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_32_00_06_core/xs" --xdcpath="C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/tidrivers_cc13xx_cc26xx_2_21_01_01/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/bios_6_46_01_38/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/uia_2_01_00_01/packages;C:/ti/ccsv7/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC2650F128 -r release -c "C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS" --compileOptions "-mv7M3 --code_state=16 --float_support=none -me --include_path=\"C:/Users/Ledx/Documents/TI Projects/colmenav1\" --include_path=\"C:/Users/Ledx/Documents/TI Projects/colmenav1\" --include_path=\"C:/ti/tirtos_cc13xx_cc26xx_2_21_01_08/products/cc26xxware_2_24_03_17272\" --include_path=\"/source/ti/blestack/common/cc26xx\" --include_path=\"/source/ti/blestack/inc\" --include_path=\"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_18.1.1.LTS/include\" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: build-514066657 ../controlPrincipal.cfg
configPkg/compiler.opt: build-514066657
configPkg/: build-514066657


