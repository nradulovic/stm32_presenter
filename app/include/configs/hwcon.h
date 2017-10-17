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
 * @brief       Hardware configuration header
 * @details     This header defines all hardware variables need to accomodate
 *              the hardware. This is done to allow for easy firmware
 *              reconfiguration to different hardware layout.
 *
 *              The configuration is mostly done by macros.
 * @author      Nenad Radulovic
 *//** @{ *//*===============================================================*/

#ifndef APP_CONFIGS_HWCON_H_
#define APP_CONFIGS_HWCON_H_

/*========================================================  INCLUDE FILES  ==*/
/*==============================================================  MACRO's  ==*/

/* NOTE:
 * Priority levels are arranged as per ARM Cortex-M NVIC datasheet: the lower
 * the value the higher the priority of IRQ is.
 */
#define HWCON_IRQ_PRIO_NEON             6

/*-----------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif
/*===========================================================  DATA TYPES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*==================================================  FUNCTION PROTOTYPES  ==*/
/*-------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif
/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of hwcon.h
 *===========================================================================*/
#endif /* APP_CONFIGS_HWCON_H_ */
