/**
 * "Copyright (c) 2009 The Regents of the University of California.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement
 * is hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY
 * OF CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 */

/**
 * Bus Matrix register definitions.
 *
 * @author Thomas Schmid
 */

#ifndef _SAM3UMATRIXHARDWARE_H
#define _SAM3UMATRIXHARDWARE_H


/**
 * Bus Matrix Master Configuration Register, AT91 ARM Cortex-M3 based
 * Microcontrollers SAM3U Series, Preliminary, p. 341
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint8_t ulbt       :  3; // undefined length burst type
        uint8_t reserved0  :  5;
        uint8_t reserved1  :  8;
        uint16_t reserved2 : 16;
    }__attribute__((__packed__)) bits;
} matrix_mcfg_t;

#define MATRIX_MCFG_ULBT_INFINITE_BURST      0x0
#define MATRIX_MCFG_ULBT_SINGLE_ACCESS       0x1
#define MATRIX_MCFG_ULBT_FOUR_BEAT_BURST     0x2
#define MATRIX_MCFG_ULBT_EIGHT_BEAT_BURST    0x3
#define MATRIX_MCFG_ULBT_SIXTEEN_BEAT_BURST  0x4

/**
 * Bus Matrix Slave Configuration Register, AT91 ARM Cortex-M3 based
 * Microcontrollers SAM3U Series, Preliminary, p. 342
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint8_t slot_cycle   :  8; // maximum number of allowed cycles for a burst
        uint8_t reserved0    :  8;
        uint8_t defmstr_type :  2; // default master type
        uint8_t fixed_defmstr:  3; // fixed default master
        uint8_t reserved1    :  3;
        uint8_t arbt         :  2; // arbitration type
        uint8_t reserved2    :  6;
    }__attribute__((__packed__)) bits;
} matrix_scfg_t;

#define MATRIX_SCFG_MASTER_TYPE_NO_DEFAULT     0x0
#define MATRIX_SCFG_MASTER_TYPE_LAST_DEFAULT   0x1
#define MATRIX_SCFG_MASTER_TYPE_FIXED_DEFAULT  0x2

#define MATRIX_SCFG_ARBT_ROUND_ROBINT          0x0
#define MATRIX_SCFG_ARBT_FIXED_PRIO            0x1


/**
 * Bus Matrix Priority Register, AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3U Series, Preliminary, p. 343
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint8_t m0pr         : 2; // master 0 priority
        uint8_t reserved0    : 2;
        uint8_t m1pr         : 2; // master 1 priority
        uint8_t reserved1    : 2;
        uint8_t m2pr         : 2; // master 2 priority
        uint8_t reserved2    : 2;
        uint8_t m3pr         : 2; // master 3 priority
        uint8_t reserved3    : 2;
        uint8_t m4pr         : 2; // master 4 priority
        uint8_t reserved4    : 6;
        uint8_t reserved5    : 8;
    }__attribute__((__packed__)) bits;
} matrix_pras_t;

/**
 * Bus Matrix Master Remap Control Register, AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3U Series, Preliminary, p. 344
 */
typedef union
{
    uint32_t flat;
    struct
    {
        uint8_t rcb0        :  1; // remap command bit for ahb master 0
        uint8_t rcb1        :  1; // remap command bit for ahb master 1
        uint8_t rcb2        :  1; // remap command bit for ahb master 2
        uint8_t rcb3        :  1; // remap command bit for ahb master 3
        uint8_t rcb4        :  1; // remap command bit for ahb master 4
        uint8_t reserved0   :  3;
        uint8_t reserved1   :  8;
        uint16_t reserved2  : 16;
    }__attribute__((__packed__)) bits;
} matrix_mrcr_t;

/**
 * Bus Matrix Write Protection Mode Register, AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3U Series, Preliminary, p. 350
 */
typedef union
{
    uint32_t flat;
    struct
    {
      uint32_t wpen       :  1;
      uint32_t reserved0  :  7;
      uint32_t wpkey      : 24;
    }__attribute__((__packed__)) bits;
} matrix_wpmr_t;

/**
 * Bus Matrix Write Protection Mode Register, AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3U Series, Preliminary, p. 350
 */
typedef union
{
    uint32_t flat;
    struct
    {
      uint8_t wpvs       :  1;
      uint8_t reserved0  :  7;
      uint16_t wpkey     : 16;
      uint8_t reserved1  :  8;
    }__attribute__((__packed__)) bits;
} matrix_wpsr_t;


/**
 * Bus Matrix Register definitions,  AT91 ARM Cortex-M3 based Microcontrollers
 * SAM3U Series, Preliminary, p. 339
 */
typedef struct matrix
{
    volatile matrix_mcfg_t mcfg0; // master configuration register 0
    volatile matrix_mcfg_t mcfg1; // master configuration register 1
    volatile matrix_mcfg_t mcfg2; // master configuration register 2
    volatile matrix_mcfg_t mcfg3; // master configuration register 3
    volatile matrix_mcfg_t mcfg4; // master configuration register 4
    uint32_t reserved0[10];
    volatile matrix_scfg_t scfg0; // slave confgiruation register 0
    volatile matrix_scfg_t scfg1; // slave confgiruation register 1
    volatile matrix_scfg_t scfg2; // slave confgiruation register 2
    volatile matrix_scfg_t scfg3; // slave confgiruation register 3
    volatile matrix_scfg_t scfg4; // slave confgiruation register 4
    volatile matrix_scfg_t scfg5; // slave confgiruation register 5
    volatile matrix_scfg_t scfg6; // slave confgiruation register 6
    volatile matrix_scfg_t scfg7; // slave confgiruation register 7
    volatile matrix_scfg_t scfg8; // slave confgiruation register 8
    volatile matrix_scfg_t scfg9; // slave confgiruation register 9
    uint32_t reserved1[5];
    volatile matrix_pras_t pras0; // priority register A for slave 0
    uint32_t reserved2;
    volatile matrix_pras_t pras1; // priority register A for slave 0
    uint32_t reserved3;
    volatile matrix_pras_t pras2; // priority register A for slave 0
    uint32_t reserved4;
    volatile matrix_pras_t pras3; // priority register A for slave 0
    uint32_t reserved5;
    volatile matrix_pras_t pras4; // priority register A for slave 0
    uint32_t reserved6;
    volatile matrix_pras_t pras5; // priority register A for slave 0
    uint32_t reserved7;
    volatile matrix_pras_t pras6; // priority register A for slave 0
    uint32_t reserved8;
    volatile matrix_pras_t pras7; // priority register A for slave 0
    uint32_t reserved9;
    volatile matrix_pras_t pras8; // priority register A for slave 0
    uint32_t reserved10;
    volatile matrix_pras_t pras9; // priority register A for slave 0
    uint32_t reserved11[12];
    volatile matrix_mrcr_t mrcr;  // master remap control register
} matrix_t;

/**
 * Memory mapping for the MATRIX
 */
volatile matrix_t* MATRIX = (volatile matrix_t*) 0x400E0200; // MATRIX Base Address

#endif // _SAM3UMATRIXHARDWARE_H
