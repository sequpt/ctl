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
 *    |  |//////|  |
 *    +------------+
 *       |<---->|
 *       | size |
 *       |      |
 *     front   back
 *
 * 1)
 *    +-------+   start = front < back < end    front : shift_right() + insert
 *    |///|   |   0 < size < capacity           middle: shift_right() + insert
 *    +-------+                                 back  : insert
 * 2)
 *    +-------+   start = front < back = end    grow() -> 1)
 *    |///////|   0 < size = capacity
 *    +-------+
 * 3)
 *    +-------+   start < front < back < end    front : insert
 *    | |///| |   0 < size < capacity           middle: shift_left() + insert
 *    +-------+                                 back  : insert
 * 4)
 *    +-------+   start < front < back = end    front : insert
 *    |   |///|   0 < size < capacity           middle: shift_left() + insert
 *    +-------+                                 back  : move_to_start() insert
 * 5)
 *    +-------+   start = front = back < end    insert
 *    ||      |   0 = size < capacity
 *    +-------+
 * 6)
 *    +-------+   start < front = back < end    start = front = back + insert
 *    |   |   |   0 = size < capacity
 *    +-------+
 * 7)
 *    +-------+   start < front = back = end    start = front = back + insert
 *    |      ||   0 = size < capacity
 *    +-------+
 * 8)
 *    +           start = front = back = end    alloc() + insert
 *    |           0 = size = capacity
 *    +
 *
 * size > 0       : {1, 2, 3, 4}          <=> front < back
 * size = 0       : {5, 6, 7, 8}          <=> front = back
 * size < capacity: {1, 3, 4, 5, 6, 7}    <=> start < front OR  back < end
 * size = capacity: {2, 8}                <=> start = front AND back = end
 * capacity > 0   : {1, 2, 3, 4, 5, 6, 7} <=> start < end
 * capacity = 0   : {8}                   <=> start = end
 * start < front  : {3, 4, 6, 7}
 * start = front  : {1, 2, 5, 8}
 * start < back   : {1, 2, 3, 4, 6, 7}    <=> size > 0 OR  start < front
 * start = back   : {5, 8}                <=> size = 0 AND start = front
 * front < end    : {1, 2, 3, 4, 5, 6}    <=> size > 0 OR  back  < end
 * front = end    : {7, 8}                <=> size = 0 AND back  = end
 * back < end     : {1, 3, 5, 6}
 * back = end     : {2, 4, 7, 8}
 * start = front AND front < back: {1, 2} <=> size > 0 AND start = front
 * front < back  AND back  < end : {1, 3} <=> size > 0 AND back  < end
 * start = front AND back  < end : {1, 5}
 * front < back  AND back  = end : {2, 4} <=> size > 0 AND back  = end
 * start = front AND back  = end : {2, 8} <=> size = capacity
 * start < front AND front < back: {3, 4} <=> size > 0 AND start < front
 * start < front AND back  < end : {3, 6} <=> size > 0 AND start < front
 * start < front AND back  = end : {4, 7}
 * front = back  AND back  < end : {5, 6} <=> size = 0 AND back  < end
 * start = front AND front = back: {5, 8} <=> size = 0 AND start = front
 * start < front AND front = back: {6, 7} <=> size = 0 AND start < front
 * front = back  AND back  = end : {7, 8} <=> front = end
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
    T * front;                                                                 \
    T * back;                                                                  \
    T * start;                                                                 \
    T * end;

