#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_ANGLE_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_ANGLE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct an angle value from a number of degrees.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_from_degrees(float angle);

/**
 * Construct an angle value from a number of radians.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_from_radians(float angle);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Angle_del(sf_Angle obj);

/**
 * Return the angle's value in degrees.
 */
SFML_SIMPLE_WRAPPER_API float sf_Angle_as_degrees(sf_Angle self);

/**
 * Return the angle's value in radians.
 */
SFML_SIMPLE_WRAPPER_API float sf_Angle_as_radians(sf_Angle self);

/**
 * Wrap to a range such that -180° <= angle < 180°.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_wrap_signed(sf_Angle self);

/**
 * Wrap to a range such that 0° <= angle < 360°.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_wrap_unsigned(sf_Angle self);

/**
 * Returns 1 if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_equal(sf_Angle self, const sf_Angle other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_greater(sf_Angle self, const sf_Angle other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_lesser(sf_Angle self, const sf_Angle other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_ne(sf_Angle self, const sf_Angle other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_ge(sf_Angle self, const sf_Angle other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Angle_is_le(sf_Angle self, const sf_Angle other);

/**
 * Returns the difference between 'self' and 'other' angles.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_sub(sf_Angle self, const sf_Angle other);

/**
 * Returns the sum of 'self' and 'other' angles.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_add(sf_Angle self, const sf_Angle other);

/**
 * Returns the product of the 'self' and 'other' angles.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_mul(sf_Angle self, const sf_Angle other);

/**
 * Returns the quotient of dividing the 'self' and 'other' angles.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_truediv(sf_Angle self, const sf_Angle other);

/**
 * Returns the remainder of dividing the 'self' angle by the 'other' angle.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Angle_mod(sf_Angle self, const sf_Angle other);


#ifdef __cplusplus
}
#endif


#endif
