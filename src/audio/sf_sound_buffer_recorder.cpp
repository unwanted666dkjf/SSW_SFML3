#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <filesystem>

#include <SFML/System/String.hpp>

#include <SFML/Audio/SoundBufferRecorder.hpp>

#include "../../headers/system/sf_string.h"

#include "../../headers/audio/sf_sound_buffer_recorder.h"


namespace fs = std::filesystem;


sf_SoundBufferRecorder sf_SoundBufferRecorder_init() {
	sf::SoundBufferRecorder* self = new sf::SoundBufferRecorder();
	if (!self) {
		std::cerr << "Could not create sf_SoundBufferRecorder in sf_SoundBufferRecorder_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_SoundBufferRecorder>(self);
}

void* sf_SoundBufferRecorder_del(sf_SoundBufferRecorder obj) {
	sf::SoundBufferRecorder* self = static_cast<sf::SoundBufferRecorder*>(obj);
	self->stop();
	delete self;
	return NULL;
}

int sf_SoundBufferRecorder_save(sf_SoundBufferRecorder self, const std_Path filepath) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	const fs::path* p = static_cast<const fs::path*>(filepath);
	return s->getBuffer().saveToFile(*p);
}

int sf_SoundBufferRecorder_start(sf_SoundBufferRecorder self, unsigned int sample_rate) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	return s->start(sample_rate);
}

void sf_SoundBufferRecorder_stop(sf_SoundBufferRecorder self) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	s->stop();
}

unsigned int sf_SoundBufferRecorder_get_sample_rate(sf_SoundBufferRecorder self) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	return s->getSampleRate();
}

sf_String sf_SoundRecorder_get_default_device() {
	std::string device = sf::SoundRecorder::getDefaultDevice();
	return sf_String_from_str(device.c_str());
}

int sf_SoundRecorder_is_available() {
	return sf::SoundRecorder::isAvailable();
}

int sf_SoundBufferRecorder_set_device(sf_SoundBufferRecorder self, const sf_String name) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	const sf::String* n = static_cast<const sf::String*>(name);
	return s->setDevice(n->toAnsiString());
}

sf_String sf_SoundBufferRecorder_get_device(sf_SoundBufferRecorder self) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	return sf_String_from_str(s->getDevice().c_str());
}

void sf_SoundBufferRecorder_set_channel_count(sf_SoundBufferRecorder self, unsigned int channel_count) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	s->setChannelCount(channel_count);
}

unsigned int sf_SoundBufferRecorder_get_channel_count(sf_SoundBufferRecorder self) {
	sf::SoundBufferRecorder* s = static_cast<sf::SoundBufferRecorder*>(self);
	return s->getChannelCount();
}
