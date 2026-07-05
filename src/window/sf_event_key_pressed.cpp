#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_key_pressed.h"


struct sf_Event_KeyPressed {
	int keycode;
	int scancode;
	int is_alt;
	int is_control;
	int is_shift;
	int is_system;
	int is_caps_lock;
	int is_num_lock;
	int is_scroll_lock;
};

sf_Event_KeyPressed* sf_Event_KeyPressed_init() {
	sf_Event_KeyPressed* self = static_cast<sf_Event_KeyPressed*>(
		std::malloc(sizeof(sf_Event_KeyPressed))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_KeyPressed in sf_Event_KeyPressed_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_KeyPressed* sf_Event_KeyPressed_from_real(const sf::Event::KeyPressed* real) {
	sf_Event_KeyPressed* self = sf_Event_KeyPressed_init();
	self->keycode        = static_cast<int>(real->code);
	self->scancode       = static_cast<int>(real->scancode);
	self->is_alt         = static_cast<int>(real->alt);
	self->is_control     = static_cast<int>(real->control);
	self->is_shift       = static_cast<int>(real->shift);
	self->is_system      = static_cast<int>(real->system);
	self->is_caps_lock   = static_cast<int>(real->capsLock);
	self->is_num_lock    = static_cast<int>(real->numLock);
	self->is_scroll_lock = static_cast<int>(real->scrollLock);
	return self;
}

void* sf_Event_KeyPressed_del(sf_Event_KeyPressed* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_KeyPressed_keycode(sf_Event_KeyPressed* self) {
	return self->keycode;
}

int sf_Event_KeyPressed_scancode(sf_Event_KeyPressed* self) {
	return self->scancode;
}

int sf_Event_KeyPressed_is_alt(sf_Event_KeyPressed* self) {
	return self->is_alt;
}

int sf_Event_KeyPressed_is_control(sf_Event_KeyPressed* self) {
	return self->is_control;
}

int sf_Event_KeyPressed_is_shift(sf_Event_KeyPressed* self) {
	return self->is_shift;
}

int sf_Event_KeyPressed_is_system(sf_Event_KeyPressed* self) {
	return self->is_system;
}

int sf_Event_KeyPressed_is_caps_lock(sf_Event_KeyPressed* self) {
	return self->is_caps_lock;
}

int sf_Event_KeyPressed_is_num_lock(sf_Event_KeyPressed* self) {
	return self->is_num_lock;
}

int sf_Event_KeyPressed_is_scroll_lock(sf_Event_KeyPressed* self) {
	return self->is_scroll_lock;
}
