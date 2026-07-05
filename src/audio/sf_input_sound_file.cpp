#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Time.hpp>

#include <SFML/Audio/InputSoundFile.hpp>

#include "../../headers/system/sf_time.h"

#include "../../headers/audio/sf_input_sound_file.h"


namespace fs = std::filesystem;


sf_InputSoundFile sf_InputSoundFile_default() {
	sf::InputSoundFile* self = new sf::InputSoundFile();
	if (!self) {
		std::cerr << "Could not create sf_InputSoundFile in sf_InputSoundFile_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_InputSoundFile>(self);
}

sf_InputSoundFile sf_InputSoundFile_init(const std_Path filepath) {
	const fs::path* p = static_cast<const fs::path*>(filepath);
	sf::InputSoundFile* self = new sf::InputSoundFile(*p);
	if (!self) {
		std::cerr << "Could not create sf_InputSoundFile in sf_InputSoundFile_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_InputSoundFile>(self);
}

void* sf_InputSoundFile_del(sf_InputSoundFile obj) {
	sf::InputSoundFile* self = static_cast<sf::InputSoundFile*>(obj);
	self->close();
	delete self;
	return NULL;
}

int sf_InputSoundFile_open(sf_InputSoundFile self, const std_Path filepath) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	const fs::path* p = static_cast<const fs::path*>(filepath);
	return s->openFromFile(*p);
}

unsigned long long sf_InputSoundFile_get_sample_count(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	return s->getSampleCount();
}

unsigned int sf_InputSoundFile_get_sample_rate(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	return s->getSampleRate();
}

unsigned int sf_InputSoundFile_get_channel_count(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	return s->getChannelCount();
}

sf_Time sf_InputSoundFile_get_duration(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	sf::Time t = s->getDuration();
	return sf_Time_from_microseconds(t.asMicroseconds());
}

sf_Time sf_InputSoundFile_get_time_offset(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	sf::Time t = s->getTimeOffset();
	return sf_Time_from_microseconds(t.asMicroseconds());
}

unsigned long long sf_InputSoundFile_get_sample_offset(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	return s->getSampleOffset();
}

void sf_InputSoundFile_seek_sample(sf_InputSoundFile self, unsigned long long offset) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	s->seek(offset);
}

void sf_InputSoundFile_seek_time(sf_InputSoundFile self, sf_Time offset) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	sf::Time* t = static_cast<sf::Time*>(offset);
	s->seek(*t);
}

void sf_InputSoundFile_close(sf_InputSoundFile self) {
	sf::InputSoundFile* s = static_cast<sf::InputSoundFile*>(self);
	s->close();
}
