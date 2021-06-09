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
* @file   lib_ringbuffer.c
* @date   22 nov. 2019
* @author admin
* @brief
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "lib_ringbuffer.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static size_t LIBRB_TailOffset(LIBRB_Ringbuffer_s *pst_RingBuffer );
static size_t LIBRB_HeadOffset(LIBRB_Ringbuffer_s *pst_RingBuffer );
static bool   LIBRB_DefaultComparer(const void *p_ItemA_Data,
                                    uint32_t u32_ItemA_DataSize,
                                    const void *p_ItemB_Data,
                                    uint32_t u32_ItemB_DataSize);

/* Private functions ---------------------------------------------------------*/

/***************************************************************************//**
* @brief    Create a Ring Buffer object
*
* @param[in]  u16_Size    - Size of Ring Buffer
* @param[in]  u16_ElemSize  - Size of each element in Buffer
*
* @see    p_Queue_Close
* @note
*******************************************************************************/
bool LIBRB_Init( OUT LIBRB_Ringbuffer_s* pst_RingBuffer,
                 uint16_t u16_Size,
                 uint16_t u16_ElemSize,
                 void* p_Buffer,
                 uint32_t u32_BufferSize ) {

  if( (uint32_t)(u16_ElemSize * u16_Size) <= u32_BufferSize)  {
    pst_RingBuffer->p_Buffer = p_Buffer;
    pst_RingBuffer->p_Head = pst_RingBuffer->p_Buffer;
    pst_RingBuffer->p_Tail = pst_RingBuffer->p_Buffer;
    pst_RingBuffer->u16_Capacity = u16_Size;
    pst_RingBuffer->u16_ElemSize = u16_ElemSize;
    pst_RingBuffer->u16_Size = 0;
    return (true);
  }

  return (false);
}

/***************************************************************************//**
* @brief This function
*
* @note
*******************************************************************************/
static size_t LIBRB_TailOffset( LIBRB_Ringbuffer_s* pst_RingBuffer ) {

  return ((STATIC_CAST(size_t, pst_RingBuffer->p_Tail) -
          STATIC_CAST(size_t, pst_RingBuffer->p_Buffer) +
          pst_RingBuffer->u16_ElemSize ) % ( pst_RingBuffer->u16_Capacity * pst_RingBuffer->u16_ElemSize ));
}

/***************************************************************************//**
* @brief This function
*
* @note
*******************************************************************************/
static size_t LIBRB_HeadOffset( LIBRB_Ringbuffer_s* pst_RingBuffer ) {

  return ((STATIC_CAST(size_t, pst_RingBuffer->p_Head) -
          STATIC_CAST(size_t, pst_RingBuffer->p_Buffer) +
          pst_RingBuffer->u16_ElemSize ) % ( pst_RingBuffer->u16_Capacity * pst_RingBuffer->u16_ElemSize ));
}

/***************************************************************************//**
* @brief    Push element to back of Ring Buffer
* @note   If Buffer is full, overwrite first element
*
* @param[in]  pst_RingBuffer  - A pointer of Ring Buffer
* @param[in]  p_Data      - A pointer to Data
*
* @return   None
* @note
*******************************************************************************/
bool LIBRB_Push(LIBRB_Ringbuffer_s* pst_RingBuffer,
                const void* p_Data ) {
  bool bRetValue = true;

  if (pst_RingBuffer != pNull) {
    CPU_SR_ALLOC();
    size_t NewTailOffset = 0;
    uint8_t *p_NewTail = pNull;

    CPU_CRITICAL_ENTER();
    // if overlaping occurs, move head pointer as well
    if ((pst_RingBuffer->p_Tail == pst_RingBuffer->p_Head) &&
        (pst_RingBuffer->u16_Size != 0)) {
      bRetValue = false;
    } else {

      memcpy(pst_RingBuffer->p_Tail, p_Data, pst_RingBuffer->u16_ElemSize);

      NewTailOffset = LIBRB_TailOffset(pst_RingBuffer);
      p_NewTail = STATIC_CAST(uint8_t*, pst_RingBuffer->p_Buffer)
                              + NewTailOffset;
      pst_RingBuffer->p_Tail = p_NewTail;

      if (pst_RingBuffer->u16_Size < pst_RingBuffer->u16_Capacity) {
        ++pst_RingBuffer->u16_Size;
      }
    }
    CPU_CRITICAL_EXIT();
  }

  return (bRetValue);
}

/***************************************************************************//**
* @brief    Pop element from top of Ring Buffer
*
* @param[in]  pst_RingBuffer  - A pointer of Message Queue
* @param[in]  p_Data      - A pointer to Data
*
* @return   true if success
* @note
*******************************************************************************/
bool LIBRB_Pop(LIBRB_Ringbuffer_s* pst_RingBuffer,
               void* p_Data ) {
  bool ok = false;

  if ( pst_RingBuffer != pNull ) {
    size_t NewHeadOffset = 0;

    if ( pst_RingBuffer->u16_Size ) {

      memcpy( p_Data, pst_RingBuffer->p_Head, pst_RingBuffer->u16_ElemSize );

      NewHeadOffset = LIBRB_HeadOffset(pst_RingBuffer);
      pst_RingBuffer->p_Head = STATIC_CAST(uint8_t*, pst_RingBuffer->p_Buffer) + NewHeadOffset;

      ok = true;
      --pst_RingBuffer->u16_Size;
    }
  }

  return (ok);
}


