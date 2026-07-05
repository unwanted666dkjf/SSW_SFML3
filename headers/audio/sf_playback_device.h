#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_PLAYBACK_DEVICE_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_PLAYBACK_DEVICE_H


#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SFML_SIMPLE_WRAPPER_sf_PlaybackDevice_InvalidDeviceSampleRate (-1)


/**
 * Get the name of the default audio playback device.
 * This function returns the name of the default audio
 *playback device. If none is available, empty string
 *is returned.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_PlaybackDevice_get_default_device();

/**
 * Set the audio playback device.
 * This function sets the audio playback device to the device
 *with the given `name`. It can be called on the fly (i.e:
 *while sounds are playing).
 *
 * If there are sounds playing when the audio playback
 *device is switched, the sounds will continue playing
 *uninterrupted on the new audio playback device.
 *
 * 1, if it was able to set the requested device.
 */
SFML_SIMPLE_WRAPPER_API int sf_PlaybackDevice_set_device(const sf_String name);

/**
 * Set the audio playback device to the default.
 * This function sets the audio playback device to the
 *default device. It can be called on the fly (i.e:
 *while sounds are playing).
 *
 * If there are sounds playing when the audio playback
 *device is switched, the sounds will continue playing
 *uninterrupted on the new audio playback device.
 *
 * When certain backends are used, using the default device
 *will enable automatic stream routing. When automatic
 *stream routing is enabled, audio data is automatically
 *sent to whichever physical audio device is currently
 *marked as the default on the system. If the default device
 *changes due to e.g. a device being added to or removed
 *from the system or the user marking another device as the
 *default, automatic stream routing will seamlessly reroute
 *the audio data to the new default device without any
 *manual intervention.
 *
 * Automatic stream routing is currently supported when using
 *the WASAPI or DirectSound backend on Windows or the
 *Core Audio backend on macOS and iOS.
 *
 * Depending on the order in which hardware devices are
 *initialized e.g. after resuming from sleep, the default
 *device might change one or more times in rapid succession
 *before it reverts back to the state in which it was
 *before the system went to sleep.
 *
 * 1, if it was able to set the audio playback device to the default device.
 */
SFML_SIMPLE_WRAPPER_API int sf_PlaybackDevice_set_device_to_default();

/**
 * Set the audio playback device to the null device.
 * This function sets the audio playback device to the
 *null device. It can be called on the fly (i.e:
 *while sounds are playing).
 *
 * If there are sounds playing when the audio playback
 *device is switched, the sounds will continue playing
 *uninterrupted on the new audio playback device.
 *
 * Audio data routed to the null device will be discarded
 *by the backend. This can be used to keep sounds playing
 *without having them actually output on a physical
 *audio playback device.
 * 1, if it was able to set the audio playback device to the null device.
 */
SFML_SIMPLE_WRAPPER_API int sf_PlaybackDevice_set_device_to_null();

/**
 * Get the name of the current audio playback device.
 * Returns the name of the current audio playback device or empty string if there is none.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_PlaybackDevice_get_device();

/**
 * Get the sample rate of the current audio playback device.
 * Returns the sample rate of the current audio playback device or
 *`sf_PlaybackDevice_InvalidDeviceSampleRate` if there is none.
 */
SFML_SIMPLE_WRAPPER_API long sf_PlaybackDevice_get_device_sample_rate();

/**
 * Check if the current playback device is the default device.
 * This function will return `false` if there is no
 *current playback device.
 * 1, if the current playback device is the default device.
 */
SFML_SIMPLE_WRAPPER_API int sf_PlaybackDevice_is_default_device();


#ifdef __cplusplus
}
#endif


#endif
