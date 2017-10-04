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
 * @brief       System initialization
 * @details     Function SystemInit() is called before entering the main
 * 				function. Its responsibility is to reset the CPU core to
 * 				defaults and setup the ISR controller.
 *
 * 				This file is based on STM32CubeF1 library v1.6.0.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "stm32f1xx.h"

/*========================================================  LOCAL MACRO's  ==*/

#if !defined(HSE_VALUE)
#error "HSE_VALUE is not defined"
#endif /* !defined(HSE_VALUE) */

#if !defined(HSI_VALUE)
#error "HSI_VALUE is not defined"
#endif /* !defined(HSI_VALUE) */

/* Vector Table base offset field. This value must be a multiple of 0x200. */
#define VECT_TAB_OFFSET  0x00000000u 

/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/

#if defined(STM32F100xB) || defined(STM32F100xE)
uint32_t SystemCoreClock = 24000000u;
#else /* defined(STM32F100xB) || defined(STM32F100xE) */
uint32_t SystemCoreClock = 72000000u;
#endif /* !(defined(STM32F100xB) || defined(STM32F100xE)) */

const uint8_t AHBPrescTable[16u] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8u] =  {0, 0, 0, 0, 1, 2, 3, 4};

/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

/**
 * @brief       Setup the microcontroller system
 *              Initialize the Embedded Flash Interface, the PLL and update the
 *              SystemCoreClock variable.
 * @note        This function should be used only after reset.
 */
void SystemInit(void)
{
    /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
    /* Set HSION bit */
    RCC->CR |= 0x00000001u;

    /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
#if !defined(STM32F105xC) && !defined(STM32F107xC)
    RCC->CFGR &= 0xF8FF0000u;
#else /* !defined(STM32F105xC) && !defined(STM32F107xC) */
    RCC->CFGR &= 0xF0FF0000u;
#endif /* !defined(STM32F105xC) && !defined(STM32F107xC) */
    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= 0xFEF6FFFFU;

    /* Reset HSEBYP bit */
    RCC->CR &= 0xFFFBFFFFU;

    /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
    RCC->CFGR &= 0xFF80FFFFU;

#if defined(STM32F105xC) || defined(STM32F107xC)
    /* Reset PLL2ON and PLL3ON bits */
    RCC->CR &= 0xEBFFFFFFU;

    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x00FF0000u;

    /* Reset CFGR2 register */
    RCC->CFGR2 = 0x00000000u;
#elif defined(STM32F100xB) || defined(STM32F100xE)
    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x009F0000u;

    /* Reset CFGR2 register */
    RCC->CFGR2 = 0x00000000u;
#else
    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0x009F0000u;
#endif
    /* Vector Table Relocation in Internal FLASH. */
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; 
}

/**
 * @brief       Update SystemCoreClock variable according to clock registers.
 *              The SystemCoreClock variable contains the core clock (HCLK), it
 *              can be used by the user application to setup the SysTick timer
 *              or configure other parameters.
 * @note        Each time the core clock (HCLK) changes, this function must be
 *              called to update SystemCoreClock variable value. Otherwise, any
 *              configuration based on this variable will be incorrect.
 * @note        The system frequency computed by this function is not the real
 *              frequency in the chip. It is calculated based on the predefined
 *              constant and the selected clock source:
 *              - If SYSCLK source is HSI, SystemCoreClock will contain the 
 *                HSI_VALUE(*)
 *              - If SYSCLK source is HSE, SystemCoreClock will contain the
 *                HSE_VALUE(**)
 *              - If SYSCLK source is PLL, SystemCoreClock will contain the
 *                HSE_VALUE(**) or HSI_VALUE(*) multiplied by the PLL factors.
 *
 * @note        HSI_VALUE is a constant defined in stm32f1xx.h file (default
 *              value 8 MHz) but the real value may vary depending on the
 *              variations in voltage and temperature.
 * @note        HSE_VALUE is a constant defined in stm32f1xx.h file (default
 *              value 8 MHz or 25 MHz, depending on the product used), user has
 *              to ensure that HSE_VALUE is same as the real frequency of the
 *              crystal used. Otherwise, this function may have wrong result.
 * @note        The result of this function could be not correct when using
 *              fractional value for HSE crystal.
 */
