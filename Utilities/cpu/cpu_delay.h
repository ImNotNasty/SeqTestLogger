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
* @file:        cpu_delay.h
* @date:        21 nov. 2018
* @author:      Onkelinx Ghislain
* @brief:
*
******************************************************************************
* History
******************************************************************************
*
******************************************************************************
*/


#ifndef _CPU_DELAY_H_
#define _CPU_DELAY_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>
#if defined(osCMSIS)
  #include "cmsis_os.h"
#endif

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
 /** Available delay units for BSP_SoftwareDelay().
  * These are ultimately used to calculate a total # of microseconds
  */
 typedef enum
 {
     BSP_DELAY_UNITS_SECONDS =      1000000,  /*<! Requested delay amount is in seconds */
     BSP_DELAY_UNITS_MILLISECONDS = 1000,     /*<! Requested delay amount is in milliseconds */
     BSP_DELAY_UNITS_MICROSECONDS = 1         /*<! Requested delay amount is in microseconds */
 } bsp_delay_units_t;

/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
#if defined(osCMSIS)  // USE_RTOS_SYSTICK
  #define DELAY_MS(x)       osDelay(x)
#else
  #define DELAY_MS(x)       BSP_SoftwareDelay(x, BSP_DELAY_UNITS_MILLISECONDS)
#endif

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
void BSP_SoftwareDelay(uint32_t delay, bsp_delay_units_t units);

#ifdef __cplusplus
}
#endif
#endif /* _CPU_DELAY_H_ */
