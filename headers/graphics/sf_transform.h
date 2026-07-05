#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TRANSFORM_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TRANSFORM_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates an identity transform (a transform that does nothing).
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Transform_default();

/**
 * Construct a transform from a 3x3 matrix
 * \param a00 Element (0, 0) of the matrix
 * \param a01 Element (0, 1) of the matrix
 * \param a02 Element (0, 2) of the matrix
 * \param a10 Element (1, 0) of the matrix
 * \param a11 Element (1, 1) of the matrix
 * \param a12 Element (1, 2) of the matrix
 * \param a20 Element (2, 0) of the matrix
 * \param a21 Element (2, 1) of the matrix
 * \param a22 Element (2, 2) of the matrix
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Transform_init(
	float a00, float a01, float a02,
	float a10, float a11, float a12,
	float a20, float a21, float a22
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Transform_del(sf_Transform obj);

/**
 * Return the transform as a 4x4 matrix
 *                                *
 * This function returns a pointer to an array of 16 floats
 *containing the transform elements as a 4x4 matrix, which
 *is directly compatible with OpenGL functions.
 *
 * \code
 * sf::Transform transform = ...;
 * glLoadMatrixf(transform.getMatrix());
 * \endcode
 *
 * \return Pointer to a 4x4 matrix
 */
SFML_SIMPLE_WRAPPER_API const float* sf_Transform_get_matrix(sf_Transform self);

/**
 * Return the inverse of the transform
 * If the inverse cannot be computed, an identity transform
 *is returned.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Transform_get_inverse(sf_Transform self);

/**
 * Transform a 2D point(x, y).
 * These two statements are equivalent:
 * \code
 * sf::Vector2f transformedPoint = matrix.transformPoint(point);
 * sf::Vector2f transformedPoint = matrix * point;
 * \endcode
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Transform_transform_point(sf_Transform self, float x, float y);

/**
 * Transform a rectangle
 * Since SFML doesn't provide support for oriented rectangles,
 *the result of this function is always an axis-aligned
 *rectangle. Which means that if the transform contains a
 *rotation, the bounding rectangle of the transformed rectangle
 *is returned.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Transform_transform_rect(sf_Transform self, const sf_FloatRect rect);

/**
 * Combine the current transform with another one
 * The result is a transform that is equivalent to applying
 *`transform` followed by `*this`. Mathematically, it is
 *equivalent to a matrix multiplication `(*this) * transform`.
 *
 * These two statements are equivalent:
 * \code
 * left.combine(right);
 * left *= right;
 * \endcode
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_combine(sf_Transform self, const sf_Transform transform);

/**
 * Combine the current transform with a translation.
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_translate(sf_Transform self, float dx, float dy);

/**
 * Combine the current transform with a rotation.
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_rotate(sf_Transform self, sf_Angle angle);

/**
 * Combine the current transform with a rotation.
 * The center of rotation is provided for convenience as a second
 *argument, so that you can build rotations around arbitrary points
 *more easily (and efficiently) than the usual
 *`translate(-center).rotate(angle).translate(center)`.
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_rotate_center(sf_Transform self, sf_Angle angle, float cx, float cy);

/**
 * Combine the current transform with a scaling.
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_scale(sf_Transform self, float kx, float ky);

/**
 * Combine the current transform with a scaling.
 * The center of scaling is provided for convenience as a second
 *argument, so that you can build scaling around arbitrary points
 *more easily (and efficiently) than the usual
 *`translate(-center).scale(factors).translate(center)`.
 */
SFML_SIMPLE_WRAPPER_API void sf_Transform_scale_center(sf_Transform self,
	float kx, float ky,
	float cx, float cy
);

/**
 * 0 if the transforms are not equal, 1 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Transform_is_equal(sf_Transform self, const sf_Transform other);

/**
 * 1 if the transforms are not equal, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Transform_is_ne(sf_Transform self, const sf_Transform other);

/**
 * This is equivalent of sf_Transform_combine. Although it's slower.
 * Returns new combined transform.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Transform_mul(sf_Transform self, const sf_Transform other);

/**
 * This is equivalent of sf_Transform_transform_point.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Transform_mul_vector(sf_Transform self, sf_Vector2f vector);


#ifdef __cplusplus
}
#endif


#endif
