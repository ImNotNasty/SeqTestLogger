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
* @file:        lib_hysteresis.h
* @date:        10 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_hysteresis
******************************************************************************
*/


#ifndef _LIB_HYSTERESIS_H_
#define _LIB_HYSTERESIS_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
  * @addtogroup Library The generic library
  * @{
  * @addtogroup lib_hysteresis
  * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
 typedef struct {
   uint16_t iUpHyst;
   uint16_t iDownHyst;
   uint16_t oResult;
 } limhyst_Handle_t;

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
void LIBHYST_Init(limhyst_Handle_t * hdlr);
void LIBHYST_Handler(limhyst_Handle_t * hdlr, uint16_t value);

/** @} */
/** @} */
#ifdef __cplusplus
}
#endif
#endif /* _LIB_HYSTERESIS_H_ */
