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
#ifndef CPL_GENERIC_IMPL_H_20210730222057
#define CPL_GENERIC_IMPL_H_20210730222057
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "../cpl_map.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CPL_PRIV_GENERIC_COMMA(...) ,

#define CPL_GENERIC_FUNC_IMPL(CTR_EXPR, DEF_EXPR, PREFIX, FUNC, ...)           \
    _Generic((CTR_EXPR), default: DEF_EXPR,                                    \
        CPL_MAP_FIXED(CPL_PRIV_GENERIC_ASSOC,                                  \
            CPL_PRIV_GENERIC_COMMA, (PREFIX, FUNC), __VA_ARGS__))

#define CPL_PRIV_GENERIC_ASSOC(PREFIX, FUNC, TYPE)                             \
    PREFIX##_##TYPE : PREFIX##_##TYPE##_##FUNC
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_GENERIC_IMPL_H_20210730222057
