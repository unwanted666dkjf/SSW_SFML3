#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_PLAYBACK_DEVICE_GEN_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_PLAYBACK_DEVICE_GEN_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates new generator.
 */
SFML_SIMPLE_WRAPPER_API sf_PlaybackDeviceGen* sf_PlaybackDeviceGen_init();

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_PlaybackDeviceGen_del(sf_PlaybackDeviceGen* obj);

/**
 * Returns 1 if there are std::string left to convert into sf_String.
 * Otherwise, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_PlaybackDeviceGen_has_next(sf_PlaybackDeviceGen* self);

/**
 * Converts next std::string from internal std::vector into sf_String and returns
 *the result.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_PlaybackDeviceGen_next(sf_PlaybackDeviceGen* self);


#ifdef __cplusplus
}
#endif


#endif
