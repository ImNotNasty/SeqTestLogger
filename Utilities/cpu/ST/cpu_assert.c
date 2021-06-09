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
* @file        cpu_assert.c
* @date        14 jun. 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup cpu_assert
******************************************************************************
*/

/***************************************************************************//**
 * @defgroup Compiler The generic library for the compiler
 * @{
 * @defgroup cpu_assert Asserts
 * @brief The generic library component for asserts
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "../cpu_assert.h"
#include "../cpu_attr.h"
#include "debug/debug.h"

/* Private define ------------------------------------------------------------*/
/*!< by defining the ASSERT_ABORT, the assert will execute
     the abort routine. no return isn't possible */
#define ASSERT_ABORT     (0)

/*!< by defining the ASSERT_RESET_CPU, the assert reset the CPU */
#define ASSERT_RESET_CPU (0)

/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/***************************************************************************//**
* @brief This function
*
* @note
*******************************************************************************/
 FORCE_INLINE void _cpu_assert(const char* expression,
                               const char* file,
                               int line)
{
   NOT_USED(expression);
   NOT_USED(file);
   NOT_USED(line);

   DEBUG_LOG(DBG_Error, "Assertion line '%d', file '%s', '%s' failed\n", line, file, expression);
#if (ASSERT_RESET_CPU != 0)
   DBGISR_ResetCPU(mmiRST_Assert);  /* doesn't return from the DBG_SoftwareReset function */
#endif

#if (ASSERT_ABORT != 0)
  abort();
#endif
}

 /** @} */
 /** @} */
/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the cpu_assert.c file
*******************************************************************************
*/
