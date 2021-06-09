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
* @file:        lib_string.h
* @date:        16 jun. 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_strings
******************************************************************************
*/


#ifndef _LIB_STRING_H_
#define _LIB_STRING_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @addtogroup lib_strings
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
#define  STR_CR_LF                     "\r\n"
#define  STR_LF_CR                     "\n\r"
#define  STR_NEW_LINE                   STR_CR_LF

#define  STR_CR_LF_LEN                 (sizeof(STR_CR_LF)       - 1)
#define  STR_LF_CR_LEN                 (sizeof(STR_LF_CR)       - 1)
#define  STR_NEW_LINE_LEN              (sizeof(STR_NEW_LINE)    - 1)

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
uint16_t Str_Len_N(const uint8_t *pstr,  uint16_t len_max);
int8_t  *Str_Copy_N(int8_t *pstr_dest,
                    const int8_t *pstr_src,
                    int16_t len_max);

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* _DUALLINE_SRC_BLOCKS_LIB_STRING_H_ */
