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
* @file:        lib_string.c
* @date:        16 jun. 2019
* @author:      G.Onkelinx
* @brief:
*
* @ingroup lib_strings
******************************************************************************
*/

/***************************************************************************//**
 * @addtogroup Library The generic library
 * @{
 * @defgroup lib_strings String functions
 * @brief The generic library component for string functions
 * @{
 ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "lib_string.h"

/* Private define ------------------------------------------------------------*/
/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/***************************************************************************//**
* @brief Calculate length of a string, up to a maximum number of characters.
* @param[in] pstr        Pointer to string (see Note #1).
* @param[in] len_max     Maximum number of characters to search (see Note #3c).
* @retval Length of string; number of characters in string before terminating NULL character,
*                           if terminating NULL character     found (see Note #2b1).
*                           Requested maximum number of characters to search,
*                           if terminating NULL character NOT found (see Note #3c).
*
* @note (1)   String buffer NOT modified.
*
* @note (2)
* @note (2a)  IEEE Std 1003.1, 2004 Edition, Section 'strlen() : DESCRIPTION' states that :
* @note (2a1) "The strlen() function shall compute the number of bytes in the string to
*              which 's' ('pstr') points," ...
* @note (2a2) "not including the terminating null byte."
*
* @note (2b)  IEEE Std 1003.1, 2004 Edition, Section 'strlen() : RETURN VALUE' states that :
* @note (2b1) "The strlen() function shall return the length of 's' ('pstr');" ...
* @note (2b2) "no return value shall be reserved to indicate an error."
*
* @note (3)   String length calculation terminates when :
* @note (3a)  String pointer points to NULL.
* @note (3a1) String buffer overlaps with NULL address.
* @note (3a2) String length calculated for string up to but NOT beyond or including the NULL address.
* @note (3b)  Terminating NULL character found.
* @note (3b1) String length calculated for string up to but NOT including the NULL character (see Note #2a2).
* @note (3c)  'len_max' number of characters searched.
* @note (3c1) 'len_max' number of characters does NOT include the terminating NULL character.
*******************************************************************************/
uint16_t Str_Len_N(const uint8_t *pstr,
                   uint16_t len_max) {
  const uint8_t *pstr_len;
  uint16_t len;

  ASSERT_PARAM(pstr != pNull);

  pstr_len = pstr;
  len = 0U;
  while ((pstr_len != pNull) &&               /* Calc string length until NULL ptr (see Note #3a) ...       */
         (*pstr_len != (uint8_t) '\0') &&     /* ... or NULL char found      (see Note #3b) ...       */
         (len < (uint16_t) len_max)) {        /* ... or max nbr chars srch'd (see Note #3c).          */
    pstr_len++;
    len++;
  }

  return (len); /* Return string length (see Note #3b1).                         */
}


/***************************************************************************//**
* @brief Copy source string to destination string buffer, up to a maximum number of characters.
* @param[out] pstr_dest   Pointer to destination string buffer to receive source string copy (see Note #1a).
* @param[in]  pstr_src    Pointer to source string to copy into destination string buffer (see Note #1b).
* @param[in]  len_max     Maximum number of characters  to copy (see Notes #2a2 & #3d).
* @retval Pointer to destination string, if NO error(s) [see Note #2b1].
*         Pointer to NULL, otherwise (see Note #2b2A).
*
* @note (1a)   Destination buffer size NOT validated; buffer overruns MUST be prevented by caller.
* @note (1a1)  Destination buffer size MUST be large enough to accommodate the entire source
*              string size including the terminating NULL character.
* @note (1b)   Source string buffer NOT modified.
*
* @note (2a1)  IEEE Std 1003.1, 2004 Edition, Section 'strncpy() : DESCRIPTION' states that :
* @note (2a1A) "The strncpy() function shall copy ... the array pointed to by 's2'
*              ('pstr_src') to the array pointed to by 's1' ('pstr_dest')"; ...
* @note (2a1B) but "not more than 'n' ('len_max') bytes" ...
* @note (2a1C) &   "(bytes that follow a null byte are not copied)".
* @note (2a2A) IEEE Std 1003.1, 2004 Edition, Section 'strncpy() : DESCRIPTION' adds that
*              "if the array pointed to by 's2' ('pstr_src') is a string that is shorter
*              than 'n' ('len_max') bytes, null bytes shall be appended to the copy in
*              the array pointed to by 's1' ('pstr_dest'), until 'n' ('len_max') bytes
*              in all are written."
* @note (2a2A1)#### Since Str_Copy() limits the maximum number of characters to copy
*              via Str_Copy_N() by the CPU's maximum number of addressable characters,
*              this requirement is intentionally NOT implemented to avoid appending
*              a potentially large number of unnecessary terminating NULL characters.
* @note (2a2B) IEEE Std 1003.1, 2004 Edition, Section 'strncpy() : APPLICATION USAGE' also
*              states that "if there is no null byte in the first 'n' ('len_max') bytes of
*              the array pointed to by 's2' ('pstr_src'), the result is not null-terminated".
* @note (2b)   IEEE Std 1003.1, 2004 Edition, Section 'strncpy() : RETURN VALUE' states that :
* @note (2b1)  "The strncpy() function shall return 's1' ('pstr_dest');" ...

* @note (2a2) "not including the terminating null byte."
*
* @note (2b)  IEEE Std 1003.1, 2004 Edition, Section 'strlen() : RETURN VALUE' states that :
* @note (2b1) "The strlen() function shall return the length of 's' ('pstr');" ...
* @note (2b2) "no return value shall be reserved to indicate an error."
* @note (2b2A) #### This requirement is intentionally ignored in order to return NULL for any error(s).
* @note (2c)   IEEE Std 1003.1, 2004 Edition, Section 'strncpy() : DESCRIPTION' states that "if
*              copying takes place between objects that overlap, the behavior is undefined".
*
* @note (3)    String copy terminates when :
* @note (3a)   Destination/Source string pointer(s) are passed NULL pointers.
* @note (3a1)  No string copy performed; NULL pointer returned.
* @note (3b)   Destination/Source string pointer(s) point to NULL.
* @note (3b1)  String buffer(s) overlap with NULL address; NULL pointer returned.
* @note (3c)   Source string's terminating NULL character found.
* @note (3c1)  Entire source string copied into destination string buffer (see Note #2a1A).
* @note (3d)   'len_max' number of characters copied.
* @note (3d1)  'len_max' number of characters MAY include the terminating NULL character (see Note #2a1C).
* @note (3d2)  Null copies allowed (i.e. zero-length copies).
* @note (3d2A) No string copy performed; destination string returned  (see Note #2b1).
*******************************************************************************/
int8_t *Str_Copy_N(int8_t *pstr_dest,
                   const int8_t *pstr_src,
                   int16_t len_max)
{
  int8_t *pstr_copy_dest;
  const int8_t *pstr_copy_src;
  int16_t len_copy;

  ASSERT_PARAM(pstr_dest != pNull);
  ASSERT_PARAM(pstr_src  != pNull);

  /* Return NULL if string ptr(s) NULL (see Note #3a1).         */
  if (pstr_dest == pNull) {
    return (pNull);
  }

  if (pstr_src == pNull) {
    return (pNull);
  }

  pstr_copy_dest = pstr_dest;
  pstr_copy_src = pstr_src;
  len_copy = 0U;

  while ((pstr_copy_dest != pNull) &&              /* Copy string until NULL ptr(s)  [see Note #3b]  ...      */
         (pstr_copy_src != pNull) &&
         (*pstr_copy_src != (int8_t) '\0') &&      /* ... or NULL char found      (see Note #3c); ...      */
         (len_copy < (int16_t) len_max)) {         /* ... or max nbr chars copied (see Note #3d).          */
    *pstr_copy_dest = *pstr_copy_src;
    pstr_copy_dest++;
    pstr_copy_src++;
    len_copy++;
  }

  /* Return NULL if NULL ptr(s) found  (see Note #3b1).      */
  if ((pstr_copy_dest == pNull) ||
      (pstr_copy_src == pNull)) {
    return (pNull);
  }

  if (len_copy < len_max) {          /* If  copy str len < max buf len (see Note #2a2A), ... */
    *pstr_copy_dest = (int8_t) '\0'; /* ... copy NULL char  (see Note #3c1).                 */
  }

  return (pstr_dest); /* Return ptr to dest str (see Note #2b1).                 */
}

/** @} */
/** @} */

/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the lib_string.c file
*******************************************************************************
*/
