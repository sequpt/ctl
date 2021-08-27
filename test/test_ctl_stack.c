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
#include "test_ctl_stack.h"
// C Standard Library
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h> // malloc(), free(), NULL
// CPL
#include <ctl.h>
#include <ctl_stack.h>
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CTL_STACK_TYPES int, char, float
CTL_DECLARE(CTL_STACK, CTL_STACK_TYPES);
CTL_DEFINE(CTL_STACK, CTL_STACK_TYPES)

#define CREATE(adt)                                                            \
    CTL_STACK(int) * (adt) = malloc(sizeof(*(adt)));                           \
    assert((adt) != NULL);                                                     \
    (adt)->start = (adt)->end = (adt)->back = NULL

#define DESTROY(adt)                                                           \
    free((adt)->start);                                                        \
    free(adt);                                                                 \
    (adt) = NULL

#define RESERVE(adt, cnt)                                                      \
    adt->start = malloc(sizeof(*(adt)->start) * (cnt));                        \
    assert((adt)->start != NULL);                                              \
    (adt)->back = (adt)->start;                                                \
    (adt)->end = (adt)->start + (cnt)

#define CLEAR(adt)                                                             \
    free((adt)->start);                                                        \
    (adt)->start = (adt)->end = (adt)->back = NULL
/*==============================================================================
    FUNCTION DECLARATION
==============================================================================*/
void TEST_ctl_Stack_Create(void);
void TEST_ctl_Stack_Destroy(void);
void TEST_ctl_Stack_Size(void);
void TEST_ctl_Stack_Capacity(void);
void TEST_ctl_Stack_IsEmpty(void);
void TEST_ctl_Stack_Reserve(void);
void TEST_ctl_Stack_Clear(void);
void TEST_ctl_Stack_At(void);
void TEST_ctl_Stack_Top(void);
void TEST_ctl_Stack_Push(void);
void TEST_ctl_Stack_Pop(void);
void TEST_ctl_Stack_Resize(void);
void TEST_ctl_Stack_ShrinkToFit(void);
/*==============================================================================
    FUNCTION DEFINITION
==============================================================================*/
/*------------------------------------------------------------------------------
    TEST_CTL_STACK()
------------------------------------------------------------------------------*/
void TEST_CTL_STACK(void)
{
    TEST_ctl_Stack_Create();
    TEST_ctl_Stack_Destroy();
    TEST_ctl_Stack_Size();
    TEST_ctl_Stack_Capacity();
    TEST_ctl_Stack_IsEmpty();
    TEST_ctl_Stack_Reserve();
    TEST_ctl_Stack_Clear();
    TEST_ctl_Stack_At();
    TEST_ctl_Stack_Top();
    TEST_ctl_Stack_Push();
    TEST_ctl_Stack_Pop();
    TEST_ctl_Stack_Resize();
    TEST_ctl_Stack_ShrinkToFit();
}
void TEST_ctl_Stack_Create(void)
{
    CTL_STACK(int) * adt = ctl_Stack_Create(adt);
    assert(adt != NULL);
    assert(adt->start == adt->end);
    assert(adt->start == adt->back);
    DESTROY(adt);
}
void TEST_ctl_Stack_Destroy(void)
{
    CREATE(adt);
    ctl_Stack_Destroy(adt);
    assert(adt == NULL);
}
void TEST_ctl_Stack_Size(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    assert(ctl_Stack_Size(adt) == 0);
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_Size(adt) == i);
        adt->back++;
    }
    DESTROY(adt);
}
void TEST_ctl_Stack_Capacity(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    // Initial state
    assert(ctl_Stack_Capacity(adt) == 0);
    // Reserve `obj_cnt`
    RESERVE(adt, obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // Add `obj_cnt` objects
    adt->back += obj_cnt;
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // Remove objects
    CLEAR(adt);
    assert(ctl_Stack_Capacity(adt) == 0);
    DESTROY(adt);
}
void TEST_ctl_Stack_IsEmpty(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    // Initial state
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Add `obj_cnt` objects
    RESERVE(adt, obj_cnt);
    adt->back += obj_cnt;
    assert(ctl_Stack_IsEmpty(adt) == false);
    // Remove objects
    CLEAR(adt);
    assert(ctl_Stack_IsEmpty(adt) == true);
    DESTROY(adt);
}
void TEST_ctl_Stack_Reserve(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    // Initial state
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Reserve 0
    ctl_Stack_Reserve(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Reserve `obj_cnt`
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Reserve `obj_cnt` again
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Reserve `obj_cnt` * 2
    ctl_Stack_Reserve(adt, obj_cnt * 2);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt * 2);
    assert(ctl_Stack_IsEmpty(adt) == true);
    DESTROY(adt);
}
void TEST_ctl_Stack_Clear(void)
{
    size_t obj_cnt = 5;
    CREATE(adt);
    // Initial state
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // Add `obj_cnt` objects
    RESERVE(adt, obj_cnt);
    adt->back += obj_cnt;
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == false);
    // Remove objects
    ctl_Stack_Clear(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == true);
    DESTROY(adt);
}
void TEST_ctl_Stack_At(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        *adt->back++ = (int)i;
        assert(ctl_Stack_At(adt, i) == (int)i);
    }
    DESTROY(adt);
}
void TEST_ctl_Stack_Top(void)
{
    const size_t obj_cnt = 5;
    CREATE(adt);
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        *adt->back++ = (int)i;
        assert(ctl_Stack_Back(adt) == (int)i);
    }
    DESTROY(adt);
}
void TEST_ctl_Stack_Push(void)
{
    const size_t obj_cnt = 50;
    // Capacity == 0
    CREATE(adt0);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt0, (int)i);
        assert(ctl_Stack_Back(adt0) == (int)i);
        assert(ctl_Stack_At(adt0, i) == (int)i);
        assert(ctl_Stack_Size(adt0) == i + 1);
    }
    DESTROY(adt0);

    // Capacity < obj_cnt
    CREATE(adt1);
    RESERVE(adt1, (size_t)((float)obj_cnt * 0.5f));
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt1, (int)i);
        assert(ctl_Stack_Back(adt1) == (int)i);
        assert(ctl_Stack_At(adt1, i) == (int)i);
        assert(ctl_Stack_Size(adt1) == i + 1);
    }
    DESTROY(adt1);

    // Capacity == obj_cnt
    CREATE(adt2);
    RESERVE(adt2, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt2, (int)i);
        assert(ctl_Stack_Back(adt2) == (int)i);
        assert(ctl_Stack_At(adt2, i) == (int)i);
        assert(ctl_Stack_Size(adt2) == i + 1);
    }
    DESTROY(adt2);
}
void TEST_ctl_Stack_Pop(void)
{
    // Capacity == 0
    CREATE(adt);
    const size_t obj_cnt = 50;
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt, (int)i);
        assert(ctl_Stack_Size(adt) == 1);
        assert(ctl_Stack_Pop(adt) == (int)i);
        assert(ctl_Stack_Size(adt) == 0);
    }
    DESTROY(adt);
}
void TEST_ctl_Stack_Resize(void)
{
    CREATE(adt0);
    size_t obj_cnt = 10;
    // Initial state
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt0, (int)i);
    }
    const size_t capacity = ctl_Stack_Capacity(adt0);
    // new size > current size
    ctl_Stack_Resize(adt0, 50);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_At(adt0, i) == (int)i);
    }
    const size_t new_capacity = ctl_Stack_Capacity(adt0);
    assert(new_capacity > capacity);
    // new size < current size
    obj_cnt = 5;
    ctl_Stack_Resize(adt0, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_At(adt0, i) == (int)i);
    }
    assert(ctl_Stack_Size(adt0) == obj_cnt);
    assert(new_capacity == ctl_Stack_Capacity(adt0));
    // new size == current size
    ctl_Stack_Resize(adt0, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_At(adt0, i) == (int)i);
    }
    assert(ctl_Stack_Size(adt0) == obj_cnt);
    assert(new_capacity == ctl_Stack_Capacity(adt0));
    DESTROY(adt0);
}
void TEST_ctl_Stack_ShrinkToFit(void)
{
    CREATE(adt0);
    // 0 == size == capacity
    size_t obj_cnt = 0;
    ctl_Stack_ShrinkToFit(adt0);
    assert(ctl_Stack_Size(adt0) == obj_cnt);
    assert(ctl_Stack_Capacity(adt0) == obj_cnt);
    // 0 < size == capacity
    obj_cnt = 10;
    ctl_Stack_Reserve(adt0, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt0, (int)i);
    }
    ctl_Stack_ShrinkToFit(adt0);
    assert(ctl_Stack_Size(adt0) == obj_cnt);
    assert(ctl_Stack_Capacity(adt0) == obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_At(adt0, i) == (int)i);
    }
    // 0 < size < capacity
    ctl_Stack_Reserve(adt0, obj_cnt * 2);
    ctl_Stack_ShrinkToFit(adt0);
    assert(ctl_Stack_Size(adt0) == obj_cnt);
    assert(ctl_Stack_Capacity(adt0) == obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_At(adt0, i) == (int)i);
    }
    DESTROY(adt0);
}
