#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <optional>

#include <SFML/Audio/PlaybackDevice.hpp>

#include "../../headers/system/sf_string.h"

#include "../../headers/audio/sf_playback_device_gen.h"


struct sf_PlaybackDeviceGen {
	unsigned long cur_ind;
	std::optional<std::vector<std::string>> devices;
};

sf_PlaybackDeviceGen* sf_PlaybackDeviceGen_init() {
	sf_PlaybackDeviceGen* self = new sf_PlaybackDeviceGen();
	if (!self) {
		std::cerr << "Could not create sf_PlaybackDeviceGen in sf_PlaybackDeviceGen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->cur_ind = 0;
	return self;
}

void* sf_PlaybackDeviceGen_del(sf_PlaybackDeviceGen* obj) {
	delete obj;
	return NULL;
}

int sf_PlaybackDeviceGen_has_next(sf_PlaybackDeviceGen* self) {
	if (!self->devices.has_value()) {
		self->devices = sf::PlaybackDevice::getAvailableDevices();
	}
	auto& v = *self->devices;
	return self->cur_ind < v.size();
}

sf_String sf_PlaybackDeviceGen_next(sf_PlaybackDeviceGen* self) {
	auto& v = *self->devices;
	std::string* device = &v[self->cur_ind];
	sf_String res = sf_String_from_str(device->c_str());
	self->cur_ind++;
	return res;
}
