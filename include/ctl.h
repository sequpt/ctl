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
 * @brief
 * Provide generic abstract data types.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CTL_H_20210731192212
#define CTL_H_20210731192212
/*==============================================================================
    INCLUDE
==============================================================================*/
// CTL
#include "impl/ctl_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * List of availble ADTs.
 *
 * Names present in this list are to be used with CTL_DECLARE() and CTL_DEFINE()
 * macros.
 *
 * - To use an ADT, a macro called `<ADT>_TYPES`(where `<ADT>` is one of
 *   the name in the list) must be defined.
 * - That macro must expand to a comma separated list of types that will be used
 *   for the data.
 * - Each type must be a single word, therefore structures and pointers must be
 *   typedef'd.
 *
 * @example{
 * #define CTL_DYN_ARRAY_TYPES int, char, float
 * }
 */
#define CTL_ADT_LIST() \
    CTL_DYN_ARRAY
/**
 * Declares the necessary structures and functions to use an ADT with specific
 * data types.
 *
 * @param ADT : One name from the CTL_ADT_LIST() macro
 * @param ... : The `<ADT>_TYPES` macro defined for \p{ADT}
 *
 * @usage{
 * #define CTL_DYN_ARRAY_TYPES int, char, float
 * CTL_DECLARE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);
 * }
 */
#define CTL_DECLARE(ADT, ...) \
    CTL_DECLARE_IMPL(ADT, __VA_ARGS__)
/**
 * Defines the necessary structures and functions to use an ADT with specific
 * data types.
 *
 * @param ADT : One name from the CTL_ADT_LIST() macro
 * @param ... : The `<ADT>_TYPES` macro defined for \p{ADT}
 *
 * @usage{
 * #define CTL_DYN_ARRAY_TYPES int, char, float
 * CTL_DECLARE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);
 * CTL_DEFINE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);
 * }
 */
#define CTL_DEFINE(ADT, ...)                                                   \
    CTL_DEFINE_IMPL(ADT, __VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_H_20210731192212
