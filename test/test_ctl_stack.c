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

#define GROWTH_FACTOR 1.5

#define CREATE(adt, T)                                                         \
    CTL_STACK(T) * (adt) = malloc(sizeof(*(adt)));                             \
    assert((adt) != NULL);                                                     \
    (adt)->start = (adt)->end = (adt)->back = NULL

#define DESTROY(adt)                                                           \
    free((adt)->start);                                                        \
    free(adt);                                                                 \
    (adt) = NULL

#define RESERVE(adt, cnt)                                                      \
    RESET(adt);                                                                \
    (adt)->start = calloc((cnt), sizeof(*((adt)->start)));                     \
    assert((adt)->start != NULL);                                              \
    (adt)->back = (adt)->start;                                                \
    (adt)->end = (adt)->start + (cnt)

#define CLEAR(adt)                                                             \
    (adt)->end = (adt)->back = (adt)->start

#define RESET(adt)                                                             \
    free((adt)->start);                                                        \
    (adt)->start = (adt)->back = (adt)->end = NULL

#define MOVE_BACK(adt, n)                                                      \
    (adt)->back += (n)

#define SET_BACK(adt, x)                                                       \
    *((adt)->back-1) = (x)

#define BACK(adt)                                                              \
    *((adt)->back-1)

#define PUSH_BACK(adt, x)                                                      \
    *((adt)->back)++ = x

#define START(adt)                                                             \
    *((adt)->start)

#define SET_AT(adt, n, x)                                                      \
    *((adt)->start + (n)) = (x)

