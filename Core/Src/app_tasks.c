/**
 * @file    app_tasks.c
 * @brief   Application tasks, queue and software timer
 */

#include "app_tasks.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Queue handle */
static QueueHandle_t xMessageQueue = NULL;

/* Software timer handle */
static TimerHandle_t xLedTimer = NULL;

/* Task handles */
static TaskHandle_t xProducerTaskHandle = NULL;
static TaskHandle_t xConsumerTaskHandle = NULL;

/* Simple message structure */
typedef struct {
    uint32_t id;
    char text[32];
} message_t;

/*-------------------- Software Timer Callback --------------------*/
static void led_timer_callback(TimerHandle_t xTimer)
{
    (void)xTimer;
    /* Toggle LED here */
    /* bsp_led_toggle(); */
}

/*-------------------- Producer Task --------------------*/
static void producer_task(void *pvParameters)
{
    (void)pvParameters;
    message_t msg;
    uint32_t counter = 0;

    for (;;) {
        msg.id = counter++;
        /* Simple message */
        msg.text[0] = 'M';
        msg.text[1] = 'S';
        msg.text[2] = 'G';
        msg.text[3] = '\0';

        if (xQueueSend(xMessageQueue, &msg, pdMS_TO_TICKS(100)) == pdPASS) {
            /* Message sent successfully */
        }

        vTaskDelay(pdMS_TO_TICKS(1000));   /* Produce every 1 second */
    }
}

/*-------------------- Consumer Task --------------------*/
static void consumer_task(void *pvParameters)
{
    (void)pvParameters;
    message_t received;

    for (;;) {
        if (xQueueReceive(xMessageQueue, &received, portMAX_DELAY) == pdPASS) {
            /* Process the message */
            /* Example: print via UART or log */
            (void)received;
        }
    }
}

/*-------------------- Public API --------------------*/
void app_tasks_create(void)
{
    /* Create queue that can hold 5 messages */
    xMessageQueue = xQueueCreate(5, sizeof(message_t));

    /* Create software timer - auto reload every 500 ms */
    xLedTimer = xTimerCreate(
        "LedTimer",
        pdMS_TO_TICKS(500),
        pdTRUE,                 /* Auto reload */
        NULL,
        led_timer_callback
    );

    if (xLedTimer != NULL) {
        xTimerStart(xLedTimer, 0);
    }

    /* Create producer task */
    xTaskCreate(
        producer_task,
        "Producer",
        256,
        NULL,
        tskIDLE_PRIORITY + 2,
        &xProducerTaskHandle
    );

    /* Create consumer task */
    xTaskCreate(
        consumer_task,
        "Consumer",
        256,
        NULL,
        tskIDLE_PRIORITY + 1,
        &xConsumerTaskHandle
    );
}
