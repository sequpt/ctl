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
 * Provides a straightforward stack data structure.
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CTL_STACK_H_20210825213605
#define CTL_STACK_H_20210825213605
/*==============================================================================
    INCLUDE
==============================================================================*/
// CTL
#include "impl/ctl_stack_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/*------------------------------------------------------------------------------
    CTL_STACK()
------------------------------------------------------------------------------*/
#define CTL_STACK(T)                                                           \
    CTL_STACK_IMPL(T)
/*------------------------------------------------------------------------------
    ctl_Stack_Create()
------------------------------------------------------------------------------*/
/**
 * Creates an empty \p{stack} with a capacity of 0.
 *
 * @param[in,out] stack : Pointer to the stack to allocate.
 *
 * @return
 * - @success: Pointer to the allocated \p{stack}.
 * - @failure: `NULL`
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 * }
 */
#define ctl_Stack_Create(stack)                                                \
    CTL_STACK_FUNC(stack, Create)()
/*------------------------------------------------------------------------------
    ctl_Stack_Destroy()
------------------------------------------------------------------------------*/
/**
 * Destroys a previously created \p{stack}.
 *
 * @param[in,out] stack : Pointer to the stack to destroy.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Destroy(stack);
 * }
 */
#define ctl_Stack_Destroy(stack)                                               \
    CTL_STACK_FUNC(stack, Destroy)(&stack)
/*------------------------------------------------------------------------------
    ctl_Stack_Size()
------------------------------------------------------------------------------*/
/**
 * Returns the number of elements in a \p{stack}.
 *
 * @param[in] stack : Pointer to the stack.
 *
 * @return The number of elements in \p{stack}.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  size_t size = ctl_Stack_Size(stack); // size = 0
 *  ctl_Stack_Push(stack, 7);
 *  size = ctl_Stack_Size(stack); // size = 1
 * }
 */
#define ctl_Stack_Size(stack)                                                  \
    CTL_STACK_FUNC(stack, Size)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_Capacity()
------------------------------------------------------------------------------*/
/**
 * Returns the capacity of a \p{stack}.
 *
 * The capcity is the number of elements for which a \p{stack} has allocated
 * space(which isn't necessarily the number of elements actually stored in the
 * stack).
 *
 * @param[in] stack : Pointer to the stack.
 *
 * @return The capacity.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  size_t capacity = ctl_Stack_Capacity(stack); // capacity = 0
 *  ctl_Stack_Reserve(stack, 1000);
 *  capacity = ctl_Stack_Capacity(stack); // capacity = 1000
 * }
 */
#define ctl_Stack_Capacity(stack)                                              \
    CTL_STACK_FUNC(stack, Capacity)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_IsEmpty()
------------------------------------------------------------------------------*/
/**
 * Returns whether a \p{stack} is empty or not.
 *
 * @param[in] stack : Pointer to the stack.
 *
 * @return
 * - `true` if the \p{stack} is empty.
 * - `false if the \p{stack} isn't empty.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  _Boo is_empty = ctl_Stack_IsEmpty(stack); // is_empty = true
 *  ctl_Stack_Push(stack, 7);
 *  is_empty = ctl_Stack_IsEmpty(stack); // is_empty = false
 * }
 */
#define ctl_Stack_IsEmpty(stack)                                               \
    CTL_STACK_FUNC(stack, IsEmpty)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_Reserve()
------------------------------------------------------------------------------*/
/**
 * Increases the capacity of a \p{stack} to a given amount.
 *
 * If the new \p{capacity} is lower or equal to the previous one, nothing
 * happens.
 *
 * @param[in,out] stack    : Pointer to the stack.
 * @param[in]     capacity : Capacity wanted.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 * - \p{capacity} must be an integer in the range `[0; SIZE_MAX]`.
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Reserve(stack, 1000);
 * }
 */
#define ctl_Stack_Reserve(stack, capacity)                                     \
    CTL_STACK_FUNC(stack, Reserve)(stack, capacity)
/*------------------------------------------------------------------------------
    ctl_Stack_Clear()
------------------------------------------------------------------------------*/
/**
 * Removes all elements from a \p{stack}.
 *
 * After a call to ctl_Stack_Clear(), the size of the stack will be 0 and the
 * capacity will stay unchanged.
 *
 * @param[in,out] stack : Pointer to the stack.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);
 *  ctl_Stack_Push(stack, 13);
 *  size_t size = ctl_Stack_Size(stack); // size = 2
 *  size_t capacity = ctl_Stack_Capacity(stack); // capacity = 2
 *  ctl_Stack_Clear(stack);
 *  size = ctl_Stack_Size(stack); // size = 0
 *  capacity = ctl_Stack_Capacity(stack); // capacity = 2
 * }
 */
