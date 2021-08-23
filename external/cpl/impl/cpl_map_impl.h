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
#ifndef CPL_MAP_IMPL_H_20210730005241
#define CPL_MAP_IMPL_H_20210730005241
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "../cpl_arg.h"
#include "../generated/cpl_map_gen.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CPL_PRIV_MAP_DEFER(M, ...) M(__VA_ARGS__)
#define CPL_PRIV_MAP_CONCAT(A, B)  CPL_PRIV_MAP_CONCAT_(A, B)
#define CPL_PRIV_MAP_CONCAT_(A, B) A##B
#define CPL_PRIV_MAP_UNPACK(...)   CPL_PRIV_MAP_EXPAND __VA_ARGS__
#define CPL_PRIV_MAP_EXPAND(...)   __VA_ARGS__

#define CPL_MAP_IMPL(M, S, ...)                                                \
    CPL_PRIV_MAP_CONCAT(CPL_MAP_FIXED_, CPL_ARG_COUNT(__VA_ARGS__))            \
    (CPL_PRIV_MAP_DEFER, S, (M), __VA_ARGS__)

#define CPL_MAP_FIXED_IMPL(M, S, F, ...)                                       \
    CPL_PRIV_MAP_CONCAT(CPL_MAP_FIXED_, CPL_ARG_COUNT(__VA_ARGS__))            \
    (M, S, F, __VA_ARGS__)

#define CPL_MAP_FIXED_0(M, ...) M(__VA_ARGS__)
#define CPL_MAP_FIXED_1(M, S, F, ...)                                          \
    CPL_MAP_FIXED_0(M, CPL_PRIV_MAP_UNPACK(F), __VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_MAP_IMPL_H_20210730005241
