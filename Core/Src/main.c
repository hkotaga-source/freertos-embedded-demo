/**
 * @file    main.c
 * @brief   FreeRTOS Embedded Demo - Entry point
 */

#include "main.h"
#include "app_tasks.h"

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"

int main(void)
{
    /* Hardware initialization would go here (clocks, GPIO, etc.) */
    /* bsp_init(); */

    /* Create application tasks */
    app_tasks_create();

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never reach here */
    while (1) {
    }

    return 0;
}
