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
* @file:        cpu_delay.c
* @date:        21 nov. 2018
* @author:      Onkelinx Ghislain
* @brief:       Include file for the software delay
*
******************************************************************************
* History
******************************************************************************
*
******************************************************************************
*/


/* Includes ------------------------------------------------------------------*/
#include "../cpu_delay.h"
#include "cmsis_device.h"
#include "../cpu_attr.h"


/* Private define ------------------------------------------------------------*/
#define DELAY_LOOP_CYCLES (4)        /*<! 4 cycles per loop. */
#define BSP_SUB_CLOCK_HZ  (32768)    /*<! Sub-Clock Oscillator */

/* Private enumerations ------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
STACKLESS__ static void BSP_software_delay_loop (uint32_t loop_cnt);

/* Private functions ---------------------------------------------------------*/


/***************************************************************************//**
* @brief       Delay the specified duration in units and return.
*
* @param[in]   delay  The number of 'units' to delay.
* @param[in]   units  The 'base' (bsp_delay_units_t) for the units specified.
*              Valid values are:
*              BSP_DELAY_UNITS_SECONDS,
*              BSP_DELAY_UNITS_MILLISECONDS,
*              BSP_DELAY_UNITS_MICROSECONDS.@n
*              For example:@n
*              At 1 MHz one cycle takes 1 microsecond (.000001 seconds).@n
*              At 12 MHz one cycle takes 1/12 microsecond or 83 nanoseconds.@n
*              Therefore one run through software_delay_loop() takes:
*              ~ (83 * DELAY_LOOP_CYCLES) or 332 ns.
*              A delay of 2 us therefore requires 2000ns/332ns or 6 loops.
*
* @note This function calls bsp_cpu_clock_get() which ultimately calls
*       R_CGC_SystemClockFreqGet() and therefore requires that the BSP has
*       already initialized the CGC (which it does as part of the Sysinit).
*       Care should be taken to ensure this remains the case if in the future
*       this function were to be called as part of the BSP initialization.
*
* @retval        None.
*******************************************************************************/
void BSP_SoftwareDelay(uint32_t delay, bsp_delay_units_t units)
{
    uint32_t iclk_hz;
    uint32_t cycles_requested;
    uint32_t ns_per_cycle;
    uint32_t loops_required;
    uint32_t total_us = (delay * units);  /** Convert the requested time to microseconds. */

    iclk_hz = HAL_RCC_GetSysClockFreq();  /** Get the system clock frequency in Hz. */

    /** The function can't accurately small time units BSP_DELAY_UNITS_MICROSECONDS with a clock as slow as
        BSP_SUB_CLOCK_HZ, so just delay one loop and return. */
    if ((iclk_hz <= BSP_SUB_CLOCK_HZ) &&
        (units == BSP_DELAY_UNITS_MICROSECONDS))
    {
        BSP_software_delay_loop((uint32_t)1UL);
    }
    else
    {
        ns_per_cycle = (1000000000)/iclk_hz;            /** Get the # of nanoseconds/cycle. */

        /** All calculations are expected to fit into 32 bits AND we are only doing integer math.
            Therefore scale total_us first to microseconds.
            Then scale to nanoseconds below here. For a small delay, for example 2 microseconds, convert
            to nanoseconds first, so the division by ns_per_cycle will actually yield a meaningful result.
            At the other end, for large second delays, if you scale to nanoseconds first you will overflow
            32 bits.
        */
        if (total_us >= ns_per_cycle)
        {
          /** Divide, then multiply to get microseconds --> nanoseconds / (ns/cycle).*/
          cycles_requested =  (total_us / ns_per_cycle) * 1000;
        }
        else
        {
          /** Multiply, then divide to get microseconds --> nanoseconds / (ns/cycle). */
          cycles_requested =  (total_us * 1000) / ns_per_cycle;
        }
        loops_required = cycles_requested / DELAY_LOOP_CYCLES;

        /** Only delay if the supplied parameters require a delay. If you can't meet the delay provided,
            just return. */
        if (loops_required > (uint32_t)0)
        {
          BSP_software_delay_loop(loops_required);
        }
    }
}

/***************************************************************************//**
* @brief This assembly language routine takes roughly 4 cycles per loop.
*        2 additional cycles occur when the loop exits.
*        The 'naked' attribute  indicates that the specified function does
*        not need prologue/epilogue sequences generated by the compiler.
*
* @param[in]     loop_cnt  The number of loops to iterate.
*
* @retval        None.
*
* @note
*******************************************************************************/
STACKLESS__ static void BSP_software_delay_loop (uint32_t loop_cnt) {
        __asm volatile ("sw_delay_loop:         \n"

#if defined(__ICCARM__)
                        "   subs r0, #1         \n"   ///< 1 cycle
#elif defined(__GNUC__)
                        "   sub r0, r0, #1      \n"   ///< 1 cycle
#endif

                        "   cmp r0, #0          \n"   ///< 1 cycle
/* CM0 has a different instruction set */
#ifdef __CORE_CM0PLUS_H_GENERIC
                        "   bne sw_delay_loop   \n"   ///< 2 cycles
#elif defined (__CORE_CM4_H_GENERIC)
                        "   bne.n sw_delay_loop \n"   ///< 2 cycles
#elif defined (__CORE_CM7_H_GENERIC)
                        "   bne.n sw_delay_loop \n"   ///< 2 cycles
#else
  #error "MCU core not defined yet"
#endif
                        "   bx lr               \n"); ///< 2 cycles

  /** loop_cnt is used but since it is used in assembly an unused parameter
   *  warning can be generated.
   */
  NOT_USED(loop_cnt);
}


/* Predecessor checks --------------------------------------------------------*/

/*
*******************************************************************************
*                        end of the cpu_delay.c file
*******************************************************************************
*/
