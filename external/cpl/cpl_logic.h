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
 *
 * @par Parameter requirements
 *
 * All functions in this header accept three types of parameter:
 * - A valid C @e identifier
 * - A sequence of characters which, when concatened to a valid @e identifier,
 *   can make a new valid @e identifier
 * - The empty token, which is the absence of a token. The C preprocessor still
 *   counts this as a token.
 *
 * The compiler will emit an error if a parameter doesn't meet these
 * requirements.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_LOGIC_H_20190806123812
#define CPL_LOGIC_H_20190806123812
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "impl/cpl_logic_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Expand to a boolean value converted from its parameter.
 *
 * - Expand to 0 if \p{A} is either 0, the empty token or a macro that itself
 *   expands to 0 or the empty token.
 * - Expand to 1 in all other cases as long as \p{A} meets the requirements to
 *   be a valid parameter.
 *
 * @expansion{
 *   CPL_BOOLEAN(0) => 0
 *   CPL_BOOLEAN(1) => 1
 *   CPL_BOOLEAN()  => 0 // Empty token
 *   #define X
 *   CPL_BOOLEAN(X) => 0 // 'X' expands to the empty token
 *   #define Y 0
 *   CPL_BOOLEAN(Y) => 0 // 'Y' expands to 0
 *   #define Z 1
 *   CPL_BOOLEAN(Z) => 1 // 'Z' expands to 1
 *   CPL_BOOLEAN(W) => 1 // 'W' isn't defined anywhere but is a valid parameter
 * }
 *
 * @param A : See parameter requirements in the file description
 */
#define CPL_BOOLEAN(A) CPL_BOOLEAN_IMPL(A)
/**
 * Logical NOT.
 *
 * Apply CPL_BOOLEAN() to its parameter before expanding.
 *
 * @expansion{
 *   CPL_NOT(0) => 1
 *   CPL_NOT(1) => 0
 *   CPL_NOT()  => 1 // Empty token
 *   #define X
 *   CPL_NOT(X) => 1 // 'X' expands to the empty token
 *   #define Y 0
 *   CPL_NOT(Y) => 1 // 'Y' expands to 0
 *   #define Z 1
 *   CPL_NOT(Z) => 0 // 'Z' expands to 1
 *   CPL_NOT(W) => 0 // 'W' isn't defined anywhere but is a valid parameter
 * }
 *
 * @param A : See parameter requirements in the file description
 */
#define CPL_NOT(A) CPL_NOT_IMPL(A)
/**
 * Logical AND
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_AND(0, 0) => 0
 *   CPL_AND(0, 1) => 0
 *   CPL_AND(1, 0) => 0
 *   CPL_AND(1, 1) => 1
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_AND(A, B) CPL_AND_IMPL(A, B)
/**
 * Logical OR
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_OR(0, 0) => 0
 *   CPL_OR(0, 1) => 1
 *   CPL_OR(1, 0) => 1
 *   CPL_OR(1, 1) => 1
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_OR(A, B) CPL_OR_IMPL(A, B)
/**
 * Logical NAND
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_NAND(0, 0) => 1
 *   CPL_NAND(0, 1) => 1
 *   CPL_NAND(1, 0) => 1
 *   CPL_NAND(1, 1) => 0
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_NAND(A, B) CPL_NAND_IMPL(A, B)
/**
 * Logical NOR
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_NOR(0, 0) => 1
 *   CPL_NOR(0, 1) => 0
 *   CPL_NOR(1, 0) => 0
 *   CPL_NOR(1, 1) => 0
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_NOR(A, B) CPL_NOR_IMPL(A, B)
/**
 * Logical XOR
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_XOR(0, 0) => 0
 *   CPL_XOR(0, 1) => 1
 *   CPL_XOR(1, 0) => 1
 *   CPL_XOR(1, 1) => 0
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_XOR(A, B) CPL_XOR_IMPL(A, B)
/**
 * Logical XNOR
 *
 * Apply CPL_BOOLEAN() to its parameters before expanding.
 *
 * @expansion{
 *   CPL_XNOR(0, 0) => 1
 *   CPL_XNOR(0, 1) => 0
 *   CPL_XNOR(1, 0) => 0
 *   CPL_XNOR(1, 1) => 1
 * }
 *
 * @param A, B : See parameter requirements in the file description
 */
#define CPL_XNOR(A, B) CPL_XNOR_IMPL(A, B)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_LOGIC_H_20190806123812
