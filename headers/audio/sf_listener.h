#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_LISTENER_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_LISTENER_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Change the global volume of all the sounds and musics
 *`volume` is a number between 0 and 100; it is combined
 *with the individual volume of each sound / music.
 * The default value for the volume is 100 (maximum).
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_global_volume(float volume);

/**
 * Get the current value of the global volume[0, 100]
 */
SFML_SIMPLE_WRAPPER_API float sf_Listener_get_global_volume();

/**
 * Set the position of the listener in the scene.
 * The default listener's position is (0, 0, 0).
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_position(const sf_Vector3f position);

/**
 * Get the current position of the listener in the scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Listener_get_position();

/**
 * Set the forward vector of the listener in the scene.
 * The direction (also called "at vector") is the vector
 *pointing forward from the listener's perspective. Together
 *with the up vector, it defines the 3D orientation of the
 *listener in the scene. The direction vector doesn't
 *have to be normalized.
 * The default listener's direction is (0, 0, -1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_direction(const sf_Vector3f direction);

/**
 * Get the current forward vector of the listener in the scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Listener_get_direction();

/**
 * Set the velocity of the listener in the scene.
 * The default listener's velocity is (0, 0, -1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_velocity(const sf_Vector3f velocity);

/**
 * Get the current forward vector of the listener in the scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Listener_get_velocity();

/**
 * Set the cone properties of the listener in the audio scene.
 * The cone defines how directional attenuation is applied.
 * The default cone of a sound is (2 * PI, 2 * PI, 1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_cone(const sf_Listener_Cone cone);

/**
 * Get the cone properties of the listener in the audio scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Listener_Cone sf_Listener_get_cone();

/**
 * Set the upward vector of the listener in the scene.
 * The up vector is the vector that points upward from the
 *listener's perspective. Together with the direction, it
 *defines the 3D orientation of the listener in the scene.
 * The up vector doesn't have to be normalized.
 * The default listener's up vector is (0, 1, 0). It is usually
 *not necessary to change it, especially in 2D scenarios.
 */
SFML_SIMPLE_WRAPPER_API void sf_Listener_set_up_vector(const sf_Vector3f vec);

/**
 * Get the current upward vector of the listener in the scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Listener_get_up_vector();


#ifdef __cplusplus
}
#endif


#endif
