#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_mouse_moved.h"


struct sf_Event_MouseMoved {
	int x;
	int y;
};

sf_Event_MouseMoved* sf_Event_MouseMoved_init() {
	sf_Event_MouseMoved* self = static_cast<sf_Event_MouseMoved*>(
		std::malloc(sizeof(sf_Event_MouseMoved))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_MouseMoved in sf_Event_MouseMoved_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_MouseMoved* sf_Event_MouseMoved_from_real(const sf::Event::MouseMoved* real) {
	sf_Event_MouseMoved* self = sf_Event_MouseMoved_init();
	self->x = real->position.x;
	self->y = real->position.y;
	return self;
}

void* sf_Event_MouseMoved_del(sf_Event_MouseMoved* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_MouseMoved_x(sf_Event_MouseMoved* self) {
	return self->x;
}

int sf_Event_MouseMoved_y(sf_Event_MouseMoved* self) {
	return self->y;
}
