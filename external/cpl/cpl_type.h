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
 * Provide macros expanding to comma separated lists of types defined by the C
 * standard.
 *
 * @see
 * @C17{6.2.5}
 */
/*==============================================================================
    GUARD
==============================================================================*/
#ifndef CPL_TYPE_H_20190718004511
#define CPL_TYPE_H_20190718004511
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
/**
 * Expand to the \i{standard signed integer types}.
 *
 * @v{
 * signed char, short int, int, long int, long long int
 * }
 */
#define CPL_TYPE_STD_SIGNED_INTEGER                                            \
    signed char,                                                               \
    short int,                                                                 \
    int,                                                                       \
    long int,                                                                  \
    long long int
/**
 * Expand to the \i{signed integer types}.
 *
 * @v{
 * signed char, short int, int, long int, long long int
 * }
 */
#define CPL_TYPE_SIGNED_INTEGER                                                \
    CPL_TYPE_STD_SIGNED_INTEGER
/**
 * Expand to the \i{standard unsigned integer types}.
 *
 * @v{
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int
 * }
 */
#define CPL_TYPE_STD_UNSIGNED_INTEGER                                          \
    _Bool,                                                                     \
    unsigned char,                                                             \
    unsigned short int,                                                        \
    unsigned int,                                                              \
    unsigned long int,                                                         \
    unsigned long long int
/**
 * Expand to the \i{unsigned integer types}.
 *
 * @v{
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int
 * }
 */
#define CPL_TYPE_UNSIGNED_INTEGER                                              \
    CPL_TYPE_STD_UNSIGNED_INTEGER
/**
 * Expand to the \i{standard integer types}.
 *
 * @v{
 * signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int
 * }
 */
#define CPL_TYPE_STD_INTEGER                                                   \
    CPL_TYPE_STD_SIGNED_INTEGER,                                               \
    CPL_TYPE_STD_UNSIGNED_INTEGER
/**
 * Expand to the \i{real floating types}.
 *
 * @v{
 * float, double, long double
 * }
 */
#define CPL_TYPE_REAL_FLOATING                                                 \
    float,                                                                     \
    double,                                                                    \
    long double
/**
 * Expand to the \i{complex types}.
 *
 * @v{
 * float _Complex, double _Complex, long double _Complex
 * }
 */
#define CPL_TYPE_COMPLEX                                                       \
    float _Complex,                                                            \
    double _Complex,                                                           \
    long double _Complex
/**
 * Expand to the \i{floating types}.
 *
 * @v{
 * float, double, long double,
 * float _Complex, double _Complex, long double _Complex
 * }
 */
#define CPL_TYPE_FLOATING                                                      \
    CPL_TYPE_REAL_FLOATING,                                                    \
    CPL_TYPE_COMPLEX
/**
 * Expand to the \i{basic types}.
 *
 * @v{
 * char, signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int,
 * float, double, long double,
 * float _Complex, double _Complex, long double _Complex
 * }
 */
#define CPL_TYPE_BASIC                                                         \
    char,                                                                      \
    CPL_TYPE_SIGNED_INTEGER,                                                   \
    CPL_TYPE_UNSIGNED_INTEGER,                                                 \
    CPL_TYPE_FLOATING
/**
 * Expand to the \i{character types}.
 *
 * @v{
 * char, signed char, unsigned char
 * }
 */
#define CPL_TYPE_CHARACTER                                                     \
    char,                                                                      \
    signed char,                                                               \
    unsigned char
/**
 * Expand to the \i{integer types}.
 *
 * @v{
 * char, signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int
 * }
 */
#define CPL_TYPE_INTEGER                                                       \
    char,                                                                      \
    CPL_TYPE_SIGNED_INTEGER,                                                   \
    CPL_TYPE_UNSIGNED_INTEGER
/**
 * Expand to the \i{real types}.
 *
 * @v{
 * char, signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int,
 * float, double, long double
 * }
 */
