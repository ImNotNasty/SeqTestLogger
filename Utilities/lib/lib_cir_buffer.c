/*
******************************************************************************
* @copyright
* <h2><center>&copy; Copyright 2019 </center></h2>
* All rights reserved. Company Name's source code is an unpublished work and
* the use of a copyright notice does not imply otherwise. This source code
* contains confidential. Any attempt or
* participation in deciphering, decoding, reverse engineering or in any way
* altering the source code is strictly prohibited.
*
* @file:        lib_cir_buffer.c
* @date:        18 feb. 2019
* @author:      Onkelinx Ghislain
* @brief:
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "lib_cir_buffer.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

 /**
 * @brief  This function clears the given Circular by filling it with zeros
 *         and resetting the buffer pointers
 * @param[in]  pCirBuf pointer to the Circular structure to must be cleared
 * @return None
 */
void LIBCBUF_Clear(LIBCBUF_Buffer_s *pCirBuf) {
  ASSERT_PARAM(pCirBuf != pNull);

  memset(pCirBuf->pBuffer, 0, pCirBuf->nSize);

  /* Reset other variables of the buffer structure */
  pCirBuf->nReadPos = 0;
  pCirBuf->nWritePos = 0;
}

/**
* @brief This function initialize the circular buffer
* @param[in]  pCirBuf: pointer to the Circular structure to work on
* @return
* @note none
*/
bool LIBCBUF_Init(LIBCBUF_Buffer_s *pCirBuf,
                  uint8_t * const pData,
                  const uint16_t nSize) {
  bool bRetValue = false;

  ASSERT_PARAM(pCirBuf != pNull);
  ASSERT_PARAM(pData != pNull);

  if (pData != pNull) {

    pCirBuf->pBuffer = pData;

    /* Set content of Circular buffer to 0 */
    LIBCBUF_Clear(pCirBuf);

    pCirBuf->nSize = nSize;
    bRetValue = true;
  }

  return (bRetValue);
}

/**
* @brief This function return the free positions in the buffer
* @param[in]  pCirBuf: pointer to the Circular structure to work on
* @return the free positions in the buffer
* @note none
*/
uint16_t LIBCBUF_GetFree(const LIBCBUF_Buffer_s *pCirBuf)
{
  int16_t nFree;

  ASSERT_PARAM(pCirBuf != pNull);

  nFree = pCirBuf->nReadPos - pCirBuf->nWritePos;
  if (nFree <= 0)
  {
    nFree += pCirBuf->nSize;
  }
  /* Note: free is guaranteed to be >=1 from the above */
  return ((uint16_t)((uint16_t)nFree - 1U));
}


/**
* @brief This function return the filled positions in the buffer
* @param[in]  pCirBuf: pointer to the Circular structure to work on
* @return The filled positions in the buffer
* @note none
*/
uint16_t LIBCBUF_GetAvail(const LIBCBUF_Buffer_s *pCirBuf)
{
  int16_t nAvail;

  ASSERT_PARAM(pCirBuf != pNull);

  nAvail = pCirBuf->nWritePos - pCirBuf->nReadPos;
  if (nAvail < 0)
  {
    nAvail += pCirBuf->nSize;
  }
  return ((uint16_t)nAvail);
}


/**
* @brief This function skip xx positions from the buffer
* @param[in]  pCirBuf: pointer to the Circular structure to work on
* @param[in]  nCount: the number of bytes to be skipped
* @return Boolean that is FALSE when the buffer doesn't have enough free
*         positions to skip the data bytes
*         TRUE when the write was successful
* @note none
*/
bool LIBCBUF_Skip(LIBCBUF_Buffer_s *pCirBuf,
                  uint16_t nCount)
{
  CPU_SR_ALLOC();
  bool nRetValue = false;
  uint16_t  nRpos;
  uint16_t  nRest;
  uint16_t  nAvail = LIBCBUF_GetAvail(pCirBuf);

  ASSERT_PARAM(pCirBuf != pNull);

  if (nCount > 0)
  {
    CPU_CRITICAL_ENTER();
    nRpos = pCirBuf->nReadPos;
    nRest = pCirBuf->nSize - nRpos;

    if (nAvail >= nCount )
    {
      if (nCount < nRest) {
        pCirBuf->nReadPos += nCount;
      } else {
        pCirBuf->nReadPos = nCount - nRest;
      }
      nRetValue = true;
    }
    CPU_CRITICAL_EXIT();
  }
  return (nRetValue);
}


