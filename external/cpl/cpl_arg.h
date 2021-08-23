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
 * Provide macros to count arguments and select the nth argument.
 *
 * @todo
 * - Detect absence of argument
 * - Document macros in `cpl_arg_gen.h`
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_ARG_H_20170809192511
#define CPL_ARG_H_20170809192511
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "impl/cpl_arg_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Expand to the number of arguments given.
 *
 * Since the C preprocessor considers the absence of arguments as the presence
 * of an empty token, this macro can't detect when there is 0 argument.
 *
 * @param ... : Comma separated list of arguments
 *
 * @expansion{
 *   CPL_ARG_COUNT()        => 1
 *   CPL_ARG_COUNT(())      => 1
 *   CPL_ARG_COUNT(,)       => 2
 *   CPL_ARG_COUNT(,,)      => 3
 *   CPL_ARG_COUNT(a)       => 1
 *   CPL_ARG_COUNT(a, b, c) => 3
 * }
 *
 * @example{
 *   int x = CPL_ARG_COUNT(a, b, c); // x = 3
 * }
 */
#define CPL_ARG_COUNT(...) CPL_ARG_COUNT_IMPL(__VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_ARG_H_20170809192511
