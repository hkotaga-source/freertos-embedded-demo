# FreeRTOS Embedded Demo

A clean **FreeRTOS** demonstration project written in Embedded C.

This project shows common FreeRTOS patterns used in real products:

- Multiple tasks with different priorities
- Queue for inter-task communication
- Software timer
- Simple GPIO / LED control
- Idle hook example

## Features

| Feature              | Description                              |
|----------------------|------------------------------------------|
| Task creation        | Two application tasks + Idle task        |
| Queue                | Producer / Consumer pattern              |
| Software Timer       | Periodic LED blink without blocking      |
| Priority scheduling  | Demonstrates preemptive scheduling       |

## Project Structure

```
freertos-embedded-demo/
├── README.md
├── Makefile
├── Core/
│   ├── Src/
│   │   ├── main.c
│   │   ├── freertos_hooks.c
│   │   └── app_tasks.c
│   └── Inc/
│       ├── main.h
│       └── app_tasks.h
└── FreeRTOS/                 # Place FreeRTOS kernel here
    ├── Source/
    └── Config/
        └── FreeRTOSConfig.h
```

## How to use

1. Download FreeRTOS kernel from https://www.freertos.org
2. Place the `Source` folder inside `FreeRTOS/`
3. Copy a suitable `FreeRTOSConfig.h` into `FreeRTOS/Config/`
4. Build with the provided Makefile (after adapting for your MCU)

## Learning Goals

- Understand task states and priorities
- Use queues safely between tasks
- Use software timers instead of blocking delays where possible
- Write clean FreeRTOS application code

## Target

Designed for Cortex-M (STM32, etc.) but the application logic is portable.
