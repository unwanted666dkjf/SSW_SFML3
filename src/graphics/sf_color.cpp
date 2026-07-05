#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Color.hpp>

#include "../../headers/graphics/sf_color.h"


sf_Color sf_Color_from_integer(unsigned int color) {
	sf::Color* self = new sf::Color(color);
	if (!self) {
		std::cerr << "Could not create sf_Color in sf_Color_from_integer!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Color>(self);
}

sf_Color sf_Color_from_rgb(
	unsigned char red,
	unsigned char green,
	unsigned char blue
) {
	sf::Color* self = new sf::Color(red, green, blue);
	if (!self) {
		std::cerr << "Could not create sf_Color in sf_Color_from_rgb!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Color>(self);
}

sf_Color sf_Color_from_rgba(
	unsigned char red,
	unsigned char green,
	unsigned char blue,
	unsigned char alpha
) {
	sf::Color* self = new sf::Color(red, green, blue, alpha);
	if (!self) {
		std::cerr << "Could not create sf_Color in sf_Color_from_rgba!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Color>(self);
}

void* sf_Color_del(sf_Color obj) {
	sf::Color* self = static_cast<sf::Color*>(obj);
	delete self;
	return NULL;
}

unsigned int sf_Color_to_integer(sf_Color self) {
	sf::Color* s = static_cast<sf::Color*>(self);
	return s->toInteger();
}

unsigned char sf_Color_get_red(sf_Color self) {
	sf::Color* s = static_cast<sf::Color*>(self);
	return s->r;
}

unsigned char sf_Color_get_green(sf_Color self) {
	sf::Color* s = static_cast<sf::Color*>(self);
	return s->g;
}

unsigned char sf_Color_get_blue(sf_Color self) {
	sf::Color* s = static_cast<sf::Color*>(self);
	return s->b;
}

unsigned char sf_Color_get_alpha(sf_Color self) {
	sf::Color* s = static_cast<sf::Color*>(self);
	return s->a;
}

int sf_Color_is_equal(sf_Color self, sf_Color other) {
	sf::Color* s = static_cast<sf::Color*>(self);
	sf::Color* o = static_cast<sf::Color*>(other);
	return *s == *o;
}

int sf_Color_is_ne(sf_Color self, sf_Color other) {
	return !sf_Color_is_equal(self, other);
}

sf_Color sf_Color_add(sf_Color self, sf_Color other) {
	sf::Color* s = static_cast<sf::Color*>(self);
	sf::Color* o = static_cast<sf::Color*>(other);
	sf::Color a = *s + *o;
	return sf_Color_from_rgba(a.r, a.g, a.b, a.a);
}

sf_Color sf_Color_sub(sf_Color self, sf_Color other) {
	sf::Color* s = static_cast<sf::Color*>(self);
	sf::Color* o = static_cast<sf::Color*>(other);
	sf::Color a = *s - *o;
	return sf_Color_from_rgba(a.r, a.g, a.b, a.a);
}

sf_Color sf_Color_mul(sf_Color self, sf_Color other) {
	sf::Color* s = static_cast<sf::Color*>(self);
	sf::Color* o = static_cast<sf::Color*>(other);
	sf::Color a = (*s) * (*o);
	return sf_Color_from_rgba(a.r, a.g, a.b, a.a);
}
