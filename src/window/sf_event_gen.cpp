#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/Event.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../headers/window/sf_event.h"

#include "../../headers/window/sf_event_gen.h"

#include "../../headers/window/sf_event_types.h"

#include "../../headers/window/sf_event_key_pressed.h"

#include "../../headers/window/sf_event_key_released.h"

#include "../../headers/window/sf_event_mouse_button_pressed.h"

#include "../../headers/window/sf_event_mouse_button_released.h"

#include "../../headers/window/sf_event_mouse_moved.h"

#include "../../headers/window/sf_event_mouse_moved_raw.h"

#include "../../headers/window/sf_event_mouse_wheel_scrolled.h"

#include "../../headers/window/sf_event_resized.h"


static sf_Event* sf_Event_Gen_event_from_opt(const std::optional<sf::Event>& event);


struct sf_Event_Gen {
	int is_exhausted;
	sf_Event* last;
	sf::RenderWindow* wnd;
};

sf_Event_Gen* sf_Event_Gen_init(sf_RenderWindow wnd) {
	sf_Event_Gen* self = static_cast<sf_Event_Gen*>(
		std::malloc(sizeof(sf_Event_Gen))
	);
	if (!self) {
		std::cerr << "Could not create sf_Event_Gen in sf_Event_Gen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->wnd = static_cast<sf::RenderWindow*>(wnd);
	const std::optional event = self->wnd->pollEvent();
	if (!event) {
		self->is_exhausted = 1;
		self->last = NULL;
	} else {
		self->is_exhausted = 0;
		self->last = sf_Event_Gen_event_from_opt(event);
	}
	return self;
}

void* sf_Event_Gen_del(sf_Event_Gen* obj) {
	if (obj->last) {
		sf_Event_cleanup(obj->last);
		sf_Event_del(obj->last);
	}
	std::free(obj);
	return NULL;
}

int sf_Event_Gen_has_next(sf_Event_Gen* self) {
	return !self->is_exhausted;
}

sf_Event* sf_Event_Gen_next(sf_Event_Gen* self) {
	sf_Event* last = self->last;
	const std::optional event = self->wnd->pollEvent();
	if (!event) {
		self->is_exhausted = 1;
		self->last = NULL;
	} else {
		self->is_exhausted = 0;
		self->last = sf_Event_Gen_event_from_opt(event);
	}
	return last;
}


sf_Event_Resized* sf_Event_Resized_from_real(const sf::Event::Resized* real);

sf_Event_KeyPressed* sf_Event_KeyPressed_from_real(const sf::Event::KeyPressed* real);

sf_Event_KeyReleased* sf_Event_KeyReleased_from_real(const sf::Event::KeyReleased* real);

sf_Event_MouseWheelScrolled* sf_Event_MouseWheelScrolled_from_real(const sf::Event::MouseWheelScrolled* real);

sf_Event_MouseButtonPressed* sf_Event_MouseButtonPressed_from_real(const sf::Event::MouseButtonPressed* real);

sf_Event_MouseButtonReleased* sf_Event_MouseButtonReleased_from_real(const sf::Event::MouseButtonReleased* real);

sf_Event_MouseMoved* sf_Event_MouseMoved_from_real(const sf::Event::MouseMoved* real);

sf_Event_MouseMovedRaw* sf_Event_MouseMovedRaw_from_real(const sf::Event::MouseMovedRaw* real);


void sf_Event_set_type(sf_Event* self, int type_);

void sf_Event_set_resized_evt(sf_Event* self, sf_Event_Resized* evt);

void sf_Event_set_key_pressed_evt(sf_Event* self, sf_Event_KeyPressed* evt);

void sf_Event_set_key_released_evt(sf_Event* self, sf_Event_KeyReleased* evt);

void sf_Event_set_mouse_button_pressed_evt(sf_Event* self, sf_Event_MouseButtonPressed* evt);

void sf_Event_set_mouse_button_released_evt(sf_Event* self, sf_Event_MouseButtonReleased* evt);

void sf_Event_set_mouse_moved_evt(sf_Event* self, sf_Event_MouseMoved* evt);

void sf_Event_set_mouse_moved_raw_evt(sf_Event* self, sf_Event_MouseMovedRaw* evt);

void sf_Event_set_mouse_wheel_scrolled_evt(sf_Event* self, sf_Event_MouseWheelScrolled* evt);


sf_Event* sf_Event_Gen_event_from_opt(const std::optional<sf::Event>& event) {
	sf_Event* evt = sf_Event_init();
	if (event->is<sf::Event::Closed>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_Closed);
	} else if (event->is<sf::Event::FocusLost>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_LostFocus);
	} else if (event->is<sf::Event::FocusGained>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_GainedFocus);
	} else if (event->is<sf::Event::MouseEntered>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseEntered);
	} else if (event->is<sf::Event::MouseLeft>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseLeft);
	} else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_Resized);
		sf_Event_set_resized_evt(
			evt, sf_Event_Resized_from_real(resized)
		);
	} else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_KeyPressed);
		sf_Event_set_key_pressed_evt(
			evt, sf_Event_KeyPressed_from_real(key_pressed)
		);
	} else if (const auto* key_released = event->getIf<sf::Event::KeyReleased>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_KeyReleased);
		sf_Event_set_key_released_evt(
			evt, sf_Event_KeyReleased_from_real(key_released)
		);
	} else if (const auto* mouse_wheel_scrolled = event->getIf<sf::Event::MouseWheelScrolled>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseWheelScrolled);
		sf_Event_set_mouse_wheel_scrolled_evt(
			evt, sf_Event_MouseWheelScrolled_from_real(mouse_wheel_scrolled)
		);
	} else if (const auto* mouse_btn_pressed = event->getIf<sf::Event::MouseButtonPressed>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseButtonPressed);
		sf_Event_set_mouse_button_pressed_evt(
			evt, sf_Event_MouseButtonPressed_from_real(mouse_btn_pressed)
		);
	} else if (const auto* mouse_btn_released = event->getIf<sf::Event::MouseButtonReleased>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseButtonReleased);
		sf_Event_set_mouse_button_released_evt(
			evt, sf_Event_MouseButtonReleased_from_real(mouse_btn_released)
		);
	} else if (const auto* mouse_moved = event->getIf<sf::Event::MouseMoved>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseMoved);
		sf_Event_set_mouse_moved_evt(
			evt, sf_Event_MouseMoved_from_real(mouse_moved)
		);
	} else if (const auto* mouse_moved_raw = event->getIf<sf::Event::MouseMovedRaw>()) {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseMovedRaw);
		sf_Event_set_mouse_moved_raw_evt(
			evt, sf_Event_MouseMovedRaw_from_real(mouse_moved_raw)
		);
	} else {
		sf_Event_set_type(evt, SFML_SIMPLE_WRAPPER_sf_Event_Unknown);
	}
	return evt;
}
