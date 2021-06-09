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
* @file        cpu_assert.h
* @date        14 jun. 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup cpu_assert
******************************************************************************
*/

#ifndef _CPU_ASSERT_H_
#define _CPU_ASSERT_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /***************************************************************************//**
   * @addtogroup Compiler The generic library for the compiler
   * @{
   * @addtogroup cpu_assert Asserts
   * @{
  ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include <assert.h>

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
#if !defined(DEBUG)
  #define ASSERT_PARAM(EXPRESSION) ((void)0)
  #define STATIC_ASSERT(cond)
#else
  #define ASSERT_PARAM(EXPRESSION) ((EXPRESSION) ? (void)0 : _cpu_assert(#EXPRESSION, __FILE__, __LINE__))

 /** @cond internal */
  #define RS_PADx(x,y) x##y
  #define RS_PADy(x,y) RS_PADx(x,y)

 /** @name Static asserts.
  *        Static asserts are used are used like standard asserts
  *        with one difference: they fire at compile time rather
  *        than at run time, and does consequently not use any
  *        resources at run time at all.
  *
  *        Static asserts are entering the upcoming C++ standard,
  *        and will likely show up in the next C standard too.
  *
  *        Using the STATIC_ASSERT is very similar to the normal
  *        ASSERT_PARAM macro, with two exceptions:
  *
  *        1) it may be used anywhere at file scope, and at
  *        function scope or block scope provided it occurs
  *        before any automatic variables are defined. Placing
  *        it after these will cause a compiler error.
  *
  *        2) as static asserts are not yet supported by
  *        compilers it must be constructed from existing parts
  *        of the language. This means that the compiler will not
  *        emit a message saying "static assertion fail" but
  *        rather something not related to static asserts at all.
  *        The file and line info will still point to the assert
  *        though.
 */
  #define STATIC_ASSERT(e) typedef char RS_PADy(assertion_failed_at_line_, __LINE__) [(e) ? 1 : -1]   /*!< Static/compile time assert. */
  //#define STATIC_ASSERT(cond)      RSASSERTSTATIC(cond)
#endif

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
void _cpu_assert(const char* expression, const char* file, int line);

/** @} */
/** @} */
#ifdef __cplusplus
}
#endif
#endif /* _CPU_ASSERT_H_ */
