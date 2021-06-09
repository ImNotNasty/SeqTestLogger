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
* @file:        lib_fir.c
* @date:        9 jul. 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_fir
******************************************************************************
*/

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @defgroup lib_fir FIR
 * @brief The generic library component for FIR functions
 * @{
 ******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "lib_fir.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void LIBFIR_AddToBuffer(LIBFIR_Handle_t *hdlr, int16_t nValue);

/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
 * @brief     This procedure initialize the FIR-filter
 * @param[in] hdlr       Handler of the FIR filter
 * @param[in] pFilter    The used filter type
 * @param[in] nInitValue The initial value.
 * @retval    none
 * @note      This function should called before executing the filter procedure
 ******************************************************************************/
void LIBFIR_Init(LIBFIR_Handle_t *hdlr,
                 const LIBFIR_Coefs_t  *coefs,
                 int16_t         *pBuffer,
                 int16_t         initValue) {
  int8_t nCnt = 0;
  int16_t *pSrc;

  ASSERT_PARAM(hdlr  != pNull);
  ASSERT_PARAM(coefs != pNull);
  ASSERT_PARAM(pBuffer  != pNull);

  hdlr->pBuffer = pBuffer;
  hdlr->params = coefs;
  pSrc = hdlr->pBuffer;

  /* initialize the buffer with an initial value */
  while (nCnt < hdlr->params->nTap) {
    *pSrc = initValue;
    pSrc++;
    nCnt++;
  }
}

/*******************************************************************************
 * @brief     This procedure add a the new value to the buffer
 * @param[in] hdlr   Handler of the FIR filter
 * @param[in] nValue The value that should be inserted.
 * @retval    none
 * @note      The newest values are at the end of the buffer and the oldest
 *            value at index 0
 ******************************************************************************/
 static void LIBFIR_AddToBuffer(LIBFIR_Handle_t *hdlr,
                                int16_t nValue) {

   ASSERT_PARAM(hdlr  != pNull);

  /* Shift the values in the buffer,
     The end of the buffer is the start position.
  */
  memcpy(&hdlr->pBuffer[0U],
         &hdlr->pBuffer[1U],
         (hdlr->params->nTap * sizeof(nValue)));

  /* insert the value on the end of the buffer */
  hdlr->pBuffer[(int8_t)(hdlr->params->nTap - 1U)] = nValue;
}

 /*******************************************************************************
  * @brief     This procedure initialize the FIR-filter
  * @param[in] hdlr       Handler of the FIR filter
  * @param[in] nInitValue The sample value.
  * @retval    return the calculated value
  * @note      Initialize the FIR-filter before using this routine
  ******************************************************************************/
 int16_t LIBFIR_Handler(LIBFIR_Handle_t *hdlr,
                        int16_t         sample) {
   uint8_t nCnt            = 0U;
   int32_t nResult         = 0L;
   int16_t *pBufIdx        = &hdlr->pBuffer[hdlr->params->nTap - 1U];
   const int16_t *pCoefIdx = &hdlr->params->Coef[0];

   ASSERT_PARAM(hdlr     != pNull);
   ASSERT_PARAM(pBufIdx  != pNull);
   ASSERT_PARAM(pCoefIdx != pNull);

   /* add the measure to the buffer */
   LIBFIR_AddToBuffer(hdlr, sample);

   /* Calculate the new output */
   while (nCnt < hdlr->params->nTap) {
     nResult += ((int32_t)(*pCoefIdx) * (*pBufIdx));
     nCnt++;
     pBufIdx--;
     pCoefIdx++;
   }
   /* rounding */
   //nResult += (int32_t)(((1u << FILT_FIR_PREC_DIV_SHIFTS) * FILT_FIR_NTAP) >> 1u);

   return ((int16_t)(nResult >> hdlr->params->DCgain_Shifts));
 }

 /** @} */
 /** @} */

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_fir.c file
*******************************************************************************
*/