#define CPL_TYPE_REAL                                                          \
    CPL_TYPE_INTEGER,                                                          \
    CPL_TYPE_REAL_FLOATING
/**
 * Expand to the \i{arithmetic types}.
 *
 * @v{
 * char, signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int,
 * float, double, long double,
 * float _Complex, double _Complex, long double _Complex
 * }
 */
#define CPL_TYPE_ARITHMETIC                                                    \
    CPL_TYPE_INTEGER,                                                          \
    CPL_TYPE_FLOATING
/**
 * Expand to the \i{pointer types} derived from the
 * \i{standard signed integer types}.
 *
 * @v{
 * signed char *, short int *, int *, long int *, long long int *
 * }
 */
#define CPL_TYPE_STD_SIGNED_INTEGER_PTR                                        \
    signed char *,                                                             \
    short int *,                                                               \
    int *,                                                                     \
    long int *,                                                                \
    long long int *
/**
 * Expand to the \i{pointer types} derived from the \i{signed integer types}.
 *
 * @v{
 * signed char *, short int *, int *, long int *, long long int *
 * }
 */
#define CPL_TYPE_SIGNED_INTEGER_PTR                                            \
    CPL_TYPE_STD_SIGNED_INTEGER_PTR
/**
 * Expand to the \i{pointer types} derived from the
 * \i{standard unsigned integer types}.
 *
 * @v{
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *
 * }
 */
#define CPL_TYPE_STD_UNSIGNED_INTEGER_PTR                                      \
    _Bool *,                                                                   \
    unsigned char *,                                                           \
    unsigned short int *,                                                      \
    unsigned int *,                                                            \
    unsigned long int *, unsigned long long int *
/**
 * Expand to the \i{pointer types} derived from the \i{unsigned integer types}.
 *
 * @v{
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *
 * }
 */
#define CPL_TYPE_UNSIGNED_INTEGER_PTR                                          \
    CPL_TYPE_STD_UNSIGNED_INTEGER_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{standard integer types}.
 *
 * @v{
 * signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *
 * }
 */
#define CPL_TYPE_STD_INTEGER_PTR                                               \
    CPL_TYPE_STD_SIGNED_INTEGER_PTR,                                           \
    CPL_TYPE_STD_UNSIGNED_INTEGER_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{real floating types}.
 *
 * @v{
 * float *, double *, long double *
 * }
 */
#define CPL_TYPE_REAL_FLOATING_PTR                                             \
    float *,                                                                   \
    double *,                                                                  \
    long double *
/**
 * Expand to the \i{pointer types} derived from the \i{complex types}.
 *
 * @v{
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_COMPLEX_PTR                                                   \
    float _Complex *,                                                          \
    double _Complex *,                                                         \
    long double _Complex *
/**
 * Expand to the \i{pointer types} derived from the \i{floating types}.
 *
 * @v{
 * float *, double *, long double *,
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_FLOATING_PTR                                                  \
    CPL_TYPE_REAL_FLOATING_PTR,                                                \
    CPL_TYPE_COMPLEX_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{basic types}.
 *
 * @v{
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *,
 * float *, double *, long double *,
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_BASIC_PTR                                                     \
    char *,                                                                    \
    CPL_TYPE_SIGNED_INTEGER_PTR,                                               \
    CPL_TYPE_UNSIGNED_INTEGER_PTR,                                             \
    CPL_TYPE_FLOATING_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{character types}.
 *
 * @v{
 * char *, signed char *, unsigned char *
 * }
 */
#define CPL_TYPE_CHARACTER_PTR                                                 \
    char *,                                                                    \
    signed char *,                                                             \
    unsigned char *
/**
 * Expand to the \i{pointer types} derived from the \i{integer types}.
 *
 * @v{
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *
 * }
 */
#define CPL_TYPE_INTEGER_PTR                                                   \
    char *,                                                                    \
    CPL_TYPE_SIGNED_INTEGER_PTR,                                               \
    CPL_TYPE_UNSIGNED_INTEGER_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{real types}.
 *
 * @v{
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *,
 * float *, double *, long double *
 * }
 */
