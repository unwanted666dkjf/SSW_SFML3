#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_RECORDER_GEN_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_RECORDER_GEN_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates new generator.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundRecorderGen* sf_SoundRecorderGen_init();

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_SoundRecorderGen_del(sf_SoundRecorderGen* obj);

/**
 * Returns 1 if there are elements left to
 *convert from std::string to sf_String.
 * Otherwise, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundRecorderGen_has_next(sf_SoundRecorderGen* self);

/**
 * Converts next element in internal std::vector<std::string> and returns result.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_SoundRecorderGen_next(sf_SoundRecorderGen* self);


#ifdef __cplusplus
}
#endif


#endif
