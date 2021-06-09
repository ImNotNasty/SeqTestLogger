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
* @file:        lib_range.c
* @date:        8 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_range
******************************************************************************
*/

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @defgroup lib_range Limit ranges
 * @brief The generic library component for range
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lib_range.h"

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
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval returns the value within the range, limited to his max en min value
* @note
*******************************************************************************/
uint32_t LIBRNG_MinMaxU32(const uint32_t value,
                          const uint32_t minValue,
                          const uint32_t maxValue) {
  uint32_t result = value;

  if (value <= minValue) {
    result = minValue;
  } else if (value >= maxValue) {
    result = maxValue;
  }
  return (result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval returns the value within the range, limited to his max en min value
* @note
*******************************************************************************/
int32_t LIBRNG_MinMaxS32(const int32_t value,
                         const int32_t minValue,
                         const int32_t maxValue) {
  int32_t result = value;

  if (value <= minValue) {
    result = minValue;
  } else if (value >= maxValue) {
    result = maxValue;
  }
  return (result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval returns the value within the range, limited to his max en min value
* @note
*******************************************************************************/
uint16_t LIBRNG_MinMaxU16(const uint32_t value,
                          const uint16_t minValue,
                          const uint16_t maxValue) {
  uint32_t result = value;

  if (value <= minValue) {
    result = minValue;
  } else if (value >= maxValue) {
    result = maxValue;
  }
  return (result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value the value to be checked
* @param[in] maxValue   the upper limit
* @retval returns the maximum value
* @note
*******************************************************************************/
uint32_t LIBRNG_MaxU32(const uint32_t value,
                       const uint32_t maxValue) {

  uint32_t result = (value >= maxValue) ? maxValue : value;

  return (result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        unsigned values
* @param[in] value the value to be checked
* @param[in] maxValue   the upper limit
* @retval returns the maximum value
* @note
*******************************************************************************/
uint16_t LIBRNG_MaxU16(const uint32_t value,
                       const uint16_t maxValue) {

  uint16_t result = (value >= maxValue) ? maxValue : value;

  return (result);
}

/***************************************************************************//**
* @brief This function limit the value in a minimum and maximum range for
*        signed values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval returns the maximum value
* @note
*******************************************************************************/
int16_t LIBRNG_MinMaxS16(const int32_t value,
                         const int16_t minValue,
                         const int16_t maxValue) {
  int16_t result = value;

  if (value < minValue) {
    result = minValue;
  } else if (value > maxValue) {
    result = maxValue;
  }
  return (result);
}

/***************************************************************************//**
* @brief This function Check the value is outside the range
*        signed values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval true:  outside range
*         false: inside the range
* @note
*******************************************************************************/
bool LIBRNG_IsOutRangeS16(const int32_t value,
                          const int16_t minValue,
                          const int16_t maxValue) {
  int32_t value32 = (int32_t)value;

  if ((value32 < minValue) ||
      (value32 > maxValue)) {
    return(true);
  }
  return (false);
}

/***************************************************************************//**
* @brief This function Check the value is outside the range
*        signed values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval true:  outside range
*         false: inside the range
* @note
*******************************************************************************/
bool LIBRNG_IsOutRangeU16(const uint32_t value,
                          const uint16_t minValue,
                          const uint16_t maxValue) {
  uint32_t value32 = (uint32_t)value;

  if ((value32 < minValue) ||
      (value32 > maxValue)) {
    return(true);
  }
  return (false);
}

/***************************************************************************//**
* @brief This function Check the value is outside the range
*        signed values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval true:  outside range
*         false: inside the range
* @note
*******************************************************************************/
bool LIBRNG_IsOutRangeU32(const uint32_t value,
                          const uint32_t minValue,
                          const uint32_t maxValue) {
  uint32_t value32 = (uint32_t)value;

  if ((value32 < minValue) ||
      (value32 > maxValue)) {
    return(true);
  }
  return (false);
}

/***************************************************************************//**
* @brief This function Check the value is outside the range
*        signed values
* @param[in] value the value to be checked
* @param[in] minValue   the lower limit
* @param[in] maxValue   the upper limit
* @retval true:  outside range
*         false: inside the range
* @note
*******************************************************************************/
bool LIBRNG_IsOutRangeS32(const int32_t value,
                          const int32_t minValue,
                          const int32_t maxValue) {
  int32_t value32 = value;

  if ((value32 < minValue) ||
      (value32 > maxValue)) {
    return(true);
  }
  return (false);
}

/** @} */
/** @} */
/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_range.c file
*******************************************************************************
*/
