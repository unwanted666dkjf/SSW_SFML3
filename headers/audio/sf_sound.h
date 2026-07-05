#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the sound with a buffer.
 */
SFML_SIMPLE_WRAPPER_API sf_Sound sf_Sound_init(const sf_SoundBuffer buffer);

/**
 * Deletes object and returns NULL.
 * Stops itself.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Sound_del(sf_Sound obj);

/**
 * Start or resume playing the sound source.
 * This function starts the source if it was stopped, resumes
 *it if it was paused, and restarts it from the beginning if
 *it was already playing.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_play(sf_Sound self);

/**
 * Pause the sound source.
 * This function pauses the source if it was playing,
 *otherwise (source already paused or stopped) it has no effect.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_pause(sf_Sound self);

/**
 * Stop playing the sound source.
 * This function stops the source if it was playing or paused,
 *and does nothing if it was already stopped.
 * It also resets the playing position (unlike `pause()`).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_stop(sf_Sound self);

/**
 * Set whether or not the sound should loop after reaching the end.
 * If set, the sound will restart from beginning after
 *reaching the end and so on, until it is stopped or
 *`setLooping(false)` is called.
 * The default looping state for sound is `false`.
 * 1 to play in loop, 0 to play once.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_is_loop(sf_Sound self, int is_loop);

/**
 * Change the current playing position of the sound.
 * The playing position can be changed when the sound is
 *either paused or playing. Changing the playing position
 *when the sound is stopped has no effect, since playing
 *the sound will reset its position.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_playing_offset(sf_Sound self, sf_Time offset);

/**
 * Get the current playing position of the sound.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_Sound_get_playing_offset(sf_Sound self);

/**
 * Tell whether or not the sound is in loop mode.
 * 1 if the sound is looping, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Sound_get_is_loop(sf_Sound self);

/**
 * Get the current status of the sound (stopped, paused, playing).
 */
SFML_SIMPLE_WRAPPER_API int sf_Sound_get_status(sf_Sound self);

