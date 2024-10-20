#include "profile.h"

#include "stm32l0xx_ll_gpio.h"
#define GPIO_PROFILE_PORT GPIOD
#define GPIO_PROFILE_PIN LL_GPIO_PIN_9

#define GPIO_PROFILE GPIO_PROFILE_PORT, GPIO_PROFILE_PIN

void profileEnable() {
    LL_GPIO_InitTypeDef profile = {.Pin = GPIO_PROFILE_PIN,
                                   .Mode = LL_GPIO_MODE_OUTPUT,
                                   .Speed = LL_GPIO_SPEED_FREQ_LOW,
                                   .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
                                   .Pull = LL_GPIO_PULL_NO,
                                   .Alternate = LL_GPIO_AF_0};
    LL_GPIO_Init(GPIO_PROFILE_PORT, &profile);
    LL_GPIO_SetOutputPin(GPIO_PROFILE);
}

void profileStart() {
    LL_GPIO_TogglePin(GPIO_PROFILE);
    LL_GPIO_TogglePin(GPIO_PROFILE);
}
void profileStop() { LL_GPIO_TogglePin(GPIO_PROFILE); }
