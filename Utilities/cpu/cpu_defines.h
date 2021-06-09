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
* @file        cpu_defines.c
* @date        14 jun. 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup cpu_defines
******************************************************************************
*/


#ifndef _CPU_DEFINES_H_
#define _CPU_DEFINES_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Public define -------------------------------------------------------------*/

#define  DEF_BIT_NR_00     (0)
#define  DEF_BIT_NR_01     (1)
#define  DEF_BIT_NR_02     (2)
#define  DEF_BIT_NR_03     (3)
#define  DEF_BIT_NR_04     (4)
#define  DEF_BIT_NR_05     (5)
#define  DEF_BIT_NR_06     (6)
#define  DEF_BIT_NR_07     (7)
#define  DEF_BIT_NR_08     (8)
#define  DEF_BIT_NR_09     (9)
#define  DEF_BIT_NR_10     (10)
#define  DEF_BIT_NR_11     (11)
#define  DEF_BIT_NR_12     (12)
#define  DEF_BIT_NR_13     (13)
#define  DEF_BIT_NR_14     (14)
#define  DEF_BIT_NR_15     (15)
#define  DEF_BIT_NR_16     (16)
#define  DEF_BIT_NR_17     (17)
#define  DEF_BIT_NR_18     (18)
#define  DEF_BIT_NR_19     (19)
#define  DEF_BIT_NR_20     (20)
#define  DEF_BIT_NR_21     (21)
#define  DEF_BIT_NR_22     (22)
#define  DEF_BIT_NR_23     (23)
#define  DEF_BIT_NR_24     (24)
#define  DEF_BIT_NR_25     (25)
#define  DEF_BIT_NR_26     (26)
#define  DEF_BIT_NR_27     (27)
#define  DEF_BIT_NR_28     (28)
#define  DEF_BIT_NR_29     (29)
#define  DEF_BIT_NR_30     (30)
#define  DEF_BIT_NR_31     (31)


/* ------------------- BIT DEFINES -------------------- */
#define  DEF_BIT_NONE                                   0x00U

#define  DEF_BIT_00                                     0x01U
#define  DEF_BIT_01                                     0x02U
#define  DEF_BIT_02                                     0x04U
#define  DEF_BIT_03                                     0x08U
#define  DEF_BIT_04                                     0x10U
#define  DEF_BIT_05                                     0x20U
#define  DEF_BIT_06                                     0x40U
#define  DEF_BIT_07                                     0x80U

#define  DEF_BIT_08                                   0x0100U
#define  DEF_BIT_09                                   0x0200U
#define  DEF_BIT_10                                   0x0400U
#define  DEF_BIT_11                                   0x0800U
#define  DEF_BIT_12                                   0x1000U
#define  DEF_BIT_13                                   0x2000U
#define  DEF_BIT_14                                   0x4000U
#define  DEF_BIT_15                                   0x8000U

#define  DEF_BIT_16                               0x00010000U
#define  DEF_BIT_17                               0x00020000U
#define  DEF_BIT_18                               0x00040000U
#define  DEF_BIT_19                               0x00080000U
#define  DEF_BIT_20                               0x00100000U
#define  DEF_BIT_21                               0x00200000U
#define  DEF_BIT_22                               0x00400000U
#define  DEF_BIT_23                               0x00800000U

#define  DEF_BIT_24                               0x01000000U
#define  DEF_BIT_25                               0x02000000U
#define  DEF_BIT_26                               0x04000000U
#define  DEF_BIT_27                               0x08000000U
#define  DEF_BIT_28                               0x10000000U
#define  DEF_BIT_29                               0x20000000U
#define  DEF_BIT_30                               0x40000000U
#define  DEF_BIT_31                               0x80000000U
#define  DEF_BIT_32                       0x0000000100000000U
#define  DEF_BIT_33                       0x0000000200000000U
#define  DEF_BIT_34                       0x0000000400000000U
#define  DEF_BIT_35                       0x0000000800000000U
#define  DEF_BIT_36                       0x0000001000000000U
#define  DEF_BIT_37                       0x0000002000000000U
#define  DEF_BIT_38                       0x0000004000000000U
#define  DEF_BIT_39                       0x0000008000000000U

