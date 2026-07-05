#ifndef SFML_SIMPLE_WRAPPER_AUDIO_SF_INPUT_SOUND_FILE_H
#define SFML_SIMPLE_WRAPPER_AUDIO_SF_INPUT_SOUND_FILE_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct an empty sound file that is not associated
 *with a file to read.
 */
SFML_SIMPLE_WRAPPER_API sf_InputSoundFile sf_InputSoundFile_default();

/**
 * Construct the sound file from a file.
 * Throws sf::Exception if loading was unsuccessful.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 */
SFML_SIMPLE_WRAPPER_API sf_InputSoundFile sf_InputSoundFile_init(const std_Path filepath);

/**
 * Deletes object and returns NULL.
 * Closes itself.
 */
SFML_SIMPLE_WRAPPER_API void* sf_InputSoundFile_del(sf_InputSoundFile obj);

/**
 * Open a sound file from the disk for reading.
 * The supported audio formats are: WAV (PCM only), OGG/Vorbis, FLAC, MP3.
 * The supported sample sizes for FLAC and WAV are 8, 16, 24 and 32 bit.
 * Returns 1 if succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_InputSoundFile_open(sf_InputSoundFile self, const std_Path filepath);

/**
 * Get the number of samples stored in the buffer.
 */
SFML_SIMPLE_WRAPPER_API unsigned long long sf_InputSoundFile_get_sample_count(sf_InputSoundFile self);

/**
 * Get the sample rate of the sound.
 * The sample rate is the number of samples played per second.
 * The higher, the better the quality (for example, 44100
 *samples/s is CD quality).
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_InputSoundFile_get_sample_rate(sf_InputSoundFile self);

/**
 * Get the number of channels used by the sound.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_InputSoundFile_get_channel_count(sf_InputSoundFile self);

/**
 * Get the total duration of the sound.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_InputSoundFile_get_duration(sf_InputSoundFile self);

/**
 * Get the read offset of the file in time.
 */
SFML_SIMPLE_WRAPPER_API sf_Time sf_InputSoundFile_get_time_offset(sf_InputSoundFile self);

/**
 * Get the read offset of the file in samples.
 */
SFML_SIMPLE_WRAPPER_API unsigned long long sf_InputSoundFile_get_sample_offset(sf_InputSoundFile self);

/**
 * Change the current read position to the given sample offset.
 * This function takes a sample offset to provide maximum
 *precision. If you need to jump to a given time, use the
 *other overload.
 *
 * The sample offset takes the channels into account.
 * If you have a time offset instead, you can easily find
 *the corresponding sample offset with the following formula:
 *`timeInSeconds * sampleRate * channelCount`
 * If the given offset exceeds to total number of samples,
 *this function jumps to the end of the sound file.
 */
SFML_SIMPLE_WRAPPER_API void sf_InputSoundFile_seek_sample(sf_InputSoundFile self, unsigned long long offset);

/**
 * Change the current read position to the given time offset.
 * Using a time offset is handy but imprecise. If you need an accurate
 *result, consider using the overload which takes a sample offset.
 *
 * If the given time exceeds to total duration, this function jumps
 *to the end of the sound file.
 */
SFML_SIMPLE_WRAPPER_API void sf_InputSoundFile_seek_time(sf_InputSoundFile self, sf_Time offset);

/**
 * Close the current file.
 */
SFML_SIMPLE_WRAPPER_API void sf_InputSoundFile_close(sf_InputSoundFile self);


#ifdef __cplusplus
}
#endif


#endif
