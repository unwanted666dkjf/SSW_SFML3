#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_mouse_button_released.h"


struct sf_Event_MouseButtonReleased {
	int button;
	int x;
	int y;
};

sf_Event_MouseButtonReleased* sf_Event_MouseButtonReleased_init() {
	sf_Event_MouseButtonReleased* self = static_cast<sf_Event_MouseButtonReleased*>(
		std::malloc(sizeof(sf_Event_MouseButtonReleased))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_MouseButtonReleased in sf_Event_MouseButtonReleased_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_MouseButtonReleased* sf_Event_MouseButtonReleased_from_real(const sf::Event::MouseButtonReleased* real) {
	sf_Event_MouseButtonReleased* self = sf_Event_MouseButtonReleased_init();
	self->button = static_cast<int>(real->button);
	self->x      = real->position.x;
	self->y      = real->position.y;
	return self;
}

void* sf_Event_MouseButtonReleased_del(sf_Event_MouseButtonReleased* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_MouseButtonReleased_button(sf_Event_MouseButtonReleased* self) {
	return self->button;
}

int sf_Event_MouseButtonReleased_x(sf_Event_MouseButtonReleased* self) {
	return self->x;
}

int sf_Event_MouseButtonReleased_y(sf_Event_MouseButtonReleased* self) {
	return self->y;
}