#define  DEF_BIT_40                       0x0000010000000000U
#define  DEF_BIT_41                       0x0000020000000000U
#define  DEF_BIT_42                       0x0000040000000000U
#define  DEF_BIT_43                       0x0000080000000000U
#define  DEF_BIT_44                       0x0000100000000000U
#define  DEF_BIT_45                       0x0000200000000000U
#define  DEF_BIT_46                       0x0000400000000000U
#define  DEF_BIT_47                       0x0000800000000000U

#define  DEF_BIT_48                       0x0001000000000000U
#define  DEF_BIT_49                       0x0002000000000000U
#define  DEF_BIT_50                       0x0004000000000000U
#define  DEF_BIT_51                       0x0008000000000000U
#define  DEF_BIT_52                       0x0010000000000000U
#define  DEF_BIT_53                       0x0020000000000000U
#define  DEF_BIT_54                       0x0040000000000000U
#define  DEF_BIT_55                       0x0080000000000000U

#define  DEF_BIT_56                       0x0100000000000000U
#define  DEF_BIT_57                       0x0200000000000000U
#define  DEF_BIT_58                       0x0400000000000000U
#define  DEF_BIT_59                       0x0800000000000000U
#define  DEF_BIT_60                       0x1000000000000000U
#define  DEF_BIT_61                       0x2000000000000000U
#define  DEF_BIT_62                       0x4000000000000000U
#define  DEF_BIT_63                       0x8000000000000000U

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/

