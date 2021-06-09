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
* @file:        lib_crc16.h
* @date:        29 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_crc16
******************************************************************************
*/


#ifndef _LIB_CRC16_H_
#define _LIB_CRC16_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
  * @addtogroup Library The generic library
  * @{
  * @addtogroup lib_crc16 CRC calculations
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
uint16_t LIB_CRC16_Calc(const uint8_t* pBytes,
                        uint16_t  nLength,
                        uint8_t   nInit,
                        bool    bInverted);
/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* _CRC16_H_ */