/**
 * Set the pitch of the sound.
 * The pitch represents the perceived fundamental frequency
 *of a sound; thus you can make a sound more acute or grave
 *by changing its pitch. A side effect of changing the pitch
 *is to modify the playing speed of the sound as well.
 * The default value for the pitch is 1.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_pitch(sf_Sound self, float pitch);

/**
 * Set the pan[-1, +1] of the sound.
 * Using panning, a mono sound can be panned between
 *stereo channels. When the pan is set to -1, the sound
 *is played only on the left channel, when the pan is set
 *to +1, the sound is played only on the right channel.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_pan(sf_Sound self, float pan);

/**
 * Set the volume of the sound.
 * The volume is a value between 0 (mute) and 100 (full volume).
 * The default value for the volume is 100.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_volume(sf_Sound self, float volume);

/**
 * Set whether spatialization of the sound is enabled.
 * Spatialization is the application of various effects to
 *simulate a sound being emitted at a virtual position in
 *3D space and exhibiting various physical phenomena such as
 *directional attenuation and doppler shift.
 * 1 to enable spatialization, 0 to disable.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_is_spatialization_enabled(sf_Sound self, int is_enabled);

/**
 * Set the 3D position of the sound in the audio scene.
 * Only sounds with one channel (mono sounds) can be
 *spatialized.
 * The default position of a sound is (0, 0, 0).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_position(sf_Sound self, const sf_Vector3f position);

/**
 * Set the 3D direction of the sound in the audio scene.
 * The direction defines where the sound source is facing
 *in 3D space. It will affect how the sound is attenuated
 *if facing away from the listener.
 * The default direction of a sound is (0, 0, -1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_direction(sf_Sound self, const sf_Vector3f direction);

/**
 * Set the cone properties of the sound in the audio scene.
 * The cone defines how directional attenuation is applied.
 * The default cone of a sound is (2 * PI, 2 * PI, 1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_cone(sf_Sound self, const sf_SoundSource_Cone cone);

/**
 * Set the 3D velocity of the sound in the audio scene.
 * The velocity is used to determine how to doppler shift
 *the sound. Sounds moving towards the listener will be
 *perceived to have a higher pitch and sounds moving away
 *from the listener will be perceived to have a lower pitch.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_velocity(sf_Sound self, const sf_Vector3f velocity);

/**
 * Set the doppler factor of the sound.
 * The doppler factor determines how strong the doppler shift will be.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_doppler_factor(sf_Sound self, float factor);

/**
 * Set the directional attenuation factor of the sound.
 * Depending on the virtual position of an output channel
 *relative to the listener (such as in surround sound
 *setups), sounds will be attenuated when emitting them
 *from certain channels. This factor determines how strong
 *the attenuation based on output channel position
 *relative to the listener is.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_directional_attenuation_factor(sf_Sound self, float factor);

/**
 * Make the sound's position relative to the listener or absolute.
 * Making a sound relative to the listener will ensure that it will always
 *be played the same way regardless of the position of the listener.
 *This can be useful for non-spatialized sounds, sounds that are
 *produced by the listener, or sounds attached to it.
 * The default value is 0 (position is absolute).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_is_relative_to_listener(sf_Sound self, int is_relative);

/**
 * Set the minimum distance of the sound.
 * The "minimum distance" of a sound is the maximum
 *distance at which it is heard at its maximum volume. Further
 *than the minimum distance, it will start to fade out according
 *to its attenuation factor. A value of 0 ("inside the head
 *of the listener") is an invalid value and is forbidden.
 * The default value of the minimum distance is 1.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_min_distance(sf_Sound self, float distance);

/**
 * Set the maximum distance of the sound.
 * The "maximum distance" of a sound is the minimum
 *distance at which it is heard at its minimum volume. Closer
 *than the maximum distance, it will start to fade in according
 *to its attenuation factor.
 * The default value of the maximum distance is the maximum
 *value a float can represent.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_max_distance(sf_Sound self, float distance);

/**
 * Set the minimum gain of the sound.
 * When the sound is further away from the listener than
 *the "maximum distance" the attenuated gain is clamped
 *so it cannot go below the minimum gain value.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_min_gain(sf_Sound self, float gain);

/**
 * Set the maximum gain of the sound.
 * When the sound is closer from the listener than
 *the "minimum distance" the attenuated gain is clamped
 *so it cannot go above the maximum gain value.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_max_gain(sf_Sound self, float gain);

/**
 * Set the attenuation factor of the sound.
 * The attenuation is a multiplicative factor which makes
 *the sound more or less loud according to its distance
 *from the listener. An attenuation of 0 will produce a
 *non-attenuated sound, i.e. its volume will always be the same
 *whether it is heard from near or from far. On the other hand,
 *an attenuation value such as 100 will make the sound fade out
 *very quickly as it gets further from the listener.
 * The default value of the attenuation is 1.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sound_set_attenuation(sf_Sound self, float attenuation);

/**
 * Get the pitch of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_pitch(sf_Sound self);

/**
 * Get the pan of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_pan(sf_Sound self);

/**
 * Get the volume of the sound[0, 100]
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_volume(sf_Sound self);

/**
 * Tell whether spatialization of the sound is enabled.
 * 1 if spatialization is enabled, 0 if it's disabled.
 */
SFML_SIMPLE_WRAPPER_API int sf_Sound_get_is_spatialization_enabled(sf_Sound self);

/**
 * Get the 3D position of the sound in the audio scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Sound_get_position(sf_Sound self);

/**
 * Get the 3D direction of the sound in the audio scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Sound_get_direction(sf_Sound self);

/**
 * Get the cone properties of the sound in the audio scene.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundSource_Cone sf_Sound_get_cone(sf_Sound self);

/**
 * Get the 3D velocity of the sound in the audio scene.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector3f sf_Sound_get_velocity(sf_Sound self);

/**
 * Get the doppler factor of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_doppler_factor(sf_Sound self);

/**
 * Get the directional attenuation factor of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_directional_attenutation_factor(sf_Sound self);

/**
 * Tell whether the sound's position is relative to the listener or is absolute.
 * 1 if the position is relative, 0 if it's absolute.
 */
SFML_SIMPLE_WRAPPER_API int sf_Sound_get_is_relative_to_listener(sf_Sound self);

/**
 * Get the minimum distance of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_min_distance(sf_Sound self);

/**
 * Get the maximum distance of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_max_distance(sf_Sound self);

/**
 * Get the minimum gain of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_min_gain(sf_Sound self);

/**
 * Get the maximum gain of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_max_gain(sf_Sound self);

/**
 * Get the attenuation factor of the sound.
 */
SFML_SIMPLE_WRAPPER_API float sf_Sound_get_attenuation(sf_Sound self);


#ifdef __cplusplus
}
#endif


#endif
