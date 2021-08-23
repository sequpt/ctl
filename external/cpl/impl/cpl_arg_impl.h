// SPDX-License-Identifier: 0BSD
/*!
 * @file
 * @license{
 * BSD Zero Clause License
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 * }
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_ARG_IMPL_H_20210730044357
#define CPL_ARG_IMPL_H_20210730044357
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "../generated/cpl_arg_gen.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CPL_ARG_COUNT_IMPL(...)                                                \
    CPL_ARG_127(__VA_ARGS__,                                                   \
    126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, \
    111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99 , 98 , 97 , \
    96 , 95 , 94 , 93 , 92 , 91 , 90 , 89 , 88 , 87 , 86 , 85 , 84 , 83 , 82 , \
    81 , 80 , 79 , 78 , 77 , 76 , 75 , 74 , 73 , 72 , 71 , 70 , 69 , 68 , 67 , \
    66 , 65 , 64 , 63 , 62 , 61 , 60 , 59 , 58 , 57 , 56 , 55 , 54 , 53 , 52 , \
    51 , 50 , 49 , 48 , 47 , 46 , 45 , 44 , 43 , 42 , 41 , 40 , 39 , 38 , 37 , \
    36 , 35 , 34 , 33 , 32 , 31 , 30 , 29 , 28 , 27 , 26 , 25 , 24 , 23 , 22 , \
    21 , 20 , 19 , 18 , 17 , 16 , 15 , 14 , 13 , 12 , 11 , 10 , 9  , 8  , 7  , \
    6  , 5  , 4  , 3  , 2  , 1, ~)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_ARG_IMPL_H_20210730044357
