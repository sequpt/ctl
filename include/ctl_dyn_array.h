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
#ifndef CTL_DYN_ARRAY_H_20190803223853
#define CTL_DYN_ARRAY_H_20190803223853
/*==============================================================================
    INCLUDE
==============================================================================*/
// CTL
#include "impl/ctl_dyn_array_impl.h"
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/*------------------------------------------------------------------------------
    CTL_DYN_ARRAY()
------------------------------------------------------------------------------*/
#define CTL_DYN_ARRAY(T)                                                       \
    CTL_DYN_ARRAY_IMPL(T)
/*------------------------------------------------------------------------------
    ctl_DynArray_Create()
------------------------------------------------------------------------------*/
/**
 * Creates an empty \p{array} with a capacity of 0.
 *
 * @param[in,out] array : Pointer to the array to allocate.
 *
 * @return
 * - @success: Pointer to the allocated \p{array}.
 * - @failure: `NULL`
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 * }
 */
#define ctl_DynArray_Create(array)                                             \
    CTL_DYN_ARRAY_FUNC(array, Create)()
/*------------------------------------------------------------------------------
    ctl_DynArray_Destroy()
------------------------------------------------------------------------------*/
/**
 * Destroys a previously created \p{array}.
 *
 * @param[in,out] array : Pointer to the array to destroy.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_Destroy(array);
 * }
 */