#define AT(adt, n)                                                             \
    *((adt)->start + (n))
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
    printf("%s:\n", __func__);
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
    printf("%s: OK\n", __func__);
}
void TEST_ctl_Stack_Create(void)
{
    CTL_STACK(int) * adt = ctl_Stack_Create(adt);
    assert(adt != NULL);
    assert(adt->start == adt->end);
    assert(adt->start == adt->back);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Destroy(void)
{
    CREATE(adt, int);
    ctl_Stack_Destroy(adt);
    assert(adt == NULL);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Size(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    // start = back = end
    assert(ctl_Stack_Size(adt) == 0);
    // start = back < end
    RESERVE(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    // start < back < end
    for(size_t i = 0; i < obj_cnt; i++) {
        assert(ctl_Stack_Size(adt) == i);
        MOVE_BACK(adt, 1);
    }
    // start < back = end
    assert(ctl_Stack_Size(adt) == obj_cnt);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Capacity(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    // 0 = size = capacity
    assert(ctl_Stack_Capacity(adt) == 0);
    // 0 = size < capacity
    RESERVE(adt, obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_IsEmpty(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    // start = back = end
    assert(ctl_Stack_IsEmpty(adt) == true);
    // start = back < end
    RESERVE(adt, obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == true);
    // start < back < end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    assert(ctl_Stack_IsEmpty(adt) == false);
    // start < back = end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    assert(ctl_Stack_IsEmpty(adt) == false);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Reserve(void)
{
    const size_t obj_cnt = 20;
    const int back_data = 0xCAFE;
    CREATE(adt, int);
    // 0 = size = reserve = capacity
    ctl_Stack_Reserve(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    // 0 = size = reserve < capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Reserve(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size = capacity < reserve
    RESET(adt);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < reserve = capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < reserve < capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Reserve(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < capacity < reserve
    RESERVE(adt, obj_cnt/2);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = reserve < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, 0);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 = reserve < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, 0);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size = reserve = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size = reserve < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size = capacity < reserve
    RESERVE(adt, obj_cnt/2);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size < reserve = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size < reserve < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/4);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/4);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size < capacity < reserve
    RESERVE(adt, obj_cnt/2);
    MOVE_BACK(adt, obj_cnt/4);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt/4);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < reserve < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < reserve < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Reserve(adt, obj_cnt/4);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Clear(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    // start = back = end
    ctl_Stack_Clear(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    // start = back < end
    RESERVE(adt, obj_cnt);
    ctl_Stack_Clear(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // start < back < end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    ctl_Stack_Clear(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // start < back = end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    ctl_Stack_Clear(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_At(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        PUSH_BACK(adt, (int)i);
        assert(ctl_Stack_At(adt, i) == (int)i);
    }
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Top(void)
{
    const size_t obj_cnt = 20;
    CREATE(adt, int);
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        PUSH_BACK(adt, (int)i);
        assert(ctl_Stack_Back(adt) == (int)i);
    }
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Push(void)
{
    const size_t obj_cnt = 20;
    const int back_data = 0xCAFE;
    CREATE(adt, int);
    // start = back = end
    ctl_Stack_Push(adt, back_data);
    assert(ctl_Stack_Size(adt) == 1);
    assert(ctl_Stack_Capacity(adt) == 1);
    assert(BACK(adt) == back_data);
    assert(START(adt) == back_data);
    // start = back < end
    RESERVE(adt, obj_cnt);
    ctl_Stack_Push(adt, back_data);
    assert(ctl_Stack_Size(adt) == 1);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    assert(START(adt) == back_data);
    // start < back < end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    ctl_Stack_Push(adt, back_data);
    assert(ctl_Stack_Size(adt) == (obj_cnt/2)+1);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // start < back = end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    ctl_Stack_Push(adt, back_data);
    assert(ctl_Stack_Size(adt) == obj_cnt+1);
    assert(ctl_Stack_Capacity(adt) == (size_t)(obj_cnt * GROWTH_FACTOR));
    assert(BACK(adt) == back_data);
    // all
    RESET(adt);
    for(size_t i = 0; i < obj_cnt; i++) {
        ctl_Stack_Push(adt, (int)i);
        assert(ctl_Stack_Size(adt) == i+1);
        assert(BACK(adt) == (int)i);
    }
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Pop(void)
{
    const size_t obj_cnt = 20;
    const int back_data = 0xCAFE;
    CREATE(adt, int);
    // start = back = end: error
    // start = back < end: error
    // start < start+1 = back < end
    RESERVE(adt, obj_cnt);
    PUSH_BACK(adt, back_data);
    assert(ctl_Stack_Pop(adt) == back_data);
    assert(ctl_Stack_Size(adt) == 0);
    // start < back < end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    assert(ctl_Stack_Pop(adt) == back_data);
    assert(ctl_Stack_Size(adt) == (obj_cnt/2)-1);
    // start < back = end
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    assert(ctl_Stack_Pop(adt) == back_data);
    assert(ctl_Stack_Size(adt) == obj_cnt-1);
    // all
    RESERVE(adt, obj_cnt);
    for(size_t i = 0; i < obj_cnt; i++) {
        PUSH_BACK(adt, (int)i);
    }
    for(size_t i = obj_cnt-1; i > 0; i--) {
        assert(ctl_Stack_Pop(adt) == (int)i);
        assert(ctl_Stack_Size(adt) == i);
    }
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_Resize(void)
{
    const size_t obj_cnt = 20;
    const int back_data = 0xCAFE;
    CREATE(adt, int);
    // 0 = size = resize = capacity
    ctl_Stack_Resize(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    // 0 = size = resize < capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Resize(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size = capacity < resize
    RESET(adt);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < resize = capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < resize < capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_Resize(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = size < capacity < resize
    RESERVE(adt, obj_cnt/2);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = resize < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    ctl_Stack_Resize(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 = resize < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    ctl_Stack_Resize(adt, 0);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    // 0 < size = resize = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size = resize < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size = capacity < resize
    RESERVE(adt, obj_cnt/2);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(AT(adt, (obj_cnt/2)-1) == back_data);
    // 0 < size < resize = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(AT(adt, (obj_cnt/2)-1) == back_data);
    // 0 < size < resize < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/4);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(AT(adt, (obj_cnt/4)-1) == back_data);
    // 0 < size < capacity < resize
    RESERVE(adt, obj_cnt/2);
    MOVE_BACK(adt, obj_cnt/4);
    SET_BACK(adt, back_data);
    ctl_Stack_Resize(adt, obj_cnt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(AT(adt, (obj_cnt/4)-1) == back_data);
    // 0 < resize < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_AT(adt, (obj_cnt/2)-1, back_data);
    ctl_Stack_Resize(adt, obj_cnt/2);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < resize < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_AT(adt, (obj_cnt/4)-1, back_data);
    ctl_Stack_Resize(adt, obj_cnt/4);
    assert(ctl_Stack_Size(adt) == obj_cnt/4);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
void TEST_ctl_Stack_ShrinkToFit(void)
{
    const size_t obj_cnt = 20;
    const int back_data = 0xCAFE;
    CREATE(adt, int);
    // 0 = size = capacity
    ctl_Stack_ShrinkToFit(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    // 0 = size < capacity
    RESERVE(adt, obj_cnt);
    ctl_Stack_ShrinkToFit(adt);
    assert(ctl_Stack_Size(adt) == 0);
    assert(ctl_Stack_Capacity(adt) == 0);
    // 0 < size = capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt);
    SET_BACK(adt, back_data);
    ctl_Stack_ShrinkToFit(adt);
    assert(ctl_Stack_Size(adt) == obj_cnt);
    assert(ctl_Stack_Capacity(adt) == obj_cnt);
    assert(BACK(adt) == back_data);
    // 0 < size < capacity
    RESERVE(adt, obj_cnt);
    MOVE_BACK(adt, obj_cnt/2);
    SET_BACK(adt, back_data);
    ctl_Stack_ShrinkToFit(adt);
    assert(ctl_Stack_Size(adt) == obj_cnt/2);
    assert(ctl_Stack_Capacity(adt) == obj_cnt/2);
    assert(BACK(adt) == back_data);
    DESTROY(adt);
    printf("\t%s: OK\n", __func__);
}
