#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_mouse_button_pressed.h"


struct sf_Event_MouseButtonPressed {
	int button;
	int x;
	int y;
};

sf_Event_MouseButtonPressed* sf_Event_MouseButtonPressed_init() {
	sf_Event_MouseButtonPressed* self = static_cast<sf_Event_MouseButtonPressed*>(
		std::malloc(sizeof(sf_Event_MouseButtonPressed))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_MouseButtonPressed in sf_Event_MouseButtonPressed_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_MouseButtonPressed* sf_Event_MouseButtonPressed_from_real(const sf::Event::MouseButtonPressed* real) {
	sf_Event_MouseButtonPressed* self = sf_Event_MouseButtonPressed_init();
	self->button = static_cast<int>(real->button);
	self->x      = real->position.x;
	self->y      = real->position.y;
	return self;
}

void* sf_Event_MouseButtonPressed_del(sf_Event_MouseButtonPressed* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_MouseButtonPressed_button(sf_Event_MouseButtonPressed* self) {
	return self->button;
}

int sf_Event_MouseButtonPressed_x(sf_Event_MouseButtonPressed* self) {
	return self->x;
}

int sf_Event_MouseButtonPressed_y(sf_Event_MouseButtonPressed* self) {
	return self->y;
}
