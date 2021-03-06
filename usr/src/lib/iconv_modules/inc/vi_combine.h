/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * COPYRIGHT AND PERMISSION NOTICE
 *
 * Copyright (c) 1991-2005 Unicode, Inc. All rights reserved. Distributed
 *  under the Terms of Use in http://www.unicode.org/copyright.html.
 *
 * This file has been modified by Sun Microsystems, Inc.
 *
*/
/*
 * Copyright(c) 2008 Sun Microsystems, Inc.
 * All rights reserved.
 */

#ifndef _VI_COMBINE_H_
#define _VI_COMBINE_H_

#define VOWEL_NUM 24

/*
 * Unicode of combining characters:
 * 0x0300, 0x0301, 0x0303, 0x0309, 0x0323.
 * */
typedef struct _combine_map {
   unsigned short   base;
   unsigned short   composed[5];
} Combine_map;

#define ISCOMB_UNI(uni) ((uni)>=0x0300 && (uni)<=0x0323)

/* Composition tables for each of the relevant combining characters. */
Combine_map vi_comb_data[VOWEL_NUM] = {
    { 0x0041, {0x00C0, 0x00C1, 0x00C3, 0x1EA2, 0x1EA0}},
    { 0x0045, {0x00C8, 0x00C9, 0x1EBC, 0x1EBA, 0x1EB8}},
    { 0x0049, {0x00CC, 0x00CD, 0x0128, 0x1EC8, 0x1ECA}},
    { 0x004F, {0x00D2, 0x00D3, 0x00D5, 0x1ECE, 0x1ECC}},
    { 0x0055, {0x00D9, 0x00DA, 0x0168, 0x1EE6, 0x1EE4}},
    { 0x0059, {0x1EF2, 0x00DD, 0x1EF8, 0x1EF6, 0x1EF4}},
    { 0x0061, {0x00E0, 0x00E1, 0x00E3, 0x1EA3, 0x1EA1}},
    { 0x0065, {0x00E8, 0x00E9, 0x1EBD, 0x1EBB, 0x1EB9}},
    { 0x0069, {0x00EC, 0x00ED, 0x0129, 0x1EC9, 0x1ECB}},
    { 0x006F, {0x00F2, 0x00F3, 0x00F5, 0x1ECF, 0x1ECD}},
    { 0x0075, {0x00F9, 0x00FA, 0x0169, 0x1EE7, 0x1EE5}},
    { 0x0079, {0x1EF3, 0x00FD, 0x1EF9, 0x1EF7, 0x1EF5}},
    { 0x00C2, {0x1EA6, 0x1EA4, 0x1EAA, 0x1EA8, 0x1EAC}},
    { 0x00CA, {0x1EC0, 0x1EBE, 0x1EC4, 0x1EC2, 0x1EC6}},
    { 0x00D4, {0x1ED2, 0x1ED0, 0x1ED6, 0x1ED4, 0x1ED8}},
    { 0x00E2, {0x1EA7, 0x1EA5, 0x1EAB, 0x1EA9, 0x1EAD}},
    { 0x00EA, {0x1EC1, 0x1EBF, 0x1EC5, 0x1EC3, 0x1EC7}},
    { 0x00F4, {0x1ED3, 0x1ED1, 0x1ED7, 0x1ED5, 0x1ED9}},
    { 0x0102, {0x1EB0, 0x1EAE, 0x1EB4, 0x1EB2, 0x1EB6}},
    { 0x0103, {0x1EB1, 0x1EAF, 0x1EB5, 0x1EB3, 0x1EB7}},
    { 0x01A0, {0x1EDC, 0x1EDA, 0x1EE0, 0x1EDE, 0x1EE2}},
    { 0x01A1, {0x1EDD, 0x1EDB, 0x1EE1, 0x1EDF, 0x1EE3}},
    { 0x01AF, {0x1EEA, 0x1EE8, 0x1EEE, 0x1EEC, 0x1EF0}},
    { 0x01B0, {0x1EEB, 0x1EE9, 0x1EEF, 0x1EED, 0x1EF1}},
};

