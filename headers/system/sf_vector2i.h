#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR2I_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR2I_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the vector from cartesian coordinates.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_init(int x, int y);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Vector2i_del(sf_Vector2i obj);

/**
 * Returns x coordinate.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_get_x(sf_Vector2i self);

/**
 * Sets x coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector2i_set_x(sf_Vector2i self, int x);

/**
 * Returns y coordinate.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_get_y(sf_Vector2i self);

/**
 * Sets y coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector2i_set_y(sf_Vector2i self, int y);

/**
 * Returns length of the vector.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2i_length(sf_Vector2i self);

/**
 * Returns square of vector's length.
 * Suitable for comparisons, more efficient than `length()`.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2i_length_squared(sf_Vector2i self);

/**
 * Returns a perpendicular vector.
 * Returns `self` rotated by +90 degrees; (x,y) becomes (-y,x).
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_perpendicular(sf_Vector2i self);

/**
 * Returns dot product of two 2D vectors.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_dot(sf_Vector2i self, sf_Vector2i rhs);

/**
 * Returns Z component of the cross product of two 2D vectors.
 * Treats the operands as 3D vectors, computes their cross product
 *and returns the result's Z component (X and Y components are always zero).
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_cross(sf_Vector2i self, sf_Vector2i rhs);

/**
 * Component-wise multiplication of `self` and `rhs`.
 * Computes `(lhs.x*rhs.x, lhs.y*rhs.y)`.
 * Scaling is the most common use case for component-wise multiplication/division.
 * This operation is also known as the Hadamard or Schur product.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_component_wise_mul(sf_Vector2i self, sf_Vector2i rhs);

/**
 * Component-wise division of `self` and `rhs`.
 * Computes `(lhs.x/rhs.x, lhs.y/rhs.y)`.
 * Neither component of `rhs` is zero.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_component_wise_div(sf_Vector2i self, sf_Vector2i rhs);

/**
 * Returns 1 if both vectors are equal, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_equal(sf_Vector2i self, sf_Vector2i other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_greater(sf_Vector2i self, sf_Vector2i other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_lesser(sf_Vector2i self, sf_Vector2i other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_ne(sf_Vector2i self, sf_Vector2i other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_ge(sf_Vector2i self, sf_Vector2i other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2i_is_le(sf_Vector2i self, sf_Vector2i other);

/**
 * This function performs a member-wise subtraction of both vectors.
 * Returns member-wise subtraction of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_sub(sf_Vector2i self, sf_Vector2i other);

/**
 * This function performs a member-wise addition of both vectors.
 * Returns member-wise addition of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_add(sf_Vector2i self, sf_Vector2i other);

/**
 * This function performs a member-wise multiplication of both vectors.
 * Returns member-wise multiplication of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_mul(sf_Vector2i self, sf_Vector2i other);

/**
 * This function performs a member-wise division of both vectors.
 * Returns member-wise division of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Vector2i_truediv(sf_Vector2i self, sf_Vector2i other);


#ifdef __cplusplus
}
#endif


#endif
