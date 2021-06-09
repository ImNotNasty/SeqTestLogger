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
* @file:        lib_scale.h
* @date:        8 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_scale
******************************************************************************
*/


#ifndef _LIB_SCALE_H_
#define _LIB_SCALE_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @addtogroup lib_scale
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
 uint16_t LIBSC_ScaleU(const uint16_t value,
                       const uint16_t fromMin,
                       const uint16_t fromMax,
                       const uint16_t toMin,
                       const uint16_t toMax);

 int16_t LIBSC_ScaleS16(const int16_t value,
                        const int16_t fromMin,
                        const int16_t fromMax,
                        const int16_t toMin,
                        const int16_t toMax);

 /** @} */
 /** @} */
#ifdef __cplusplus
}
#endif
#endif /* _LIB_SCALE_H_ */
