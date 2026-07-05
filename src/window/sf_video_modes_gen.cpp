#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <optional>

#include <SFML/Window/VideoMode.hpp>

#include "../../headers/window/sf_video_mode.h"

#include "../../headers/window/sf_video_modes_gen.h"


struct sf_VideoModes_Gen {
	unsigned long cur_ind;
	std::optional<std::vector<sf::VideoMode>> modes;
};

sf_VideoModes_Gen* sf_VideoModes_Gen_init() {
	sf_VideoModes_Gen* self = new sf_VideoModes_Gen();
	if (!self) {
		std::cerr << "Could not create sf_VideoModes_Gen in sf_VideoModes_Gen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->cur_ind = 0;
	return self;
}

void* sf_VideoModes_Gen_del(sf_VideoModes_Gen* obj) {
	delete obj;
	return NULL;
}

int sf_VideoModes_Gen_has_next(sf_VideoModes_Gen* self) {
	if (!self->modes.has_value()) {
		self->modes = sf::VideoMode::getFullscreenModes();
	}
	auto& v = *self->modes;
	return self->cur_ind < v.size();
}

sf_VideoMode sf_VideoModes_Gen_next(sf_VideoModes_Gen* self) {
	auto& v = *self->modes;
	sf::VideoMode* mode = &v[self->cur_ind];
	sf_VideoMode res = sf_VideoMode_init(mode->size.x, mode->size.y, mode->bitsPerPixel);
	self->cur_ind++;
	return res;
}