void SystemCoreClockUpdate(void)
{
    uint32_t tmp = 0u;
    uint32_t pllmull = 0u;
    uint32_t pllsource = 0u;

#if defined(STM32F105xC) || defined(STM32F107xC)
    uint32_t prediv1source = 0u;
    uint32_t prediv1factor = 0u;
    uint32_t prediv2factor = 0u;
    uint32_t pll2mull = 0u;
#endif /* defined(STM32F105xC) || defined(STM32F107xC) */

#if defined(STM32F100xB) || defined(STM32F100xE)
    uint32_t prediv1factor = 0u;
#endif /* defined(STM32F100xB) || defined(STM32F100xE) */

    /* Get SYSCLK source */
    tmp = RCC->CFGR & RCC_CFGR_SWS;

    switch (tmp) {
        case 0x00u:  /* HSI used as system clock */
            SystemCoreClock = HSI_VALUE;
            break;
        case 0x04u:  /* HSE used as system clock */
            SystemCoreClock = HSE_VALUE;
            break;
        case 0x08u:  /* PLL used as system clock */
            /* Get PLL clock source and multiplication factor */
            pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
            pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;

#if !defined(STM32F105xC) && !defined(STM32F107xC)
            pllmull = ( pllmull >> 18u) + 2u;

            if (pllsource == 0x00u) {
                /* HSI oscillator clock divided by 2 selected as PLL clock
                 * entry
                 */
                SystemCoreClock = (HSI_VALUE >> 1u) * pllmull;
            } else {
#if defined(STM32F100xB) || defined(STM32F100xE)
                prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1u;
                /* HSE oscillator clock selected as PREDIV1 clock entry */
                SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull; 
#else /* defined(STM32F100xB) || defined(STM32F100xE) */
                /* HSE selected as PLL clock entry */
                if ((RCC->CFGR & RCC_CFGR_PLLXTPRE) != (uint32_t)RESET) {
                    /* HSE oscillator clock divided by 2 */
                    SystemCoreClock = (HSE_VALUE >> 1u) * pllmull;
                } else {
                    SystemCoreClock = HSE_VALUE * pllmull;
                }
#endif /* !(defined(STM32F100xB) || defined(STM32F100xE)) */
            }
#else /* !defined(STM32F105xC) && !defined(STM32F107xC) */
            pllmull = pllmull >> 18u;

            if (pllmull != 0x0du) {
                pllmull += 2u;
            } else {
                /* PLL multiplication factor = PLL input clock * 6.5 */
                pllmull = 13u / 2u; 
            }

            if (pllsource == 0x00u) {
                /* HSI oscillator clock divided by 2 selected as PLL clock
                 * entry
                 */
                SystemCoreClock = (HSI_VALUE >> 1u) * pllmull;
            } else {
                /* PREDIV1 selected as PLL clock entry */
                /* Get PREDIV1 clock source and division factor */
                prediv1source = RCC->CFGR2 & RCC_CFGR2_PREDIV1SRC;
                prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1u;

                if (prediv1source == 0u) {
                    /* HSE oscillator clock selected as PREDIV1 clock entry */
                    SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull;
                } else {
                    /* PLL2 clock selected as PREDIV1 clock entry */
                    /* Get PREDIV2 division factor and PLL2 multiplication
                     * factor
                     */
                    prediv2factor = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> 4u) 
                        + 1u;
                    pll2mull = ((RCC->CFGR2 & RCC_CFGR2_PLL2MUL) >> 8u) + 2u; 
                    SystemCoreClock = (((HSE_VALUE / prediv2factor) * pll2mull) 
                        / prediv1factor) * pllmull;
                }
            }
#endif /* defined(STM32F105xC) || defined(STM32F107xC) */ 
            break;
        default:
            SystemCoreClock = HSI_VALUE;
            break;
    }

    /* Compute HCLK clock frequency */
    /* Get HCLK prescaler */
    tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4u)];
    /* HCLK clock frequency */
    SystemCoreClock >>= tmp;
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of system_stm32f1xx.c
 *===========================================================================*/
