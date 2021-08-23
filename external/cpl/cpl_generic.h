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
 *
 * @brief
 * Provide macros to easily create `_Generic()` expressions(aka
 * @e generic-selection).
 *
 * @see
 * @C17{6.5.1}
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_GENERIC_H_20190803125336
#define CPL_GENERIC_H_20190803125336
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "impl/cpl_generic_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Expands to a `_Generic()` expression where the associations are constructed
 * according to a determined pattern.
 *
 * The default association has to be set manually, the others are automatically
 * constructed as follows:
 * - Type      : `<prefix>_<type>`.
 * - Expression: `<prefix>_<type>_<func>`.
 *
 * @param CTR_EXPR : Controlling expression
 * @param DEF_EXPR : Default expression
 * @param PREFIX   : `<prefix>` (single word)
 * @param FUNC     : `<func>` (single word)
 * @param ...      : Comma separated list of `<type>` (each a single word)
 *
 * @expansion{
 * CPL_GENERIC_FUNC(x, 0, foo, bar, char, int) =>
 *     _Generic((x),
 *         default : 0,
 *         foo_char : foo_char_bar,
 *         foo_int : foo_int_bar
 *     )
 * }
 *
 * @example{
 * int x = CPL_GENERIC_FUNC(x, 0, foo, bar, char, int)(a, b); // x = foo_int_bar(a, b)
 * }
 */
#define CPL_GENERIC_FUNC(CTR_EXPR, DEF_EXPR, PREFIX, FUNC, ...)                \
    CPL_GENERIC_FUNC_IMPL(CTR_EXPR, DEF_EXPR, PREFIX, FUNC, __VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_GENERIC_H_20190803125336
