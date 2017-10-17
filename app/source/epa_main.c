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
 * @brief       Main EPA implementation
 * @details     Main EPA is invoking all other EPAs in the system.
 * @author      Nenad Radulovic
 *//** @{ */

/*========================================================  INCLUDE FILES  ==*/

#include "epa_main.h"
#include "neon_eds.h"

/*========================================================  LOCAL MACRO's  ==*/
/*=====================================================  LOCAL DATA TYPES  ==*/

struct main_wspace
{
	int a;
};

/*============================================  LOCAL FUNCTION PROTOTYPES  ==*/

static naction state_init(struct nsm *, const struct nevent *);

/*======================================================  LOCAL VARIABLES  ==*/

static NEPA_BUNDLE_DEFINE(main, EPA_MAIN_QUEUE_SIZE, EPA_MAIN_PRIORITY,
    struct main_wspace, state_init, NSM_TYPE_FSM);

/*=====================================================  GLOBAL VARIABLES  ==*/

struct nepa * 					epa_main = NEPA_FROM_BUNDLE(&main);

/*===========================================  LOCAL FUNCTION DEFINITIONS  ==*/

static naction state_init(struct nsm * sm, const struct nevent * event)
{
	switch (nevent_id(event)) {
		case NSM_INIT: {
			return (naction_handled());
		}
		default: {
			return (naction_ignored());
		}
	}
};

/*==========================================  GLOBAL FUNCTION DEFINITIONS  ==*/
/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of epa_main.c
 *===========================================================================*/
