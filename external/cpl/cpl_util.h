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
 * Provide miscellaneous simple macros.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_UTIL_H_20190808212721
#define CPL_UTIL_H_20190808212721
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Delay the call to \p{M()}, allowing \p{...} to be expanded before being
 * passed as arguments to \p{M()}.
 *
 * @param M   : Macro to call
 * @param ... : Comma separated list of arguments to be passed to \p{M()}
 *
 * @expansion{
 *  #define A foo, bar
 *  #define B baz
 *  CPL_DEFER(M, foo, bar) => M(foo, bar)
 *  CPL_DEFER(M, A, B) => M(foo, bar, baz)
 *  #define M(...) __VA_ARGS__
 *  CPL_DEFER(M, foo, bar) => foo, bar
 *  CPL_DEFER(M, A, B) => foo, bar, baz
 * }
 */
#define CPL_DEFER(M, ...) M(__VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_UTIL_H_20190808212721
