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
* @file        cpu_typedefs.h
* @date        14 jun. 2019
* @author      G.Onkelinx
* @brief
*
* @ingroup cpu_typedefs
******************************************************************************
*/

#ifndef _CPU_TYPEDEFS_H_
#define _CPU_TYPEDEFS_H_

#ifdef __cplusplus
 extern "C" {
#endif


 /***************************************************************************//**
   * @addtogroup Compiler The generic library for the compiler
   * @{
   * @addtogroup cpu_typedefs typedefs
   * @{
  ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
 /* Public define -------------------------------------------------------------*/

#ifndef IN
#define IN
#endif // IN

#ifndef OUT
#define OUT
#endif // OUT

#ifndef INOUT
#define INOUT
#endif // INOUT

#define STATIC_CAST( typeto, what ) ( (typeto)(what) )

/* #define LITTLE_ENDIAN  */

/* Public enumerations -------------------------------------------------------*/
 /*!
  * @enum eBool
  * @brief Boolean state true, false
 **/
 //typedef enum eBool {
 //  FALSE = false,
 //  TRUE = true
 //} eBool;

 /*!
  * @enum eState
  * @brief Activation state On, Off
 **/
  typedef enum eState {
    Off = 0U, //!< Off / Reset
    On = 1U   //!< On / Set
  } eState;


 /*!
  * @enum eEdge
  * @brief Signal Edges
 **/
  typedef enum eEdge {
    NoEdge = 0, //!< No change
    Rising,     //!< Rising edge
    Falling     //!< Falling edge
  } eEdge;


 /*!
  * @enum eGPIOState
  * @brief GPIO possible states/actions enumeration
 **/
  typedef enum eGPIOState {
    Reset = 0,  //!< Reset State
    Set,        //!< Set State
    Toggle      //!< Toggle Output
    //!@note Toggle is only GPIO output related
  } eGPIOState;

 /*!
  * @enum eGPIOPull
  * @brief GPIO possible pull resistor configuration
 **/
  typedef enum eGPIOPull {
    PullDown = 0, //!< GPIO with pull down
    PullUp,       //!< GPIO with pull up
    NoPull        //!< GPIO without pull
  } eGPIOPull;


 /*!
  * @enum eEndian
  * @brief Core endian
 **/
  typedef enum eEndian {
    Endian_little = 0,    //!< Little endian configured MCU
    Endian_big,           //!< Big endian configured MCU
    Endian_mid_little,    //!< Middle little endian configured MCU (PDP-11)
    Endian_mid_big,       //!< Middle big endian configured MCU (Honeywell 316)
    Endian_unknown        //!< Unknown endian MCU
  } eEndian;

  /* Public typedef ------------------------------------------------------------*/

 /*!
  * @struct StructBitfield8
  * @brief Bitfield 8b
 **/
  typedef struct StructBitfield8 {
    #ifndef REVERSE_BITFIELD
      uint8_t  b0  :1; //!< Bit 0 (LSB)
      uint8_t  b1  :1; //!< Bit 1
      uint8_t  b2  :1; //!< Bit 2
      uint8_t  b3  :1; //!< Bit 3
      uint8_t  b4  :1; //!< Bit 4
      uint8_t  b5  :1; //!< Bit 5
      uint8_t  b6  :1; //!< Bit 6
      uint8_t  b7  :1; //!< Bit 7 (MSB)
    #else
      uint8_t  b7  :1; //!< Bit 7 (MSB)
      uint8_t  b6  :1; //!< Bit 6
      uint8_t  b5  :1; //!< Bit 5
      uint8_t  b4  :1; //!< Bit 4
      uint8_t  b3  :1; //!< Bit 3
      uint8_t  b2  :1; //!< Bit 2
      uint8_t  b1  :1; //!< Bit 1
      uint8_t  b0  :1; //!< Bit 0 (LSB)
    #endif
  } sBitfield8;

 /*!
  * @struct StructBitfield16
  * @brief Bitfield 16b
 **/
  typedef struct StructBitfield16 {
    #ifndef REVERSE_BITFIELD
      uint16_t  b0  :1; //!< Bit 0 (LSB)
      uint16_t  b1  :1; //!< Bit 1
      uint16_t  b2  :1; //!< Bit 2
      uint16_t  b3  :1; //!< Bit 3
      uint16_t  b4  :1; //!< Bit 4
      uint16_t  b5  :1; //!< Bit 5
      uint16_t  b6  :1; //!< Bit 6
      uint16_t  b7  :1; //!< Bit 7
      uint16_t  b8  :1; //!< Bit 8
      uint16_t  b9  :1; //!< Bit 9
      uint16_t  b10 :1; //!< Bit 10
      uint16_t  b11 :1; //!< Bit 11
      uint16_t  b12 :1; //!< Bit 12
      uint16_t  b13 :1; //!< Bit 13
      uint16_t  b14 :1; //!< Bit 14
      uint16_t  b15 :1; //!< Bit 15 (MSB)
    #else
      uint16_t  b15 :1; //!< Bit 15 (MSB)
      uint16_t  b14 :1; //!< Bit 14
      uint16_t  b13 :1; //!< Bit 13
      uint16_t  b12 :1; //!< Bit 12
      uint16_t  b11 :1; //!< Bit 11
      uint16_t  b10 :1; //!< Bit 10
      uint16_t  b9  :1; //!< Bit 9
      uint16_t  b8  :1; //!< Bit 8
      uint16_t  b7  :1; //!< Bit 7
      uint16_t  b6  :1; //!< Bit 6
      uint16_t  b5  :1; //!< Bit 5
      uint16_t  b4  :1; //!< Bit 4
      uint16_t  b3  :1; //!< Bit 3
      uint16_t  b2  :1; //!< Bit 2
      uint16_t  b1  :1; //!< Bit 1
      uint16_t  b0  :1; //!< Bit 0 (LSB)
    #endif
  } sBitfield16;

 /*!
  * @struct StructBitfield32
  * @brief Bitfield 32b
 **/
  typedef struct StructBitfield32 {
    #ifndef REVERSE_BITFIELD
      uint32_t b0  :1; //!< Bit 0 (LSB)
      uint32_t b1  :1; //!< Bit 1
      uint32_t b2  :1; //!< Bit 2
      uint32_t b3  :1; //!< Bit 3
      uint32_t b4  :1; //!< Bit 4
      uint32_t b5  :1; //!< Bit 5
      uint32_t b6  :1; //!< Bit 6
      uint32_t b7  :1; //!< Bit 7
      uint32_t b8  :1; //!< Bit 8
      uint32_t b9  :1; //!< Bit 9
      uint32_t b10 :1; //!< Bit 10
      uint32_t b11 :1; //!< Bit 11
      uint32_t b12 :1; //!< Bit 12
      uint32_t b13 :1; //!< Bit 13
      uint32_t b14 :1; //!< Bit 14
      uint32_t b15 :1; //!< Bit 15
      uint32_t b16 :1; //!< Bit 16
      uint32_t b17 :1; //!< Bit 17
      uint32_t b18 :1; //!< Bit 18
      uint32_t b19 :1; //!< Bit 19
      uint32_t b20 :1; //!< Bit 20
      uint32_t b21 :1; //!< Bit 21
      uint32_t b22 :1; //!< Bit 22
      uint32_t b23 :1; //!< Bit 23
      uint32_t b24 :1; //!< Bit 24
      uint32_t b25 :1; //!< Bit 25
      uint32_t b26 :1; //!< Bit 26
      uint32_t b27 :1; //!< Bit 27
      uint32_t b28 :1; //!< Bit 28
      uint32_t b29 :1; //!< Bit 29
      uint32_t b30 :1; //!< Bit 30
      uint32_t b31 :1; //!< Bit 31 (MSB)
    #else
      uint32_t b31 :1; //!< Bit 31 (MSB)
      uint32_t b30 :1; //!< Bit 30
      uint32_t b29 :1; //!< Bit 29
      uint32_t b28 :1; //!< Bit 28
      uint32_t b27 :1; //!< Bit 27
      uint32_t b26 :1; //!< Bit 26
      uint32_t b25 :1; //!< Bit 25
      uint32_t b24 :1; //!< Bit 24
      uint32_t b23 :1; //!< Bit 23
      uint32_t b22 :1; //!< Bit 22
      uint32_t b21 :1; //!< Bit 21
      uint32_t b20 :1; //!< Bit 20
      uint32_t b19 :1; //!< Bit 19
      uint32_t b18 :1; //!< Bit 18
      uint32_t b17 :1; //!< Bit 17
      uint32_t b16 :1; //!< Bit 16
      uint32_t b15 :1; //!< Bit 15
      uint32_t b14 :1; //!< Bit 14
      uint32_t b13 :1; //!< Bit 13
      uint32_t b12 :1; //!< Bit 12
      uint32_t b11 :1; //!< Bit 11
      uint32_t b10 :1; //!< Bit 10
      uint32_t b9  :1; //!< Bit 9
      uint32_t b8  :1; //!< Bit 8
      uint32_t b7  :1; //!< Bit 7
      uint32_t b6  :1; //!< Bit 6
      uint32_t b5  :1; //!< Bit 5
      uint32_t b4  :1; //!< Bit 4
      uint32_t b3  :1; //!< Bit 3
      uint32_t b2  :1; //!< Bit 2
      uint32_t b1  :1; //!< Bit 1
      uint32_t b0  :1; //!< Bit 0 (LSB)
    #endif
  } sBitfield32;

 /*!
  * @struct StructBitfield64
  * @brief Bitfield 64b
  */
  typedef struct StructBitfield64 {
    #ifndef REVERSE_BITFIELD
      uint64_t b0  :1; //!< Bit 0 (LSB)
      uint64_t b1  :1; //!< Bit 1
      uint64_t b2  :1; //!< Bit 2
      uint64_t b3  :1; //!< Bit 3
      uint64_t b4  :1; //!< Bit 4
      uint64_t b5  :1; //!< Bit 5
      uint64_t b6  :1; //!< Bit 6
      uint64_t b7  :1; //!< Bit 7
      uint64_t b8  :1; //!< Bit 8
      uint64_t b9  :1; //!< Bit 9
      uint64_t b10 :1; //!< Bit 10
      uint64_t b11 :1; //!< Bit 11
      uint64_t b12 :1; //!< Bit 12
      uint64_t b13 :1; //!< Bit 13
      uint64_t b14 :1; //!< Bit 14
      uint64_t b15 :1; //!< Bit 15
      uint64_t b16 :1; //!< Bit 16
      uint64_t b17 :1; //!< Bit 17
      uint64_t b18 :1; //!< Bit 18
      uint64_t b19 :1; //!< Bit 19
      uint64_t b20 :1; //!< Bit 20
      uint64_t b21 :1; //!< Bit 21
      uint64_t b22 :1; //!< Bit 22
      uint64_t b23 :1; //!< Bit 23
      uint64_t b24 :1; //!< Bit 24
      uint64_t b25 :1; //!< Bit 25
      uint64_t b26 :1; //!< Bit 26
      uint64_t b27 :1; //!< Bit 27
      uint64_t b28 :1; //!< Bit 28
      uint64_t b29 :1; //!< Bit 29
      uint64_t b30 :1; //!< Bit 30
      uint64_t b31 :1; //!< Bit 31
      uint64_t b32 :1; //!< Bit 32
      uint64_t b33 :1; //!< Bit 33
      uint64_t b34 :1; //!< Bit 34
      uint64_t b35 :1; //!< Bit 35
      uint64_t b36 :1; //!< Bit 36
      uint64_t b37 :1; //!< Bit 37
      uint64_t b38 :1; //!< Bit 38
      uint64_t b39 :1; //!< Bit 39
      uint64_t b40 :1; //!< Bit 40
      uint64_t b41 :1; //!< Bit 41
      uint64_t b42 :1; //!< Bit 42
      uint64_t b43 :1; //!< Bit 43
      uint64_t b44 :1; //!< Bit 44
      uint64_t b45 :1; //!< Bit 45
      uint64_t b46 :1; //!< Bit 46
      uint64_t b47 :1; //!< Bit 47
      uint64_t b48 :1; //!< Bit 48
      uint64_t b49 :1; //!< Bit 49
      uint64_t b50 :1; //!< Bit 50
      uint64_t b51 :1; //!< Bit 51
      uint64_t b52 :1; //!< Bit 52
      uint64_t b53 :1; //!< Bit 53
      uint64_t b54 :1; //!< Bit 54
      uint64_t b55 :1; //!< Bit 55
      uint64_t b56 :1; //!< Bit 56
      uint64_t b57 :1; //!< Bit 57
      uint64_t b58 :1; //!< Bit 58
      uint64_t b59 :1; //!< Bit 59
      uint64_t b60 :1; //!< Bit 60
      uint64_t b61 :1; //!< Bit 61
      uint64_t b62 :1; //!< Bit 62
      uint64_t b63 :1; //!< Bit 63 (MSB)
    #else
      uint64_t b63 :1; //!< Bit 63 (MSB)
      uint64_t b62 :1; //!< Bit 62
      uint64_t b61 :1; //!< Bit 61
      uint64_t b60 :1; //!< Bit 60
      uint64_t b59 :1; //!< Bit 59
      uint64_t b58 :1; //!< Bit 58
      uint64_t b57 :1; //!< Bit 57
      uint64_t b56 :1; //!< Bit 56
      uint64_t b55 :1; //!< Bit 55
      uint64_t b54 :1; //!< Bit 54
      uint64_t b53 :1; //!< Bit 53
      uint64_t b52 :1; //!< Bit 52
      uint64_t b51 :1; //!< Bit 51
      uint64_t b50 :1; //!< Bit 50
      uint64_t b49 :1; //!< Bit 49
      uint64_t b48 :1; //!< Bit 48
      uint64_t b47 :1; //!< Bit 47
      uint64_t b46 :1; //!< Bit 46
      uint64_t b45 :1; //!< Bit 45
      uint64_t b44 :1; //!< Bit 44
      uint64_t b43 :1; //!< Bit 43
      uint64_t b42 :1; //!< Bit 42
      uint64_t b41 :1; //!< Bit 41
      uint64_t b40 :1; //!< Bit 40
      uint64_t b39 :1; //!< Bit 39
      uint64_t b38 :1; //!< Bit 38
      uint64_t b37 :1; //!< Bit 37
      uint64_t b36 :1; //!< Bit 36
      uint64_t b35 :1; //!< Bit 35
      uint64_t b34 :1; //!< Bit 34
      uint64_t b33 :1; //!< Bit 33
      uint64_t b32 :1; //!< Bit 32
      uint64_t b31 :1; //!< Bit 31
      uint64_t b30 :1; //!< Bit 30
      uint64_t b29 :1; //!< Bit 29
      uint64_t b28 :1; //!< Bit 28
      uint64_t b27 :1; //!< Bit 27
      uint64_t b26 :1; //!< Bit 26
      uint64_t b25 :1; //!< Bit 25
      uint64_t b24 :1; //!< Bit 24
      uint64_t b23 :1; //!< Bit 23
      uint64_t b22 :1; //!< Bit 22
      uint64_t b21 :1; //!< Bit 21
      uint64_t b20 :1; //!< Bit 20
      uint64_t b19 :1; //!< Bit 19
      uint64_t b18 :1; //!< Bit 18
      uint64_t b17 :1; //!< Bit 17
      uint64_t b16 :1; //!< Bit 16
      uint64_t b15 :1; //!< Bit 15
      uint64_t b14 :1; //!< Bit 14
      uint64_t b13 :1; //!< Bit 13
      uint64_t b12 :1; //!< Bit 12
      uint64_t b11 :1; //!< Bit 11
      uint64_t b10 :1; //!< Bit 10
      uint64_t b9  :1; //!< Bit 9
      uint64_t b8  :1; //!< Bit 8
      uint64_t b7  :1; //!< Bit 7
      uint64_t b6  :1; //!< Bit 6
      uint64_t b5  :1; //!< Bit 5
      uint64_t b4  :1; //!< Bit 4
      uint64_t b3  :1; //!< Bit 3
      uint64_t b2  :1; //!< Bit 2
      uint64_t b1  :1; //!< Bit 1
      uint64_t b0  :1; //!< Bit 0 (LSB)
    #endif
  } sBitfield64;


 /*!
  * @union UnionByte
  * @brief Union for uint8_t
 **/
  typedef union UnionByte {
    uint8_t    Byte; //!< uint8_t
    sBitfield8  Bits; //!< Bits
  } uuByte;

 /*!
  * @union UnionWord
  * @brief Union for uint16_t
 **/
  typedef union UnionWord {
    uint16_t      Word;    //!< 16b
    uint8_t      Byte[2];  //!< Bytes tab
    struct {
      #ifdef LITTLE_ENDIAN
        uint8_t  B0 :8;    //!< LSByte
        uint8_t  B1 :8;    //!< MSByte
      #else
        uint8_t  B1 :8;    //!< MSByte
        uint8_t  B0 :8;    //!< LSByte
      #endif
    } Bytes;
    sBitfield16   Bits;    //!< Bits
  } uuWord;

 /*!
  * @union UnionDWord
  * @brief Union for uint32_t
 **/
  typedef union UnionDWord {
    uint32_t     DWord;    //!< 32b
    uint16_t     Word[2];  //!< Words tab
    uint8_t      Byte[4];  //!< Bytes tab
    struct {
      #ifdef LITTLE_ENDIAN
        uint16_t  W0 :16;   //!< W0 LSWord
        uint16_t  W1 :16;   //!< W1 MSWord
      #else
        uint16_t  W1 :16;   //!< W1 MSWord
        uint16_t  W0 :16;   //!< W0 LSWord
      #endif
    } Words;
    struct {
      #ifdef LITTLE_ENDIAN
        uint8_t  B0 :8;    //!< B0 LSByte
        uint8_t  B1 :8;    //!< B1
        uint8_t  B2 :8;    //!< B2
        uint8_t  B3 :8;    //!< B3 MSByte
      #else
        uint8_t  B3 :8;    //!< B3 MSByte
        uint8_t  B2 :8;    //!< B2
        uint8_t  B1 :8;    //!< B1
        uint8_t  B0 :8;    //!< B0 LSByte
      #endif
    } Bytes;
    sBitfield32   Bits;   //!< Bits
  } uuDWord;

 /*!
  * @union UnionLWord
  * @brief Union for uint64_t
 **/
  typedef union UnionLWord {
    uint64_t     LWord;    //!< 64b
    uint32_t     DWord[2]; //!< DWords tab
    uint16_t     Word[4];  //!< Words tab
    uint8_t      Byte[8];  //!< Bytes tab
    struct {
      #ifdef LITTLE_ENDIAN
        uint32_t D0 :32;   //!< DW0 LSDWord
        uint32_t D1 :32;   //!< DW1 MSDWord
      #else
        uint32_t D1 :32;   //!< DW1 MSDWord
        uint32_t D0 :32;   //!< DW0 LSDWord
      #endif
    } DWords;
    struct {
      #ifdef LITTLE_ENDIAN
        uint16_t  W0 :16;   //!< W0 LSWord
        uint16_t  W1 :16;   //!< W1
        uint16_t  W2 :16;   //!< W2
        uint16_t  W3 :16;   //!< W3 MSWord
      #else
        uint16_t  W3 :16;   //!< W3 MSWord
        uint16_t  W2 :16;   //!< W2
        uint16_t  W1 :16;   //!< W1
        uint16_t  W0 :16;   //!< W0 LSWord
      #endif
    } Words;
    struct {
      #ifdef LITTLE_ENDIAN
        uint8_t  B0 :8;    //!< B0 LSByte
        uint8_t  B1 :8;    //!< B1
        uint8_t  B2 :8;    //!< B2
        uint8_t  B3 :8;    //!< B3
        uint8_t  B4 :8;    //!< B4
        uint8_t  B5 :8;    //!< B5
        uint8_t  B6 :8;    //!< B6
        uint8_t  B7 :8;    //!< B7 MSByte
      #else
        uint8_t  B7 :8;    //!< B7 MSByte
        uint8_t  B6 :8;    //!< B6
        uint8_t  B5 :8;    //!< B5
        uint8_t  B4 :8;    //!< B4
        uint8_t  B3 :8;    //!< B3
        uint8_t  B2 :8;    //!< B2
        uint8_t  B1 :8;    //!< B1
        uint8_t  B0 :8;    //!< B0 LSByte
      #endif
    } Bytes;
    sBitfield64   Bits;   //!< Bits
  } uuLWord;

  /*!
   * @union UnionDWord
   * @brief Union for uint32_t
  **/
typedef union UnionFloat {
  float    Float;
  uint32_t DWord;    //!< 32b
  uint16_t Word[2];  //!< Words tab
  uint8_t  Byte[4];  //!< Bytes tab
  struct {
#ifdef LITTLE_ENDIAN
    uint16_t W0 :16;   //!< W0 LSWord
    uint16_t W1 :16;   //!< W1 MSWord
#else
    uint16_t W1 :16;   //!< W1 MSWord
    uint16_t W0 :16;   //!< W0 LSWord
#endif
  } Words;
  struct {
#ifdef LITTLE_ENDIAN
    uint8_t B0 :8;    //!< B0 LSByte
    uint8_t B1 :8;    //!< B1
    uint8_t B2 :8;    //!< B2
    uint8_t B3 :8;    //!< B3 MSByte
#else
    uint8_t B3 :8;    //!< B3 MSByte
    uint8_t B2 :8;    //!< B2
    uint8_t B1 :8;    //!< B1
    uint8_t B0 :8;    //!< B0 LSByte
#endif
  } Bytes;
  sBitfield32 Bits;   //!< Bits
} uuFloat;

/* Public macro --------------------------------------------------------------*/
/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @} */
/** @} */
#ifdef __cplusplus
}
#endif
#endif /* _CPU_TYPEDEFS_H_ */