#define CPL_TYPE_REAL_PTR                                                      \
    CPL_TYPE_INTEGER_PTR,                                                      \
    CPL_TYPE_REAL_FLOATING_PTR
/**
 * Expand to the \i{pointer types} derived from the \i{arithmetic types}.
 *
 * @v{
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *,
 * float *, double *, long double *,
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_ARITHMETIC_PTR                                                \
    CPL_TYPE_INTEGER_PTR,                                                      \
    CPL_TYPE_FLOATING_PTR
/**
 * Expand to the \i{pointer types} derived from object types.
 *
 * @v{
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *,
 * float *, double *, long double *,
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_POINTER                                                       \
    CPL_TYPE_ARITHMETIC_PTR
/**
 * Expand to the \i{scalar types}.
 *
 * @v{
 * char, signed char, short int, int, long int, long long int,
 * _Bool, unsigned char, unsigned short int, unsigned int, unsigned long int,
 * unsigned long long int,
 * float, double, long double,
 * float _Complex, double _Complex, long double _Complex,
 * char *, signed char *, short int *, int *, long int *, long long int *,
 * _Bool *, unsigned char *, unsigned short int *, unsigned int *,
 * unsigned long int *, unsigned long long int *,
 * float, double *, long double *,
 * float _Complex *, double _Complex *, long double _Complex *
 * }
 */
#define CPL_TYPE_SCALAR                                                        \
    CPL_TYPE_ARITHMETIC,                                                       \
    CPL_TYPE_ARITHMETIC_PTR
/**
 * Expand to an abbreviated form of the \i{standard signed integer types}.
 *
 * @v{
 * schar, short, int, long, llong
 * }
 */
#define CPL_TYPE_STD_SIGNED_INTEGER_ABBR                                       \
    schar,                                                                     \
    short,                                                                     \
    int,                                                                       \
    long,                                                                      \
    llong
/**
 * Expand to an abbreviated form of the \i{signed integer types}.
 *
 * @v{
 * schar, short, int, long, llong
 * }
 */
#define CPL_TYPE_SIGNED_INTEGER_ABBR                                           \
    CPL_TYPE_STD_SIGNED_INTEGER_ABBR
/**
 * Expand to an abbreviated form of the \i{standard unsigned integer types}.
 *
 * @v{
 * _Bool, uchar, ushort, uint, ulong, ullong
 * }
 */
#define CPL_TYPE_STD_UNSIGNED_INTEGER_ABBR                                     \
    _Bool,                                                                     \
    uchar,                                                                     \
    ushort,                                                                    \
    uint,                                                                      \
    ulong,                                                                     \
    ullong
/**
 * Expand to an abbreviated form of the \i{unsigned integer types}.
 *
 * @v{
 * _Bool, uchar, ushort, uint, ulong, ullong
 * }
 */
#define CPL_TYPE_UNSIGNED_INTEGER_ABBR                                         \
    CPL_TYPE_STD_UNSIGNED_INTEGER_ABBR
/**
 * Expand to an abbreviated form of the \i{standard integer types}.
 *
 * @v{
 * schar, short, int, long, llong, bool, uchar, ushort, uint, ulong, ullong
 * }
 */
#define CPL_TYPE_STD_INTEGER_ABBR                                              \
    CPL_TYPE_STD_SIGNED_INTEGER_ABBR,                                          \
    CPL_TYPE_STD_UNSIGNED_INTEGER_ABBR
/**
 * Expand to an abbreviated form of the \i{real floating types}.
 *
 * @v{
 * float, double, ldouble
 * }
 */
#define CPL_TYPE_REAL_FLOATING_ABBR                                            \
    float,                                                                     \
    double,                                                                    \
    ldouble
/**
 * Expand to an abbreviated form of the \i{complex types}.
 *
 * @v{
 * floatcx, doublecx, ldoublecx
 * }
 */
