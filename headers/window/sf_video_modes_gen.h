#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_VIDEO_MODES_GEN_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_VIDEO_MODES_GEN_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates generator.
 * Generator stores std::vector of sf::VideoMode to convert.
 */
SFML_SIMPLE_WRAPPER_API sf_VideoModes_Gen* sf_VideoModes_Gen_init();

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_VideoModes_Gen_del(sf_VideoModes_Gen* obj);

/**
 * Returns 1 if there are elements left to
 *convert from sf::VideoMode to sf_VideoMode.
 * Otherwise, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_VideoModes_Gen_has_next(sf_VideoModes_Gen* self);

/**
 * Returns converted sf::VideoMode from internal std::vector.
 */
SFML_SIMPLE_WRAPPER_API sf_VideoMode sf_VideoModes_Gen_next(sf_VideoModes_Gen* self);


#ifdef __cplusplus
}
#endif


#endif
