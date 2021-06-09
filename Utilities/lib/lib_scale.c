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
* @file:        lib_scale.c
* @date:        8 may 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_scale
******************************************************************************
*/

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @defgroup lib_scale Scaling values
 * @brief The generic library component for scaling
 *        With these functions it is possible to scale the value from a specific
 *        range to another range.
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lib_scale.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value: the value to be checked
* @param[in] fromMin:   the lower limit of the existing value
* @param[in] fromMax:   the upper limit of the existing value
* @param[in] toMin:     the lower limit to scale the new value
* @param[in] toMax:     the upper limit to scale the new value
* @note
*******************************************************************************/
uint16_t LIBSC_ScaleU(const uint16_t value,
                      const uint16_t fromMin,
                      const uint16_t fromMax,
                      const uint16_t toMin,
                      const uint16_t toMax) {
  uint16_t result1;
  uint32_t result;
  uint16_t newValue = value;

  /* protect input range */
  if (newValue < fromMin) {
    newValue = fromMin;
  } else if (newValue > fromMax) {
    newValue = fromMax;
  }

  /**
   * @f[
   * y = y0 + ((y1 - y0) * (x - x0) / (x1 - x0))
   * @f]
   *
   * where x is the existing range
   *       y is the new range
   */
  result1 = (uint16_t)(fromMax - fromMin);
  result  = (uint32_t)((toMax - toMin) * (newValue - fromMin));
  result /= result1;
  result += toMin;

  return ((uint16_t)result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value: the value to be checked
* @param[in] fromMin:   the lower limit of the existing value
* @param[in] fromMax:   the upper limit of the existing value
* @param[in] toMin:     the lower limit to scale the new value
* @param[in] toMax:     the upper limit to scale the new value
* @note
*******************************************************************************/
int16_t LIBSC_ScaleS16(const int16_t value,
                       const int16_t fromMin,
                       const int16_t fromMax,
                       const int16_t toMin,
                       const int16_t toMax) {
  int16_t result1;
  int32_t result;
  int16_t newValue = value;

  /* protect input range */
  if (newValue < fromMin) {
    newValue = fromMin;
  } else if (newValue > fromMax) {
    newValue = fromMax;
  }

  /**
   * @f[
   * y = y0 + ((y1 - y0) * (x - x0) / (x1 - x0))
   * @f]
   *
   * where x is the existing range
   *       y is the new range
   */
  result1 = (int16_t)(fromMax - fromMin);
  result  = (int32_t)((toMax - toMin) * (newValue - fromMin));
  result /= result1;
  result += toMin;

  return ((int16_t)result);
}

/** @} */
/** @} */

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_scale.c file
*******************************************************************************
*/
