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
* @file   lib_version.c
* @date   18 nov. 2019
* @author admin
* @brief
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "lib_version.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
static const LIBVER_Version_s LIBVER_Version = {
    .major = LIBVER_VERSION_MAJOR,
    .minor = LIBVER_VERSION_MINOR,
    .patch = LIBVER_VERSION_PATCH,
    .dummy = 0,
};

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/***************************************************************************//**
* @brief This function get the library version
*
* @note
*******************************************************************************/
LIBVER_Version_s LIBVER_GetVersion(void) {

  return (LIBVER_Version);
}


/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_version.c file
*******************************************************************************
*/
