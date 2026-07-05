#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR2F_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR2F_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the vector from polar coordinates.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_create_polar(float r, sf_Angle phi);

/**
 * Construct the vector from cartesian coordinates.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_init(float x, float y);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Vector2f_del(sf_Vector2f obj);

/**
 * Returns x coordinate.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_get_x(sf_Vector2f self);

/**
 * Sets x coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector2f_set_x(sf_Vector2f self, float x);

/**
 * Returns y coordinate.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_get_y(sf_Vector2f self);

/**
 * Sets y coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector2f_set_y(sf_Vector2f self, float y);

/**
 * Returns length of the vector.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_length(sf_Vector2f self);

/**
 * Returns square of vector's length.
 * Suitable for comparisons, more efficient than `length()`.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_length_squared(sf_Vector2f self);

/**
 * Returns vector with same direction but length 1.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_normalized(sf_Vector2f self);

/**
 * Returns signed angle from `self` to `rhs`.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Vector2f_angle_to(sf_Vector2f self, sf_Vector2f rhs);

/**
 * Returns signed angle from +X or (1,0) vector.
 * For example, the vector (1,0) corresponds to 0 degrees, (0,1) corresponds to 90 degrees.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Vector2f_angle(sf_Vector2f self);

/**
 * Rotate by angle.
 * Returns a vector with same length but different direction.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_rotated_by(sf_Vector2f self, sf_Angle phi);

/**
 * Projection of this vector onto `axis`.
 * Returns vector being projected onto. Need not be normalized.
 * `axis` must not have length zero.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_projected_onto(sf_Vector2f self, sf_Vector2f axis);

/**
 * Returns a perpendicular vector.
 * Returns `self` rotated by +90 degrees; (x,y) becomes (-y,x).
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_perpendicular(sf_Vector2f self);

/**
 * Returns dot product of two 2D vectors.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_dot(sf_Vector2f self, sf_Vector2f rhs);

/**
 * Returns Z component of the cross product of two 2D vectors.
 * Treats the operands as 3D vectors, computes their cross product
 *and returns the result's Z component (X and Y components are always zero).
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector2f_cross(sf_Vector2f self, sf_Vector2f rhs);

/**
 * Component-wise multiplication of `self` and `rhs`.
 * Computes `(lhs.x*rhs.x, lhs.y*rhs.y)`.
 * Scaling is the most common use case for component-wise multiplication/division.
 * This operation is also known as the Hadamard or Schur product.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_component_wise_mul(sf_Vector2f self, sf_Vector2f rhs);

/**
 * Component-wise division of `self` and `rhs`.
 * Computes `(lhs.x/rhs.x, lhs.y/rhs.y)`.
 * Neither component of `rhs` is zero.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_component_wise_div(sf_Vector2f self, sf_Vector2f rhs);

/**
 * Returns 1 if both vectors are equal, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_equal(sf_Vector2f self, sf_Vector2f other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_greater(sf_Vector2f self, sf_Vector2f other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_lesser(sf_Vector2f self, sf_Vector2f other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_ne(sf_Vector2f self, sf_Vector2f other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_ge(sf_Vector2f self, sf_Vector2f other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector2f_is_le(sf_Vector2f self, sf_Vector2f other);

/**
 * This function performs a member-wise subtraction of both vectors.
 * Returns member-wise subtraction of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_sub(sf_Vector2f self, sf_Vector2f other);

/**
 * This function performs a member-wise addition of both vectors.
 * Returns member-wise addition of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_add(sf_Vector2f self, sf_Vector2f other);

/**
 * This function performs a member-wise multiplication of both vectors.
 * Returns member-wise multiplication of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_mul(sf_Vector2f self, sf_Vector2f other);

/**
 * This function performs a member-wise division of both vectors.
 * Returns member-wise division of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Vector2f_truediv(sf_Vector2f self, sf_Vector2f other);


#ifdef __cplusplus
}
#endif


#endif
