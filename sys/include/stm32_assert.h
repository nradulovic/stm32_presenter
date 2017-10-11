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
 * @brief       STM32CubeF1 assert handling
 * @details     STM32 library is using assert macro defined in this file.
 * @author      Nenad Radulovic
 *//** @{ *//*===============================================================*/

#ifndef STM32_ASSERT_H_
#define STM32_ASSERT_H_

/*========================================================  INCLUDE FILES  ==*/

#include <stdint.h>

/*==============================================================  MACRO's  ==*/

#ifdef  USE_FULL_ASSERT
/**
  * @brief      The assert_param macro is used for function's parameters check.
  * @param      expr: If expr is false, it calls assert_failed function which
  *             reports the name of the source file and the source line number
  *             of the call that failed. If expr is true, it returns no value.
  */
#define assert_param(expr)                                                      \
    ((expr) ? (void)0u : assert_failed((uint8_t *)__FILE__, __LINE__))
#else
#define assert_param(expr)              ((void)0u)
#endif /* USE_FULL_ASSERT */


/*-----------------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*===========================================================  DATA TYPES  ==*/
/*=====================================================  GLOBAL VARIABLES  ==*/
/*==================================================  FUNCTION PROTOTYPES  ==*/

void assert_failed(uint8_t * file, uint32_t line);

/*-------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif
/*===============================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//*===================================================*
 * END of stm32_assert.h
 *===========================================================================*/
#endif /* STM32_ASSERT_H_ */