/***************************************************************************//**
 * @fn     DEF_BIT()
 * @brief  Create bit mask with single, specified bit set.
 * @param  bit         Bit number of bit to set.
 * @return Bit mask with single, specified bit set.
 * @note   (1) 'bit' SHOULD be a non-negative integer.
 *         (2) 'bit' values that overflow the target CPU &/or compiler
 *                   environment (e.g. negative or greater-than-CPU-data-size
 *                   values) MAY generate compiler warnings &/or errors.
 ******************************************************************************/
 #define  DEF_BIT(bit)     (1u << (bit))
 #define  DEF_BIT08(bit)   ((uint8_t) ((uint8_t) 1u  << (bit)))
 #define  DEF_BIT16(bit)   ((uint16_t)((uint16_t)1u  << (bit)))
 #define  DEF_BIT32(bit)   ((uint32_t)((uint32_t)1u  << (bit)))
 #define  DEF_BIT64(bit)   ((uint64_t)((uint64_t)1u  << (bit)))

 /*! Create & shift a contiguous bit field. */
 #define  DEF_BIT_MASK(bit_mask, bit_shift)     ((bit_mask) << (bit_shift))
 #define  DEF_BIT_MASK_08(bit_mask, bit_shift)  ((uint8_t) ((uint8_t)(bit_mask)  << (bit_shift)))
 #define  DEF_BIT_MASK_16(bit_mask, bit_shift)  ((uint16_t)((uint16_t)(bit_mask) << (bit_shift)))
 #define  DEF_BIT_MASK_32(bit_mask, bit_shift)  ((uint32_t)((uint32_t)(bit_mask) << (bit_shift)))
 #define  DEF_BIT_MASK_64(bit_mask, bit_shift)  ((uint64_t)((uint64_t)(bit_mask) << (bit_shift)))
 /*! Create & shift a contiguous bit field of specified bit size. */
 #define  DEF_BIT_FIELD(bit_field, bit_shift)    ((((bit_field) >= DEF_INT_CPU_NBR_BITS) ? (DEF_INT_CPU_U_MAX_VAL)     \
                                                                                        : (DEF_BIT(bit_field) - 1uL)) \
                                                                                          << (bit_shift))
 #define  DEF_BIT_FIELD_08(bit_field, bit_shift) ((uint8_t)((((uint8_t)(bit_field) >= (uint8_t)DEF_INT_08_NBR_BITS) ? (uint8_t)(DEF_INT_08U_MAX_VAL)                    \
                                                                                                                    : (uint8_t)(DEF_BIT08(bit_field) - (uint8_t)1u)) \
                                                                                                                                                      << (bit_shift)))
 #define  DEF_BIT_FIELD_16(bit_field, bit_shift) ((uint16_t)((((uint16_t)(bit_field) >= (uint16_t)DEF_INT_16_NBR_BITS) ? (uint16_t)(DEF_INT_16U_MAX_VAL)                    \
                                                                                                                       : (uint16_t)(DEF_BIT16(bit_field) - (uint16_t)1u)) \
                                                                                                                                                      << (bit_shift)))
 #define  DEF_BIT_FIELD_32(bit_field, bit_shift) ((uint32_t)((((uint32_t)(bit_field) >= (uint32_t)DEF_INT_32_NBR_BITS) ? (uint32_t)(DEF_INT_32U_MAX_VAL)                    \
                                                                                                                       : (uint32_t)(DEF_BIT32(bit_field) - (uint32_t)1u)) \
                                                                                                                                                      << (bit_shift)))
 #define  DEF_BIT_FIELD_64(bit_field, bit_shift) ((uint64_t)((((uint64_t)(bit_field) >= (uint64_t)DEF_INT_64_NBR_BITS) ? (uint64_t)(DEF_INT_64U_MAX_VAL)                    \
                                                                                                                       : (uint64_t)(DEF_BIT64(bit_field) - (uint64_t)1u)) \

 /*! Set specified bit(s) in a value. */
 #define  DEF_BIT_SET(val, mask)     ((val) = ((val) | (mask)))
 #define  DEF_BIT_SET_08(val, mask)  DEF_BIT_SET((val), (mask))
 #define  DEF_BIT_SET_16(val, mask)  DEF_BIT_SET((val), (mask))
 #define  DEF_BIT_SET_32(val, mask)  DEF_BIT_SET((val), (mask))
 #define  DEF_BIT_SET_64(val, mask)  DEF_BIT_SET((val), (mask))

 /*! Clear specified bit(s) in a value. */
 #define  DEF_BIT_CLR(val, mask)                        ((val) = ((val) & ~(mask)))
 #define  DEF_BIT_CLR_08(val, mask)                     DEF_BIT_CLR((val), (mask))
 #define  DEF_BIT_CLR_16(val, mask)                     DEF_BIT_CLR((val), (mask))
 #define  DEF_BIT_CLR_32(val, mask)                     DEF_BIT_CLR((val), (mask))
 #define  DEF_BIT_CLR_64(val, mask)                     DEF_BIT_CLR((val), (mask))

 /*! Toggles specified bit(s) in a value. */
 #define  DEF_BIT_TOGGLE(val, mask)                      ((val) ^= (mask))

 /*! Reads a 'val' field, masked and shifted, given by mask 'field_mask'. */
 #define  DEF_BIT_FIELD_RD(val, field_mask)              (((val) & (field_mask)) / ((field_mask) & ~((field_mask) << 1u)))

 /*! Encodes given 'field_val' at position given by mask 'field_mask'. */
 #define  DEF_BIT_FIELD_ENC(field_val, field_mask)       (((field_val) * ((field_mask) & ~((field_mask) << 1u))) & (field_mask))

 /*! Writes 'field_val' field at position given by mask 'field_mask' in variable 'var'. */
 #define  DEF_BIT_FIELD_WR(var, field_val, field_mask)   (var) = (((var) & ~(field_mask)) | DEF_BIT_FIELD_ENC((field_val), (field_mask)))

 /*! Determine if specified bit(s) in a value are set. */
 #define  DEF_BIT_IS_SET(val, mask)                    (((((val) & (mask)) == (mask)) && \
                                                          ((mask)          !=  0u))    ? (DEF_YES) : (DEF_NO))

 /*! Determine if specified bit(s) in a value are clear. */
 #define  DEF_BIT_IS_CLR(val, mask)                    (((((val) & (mask)) ==  0u)  && \
                                                          ((mask)          !=  0u))  ? (DEF_YES) : (DEF_NO))

 /*! Determine if any specified bit(s) in a value are set. */
 #define  DEF_BIT_IS_SET_ANY(val, mask)               ((((val) & (mask)) ==  0u)     ? (DEF_NO ) : (DEF_YES))

 /*! Determine if any specified bit(s) in a value are clear. */
 #define  DEF_BIT_IS_CLR_ANY(val, mask)               ((((val) & (mask)) == (mask))  ? (DEF_NO ) : (DEF_YES))

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef __cplusplus
}
#endif
#endif /* _GENERIC_ARM_DEFINES_H_ */
