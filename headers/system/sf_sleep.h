#ifndef SFML_SIMPLE_WRAPPER_SYSTEM_SF_SLEEP_H
#define SFML_SIMPLE_WRAPPER_SYSTEM_SF_SLEEP_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Make the current thread sleep for a given duration.
 * `sf::sleep` is the best way to block a program or one of its threads, as
 *it doesn't consume any CPU power. Compared to the standard `std::this_thread::sleep_for`
 *function, this one provides more accurate sleeping time thanks to some platform-specific
 *tweaks. `sf::sleep` only guarantees millisecond precision. Sleeping for a duration less
 *than 1 millisecond is prone to result in the actual sleep duration being less than what
 *is requested.
 */
SFML_SIMPLE_WRAPPER_API void sf_sleep(sf_Time duration);


#ifdef __cplusplus
}
#endif


#endif
