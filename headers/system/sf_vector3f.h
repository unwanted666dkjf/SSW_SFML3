#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR3F_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_VECTOR3F_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the vector from its coordinates.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_init(float x, float y, float z);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Vector3f_del(sf_Vector3f obj);

/**
 * Returns x coordinate.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_get_x(sf_Vector3f self);

/**
 * Sets x coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector3f_set_x(sf_Vector3f self, float x);

/**
 * Returns y coordinate.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_get_y(sf_Vector3f self);

/**
 * Sets y coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector3f_set_y(sf_Vector3f self, float y);

/**
 * Returns z coordinate.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_get_z(sf_Vector3f self);

/**
 * Sets z coordinate.
 */
SFML_SIMPLE_WRAPPER_API void sf_Vector3f_set_z(sf_Vector3f self, float z);

/**
 * Returns length of the vector.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_length(sf_Vector3f self);

/**
 * Returns square of vector's length.
 * Suitable for comparisons, more efficient than `length()`.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_length_squared(sf_Vector3f self);

/**
 * Returns vector with same direction but length 1.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_normalized(sf_Vector3f self);

/**
 * Returns dot product of two 3D vectors.
 */
SFML_SIMPLE_WRAPPER_API float sf_Vector3f_dot(sf_Vector3f self, sf_Vector3f rhs);

/**
 * Returns cross product of two 3D vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_cross(sf_Vector3f self, sf_Vector3f rhs);

/**
 * Component-wise multiplication of `self` and `rhs`.
 * Computes `(lhs.x*rhs.x, lhs.y*rhs.y, lhs.z*rhs.z)`.
 * Scaling is the most common use case for component-wise multiplication/division.
 * This operation is also known as the Hadamard or Schur product.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_component_wise_mul(sf_Vector3f self, sf_Vector3f rhs);

/**
 * Component-wise division of `self` and `rhs`.
 * Computes `(lhs.x/rhs.x, lhs.y/rhs.y, lhs.z/rhs.z)`.
 * Neither component of `rhs` is zero.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_component_wise_div(sf_Vector3f self, sf_Vector3f rhs);

/**
 * Returns 1 if both vectors are equal, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_equal(sf_Vector3f self, sf_Vector3f other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_greater(sf_Vector3f self, sf_Vector3f other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 * Uses 'length_squared' for comparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_lesser(sf_Vector3f self, sf_Vector3f other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_ne(sf_Vector3f self, sf_Vector3f other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_ge(sf_Vector3f self, sf_Vector3f other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Vector3f_is_le(sf_Vector3f self, sf_Vector3f other);

/**
 * This function performs a member-wise subtraction of both vectors.
 * Returns member-wise subtraction of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_sub(sf_Vector3f self, sf_Vector3f other);

/**
 * This function performs a member-wise addition of both vectors.
 * Returns member-wise addition of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_add(sf_Vector3f self, sf_Vector3f other);

/**
 * This function performs a member-wise multiplication of both vectors.
 * Returns member-wise multiplication of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_mul(sf_Vector3f self, sf_Vector3f other);

/**
 * This function performs a member-wise division of both vectors.
 * Returns member-wise division of both vectors.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Vector3f_truediv(sf_Vector3f self, sf_Vector3f other);


#ifdef __cplusplus
}
#endif


#endif