#define ctl_DynArray_Destroy(array)                                            \
    CTL_DYN_ARRAY_FUNC(array, Destroy)(&array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Reserve()
------------------------------------------------------------------------------*/
/**
 * Increases the capacity of an \p{array} to a given amount.
 *
 * If the new \p{capacity} is lower or equal to the previous one, nothing
 * happens.
 *
 * @param[in,out] array    : Pointer to the array.
 * @param[in]     capacity : Capacity wanted.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - \p{capacity} must be an integer in the range `[0; SIZE_MAX]`.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_Reserve(array, 1000);
 * }
 */
#define ctl_DynArray_Reserve(array, capacity)                                  \
    CTL_DYN_ARRAY_FUNC(array, Reserve)(array, capacity)
/*------------------------------------------------------------------------------
    ctl_DynArray_Insert()
------------------------------------------------------------------------------*/
/**
 * Inserts \p{data} at the specified \p{index} of an \p{array}.
 *
 * @param[in,out] array : Pointer to the array.
 * @param[in]     index : Index at which to insert the element.
 * @param[in]     data  : Element to insert.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - \p{index} must be an integer in the range `[0; ctl_DynArray_Size()]`.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_Insert(array, 0, 7);
 * }
 */
#define ctl_DynArray_Insert(array, index, data)                                \
    CTL_DYN_ARRAY_FUNC(array, Insert)(array, index, data)
/*------------------------------------------------------------------------------
    ctl_DynArray_PushFront()
------------------------------------------------------------------------------*/
/**
 * Inserts \p{data} at the beginning of an \p{array}.
 *
 * @param[in,out] array : Pointer to the array.
 * @param[in]     data  : Element to insert.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushFront(array, 7);
 * }
 */
#define ctl_DynArray_PushFront(array, data)                                    \
    CTL_DYN_ARRAY_FUNC(array, PushFront)(array, data)
/*------------------------------------------------------------------------------
    ctl_DynArray_PushBack()
------------------------------------------------------------------------------*/
/**
 * Inserts \p{data} at the end of an \p{array}.
 *
 * @param[in,out] array : Pointer to the array.
 * @param[in]     data  : Element to insert.
 *
 * @return
 * - @success: `true`
 * - @failure: `false`
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 * }
 */
#define ctl_DynArray_PushBack(array, data)                                     \
    CTL_DYN_ARRAY_FUNC(array, PushBack)(array, data)
/*------------------------------------------------------------------------------
    ctl_DynArray_PopFront()
------------------------------------------------------------------------------*/
/**
 * Removes the first element from an \p{array} and returns it.
 *
 * @param[in,out] array : Pointer to the array.
 *
 * @return The first element of \p{array}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  int x = ctl_DynArray_PopFront(array); // x = 7
 * }
 */
#define ctl_DynArray_PopFront(array)                                           \
    CTL_DYN_ARRAY_FUNC(array, PopFront)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_PopBack()
------------------------------------------------------------------------------*/
/**
 * Removes the last element from an \p{array} and returns it.
 *
 * @param[in,out] array : Pointer to the array.
 *
 * @return The last element of \p{array}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  int x = ctl_DynArray_PopBack(array); // x = 13
 * }
 */
#define ctl_DynArray_PopBack(array)                                            \
    CTL_DYN_ARRAY_FUNC(array, PopBack)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_At()
------------------------------------------------------------------------------*/
/**
 * Return the element at the specified \p{index}.
 *
 * @param[in] array : Pointer to the array.
 * @param[in] index : Index of the element.
 *
 * @return The element at the specified \p{index}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 * - \p{index} must be an integer in the range `[0; ctl_DynArray_Size() - 1]`.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  int x = ctl_DynArray_At(array, 0); // x = 7
 *  x = ctl_DynArray_At(array, 1); // x = 13
 * }
 */
#define ctl_DynArray_At(array, index)                                          \
    CTL_DYN_ARRAY_FUNC(array, At)(array, index)
/*------------------------------------------------------------------------------
    ctl_DynArray_Front()
------------------------------------------------------------------------------*/
/**
 * Returns the first element in an \p{array}.
 *
 * @param[in] array : Pointer to the array.
 *
 * @return The first element in \p{array}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  int x = ctl_DynArray_Front(array); // x = 7
 * }
 */
#define ctl_DynArray_Front(array)                                              \
    CTL_DYN_ARRAY_FUNC(array, Front)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Back()
------------------------------------------------------------------------------*/
/**
 * Returns the last element in an \p{array}.
 *
 * @param[in] array : Pointer to the array.
 *
 * @return The last element in \p{array}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  int x = ctl_DynArray_Back(array); // x = 13
 * }
 */
#define ctl_DynArray_Back(array)                                               \
    CTL_DYN_ARRAY_FUNC(array, Back)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Size()
------------------------------------------------------------------------------*/
/**
 * Returns the number of elements in an \p{array}.
 *
 * @param[in] array : Pointer to the array.
 *
 * @return The number of elements in \p{array}.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  size_t size = ctl_DynArray_Size(array); // size = 0
 *  ctl_DynArray_PushBack(array, 7);
 *  size = ctl_DynArray_Size(array); // size = 1
 * }
 */
#define ctl_DynArray_Size(array)                                               \
    CTL_DYN_ARRAY_FUNC(array, Size)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Capacity()
------------------------------------------------------------------------------*/
/**
 * Returns the capacity of an \p{array}.
 *
 * The capcity is the number of elements for which an \p{array} has allocated
 * space(which isn't necessarily the number of elements actually stored in the
 * array).
 *
 * @param[in] array : Pointer to the array.
 *
 * @return The capacity.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  size_t capacity = ctl_DynArray_Capacity(array); // capacity = 0
 *  ctl_DynArray_Reserve(array, 1000);
 *  capacity = ctl_DynArray_Capacity(array); // capacity = 1000
 * }
 */
#define ctl_DynArray_Capacity(array)                                           \
    CTL_DYN_ARRAY_FUNC(array, Capacity)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_IsEmpty()
------------------------------------------------------------------------------*/
/**
 * Returns whether an \p{array} is empty or not.
 *
 * @param[in] array : Pointer to the array.
 *
 * @return
 * - `true` if the \p{array} is empty.
 * - `false if the \p{array} isn't empty.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  _Boo is_empty = ctl_DynArray_IsEmpty(array); // is_empty = true
 *  ctl_DynArray_PushBack(array, 7);
 *  is_empty = ctl_DynArray_IsEmpty(array); // is_empty = false
 * }
 */
#define ctl_DynArray_IsEmpty(array)                                            \
    CTL_DYN_ARRAY_FUNC(array, IsEmpty)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Clear()
------------------------------------------------------------------------------*/
/**
 * Removes all elements from an \p{array}.
 *
 * After a call to ctl_DynArray_Clear(), the size of the array will be 0 and the
 * capacity will stay unchanged.
 *
 * @param[in,out] array : Pointer to the array.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);
 *  ctl_DynArray_PushBack(array, 13);
 *  size_t size = ctl_DynArray_Size(array); // size = 2
 *  size_t capacity = ctl_DynArray_Capacity(array); // capacity = 2
 *  ctl_DynArray_Clear(array);
 *  size = ctl_DynArray_Size(array); // size = 0
 *  capacity = ctl_DynArray_Capacity(array); // capacity = 2
 * }
 */
#define ctl_DynArray_Clear(array)                                              \
    CTL_DYN_ARRAY_FUNC(array, Clear)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Resize()
------------------------------------------------------------------------------*/
/**
 * Resizes an \p{array} to a given size.
 *
 * - The \p{array} capacity is increased if \p{size} is greater than the current
 *   capacity.
 * - The \p{array} is truncated to its first \p{size} elements if \p{size} is
 *   smaller than the current size. Capacity stays unchanged.
 * - Nothing happens if \p{size} is equal to the current size.
 *
 * @param[in,out] array : Pointer to the array.
 * @param[in]     size  : New size wanted.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - \p{size} must be an integer in the range `[0; SIZE_MAX]`.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7); // size = 1 , capacity = 1
 *  ctl_DynArray_Resize(array, 10);  // size = 10, capacity = 10
 *  ctl_DynArray_Resize(array, 3);   // size = 3 , capacity = 10
 * }
 */
#define ctl_DynArray_Resize(array, size) \
    CTL_DYN_ARRAY_FUNC(array, Resize)(array, size)
/*------------------------------------------------------------------------------
    ctl_DynArray_ShrinkToFit()
------------------------------------------------------------------------------*/
/**
 * Shrinks an \p{array} capacity to its size.
 *
 * @param[in,out] array : Pointer to the array.
 *
 * @return Nothing.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_Resize(array, 5);   // size = 5, capacity = 5
 *  ctl_DynArray_Reserve(array, 10); // size = 5, capacity = 10
 *  ctl_DynArray_ShrinkToFit(array); // size = 5, capacity = 5
 * }
 */
#define ctl_DynArray_ShrinkToFit(array) \
    CTL_DYN_ARRAY_FUNC(array, ShrinkToFit)(array)
/*------------------------------------------------------------------------------
    ctl_DynArray_Remove()
------------------------------------------------------------------------------*/
/**
 * Removes the element at the specified \p{index} of an \p{array}.
 *
 * @param[in,out] array : Pointer to the array.
 * @param[in]     index : Index of the element.
 *
 * @return The removed element.
 *
 * @warning
 * - \p{array} must be a valid pointer to an array created with
 * ctl_DynArray_Create().
 * - ctl_DynArray_Size() must be > 0.
 * - \p{index} must be an integer in the range `[0; ctl_DynArray_Size() - 1]`.
 *
 * @example{
 *  CTL_DYN_ARRAY(int) * array = ctl_DynArray_Create(array);
 *  ctl_DynArray_PushBack(array, 7);       // size = 1
 *  ctl_DynArray_PushBack(array, 13);      // size = 2
 *  ctl_DynArray_PushBack(array, 19);      // size = 3
 *  int x = ctl_DynArray_Remove(array, 1); // x = 13, size = 2
 *  int y = ctl_DynArray_Remove(array, 1); // y = 19, size = 1
 * }
 */
#define ctl_DynArray_Remove(array, index)                                      \
    CTL_DYN_ARRAY_FUNC(array, Remove)(array, index)
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CTL_DYN_ARRAY_H_20190803223853
