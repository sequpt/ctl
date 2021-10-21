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
 * free space:   used space:
 * +---+         +---+
 * |   |         |///|
 * +---+         +---+
 *
 *  start         end
 *    |            |
 *    |  capacity  |
 *    |<---------->|
 *    +------------+
 *    |//////|     |
 *    +------------+
 *     <---->|
 *      size |
 *           |
 *          back
 *
 * 1)
 *    +-------+  |  start < back < end   |  push: back++
 *    |///|   |  |  0 < size < capacity  |  pop : back--
 *    +-------+  |                       |
 * 2)            |                       |
 *    +-------+  |  start < back = end   |  push: grow -> back++
 *    |///////|  |  0 < size = capacity  |  pop : back--
 *    +-------+  |                       |
 * 3)            |                       |
 *    +-------+  |  start = back < end   |  push: back++
 *    ||      |  |  0 = size < capacity  |  pop : error
 *    +-------+  |                       |
 * 4)            |                       |
 *    +          |  start = back = end   |  push: grow -> back++
 *    |          |  0 = size = capacity  |  pop : error
 *    +          |                       |
 *
 * size > 0       : {1, 2}    <=> start < back
 * size = 0       : {3, 4}    <=> start = back
 * size < capacity: {1, 3}    <=> back  < end
 * size = capacity: {2, 4}    <=> back  = end
 * capacity > 0   : {1, 2, 3} <=> start < end
 * capacity = 0   : {4}       <=> start = end
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CTL_STACK_IMPL_H_20210825213638
#define CTL_STACK_IMPL_H_20210825213638
/*==============================================================================
    INCLUDE
==============================================================================*/
// CTL
#include "ctl_impl.h"
// C Standard Library
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>  // fprintf()
#include <stdlib.h> // size_t, NULL, malloc(), free()
#include <string.h> // memmove(), strerror()
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CTL_STACK_IMPL(T) ctl_stack_##T

#define CTL_STACK_LOWER ctl_stack

#define CTL_STACK_FUNC(OBJ, FUNC)                                              \
    CTL_GENERIC_FUNC(OBJ, CTL_STACK_LOWER, FUNC, CTL_STACK_TYPES)

#define CTL_STACK_STRUCT_CONTENT(T)                                            \
    T * start;                                                                 \
    T * back;                                                                  \
    T * end;

#define CTL_STACK_DECLARE_FUNC(ADT, T)                                         \
    ADT * ADT##_Create(void);                                                  \
    void ADT##_Destroy(ADT ** adt);                                            \
    size_t ADT##_Size(const ADT * adt);                                        \
    size_t ADT##_Capacity(const ADT * adt);                                    \
    _Bool ADT##_IsEmpty(const ADT * adt);                                      \
    _Bool ADT##_Reserve(ADT * adt, size_t capacity);                           \
    void ADT##_Clear(ADT * adt);                                               \
    T ADT##_At(const ADT * adt, size_t index);                                 \
    T ADT##_Back(const ADT * adt);                                             \
    void ADT##_Push(ADT * adt, T data);                                        \
    T ADT##_Pop(ADT * adt);                                                    \
    void ADT##_Resize(ADT * adt, size_t size);                                 \
    void ADT##_ShrinkToFit(ADT * adt)

