/*
 * bsp.c
 *
 *  Created on: Oct 11, 2017
 *      Author: nenad
 */

#include "bsp.h"
#include "stm32f1xx.h"

void bsp_init(void)
{
	HAL_Init();
}
