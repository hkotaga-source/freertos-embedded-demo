/**
 * @file    freertos_hooks.c
 * @brief   FreeRTOS hook functions
 */

#include "FreeRTOS.h"
#include "task.h"

void vApplicationIdleHook(void)
{
    /* Called when the Idle task is running */
    /* Can be used for low-power mode or background work */
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)xTask;
    (void)pcTaskName;
    /* Stack overflow detected - handle error (blink LED rapidly, etc.) */
    for (;;) {
        /* Stay here */
    }
}

void vApplicationMallocFailedHook(void)
{
    /* Memory allocation failed */
    for (;;) {
        /* Stay here */
    }
}
