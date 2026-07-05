#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_SOURCE_CONE_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_SOURCE_CONE_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Create new sf_SoundSource_Cone from given values.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundSource_Cone sf_SoundSource_Cone_init(
	sf_Angle inner_angle,
	sf_Angle outer_angle,
	float outer_gain
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_SoundSource_Cone_del(sf_SoundSource_Cone obj);

/**
 * Returns copy of inner angle.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_SoundSource_Cone_get_inner_angle(sf_SoundSource_Cone self);

/**
 * Returns copy of outer angle.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_SoundSource_Cone_get_outer_angle(sf_SoundSource_Cone self);

/**
 * Returns outer gain.
 */
SFML_SIMPLE_WRAPPER_API float sf_SoundSource_Cone_get_outer_gain(sf_SoundSource_Cone self);


#ifdef __cplusplus
}
#endif


#endif
