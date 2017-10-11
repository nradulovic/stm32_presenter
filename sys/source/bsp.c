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
 * @brief       Board Support Package implementation
 * @details     Package that encapsulates some of HAL functions.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "bsp.h"
#include "stm32f1xx.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

void bsp_init(void)
{
	HAL_Init();
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of file_name.c
 *===========================================================================*/
