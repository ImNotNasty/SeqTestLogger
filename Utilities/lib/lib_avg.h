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
* @file:        lib_avg.h
* @date:        10 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_avg
******************************************************************************
*/


#ifndef _LIB_AVG_H_
#define _LIB_AVG_H_

#ifdef __cplusplus
 extern "C" {
#endif

/***************************************************************************//**
  * @addtogroup Library The generic library
  * @{
  * @addtogroup lib_avg Averages
  * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
#define LIBAVG_AVG_MAX_SIZE  (32)

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/

/**
  * @brief Handle of a average buffer
  * @details This structure stores all the parameters needed to perform a average buffer.
  */
 PACK_PUSH(1)
typedef struct {
  uint16_t  value[LIBAVG_AVG_MAX_SIZE];
  uint16_t  actPos;
} LIBAVG_buffer_t;
PACK_POP

/**
  * @brief Handle of a average component
  * @details This structure stores all the parameters needed to perform a average computation.
  * This structure is passed to each average component function.
  */
PACK_PUSH(1)
typedef struct {
  uint8_t avgsize;
  LIBAVG_buffer_t buffer;
  uint16_t result;
} LIBAVG_Handle_t;
PACK_POP

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
bool     LIBAVG_Init(LIBAVG_Handle_t *hdlr, uint8_t avgSize);
uint16_t LIBAVG_GetResult(LIBAVG_Handle_t *hdlr);
void     LIBAVG_Handle(LIBAVG_Handle_t *hdlr, uint16_t value);

/** @} */
/** @} */

#ifdef __cplusplus
}
#endif
#endif /* _DUALLINE_SRC_BLOCKS_LIM_AVG_H_ */
