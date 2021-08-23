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
#ifndef CTL_IMPL_H_20190822121726
#define CTL_IMPL_H_20190822121726
/*==============================================================================
    INCLUDE
==============================================================================*/
// CPL
#include "cpl/cpl_concat.h"
#include "cpl/cpl_generic.h"
#include "cpl/cpl_map.h"
#include "cpl/cpl_token.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Call CTL_DECLARE_ADT(ADT, T) for every type found in `__VA_ARGS__`.
 */
#define CTL_DECLARE_IMPL(ADT, ...)                                             \
    CPL_MAP_FIXED(CTL_DECLARE_ADT, CPL_SEMICOLON, (ADT), __VA_ARGS__)
/**
 * Call CTL_DEFINE_ADT(ADT, T) for every type found in `__VA_ARGS__`.
 */
#define CTL_DEFINE_IMPL(ADT, ...)                                              \
    CPL_MAP_FIXED(CTL_DEFINE_ADT, CPL_EMPTY, (ADT), __VA_ARGS__)

#define CTL_DECLARE_ADT(ADT, T)                                                \
    CTL_DEFINE_STRUCT(ADT, T)                                                  \
    CPL_CONCAT_2(ADT, _DECLARE_FUNC(ADT(T), T))

#define CTL_DEFINE_ADT(ADT, T) CPL_CONCAT_2(ADT, _DEFINE_FUNC(ADT(T), T))
/*------------------------------------------------------------------------------
    CTL_DEFINE_STRUCT()
------------------------------------------------------------------------------*/
/**
 * Since the structure isn't opaque and that ADT isn't actually defined, we want
 * to prevent the user to play with the 'type' member as much as possible by
 * declaring it as a const pointer to a const struct ADT.
 *
 * We can't just write 'typedef const struct ADT * const ADT' because _Generic()
 * sees its controlling expression as an lvalue and ignores the type-qualifier
 * and compatible types must be identically qualified.
 *
 * typedef const struct ADT * const ADT;
 * ADT adt;
 * _Generic(adt,
 *     ADT     : 1,
 *     default : 0
 * )
 *
 * In this case, the default association will trigger because inside _Generic()
 * adt is of type pointer to struct ADT and ADT is const pointer to struct ADT.
 *
 * The solution is to const-qualify struct ADT in the typedef and const-qualify
 * ADT in the ADT##_##T structure.
 *
 *  See: -
 * https://gustedt.wordpress.com/2018/06/15/c17-rvalues-and-function-types-drop-qualifiers/
 *       - C17 standard (ISO/IEC 9899:2017)
 *          - $6.5.1.1 p2
 *          - $6.7.3 p11
 */
#define CTL_DEFINE_STRUCT(ADT, T)                                              \
    typedef const struct ADT##_LOWER * ADT##_LOWER;                            \
    typedef struct ADT(T) {                                                    \
        union {                                                                \
            struct {                                                           \
                ADT##_STRUCT_CONTENT(T)                                        \
            };                                                                 \
            const ADT##_LOWER type;                                            \
        };                                                                     \
    } ADT(T);
/*------------------------------------------------------------------------------
    CTL_GENERIC_FUNC()
------------------------------------------------------------------------------*/
#define CTL_GENERIC_FUNC(OBJ, ADT, FUNC, ...)                                  \
    CPL_GENERIC_FUNC(*OBJ, 0, ADT, FUNC, __VA_ARGS__)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_IMPL_H_20190822121726
