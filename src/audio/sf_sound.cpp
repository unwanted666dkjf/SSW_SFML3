#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Time.hpp>

#include <SFML/Audio/Sound.hpp>

#include "../../headers/system/sf_time.h"

#include "../../headers/system/sf_vector3f.h"

#include "../../headers/audio/sf_sound.h"


sf_SoundSource_Cone sf_SoundSource_Cone_from_real(const sf::SoundSource::Cone& real);


sf_Sound sf_Sound_init(const sf_SoundBuffer buffer) {
	const sf::SoundBuffer* buf = static_cast<const sf::SoundBuffer*>(buffer);
	sf::Sound* self = new sf::Sound(*buf);
	if (!self) {
		std::cerr << "Could not create sf_Sound in sf_Sound_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Sound>(self);
}

void* sf_Sound_del(sf_Sound obj) {
	sf::Sound* self = static_cast<sf::Sound*>(obj);
	self->stop();
	delete self;
	return NULL;
}

void sf_Sound_play(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->play();
}

void sf_Sound_pause(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->pause();
}

void sf_Sound_stop(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->stop();
}

void sf_Sound_set_is_loop(sf_Sound self, int is_loop) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setLooping(is_loop);
}

void sf_Sound_set_playing_offset(sf_Sound self, sf_Time offset) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	sf::Time* off = static_cast<sf::Time*>(offset);
	s->setPlayingOffset(*off);
}

sf_Time sf_Sound_get_playing_offset(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	sf_Time res = sf_Time_from_microseconds(
		s->getPlayingOffset().asMicroseconds()
	);
	return res;
}

int sf_Sound_get_is_loop(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->isLooping();
}

int sf_Sound_get_status(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return static_cast<int>(s->getStatus());
}

void sf_Sound_set_pitch(sf_Sound self, float pitch) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setPitch(pitch);
}

void sf_Sound_set_pan(sf_Sound self, float pan) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setPan(pan);
}

void sf_Sound_set_volume(sf_Sound self, float volume) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setVolume(volume);
}

void sf_Sound_set_is_spatialization_enabled(sf_Sound self, int is_enabled) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setSpatializationEnabled(is_enabled);
}

void sf_Sound_set_position(sf_Sound self, const sf_Vector3f position) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(position);
	s->setPosition(*v);
}

void sf_Sound_set_direction(sf_Sound self, const sf_Vector3f direction) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(direction);
	s->setDirection(*v);
}

void sf_Sound_set_cone(sf_Sound self, const sf_SoundSource_Cone cone) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	const sf::SoundSource::Cone* c = static_cast<const sf::SoundSource::Cone*>(cone);
	s->setCone(*c);
}

void sf_Sound_set_velocity(sf_Sound self, const sf_Vector3f velocity) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(velocity);
	s->setVelocity(*v);
}

void sf_Sound_set_doppler_factor(sf_Sound self, float factor) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setDopplerFactor(factor);
}

void sf_Sound_set_directional_attenuation_factor(sf_Sound self, float factor) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setDirectionalAttenuationFactor(factor);
}

void sf_Sound_set_is_relative_to_listener(sf_Sound self, int is_relative) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setRelativeToListener(is_relative);
}

void sf_Sound_set_min_distance(sf_Sound self, float distance) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setMinDistance(distance);
}

void sf_Sound_set_max_distance(sf_Sound self, float distance) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setMaxDistance(distance);
}

void sf_Sound_set_min_gain(sf_Sound self, float gain) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setMinGain(gain);
}

void sf_Sound_set_max_gain(sf_Sound self, float gain) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setMaxGain(gain);
}

void sf_Sound_set_attenuation(sf_Sound self, float attenuation) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	s->setAttenuation(attenuation);
}

float sf_Sound_get_pitch(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getPitch();
}

float sf_Sound_get_pan(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getPan();
}

float sf_Sound_get_volume(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getVolume();
}

int sf_Sound_get_is_spatialization_enabled(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->isSpatializationEnabled();
}

sf_Vector3f sf_Sound_get_position(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	sf::Vector3f v = s->getPosition();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

sf_Vector3f sf_Sound_get_direction(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	sf::Vector3f v = s->getDirection();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

sf_SoundSource_Cone sf_Sound_get_cone(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return sf_SoundSource_Cone_from_real(s->getCone());
}

sf_Vector3f sf_Sound_get_velocity(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	sf::Vector3f v = s->getVelocity();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

float sf_Sound_get_doppler_factor(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getDopplerFactor();
}

float sf_Sound_get_directional_attenutation_factor(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getDirectionalAttenuationFactor();
}

int sf_Sound_get_is_relative_to_listener(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->isRelativeToListener();
}

float sf_Sound_get_min_distance(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getMinDistance();
}

float sf_Sound_get_max_distance(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getMaxDistance();
}

float sf_Sound_get_min_gain(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getMinGain();
}

float sf_Sound_get_max_gain(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getMaxGain();
}

float sf_Sound_get_attenuation(sf_Sound self) {
	sf::Sound* s = static_cast<sf::Sound*>(self);
	return s->getAttenuation();
}
