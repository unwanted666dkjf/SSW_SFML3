#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/String.hpp>

#include <SFML/Audio/PlaybackDevice.hpp>

#include "../../headers/system/sf_string.h"

#include "../../headers/audio/sf_playback_device.h"


sf_String sf_PlaybackDevice_get_default_device() {
	std::optional<std::string> d = sf::PlaybackDevice::getDefaultDevice();
	sf_String res;
	if (!d) {
		res = sf_String_from_str("");
	} else {
		res = sf_String_from_str(d->c_str());
	}
	return res;
}

int sf_PlaybackDevice_set_device(const sf_String name) {
	const sf::String* n = static_cast<const sf::String*>(name);
	return sf::PlaybackDevice::setDevice(n->toAnsiString());
}

int sf_PlaybackDevice_set_device_to_default() {
	return sf::PlaybackDevice::setDeviceToDefault();
}

int sf_PlaybackDevice_set_device_to_null() {
	return sf::PlaybackDevice::setDeviceToNull();
}

sf_String sf_PlaybackDevice_get_device() {
	std::optional<std::string> d = sf::PlaybackDevice::getDevice();
	sf_String res;
	if (!d) {
		res = sf_String_from_str("");
	} else {
		res = sf_String_from_str(d->c_str());
	}
	return res;
}

long sf_PlaybackDevice_get_device_sample_rate() {
	std::optional<std::uint32_t> rate = sf::PlaybackDevice::getDeviceSampleRate();
	long res = SFML_SIMPLE_WRAPPER_sf_PlaybackDevice_InvalidDeviceSampleRate;
	if (rate) {
		res = static_cast<long>(*rate);
	}
	return res;
}

int sf_PlaybackDevice_is_default_device() {
	return sf::PlaybackDevice::isDefaultDevice();
}
