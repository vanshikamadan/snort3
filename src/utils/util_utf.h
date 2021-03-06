//--------------------------------------------------------------------------
// Copyright (C) 2014-2017 Cisco and/or its affiliates. All rights reserved.
// Copyright (C) 2010-2013 Sourcefire, Inc.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

#ifndef UTIL_UTF_H
#define UTIL_UTF_H

// Some UTF-{16,32}{le,be} normalization functions

#include "main/snort_types.h"

// Character set types. Used by HTTP inspectors. Update inspectors while changing this value.
enum CharsetCode
{
    CHARSET_DEFAULT=0,
    CHARSET_OTHER,
    CHARSET_UTF7,
    CHARSET_IRRELEVANT,
    CHARSET_UTF16LE,
    CHARSET_UTF16BE,
    CHARSET_UTF32LE,
    CHARSET_UTF32BE,
    CHARSET_UNKNOWN
};

// Since payloads don't have to end on 2/4-byte boundaries, callers to
// DecodeUTF are responsible for keeping a decode_utf_state_t. This carries
// state between subsequent calls.
struct decode_utf_state_t
{
    int state;
    CharsetCode charset;
};

void keep_utf_lib();  // FIXIT-L eliminate; required to keep symbols for dyn plugins

class SO_PUBLIC UtfDecodeSession
{
public:
    UtfDecodeSession();
    virtual ~UtfDecodeSession() { }
    void init_decode_utf_state();
    void set_decode_utf_state_charset(CharsetCode charset);
    CharsetCode get_decode_utf_state_charset();
    bool is_utf_encoding_present();
    bool decode_utf(const char* src, unsigned int src_len, char* dst, unsigned int dst_len, int* bytes_copied);
private:
    decode_utf_state_t dstate;
    bool DecodeUTF16LE(const char* src, unsigned int src_len, char* dst, unsigned int dst_len, int* bytes_copied);
    bool DecodeUTF16BE(const char* src, unsigned int src_len, char* dst, unsigned int dst_len, int* bytes_copied);
    bool DecodeUTF32LE(const char* src, unsigned int src_len, char* dst, unsigned int dst_len, int* bytes_copied);
    bool DecodeUTF32BE(const char* src, unsigned int src_len, char* dst, unsigned int dst_len, int* bytes_copied);
    void determine_charset(const char** src, unsigned int *src_len);
};
#endif
