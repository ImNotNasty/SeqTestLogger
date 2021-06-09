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
* @file:        lib_range.h
* @date:        8 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_range
******************************************************************************
*/


#ifndef _LIB_RANGE_H_
#define _LIB_RANGE_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @addtogroup lib_range
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

 int32_t LIBRNG_MinMaxS32(const int32_t value,
                          const int32_t minValue,
                          const int32_t maxValue);

 uint32_t LIBRNG_MinMaxU32(const uint32_t value,
                           const uint32_t minValue,
                           const uint32_t maxValue);

 uint16_t LIBRNG_MinMaxU16(const uint32_t value,
                           const uint16_t minValue,
                           const uint16_t maxValue);
 uint16_t LIBRNG_MaxU16(const uint32_t value,
                        const uint16_t maxValue);
 uint32_t LIBRNG_MaxU32(const uint32_t value,
                        const uint32_t maxValue) ;
 int16_t  LIBRNG_MinMaxS16(const int32_t value,
                           const int16_t minValue,
                           const int16_t maxValue);
 bool     LIBRNG_IsOutRangeS16(const int32_t value,
                               const int16_t minValue,
                               const int16_t maxValue);
 bool     LIBRNG_IsOutRangeU16(const uint32_t value,
                               const uint16_t minValue,
                               const uint16_t maxValue);
 bool     LIBRNG_IsOutRangeU32(const uint32_t value,
                               const uint32_t minValue,
                               const uint32_t maxValue);
 bool     LIBRNG_IsOutRangeS32(const int32_t value,
                               const int32_t minValue,
                               const int32_t maxValue);
 /** @} */
 /** @} */
#ifdef __cplusplus
}
#endif
#endif /* _LIB_RANGE_H_ */