#define CPL_TYPE_COMPLEX_ABBR                                                  \
    floatcx,                                                                   \
    doublecx,                                                                  \
    ldoublecx
/**
 * Expand to an abbreviated form of the \i{floating types}.
 *
 * @v{
 * float, double, ldouble,
 * floatcx, doublecx, ldoublecx
 * }
 */
#define CPL_TYPE_FLOATING_ABBR                                                 \
    CPL_TYPE_REAL_FLOATING_ABBR,                                               \
    CPL_TYPE_COMPLEX_ABBR
/**
 * Expand to an abbreviated form of the \i{basic types}.
 *
 * @v{
 * char, schar, short, int, long, llong,
 * _Bool, uchar, ushort, uint, ulong, ullong,
 * float, double, ldouble,
 * floatcx, doublecx, ldoublecx
 * }
 */
#define CPL_TYPE_BASIC_ABBR                                                    \
    char,                                                                      \
    CPL_TYPE_SIGNED_INTEGER_ABBR,                                              \
    CPL_TYPE_UNSIGNED_INTEGER_ABBR,                                            \
    CPL_TYPE_FLOATING_ABBR
/**
 * Expand to an abbreviated form of the \i{character types}.
 *
 * @v{
 * char, schar, uchar
 * }
 */
#define CPL_TYPE_CHARACTER_ABBR                                                \
    char,                                                                      \
    schar,                                                                     \
    uchar
/**
 * Expand to an abbreviated form of the \i{integer types}.
 *
 * @v{
 * char, schar, short, int, long, llong,
 * _Bool, uchar, ushort, uint, ulong, ullong
 * }
 */
#define CPL_TYPE_INTEGER_ABBR                                                  \
    char,                                                                      \
    CPL_TYPE_SIGNED_INTEGER_ABBR,                                              \
    CPL_TYPE_UNSIGNED_INTEGER_ABBR
/**
 * Expand to an abbreviated form of the \i{real types}.
 *
 * @v{
 * char, schar, short, int, long, llong,
 * _Bool, uchar, ushort, uint, ulong, ullong,
 * float, double, ldouble
 * }
 */
#define CPL_TYPE_REAL_ABBR                                                     \
    CPL_TYPE_INTEGER_ABBR,                                                     \
    CPL_TYPE_REAL_FLOATING_ABBR
/**
 * Expand to an abbreviated form of the \i{arithmetic types}.
 *
 * @v{
 * char, schar, short, int, long, llong,
 * _Bool, uchar, ushort, uint, ulong, ullong,
 * float, double, ldouble,
 * floatcx, doublecx, ldoublecx
 * }
 */
#define CPL_TYPE_ARITHMETIC_ABBR                                               \
    CPL_TYPE_INTEGER_ABBR,                                                     \
    CPL_TYPE_FLOATING_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{standard signed integer types}.
 *
 * @v{
 * schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr
 * }
 */
#define CPL_TYPE_STD_SIGNED_INTEGER_PTR_ABBR                                   \
    schar_ptr,                                                                 \
    short_ptr,                                                                 \
    int_ptr,                                                                   \
    long_ptr,                                                                  \
    llong_ptr
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{signed integer types}.
 *
 * @v{
 * schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr
 * }
 */
#define CPL_TYPE_SIGNED_INTEGER_PTR_ABBR                                       \
    CPL_TYPE_STD_SIGNED_INTEGER_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{standard unsigned integer types}.
 *
 * @v{
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr
 * }
 */
#define CPL_TYPE_STD_UNSIGNED_INTEGER_PTR_ABBR                                 \
    _Bool_ptr,                                                                 \
    uchar_ptr,                                                                 \
    ushort_ptr,                                                                \
    uint_ptr,                                                                  \
    ulong_ptr,                                                                 \
    ullong_ptr
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{unsigned integer types}.
 *
 * @v{
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr
 * }
 */
#define CPL_TYPE_UNSIGNED_INTEGER_PTR_ABBR                                     \
    CPL_TYPE_STD_UNSIGNED_INTEGER_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{standard integer types}.
 *
 * @v{
 * schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr
 * }
 */
