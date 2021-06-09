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
* @file:        lib_cir_buffer.h
* @date:        18 feb. 2019
* @author:      Onkelinx Ghislain
* @brief:
*
******************************************************************************
*/

#ifndef _LIB_CIR_BUFFER_H_
#define _LIB_CIR_BUFFER_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
 typedef struct
{
   uint16_t nWritePos;
   uint16_t nReadPos;
   uint16_t nSize;
   uint8_t  *pBuffer;
} LIBCBUF_Buffer_s;

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

bool LIBCBUF_Init(LIBCBUF_Buffer_s *pCirBuf,
                  uint8_t * const pData,
                  uint16_t nSize);
void LIBCBUF_Clear(LIBCBUF_Buffer_s *pCirBuf);

bool LIBCBUF_Write(LIBCBUF_Buffer_s *pCirBuf,
                  const uint8_t        *pBuffer,
                  uint8_t               Length);

bool LIBCBUF_Read(LIBCBUF_Buffer_s *pCirBuf,
                  uint8_t              *pBuffer,
                  uint8_t               Length,
                  bool                  bSubmit);
uint16_t LIBCBUF_GetAvail(const LIBCBUF_Buffer_s *pCirBuf);
uint16_t LIBCBUF_GetFree(const LIBCBUF_Buffer_s *pCirBuf);
bool     LIBCBUF_Skip(LIBCBUF_Buffer_s *pCirBuf,
                      uint16_t nCount);

#ifdef __cplusplus
}
#endif

#endif /* _LIB_CIR_BUFFER_H_ */
