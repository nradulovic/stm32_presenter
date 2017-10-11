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
 * @brief       STM32CubeF1 interrupt service routines implementation.
 * @details     These routines implement calls to specific HAL functions.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "main.h"
#include "stm32f1xx.h"
#include "stm32f1xx_it.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1);
}

void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1);
}

void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1);
}

void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1);
}

void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
    HAL_IncTick();
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of stm32f1xx_it.c
 *===========================================================================*/
