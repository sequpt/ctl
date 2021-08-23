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
 * Provide macros to evaluate simple boolean functions.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_MAP_H_20190728222334
#define CPL_MAP_H_20190728222334
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "impl/cpl_map_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Apply \p{M()} to each argument of \p{...} and separate two calls of \p{M()}
 * with a call to \p{S()}.
 *
 * - \p{S()} is not called if there is only one call to \p{M()}.
 *
 * @expansion{
 *   CPL_MAP(M, S,)              => M()
 *   CPL_MAP(M, S, a)            => M(a)
 *   CPL_MAP(M, S, a, b, c)      => M(a) S() M(b) S() M(c)
 *   CPL_MAP(M, S, (a, b, c), d) => M((a, b, c)) S() M(d)
 * }
 *
 * @param M   : Called as \p{M()} and applied to each arguments of \p{...}
 * @param S   : Called as \p{S()} and inserted between two calls of \p{M()}
 * @param ... : Comma separated list of arguments
 */
#define CPL_MAP(M, S, ...) CPL_MAP_IMPL(M, S, __VA_ARGS__)
/**
 * Apply \p{M()} to each argument of \p{...}, taking the tuple \p{F} as
 * parameter of \p{M()}, and separate calls to \p{M()} with the expansion of
 * \p{S()}.
 *
 * - \p{S()} is not called if there is only 1 call to \p{M()}.
 *
 * @expansion{
 * CPL_MAP_FIXED(M, S, (F),)            => M(F,)
 * CPL_MAP_FIXED(M, S, (F), a)          => M(F, a)
 * CPL_MAP_FIXED(M, S, ((F)), a)        => M((F), a)
 * CPL_MAP_FIXED(M, S, (F), a, (b), c)  => M(F, a) S() M(F, (b)) S() M(F, c)
 * CPL_MAP_FIXED(M, S, (F, G), a, b, c) => M(F, G, a) S() M(F, G, b) S() M(F, G, c)
 * }
 *
 * @param M   : Called as \p{M()} and applied to each arguments of \p{...}
 * @param S   : Called as \p{S()} and inserted between two calls of \p{M()}
 * @param F   : Tuple of arguments inserted at the begining of the \p{M()}
 *              parameters list
 * @param ... : Comma separated list of arguments
 */
#define CPL_MAP_FIXED(M, S, F, ...) CPL_MAP_FIXED_IMPL(M, S, F, __VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_MAP_H_20190728222334
