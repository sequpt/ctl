# Changelog

This file is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/) but
doesn't follow it to the letter.

This project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html),
which says in its summary:

    Given a version number MAJOR.MINOR.PATCH, increment the:
      1. MAJOR version when you make incompatible API changes,
      2. MINOR version when you add functionality in a backwards compatible manner, and
      3. PATCH version when you make backwards compatible bug fixes.

## [Unreleased]

## [0.3.0]

(2021-11-11)

### Removed

- `ctl_dyn_array.h`:
  - `ctl_DynArray_PushFront()`.
  - `ctl_DynArray_PopFront()`.

### Fixed

- Bug in `ctl_Stack_ShrinkToFit()` where `realloc(0)` was called.
- Bug in `ctl_DynArray_ShrinkToFit()` where `realloc(0)` was called.

## [0.2.0]

(2021-08-27)

### Added

- `ctl.h`:
  - `CTL_STACK` to `CTL_ADT_LIST()`.
- `ctl_stack.h`: a straightforward stack data structure.
  - `CTL_STACK()` to use as a stack type specifier.
  - `ctl_Stack_Create()` to create a stack.
  - `ctl_Stack_Destroy()` to destroy a stack.
  - `ctl_Stack_Reserve()` to increase the capacity.
  - `ctl_Stack_Push()` to insert an element at the top.
  - `ctl_Stack_Pop()` to remove and return the top element.
  - `ctl_Stack_At()` to get the element at a given position.
  - `ctl_Stack_Back()` to get the top element.
  - `ctl_Stack_Capacity()` to get the current capacity.
  - `ctl_Stack_Size()` to get the current size.
  - `ctl_Stack_IsEmpty()` to test if the stack is empty or not.
  - `ctl_Stack_Clear()` to remove all elements.
  - `ctl_Stack_Resize()` to resize to a bigger or smaller stack.
  - `ctl_Stack_ShrinkToFit()` to shrink the capacity to the size.

## [0.1.1]

(2021-08-27)

### Fixed

- Speed hit in `ctl_DynArray_PushBack()`.
- Unit test for `ctl_DynArray_PopFront()`.

## [0.1.0]

(2021-08-25)

### Added

- `ctl.h`:
  - `CTL_ADT_LIST()` to list the supported ADTs.
  - `CTL_DECLARE()` to declare an ADT with one or more type.
  - `CTL_DEFINE()` to define an ADT with one or more type.
- `ctl_dyn_array.h`: A dynamic array data structure.
  - `CTL_DYN_ARRAY()` to use as a dynamic array type specifier.
  - `ctl_DynArray_Create()` to create a dynamic array.
  - `ctl_DynArray_Destroy()` to destroy a dynamic array.
  - `ctl_DynArray_Reserve()` to increase the capacity.
  - `ctl_DynArray_Insert()` to insert an element at a given position.
  - `ctl_DynArray_PushFront()` to insert an element at the front.
  - `ctl_DynArray_PushBack()` to insert an element at the back.
  - `ctl_DynArray_PopFront()` to remove and return the first element
  - `ctl_DynArray_PopBack()` to remove and return the last element.
  - `ctl_DynArray_At()` to get the element at a given position.
  - `ctl_DynArray_Front()` to get the first element.
  - `ctl_DynArray_Back()` to get the last element.
  - `ctl_DynArray_Capacity()` to get the current capacity.
  - `ctl_DynArray_Size()` to get the current size.
  - `ctl_DynArray_IsEmpty()` to test if the array is empty or not.
  - `ctl_DynArray_Clear()` to remove all elements.
  - `ctl_DynArray_Resize()` to resize to a bigger or smaller array.
  - `ctl_DynArray_ShrinkToFit()` to shrink the capacity to the size.
  - `ctl_DynArray_Remove()` to remove an element from a given position.
