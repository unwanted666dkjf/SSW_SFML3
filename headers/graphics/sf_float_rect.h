#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FLOAT_RECT_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FLOAT_RECT_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor.
 * Creates an empty rectangle (it is equivalent to calling `Rect({0, 0}, {0, 0})`).
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_FloatRect_default();

/**
 * Constructs the rectangle from given values.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_FloatRect_init(float left, float top, float width, float height);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_FloatRect_del(sf_FloatRect obj);

/**
 * Get the position(left, top) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_FloatRect_get_lefttop(sf_FloatRect self);

/**
 * Set the position(left, top) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_FloatRect_set_lefttop(sf_FloatRect self, float left, float top);

/**
 * Get the size(width, height) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_FloatRect_get_widthheight(sf_FloatRect self);

/**
 * Set the size(width, height) of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_FloatRect_set_widthheight(sf_FloatRect self, float width, float height);

/**
 * Get the position of the center of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_FloatRect_get_center(sf_FloatRect self);

/**
 * Set the position of the center of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_FloatRect_set_center(sf_FloatRect self, float cx, float cy);

/**
 * Check if a point is inside the rectangle's area.
 * This check is non-inclusive. If the point lies on the
 *edge of the rectangle, this function will return 0.
 * Returns 1 if the point is inside, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_FloatRect_contains(sf_FloatRect self, float x, float y);

/**
 * Returns 1 if the rectangle is empty, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_FloatRect_is_empty(sf_FloatRect self);

/**
 * Check the intersection between two rectangles.
 * In the case of an intersection, the intersection rectangle will
 *be copied to the intersection pointer, otherwise it will be
 *assigned an empty rectangle.
 * Returns intersection pointer.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_FloatRect_intersects(sf_FloatRect self, sf_FloatRect other);

/**
 * Returns 1 if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_FloatRect_is_equal(sf_FloatRect self, sf_FloatRect other);

/**
 * Returns 0 if 'self' is equal to 'other', otherwise 1.
 */
SFML_SIMPLE_WRAPPER_API int sf_FloatRect_is_ne(sf_FloatRect self, sf_FloatRect other);


#ifdef __cplusplus
}
#endif


#endif
