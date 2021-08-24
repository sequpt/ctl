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
    INCLUDE
==============================================================================*/
// Own header
#include "test_ctl_dyn_array.h"
// C Standard Library
#include <assert.h>
#include <stdlib.h> // malloc(), free(), NULL
// CPL
#include <ctl.h>
#include <ctl_dyn_array.h>
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CTL_DYN_ARRAY_TYPES int, char, float
CTL_DECLARE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);
CTL_DEFINE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES)

#define CREATE(array)                                                          \
    CTL_DYN_ARRAY(int) * array = malloc(sizeof(*array));                       \
    assert(array != NULL);                                                     \
    array->front = NULL;                                                       \
    array->back  = NULL;                                                       \
    array->start = NULL;                                                       \
    array->end   = NULL

#define DESTROY(array)                                                         \
    free(array->start);                                                        \
    free(array);                                                               \
    array = NULL

#define RESERVE(array, cnt)                                                    \
    array->start = malloc(sizeof(*array->front) * (cnt));                      \
    assert(array->start != NULL);                                              \
    array->back = array->front = array->start;                                 \
    array->end                 = array->start + (cnt)

#define CLEAR(array)                                                           \
    free(array->start);                                                        \
    array->start = NULL;                                                       \
    array->end = array->back = array->front = array->start
