#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_STRING_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_STRING_H


#include <wchar.h>

#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SFML_SIMPLE_WRAPPER_sf_String_STR_NOT_FOUND (-1)

#define SFML_SIMPLE_WRAPPER_sf_String_INVALID_POS (-1)


/**
 * Construct from a single ANSI character and a locale.
 * The source character is converted to UTF-32 according
 *to the locale.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_from_char(char c);

/**
 * Construct from a single wide character.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_from_wchar(wchar_t c);

/**
 * Construct from a null-terminated C-style ANSI string and a locale.
 * The source character is converted to UTF-32 according
 *to the locale.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_from_str(const char* str_);

/**
 * Construct from null-terminated C-style wide string.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_from_wstr(const wchar_t* str_);

/**
 * Deletes the pointer and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_String_del(sf_String obj);

/**
 * Convert internal string array to ansi string and
 *returns result as ssw_CStrBuf*.
 */
SFML_SIMPLE_WRAPPER_API ssw_CStrBuf* sf_String_to_ansi(sf_String self);

/**
 * Convert internal string array to wide string and
 *returns result as ssw_WCStrBuf*.
 */
SFML_SIMPLE_WRAPPER_API ssw_WCStrBuf* sf_String_to_wide(sf_String self);

/**
 * Returns code of character at given index.
 *Note: the behavior is undefined if `index` is out of range.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_String_get(sf_String self, unsigned long index);

/**
 * This function removes all the characters from the string.
 */
SFML_SIMPLE_WRAPPER_API void sf_String_clear(sf_String self);

/**
 * Returns number of characters in the string.
 */
SFML_SIMPLE_WRAPPER_API unsigned long sf_String_size(sf_String self);

/**
 * Returns 1 if string is empty(i.e. contains no character), otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_empty(sf_String self);

/**
 * This function removes a sequence of `count` characters
 *starting from `position`.
 */
SFML_SIMPLE_WRAPPER_API void sf_String_erase(sf_String self,
	unsigned long position,
	unsigned long count
);

/**
 * This function inserts the characters of `str`
 *into the string, starting from `position`.
 */
SFML_SIMPLE_WRAPPER_API void sf_String_insert(sf_String self,
	unsigned long position,
	const sf_String str_
);

/**
 * This function searches for the characters of `str`
 *in the string, starting from `start`.
 * Returns position of `str` in the string, or sf_String_STR_NOT_FOUND if not found.
 */
SFML_SIMPLE_WRAPPER_API long sf_String_find(sf_String self,
	const sf_String str_,
	unsigned long start
);

/**
 * This function replaces the substring that starts at index `position`
 *and spans `length` characters with the string `replace_with`.
 */
SFML_SIMPLE_WRAPPER_API void sf_String_replace(sf_String self,
	unsigned long position,
	unsigned long length,
	const sf_String replace_with
);

/**
 * This function replaces all occurrences of `search_for` in this string
 *with the string `replace_with`.
 */
SFML_SIMPLE_WRAPPER_API void sf_String_replace_substrings(sf_String self,
	const sf_String search_for,
	const sf_String replace_with
);

/**
 * This function returns the substring that starts at index `position`
 *and spans `length` characters.
 * sf_String_INVALID_POS can be used to include all characters
 *until the end of the string.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_substring(sf_String self,
	unsigned long position,
	unsigned long length
);

/**
 * Concatenates 'self' with 'other' and returns concatenated string.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_String_concat(sf_String self, const sf_String other);

/**
 * Returns 1 if both strings are equal, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_equal(sf_String self, const sf_String other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 * 'self' is greater, if it is lexicographically after 'other'.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_greater(sf_String self, const sf_String other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 * 'self' is lesser, if it is lexicographically before 'other'.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_lesser(sf_String self, const sf_String other);

/**
 * Return 1 if strings are not equal, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_ne(sf_String self, const sf_String other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other'.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_ge(sf_String self, const sf_String other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other'.
 */
SFML_SIMPLE_WRAPPER_API int sf_String_is_le(sf_String self, const sf_String other);


/**
 * Creates and returns ssw_CStrBuf*.
 * Calculates the length itself.
 * Does not copy characters, becomes an owner of the string.
 */
SFML_SIMPLE_WRAPPER_API ssw_CStrBuf* ssw_CStrBuf_cast_char_str(char* str_);

/**
 * Creates and returns ssw_CStrBuf*. Copies characters from 'str_'.
 */
SFML_SIMPLE_WRAPPER_API ssw_CStrBuf* ssw_CStrBuf_init(const char* str_, unsigned long length);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* ssw_CStrBuf_del(ssw_CStrBuf* obj);

/**
 * Returns internal string as immutable object.
 */
SFML_SIMPLE_WRAPPER_API const char* ssw_CStrBuf_str(ssw_CStrBuf* self);

/**
 * Returns length(number of characters) of internal string.
 */
SFML_SIMPLE_WRAPPER_API unsigned long ssw_CStrBuf_length(ssw_CStrBuf* self);


/**
 * Creates and returns ssw_WCStrBuf*.
 * Calculates the length itself.
 * Does not copy characters, becomes an owner of the string.
 */
SFML_SIMPLE_WRAPPER_API ssw_WCStrBuf* ssw_WCStrBuf_cast_wchar_str(wchar_t* str_);

/**
 * Creates and returns ssw_WCStrBuf*. Copies wide characters from 'str_'.
 */
SFML_SIMPLE_WRAPPER_API ssw_WCStrBuf* ssw_WCStrBuf_init(const wchar_t* str_, unsigned long length);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* ssw_WCStrBuf_del(ssw_WCStrBuf* obj);

/**
 * Returns internal string as immutable object.
 */
SFML_SIMPLE_WRAPPER_API const wchar_t* ssw_WCStrBuf_str(ssw_WCStrBuf* self);

/**
 * Returns length(number of characters) of internal string.
 */
SFML_SIMPLE_WRAPPER_API unsigned long ssw_WCStrBuf_length(ssw_WCStrBuf* self);


#ifdef __cplusplus
}
#endif


#endif
