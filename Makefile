# Simple Makefile placeholder for FreeRTOS project
# Adapt this to your specific MCU and toolchain

TARGET = freertos_demo
BUILD_DIR = build

PREFIX = arm-none-eabi-
CC = $(PREFIX)gcc

# Add your MCU flags, include paths and FreeRTOS source files here

all:
	@echo "Please configure the Makefile for your target MCU and FreeRTOS path."
	@echo "Typical command: make with proper CFLAGS and FreeRTOS sources."

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
