/*
 * Presenter
 *
 *===========================================================================*
 *
 * Copyright (C) 2017 Nenad Radulovic
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *//**
 * @file
 * @brief       STM32CubeF1 support file
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include <stdbool.h>

#include "main.h"
#include "stm32f1xx.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/

static void hw_error(void);
static void setup_clock_mcu(void);

/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/

static void hw_error(void)
{
    while(true);
}

/**
 * @brief       System Clock Configuration
 *              The system Clock is configured as follows:
 *              * HSE Frequency(Hz)     = 8000000
 *              * System Clock source   = PLL (HSE)
 *              * SYSCLK(Hz)            = 72000000
 *              * HCLK(Hz)              = 72000000
 *              * AHB Prescaler         = 1
 *              * APB1 Prescaler        = 2
 *              * APB2 Prescaler        = 1
 *              * PLLMUL                = 9
 *              * Flash Latency(WS)     = 2
 */
static void setup_clock_mcu(void)
{
    RCC_ClkInitTypeDef clkinitstruct = {0};
    RCC_OscInitTypeDef oscinitstruct = {0};
    RCC_PeriphCLKInitTypeDef rccperiphclkinit = {0};

    /* Main oscillator setup */
    oscinitstruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
    oscinitstruct.HSEState        = RCC_HSE_ON;
    oscinitstruct.HSEPredivValue  = RCC_HSE_PREDIV_DIV1;
    oscinitstruct.PLL.PLLState    = RCC_PLL_ON;
    oscinitstruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;
    oscinitstruct.PLL.PLLMUL      = RCC_PLL_MUL9;

    if (HAL_RCC_OscConfig(&oscinitstruct) != HAL_OK) {
        hw_error();
    }

    /* USB clock selection */
    rccperiphclkinit.PeriphClockSelection = RCC_PERIPHCLK_USB;
    rccperiphclkinit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;

    if (HAL_RCCEx_PeriphCLKConfig(&rccperiphclkinit) != HAL_OK) {
        hw_error();
    }

    /* ADC clock selection */
    rccperiphclkinit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
    rccperiphclkinit.AdcClockSelection = RCC_ADCPCLK2_DIV6;

    if (HAL_RCCEx_PeriphCLKConfig(&rccperiphclkinit) != HAL_OK) {
        hw_error();
    }

    /* System clock slection */
    clkinitstruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                               RCC_CLOCKTYPE_PCLK1  | RCC_CLOCKTYPE_PCLK2);
    clkinitstruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clkinitstruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clkinitstruct.APB2CLKDivider = RCC_HCLK_DIV1;
    clkinitstruct.APB1CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&clkinitstruct, FLASH_LATENCY_2) != HAL_OK) {
        hw_error();
    }
}

static void teardown_clock_mcu()
{
    HAL_RCC_DeInit();
}


/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

void HAL_MspInit(void)
{
    setup_clock_mcu();
}


void HAL_MspDeInit(void)
{
    teardown_clock_mcu();
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of stm32f1xx_hal_msp.c
 *===========================================================================*/
