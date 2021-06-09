/**
******************************************************************************
* @copyright
* <h2><center>&copy; Copyright 2019 </center></h2>
* All rights reserved. Company Name's source code is an unpublished work and
* the use of a copyright notice does not imply otherwise. This source code
* contains confidential. Any attempt or
* participation in deciphering, decoding, reverse engineering or in any way
* altering the source code is strictly prohibited.
*
* @file        cmsis_device.h
* @date        28 mrt. 2019
* @author      G.Onkelinx
* @brief
*
******************************************************************************
*/

#ifndef _CMSIS_DEVICE_H_
#define _CMSIS_DEVICE_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined(STM32G474xx)
  #include "stm32g474xx.h"
  #include "stm32g4xx_hal.h"

#elif defined(STM32H743xx)
  #include "stm32H743xx.h"
  #include "stm32H7xx_hal.h"

#elif defined(STM32L010x8)

 #include "stm32l010x8.h"
 #include "stm32l0xx_hal.h"
 //#include "stm32g4xx_ll_system.h"
 //#include "stm32l0xx_ll_utils.h"

#else
 #error "CPU not defined yet"
#endif


/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* _CMSIS_DEVICE_H_ */
