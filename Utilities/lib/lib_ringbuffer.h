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
* @file   lib_ringbuffer.h
* @date   22 nov. 2019
* @author admin
* @brief
*
******************************************************************************
*/

#ifndef _LIB_LIB_RINGBUFFER_H_
#define _LIB_LIB_RINGBUFFER_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
PACK_PUSH(1)
typedef struct {
   void*         p_Buffer;        //!< Pointer to memory block
   uint16_t      u16_Capacity;    //!< Max Size of Buffer
   uint16_t      u16_Size;        //!< Current Size of Buffer
   uint16_t      u16_ElemSize;    //!< Size of each element in Buffer
   void*         p_Head;          //!< Pointer to first valid element
   void*         p_Tail;          //!< Pointer to last element
} LIBRB_Ringbuffer_s;
PACK_POP

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
typedef bool (*t_pf_ItemComparer)( const void* p_ItemA_Data,
                                   uint32_t     u32_ItemA_DataSize,
                                   const void* p_ItemB_Data,
                                   uint32_t     u32_ItemB_DataSize );

/* Public macro --------------------------------------------------------------*/
#define STATIC_RINGBUFFER_BUFF_SIZE( items_count, item_size ) ( ( items_count ) * ( item_size ) )

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
bool LIBRB_Init( OUT LIBRB_Ringbuffer_s* pst_RingBuffer,
                 uint16_t u16_Size,
                 uint16_t u16_ElemSize,
                 void* p_Buffer,
                 uint32_t u32_BufferSize );

void LIBRB_Clear( LIBRB_Ringbuffer_s * pst_RingBuffer );

bool LIBRB_Find( LIBRB_Ringbuffer_s*  pst_RingBuffer,
                 const void*          p_ItemData,
                 uint16_t             u16_ItemDataSize,
                 OUT void*            p_FoundData );

bool LIBRB_FindCustom(LIBRB_Ringbuffer_s*  pst_RingBuffer,
                      const void*          p_ItemData,
                      uint16_t             u16_ItemDataSize,
                      t_pf_ItemComparer    pf_Comparer,
                      OUT void*            p_FoundData );

bool LIBRB_Pop(LIBRB_Ringbuffer_s* pst_RingBuffer,
               void* p_Data );

bool LIBRB_Push(LIBRB_Ringbuffer_s* pst_RingBuffer,
                const void*         p_Data );

#ifdef __cplusplus
}
#endif
#endif /* _LIB_LIB_RINGBUFFER_H_ */