/* MASK_NUM = (0x01B0 - 0x0041) / 32(bit of unsigned int) + 1 */
#define MASK_NUM  12

/* Possible Compbine base make.
 * The possible bases in vi_comb_data:
 *  0x0041, 0x0045, 0x0049, 0x004F, 0x0055, 0x0059, 0x0061, 0x0065,
 *  0x0069, 0x006F, 0x0075, 0x0079, 0x00C2, 0x00CA, 0x00D4, 0x00E2,
 *  0x00EA, 0x00F4, 0x0102, 0x0103, 0x01A0, 0x01A1, 0x01AF, 0x01B0.
 * */
static const unsigned long tcvn_comp_bases_mask[MASK_NUM] = {
    0x02208222, 0x02208222, 0x00000000, 0x00000000,
    0x00100404, 0x00100404, 0x0000000c, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00018003
};


/*
 * TCVN code of combining characters:
 * 0xb0...0xb4.
 * */
typedef struct _combine_map_tcvn {
   unsigned char   base;
   unsigned char   composed[5];
} Combine_map_tcvn;

#define ISCOMB_TCVN(ch) ((ch)>=0xb0 && (ch)<=0xb4)

/* Composition tables for each of the relevant combining characters. */
Combine_map_tcvn tcvn_comb_data[VOWEL_NUM] = {
    {0x41, { 0x80, 0x81, 0x82, 0x83, 0x84 }},
    {0x45, { 0x87, 0x88, 0x89, 0x8a, 0x8b }},
    {0x49, { 0x8d, 0x8e, 0x8f, 0x90, 0x91 }},
    {0x4f, { 0x92, 0x93, 0x94, 0x95, 0x96 }},
    {0x55, { 0x9d, 0x9e, 0x9f, 0x01, 0x02 }},
    {0x59, { 0x13, 0x14, 0x15, 0x16, 0x17 }},
    {0x61, { 0xb5, 0xb6, 0xb7, 0xb8, 0xb9 }},
    {0x65, { 0xcc, 0xce, 0xcf, 0xd0, 0xd1 }},
    {0x69, { 0xd7, 0xd8, 0xdc, 0xdd, 0xde }},
    {0x6f, { 0xdf, 0xe1, 0xe2, 0xe3, 0xe4 }},
    {0x75, { 0xef, 0xf1, 0xf2, 0xf3, 0xf4 }},
    {0x79, { 0xfa, 0xfb, 0xfc, 0xfd, 0xfe }},
    {0xa1, { 0xaf, 0xba, 0xbf, 0xc0, 0x85 }},
    {0xa2, { 0xc1, 0xc2, 0xc3, 0xc4, 0x86 }},
    {0xa3, { 0xc5, 0xcd, 0xd9, 0xda, 0x8c }},
    {0xa4, { 0xdb, 0xe0, 0xf0, 0xff, 0x97 }},
    {0xa5, { 0x98, 0x99, 0x9a, 0x9b, 0x9c }},
    {0xa6, { 0x04, 0x05, 0x06, 0x11, 0x12 }},
    {0xa8, { 0xbb, 0xbc, 0xbd, 0xbe, 0xc6 }},
    {0xa9, { 0xc7, 0xc8, 0xc9, 0xca, 0xcb }},
    {0xaa, { 0xd2, 0xd3, 0xd4, 0xd5, 0xd6 }},
    {0xab, { 0xe5, 0xe6, 0xe7, 0xe8, 0xe9 }},
    {0xac, { 0xea, 0xeb, 0xec, 0xed, 0xee }},
    {0xad, { 0xf5, 0xf6, 0xf7, 0xf8, 0xf9 }},
};

/* MASK_NUM = (0xad - 0x40) / 32 (bit of unsigned int) + 1 */
#define MASK_NUM_TCVN  4
static const unsigned int tcvn_comp_bases_mask0[MASK_NUM_TCVN] = {
    0x02208222, 0x02208222,
    0x00000000, 0x00003f7e,
};

#endif
