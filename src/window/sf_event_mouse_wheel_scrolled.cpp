#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_mouse_wheel_scrolled.h"


struct sf_Event_MouseWheelScrolled {
	int wheel;
	int x;
	int y;
	float delta;
};

sf_Event_MouseWheelScrolled* sf_Event_MouseWheelScrolled_init() {
	sf_Event_MouseWheelScrolled* self = static_cast<sf_Event_MouseWheelScrolled*>(
		std::malloc(sizeof(sf_Event_MouseWheelScrolled))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_MouseWheelScrolled in sf_Event_MouseWheelScrolled_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_MouseWheelScrolled* sf_Event_MouseWheelScrolled_from_real(const sf::Event::MouseWheelScrolled* real) {
	sf_Event_MouseWheelScrolled* self = sf_Event_MouseWheelScrolled_init();
	self->wheel = static_cast<int>(real->wheel);
	self->x     = real->position.x;
	self->y     = real->position.y;
	self->delta = real->delta;
	return self;
}

void* sf_Event_MouseWheelScrolled_del(sf_Event_MouseWheelScrolled* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_MouseWheelScrolled_wheel(sf_Event_MouseWheelScrolled* self) {
	return self->wheel;
}

float sf_Event_MouseWheelScrolled_delta(sf_Event_MouseWheelScrolled* self) {
	return self->delta;
}

int sf_Event_MouseWheelScrolled_x(sf_Event_MouseWheelScrolled* self) {
	return self->x;
}

int sf_Event_MouseWheelScrolled_y(sf_Event_MouseWheelScrolled* self) {
	return self->y;
}
