// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include_next <mcuconf.h>

#undef STM32_LSE_ENABLED
#define STM32_LSE_ENABLED TRUE

#undef STM32_RTCSEL
#define STM32_RTCSEL STM32_RTCSEL_LSE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE
