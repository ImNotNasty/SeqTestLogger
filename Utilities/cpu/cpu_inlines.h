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
* @file:        cpu_inlines.h
* @date:        30 nov. 2018
* @author:      Onkelinx Ghislain
* @brief:
*
******************************************************************************
* History
******************************************************************************
*
******************************************************************************
*/


#ifndef _CPU_INLINES_H_
#define _CPU_INLINES_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "cpu_macros.h"
#include "cpu_typedefs.h"

/* Public define -------------------------------------------------------------*/
/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
 /******************************/
 /***  BINARY MANIPULATIONS  ***/
 /******************************/

/*!
 * @brief Create specified number of bits mask
 * @note function limited to arm native 32b
 * @param[in] bits - Number of bits to create mask
 * @return Mask value for specified number of bits
**/
 __INLINE uint32_t maskBits(const uint8_t bits) {
   const uint8_t  nb_bits = 32;
   uint8_t   nb = (bits > nb_bits) ? nb_bits : bits;
   uint32_t   mask = 0;
   for (unsigned int i = 0 ; i < nb ; i++) mask |= 1UL << i;
   return (mask); }

/*!
 * @brief Check the number of clear/set bits in a variable
 * @note function limited to arm native 32b
 * @param[in] val - Variable to check for bits
 * @param[in] bits - Number of bits to check
 * @param[in] state - Logic state to check
 * @return Number of state specified bits in val
 **/
 __INLINE uint8_t nbBitsState(const uint32_t val, const uint8_t bits, const bool state) {
   const uint8_t  nb_bits = 32;
   uint8_t   nb = (bits > nb_bits) ? nb_bits : bits;
   uint8_t    ret = 0;
   for (unsigned int i = 0 ; i < nb ; i++) { if (val & (1UL << i)) ret++; }
   return ((state) ? ret : nb - ret); }

/*!
 * @brief Get power of 2 of the most significant set bit
 * @param[in] val - Variable to check for bits
 * @return Power of 2 of most significant bit set
 * @retval >=0: Index (power of 2) of most significant bit set
 * @retval -1: no bit set
 **/
 __INLINE int8_t getMSBitSet(const uint32_t val) {
   const uint8_t  nb_bits = 32;
   for (int i = nb_bits - 1 ; i >= 0 ; i--)  { if (val & (1UL << i)) return (i); }
   return (-1); }

/*!
 * @brief Swap specified number of bits in value (mirroring bits)
 * @note function limited to arm native 32b
 * @param[in] val - Value to swap
 * @param[in] bits - Number of bits to swap
 * @return Swapped binary value
**/
 __INLINE uint32_t swapBits(const uint32_t val, const uint8_t bits) {
   const uint8_t  nb_bits = 32;
   uint8_t   nb = (bits > nb_bits ? nb_bits : bits) - 1;
   uint32_t   swap = 0;
   for (int i = nb ; i >= 0 ; i--) { if (val & (1UL << i)) swap |= 1UL << (nb - i); }
   return (swap); }


 /*************************************************/
 /***  HEX, ASCII, BCD & GRAY CODE CONVERSIONS  ***/
 /*************************************************/

/*!
 * @brief Converts hexadecimal value to BCD
 * @note Returns 0xFF if Hex value can't be represented on a BCD uint8_t
 * @param[in] hex - Hexadecimal value to convert
 * @return BCD value
**/
 __INLINE uint8_t HexToBCD(const uint8_t hex) {
   if (hex > 99) { return (0xFF); }
   return (LSHIFT((hex / 10), 4) | (hex % 10)); }

/*!
 * @brief Converts BCD value to hexadecimal
 * @note Returns 0xFF if BCD value is inconsistent
 * @param[in] bcd - BCD value to convert
 * @return Hexadecimal value
**/
 __INLINE uint8_t BCDToHex(const uint8_t bcd) {
   uint8_t ms = RSHIFT(bcd & 0xF0, 4);
   uint8_t ls = bcd & 0x0F;
   if ((ms > 9) || (ls > 9)) { return (0xFF); }
   return ((uint8_t) ((ms * 10) + ls)); }


/*!
 * @brief Converts hexadecimal value to ASCII
 * @param[in] hex - Hexadecimal value to convert
 * @return ASCII char
**/
 __INLINE char INLINE__ HexToASCII(uint8_t hex) {
   hex &= 0x0F;
   return ((hex < 0x0A ? 0x30 : 0x37) + hex); }

/*!
 * @brief Converts ASCII char to hexadecimal
 * @param[in] ascii - ASCII char to convert
 * @return Hexadecimal value
**/
 __INLINE int8_t ASCIIToHex(const char ascii) {
   if ((ascii >= '0') && (ascii <= '9'))     { return (ascii - 0x30); }
   else if ((ascii >= 'A') && (ascii <= 'F'))    { return (ascii - 0x37); }
   else if ((ascii >= 'a') && (ascii <= 'f'))    { return (ascii - 0x47); }
   else                      { return (-1); } }


/*!
 * @brief Convert binary value to gray code
 * @param[in] bin - binary value
 * @return Converted value (gray code)
**/
 __INLINE uint32_t INLINE__ bin2gray(const uint32_t bin) {
   return (RSHIFT(bin, 1) ^ bin); }

/*!
 * @brief Convert gray code to binary value
 * @param[in] gray - gray code value
 * @return Converted value (binary)
**/
 __INLINE uint32_t gray2bin(const uint32_t gray) {
   int32_t bits = 32;
   uint32_t tmp = gray;
   while ((bits >>= 1) > 0)  { tmp ^= (tmp >> bits); }
   return (tmp); }

 /******************************/
 /***  VAR SIZE CONVERSIONS  ***/
 /******************************/

/*!
 * @brief converts 16bits to 8bits
 * @param[in] val - 16b value to convert
 * @return Converted value
**/
 __INLINE uint8_t INLINE__ conv16to8Bits(const uint16_t val) {
   return ((uint8_t) RSHIFT(val, 8)); }

/*!
 * @brief converts 8bits to 16bits
 * @param[in] val - 8b value to convert
 * @return Converted value
**/
 __INLINE uint16_t INLINE__ conv8to16Bits(const uint8_t val) {
   return ((uint16_t) (LSHIFT(val, 8) + val)); }


/*!
 * @brief converts 8bits to 8+nb bits (16bits max)
 * @warning conversion output shall not exceed 16bits (input shall strictly be unsigned 8bits)
 * @warning nb shall be in range 0-8 (note that using 0 doesn't change val)
 * @param[in] val - 8b value to convert
 * @param[in] nb - number of bits to add (8bits max)
 * @return Converted value
**/
 __INLINE uint16_t conv8upto16Bits(const uint8_t val, const uint8_t nb) {
   return ((uint16_t) ((uint16_t) (val << nb) + (uint16_t) (val & (0xFFU >> (8-nb))))); }

/*!
 * @brief converts 16bits to 16+nb bits (32bits max)
 * @warning conversion output shall not exceed 32bits (input shall strictly be unsigned 16bits)
 * @warning nb shall be in range 0-16 (note that using 0 doesn't change val)
 * @param[in] val - 16b value to convert
 * @param[in] nb - number of bits to add (16bits max)
 * @return Converted value
**/
 __INLINE uint32_t conv16upto32Bits(const uint16_t val, const uint8_t nb) {
   return ((uint32_t) ((uint32_t) (val << nb) + (uint32_t) (val & (0xFFFFU >> (16-nb))))); }

/*!
 * @brief converts 32bits to 32+nb bits (64bits max)
 * @warning conversion output shall not exceed 64bits (input shall strictly be unsigned 32bits)
 * @warning nb shall be in range 0-32 (note that using 0 doesn't change val)
 * @param[in] val - 32b value to convert
 * @param[in] nb - number of bits to add (32bits max)
 * @return Converted value
**/
 __INLINE uint64_t conv32upto64Bits(const uint32_t val, const uint8_t nb) {
   return ((uint64_t) ((uint64_t) (val << nb) + (uint64_t) (val & (0xFFFFFFFFUL >> (32-nb))))); }

 /************************/
 /***  VALUES TESTING  ***/
 /************************/

/*!
 * @brief Checks if val given as parameter is in tolerance
 * @param[in] val - Value to check
 * @param[in] ref - Reference value
 * @param[in] tolerance - Tolerance on reference value (in percent)
 * @return true if val is inTolerance
**/
 __INLINE bool inTolerance(const int32_t val, const int32_t ref, float tolerance) {
   tolerance = min(100.0f, max(0.0f, tolerance));
   uint32_t margin = (uint32_t) (ref * (tolerance / 100.0f));
   return ((val <= (int32_t) (ref + margin)) && (val >= (int32_t) (ref - margin))); }

/*!
 * @brief Checks if val given as parameter is in range
 * @param[in] val - Value to check
 * @param[in] low - Low range boundary
 * @param[in] high - High range boundary
 * @return true if val is inRange
**/
 __INLINE bool INLINE__ inRange(const int32_t val, const int32_t low, const int32_t high) {
   return ((val <= high) && (val >= low)); }


 /*****************************/
 /***  ENDIANS CONVERSIONS  ***/
 /*****************************/

/*!
 * @brief Swap endians of the contents of a 16b value (little -> big, big -> little)
 * @param[in] w - 16b value
 * @return Swapped value
**/
 __INLINE uint16_t SWAP_END16B(const uint16_t w) {
   return ((uint16_t) (LSHIFT((w & 0xFFU), 8) | RSHIFT((w & 0xFF00U), 8))); }

/*!
 * @brief Swap endians of the contents of a 32b value (little -> big, big -> little)
 * @param[in] d - 32b value
 * @return Swapped value
**/
 __INLINE uint32_t SWAP_END32B(const uint32_t d) {
   return ((uint32_t) (LSHIFT(SWAP_END16B(d & 0xFFFFUL), 16) | SWAP_END16B(RSHIFT((d & 0xFFFF0000UL), 16)))); }

/*!
 * @brief Swap endians of the contents of a 64b value (little -> big, big -> little)
 * @param[in] l - 64b value
 * @return Swapped value
**/
// __INLINE uint64_t SWAP_END64B(const uint64_t l) {
//   return (uint64_t) (LSHIFT64(SWAP_END32B(l & 0xFFFFFFFFULL), 32) | SWAP_END32B(RSHIFT64((l & 0xFFFFFFFF00000000ULL), 32))); }


/*!
 * @brief Swap endians of a 16b tab (little -> big, big -> little)
 * @param[in] tab - tab of 16b values
 * @param[in] nb - nb of values in tab
**/
 __INLINE void NONNULL_INLINE__ SWAP_END16B_TAB(uint16_t tab[], const uint16_t nb) {
   for (unsigned int i = 0 ; i < nb ; i++) tab[i] = SWAP_END16B(tab[i]); }

/*!
 * @brief Swap endians of a 32b tab (little -> big, big -> little)
 * @param[in] tab - tab of 32b values
 * @param[in] nb - nb of values in tab
**/
 __INLINE void NONNULL_INLINE__ SWAP_END32B_TAB(uint32_t tab[], const uint16_t nb) {
   for (unsigned int i = 0 ; i < nb ; i++) tab[i] = SWAP_END32B(tab[i]); }


 /*************************/
 /***  ENDIANS TESTING  ***/
 /*************************/

/*!
 * @brief Test Core endian
 * @return Endian type
**/
 __INLINE eEndian testEndian_basic(void) {
   uint16_t x = 0x100;
   return ((* (char *) (&x)) ? Endian_big : Endian_little); }

/*!
 * @brief Test Core endian (full, recognizing mid endians too)
 * @return Endian type
**/
 __INLINE eEndian testEndian_full(void) {
   union {
     uint64_t dword;
     uint8_t  byte[sizeof(uint64_t)];
   } tst;

   tst.byte[0] = 1;
   tst.byte[1] = 2;
   tst.byte[2] = 3;
   tst.byte[3] = 4;

   switch (tst.dword)
   {
     case 0x01020304UL:  return (Endian_big);
     case 0x04030201UL:  return (Endian_little);
     case 0x03040102UL:  return (Endian_mid_big);
     case 0x02010403UL:  return (Endian_mid_little);
     default:          return (Endian_unknown);
   }
 }


 /*********************************/
 /***  TEMPERATURE CCONVERSIONS ***/
 /*********************************/

/*!
 * @brief Convert degrees Celsius to Kelvin
 * @param[in] cels - Celsius degrees value
 * @return Kelvin degrees
**/
 __INLINE float celsius2kelvin(const float cels) {
   return (cels + 273.15f); }

/*!
 * @brief Convert degrees Kelvin to Celsius
 * @param[in] kelv - Kelvin degrees value
 * @return Kelvin degrees
**/
 __INLINE float kelvin2celsius(const float kelv) {
   return (kelv - 273.15f); }


/*!
 * @brief Convert degrees Celsius to Fahrenheit
 * @param[in] cels - Celsius degrees value
 * @return Fahrenheit degrees
**/
 __INLINE float celsius2fahrenheit(const float cels) {
   return ((cels * (9.0f / 5.0f)) + 32.0f); }

/*!
 * @brief Convert degrees Fahrenheit to Celsius
 * @param[in] fahr - Fahrenheit degrees value
 * @return Celsius degrees
**/
 __INLINE float fahrenheit2celsius(const float fahr) {
   return ((fahr - 32.0f) * (5.0f / 9.0f)); }


/*!
 * @brief Convert degrees Fahrenheit to Kelvin
 * @param[in] fahr - Fahrenheit degrees value
 * @return Kelvin degrees
**/
 __INLINE float fahrenheit2kelvin(const float fahr) {
   return (celsius2kelvin(fahrenheit2celsius(fahr))); }

/*!
 * @brief Convert degrees Kelvin to Fahrenheit
 * @param[in] kelv - Kelvin degrees value
 * @return Fahrenheit degrees
**/
 __INLINE float kelvin2fahrenheit(const float kelv) {
   return (celsius2fahrenheit(kelvin2celsius(kelv))); }


 /************************/
 /***  FLOATING POINT  ***/
 /************************/

/*!
 * @brief Get floating point number decimal part
 * @note in need to print floats, add '-u _printf_float' in Linker options.
 * @warning enabling floating point support from linker seems to fubar printing long variables,
 *          so welcome get_fp_dec for the purpose.
 * @param[in] f - floating point value
 * @param[in] nb - Number of decimal to get after floating point
 * @return nb decimal part as integer
**/
 __INLINE int32_t get_fp_dec(float f, uint8_t nb) {
   int32_t mul = 1;
   f -= (int32_t) f;
   while (nb-- != 0) { mul *= 10; }
   return ((int32_t) (f * mul)); }


 /*******************/
 /***  AVERAGING  ***/
 /*******************/
#define RESTRICTED_AVERAGE(typ_t, sum_t)                                                \
   __INLINE typ_t RestrictedAverage_##typ_t(volatile typ_t pArray[], const uint8_t nb)  \
   {                                                                                    \
     typ_t Array[nb];                                                                   \
     sum_t sum = 0;                                                                     \
     uint16_t i;                                                                        \
                                                                                        \
     if (nb <= 2)  { return (0); }                                                        \
                                                                                        \
     /* Array copy (memcpy not used as copy by byte and pTab may be volatile) */        \
     for (i = 0 ; i < nb ; i++)      { Array[i] = pArray[i]; }                          \
     /* Shift min to first array index */                                               \
     for (i = 1 ; i < nb ; i++)      { if (Array[i] < Array[0])  SWAP_TYPE(Array[0], Array[i], typ_t); }  \
     /* Shift max to last array index */                                                \
     for (i = 1 ; i < (nb - 1) ; i++)  { if (Array[i] > Array[nb - 1]) SWAP_TYPE(Array[nb - 1], Array[i], typ_t); }  \
     /* Sum and averaging */                                                            \
     for (i = 1 ; i < (nb - 1) ; i++)  { sum += Array[i]; }                             \
     return (sum / (nb - 2));                                                           \
   }                                                                                    \

/*!
 * @brief Get average value of tab excluding most extreme values (uint8_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for uint8_ts).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 *
 * @param[in] pArray - Pointer to uint8_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (uint8_t)
**/
 RESTRICTED_AVERAGE(uint8_t, uint32_t)

/*!
 * @brief Get average value of tab excluding most extreme values (uint16_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results for 8b microcontroller).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to uint16_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (uint16_t)
**/
 RESTRICTED_AVERAGE(uint16_t, uint64_t)

/*!
 * @brief Get average value of tab excluding most extreme values (uint32_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results for 8b and 16b microcontroller).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to uint32_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (uint32_t)
**/
 RESTRICTED_AVERAGE(uint32_t, uint64_t)

/*!
  @brief Get average value of tab excluding most extreme values (Suint8_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it (not dangerous for Suint8_ts).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to Suint8_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (Suint8_t)
**/
 RESTRICTED_AVERAGE(int8_t, int32_t)

/*!
 * @brief Get average value of tab excluding most extreme values (int16_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results for 8b microcontroller).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to int16_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (int16_t)
**/
 RESTRICTED_AVERAGE(int16_t, int64_t)

/*!
 * @brief Get average value of tab excluding most extreme values (int32_t)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results for 8b and 16b microcontroller).
 *      Disabling interruptions before calling function can overcome this behavior if needed
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to int32_ts array
 * @param[in] nb - Number of array elements
 * @return Average value (int32_t)
**/
 RESTRICTED_AVERAGE(int32_t, int64_t)

/*!
 * @brief Get average value of tab excluding most extreme values (float)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results).
 *      Disabling interruptions before calling function can overcome this behavior
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to floats array
 * @param[in] nb - Number of array elements
 * @return Average value (float)
**/
 RESTRICTED_AVERAGE(float, float)

/*!
 * @brief Get average value of tab excluding most extreme values (double)
 * @warning If pArray is volatile array:
 *      A new value may be written in the tab (by interrupt for example) while copying it
 *      (which can lead to corrupted results).
 *      Disabling interruptions before calling function can overcome this behavior
 *      (not forgetting to re-enable interrupts after).
 *
 * @param[in] pArray - Pointer to doubles array
 * @param[in] nb - Number of array elements
 * @return Average value (double)
**/
 RESTRICTED_AVERAGE(double, double)


#ifdef __cplusplus
}
#endif
#endif /* _CPU_INLINES_H_ */
