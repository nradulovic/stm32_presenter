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
 * @brief       Main file
 * @details     This is where it all begins.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "main.h"
#include "neon_eds.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/
/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/
/*======================================================  LOCAL VARIABLES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/
/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/

struct epa_test_wspace
{
    int a;
};

static NQUEUE_BUNDLE_DEFINE(epa_test_equeueg, 16);
static NSM_BUNDLE_DEFINE(epa_test_smh, struct epa_test_wspace, NULL, NSM_TYPE_FSM);

static NEPA_BUNDLE_DEFINE(epa_test, 16, 1, struct epa_test_wspace, NULL, NSM_TYPE_HSM);

int main (void)
{
    return (0);
}

/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of main.c
 *===========================================================================*/
