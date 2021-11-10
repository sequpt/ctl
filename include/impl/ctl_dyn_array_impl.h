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
 *    +-------+  |  start < back < end   |  insert front/middle: shift_right() -> back++
 *    |///|   |  |  0 < size < capacity  |  insert back        : back++
 *    +-------+  |                       |  remove front/middle: shift_left() -> back--
 *               |                       |  remove back        : back--
 * 2)
 *    +-------+  |  start < back = end   |  insert front/middle: grow() -> shift_right() -> back++
 *    |///////|  |  0 < size = capacity  |  insert back        : grow() -> back++
 *    +-------+  |                       |  remove front/middle: shift_left() -> back--
 *               |                       |  remove back        : back--
 * 3)
 *    +-------+  |  start = back < end   |  insert front/middle/back: back++
 *    ||      |  |  0 = size < capacity  |  remove front/middle/back: error
 *    +-------+  |                       |
 *               |                       |
 * 4)
 *    +          |  start = back = end   |  insert front/middle/back: grow() -> back++
 *    |          |  0 = size = capacity  |  remove front/middle/back: error
 *    +          |                       |
 *               |                       |
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
#ifndef CTL_DYN_ARRAY_IMPL_H_20190805124350
#define CTL_DYN_ARRAY_IMPL_H_20190805124350
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
#define CTL_DYN_ARRAY_IMPL(T) ctl_dyn_array_##T

#define CTL_DYN_ARRAY_LOWER ctl_dyn_array

#define CTL_DYN_ARRAY_FUNC(OBJ, FUNC)                                          \
    CTL_GENERIC_FUNC(OBJ, CTL_DYN_ARRAY_LOWER, FUNC, CTL_DYN_ARRAY_TYPES)

#define CTL_DYN_ARRAY_STRUCT_CONTENT(T)                                        \
    T * start;                                                                 \
    T * back;                                                                  \
    T * end;

#define CTL_DYN_ARRAY_DECLARE_FUNC(ADT, T)                                     \
    ADT * ADT##_Create(void);                                                  \
    ADT * ADT##_CreateAndReserve(size_t capacity);                             \
    void ADT##_Destroy(ADT ** adt);                                            \
    _Bool ADT##_Reserve(ADT * adt, size_t capacity);                           \
    void ADT##_Insert(ADT * adt, size_t index, T data);                        \
    void ADT##_PushBack(ADT * adt, T data);                                    \
    T ADT##_PopBack(ADT * adt);                                                \
    T ADT##_At(const ADT * adt, size_t index);                                 \
    T ADT##_Front(ADT * adt);                                                  \
    T ADT##_Back(ADT * adt);                                                   \
    size_t ADT##_Size(const ADT * adt);                                        \
    size_t ADT##_Capacity(const ADT * adt);                                    \
    _Bool ADT##_IsEmpty(const ADT * adt);                                      \
    void ADT##_Clear(ADT * adt);                                               \
    T ADT##_Remove(ADT * adt, size_t index);                                   \
    void ADT##_ShrinkToFit(ADT * adt);                                         \
    void ADT##_Resize(ADT * adt, size_t size)

#define CTL_DYN_ARRAY_DEFINE_FUNC(ADT, T)                                      \
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
        adt->start = NULL;                                                     \
        adt->end   = NULL;                                                     \
        adt->back  = NULL;                                                     \
    } else {                                                                   \
        fprintf(stderr, "malloc() failed! %s\n", strerror(errno));             \
    }                                                                          \
    return adt;                                                                \
}                                                                              \
ADT * ADT##_CreateAndReserve(size_t capacity)                                  \
{                                                                              \
    ADT * adt = ADT##_Create();                                                \
    if(adt != NULL && capacity > 0 && !ADT##_Reserve(adt, capacity)) {         \
        free(adt);                                                             \
        return NULL;                                                           \
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
void ADT##_Insert(ADT * const adt, const size_t index, T data)                 \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t size = ADT##_Size(adt);                                       \
    assert(index <= size);                                                     \
    /* Array is full {2, 4} */                                                 \
    if(adt->back == adt->end) {                                                \
        ADT##_grow(adt);                                                       \
    }                                                                          \
    /* Insert front/middle */                                                  \
    if(index < size) {                                                         \
        /* Shift array to the right */                                         \
        T * const dest = adt->start + index + 1;                               \
        const T * const src = dest - 1;                                        \
        memmove(dest, src, sizeof(T) * (size - index));                        \
        adt->back++;                                                           \
        *(adt->start + index) = data;                                          \
    /* Insert back */                                                          \
    } else {                                                                   \
        *adt->back++ = data;                                                   \
    }                                                                          \
}                                                                              \
void ADT##_PushBack(ADT * const adt, T data)                                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    /* Array is full {2, 4} */                                                 \
    if((adt->back == adt->end)) {                                              \
        ADT##_grow(adt);                                                       \
    }                                                                          \
    *adt->back++ = data;                                                       \
}                                                                              \
T ADT##_PopBack(ADT * const adt)                                               \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    assert(adt->start < adt->back);                                            \
    return *--adt->back;                                                       \
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
T ADT##_Front(ADT * const adt)                                                 \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    return *adt->start;                                                        \
}                                                                              \
T ADT##_Back(ADT * const adt)                                                  \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->back != NULL);                                                 \
    assert(adt->start < adt->back);                                            \
    return *(adt->back - 1);                                                   \
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
void ADT##_Clear(ADT * const adt)                                              \
{                                                                              \
    assert(adt != NULL);                                                       \
    adt->back = adt->start;                                                    \
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
    if(size != 0) {                                                            \
        if(size != ADT##_Capacity(adt)) {                                      \
            T * const start = realloc(adt->start, sizeof(T) * size);           \
            if(start != NULL) {                                                \
                adt->start = start;                                            \
                adt->end = adt->back = start + size;                           \
            } else {                                                           \
                fprintf(stderr, "realloc() failed! %s\n", strerror(errno));    \
            }                                                                  \
        }                                                                      \
    } else {                                                                   \
        free(adt->start);                                                      \
        adt->start = adt->back = adt->end = NULL;                              \
    }                                                                          \
}                                                                              \
T ADT##_Remove(ADT * const adt, const size_t index)                            \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t size = ADT##_Size(adt);                                       \
    assert(index < size);                                                      \
    /* Remove front/middle */                                                  \
    if(index < size-1) {                                                       \
        /* Shift array to the left */                                          \
        T * const dest = adt->start + index;                                   \
        const T * const src = dest + 1;                                        \
        const T data = *dest;                                                  \
        memmove(dest, src, sizeof(T) * (size-index-1));                        \
        adt->back--;                                                           \
        return data;                                                           \
    }                                                                          \
    /* Remove back */                                                          \
    return *--adt->back;                                                       \
}
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_DYN_ARRAY_IMPL_H_20190805124350
