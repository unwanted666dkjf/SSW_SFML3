#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include "../../headers/window/sf_event_key_released.h"


struct sf_Event_KeyReleased {
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

sf_Event_KeyReleased* sf_Event_KeyReleased_init() {
	sf_Event_KeyReleased* self = static_cast<sf_Event_KeyReleased*>(
		std::malloc(sizeof(sf_Event_KeyReleased))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_KeyReleased in sf_Event_KeyReleased_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

sf_Event_KeyReleased* sf_Event_KeyReleased_from_real(const sf::Event::KeyReleased* real) {
	sf_Event_KeyReleased* self = sf_Event_KeyReleased_init();
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

void* sf_Event_KeyReleased_del(sf_Event_KeyReleased* obj) {
	std::free(obj);
	return NULL;
}

int sf_Event_KeyReleased_keycode(sf_Event_KeyReleased* self) {
	return self->keycode;
}

int sf_Event_KeyReleased_scancode(sf_Event_KeyReleased* self) {
	return self->scancode;
}

int sf_Event_KeyReleased_is_alt(sf_Event_KeyReleased* self) {
	return self->is_alt;
}

int sf_Event_KeyReleased_is_control(sf_Event_KeyReleased* self) {
	return self->is_control;
}

int sf_Event_KeyReleased_is_shift(sf_Event_KeyReleased* self) {
	return self->is_shift;
}

int sf_Event_KeyReleased_is_system(sf_Event_KeyReleased* self) {
	return self->is_system;
}

int sf_Event_KeyReleased_is_caps_lock(sf_Event_KeyReleased* self) {
	return self->is_caps_lock;
}

int sf_Event_KeyReleased_is_num_lock(sf_Event_KeyReleased* self) {
	return self->is_num_lock;
}

int sf_Event_KeyReleased_is_scroll_lock(sf_Event_KeyReleased* self) {
	return self->is_scroll_lock;
}