#define ctl_Stack_Clear(stack)                                                 \
    CTL_STACK_FUNC(stack, Clear)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_At()
------------------------------------------------------------------------------*/
/**
 * Return the element at the specified \p{index}.
 *
 * @param[in] stack : Pointer to the stack.
 * @param[in] index : Index of the element.
 *
 * @return The element at the specified \p{index}.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 * - ctl_Stack_Size() must be > 0.
 * - \p{index} must be an integer in the range `[0; ctl_Stack_Size() - 1]`.
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);
 *  ctl_Stack_Push(stack, 13);
 *  int x = ctl_Stack_At(stack, 0); // x = 7
 *  int y = ctl_Stack_At(stack, 1); // y = 13
 * }
 */
#define ctl_Stack_At(stack, index)                                             \
    CTL_STACK_FUNC(stack, At)(stack, index)
/*------------------------------------------------------------------------------
    ctl_Stack_Top()
------------------------------------------------------------------------------*/
/**
 * Returns the last element in a \p{stack}.
 *
 * @param[in] stack : Pointer to the stack.
 *
 * @return The last element in \p{stack}.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 * - ctl_Stack_Size() must be > 0.
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);
 *  ctl_Stack_Push(stack, 13);
 *  int x = ctl_Stack_Top(stack); // x = 13
 * }
 */
#define ctl_Stack_Back(stack)                                                  \
    CTL_STACK_FUNC(stack, Back)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_Push()
------------------------------------------------------------------------------*/
/**
 * Inserts \p{data} at the end of a \p{stack}.
 *
 * @param[in,out] stack : Pointer to the stack.
 * @param[in]     data  : Element to insert.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);
 * }
 */
#define ctl_Stack_Push(stack, data)                                            \
    CTL_STACK_FUNC(stack, Push)(stack, data)
/*------------------------------------------------------------------------------
    ctl_Stack_Pop()
------------------------------------------------------------------------------*/
/**
 * Removes the last element from a \p{stack} and returns it.
 *
 * @param[in,out] stack : Pointer to the stack.
 *
 * @return The last element of \p{stack}.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 * - ctl_Stack_Size() must be > 0.
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);
 *  ctl_Stack_Push(stack, 13);
 *  int x = ctl_Stack_Pop(stack); // x = 13
 * }
 */
#define ctl_Stack_Pop(stack)                                                   \
    CTL_STACK_FUNC(stack, Pop)(stack)
/*------------------------------------------------------------------------------
    ctl_Stack_Resize()
------------------------------------------------------------------------------*/
/**
 * Resizes a \p{stack} to a given size.
 *
 * - The \p{stack} capacity is increased if \p{size} is greater than the current
 *   capacity.
 * - The \p{stack} is truncated to its first \p{size} elements if \p{size} is
 *   smaller than the current size. Capacity stays unchanged.
 * - Nothing happens if \p{size} is equal to the current size.
 *
 * @param[in,out] stack : Pointer to the stack.
 * @param[in]     size  : New size wanted.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 * - \p{size} must be an integer in the range `[0; SIZE_MAX]`.
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Push(stack, 7);    // size = 1 , capacity = 1
 *  ctl_Stack_Resize(stack, 10); // size = 10, capacity = 10
 *  ctl_Stack_Resize(stack, 3);  // size = 3 , capacity = 10
 * }
 */
#define ctl_Stack_Resize(stack, size) \
    CTL_STACK_FUNC(stack, Resize)(stack, size)
/*------------------------------------------------------------------------------
    ctl_Stack_ShrinkToFit()
------------------------------------------------------------------------------*/
/**
 * Shrinks a \p{stack} capacity to its size.
 *
 * @param[in,out] stack : Pointer to the stack.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{stack} must be a valid pointer to a stack created with
 *   ctl_Stack_Create().
 *
 * @example{
 *  CTL_STACK(int) * stack = ctl_Stack_Create(stack);
 *  ctl_Stack_Resize(stack, 5);   // size = 5, capacity = 5
 *  ctl_Stack_Reserve(stack, 10); // size = 5, capacity = 10
 *  ctl_Stack_ShrinkToFit(stack); // size = 5, capacity = 5
 * }
 */
#define ctl_Stack_ShrinkToFit(stack) \
    CTL_STACK_FUNC(stack, ShrinkToFit)(stack)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_STACK_H_20210825213605
