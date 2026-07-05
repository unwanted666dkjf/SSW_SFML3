#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector2.hpp>

#include <SFML/Window/VideoMode.hpp>

#include "../../headers/window/sf_video_mode.h"


sf_VideoMode sf_VideoMode_get_desktop_mode() {
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	return sf_VideoMode_init(desktop.size.x, desktop.size.y, desktop.bitsPerPixel);
}

sf_VideoMode sf_VideoMode_init(
	unsigned int width,
	unsigned int height,
	unsigned int modeBitsPerPixel
) {
	sf::VideoMode* self = new sf::VideoMode(sf::Vector2u(width, height), modeBitsPerPixel);
	if (!self) {
		std::cerr << "Could not create sf_VideoMode in sf_VideoMode_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_VideoMode>(self);
}

void* sf_VideoMode_del(sf_VideoMode obj) {
	sf::VideoMode* self = static_cast<sf::VideoMode*>(obj);
	delete self;
	return NULL;
}

int sf_VideoMode_is_valid(sf_VideoMode self) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	return s->isValid();
}

unsigned int sf_VideoMode_width(sf_VideoMode self) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	return s->size.x;
}

unsigned int sf_VideoMode_height(sf_VideoMode self) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	return s->size.y;
}

unsigned int sf_VideoMode_bits_per_pixel(sf_VideoMode self) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	return s->bitsPerPixel;
}

int sf_VideoMode_is_equal(sf_VideoMode self, const sf_VideoMode other) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	const sf::VideoMode* o = static_cast<const sf::VideoMode*>(other);
	return *s == *o;
}

int sf_VideoMode_is_greater(sf_VideoMode self, const sf_VideoMode other) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	const sf::VideoMode* o = static_cast<const sf::VideoMode*>(other);
	return *s > *o;
}

int sf_VideoMode_is_lesser(sf_VideoMode self, const sf_VideoMode other) {
	sf::VideoMode* s = static_cast<sf::VideoMode*>(self);
	const sf::VideoMode* o = static_cast<const sf::VideoMode*>(other);
	return *s < *o;
}

int sf_VideoMode_is_ne(sf_VideoMode self, const sf_VideoMode other) {
	return !sf_VideoMode_is_equal(self, other);
}

int sf_VideoMode_is_ge(sf_VideoMode self, const sf_VideoMode other) {
	return sf_VideoMode_is_greater(self, other) || sf_VideoMode_is_equal(self, other);
}

int sf_VideoMode_is_le(sf_VideoMode self, const sf_VideoMode other) {
	return sf_VideoMode_is_lesser(self, other) || sf_VideoMode_is_equal(self, other);
}
