cmake_minimum_required(VERSION 3.30)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(CXX ASM)

target_compile_definitions(
    stm32cubemx
    INTERFACE USE_HAL_DRIVER
              USE_FULL_LL_DRIVER
              STM32L010xB
              STM32_THREAD_SAFE_STRATEGY=4
              $<$<CONFIG:Debug>:DEBUG>
)

set(cube "/home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2")

target_include_directories(
    stm32cubemx
    INTERFACE ../../Core/Inc
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Inc
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/include
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0
              ${cube}/Drivers/CMSIS/Device/ST/STM32L0xx/Include
              ${cube}/Drivers/CMSIS/Include
)

target_sources(
    stm32cubemx
    INTERFACE ../../Core/Src/main.cpp
              ../../Core/Src/tasks/freertos.cpp
              ../../Core/Src/tasks/heartbeat.cpp
              ../../Core/Src/drivers/profile.cpp
              ../../Core/Src/drivers/com.cpp
              ../../Core/Src/drivers/gpio.cpp
              ../../Core/Src/drivers/tim.cpp
              ../../Core/Src/drivers/usart.cpp
              ../../Core/Src/stm32l0xx_it.cpp
              ../../Core/Src/stm32l0xx_hal_msp.cpp
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c_ex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ramfunc.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_exti.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim_ex.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_ll_usart.c
              ${cube}/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart_ex.c
              ../../Core/Src/system_stm32l0xx.cpp
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/list.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/queue.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/timers.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
              ${cube}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
              ../../Core/Src/sysmem.cpp
              ../../Core/Src/syscalls.cpp
              ../../startup_stm32l010xb.s
)

target_link_directories(stm32cubemx INTERFACE)

target_link_libraries(stm32cubemx INTERFACE)

# Validate that STM32CubeMX code is compatible with C standard
if (CMAKE_CXX_STANDARD LESS 20)
    message(ERROR "Generated code requires C++20 or higher")
endif ()
