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
* @file   lib_version.h
* @date   18 nov. 2019
* @author admin
* @brief
*
******************************************************************************
*/

#ifndef _LIB_LIB_VERSION_H_
#define _LIB_LIB_VERSION_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "../cpu/cpu_inc.h"

/* Public define -------------------------------------------------------------*/
#define LIBVER_VERSION_MAJOR (1)
#define LIBVER_VERSION_MINOR (0)
#define LIBVER_VERSION_PATCH (0)

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
typedef struct {
  const uint8_t major;      /*<! major version */
  const uint8_t minor;      /*<! minor version */
  const uint8_t patch;      /*<! patch */
  const uint8_t dummy;
} LIBVER_Version_s;

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
LIBVER_Version_s LIBVER_GetVersion(void);

#ifdef __cplusplus
}
#endif
#endif /* _LIB_LIB_VERSION_H_ */
