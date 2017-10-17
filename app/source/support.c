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
 * @brief       Application support package implementation
 * @details     This file contains some helper/support functions.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "stm32_assert.h"
#include "base/debug.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

void assert_failed(uint8_t * file, uint32_t line)
{
	(void)file;
	(void)line;

	for (;;);
}

void hook_at_assert(const char * file, const char * fn, uint32_t line,
    const char * expr)
{
	(void)file;
	(void)fn;
	(void)line;
	(void)expr;

	for (;;);
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of file_name.c
 *===========================================================================*/
