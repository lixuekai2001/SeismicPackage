/*<license>
 -------------------------------------------------------------------------------
  Copyright (c) 2007 ConocoPhillips Company
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 -------------------------------------------------------------------------------
 </license>*/

/****************************************************************************
 * NCSA HDF                                                                 *
 * Software Development Group                                               *
 * National Center for Supercomputing Applications                          *
 * University of Illinois at Urbana-Champaign                               *
 * 605 E. Springfield, Champaign IL 61820                                   *
 *                                                                          *
 * For conditions of distribution and use, see the accompanying             *
 * hdf/COPYING file.                                                        *
 *                                                                          *
 ****************************************************************************/

/* $Id: hbitio.h,v 1.14 1996/10/28 22:48:26 koziol Exp $ */

/*
   **  hbitio.h
   **
   **  Data structures and macros for bitfile access to HDF data objects.
   **  These are mainly used for compression I/O and N-bit data objects.
 */

#ifndef __HBITIO_H
#define __HBITIO_H

/* Define the number of elements in the buffered array */
#define BITBUF_SIZE 4096
/* Macro to define the number of bits cached in the 'bits' variable */
#define BITNUM      (sizeof(uint8)*8)
/* Macro to define the number of bits able to be read/written at a time */
#define DATANUM     (sizeof(uint32)*8)

typedef struct bitrec_t
  {
      int32       acc_id;       /* Access ID for H layer I/O routines */
      int32       bit_id;       /* Bitfile ID for internal use */
  /* Note that since HDF has signed 32bit offset limit we need to change this to signed
     since the get passed to Hxxx calls which take signed 32bit arguments */
      int32      block_offset, /* offset of the current buffered block in the dataset */
                 max_offset,   /* offset of the last byte written to the dataset */
                 byte_offset;  /* offset of the current byte in the dataset */

      intn       count,        /* bit count to next boundary */
                 buf_read;     /* number of bytes read into buffer (necessary for random I/O) */
      uint8       access;       /* What the access on this file is ('r', 'w', etc..) */
      uint8       mode;         /* how are we interacting with the data now ('r', 'w', etc) */
      uint8       bits;         /* extra bit buffer, 0..BITNUM-1 bits */
      uint8      *bytep;        /* current position in buffer */
      uint8      *bytez;        /* end of buffer to compare */
      uint8      *bytea;        /* byte buffer */
  }
bitrec_t;

#ifndef BITMASTER
extern
#endif
const uint8 maskc[9]
#ifdef BITMASTER
=
{0, 1, 3, 7, 15, 31, 63, 127, 255}
#endif
           ;

#ifndef BITMASTER
extern
#endif
const uint32 maskl[33]
#ifdef BITMASTER
=
{0x00000000,
 0x00000001, 0x00000003, 0x00000007, 0x0000000f,
 0x0000001f, 0x0000003f, 0x0000007f, 0x000000ff,
 0x000001ff, 0x000003ff, 0x000007ff, 0x00000fff,
 0x00001fff, 0x00003fff, 0x00007fff, 0x0000ffff,
 0x0001ffff, 0x0003ffff, 0x0007ffff, 0x000fffff,
 0x001fffff, 0x003fffff, 0x007fffff, 0x00ffffff,
 0x01ffffff, 0x03ffffff, 0x07ffffff, 0x0fffffff,
 0x1fffffff, 0x3fffffff, 0x7fffffff, 0xffffffffUL}
#endif
           ;

/* Function-like Macros */
#define Hputbit(bitid,bit) ((Hbitwrite(bitid,1,(uint32)bit)==FAIL) ? FAIL : SUCCEED)

#endif /* __HBITIO_H */
