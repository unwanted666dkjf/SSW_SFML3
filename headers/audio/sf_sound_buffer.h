#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_BUFFER_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_SOUND_BUFFER_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct an empty sound buffer that does not contain any samples.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundBuffer sf_SoundBuffer_default();

/**
 * Construct the sound buffer from a file.
 * Throws sf::Exception if loading was unsuccessful.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 */
SFML_SIMPLE_WRAPPER_API sf_SoundBuffer sf_SoundBuffer_init(const std_Path filepath);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_SoundBuffer_del(sf_SoundBuffer obj);

/**
 * Load the sound buffer from a file.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 * Returns 1 if succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundBuffer_load(sf_SoundBuffer self, const std_Path filepath);

/**
 * Save the sound buffer to an audio file.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 * Returns 1 if succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_SoundBuffer_save(sf_SoundBuffer self, const std_Path filepath);

/**
 * Get the number of samples stored in the buffer.
 */
SFML_SIMPLE_WRAPPER_API unsigned long long sf_SoundBuffer_get_sample_count(sf_SoundBuffer self);

/**
 * Get the sample rate of the sound.
 * The sample rate is the number of samples played per second.
 * The higher, the better the quality (for example, 44100
 *samples/s is CD quality).
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_SoundBuffer_get_sample_rate(sf_SoundBuffer self);

/**
 * Get the number of channels used by the sound.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_SoundBuffer_get_channel_count(sf_SoundBuffer self);

/**
 * Get the total duration of the sound.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_SoundBuffer_get_duration(sf_SoundBuffer self);


#ifdef __cplusplus
}
#endif


#endif
