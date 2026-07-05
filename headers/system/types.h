#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_TYPES_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_TYPES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct SFML_SIMPLE_WRAPPER_API ssw_CStrBuf;

struct SFML_SIMPLE_WRAPPER_API ssw_WCStrBuf;

struct SFML_SIMPLE_WRAPPER_API std_WalkGen;

struct SFML_SIMPLE_WRAPPER_API std_WalkGenRecurse;


/**
 * Buffer class for char* string,
 *contains array of characters and it's length.
 */
typedef struct ssw_CStrBuf ssw_CStrBuf;

/**
 * Buffer class for wchar_t* string,
 *contains array of wide characters and it's length.
 */
typedef struct ssw_WCStrBuf ssw_WCStrBuf;


/**
 * Generator.
 * Wrapper for std::filesystem::directory_iterator.
 * LegacyInputIterator that iterates over the directory_entry elements of
 *a directory (but does not visit the subdirectories). The iteration order
 *is unspecified, except that each directory entry is visited only once.
 *The special pathnames dot and dot-dot are skipped.
 */
typedef struct std_WalkGen std_WalkGen;


/**
 * Generator.
 * Wrapper for std::filesystem::recursive_directory_iterator.
 * LegacyInputIterator that iterates over the directory_entry elements of
 *a directory, and, recursively, over the entries of all subdirectories.
 *The iteration order is unspecified, except that each directory entry is
 *visited only once.
 * By default, symlinks are not followed, but this can be enabled by
 *specifying the directory option follow_directory_symlink at construction time.
 */
typedef struct std_WalkGenRecurse std_WalkGenRecurse;


/**
 * Opaque type for sf::Angle.
 */
typedef void* sf_Angle;


/**
 * Opaque type for sf::Time.
 */
typedef void* sf_Time;


/**
 * Opaque type for sf::Clock.
 */
typedef void* sf_Clock;


/**
 * Opaque type for sf::String*.
 * sf::String is utility string class that automatically handles
 *conversions between types and encodings.
 */
typedef void* sf_String;


/**
 * Opaque type for std::filesystem::path.
 * Incomplete wrapper, just to use with sf::Texture and others.
 * Objects of type path represent paths on a filesystem.
 * Only syntactic aspects of paths are handled: the pathname may represent
 *a non existing path or even one that is not allowed to exist on the
 *current file system or OS.
 */
typedef void* std_Path;


/**
 * Opaque type for sf::Vector3f.
 */
typedef void* sf_Vector3f;


/**
 * Opaque type for sf::Vector2f.
 */
typedef void* sf_Vector2f;


/**
 * Opaque type for sf::Vector2i.
 */
typedef void* sf_Vector2i;


/**
 * Opaque type for sf::Vector2u.
 */
typedef void* sf_Vector2u;


#ifdef __cplusplus
}
#endif


#endif
