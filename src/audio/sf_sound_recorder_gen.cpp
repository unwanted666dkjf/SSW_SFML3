#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <optional>

#include <SFML/System/String.hpp>

#include <SFML/Audio/SoundRecorder.hpp>

#include "../../headers/system/sf_string.h"

#include "../../headers/audio/sf_sound_recorder_gen.h"


struct sf_SoundRecorderGen {
	unsigned long cur_ind;
	std::optional<std::vector<std::string>> devices;
};

sf_SoundRecorderGen* sf_SoundRecorderGen_init() {
	sf_SoundRecorderGen* self = new sf_SoundRecorderGen();
	if (!self) {
		std::cerr << "Could not create new sf_SoundRecorderGen in sf_SoundRecorderGen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->cur_ind = 0;
	return self;
}

void* sf_SoundRecorderGen_del(sf_SoundRecorderGen* obj) {
	delete obj;
	return NULL;
}

int sf_SoundRecorderGen_has_next(sf_SoundRecorderGen* self) {
	if (!self->devices.has_value()) {
		self->devices = sf::SoundRecorder::getAvailableDevices();
	}
	auto& v = *self->devices;
	return self->cur_ind < v.size();
}

sf_String sf_SoundRecorderGen_next(sf_SoundRecorderGen* self) {
	auto& v = *self->devices;
	std::string* device = &v[self->cur_ind];
	sf_String res = sf_String_from_str(device->c_str());
	self->cur_ind++;
	return res;
}
