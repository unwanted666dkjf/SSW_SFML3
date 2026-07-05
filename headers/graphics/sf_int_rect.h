#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_INT_RECT_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_INT_RECT_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor.
 * Creates an empty rectangle (it is equivalent to calling `Rect({0, 0}, {0, 0})`).
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_IntRect_default();

/**
 * Constructs the rectangle from given values.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_IntRect_init(int left, int top, int width, int height);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_IntRect_del(sf_IntRect obj);

/**
 * Get the position(left, top) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_IntRect_get_lefttop(sf_IntRect self);

/**
 * Set the position(left, top) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_IntRect_set_lefttop(sf_IntRect self, int left, int top);

/**
 * Get the size(width, height) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_IntRect_get_widthheight(sf_IntRect self);

/**
 * Set the size(width, height) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_IntRect_set_widthheight(sf_IntRect self, int width, int height);

/**
 * Get the position of the center of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_IntRect_get_center(sf_IntRect self);

/**
 * Set the position of the center of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_IntRect_set_center(sf_IntRect self, int cx, int cy);

/**
 * Check if a point is inside the rectangle's area.
 * This check is non-inclusive. If the point lies on the
 *edge of the rectangle, this function will return 0.
 * Returns 1 if the point is inside, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_IntRect_contains(sf_IntRect self, int x, int y);

/**
 * Returns 1 if the rectangle is empty, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_IntRect_is_empty(sf_IntRect self);

/**
 * Check the intersection between two rectangles.
 * In the case of an intersection, the intersection rectangle will
 *be copied to the intersection pointer, otherwise it will be
 *assigned an empty rectangle.
 * Returns intersection pointer.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_IntRect_intersects(sf_IntRect self, sf_IntRect other);

/**
 * Returns 1 if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_IntRect_is_equal(sf_IntRect self, sf_IntRect other);

/**
 * Returns 0 if 'self' is equal to 'other', otherwise 1.
 */
SFML_SIMPLE_WRAPPER_API int sf_IntRect_is_ne(sf_IntRect self, sf_IntRect other);


#ifdef __cplusplus
}
#endif


#endif
