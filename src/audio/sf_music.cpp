#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Time.hpp>

#include <SFML/Audio/Music.hpp>

#include "../../headers/system/sf_time.h"

#include "../../headers/system/sf_vector3f.h"

#include "../../headers/audio/sf_music.h"


namespace fs = std::filesystem;


sf_SoundSource_Cone sf_SoundSource_Cone_from_real(const sf::SoundSource::Cone& real);


sf_Music sf_Music_default() {
	sf::Music* self = new sf::Music();
	if (!self) {
		std::cerr << "Could not create sf_Music in sf_Music_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Music>(self);
}

sf_Music sf_Music_init(const std_Path filepath) {
	const fs::path* p = static_cast<const fs::path*>(filepath);
	sf::Music* self = new sf::Music(*p);
	if (!self) {
		std::cerr << "Could not create sf_Music in sf_Music_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Music>(self);
}

void* sf_Music_del(sf_Music obj) {
	sf::Music* self = static_cast<sf::Music*>(obj);
	self->stop();
	delete self;
	return NULL;
}

int sf_Music_open(sf_Music self, const std_Path filepath) {
	const fs::path* p = static_cast<const fs::path*>(filepath);
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->openFromFile(*p);
}

void sf_Music_play(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->play();
}

void sf_Music_pause(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->pause();
}

void sf_Music_stop(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->stop();
}

sf_Time sf_Music_get_duration(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return sf_Time_from_microseconds(
		s->getDuration().asMicroseconds()
	);
}

unsigned int sf_Music_get_channel_count(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getChannelCount();
}

unsigned int sf_Music_get_sample_rate(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getSampleRate();
}

int sf_Music_get_is_loop(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->isLooping();
}

void sf_Music_set_is_loop(sf_Music self, int is_loop) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setLooping(is_loop);
}

sf_Time sf_Music_get_playing_offset(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return sf_Time_from_microseconds(
		s->getPlayingOffset().asMicroseconds()
	);
}

void sf_Music_set_playing_offset(sf_Music self, sf_Time offset) {
	sf::Music* s = static_cast<sf::Music*>(self);
	sf::Time* off = static_cast<sf::Time*>(offset);
	s->setPlayingOffset(*off);
}

int sf_Music_get_status(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return static_cast<int>(s->getStatus());
}

void sf_Music_set_pitch(sf_Music self, float pitch) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setPitch(pitch);
}

void sf_Music_set_pan(sf_Music self, float pan) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setPan(pan);
}

void sf_Music_set_volume(sf_Music self, float volume) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setVolume(volume);
}

void sf_Music_set_is_spatialization_enabled(sf_Music self, int is_enabled) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setSpatializationEnabled(is_enabled);
}

void sf_Music_set_position(sf_Music self, const sf_Vector3f position) {
	sf::Music* s = static_cast<sf::Music*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(position);
	s->setPosition(*v);
}

void sf_Music_set_direction(sf_Music self, const sf_Vector3f direction) {
	sf::Music* s = static_cast<sf::Music*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(direction);
	s->setDirection(*v);
}

void sf_Music_set_cone(sf_Music self, const sf_SoundSource_Cone cone) {
	sf::Music* s = static_cast<sf::Music*>(self);
	const sf::SoundSource::Cone* c = static_cast<const sf::SoundSource::Cone*>(cone);
	s->setCone(*c);
}

void sf_Music_set_velocity(sf_Music self, const sf_Vector3f velocity) {
	sf::Music* s = static_cast<sf::Music*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(velocity);
	s->setVelocity(*v);
}

void sf_Music_set_doppler_factor(sf_Music self, float factor) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setDopplerFactor(factor);
}

void sf_Music_set_directional_attenuation_factor(sf_Music self, float factor) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setDirectionalAttenuationFactor(factor);
}

void sf_Music_set_is_relative_to_listener(sf_Music self, int is_relative) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setRelativeToListener(is_relative);
}

void sf_Music_set_min_distance(sf_Music self, float distance) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setMinDistance(distance);
}

void sf_Music_set_max_distance(sf_Music self, float distance) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setMaxDistance(distance);
}

void sf_Music_set_min_gain(sf_Music self, float gain) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setMinGain(gain);
}

void sf_Music_set_max_gain(sf_Music self, float gain) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setMaxGain(gain);
}

void sf_Music_set_attenuation(sf_Music self, float attenuation) {
	sf::Music* s = static_cast<sf::Music*>(self);
	s->setAttenuation(attenuation);
}

float sf_Music_get_pitch(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getPitch();
}

float sf_Music_get_pan(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getPan();
}

float sf_Music_get_volume(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getVolume();
}

int sf_Music_get_is_spatialization_enabled(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->isSpatializationEnabled();
}

sf_Vector3f sf_Music_get_position(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	sf::Vector3f v = s->getPosition();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

sf_Vector3f sf_Music_get_direction(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	sf::Vector3f v = s->getDirection();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

sf_SoundSource_Cone sf_Music_get_cone(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return sf_SoundSource_Cone_from_real(s->getCone());
}

sf_Vector3f sf_Music_get_velocity(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	sf::Vector3f v = s->getVelocity();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

float sf_Music_get_doppler_factor(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getDopplerFactor();
}

float sf_Music_get_directional_attenutation_factor(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getDirectionalAttenuationFactor();
}

int sf_Music_get_is_relative_to_listener(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->isRelativeToListener();
}

float sf_Music_get_min_distance(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getMinDistance();
}

float sf_Music_get_max_distance(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getMaxDistance();
}

float sf_Music_get_min_gain(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getMinGain();
}

float sf_Music_get_max_gain(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getMaxGain();
}

float sf_Music_get_attenuation(sf_Music self) {
	sf::Music* s = static_cast<sf::Music*>(self);
	return s->getAttenuation();
}
