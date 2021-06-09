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
* @file        lib_fir_coefs.h
* @date        9 jul. 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup lib_fir
******************************************************************************
*/


#ifndef _FIR_COEFS_H_
#define _FIR_COEFS_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @addtogroup lib_fir FIR
 * @{
 * @brief The file contain the different coefficients table that can be used
 *        for the FIR filter.
 *        The values can be calculated with the tool WinFilter
 *        <a href="http://www.winfilter.20m.com">Winfilter</a>
 ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "lib_fir.h"

/* Public define -------------------------------------------------------------*/
#define LIBFIR_FLT_1HZ12TAP_SIZE  (12)
#define LIBFIR_FLT_1HZ20TAP_SIZE  (20)

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/*******************************************************
 *             Filter
 *******************************************************
 * @brief
 * Filter type             : Low Pass
 * Filter model            : Bessel
 * Filter order            : 16
 * Filter N TAP            : 12
 * Sampling Frequency      : 8 Hz
 * Cut Frequency           : 1 Hz
 * Coefficients Quantization: Signed 16-bit
 *******************************************************/
 const LIBFIR_Coefs_t LIBFIR_Filter1Hz12Taps = {
   .nTap          = LIBFIR_FLT_1HZ12TAP_SIZE,  /*!< FIR-filter N tap         */
   .DCgain_Shifts = 17U,  /*!< FIR-filter DCgain shifts 2^18 or 262144 */
   {                      /*!< FIR-filter Coef          */
      3749,
      7064,
     11121,
     15130,
     18100,
     19197,
     18100,
     15130,
     11121,
      7064,
      3749,
      1542
   }
 };

/*******************************************************
 *             Filter
 *******************************************************
 * @brief
 * Filter type             : Low Pass
 * Filter model            : Bessel
 * Filter order            : 16
 * Filter N TAP            : 12
 * Sampling Frequency      : 8 Hz
 * Cut Frequency           : 1 Hz
 * Coefficients Quantization: Signed 16-bit
 *******************************************************/
 const LIBFIR_Coefs_t LIBFIR_Filter1Hz20Taps = {
   .nTap          = LIBFIR_FLT_1HZ20TAP_SIZE,  /*!< FIR-filter N tap         */
   .DCgain_Shifts = 15U,  /*!< FIR-filter DCgain shifts 2^18 or 262144 */
   {                      /*!< FIR-filter Coef          */
      3276,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      1638,
      0
   }
 };

/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

 /** @} */
 /** @} */

#ifdef __cplusplus
}
#endif
#endif /* _FIR_COEFS_H_ */
