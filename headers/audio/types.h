#ifndef SFML_SIMPLE_WRAPPER_AUDIO_TYPES_H
#define SFML_SIMPLE_WRAPPER_AUDIO_TYPES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct SFML_SIMPLE_WRAPPER_API sf_PlaybackDeviceGen;

struct SFML_SIMPLE_WRAPPER_API sf_SoundRecorderGen;


/**
 * Generator.
 * Takes 'std::vector<std::string> sf::Playback::Device::getAvailableDevices()' and generates
 *strings 'sf_String' from it.
 */
typedef struct sf_PlaybackDeviceGen sf_PlaybackDeviceGen;


/**
 * Generator.
 * Takes 'std::vector<std::string> sf::SoundRecorder::getAvailableDevices()' and generates
 *strings 'sf_String' from it.
 */
typedef struct sf_SoundRecorderGen sf_SoundRecorderGen;


/**
 * Opaque type for sf::SoundBuffer.
 * Storage for audio samples defining a sound.
 */
typedef void* sf_SoundBuffer;


/**
 * Opaque type for sf::SoundBufferRecorder.
 * Specialized SoundRecorder which stores the captured
 *audio data into a sound buffer.
 */
typedef void* sf_SoundBufferRecorder;


/**
 * Opaque type for sf::InputSoundFile.
 * Provide read access to sound files.
 */
typedef void* sf_InputSoundFile;


/**
 * Opaque type for sf::Sound.
 * Regular sound that can be played in the audio environment.
 */
typedef void* sf_Sound;


/**
 * Opaque type for sf::Music.
 * Streamed music played from an audio file.
 */
typedef void* sf_Music;


/**
 * Opaque type for sf::SoundSource::Cone.
 * Structure defining the properties of a directional cone.
 * Sounds will play at gain 1 when the listener
 *is positioned within the inner angle of the cone.
 * Sounds will play at `outerGain` when the listener is
 *positioned outside the outer angle of the cone.
 * The gain declines linearly from 1 to `outerGain` as the
 *listener moves from the inner angle to the outer angle.
 */
typedef void* sf_SoundSource_Cone;


/**
 * Opaque type for sf::Listener::Cone.
 * Structure defining the properties of a directional cone.
 * Sounds will play at gain 1 when the listener
 *is positioned within the inner angle of the cone.
 * Sounds will play at `outerGain` when the listener is
 *positioned outside the outer angle of the cone.
 * The gain declines linearly from 1 to `outerGain` as the
 *listener moves from the inner angle to the outer angle.
 */
typedef void* sf_Listener_Cone;


#ifdef __cplusplus
}
#endif


#endif
