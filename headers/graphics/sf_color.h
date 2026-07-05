#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_COLOR_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_COLOR_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the color from 32-bit unsigned integer.
 * Note: number treats as containing the RGBA components (in that order).
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_from_integer(unsigned int color);

/**
 * Creates sf::Color with given rgb and default alpha.
 * Default alpha is 255.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_from_rgb(
	unsigned char red,
	unsigned char green,
	unsigned char blue
);

/**
 * Creates sf::Color with given rgba.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_from_rgba(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Color_del(sf_Color obj);

/**
 * Returns the color as a 32-bit unsigned integer.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Color_to_integer(sf_Color self);

/**
 * Returns 'red' component of the color.
 */
SFML_SIMPLE_WRAPPER_API unsigned char sf_Color_get_red(sf_Color self);

/**
 * Returns 'green' component of the color.
 */
SFML_SIMPLE_WRAPPER_API unsigned char sf_Color_get_green(sf_Color self);

/**
 * Returns 'blue' component of the color.
 */
SFML_SIMPLE_WRAPPER_API unsigned char sf_Color_get_blue(sf_Color self);

/**
 * Returns 'alpha' component of the color.
 */
SFML_SIMPLE_WRAPPER_API unsigned char sf_Color_get_alpha(sf_Color self);

/**
 * Returns 1 if colors are equal, 0 if they are different.
 */
SFML_SIMPLE_WRAPPER_API int sf_Color_is_equal(sf_Color self, sf_Color other);

/**
 * Returns 0 if colors are equal, 1 if they are different.
 */
SFML_SIMPLE_WRAPPER_API int sf_Color_is_ne(sf_Color self, sf_Color other);

/**
 * This function returns the component-wise sum of two colors.
 * Components that exceed 255 are clamped to 255.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_add(sf_Color self, sf_Color other);

/**
 * This function returns the component-wise subtraction of two colors.
 * Components below 0 are clamped to 0.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_sub(sf_Color self, sf_Color other);

/**
 * This operator returns the component-wise multiplication
 *(also called "modulation") of two colors. Components are then
 *divided by 255 so that the result is still in the range [0, 255].
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Color_mul(sf_Color self, sf_Color other);


#ifdef __cplusplus
}
#endif


#endif
