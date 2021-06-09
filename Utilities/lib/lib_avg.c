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
* @file        lib_avg.c
* @date        10 mei 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup lib_avg
******************************************************************************
*/

/***************************************************************************//**
 * @defgroup Library The generic library
 * @{
 * @defgroup lib_avg Averages
 * @brief The generic library component for averaging
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lib_avg.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/***************************************************************************//**
* @brief This function
* @param[in,out] hdlr: handler of the current instance of the average component
*                @ref LIBAVG_Handle_t
* @param[in] avgSize The size of the average samples
* @retval false error detected during initialization
*         true  successful
* @note
*******************************************************************************/
bool LIBAVG_Init(LIBAVG_Handle_t *hdlr, uint8_t avgSize) {
  bool bRetValue = true;

  ASSERT_PARAM(hdlr != pNull);

  memset(&hdlr->buffer, 0, sizeof(LIBAVG_buffer_t));
  hdlr->result = 0;
  hdlr->avgsize = avgSize;

  if (hdlr->avgsize > LIBAVG_AVG_MAX_SIZE) {
    hdlr->avgsize = LIBAVG_AVG_MAX_SIZE;
    bRetValue = false;
  }

  return (bRetValue);
}

/***************************************************************************//**
* @brief This function
* @param[in,out] hdlr: handler of the current instance of the average component
*                @ref LIBAVG_Handle_t
* @retval uint16_t CRC (returned the CRC result)
* @note
*******************************************************************************/
uint16_t LIBAVG_GetResult(LIBAVG_Handle_t *hdlr) {
  uint32_t total = 0U;
  uint8_t cnt = hdlr->avgsize;
  const uint16_t *pBuf = hdlr->buffer.value;

  ASSERT_PARAM(hdlr != pNull);

  while (cnt-- > 0 ) {
    total += *pBuf++;
  }

  if ((hdlr->avgsize != 0) &&
      (hdlr->avgsize <= LIBAVG_AVG_MAX_SIZE)) {
    hdlr->result = (uint16_t)(total / hdlr->avgsize);
  } else {
    hdlr->result = 0;
  }
  return (hdlr->result);
}

/***************************************************************************//**
* @brief This function
* @param[in,out] hdlr: handler of the current instance of the average component
*                @ref LIBAVG_Handle_t
* @param[in] value The new value to be added
* @note
*******************************************************************************/
void LIBAVG_Handle(LIBAVG_Handle_t *hdlr, uint16_t value) {

  ASSERT_PARAM(hdlr != pNull);

  if ((hdlr->buffer.actPos >= hdlr->avgsize) ||
      (hdlr->buffer.actPos >= LIBAVG_AVG_MAX_SIZE)) {
    hdlr->buffer.actPos = 0;
  }
  hdlr->buffer.value[hdlr->buffer.actPos++] = value;
}

/** @} */
/** @} */

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lim_avg.c file
*******************************************************************************
*/
