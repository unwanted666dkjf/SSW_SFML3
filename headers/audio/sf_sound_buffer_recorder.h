#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_BUFFER_RECORDER_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_BUFFER_RECORDER_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SFML_SIMPLE_WRAPPER_sf_SoundRecorder_DefaultSampleRate (44100)


/**
 * Constructs new sf_SoundBufferRecorder.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundBufferRecorder sf_SoundBufferRecorder_init();

/**
 * Deletes object and returns NULL.
 * Stops itself.
 */
SFML_SIMPLE_WRAPPER_API void* sf_SoundBufferRecorder_del(sf_SoundBufferRecorder obj);

/**
 * Saves the captured audio data to an audio file.
 * Returns 1 if saving succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundBufferRecorder_save(sf_SoundBufferRecorder self, const std_Path filepath);

/**
 * Start the capture.
 * The `sampleRate` parameter defines the number of audio samples
 *captured per second. The higher, the better the quality
 *(for example, 44100 samples/sec is CD quality).
 * This function uses its own thread so that it doesn't block
 *the rest of the program while the capture runs.
 * Please note that only one capture can happen at the same time.
 * You can select which capture device will be used by passing
 *the name to the `setDevice()` method. If none was selected
 *before, the default capture device will be used. You can create a
 *list of the names of all available capture devices by using
 *sf_SoundRecorderGen.
 * Returns 1, if start of capture was successful.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundBufferRecorder_start(sf_SoundBufferRecorder self, unsigned int sample_rate);

/**
 * Stop the capture.
 */
SFML_SIMPLE_WRAPPER_API void sf_SoundBufferRecorder_stop(sf_SoundBufferRecorder self);

/**
 * Get the sample rate.
 * The sample rate defines the number of audio samples
 *captured per second. The higher, the better the quality
 *(for example, 44100 samples/sec is CD quality).
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_SoundBufferRecorder_get_sample_rate(sf_SoundBufferRecorder self);

/**
 * Get the name of the default audio capture device.
 * This function returns the name of the default audio
 *capture device. If none is available, an empty string
 *is returned.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_SoundRecorder_get_default_device();

/**
 * Check if the system supports audio capture.
 * This function should always be called before using
 *the audio capture features. If it returns `false`, then
 *any attempt to use `sf::SoundRecorder` or one of its derived
 *classes will fail.
 * Returns 1 if audio capture is supported, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundRecorder_is_available();

/**
 * Set the audio capture device.
 * This function sets the audio capture device to the device
 *with the given `name`. It can be called on the fly (i.e:
 *while recording). If you do so while recording and
 *opening the device fails, it stops the recording.
 * 1, if it was able to set the requested device.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundBufferRecorder_set_device(sf_SoundBufferRecorder self, const sf_String name);

/**
 * Get the name of the current audio capture device.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_SoundBufferRecorder_get_device(sf_SoundBufferRecorder self);

/**
 * Set the channel count of the audio capture device.
 * This method allows you to specify the number of channels
 *used for recording. Currently only 16-bit mono and
 *16-bit stereo are supported.
 */
SFML_SIMPLE_WRAPPER_API void sf_SoundBufferRecorder_set_channel_count(sf_SoundBufferRecorder self, unsigned int channel_count);

/**
 * Get the number of channels used by this recorder.
 * Currently only mono and stereo are supported, so the
 *value is either 1 (for mono) or 2 (for stereo).
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_SoundBufferRecorder_get_channel_count(sf_SoundBufferRecorder self);


#ifdef __cplusplus
}
#endif


#endif