#define CPL_TYPE_STD_INTEGER_PTR_ABBR                                          \
    CPL_TYPE_STD_SIGNED_INTEGER_PTR_ABBR,                                      \
    CPL_TYPE_STD_UNSIGNED_INTEGER_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{real types}.
 *
 * @v{
 * float_ptr, double_ptr, ldouble_ptr
 * }
 */
#define CPL_TYPE_REAL_FLOATING_PTR_ABBR                                        \
    float_ptr,                                                                 \
    double_ptr,                                                                \
    ldouble_ptr
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{complex types}.
 *
 * @v{
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_COMPLEX_PTR_ABBR                                              \
    floatcx_ptr,                                                               \
    doublecx_ptr,                                                              \
    ldoublecx_ptr
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{floating types}.
 *
 * @v{
 * float_ptr, double_ptr, ldouble_ptr,
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_FLOATING_PTR_ABBR                                             \
    CPL_TYPE_REAL_FLOATING_PTR_ABBR,                                           \
    CPL_TYPE_COMPLEX_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{basic types}.
 *
 * @v{
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr,
 * float_ptr, double_ptr, ldouble_ptr,
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_BASIC_PTR_ABBR                                                \
    char_ptr,                                                                  \
    CPL_TYPE_SIGNED_INTEGER_PTR_ABBR,                                          \
    CPL_TYPE_UNSIGNED_INTEGER_PTR_ABBR,                                        \
    CPL_TYPE_FLOATING_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{character types}.
 *
 * @v{
 * char_ptr, schar_ptr, uchar_ptr
 * }
 */
#define CPL_TYPE_CHARACTER_PTR_ABBR                                            \
    char_ptr,                                                                  \
    schar_ptr,                                                                 \
    uchar_ptr
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{integer types}.
 *
 * @v{
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr
 * }
 */
#define CPL_TYPE_INTEGER_PTR_ABBR                                              \
    char_ptr,                                                                  \
    CPL_TYPE_SIGNED_INTEGER_PTR_ABBR,                                          \
    CPL_TYPE_UNSIGNED_INTEGER_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{real types}.
 *
 * @v{
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr,
 * float_ptr, double_ptr, ldouble_ptr
 * }
 */
#define CPL_TYPE_REAL_PTR_ABBR                                                 \
    CPL_TYPE_INTEGER_PTR_ABBR,                                                 \
    CPL_TYPE_REAL_FLOATING_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from the
 * \i{arithmetic types}.
 *
 * @v{
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr,
 * float_ptr, double_ptr, ldouble_ptr,
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_ARITHMETIC_PTR_ABBR                                           \
    CPL_TYPE_INTEGER_PTR_ABBR,                                                 \
    CPL_TYPE_FLOATING_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{pointer types} derived from object
 * types.
 *
 * @v{
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr,
 * float_ptr, double_ptr, ldouble_ptr,
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_POINTER_ABBR                                                  \
    CPL_TYPE_ARITHMETIC_PTR_ABBR
/**
 * Expand to an abbreviated form of the \i{scalar types}.
 *
 * @v{
 * char, schar, short, int, long, llong,
 * _Bool, uchar, ushort, uint, ulong, ullong,
 * float, double, ldouble,
 * floatcx, doublecx, ldoublecx,
 * char_ptr, schar_ptr, short_ptr, int_ptr, long_ptr, llong_ptr,
 * _Bool_ptr, uchar_ptr, ushort_ptr, uint_ptr, ulong_ptr, ullong_ptr,
 * float_ptr, double_ptr, ldouble_ptr,
 * floatcx_ptr, doublecx_ptr, ldoublecx_ptr
 * }
 */
#define CPL_TYPE_SCALAR_ABBR                                                   \
    CPL_TYPE_ARITHMETIC_ABBR,                                                  \
    CPL_TYPE_ARITHMETIC_PTR_ABBR
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_TYPE_H_20190718004511
