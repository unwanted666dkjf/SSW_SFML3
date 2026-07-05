#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_USEFUL_FUNCS_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_USEFUL_FUNCS_H


#include "./types.h"

#include "../system/types.h"



#ifdef __cplusplus
extern "C" {
#endif


#define SIMPLE_SFML_WRAPPER_PI 3.14159265358979323846f


/**
 * Places a window on top of other windows and gives it focus.
 * Returns 1 if it succeeds and 0 if it fails.
 * Windows-only, on Linux always returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_set_wnd_topmost(sf_RenderWindow wnd);

/**
 * Changes the transparency of the whole window. 0 (fully transparent) to 255 (opaque).
 * Returns 1 if it succeeds and 0 if it fails.
 * Windows-only, on Linux always returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_set_wnd_alpha(sf_RenderWindow wnd, unsigned char alpha);

/**
 * Changes the transparency of a specific color on the window. 0 (fully transparent) to 255 (opaque).
 * Returns 1 if it succeeds and 0 if it fails.
 * Windows-only, on Linux always returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_make_wnd_clr_transparent(sf_RenderWindow wnd, sf_Color clr);

/**
 * Checks whether the rectangle is in view(shown area of the screen) or not.
 * Returns 1 if the area defined by the rectangle can be shown on the screen,
 *otherwise returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_is_frect_on_screen(sf_FloatRect rect, sf_RenderWindow wnd);

/**
 * Converts radians to degrees.
 */
SFML_SIMPLE_WRAPPER_API float ssw_radians_to_degrees(float radians);

/**
 * Converts degrees to radians.
 */
SFML_SIMPLE_WRAPPER_API float ssw_degrees_to_radians(float degrees);

/**
 * Decomposes a value along axes in a 2D coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f ssw_get_offset_with_angle(float value, sf_Angle angle);

/**
 * Calculates the new position of the top-left corner so that the 'rect' is in the 'rect_area' zone.
 * Returns a new position in a two-dimensional coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f ssw_keep_frect_on_area(sf_FloatRect rect, sf_FloatRect rect_area);

/**
 * Flips the sprite about the oX and oY axes, keeping it in its current position.
 * if 'flip_x' and 'flip_y' are 0, does nothing.
 * If 'global_coords' is not equal to 0, use 'getGlobalBounds()' to define
 *the coordinates, otherwise 'getLocalBounds()'.
 */
SFML_SIMPLE_WRAPPER_API void ssw_flip_sprite(sf_Sprite sprite, int flip_x, int flip_y, int global_coords);

/**
 * Returns the coefficients to get from current sizes new.
 * If 'current_width' or 'current_height' is 0, returns the default coefficients(1., 1.).
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f ssw_get_new_scale(
	float new_width, 	 float new_height,
	float current_width, float current_height,
	int   keep_width,	 int   keep_height
);


#ifdef __cplusplus
}
#endif


#endif
