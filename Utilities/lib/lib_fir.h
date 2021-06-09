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
* @file:        lib_fir.h
* @date:        9 jul. 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_fir
******************************************************************************
*/


#ifndef _LIB_FIR_H_
#define _LIB_FIR_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @addtogroup lib_fir
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
 PACK_PUSH(1)
 typedef struct
 {
     const uint8_t nTap;                       /*!< Filter N TAP               */
     const uint8_t DCgain_Shifts;              /*!< Filter DC gain shifts      */
     const int16_t Coef[];                     /*!< Filter coefficients buffer */
 } LIBFIR_Coefs_t;

 typedef struct {
   const LIBFIR_Coefs_t *params;
   int16_t *pBuffer;
 } LIBFIR_Handle_t;
 PACK_POP

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
 void    LIBFIR_Init(LIBFIR_Handle_t *hdlr,
                     const LIBFIR_Coefs_t  *coefs,
                     int16_t         *pBuffer,
                     int16_t          initValue);
 int16_t LIBFIR_Handler(LIBFIR_Handle_t *hdlr,
                        int16_t sample);

 /** @} */
 /** @} */
#ifdef __cplusplus
}
#endif
#endif /* _LIB_FIR_H_ */