/*==============================================================================
    FUNCTION DECLARATION
==============================================================================*/
void TEST_ctl_DynArray_Create(void);
void TEST_ctl_DynArray_Destroy(void);
void TEST_ctl_DynArray_Size(void);
void TEST_ctl_DynArray_Capacity(void);
void TEST_ctl_DynArray_IsEmpty(void);
void TEST_ctl_DynArray_Reserve(void);
void TEST_ctl_DynArray_Clear(void);
void TEST_ctl_DynArray_At(void);
void TEST_ctl_DynArray_Back(void);
void TEST_ctl_DynArray_PushBack(void);
void TEST_ctl_DynArray_PopBack(void);
void TEST_ctl_DynArray_Front(void);
void TEST_ctl_DynArray_PushFront(void);
void TEST_ctl_DynArray_PopFront(void);
void TEST_ctl_DynArray_Insert(void);
void TEST_ctl_DynArray_Resize(void);
/*==============================================================================
    FUNCTION DEFINITION
==============================================================================*/
/*------------------------------------------------------------------------------
    TEST_CTL_DYN_ARRAY()
------------------------------------------------------------------------------*/
void TEST_CTL_DYN_ARRAY(void)
{
    TEST_ctl_DynArray_Create();
    TEST_ctl_DynArray_Destroy();
    TEST_ctl_DynArray_Size();
    TEST_ctl_DynArray_Capacity();
    TEST_ctl_DynArray_IsEmpty();
    TEST_ctl_DynArray_Reserve();
    TEST_ctl_DynArray_Clear();
    TEST_ctl_DynArray_At();
    TEST_ctl_DynArray_Back();
    TEST_ctl_DynArray_PushBack();
    TEST_ctl_DynArray_PopBack();
    TEST_ctl_DynArray_Front();
    TEST_ctl_DynArray_PushFront();
    TEST_ctl_DynArray_PopFront();
    TEST_ctl_DynArray_Insert();
    TEST_ctl_DynArray_Resize();
}
/*==============================================================================
    FUNCTION DEFINITION
==============================================================================*/
void TEST_ctl_DynArray_Create(void)
{
    CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
    assert(array != NULL);
    assert(array->start == array->front);
    assert(array->start == array->back);
    assert(array->start == array->end);
    DESTROY(array);
}
void TEST_ctl_DynArray_Destroy(void)
{
    CREATE(array);
    ctl_DynArray_Destroy(array);
    assert(array == NULL);
}
void TEST_ctl_DynArray_Size(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    assert(ctl_DynArray_Size(array) == 0);
    RESERVE(array, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_DynArray_Size(array) == i);
        array->back++;
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_Capacity(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    // Initial state
    assert(ctl_DynArray_Capacity(array) == 0);
    // Reserve `obj_cnt`
    RESERVE(array, obj_cnt);
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    // Add `obj_cnt` objects
    array->back += obj_cnt;
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    // Remove objects
    CLEAR(array);
    assert(ctl_DynArray_Capacity(array) == 0);
    DESTROY(array);
}
void TEST_ctl_DynArray_IsEmpty(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    // Initial state
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Add `obj_cnt` objects
    RESERVE(array, obj_cnt);
    array->back += obj_cnt;
    assert(ctl_DynArray_IsEmpty(array) == false);
    // Remove objects
    CLEAR(array);
    assert(ctl_DynArray_IsEmpty(array) == true);
    DESTROY(array);
}
void TEST_ctl_DynArray_Reserve(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    // Initial state
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == 0);
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Reserve 0
    ctl_DynArray_Reserve(array, 0);
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == 0);
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Reserve `obj_cnt`
    ctl_DynArray_Reserve(array, obj_cnt);
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Reserve `obj_cnt` again
    ctl_DynArray_Reserve(array, obj_cnt);
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Reserve `obj_cnt` * 2
    ctl_DynArray_Reserve(array, obj_cnt * 2);
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == obj_cnt * 2);
    assert(ctl_DynArray_IsEmpty(array) == true);
    DESTROY(array);
}
void TEST_ctl_DynArray_Clear(void)
{
    size_t obj_cnt = 5;
    CREATE(array);
    // Initial state
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == 0);
    assert(ctl_DynArray_IsEmpty(array) == true);
    // Add `obj_cnt` objects
    RESERVE(array, obj_cnt);
    array->back += obj_cnt;
    assert(ctl_DynArray_Size(array) == obj_cnt);
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    assert(ctl_DynArray_IsEmpty(array) == false);
    // Remove objects
    ctl_DynArray_Clear(array);
    assert(ctl_DynArray_Size(array) == 0);
    assert(ctl_DynArray_Capacity(array) == obj_cnt);
    assert(ctl_DynArray_IsEmpty(array) == true);
    DESTROY(array);
}
void TEST_ctl_DynArray_At(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    RESERVE(array, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        *array->back++ = (int)i;
        assert(ctl_DynArray_At(array, i) == (int)i);
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_Back(void)
{
    const size_t obj_cnt = 5;
    CREATE(array);
    RESERVE(array, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        *array->back++ = (int)i;
        assert(ctl_DynArray_Back(array) == (int)i);
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_PushBack(void)
{
    const size_t obj_cnt = 50;
    // Capacity == 0
    CREATE(array0);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushBack(array0, (int)i);
        assert(ctl_DynArray_Back(array0) == (int)i);
        assert(ctl_DynArray_At(array0, i) == (int)i);
        assert(ctl_DynArray_Size(array0) == i + 1);
    }
    DESTROY(array0);

    // Capacity < obj_cnt
    CREATE(array1);
    RESERVE(array1, (size_t)((float)obj_cnt * 0.5f));
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushBack(array1, (int)i);
        assert(ctl_DynArray_Back(array1) == (int)i);
        assert(ctl_DynArray_At(array1, i) == (int)i);
        assert(ctl_DynArray_Size(array1) == i + 1);
    }
    DESTROY(array1);

    // Capacity == obj_cnt
    CREATE(array2);
    RESERVE(array2, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushBack(array2, (int)i);
        assert(ctl_DynArray_Back(array2) == (int)i);
        assert(ctl_DynArray_At(array2, i) == (int)i);
        assert(ctl_DynArray_Size(array2) == i + 1);
    }
    DESTROY(array2);
}
void TEST_ctl_DynArray_PopBack(void)
{
    // Capacity == 0
    CREATE(array);
    const size_t obj_cnt = 50;
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushBack(array, (int)i);
        assert(ctl_DynArray_Size(array) == 1);
        assert(ctl_DynArray_PopBack(array) == (int)i);
        assert(ctl_DynArray_Size(array) == 0);
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_Front(void)
{
    CREATE(array);
    const size_t obj_cnt = 5;
    RESERVE(array, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        *array->front = (int)i;
        array->back   = array->front + 1;
        assert(ctl_DynArray_Front(array) == (int)i);
        array->front++;
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_PushFront(void)
{
    const size_t obj_cnt = 50;
    // Capacity == 0
    CREATE(array0);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushFront(array0, (int)i);
        assert(ctl_DynArray_Front(array0) == (int)i);
        assert(ctl_DynArray_At(array0, 0) == (int)i);
        assert(ctl_DynArray_Size(array0) == i + 1);
    }
    DESTROY(array0);

    // Capacity < obj_cnt
    CREATE(array1);
    RESERVE(array1, (size_t)((float)obj_cnt * 0.5f));
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushFront(array1, (int)i);
        assert(ctl_DynArray_Front(array1) == (int)i);
        assert(ctl_DynArray_At(array1, 0) == (int)i);
        assert(ctl_DynArray_Size(array1) == i + 1);
    }
    DESTROY(array1);

    // Capacity == obj_cnt
    CREATE(array2);
    RESERVE(array2, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushFront(array2, (int)i);
        assert(ctl_DynArray_Front(array2) == (int)i);
        assert(ctl_DynArray_At(array2, 0) == (int)i);
        assert(ctl_DynArray_Size(array2) == i + 1);
    }
    DESTROY(array2);
}
void TEST_ctl_DynArray_PopFront(void)
{
    CREATE(array);
    const size_t obj_cnt = 50;
    RESERVE(array, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushFront(array, (int)i);
        assert(ctl_DynArray_Size(array) == 1);
        assert(ctl_DynArray_PopBack(array) == (int)i);
        assert(ctl_DynArray_Size(array) == 0);
    }
    DESTROY(array);
}
void TEST_ctl_DynArray_Insert(void)
{
    size_t obj_cnt = 50;
    // Insert front: capacity == 0
    CREATE(array0);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array0, 0, (int)i);
        assert(ctl_DynArray_Front(array0) == (int)i);
        assert(ctl_DynArray_At(array0, 0) == (int)i);
        assert(ctl_DynArray_Size(array0) == i + 1);
    }
    DESTROY(array0);

    // Insert front: capacity < obj_cnt
    CREATE(array1);
    RESERVE(array1, (size_t)((float)obj_cnt * 0.5f));
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array1, 0, (int)i);
        assert(ctl_DynArray_Front(array1) == (int)i);
        assert(ctl_DynArray_At(array1, 0) == (int)i);
        assert(ctl_DynArray_Size(array1) == i + 1);
    }
    DESTROY(array1);

    // Insert front: capacity == obj_cnt
    CREATE(array2);
    RESERVE(array2, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array2, 0, (int)i);
        assert(ctl_DynArray_Front(array2) == (int)i);
        assert(ctl_DynArray_At(array2, 0) == (int)i);
        assert(ctl_DynArray_Size(array2) == i + 1);
    }
    DESTROY(array2);

    // Insert back: capacity == 0
    CREATE(array3);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array3, i, (int)i);
        assert(ctl_DynArray_Back(array3) == (int)i);
        assert(ctl_DynArray_At(array3, i) == (int)i);
        assert(ctl_DynArray_Size(array3) == i + 1);
    }
    DESTROY(array3);

    // Insert back: capacity < obj_cnt
    CREATE(array4);
    RESERVE(array4, (size_t)((float)obj_cnt * 0.5f));
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array4, i, (int)i);
        assert(ctl_DynArray_Back(array4) == (int)i);
        assert(ctl_DynArray_At(array4, i) == (int)i);
        assert(ctl_DynArray_Size(array4) == i + 1);
    }
    DESTROY(array4);

    // Insert back: capacity == obj_cnt
    CREATE(array5);
    RESERVE(array5, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array5, i, (int)i);
        assert(ctl_DynArray_Back(array5) == (int)i);
        assert(ctl_DynArray_At(array5, i) == (int)i);
        assert(ctl_DynArray_Size(array5) == i + 1);
    }
    DESTROY(array5);

    // Insert middle: linear
    CREATE(array6);
    ctl_DynArray_Insert(array6, 0, (int)0);
    ctl_DynArray_Insert(array6, 0, (int)1);
    ctl_DynArray_Insert(array6, 0, (int)2);
    for(size_t i = 3; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array6, i - 2, (int)i);
        assert(ctl_DynArray_At(array6, i - 2) == (int)i);
        assert(ctl_DynArray_Size(array6) == i + 1);
    }
    DESTROY(array6);

    // Insert middle: random
    CREATE(array7);
    RESERVE(array7, obj_cnt);
    obj_cnt = 10000;
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array7, i, 1000);
    }
    srand(0);
    for(size_t i = 0; i < obj_cnt; i++) {
        const size_t n = ((size_t)rand() % (obj_cnt + i + 1)) + 1;
        ctl_DynArray_Insert(array7, n, (int)n);
        assert(ctl_DynArray_At(array7, n) == (int)n);
        assert(ctl_DynArray_Size(array7) == obj_cnt + i + 1);
    }
    DESTROY(array7);

    // Insert middle: fixed
    CREATE(array8);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array8, i, 1000);
    }
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_Insert(array8, 1, (int)i);
        assert(ctl_DynArray_At(array8, 1) == (int)i);
        assert(ctl_DynArray_Size(array8) == obj_cnt + i + 1);
    }
    DESTROY(array8);
}
void TEST_ctl_DynArray_Resize(void)
{
    CREATE(array0);
    size_t obj_cnt = 10;
    // Initial state
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_DynArray_PushBack(array0, (int)i);
    }
    const size_t capacity = ctl_DynArray_Capacity(array0);
    // new size > current size
    ctl_DynArray_Resize(array0, 50);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_DynArray_At(array0, i) == (int)i);
    }
    const size_t new_capacity = ctl_DynArray_Capacity(array0);
    assert(new_capacity > capacity);
    // new size < current size
    obj_cnt = 5;
    ctl_DynArray_Resize(array0, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_DynArray_At(array0, i) == (int)i);
    }
    assert(ctl_DynArray_Size(array0) == obj_cnt);
    assert(new_capacity == ctl_DynArray_Capacity(array0));
    // new size == current size
    ctl_DynArray_Resize(array0, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_DynArray_At(array0, i) == (int)i);
    }
    assert(ctl_DynArray_Size(array0) == obj_cnt);
    assert(new_capacity == ctl_DynArray_Capacity(array0));
    DESTROY(array0);
}
