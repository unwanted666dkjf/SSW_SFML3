#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_STD_WALK_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_STD_WALK_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Constructs new iterator.
 * If 'follow_symlinks' is not 0, follow directory symlinks. Otherwise, skips.
 * If 'skip_permission_denied' is not 0, skips directories that would otherwise
 *result in “permission denied” errors.
 */
SFML_SIMPLE_WRAPPER_API std_WalkGen* std_WalkGen_init(
	const std_Path start_dir,
	int follow_symlinks,
	int skip_permission_denied
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* std_WalkGen_del(std_WalkGen* obj);

/**
 * Returns 0 if iterator reached the end, 1 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int std_WalkGen_has_next(std_WalkGen* self);

/**
 * Returns next path.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_WalkGen_next(std_WalkGen* self);


/**
 * Constructs new iterator.
 * If 'follow_symlinks' is not 0, follow directory symlinks. Otherwise, skips.
 * If 'skip_permission_denied' is not 0, skips directories that would otherwise
 *result in “permission denied” errors.
 */
SFML_SIMPLE_WRAPPER_API std_WalkGenRecurse* std_WalkGenRecurse_init(
	const std_Path start_dir,
	int follow_symlinks,
	int skip_permission_denied
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* std_WalkGenRecurse_del(std_WalkGenRecurse* obj);

/**
 * Returns 0 if iterator reached the end, 1 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int std_WalkGenRecurse_has_next(std_WalkGenRecurse* self);

/**
 * Returns next path.
 */
SFML_SIMPLE_WRAPPER_API std_Path std_WalkGenRecurse_next(std_WalkGenRecurse* self);


#ifdef __cplusplus
}
#endif


#endif
