#include <iostream>

#include <cstdlib>

#include <cstddef>

#include "../../headers/window/sf_event.h"

#include "../../headers/window/sf_event_types.h"

#include "../../headers/window/sf_event_key_pressed.h"

#include "../../headers/window/sf_event_key_released.h"

#include "../../headers/window/sf_event_mouse_button_pressed.h"

#include "../../headers/window/sf_event_mouse_button_released.h"

#include "../../headers/window/sf_event_mouse_moved.h"

#include "../../headers/window/sf_event_mouse_moved_raw.h"

#include "../../headers/window/sf_event_mouse_wheel_scrolled.h"

#include "../../headers/window/sf_event_resized.h"


typedef union {
	sf_Event_Resized*             resized;
	sf_Event_KeyPressed*          key_pressed;
	sf_Event_KeyReleased*         key_released;
	sf_Event_MouseWheelScrolled*  mouse_wheel_scrolled;
	sf_Event_MouseButtonPressed*  mouse_button_pressed;
	sf_Event_MouseButtonReleased* mouse_button_released;
	sf_Event_MouseMoved*          mouse_moved;
	sf_Event_MouseMovedRaw*       mouse_moved_raw;
} sf_Events;


struct sf_Event {
	int type_;
	sf_Events evt;
};

sf_Event* sf_Event_init() {
	sf_Event* self = static_cast<sf_Event*>(
		std::malloc(sizeof(sf_Event))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event in sf_Event_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->type_ = SFML_SIMPLE_WRAPPER_sf_Event_Unknown;
	self->evt.resized               = NULL;
	self->evt.key_pressed           = NULL;
	self->evt.key_released          = NULL;
	self->evt.mouse_wheel_scrolled  = NULL;
	self->evt.mouse_button_pressed  = NULL;
	self->evt.mouse_button_released = NULL;
	self->evt.mouse_moved           = NULL;
	self->evt.mouse_moved_raw       = NULL;
	return self;
}

void* sf_Event_del(sf_Event* obj) {
	std::free(obj);
	return NULL;
}

void sf_Event_cleanup(sf_Event* self) {
	if (self->evt.resized) {
		sf_Event_Resized_del(self->evt.resized);
		self->evt.resized = NULL;
	}
	if (self->evt.key_pressed) {
		sf_Event_KeyPressed_del(self->evt.key_pressed);
		self->evt.key_pressed = NULL;
	}
	if (self->evt.key_released) {
		sf_Event_KeyReleased_del(self->evt.key_released);
		self->evt.key_released = NULL;
	}
	if (self->evt.mouse_wheel_scrolled) {
		sf_Event_MouseWheelScrolled_del(self->evt.mouse_wheel_scrolled);
		self->evt.mouse_wheel_scrolled = NULL;
	}
	if (self->evt.mouse_button_pressed) {
		sf_Event_MouseButtonPressed_del(self->evt.mouse_button_pressed);
		self->evt.mouse_button_pressed = NULL;
	}
	if (self->evt.mouse_button_released) {
		sf_Event_MouseButtonReleased_del(self->evt.mouse_button_released);
		self->evt.mouse_button_released = NULL;
	}
	if (self->evt.mouse_moved) {
		sf_Event_MouseMoved_del(self->evt.mouse_moved);
		self->evt.mouse_moved = NULL;
	}
	if (self->evt.mouse_moved_raw) {
		sf_Event_MouseMovedRaw_del(self->evt.mouse_moved_raw);
		self->evt.mouse_moved_raw = NULL;
	}
}

int sf_Event_get_type(sf_Event* self) {
	return self->type_;
}

void sf_Event_set_type(sf_Event* self, int type_) {
	self->type_ = type_;
}

sf_Event_KeyPressed* sf_Event_get_key_pressed_evt(sf_Event* self) {
	if (!self->evt.key_pressed) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_key_pressed_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.key_pressed;
}

void sf_Event_set_key_pressed_evt(sf_Event* self, sf_Event_KeyPressed* evt) {
	self->evt.key_pressed = evt;
}

sf_Event_KeyReleased* sf_Event_get_key_released_evt(sf_Event* self) {
	if (!self->evt.key_released) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_key_released_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.key_released;
}

void sf_Event_set_key_released_evt(sf_Event* self, sf_Event_KeyReleased* evt) {
	self->evt.key_released = evt;
}

sf_Event_MouseButtonPressed* sf_Event_get_mouse_button_pressed_evt(sf_Event* self) {
	if (!self->evt.mouse_button_pressed) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_mouse_button_pressed_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.mouse_button_pressed;
}

void sf_Event_set_mouse_button_pressed_evt(sf_Event* self, sf_Event_MouseButtonPressed* evt) {
	self->evt.mouse_button_pressed = evt;
}

sf_Event_MouseButtonReleased* sf_Event_get_mouse_button_released_evt(sf_Event* self) {
	if (!self->evt.mouse_button_released) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_mouse_button_released_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.mouse_button_released;
}

void sf_Event_set_mouse_button_released_evt(sf_Event* self, sf_Event_MouseButtonReleased* evt) {
	self->evt.mouse_button_released = evt;
}

sf_Event_MouseMoved* sf_Event_get_mouse_moved_evt(sf_Event* self) {
	if (!self->evt.mouse_moved) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_mouse_moved_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.mouse_moved;
}

void sf_Event_set_mouse_moved_evt(sf_Event* self, sf_Event_MouseMoved* evt) {
	self->evt.mouse_moved = evt;
}

sf_Event_MouseMovedRaw* sf_Event_get_mouse_moved_raw_evt(sf_Event* self) {
	if (!self->evt.mouse_moved_raw) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_mouse_moved_raw_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.mouse_moved_raw;
}

void sf_Event_set_mouse_moved_raw_evt(sf_Event* self, sf_Event_MouseMovedRaw* evt) {
	self->evt.mouse_moved_raw = evt;
}

sf_Event_MouseWheelScrolled* sf_Event_get_mouse_wheel_scrolled_evt(sf_Event* self) {
	if (!self->evt.mouse_wheel_scrolled) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_mouse_wheel_scrolled_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.mouse_wheel_scrolled;
}

void sf_Event_set_mouse_wheel_scrolled_evt(sf_Event* self, sf_Event_MouseWheelScrolled* evt) {
	self->evt.mouse_wheel_scrolled = evt;
}

sf_Event_Resized* sf_Event_get_resized_evt(sf_Event* self) {
	if (!self->evt.resized) {
		std::cerr << "Trying to access an uninitialized event in sf_Event_get_resized_evt!\n";
		std::exit(EXIT_FAILURE);
	}
	return self->evt.resized;
}

void sf_Event_set_resized_evt(sf_Event* self, sf_Event_Resized* evt) {
	self->evt.resized = evt;
}
