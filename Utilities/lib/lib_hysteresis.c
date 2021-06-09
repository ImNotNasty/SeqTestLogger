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
* @file:        lib_hysteresis.c
* @date:        10 mei 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_hysteresis
******************************************************************************
*/

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @defgroup lib_hysteresis Hysteresis
 * @brief The generic library component for hysteresis functions
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lib_hysteresis.h"

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
* @param[in,out] hdlr: handler of the current instance of the hysteresis component
* @note
*******************************************************************************/
void LIBHYST_Init(limhyst_Handle_t * hdlr) {

  ASSERT_PARAM(hdlr != pNull);

  hdlr->oResult = 0;
}

/***************************************************************************//**
* @brief This function
* @param[in,out] hdlr: handler of the current instance of the hysteresis component
* @param[in] value The input value
* @note
*******************************************************************************/
void LIBHYST_Handler(limhyst_Handle_t * hdlr, uint16_t value) {
  
  ASSERT_PARAM(hdlr != pNull);

  int32_t hValue = (int32_t)hdlr->oResult + hdlr->iUpHyst;
  int32_t lValue = (int32_t)hdlr->oResult - hdlr->iDownHyst;

  if (((int32_t)value >= hValue) ||
      ((int32_t)value <= lValue)) {
    hdlr->oResult = value;
  }
}

/** @} */
/** @} */

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lim_hysteresis.c file
*******************************************************************************
*/
