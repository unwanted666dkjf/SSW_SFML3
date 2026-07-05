#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_CLOCK_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_CLOCK_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates and returns new clock.
 * Clock is stopped by default.
 */
SFML_SIMPLE_WRAPPER_API sf_Clock sf_Clock_init();

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Clock_del(sf_Clock obj);

/**
 * This function returns the time elapsed since the last call to `restart()`
 *(or the construction of the instance if `restart()` has not been called).
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Clock_get_elapsed_time(sf_Clock self);

/**
 * Returns 1 if the clock is running, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Clock_is_running(sf_Clock self);

/**
 * Start the clock.
 */
SFML_SIMPLE_WRAPPER_API void sf_Clock_start(sf_Clock self);

/**
 * Stop the clock.
 */
SFML_SIMPLE_WRAPPER_API void sf_Clock_stop(sf_Clock self);

/**
 * This function puts the time counter back to zero, returns the
 *elapsed time, and leaves the clock in a running state.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Clock_restart(sf_Clock self);

/**
 * This function puts the time counter back to zero, returns the
 *elapsed time, and leaves the clock in a paused state.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Clock_reset(sf_Clock self);


#ifdef __cplusplus
}
#endif


#endif
