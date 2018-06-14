/******************************************************************************/
/* Universidad Nacional Autónoma de México                                    */
/* Instituto de Ciencias Nucleares                                            */
/*----------------------------------------------------------------------------*/
/* Software de navegacion principal                                           */
/*----------------------------------------------------------------------------*/
/* Desarrollador: Ing. Led Eduardo Ruvalcaba Tamés                            */
/*----------------------------------------------------------------------------*/
/* Programa: COLMENA                                                          */
/* Director: Dr. Gustavo Adolfo Medina Tanco                                  */
/*----------------------------------------------------------------------------*/
/* Actualizado                                                                */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/*Cabeceras generales                                                         */
/*----------------------------------------------------------------------------*/

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Semaphore.h>


/* TI-RTOS Header files */
#include <ti/drivers/I2C.h>
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>
#include <ti/drivers/PWM.h>

#include <ti/drivers/timer/GPTimerCC26XX.h>
//#include <ti/drivers/SPI.h>
//#include <ti/drivers/UART.h>
#include <ti/drivers/Watchdog.h>

/* Board Header files */
#include "Board.h"

/*BLE*/


#define TASKSTACKSIZE   512

char nombre[] = { 'R', 'o', 'b', 'o', 't', ' ', '1', '\0' };
Task_Struct BIOS0,sensado,giroFrente;

Char giroStack[TASKSTACKSIZE],sensadoStack[TASKSTACKSIZE],operacionStack[TASKSTACKSIZE];

/* Driver manejador de motor1 */
static PIN_Handle motor1Handle;
static PIN_State motor1State;

/* Driver manejador de motor2 */
static PIN_Handle motor2Handle;
static PIN_State motor2State;

/*Driver manejador de IMU*/
I2C_Handle      IMUhandle;
I2C_Params      IMUparams;
I2C_Transaction i2cTransaction;

/* Configuración de los pines para motores e IMU */

PIN_Config motor1[] = {
    PINCC26XX_DIO18| PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO19| PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO20| PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO21| PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};

PIN_Config motor2[] = {
    PINCC26XX_DIO8 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO9 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO10 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PINCC26XX_DIO11 | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
    PIN_TERMINATE
};

PIN_Config IMU[] = {

};

/**Funciones**/

void bios(UArg arg0, UArg arg1){

}
void avance(UArg arg0, UArg arg1)
{
    System_printf("Iniciando avance\n");
    System_flush();
    while(1){
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO18,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO19,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO20,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO21,0);
    Task_sleep(Clock_tickPeriod);

    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO18,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO19,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO20,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO21,0);
    Task_sleep(Clock_tickPeriod);

    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO18,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO19,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO20,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO21,1);
    Task_sleep(Clock_tickPeriod);

    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO18,1);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO19,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO20,0);
    Task_sleep(Clock_tickPeriod);
    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO21,1);
    Task_sleep(Clock_tickPeriod);
    }

    PIN_setOutputValue(motor1Handle, PINCC26XX_DIO8,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO9,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO10,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO11,0);
    Task_sleep(100*1000/Clock_tickPeriod);

    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO8,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO9,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO10,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO11,0);
    Task_sleep(100*1000/Clock_tickPeriod);

    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO8,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO9,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO10,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO11,1);
    Task_sleep(100*1000/Clock_tickPeriod);

    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO8,1);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO9,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO10,0);
    Task_sleep(100*1000/Clock_tickPeriod);
    PIN_setOutputValue(motor2Handle, PINCC26XX_DIO11,1);
    Task_sleep(100*1000/Clock_tickPeriod);

}

void giroD(UArg arg0, UArg arg1)
{
    System_printf("Iniciando giro hacia la derecha\n");
    System_flush();


}

void giroI(UArg arg0, UArg arg1)
{
    System_printf("Iniciando giro hacia la izquierda\n");
    System_flush();



}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Params giroParams;



    /* Llamado a las funciones de inicializacion de la tarjeta */
    Board_initGeneral();
    Board_initI2C();
    // Board_initSPI();
    // Board_initUART();
    // Board_initWatchdog();
    System_printf("Bienvenido al sistema COLMENA V1.0\n");
    System_printf("%s reportandose\n",nombre);
    System_printf("Iniciando tareas del sistema\n");
    System_printf(".\n.\n.\n.\n.\n.\n.\n");


    /* Abriendo los pines de los motores */

    motor1Handle = PIN_open(&motor1State, motor1);
    motor2Handle = PIN_open(&motor2State, motor2);


    if(!motor1Handle) {
        System_abort("Error iniciando motor 1\n");
    }
    else{
        System_printf("Interface con motor 1 correctamente inicializada\n");
    }

    if(!motor2Handle) {
        System_abort("Error iniciando motor 2\n");
        }
    else{
        System_printf("Interface con motor 2 correctamente inicializada\n");
    }


    /*Abriendo los pines de la IMU*/

    I2C_Params_init(&IMUparams);
    IMUparams.bitRate = I2C_400kHz;
    IMUhandle = I2C_open(Board_I2C_TMP, &IMUparams);
    if (!IMUhandle) {
        System_abort("Error estableciendo comunicacion con la IMU");
    }else
        System_printf("Interface con IMU correctamente inicializada\n");

    /* Iniciando comunicacion con IMU*/

    IMUparams.transferMode  = I2C_MODE_CALLBACK;
    //IMUparams.transferCallbackFxn = someI2CCallbackFunction;
    System_flush();

    /* Construir el hilo de la tarea avance */
    Task_Params_init(&giroParams);
    giroParams.arg0 = 1000000 / Clock_tickPeriod;
    giroParams.stackSize = TASKSTACKSIZE;
    giroParams.stack = &giroStack;
    Task_construct(&giroFrente, (Task_FuncPtr)avance, &giroParams, NULL);

    System_flush();
    /* Iniciando BIOS */
    BIOS_start();
    return (0);
}