/***************************************************************************//**
* @brief    This is a function prototype of two items comparing
*
* @param[in]  p_ItemA_Data      A pointer of item A.
* @param[in]  u32_ItemA_DataSize    Size of item A data.
* @param[in]  p_ItemB_Data      A pointer of item B.
* @param[in]  u32_ItemB_DataSize    Size of item B data.
*
* @return   true if two items are the same. false if they do not match
* @note
*******************************************************************************/
static bool LIBRB_DefaultComparer(const void *p_ItemA_Data,
                                  uint32_t u32_ItemA_DataSize,
                                  const void *p_ItemB_Data,
                                  uint32_t u32_ItemB_DataSize) {

  if((u32_ItemA_DataSize <= 0) ||
     (u32_ItemB_DataSize <= 0) ||
     (!(uint32_t)p_ItemA_Data) ||
     (!(uint32_t)p_ItemB_Data)) {
    return (false);
  }

  if ( u32_ItemA_DataSize != u32_ItemB_DataSize ) {
    return (false);
  }

  if ( !memcmp( p_ItemA_Data, p_ItemB_Data, u32_ItemA_DataSize )) {
    return (true);
  }

  return (false);
}

/***************************************************************************//**
* @brief    This function search item in Ring Buffer using pf_Comparer
*       function
*
* @param[in]  pst_RingBuffer    A pointer of Ring Buffer
* @param[in]  p_ItemData      A pointer of item data to be searched
* @param[in]  u16_ItemDataSize  Size of searching data
* @param[in]  pf_Comparer     Specific compare function
* @param[out] p_FoundData     A pointer for found item
*
* @return   true if search succeeds
* @note
*******************************************************************************/
bool LIBRB_FindCustom(LIBRB_Ringbuffer_s*  pst_RingBuffer,
                      const void*     p_ItemData,
                      uint16_t         u16_ItemDataSize,
                      t_pf_ItemComparer pf_Comparer,
                      OUT void*     p_FoundData ) {
  bool ok = false;

  if (  !pst_RingBuffer
      || !p_ItemData
      || !u16_ItemDataSize
      || !pf_Comparer
      || !pst_RingBuffer->u16_Size ) {
    return (false);
  }

  {
    uint8_t* p_BufStart = (pst_RingBuffer->p_Head > pst_RingBuffer->p_Tail) ? pst_RingBuffer->p_Tail :
                                       pst_RingBuffer->p_Head;

    uint8_t* p_BufEnd = (pst_RingBuffer->p_Head < pst_RingBuffer->p_Tail) ?  pst_RingBuffer->p_Tail :
                                      pst_RingBuffer->p_Head;
    uint8_t* p_BufPos = pNull;
    for ( p_BufPos = p_BufStart; p_BufPos < p_BufEnd; p_BufPos += pst_RingBuffer->u16_ElemSize )
    {
      if ( pf_Comparer( p_BufPos, pst_RingBuffer->u16_ElemSize,
                p_ItemData, u16_ItemDataSize ) )
      {
        ok = true;
        memcpy(p_FoundData, p_BufPos, pst_RingBuffer->u16_ElemSize);
        memset(p_BufPos, 0, pst_RingBuffer->u16_ElemSize);
        break;
      }
    }
  }

  return (ok);
}

/***************************************************************************//**
* @brief    This function search item in Ring Buffer
*
* @param[in]  pst_RingBuffer    A pointer of Ring Buffer
* @param[in]  p_ItemData      A pointer of item data to be searched
* @param[in]  u16_ItemDataSize  Size of searching data
* @param[out] p_FoundData     A pointer for found item
*
* @return   true if search succeeds
* @note
*******************************************************************************/
bool LIBRB_Find( LIBRB_Ringbuffer_s*  pst_RingBuffer,
            const void*     p_ItemData,
            uint16_t         u16_ItemDataSize,
            OUT void*     p_FoundData ) {

  return (LIBRB_FindCustom(pst_RingBuffer,
                           p_ItemData,
                           u16_ItemDataSize,
                           LIBRB_DefaultComparer,
                           p_FoundData ));
}

/***************************************************************************//**
* @brief    Clear Ring Buffer object
*
* @param[in]  pst_RingBuffer  - A pointer to object
*
* @return   None
* @note
*******************************************************************************/
void LIBRB_Clear( LIBRB_Ringbuffer_s * pst_RingBuffer ) {

  memset( pst_RingBuffer->p_Buffer, 0, pst_RingBuffer->u16_Capacity );
  pst_RingBuffer->p_Head = pst_RingBuffer->p_Buffer;
  pst_RingBuffer->p_Tail = pst_RingBuffer->p_Buffer;
  pst_RingBuffer->u16_Size = 0;
}

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_ringbuffer.c file
*******************************************************************************
*/
