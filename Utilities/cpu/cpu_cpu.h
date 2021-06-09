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
* @file        cpu_cpu.h
* @date        28 mrt. 2019
* @author      G.Onkelinx
* @brief
*
******************************************************************************
*/

#ifndef _CPU_CPU_H_
#define _CPU_CPU_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "cmsis_device.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
typedef  uint32_t        CPU_SR;   /*!< Defines CPU status register size */
typedef  char            CPU_CHAR; /*!< Define char */

/* Public macro --------------------------------------------------------------*/
#define CPU_INT_DIS()    __disable_irq()   /*!< Disable interruptions macro */
#define CPU_INT_EN()     __enable_irq()    /*!< Enable interruptions macro */

#define  CPU_SR_ALLOC()  CPU_SR  cpu_sr = (CPU_SR)0

#if defined ( __GNUC__ )
 /* Save    CPU status word & disable interrupts.*/
#define  CPU_CRITICAL_ENTER()  do { cpu_sr =  __get_PRIMASK(); \
                                    CPU_INT_DIS(); \
                                  } while (0)

/* Restore CPU status word. */
#define  CPU_CRITICAL_EXIT()   do { __set_PRIMASK(cpu_sr); \
                                  } while (0)
#else
  #error "Not defined yet for this compiler"
#endif

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* _CPU_CPU_H_ */
