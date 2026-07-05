#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_STD_PATH_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_STD_PATH_H


#include <wchar.h>

#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Returns the current path.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_current_path();

/**
 * Creates path object from normal string.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_from_char_str(const char* s);

/**
 * Creates path object from wide string.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_from_wchar_str(const wchar_t* s);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* std_Path_del(std_Path obj);

/**
 * Returns internal string as SFML3 sf::String pointer.
 */
SFML_SIMPLE_WRAPPER_API sf_String std_Path_sf_str(std_Path self);

/**
 * Returns path relative to root-path, that is, a pathname
 *composed of every generic-format component of 'self' after root-path.
 * If this is an empty path, returns an empty path.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_relative_path(std_Path self);

/**
 * Returns the path to the parent directory.
 * If has_relative_path() returns 0, the result is a copy of 'self'.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_parent_path(std_Path self);

/**
 * Returns the root name of the generic-format path.
 *If the path (in generic format) does not include root name, returns path().
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_root_name(std_Path self);

/**
 * Returns the root path of the path. If the path does not include root path, returns path().
 * Effectively returns root_name() / root_directory().
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_root_path(std_Path self);

/**
 * Returns the root directory of the generic-format path.
 * If the path (in generic format) does not include root directory, returns path().
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_root_directory(std_Path self);

/**
 * Returns the generic-format filename component of the path.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_filename(std_Path self);

/**
 * Returns the filename identified by the generic-format path stripped of its extension.
 * Returns the substring from the beginning of filename() up to and not including the
 *last period (.) character, with the following exceptions:
 * - If the first character in the filename is a period, that period is ignored
 *(a filename like ".profile" is not treated as an extension);
 * - If the filename is one of the special filesystem components dot or dot-dot,
 *or if it has no periods, the function returns the entire filename().
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_stem(std_Path self);

/**
 * Returns the extension of the filename component of the generic-format view of 'self'.
 * If the filename() component of the generic-format path contains a period (.),
 *and is not one of the special filesystem elements dot or dot-dot, then the extension
 *is the substring beginning at the rightmost period (including the period) and
 *until the end of the pathname.
 * If the first character in the filename is a period, that period is ignored
 *(a filename like ".profile" is not treated as an extension).
 * If the pathname is either . or .., or if filename() does not contain the
 *'.' character, then empty path is returned.
 * Additional behavior may be defined by the implementations for file systems which
 *append additional elements (such as alternate data streams or partitioned dataset names) to extensions.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_extension(std_Path self);

/**
 * Concatenates 'self' with string using OS-dependant separator.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_add(std_Path self, const char* s);

/**
 * Concatenates 'self' with another path using OS-dependant separator.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_Path_add_path(std_Path self, std_Path other);

/**
 * Clears the stored pathname. 'is_empty()' is 1 after the call.
 */
SFML_SIMPLE_WRAPPER_API void std_Path_clear(std_Path self);

/**
 * Removes a single generic-format filename component (as returned by filename) from the given generic-format path.
 * After this function completes, has_filename returns 0.
 */
SFML_SIMPLE_WRAPPER_API void std_Path_remove_filename(std_Path self);

/**
 * Replaces a single filename component with replacement.
 */
SFML_SIMPLE_WRAPPER_API void std_Path_replace_filename(std_Path self, const std_Path replacement);

/**
 * Replaces the extension with replacement or removes it when the default value of replacement is used.
 * Firstly, if this path has an extension(), it is removed from the generic-format view of the pathname.
 * Then, a dot character is appended to the generic-format view of the pathname, if replacement is not empty
 *and does not begin with a dot character.
 */
SFML_SIMPLE_WRAPPER_API void std_Path_replace_extension(std_Path self, const std_Path replacement);

/**
 * Returns 1 if 'self' is empty, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_empty(std_Path self);

/**
 * Returns 1 if 'self' has root path, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_root_path(std_Path self);

/**
 * Returns 1 if 'self' has root name, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_root_name(std_Path self);

/**
 * Returns 1 if 'self' has root directory, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_root_directory(std_Path self);

/**
 * Returns 1 if 'self' has relative path, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_relative_path(std_Path self);

/**
 * Returns 1 if 'self' has filename, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_filename(std_Path self);

/**
 * Returns 1 if 'self' has stem, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_stem(std_Path self);

/**
 * Returns 1 if 'self' has extension, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_has_extension(std_Path self);

/**
 * Returns 1 if path is absolute, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_absolute(std_Path self);

/**
 * Returns 1 if path is not absolute, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_relative(std_Path self);

/**
 * Returns 1 if path exists, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_exists(std_Path self);

/**
 * Returns 1 if path exists and it is a directory, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_directory(std_Path self);

/**
 * Returns 1 if path exists and it is a regular file, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_regular_file(std_Path self);

/**
 * Returns 1 if paths are equal, otherwise 0.
 * Only lexical representations are compared.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_equal(std_Path self, std_Path other);

/**
 * Returns 1 if 'self' is not equal to 'other'.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_ne(std_Path self, std_Path other);

/**
 * Checks whether the paths 'self' and 'other' resolve to the same file system entity.
 * If either 'self' or 'other' does not exist, returns 0.
 * With symlinks may throw C++ exception.
 */
SFML_SIMPLE_WRAPPER_API int std_Path_is_equivalent(std_Path self, std_Path other);


#ifdef __cplusplus
}
#endif


#endif
