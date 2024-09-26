cmake_minimum_required(VERSION 3.30)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(CXX ASM)

target_compile_definitions(
    stm32cubemx INTERFACE USE_HAL_DRIVER STM32L010xB STM32_THREAD_SAFE_STRATEGY=4
                          $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(
    stm32cubemx
    INTERFACE
        ../../Core/Inc
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Inc
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Inc/Legacy
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/include
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/CMSIS/Device/ST/STM32L0xx/Include
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/CMSIS/Include
)

target_sources(
    stm32cubemx
    INTERFACE
        ../../Core/Src/main.cpp
        ../../Core/Src/gpio.cpp
        ../../Core/Src/freertos.cpp
        ../../Core/Src/tim.cpp
        ../../Core/Src/usart.cpp
        ../../Core/Src/stm32l0xx_it.cpp
        ../../Core/Src/stm32l0xx_hal_msp.cpp
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c_ex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ramfunc.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_flash_ex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_exti.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim_ex.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart_ex.c
        ../../Core/Src/system_stm32l0xx.cpp
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/list.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/queue.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/timers.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
        /home/ksolomon/STM32Cube/Repository/STM32Cube_FW_L0_V1.12.2/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c
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
