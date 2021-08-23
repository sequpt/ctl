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
 * Provide macros allowing direct and delayed concatenation of their arguments.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_CONCAT_H_20170807175029
#define CPL_CONCAT_H_20170807175029
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Concatenates two arguments after expanding them.
 *
 * @expansion{
 *  #define A foo
 *  #define B bar
 *  CPL_CONCAT_2(foo, bar) => foobar
 *  CPL_CONCAT_2(A, B)     => foobar
 * }
 */
#define CPL_CONCAT_2(A, B) CPL_CONCAT_RAW_2(A, B)
/**
 * Concatenates two arguments without expanding them.
 *
 * @expansion{
 *  #define A foo
 *  #define B bar
 *  CPL_CONCAT_RAW_2(foo, bar) => foobar
 *  CPL_CONCAT_RAW_2(A, B)     => AB
 * }
 */
#define CPL_CONCAT_RAW_2(A, B) A##B
/**
 * Concatenates three arguments after expanding them.
 *
 * @expansion{
 *  #define A foo
 *  #define B bar
 *  #define UNDERSCORE _
 *  CPL_CONCAT_3(foo, UNDERSCORE, bar) => foo_bar
 *  CPL_CONCAT_3(A, UNDERSCORE, B)     => foo_bar
 * }
 */
#define CPL_CONCAT_3(A, B, C) CPL_CONCAT_RAW_3(A, B, C)
/**
 * Concatenates three arguments without expanding them.
 *
 * @expansion{
 *  #define A foo
 *  #define B bar
 *  #define UNDERSCORE _
 *  CPL_CONCAT_RAW_3(foo, UNDERSCORE, bar) => fooUNDERSCOREbar
 *  CPL_CONCAT_RAW_3(A, UNDERSCORE, B)     => AUNDERSCOREB
 * }
 */
#define CPL_CONCAT_RAW_3(A, B, C) A##B##C
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_CONCAT_H_20170807175029