#define CTL_STACK_DEFINE_FUNC(ADT, T)                                          \
static _Bool ADT##_grow(ADT * const adt)                                       \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t old_capacity = ADT##_Capacity(adt);                           \
    size_t new_capacity = (size_t)((double)old_capacity * 1.5);                \
    new_capacity += (new_capacity == old_capacity);                            \
    return ADT##_Reserve(adt, new_capacity);                                   \
}                                                                              \
ADT * ADT##_Create(void)                                                       \
{                                                                              \
    ADT * adt = malloc(sizeof(*adt));                                          \
    if(adt != NULL) {                                                          \
        adt->start = adt->end = adt->back = NULL;                              \
    } else {                                                                   \
        fprintf(stderr, "malloc() failed! %s\n", strerror(errno));             \
    }                                                                          \
    return adt;                                                                \
}                                                                              \
void ADT##_Destroy(ADT ** const adt)                                           \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(*adt != NULL);                                                      \
    free((*adt)->start);                                                       \
    free(*adt);                                                                \
    *adt = NULL;                                                               \
}                                                                              \
size_t ADT##_Size(const ADT * const adt)                                       \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->start != adt->back) ? (size_t)(adt->back - adt->start) : 0;   \
}                                                                              \
size_t ADT##_Capacity(const ADT * const adt)                                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->start != adt->end) ? (size_t)(adt->end - adt->start) : 0;     \
}                                                                              \
_Bool ADT##_IsEmpty(const ADT * const adt)                                     \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->start == adt->back);                                          \
}                                                                              \
_Bool ADT##_Reserve(ADT * const adt, const size_t capacity)                    \
{                                                                              \
    assert(adt != NULL);                                                       \
    if(capacity > ADT##_Capacity(adt)) {                                       \
        const size_t size = ADT##_Size(adt);                                   \
        T * const start   = realloc(adt->start, sizeof(T) * capacity);         \
        if(start != NULL) {                                                    \
            adt->start = start;                                                \
            adt->end   = start + capacity;                                     \
            adt->back  = start + size;                                         \
            return true;                                                       \
        }                                                                      \
        fprintf(stderr, "realloc() failed! %s\n", strerror(errno));            \
    }                                                                          \
    return false;                                                              \
}                                                                              \
void ADT##_Clear(ADT * const adt)                                              \
{                                                                              \
    assert(adt != NULL);                                                       \
    adt->back = adt->start;                                                    \
}                                                                              \
T ADT##_At(const ADT * const adt, const size_t index)                          \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    assert(index < (size_t)(adt->back - adt->start));                          \
    return *(adt->start + index);                                              \
}                                                                              \
T ADT##_Back(const ADT * const adt)                                            \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    assert(adt->start < adt->back);                                            \
    return *(adt->back - 1);                                                   \
}                                                                              \
void ADT##_Push(ADT * const adt, const T data)                                 \
{                                                                              \
    assert(adt != NULL);                                                       \
    /* {1, 3} */                                                               \
    if((adt->back == adt->end)) {                                              \
        ADT##_grow(adt);                                                       \
    /* {2, 4} */                                                               \
    }                                                                          \
        *adt->back++ = data;                                                   \
}                                                                              \
T ADT##_Pop(ADT * const adt)                                                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    assert(adt->start < adt->back);                                            \
    return *--adt->back;                                                       \
}                                                                              \
void ADT##_Resize(ADT * const adt, const size_t size)                          \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t capacity = ADT##_Capacity(adt);                               \
    if(size > capacity) {                                                      \
        T * const start = realloc(adt->start, sizeof(T) * size);               \
        if(start != NULL) {                                                    \
            adt->start = start;                                                \
            adt->end = adt->back = start + size;                               \
        } else {                                                               \
            fprintf(stderr, "realloc() failed! %s\n", strerror(errno));        \
        }                                                                      \
    } else {                                                                   \
        adt->back += -(ADT##_Size(adt) - size);                                \
    }                                                                          \
}                                                                              \
void ADT##_ShrinkToFit(ADT * const adt)                                        \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t size = ADT##_Size(adt);                                       \
    if(size != ADT##_Capacity(adt)) {                                          \
        T * const start = realloc(adt->start, sizeof(T) * size);               \
        if(start != NULL) {                                                    \
            adt->start = start;                                                \
            adt->end = adt->back = start + size;                               \
        } else {                                                               \
            fprintf(stderr, "realloc() failed! %s\n", strerror(errno));        \
        }                                                                      \
    }                                                                          \
}
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_STACK_IMPL_H_20210825213638
