################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../controlPrincipal.cfg 

CMD_SRCS += \
../CC2650_LAUNCHXL.cmd 

C_SRCS += \
../CC2650_LAUNCHXL.c \
../ccfg.c \
../controlPrincipal.c 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

GEN_MISC_DIRS += \
./configPkg/ 

C_DEPS += \
./CC2650_LAUNCHXL.d \
./ccfg.d \
./controlPrincipal.d 

GEN_OPTS += \
./configPkg/compiler.opt 

OBJS += \
./CC2650_LAUNCHXL.obj \
./ccfg.obj \
./controlPrincipal.obj 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

OBJS__QUOTED += \
"CC2650_LAUNCHXL.obj" \
"ccfg.obj" \
"controlPrincipal.obj" 

C_DEPS__QUOTED += \
"CC2650_LAUNCHXL.d" \
"ccfg.d" \
"controlPrincipal.d" 

GEN_FILES__QUOTED += \
"configPkg\linker.cmd" \
"configPkg\compiler.opt" 

C_SRCS__QUOTED += \
"../CC2650_LAUNCHXL.c" \
"../ccfg.c" \
"../controlPrincipal.c" 


