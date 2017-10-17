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
 * @brief       STM32CubeF1 interrupt service routines
 * @details     These routines implement calls to specific HAL functions.
 * @author      Nenad Radulovic
 *//** @{ *//*===============================================================*/

#ifndef STM32F1XX_IT_H_
#define STM32F1XX_IT_H_

/*========================================================  INCLUDE FILES  ==*/
/*==============================================================  MACRO's  ==*/
/*-----------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif
/*===========================================================  DATA TYPES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*==================================================  FUNCTION PROTOTYPES  ==*/

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void SysTick_Handler(void);

/*-------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif
/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of stm32f1xx.h
 *===========================================================================*/
#endif /* STM32F1XX_IT_H_ */
