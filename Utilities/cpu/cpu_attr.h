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
* @file        cpu_attr.h
* @date        20 mei 2019
* @author      G.Onkelinx
* @brief       this are the compiler attributes
*
* @ingroup cpu_attr
******************************************************************************
*/

#ifndef _COMP_ATTR_H_
#define _COMP_ATTR_H_

#ifdef __cplusplus
 extern "C" {
#endif


 /***************************************************************************//**
   * @addtogroup Compiler The generic library for the compiler
   * @{
   * @addtogroup cpu_attr Attributes
   * @{
  ******************************************************************************/

/* Includes ------------------------------------------------------------------*/
/* Public define -------------------------------------------------------------*/
#if defined (__GNUC__)
  #define DO_PRAGMA(x)     _Pragma (#x)

  /*** GCC ***/
  // Declared as qualifier
  #define __WEAK           __attribute__((weak))                  //!< \b Weak attribute
  #define __IRQ            __attribute__((interrupt_handler))     //!< \b Interrupt attribute
  // Declared as attribute
  #define ATTR__(...)      __attribute__((__VA_ARGS__))           //!< Macro to define one or multiple attribute(s) \b ... for a declaration

  #define ALIGN__(n)       __attribute__((align(n)))              //!< \b Align attribute padded to \b n
  #define COLD__           __attribute__((cold))                  //!< \b Cold attribute
  #define DEPRECATED__     __attribute__((deprecated))            //!< \b Deprecated attribute
  #define HOT__            __attribute__((hot))                   //!< \b Hot attribute
  #define INLINE__         __attribute__((always_inline))         //!< \b Always \b inline attribute
  #define NONNULL__        __attribute__((nonnull))               //!< \b Non \b null attribute (all pointers will be checked)
  #define NONNULLX__(...)  __attribute__((nonnull(__VA_ARGS__)))  //!< \b Non \b null attribute for \b ... pointers indexes
  #define NORETURN__       __attribute__((noreturn))              //!< \b No \b return attribute
  #define PACK__           __attribute__((__packed__))            //!< \b Packed attribute
  #define PURE__           __attribute__((pure))                  //!< \b Pure attribute
  #define SECTION__(s)     __attribute__((section(#s)))           //!< \b Section attribute to place declaration into section \b s
  #define USED__           __attribute__((used))                  //!< \b Used attribute ensures declaration won't be removed by garbage collector
  #define UNUSED__         __attribute__((unused))

  // Common mixed attributes
  #define NONNULL_INLINE__  ATTR__(nonnull, always_inline)        //!< \b Ensures declaration won't be removed by garbage collector
  #define FORCE_INLINE __attribute__(( always_inline)) inline     //!< \b Always \b inline attribute
  #define STATIC_FORCE_INLINE __attribute__(( always_inline)) static inline     //!< \b Always \b inline attribute
  #define STACKLESS__      __attribute__((naked))                 //!< \b Do not use the stack

  #define PACK_PUSH(align)   DO_PRAGMA(pack(push,align))
  #define PACK_POP           DO_PRAGMA(pack(pop))

#else
  #error Unknown compiler. Attributes will not be recognized.
#endif

/* Public enumerations -------------------------------------------------------*/
/* Public typedef ------------------------------------------------------------*/
/* Public macro --------------------------------------------------------------*/
 /**
  * This macro is used to suppress compiler messages about a parameter not
  * being used in a function.
  * The nice thing about using this implementation is that it does not take any
  * extra RAM or ROM.
  */
 #define NOT_USED(p) (void) ((p))

/* Public constants ----------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Public function prototypes ------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

 /** @} */
 /** @} */
#ifdef __cplusplus
}
#endif
#endif /* _COMP_ATTR_H_ */