/**
* @brief  Write the specified number of bytes to the given Circular
*         Data is only added to the buffer when there are enough free positions
* @param[in]  pCirBuf: pointer to the Circular structure to work on
* @param[in]  pBuffer: pointer to the array of bytes that contains the data to
*                      be added
* @param[in]  Length: the number of bytes to be added
* @return Boolean that is FALSE when the buffer doesn't have enough free
*         positions to store the new data bytes (OVERRUN)
*         TRUE when the write was successful
*/
bool LIBCBUF_Write(LIBCBUF_Buffer_s *pCirBuf,
                  const uint8_t        *pBuffer,
                  uint8_t               Length)
{
  bool nRetValue = false;
  uint16_t  nRpos;
  uint16_t  nRest;
  uint16_t  nFree = LIBCBUF_GetFree(pCirBuf);

  ASSERT_PARAM(pCirBuf != pNull);
  ASSERT_PARAM(pBuffer != pNull);

  if (pCirBuf->pBuffer == pNull) return (false);

  if ((Length > 0U) &&
      (nFree >= Length))
  {
    nRpos = pCirBuf->nWritePos;
    nRest = pCirBuf->nSize - nRpos;

    if (Length >= nRest)
    {
      memcpy(pCirBuf->pBuffer + nRpos,
             pBuffer,
             nRest);
      if ((Length - nRest) != 0U)
      {
        memcpy(pCirBuf->pBuffer,
               pBuffer + nRest,
               (uint16_t)(Length - nRest));
      }
      pCirBuf->nWritePos = (Length - nRest);
    } else {
      memcpy(pCirBuf->pBuffer + nRpos,
             pBuffer,
             Length);
      pCirBuf->nWritePos += Length;
    }
    nRetValue = true;
  }
  return (nRetValue);
}


/**
 * @brief  Read the specified number of bytes from the given Circular
           Read is only performed when there are enough filled positions
 * @param[in]  pCirBuf pointer to the Circular structure to work on
 * @param[out] pBuffer pointer to an array of bytes where the data from the
 *                     buffer should be copied to
 * @param[in]  Length  the number of bytes to be read
 * @param[in]  Submit  Boolean that indicates if the read operation should erase
 *                     the read bytes from the buffer (TRUE),
 *                     or to simply show them but keep the buffer pointers
 *                     unchanged (FALSE). This allows peaking in the buffer
 *                     contents
 * @return Boolean that is FALSE when the buffer doesn't have enough filled
 *         positions to return the number of requested bytes (UNDERRUN)
 *         TRUE when the read was successful
 */
 bool LIBCBUF_Read(LIBCBUF_Buffer_s *pCirBuf,
                  uint8_t              *pBuffer,
                  uint8_t               Length,
                  bool                  bSubmit)
 {
  CPU_SR_ALLOC();
  bool nRetValue = false;
  uint16_t  nRpos;
  uint16_t  nRest;
  uint16_t  nAvail = LIBCBUF_GetAvail(pCirBuf);
  uint16_t nTempReadPos = 0;

  ASSERT_PARAM(pCirBuf != pNull);
  ASSERT_PARAM(pBuffer != pNull);

  if (pCirBuf->pBuffer == pNull) return (false);

  if ((Length > 0U) &&
      (nAvail >= Length))
  {
    CPU_CRITICAL_ENTER();

    nRpos  = pCirBuf->nReadPos;
    nRest  = pCirBuf->nSize - nRpos;

    if (Length < nRest)
    {
      memcpy(pBuffer,
             pCirBuf->pBuffer + nRpos,
             Length);
      nTempReadPos = pCirBuf->nReadPos + Length;
    } else {
      memcpy(pBuffer,
             pCirBuf->pBuffer + nRpos,
             nRest);
      if ((Length - nRest) != 0)
      {
        memcpy(pBuffer + nRest,
               pCirBuf->pBuffer,
               Length - nRest);
      }
      nTempReadPos = Length - nRest;
    }

    if (bSubmit == true)
    {
      pCirBuf->nReadPos = nTempReadPos;
    }
    nRetValue = true;
    CPU_CRITICAL_EXIT();
  }
  return (nRetValue);
}


/*
*******************************************************************************
*                        end of the lib_cir_buffer.c file
*******************************************************************************
*/
