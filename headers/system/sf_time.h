#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_TIME_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_TIME_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct a time value from a number of seconds.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_from_seconds(float amount);

/**
 * Construct a time value from a number of milliseconds.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_from_milliseconds(long amount);

/**
 * Construct a time value from a number of microseconds.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_from_microseconds(long long amount);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Time_del(sf_Time obj);

/**
 * Return the time value as a number of seconds.
 */
SFML_SIMPLE_WRAPPER_API float sf_Time_as_seconds(sf_Time self);

/**
 * Return the time value as a number of milliseconds.
 */
SFML_SIMPLE_WRAPPER_API long sf_Time_as_milliseconds(sf_Time self);

/**
 * Return the time value as a number of microseconds.
 */
SFML_SIMPLE_WRAPPER_API long long sf_Time_as_microseconds(sf_Time self);

/**
 * Returns 1 if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_equal(sf_Time self, const sf_Time other);

/**
 * Returns 1 if 'self' is greater than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_greater(sf_Time self, const sf_Time other);

/**
 * Returns 1 if 'self' is lesser than 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_lesser(sf_Time self, const sf_Time other);

/**
 * Returns 1 if 'self' is not equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_ne(sf_Time self, const sf_Time other);

/**
 * Returns 1 if 'self' is greater than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_ge(sf_Time self, const sf_Time other);

/**
 * Returns 1 if 'self' is lesser than or equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Time_is_le(sf_Time self, const sf_Time other);

/**
 * Returns the sum of 'self' and 'other'.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_add(sf_Time self, const sf_Time other);

/**
 * Returns the difference between 'self' and 'other'.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_sub(sf_Time self, const sf_Time other);

/**
 * Returns the product of the 'self' and 'other'.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_mul(sf_Time self, const sf_Time other);

/**
 * Returns the quotient of dividing 'self' by 'other'.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_truediv(sf_Time self, const sf_Time other);

/**
 * Returns the remainder of dividing 'self' by 'other'.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Time_mod(sf_Time self, const sf_Time other);


#ifdef __cplusplus
}
#endif


#endif
