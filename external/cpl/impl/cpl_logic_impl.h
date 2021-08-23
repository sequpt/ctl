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
#ifndef CPL_LOGIC_PRIV_H_20210726065202
#define CPL_LOGIC_PRIV_H_20210726065202
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/*
 * These four small macros are redefined here(with different names) to prevent
 * the inclusion of a lot of unnecessary things comming with other includes.
 */
#define CPL_PRIV_LOGIC_DEFER(M, ...)      M(__VA_ARGS__)
#define CPL_PRIV_LOGIC_ARG_2(A, B, ...)   B
#define CPL_PRIV_LOGIC_CONCAT_3(A, B, C)  CPL_PRIV_LOGIC_CONCAT_3_(A, B, C)
#define CPL_PRIV_LOGIC_CONCAT_3_(A, B, C) A##B##C
/*
 * The trick here is to change the number and position of the arguments that
 * will be passed to `CPL_PRIV_LOGIC_ARG_2()` according to the value of `A`.
 *
 * If `A` is 0 or the empty token, the resulting concatenation is either
 * `CPL_BOOLEAN_PRIV_` or CPL_BOOLEAN_PRIV_0, both of which expand to `~, 0`.
 * The call to `CPL_PRIV_LOGIC_ARG_2(~, 0, 1, ~)` expands to its 2nd argument
 * which is `0`.
 * If `A` is anything else, like `foo` for instance, the resulting concatenation
 * is `CPL_BOOLEAN_PRIV_foo` which doesn't expand any further.
 * The call to `CPL_PRIV_LOGIC_ARG_2(CPL_BOOLEAN_PRIV_foo, 1, ~)` expands to its
 * 2nd argument which is `1`.
 *
 * The call to `CPL_PRIV_LOGIC_DEFER()` is needed to let `CPL_BOOLEAN_PRIV_##A`
 * expands if possible.
 *
 * The `~` at the end of the parameters list is needed because
 * `CPL_PRIV_LOGIC_ARG_2()` needs at least 3 arguments.
 */
#define CPL_BOOLEAN_IMPL(A)                                                    \
    CPL_PRIV_LOGIC_DEFER(CPL_PRIV_LOGIC_ARG_2, CPL_BOOLEAN_PRIV_##A, 1, ~)
#define CPL_BOOLEAN_PRIV_  ~, 0
#define CPL_BOOLEAN_PRIV_0 ~, 0
/*
 * This is the same principle as for `CPL_BOOLEAN_IMPL()` but the boolean values
 * are inverted.
 */
#define CPL_NOT_IMPL(A)                                                        \
    CPL_PRIV_LOGIC_DEFER(CPL_PRIV_LOGIC_ARG_2, CPL_PRIV_NOT_##A, 0, ~)
#define CPL_PRIV_NOT_  ~, 1
#define CPL_PRIV_NOT_0 ~, 1
/*
 * The previous method is not applicable for `CPL_AND_IMPL()` because
 * concatenations involving a parameter which is neither `0`, `1` nor the empty
 * token can evaluate to different values.
 *
 * If `A` is `foo` for example and `B` is either `0` or `1`, it'd result in
 * two possible concatenations `CPL_PRIV_AND_foo0' and `CPL_PRIV_AND_foo1',
 * which should have different values but evaluate both to `1` since they are
 * not defined.
 * These macros could be defined of course but then it would only work for
 * `foo`. Macros for other values would have to be manually created everytime
 * there is a need to evaluate them the correct value.
 *
 * So for this function, parameters are first converted to their boolean values
 * before concatening them both to `CPL_PRIV_AND_` which now serves as a prefix
 * to a more classical truth table.
 */
#define CPL_AND_IMPL(A, B)                                                     \
    CPL_PRIV_LOGIC_CONCAT_3(CPL_PRIV_AND_, CPL_BOOLEAN(A), CPL_BOOLEAN(B))
#define CPL_PRIV_AND_00 0
#define CPL_PRIV_AND_01 0
#define CPL_PRIV_AND_10 0
#define CPL_PRIV_AND_11 1
/**
 * This time, contrary to `CPL_AND_IMPL()`, all concatenations involving a
 * parameter which is neither `0`, `1` nor the empty token evalute to `1`.
 * Therefore the method used for `CPL_BOOLEAN_IMPL()` can be used here as well.
 *
 * Although `CPL_OR_IMPL()` could be defined in the same way as `CPL_AND_IMPL()`
 * is, it involves more macro expansions and they should be avoided as long as
 * the readability isn't heavily affected.
 */
#define CPL_OR_IMPL(A, B)                                                      \
    CPL_PRIV_LOGIC_DEFER(CPL_PRIV_LOGIC_ARG_2, CPL_PRIV_OR_##A##B, 1, ~)
#define CPL_PRIV_OR_   ~, 0
#define CPL_PRIV_OR_0  ~, 0
#define CPL_PRIV_OR_00 ~, 0
/**
 * Same method as `CPL_AND_IMPL()` but boolean values are inverted.
 */
#define CPL_NAND_IMPL(A, B)                                                    \
    CPL_PRIV_LOGIC_CONCAT_3(CPL_PRIV_NAND_, CPL_BOOLEAN(A), CPL_BOOLEAN(B))
#define CPL_PRIV_NAND_00 1
#define CPL_PRIV_NAND_01 1
#define CPL_PRIV_NAND_10 1
#define CPL_PRIV_NAND_11 0
/**
 * Same method as `CPL_OR_IMPL()` but boolean values are inverted.
 */
#define CPL_NOR_IMPL(A, B)                                                     \
    CPL_PRIV_LOGIC_DEFER(CPL_PRIV_LOGIC_ARG_2, CPL_PRIV_NOR_##A##B, 0, ~)
#define CPL_PRIV_NOR_   ~, 1
#define CPL_PRIV_NOR_0  ~, 1
#define CPL_PRIV_NOR_00 ~, 1
/**
 * Etc.
 */
#define CPL_XOR_IMPL(A, B)                                                     \
    CPL_PRIV_LOGIC_CONCAT_3(CPL_PRIV_XOR_, CPL_BOOLEAN(A), CPL_BOOLEAN(B))
#define CPL_PRIV_XOR_00 0
#define CPL_PRIV_XOR_01 1
#define CPL_PRIV_XOR_10 1
#define CPL_PRIV_XOR_11 0
/**
 * Etc.
 */
#define CPL_XNOR_IMPL(A, B)                                                    \
    CPL_PRIV_LOGIC_CONCAT_3(CPL_PRIV_XNOR_, CPL_BOOLEAN(A), CPL_BOOLEAN(B))
#define CPL_PRIV_XNOR_00 1
#define CPL_PRIV_XNOR_01 0
#define CPL_PRIV_XNOR_10 0
#define CPL_PRIV_XNOR_11 1
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_LOGIC_PRIV_H_20210726065202
