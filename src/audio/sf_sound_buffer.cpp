#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Audio/SoundBuffer.hpp>

#include "../../headers/system/sf_time.h"

#include "../../headers/audio/sf_sound_buffer.h"


namespace fs = std::filesystem;


sf_SoundBuffer sf_SoundBuffer_default() {
	sf::SoundBuffer* self = new sf::SoundBuffer();
	if (!self) {
		std::cerr << "Could not create sf_SoundBuffer in sf_SoundBuffer_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_SoundBuffer>(self);
}

sf_SoundBuffer sf_SoundBuffer_init(const std_Path filepath) {
	const fs::path* p = static_cast<const fs::path*>(filepath);
	sf::SoundBuffer* self = new sf::SoundBuffer(*p);
	if (!self) {
		std::cerr << "Could not create sf_SoundBuffer in sf_SoundBuffer_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_SoundBuffer>(self);
}

void* sf_SoundBuffer_del(sf_SoundBuffer obj) {
	sf::SoundBuffer* self = static_cast<sf::SoundBuffer*>(obj);
	delete self;
	return NULL;
}

int sf_SoundBuffer_load(sf_SoundBuffer self, const std_Path filepath) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	const fs::path* p = static_cast<const fs::path*>(filepath);
	return s->loadFromFile(*p);
}

int sf_SoundBuffer_save(sf_SoundBuffer self, const std_Path filepath) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	const fs::path* p = static_cast<const fs::path*>(filepath);
	return s->saveToFile(*p);
}

unsigned long long sf_SoundBuffer_get_sample_count(sf_SoundBuffer self) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	return s->getSampleCount();
}

unsigned int sf_SoundBuffer_get_sample_rate(sf_SoundBuffer self) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	return s->getSampleRate();
}

unsigned int sf_SoundBuffer_get_channel_count(sf_SoundBuffer self) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	return s->getChannelCount();
}

sf_Time sf_SoundBuffer_get_duration(sf_SoundBuffer self) {
	sf::SoundBuffer* s = static_cast<sf::SoundBuffer*>(self);
	sf::Time t = s->getDuration();
	return sf_Time_from_microseconds(t.asMicroseconds());
}
