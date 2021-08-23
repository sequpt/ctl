// SPDX-License-Identifier: 0BSD
/*
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
#ifndef CPL_ARG_GEN_H
#define CPL_ARG_GEN_H
/*==============================================================================
    PREPROCESSOR
==============================================================================*/
#define CPL_ARG_1(                                                             \
    A1  , ...                                                                  \
) A1
#define CPL_ARG_2(                                                             \
    A1  , A2  , ...                                                            \
) A2
#define CPL_ARG_3(                                                             \
    A1  , A2  , A3  , ...                                                      \
) A3
#define CPL_ARG_4(                                                             \
    A1  , A2  , A3  , A4  , ...                                                \
) A4
#define CPL_ARG_5(                                                             \
    A1  , A2  , A3  , A4  , A5  , ...                                          \
) A5
#define CPL_ARG_6(                                                             \
    A1  , A2  , A3  , A4  , A5  , A6  , ...                                    \
) A6
#define CPL_ARG_7(                                                             \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , ...                              \
) A7
#define CPL_ARG_8(                                                             \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , ...                        \
) A8
#define CPL_ARG_9(                                                             \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , ...                  \
) A9
#define CPL_ARG_10(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , ...            \
) A10
#define CPL_ARG_11(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , ...      \
) A11
#define CPL_ARG_12(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    ...                                                                        \
) A12
#define CPL_ARG_13(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , ...                                                                  \
) A13
#define CPL_ARG_14(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , ...                                                            \
) A14
#define CPL_ARG_15(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , ...                                                      \
) A15
#define CPL_ARG_16(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , ...                                                \
) A16
#define CPL_ARG_17(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , ...                                          \
) A17
#define CPL_ARG_18(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , ...                                    \
) A18
#define CPL_ARG_19(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , ...                              \
) A19
#define CPL_ARG_20(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , ...                        \
) A20
#define CPL_ARG_21(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , ...                  \
) A21
#define CPL_ARG_22(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , ...            \
) A22
#define CPL_ARG_23(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , ...      \
) A23
#define CPL_ARG_24(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    ...                                                                        \
) A24
#define CPL_ARG_25(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , ...                                                                  \
) A25
#define CPL_ARG_26(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , ...                                                            \
) A26
#define CPL_ARG_27(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , ...                                                      \
) A27
#define CPL_ARG_28(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , ...                                                \
) A28
#define CPL_ARG_29(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , ...                                          \
) A29
#define CPL_ARG_30(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , ...                                    \
) A30
#define CPL_ARG_31(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , ...                              \
) A31
#define CPL_ARG_32(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , ...                        \
) A32
#define CPL_ARG_33(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , ...                  \
) A33
#define CPL_ARG_34(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , ...            \
) A34
#define CPL_ARG_35(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , ...      \
) A35
#define CPL_ARG_36(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    ...                                                                        \
) A36
#define CPL_ARG_37(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , ...                                                                  \
) A37
#define CPL_ARG_38(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , ...                                                            \
) A38
#define CPL_ARG_39(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , ...                                                      \
) A39
#define CPL_ARG_40(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , ...                                                \
) A40
#define CPL_ARG_41(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , ...                                          \
) A41
#define CPL_ARG_42(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , ...                                    \
) A42
#define CPL_ARG_43(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , ...                              \
) A43
#define CPL_ARG_44(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , ...                        \
) A44
#define CPL_ARG_45(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , ...                  \
) A45
#define CPL_ARG_46(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , ...            \
) A46
#define CPL_ARG_47(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , ...      \
) A47
#define CPL_ARG_48(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    ...                                                                        \
) A48
#define CPL_ARG_49(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , ...                                                                  \
) A49
#define CPL_ARG_50(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , ...                                                            \
) A50
#define CPL_ARG_51(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , ...                                                      \
) A51
#define CPL_ARG_52(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , ...                                                \
) A52
#define CPL_ARG_53(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , ...                                          \
) A53
#define CPL_ARG_54(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , ...                                    \
) A54
#define CPL_ARG_55(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , ...                              \
) A55
#define CPL_ARG_56(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , ...                        \
) A56
#define CPL_ARG_57(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , ...                  \
) A57
#define CPL_ARG_58(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , ...            \
) A58
#define CPL_ARG_59(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , ...      \
) A59
#define CPL_ARG_60(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    ...                                                                        \
) A60
#define CPL_ARG_61(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , ...                                                                  \
) A61
#define CPL_ARG_62(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , ...                                                            \
) A62
#define CPL_ARG_63(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , ...                                                      \
) A63
#define CPL_ARG_64(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , ...                                                \
) A64
#define CPL_ARG_65(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , ...                                          \
) A65
#define CPL_ARG_66(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , ...                                    \
) A66
#define CPL_ARG_67(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , ...                              \
) A67
#define CPL_ARG_68(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , ...                        \
) A68
#define CPL_ARG_69(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , ...                  \
) A69
#define CPL_ARG_70(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , ...            \
) A70
#define CPL_ARG_71(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , ...      \
) A71
#define CPL_ARG_72(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    ...                                                                        \
) A72
#define CPL_ARG_73(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , ...                                                                  \
) A73
#define CPL_ARG_74(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , ...                                                            \
) A74
#define CPL_ARG_75(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , ...                                                      \
) A75
#define CPL_ARG_76(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , ...                                                \
) A76
#define CPL_ARG_77(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , ...                                          \
) A77
#define CPL_ARG_78(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , ...                                    \
) A78
#define CPL_ARG_79(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , ...                              \
) A79
#define CPL_ARG_80(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , ...                        \
) A80
#define CPL_ARG_81(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , ...                  \
) A81
#define CPL_ARG_82(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , ...            \
) A82
#define CPL_ARG_83(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , ...      \
) A83
#define CPL_ARG_84(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    ...                                                                        \
) A84
#define CPL_ARG_85(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , ...                                                                  \
) A85
#define CPL_ARG_86(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , ...                                                            \
) A86
#define CPL_ARG_87(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , ...                                                      \
) A87
#define CPL_ARG_88(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , ...                                                \
) A88
#define CPL_ARG_89(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , ...                                          \
) A89
#define CPL_ARG_90(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , ...                                    \
) A90
#define CPL_ARG_91(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , ...                              \
) A91
#define CPL_ARG_92(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , ...                        \
) A92
#define CPL_ARG_93(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , ...                  \
) A93
#define CPL_ARG_94(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , ...            \
) A94
#define CPL_ARG_95(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , ...      \
) A95
#define CPL_ARG_96(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    ...                                                                        \
) A96
#define CPL_ARG_97(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , ...                                                                  \
) A97
#define CPL_ARG_98(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , ...                                                            \
) A98
#define CPL_ARG_99(                                                            \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , ...                                                      \
) A99
#define CPL_ARG_100(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, ...                                                \
) A100
#define CPL_ARG_101(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, ...                                          \
) A101
#define CPL_ARG_102(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, ...                                    \
) A102
#define CPL_ARG_103(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, ...                              \
) A103
#define CPL_ARG_104(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, ...                        \
) A104
#define CPL_ARG_105(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, ...                  \
) A105
#define CPL_ARG_106(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, ...            \
) A106
#define CPL_ARG_107(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, ...      \
) A107
#define CPL_ARG_108(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    ...                                                                        \
) A108
#define CPL_ARG_109(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, ...                                                                  \
) A109
#define CPL_ARG_110(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, ...                                                            \
) A110
#define CPL_ARG_111(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, ...                                                      \
) A111
#define CPL_ARG_112(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, ...                                                \
) A112
#define CPL_ARG_113(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, ...                                          \
) A113
#define CPL_ARG_114(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, ...                                    \
) A114
#define CPL_ARG_115(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, ...                              \
) A115
#define CPL_ARG_116(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, ...                        \
) A116
#define CPL_ARG_117(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, ...                  \
) A117
#define CPL_ARG_118(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, ...            \
) A118
#define CPL_ARG_119(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, ...      \
) A119
#define CPL_ARG_120(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    ...                                                                        \
) A120
#define CPL_ARG_121(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, ...                                                                  \
) A121
#define CPL_ARG_122(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, ...                                                            \
) A122
#define CPL_ARG_123(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, A123, ...                                                      \
) A123
#define CPL_ARG_124(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, A123, A124, ...                                                \
) A124
#define CPL_ARG_125(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, A123, A124, A125, ...                                          \
) A125
#define CPL_ARG_126(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, A123, A124, A125, A126, ...                                    \
) A126
#define CPL_ARG_127(                                                           \
    A1  , A2  , A3  , A4  , A5  , A6  , A7  , A8  , A9  , A10 , A11 , A12 ,    \
    A13 , A14 , A15 , A16 , A17 , A18 , A19 , A20 , A21 , A22 , A23 , A24 ,    \
    A25 , A26 , A27 , A28 , A29 , A30 , A31 , A32 , A33 , A34 , A35 , A36 ,    \
    A37 , A38 , A39 , A40 , A41 , A42 , A43 , A44 , A45 , A46 , A47 , A48 ,    \
    A49 , A50 , A51 , A52 , A53 , A54 , A55 , A56 , A57 , A58 , A59 , A60 ,    \
    A61 , A62 , A63 , A64 , A65 , A66 , A67 , A68 , A69 , A70 , A71 , A72 ,    \
    A73 , A74 , A75 , A76 , A77 , A78 , A79 , A80 , A81 , A82 , A83 , A84 ,    \
    A85 , A86 , A87 , A88 , A89 , A90 , A91 , A92 , A93 , A94 , A95 , A96 ,    \
    A97 , A98 , A99 , A100, A101, A102, A103, A104, A105, A106, A107, A108,    \
    A109, A110, A111, A112, A113, A114, A115, A116, A117, A118, A119, A120,    \
    A121, A122, A123, A124, A125, A126, A127, ...                              \
) A127
/*==============================================================================
    GUARD
==============================================================================*/
#endif // CPL_ARG_GEN_H
