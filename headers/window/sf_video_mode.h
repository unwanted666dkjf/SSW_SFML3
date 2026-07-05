#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_VIDEO_MODE_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_VIDEO_MODE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


// 32
#define SFML_SIMPLE_WRAPPER_sf_VideoMode_DefaultModeBitsPerPixel (32)


/**
 * Returns current desktop video mode.
 */
SFML_SIMPLE_WRAPPER_API sf_VideoMode sf_VideoMode_get_desktop_mode();

/**
 * Construct the video mode with its attributes.
 */
SFML_SIMPLE_WRAPPER_API sf_VideoMode sf_VideoMode_init(
	unsigned int width,
	unsigned int height,
	unsigned int modeBitsPerPixel
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_VideoMode_del(sf_VideoMode obj);

/**
 * Returns 1 if video mode is valid, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_valid(sf_VideoMode self);

/**
 * Returns width.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_VideoMode_width(sf_VideoMode self);

/**
 * Returns height.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_VideoMode_height(sf_VideoMode self);

/**
 * Returns modeBitsPerPixel.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_VideoMode_bits_per_pixel(sf_VideoMode self);

/**
 * Returns 1 if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_equal(sf_VideoMode self, const sf_VideoMode other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_greater(sf_VideoMode self, const sf_VideoMode other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_lesser(sf_VideoMode self, const sf_VideoMode other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_ne(sf_VideoMode self, const sf_VideoMode other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_ge(sf_VideoMode self, const sf_VideoMode other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoMode_is_le(sf_VideoMode self, const sf_VideoMode other);


#ifdef __cplusplus
}
#endif


#endif
