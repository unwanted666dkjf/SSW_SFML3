#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_mouse_moved_raw.h"


struct sf_Event_MouseMovedRaw {
	int delta_x;
	int delta_y;
};

sf_Event_MouseMovedRaw* sf_Event_MouseMovedRaw_init() {
	sf_Event_MouseMovedRaw* self = static_cast<sf_Event_MouseMovedRaw*>(
		std::malloc(sizeof(sf_Event_MouseMovedRaw))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_MouseMovedRaw in sf_Event_MouseMovedRaw_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_MouseMovedRaw* sf_Event_MouseMovedRaw_from_real(const sf::Event::MouseMovedRaw* real) {
	sf_Event_MouseMovedRaw* self = sf_Event_MouseMovedRaw_init();
	self->delta_x = real->delta.x;
	self->delta_y = real->delta.y;
	return self;
}

void* sf_Event_MouseMovedRaw_del(sf_Event_MouseMovedRaw* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_MouseMovedRaw_delta_x(sf_Event_MouseMovedRaw* self) {
	return self->delta_x;
}

int sf_Event_MouseMovedRaw_delta_y(sf_Event_MouseMovedRaw* self) {
	return self->delta_y;
}
