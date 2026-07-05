#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_LISTENER_CONE_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_LISTENER_CONE_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Create new sf_Listener_Cone from given values.
 */
SFML_SIMPLE_WRAPPER_API sf_Listener_Cone sf_Listener_Cone_init(
	sf_Angle inner_angle,
	sf_Angle outer_angle,
	float outer_gain
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Listener_Cone_del(sf_Listener_Cone obj);

/**
 * Returns copy of inner angle.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Listener_Cone_get_inner_angle(sf_Listener_Cone self);

/**
 * Returns copy of outer angle.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Listener_Cone_get_outer_angle(sf_Listener_Cone self);

/**
 * Returns outer gain.
 */
SFML_SIMPLE_WRAPPER_API float sf_Listener_Cone_get_outer_gain(sf_Listener_Cone self);


#ifdef __cplusplus
}
#endif


#endif
