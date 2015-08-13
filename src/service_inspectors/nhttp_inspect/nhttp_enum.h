//--------------------------------------------------------------------------
// Copyright (C) 2014-2015 Cisco and/or its affiliates. All rights reserved.
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
// nhttp_enum.h author Tom Peters <thopeter@cisco.com>

#ifndef NHTTP_ENUM_H
#define NHTTP_ENUM_H

#include <stdint.h>

namespace NHttpEnums
{
static const int MAX_OCTETS = 65535;
static const int DATA_BLOCK_SIZE = 16384;
static const int FINAL_BLOCK_SIZE = 24576;
static const int GZIP_BLOCK_SIZE = 4096;
static const uint32_t NHTTP_GID = 219;

// Field status codes for when no valid value is present in length or integer value. Positive
// values are actual length or field value.
enum StatusCode { STAT_NOSOURCE=-16, STAT_NOTCONFIGURED=-15, STAT_NOTCOMPUTE=-14,
    STAT_INSUFMEMORY=-13, STAT_PROBLEMATIC=-12, STAT_NOTPRESENT=-11, STAT_EMPTYSTRING=0,
    STAT_OTHER=1 };

// Message originator--client or server
enum SourceId { SRC__NOTCOMPUTE=-14, SRC_CLIENT=0, SRC_SERVER=1 };

// Type of message section
enum SectionType { SEC_DISCARD = -19, SEC_ABORT = -18, SEC__NOTCOMPUTE=-14, SEC__NOTPRESENT=-11,
    SEC_REQUEST = 2, SEC_STATUS, SEC_HEADER, SEC_BODY, SEC_CHUNK, SEC_TRAILER };

// Result of scanning by splitter
enum ScanResult { SCAN_NOTFOUND, SCAN_FOUND, SCAN_FOUND_PIECE, SCAN_DISCARD, SCAN_DISCARD_PIECE,
    SCAN_ABORT };

// State machine for chunk parsing
enum ChunkState { CHUNK_ZEROS, CHUNK_NUMBER, CHUNK_WHITESPACE, CHUNK_OPTIONS, CHUNK_HCRLF,
    CHUNK_DATA, CHUNK_DCRLF1, CHUNK_DCRLF2, CHUNK_BAD };

// List of possible HTTP versions. Version 0.9 omitted because 0.9 predates creation of the
// HTTP/X.Y token. There would never be a message with "HTTP/0.9"
enum VersionId { VERS__NOSOURCE=-16, VERS__NOTCOMPUTE=-14, VERS__PROBLEMATIC=-12,
    VERS__NOTPRESENT=-11, VERS__OTHER=1, VERS_1_0, VERS_1_1, VERS_2_0 };

// Every request method we have ever heard of
enum MethodId { METH__NOSOURCE=-16, METH__NOTCOMPUTE=-14, METH__INSUFMEMORY=-13,
    METH__PROBLEMATIC=-12, METH__NOTPRESENT=-11, METH__OTHER=1, METH_OPTIONS, METH_GET, METH_HEAD,
    METH_POST, METH_PUT, METH_DELETE, METH_TRACE, METH_CONNECT, METH_PROPFIND, METH_PROPPATCH,
    METH_MKCOL, METH_COPY, METH_MOVE, METH_LOCK, METH_UNLOCK, METH_VERSION_CONTROL, METH_REPORT,
    METH_CHECKOUT, METH_CHECKIN, METH_UNCHECKOUT, METH_MKWORKSPACE, METH_UPDATE, METH_LABEL,
    METH_MERGE, METH_BASELINE_CONTROL, METH_MKACTIVITY, METH_ORDERPATCH, METH_ACL, METH_PATCH,
    METH_SEARCH, METH_BCOPY, METH_BDELETE, METH_BMOVE, METH_BPROPFIND, METH_BPROPPATCH,
    METH_NOTIFY, METH_POLL, METH_SUBSCRIBE, METH_UNSUBSCRIBE, METH_X_MS_ENUMATTS, METH_BIND,
    METH_LINK, METH_MKCALENDAR, METH_MKREDIRECTREF, METH_REBIND, METH_UNBIND, METH_UNLINK,
    METH_UPDATEREDIRECTREF };

// URI formats
enum UriType { URI__NOTCOMPUTE=-14, URI__PROBLEMATIC=-12, URI_ASTERISK = 2, URI_AUTHORITY,
    URI_ABSPATH, URI_ABSOLUTE };

// URI schemes
enum SchemeId { SCH__NOSOURCE=-16, SCH__NOTCOMPUTE=-14, SCH__INSUFMEMORY=-13, SCH__NOTPRESENT=-11,
    SCH_OTHER = 1, SCH_HTTP, SCH_HTTPS, SCH_FTP, SCH_GOPHER, SCH_FILE };

// Every header we have ever heard of
enum HeaderId { HEAD__NOTCOMPUTE=-14, HEAD__INSUFMEMORY=-13, HEAD__PROBLEMATIC=-12,
    HEAD__NOTPRESENT=-11, HEAD__OTHER=1, HEAD_CACHE_CONTROL, HEAD_CONNECTION, HEAD_DATE,
    HEAD_PRAGMA, HEAD_TRAILER, HEAD_COOKIE, HEAD_SET_COOKIE, HEAD_TRANSFER_ENCODING, HEAD_UPGRADE,
    HEAD_VIA, HEAD_WARNING, HEAD_ACCEPT, HEAD_ACCEPT_CHARSET, HEAD_ACCEPT_ENCODING,
    HEAD_ACCEPT_LANGUAGE, HEAD_AUTHORIZATION, HEAD_EXPECT, HEAD_FROM, HEAD_HOST, HEAD_IF_MATCH,
    HEAD_IF_MODIFIED_SINCE, HEAD_IF_NONE_MATCH, HEAD_IF_RANGE, HEAD_IF_UNMODIFIED_SINCE,
    HEAD_MAX_FORWARDS, HEAD_PROXY_AUTHORIZATION, HEAD_RANGE, HEAD_REFERER, HEAD_TE,
    HEAD_USER_AGENT, HEAD_ACCEPT_RANGES, HEAD_AGE, HEAD_ETAG, HEAD_LOCATION,
    HEAD_PROXY_AUTHENTICATE, HEAD_RETRY_AFTER, HEAD_SERVER, HEAD_VARY, HEAD_WWW_AUTHENTICATE,
    HEAD_ALLOW, HEAD_CONTENT_ENCODING, HEAD_CONTENT_LANGUAGE, HEAD_CONTENT_LENGTH,
    HEAD_CONTENT_LOCATION, HEAD_CONTENT_MD5, HEAD_CONTENT_RANGE, HEAD_CONTENT_TYPE, HEAD_EXPIRES,
    HEAD_LAST_MODIFIED, HEAD_X_FORWARDED_FOR, HEAD_TRUE_CLIENT_IP, HEAD__MAX_VALUE };

// All the infractions we might find while parsing and analyzing a message
enum Infraction
{
    INF_TRUNCATED = 0,
    INF_HEAD_TOO_LONG,
    INF_BAD_REQ_LINE,
    INF_BAD_STAT_LINE,
    INF_TOO_MANY_HEADERS,
    INF_BAD_HEADER,
    INF_BAD_STAT_CODE,
    INF_UNKNOWN_VERSION,
    INF_BAD_VERSION,
    INF_NO_SCRATCH,
    INF_BAD_HEADER_REPS,
    INF_BAD_HEADER_DATA,
    INF_PIPELINE_OVERFLOW,
    INF_BAD_CHUNK_SIZE,
    INF_BAD_PHRASE,
    INF_BAD_URI,
    INF_BAD_PORT,
    INF_URI_NEED_NORM,
    INF_URI_PERCENT_NORMAL,
    INF_URI_PERCENT_ASCII,
    INF_URI_PERCENT_UTF8,
    INF_URI_PERCENT_UCODE,
    INF_URI_PERCENT_OTHER,
    INF_URI_BAD_CHAR,
    INF_URI_8BIT_CHAR,
    INF_URI_MULTISLASH,
    INF_URI_BACKSLASH,
    INF_URI_SLASH_DOT,
    INF_URI_SLASH_DOT_DOT,
    INF_URI_ROOT_TRAV,
    INF_TOO_MUCH_LEADING_WS,
    INF_WS_BETWEEN_MSGS,
    INF_ENDLESS_HEADER,
    INF_LF_WITHOUT_CR,
    INF_NOT_HTTP,
    INF_NO_URI,
    INF_REQUEST_WS,
    INF_REQUEST_TAB,
    INF_STATUS_WS,
    INF_STATUS_TAB,
    INF_URI_SPACE,
    INF_TOO_LONG_HEADER,
    INF_LONE_CR,
    INF_CHUNK_ZEROS,
    INF_CHUNK_OPTIONS,
    INF_CHUNK_BAD_CHAR,
    INF_CHUNK_TOO_LARGE,
    INF_CHUNK_BARE_LF,
    INF_CHUNK_LONE_CR,
    INF_CHUNK_NO_LENGTH,
    INF_CHUNK_BAD_END,
    INF_PARTIAL_START,
    INF_CHUNK_WHITESPACE,
    INF__MAX_VALUE
};

// Formats for output from a header normalization function
enum NormFormat { NORM_NULL, NORM_FIELD, NORM_INT64, NORM_ENUM64, NORM_ENUM64LIST };

// Types of character for URI scanning
enum CharAction { CHAR_NORMAL=2, CHAR_PERCENT, CHAR_PATH, CHAR_INVALID, CHAR_EIGHTBIT };

// Transfer codings
enum Transcoding { TRANSCODE__OTHER=1, TRANSCODE_CHUNKED, TRANSCODE_IDENTITY, TRANSCODE_GZIP,
    TRANSCODE_COMPRESS, TRANSCODE_DEFLATE };

enum EventSid
{
    EVENT_ASCII = 1,
    EVENT_DOUBLE_DECODE,
    EVENT_U_ENCODE,
    EVENT_BARE_BYTE,
    EVENT_OBSOLETE_1,
    EVENT_UTF_8,
    EVENT_IIS_UNICODE,
    EVENT_MULTI_SLASH,
    EVENT_IIS_BACKSLASH,
    EVENT_SELF_DIR_TRAV,
    EVENT_DIR_TRAV,
    EVENT_APACHE_WS,
    EVENT_IIS_DELIMITER,
    EVENT_NON_RFC_CHAR,
    EVENT_OVERSIZE_DIR,
    EVENT_LARGE_CHUNK,
    EVENT_PROXY_USE,
    EVENT_WEBROOT_DIR,
    EVENT_LONG_HDR,
    EVENT_MAX_HEADERS,
    EVENT_MULTIPLE_CONTLEN,
    EVENT_CHUNK_SIZE_MISMATCH,
    EVENT_INVALID_TRUEIP,
    EVENT_MULTIPLE_HOST_HDRS,
    EVENT_LONG_HOSTNAME,
    EVENT_EXCEEDS_SPACES,
    EVENT_CONSECUTIVE_SMALL_CHUNKS,
    EVENT_UNBOUNDED_POST,
    EVENT_MULTIPLE_TRUEIP_IN_SESSION,
    EVENT_BOTH_TRUEIP_XFF_HDRS,
    EVENT_UNKNOWN_METHOD,
    EVENT_SIMPLE_REQUEST,
    EVENT_UNESCAPED_SPACE_URI,
    EVENT_PIPELINE_MAX,
    EVENT_ANOM_SERVER,
    EVENT_INVALID_STATCODE,
    EVENT_NO_CONTLEN,
    EVENT_UTF_NORM_FAIL,
    EVENT_UTF7,
    EVENT_DECOMPR_FAILED,
    EVENT_CONSECUTIVE_SMALL_CHUNKS_S,
    EVENT_MSG_SIZE_EXCEPTION,
    EVENT_JS_OBFUSCATION_EXCD,
    EVENT_JS_EXCESS_WS,
    EVENT_MIXED_ENCODINGS,
    EVENT_SWF_ZLIB_FAILURE,
    EVENT_SWF_LZMA_FAILURE,
    EVENT_PDF_DEFL_FAILURE,
    EVENT_PDF_UNSUP_COMP_TYPE,
    EVENT_PDF_CASC_COMP,
    EVENT_PDF_PARSE_FAILURE,
    EVENT_LOSS_OF_SYNC,
    EVENT_CHUNK_ZEROS,
    EVENT_WS_BETWEEN_MSGS,
    EVENT_URI_MISSING,
    EVENT_CTRL_IN_REASON,
    EVENT_IMPROPER_WS,
    EVENT_BAD_VERS,
    EVENT_UNKNOWN_VERS,
    EVENT_BAD_HEADER,
    EVENT_CHUNK_OPTIONS,
    EVENT_URI_BAD_FORMAT,
    EVENT_URI_BAD_PORT,
    EVENT_BROKEN_CHUNK,
    EVENT_CHUNK_WHITESPACE,
    EVENT__MAX_VALUE
};

extern const int8_t as_hex[256];
extern const bool token_char[256];
extern const bool is_sp_tab[256];
} // end namespace NHttpEnums

#endif