#define CTL_DYN_ARRAY_DECLARE_FUNC(ADT, T)                                     \
    ADT * ADT##_Create(void);                                                  \
    ADT * ADT##_CreateAndReserve(size_t capacity);                             \
    void ADT##_Destroy(ADT ** adt);                                            \
    _Bool ADT##_Reserve(ADT * adt, size_t capacity);                           \
    void ADT##_Insert(ADT * adt, size_t index, T data);                        \
    void ADT##_PushFront(ADT * adt, T data);                                   \
    void ADT##_PushBack(ADT * adt, T data);                                    \
    T ADT##_PopFront(ADT * adt);                                               \
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
static void ADT##_move_to_start(ADT * const adt)                               \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
                                                                               \
    size_t size = (size_t)(adt->back - adt->front);                            \
    memcpy(adt->start, adt->front, size);                                      \
    adt->front = adt->start;                                                   \
    adt->back  = adt->start + size;                                            \
}                                                                              \
static void ADT##_shift_left(ADT * const adt, size_t index)                    \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->front > adt->start);                                           \
    assert(index < (size_t)(adt->back - adt->front));                          \
    adt->front--;                                                              \
    memmove(adt->front, adt->front + 1, sizeof(T) * (index + 1));              \
}                                                                              \
static void ADT##_shift_right(ADT * const adt, size_t index)                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->back < adt->end);                                              \
    const size_t size = (size_t)(adt->back - adt->front);                      \
    memmove(adt->front + index + 1, adt->front + index,                        \
        sizeof(T) * (size - index));                                           \
    adt->back++;                                                               \
}                                                                              \
ADT * ADT##_Create(void)                                                       \
{                                                                              \
    ADT * adt = malloc(sizeof(*adt));                                          \
    if(adt != NULL) {                                                          \
        adt->start = NULL;                                                     \
        adt->end   = NULL;                                                     \
        adt->front = NULL;                                                     \
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
            adt->front = start;                                                \
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
    /* Insert middle */                                                        \
    if(index > 0 && index < size) {                                            \
        if(adt->start == adt->front && adt->back == adt->end) {                \
            ADT##_grow(adt);                                                   \
        }                                                                      \
        if(adt->start == adt->front) {                                         \
            ADT##_shift_right(adt, index);                                     \
        } else {                                                               \
            ADT##_shift_left(adt, index);                                      \
        }                                                                      \
        *(adt->front + index) = data;                                          \
    /* Insert front */                                                         \
    } else if(index == 0) {                                                    \
        ADT##_PushFront(adt, data);                                            \
    /* Insert back */                                                          \
    } else {                                                                   \
        ADT##_PushBack(adt, data);                                             \
    }                                                                          \
}                                                                              \
void ADT##_PushFront(ADT * const adt, const T data)                            \
{                                                                              \
    assert(adt != NULL);                                                       \
    /* {3, 4, 6, 7} */                                                         \
    if(adt->start != adt->front) {                                             \
        *--adt->front = data;                                                  \
    /* {2, 8} */                                                               \
    } else if(adt->back == adt->end) {                                         \
        ADT##_grow(adt);                                                       \
        ADT##_shift_right(adt, 0);                                             \
        *adt->front = data;                                                    \
    /* {1, 5} */                                                               \
    } else {                                                                   \
        ADT##_shift_right(adt, 0);                                             \
        *adt->front = data;                                                    \
    }                                                                          \
}                                                                              \
void ADT##_PushBack(ADT * const adt, T data)                                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    /* {1, 3, 5, 6} */                                                         \
    if((adt->back != adt->end)) {                                              \
        *adt->back++ = data;                                                   \
    /* {2, 8} */                                                               \
    } else if(adt->start == adt->front) {                                      \
        ADT##_grow(adt);                                                       \
        *adt->back++ = data;                                                   \
    /* {4, 7} */                                                               \
    } else {                                                                   \
        ADT##_move_to_start(adt);                                              \
        *adt->back++ = data;                                                   \
    }                                                                          \
}                                                                              \
T ADT##_PopFront(ADT * const adt)                                              \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->front < adt->back);                                            \
    return *adt->front++;                                                      \
}                                                                              \
T ADT##_PopBack(ADT * const adt)                                               \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->front < adt->back);                                            \
    return *--adt->back;                                                       \
}                                                                              \
T ADT##_At(const ADT * const adt, const size_t index)                          \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(index < (size_t)(adt->back - adt->front));                          \
    return *(adt->front + index);                                              \
}                                                                              \
T ADT##_Front(ADT * const adt)                                                 \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->front < adt->back);                                            \
    return *adt->front;                                                        \
}                                                                              \
T ADT##_Back(ADT * const adt)                                                  \
{                                                                              \
    assert(adt != NULL);                                                       \
    assert(adt->start != NULL);                                                \
    assert(adt->end != NULL);                                                  \
    assert(adt->front != NULL);                                                \
    assert(adt->back != NULL);                                                 \
    assert(adt->front < adt->back);                                            \
    return *(adt->back - 1);                                                   \
}                                                                              \
size_t ADT##_Size(const ADT * const adt)                                       \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->front != adt->back) ? (size_t)(adt->back - adt->front) : 0;   \
}                                                                              \
size_t ADT##_Capacity(const ADT * const adt)                                   \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->start != adt->end) ? (size_t)(adt->end - adt->start) : 0;     \
}                                                                              \
_Bool ADT##_IsEmpty(const ADT * const adt)                                     \
{                                                                              \
    assert(adt != NULL);                                                       \
    return (adt->front == adt->back);                                          \
}                                                                              \
void ADT##_Clear(ADT * const adt)                                              \
{                                                                              \
    assert(adt != NULL);                                                       \
    adt->front = adt->start;                                                   \
    adt->back  = adt->start;                                                   \
}                                                                              \
void ADT##_Resize(ADT * const adt, const size_t size)                          \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t capacity = ADT##_Capacity(adt);                               \
    if(size > capacity) {                                                      \
        T * const start = realloc(adt->start, sizeof(T) * size);               \
        if(start != NULL) {                                                    \
            adt->start = adt->front = start;                                   \
            adt->end   = adt->back  = start + size;                            \
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
            adt->start = adt->front = start;                                   \
            adt->end   = adt->back  = start + size;                            \
        } else {                                                               \
            fprintf(stderr, "realloc() failed! %s\n", strerror(errno));        \
        }                                                                      \
    }                                                                          \
}                                                                              \
T ADT##_Remove(ADT * const adt, const size_t index)                            \
{                                                                              \
    assert(adt != NULL);                                                       \
    const size_t size = ADT##_Size(adt);                                       \
    assert(index < size);                                                      \
    /* Remove middle */                                                        \
    if(index > 0 && index < size-1) {                                          \
        const T data = *(adt->front + index);                                  \
        memmove(adt->front + index, adt->front + index + 1,                    \
            sizeof(T) * (size-index-1));                                       \
        adt->back--;                                                           \
        return data;                                                           \
    }                                                                          \
    /* Remove front */                                                         \
    if(index == 0) {                                                           \
        return *adt->front++;                                                  \
    }                                                                          \
    /* Remove back */                                                          \
    return *--adt->back;                                                       \
}
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_DYN_ARRAY_IMPL_H_20190805124350
