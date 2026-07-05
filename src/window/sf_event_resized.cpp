#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_resized.h"


struct sf_Event_Resized {
	unsigned int width;
	unsigned int height;
};

sf_Event_Resized* sf_Event_Resized_init() {
	sf_Event_Resized* self = static_cast<sf_Event_Resized*>(
		std::malloc(sizeof(sf_Event_Resized))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_Resized in sf_Event_Resized_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_Resized* sf_Event_Resized_from_real(const sf::Event::Resized* real) {
	sf_Event_Resized* self = sf_Event_Resized_init();
	self->width  = real->size.x;
	self->height = real->size.y;
	return self;
}

void* sf_Event_Resized_del(sf_Event_Resized* obj) {
	std::free(obj);
	return NULL;
}

unsigned int sf_Event_Resized_get_width(sf_Event_Resized* self) {
	return self->width;
}

unsigned int sf_Event_Resized_get_height(sf_Event_Resized* self) {
	return self->height;
}
