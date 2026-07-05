#include <iostream>

#include <cmath>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector2.hpp>

#include "../../headers/system/sf_vector2i.h"


sf_Vector2i sf_Vector2i_init(int x, int y) {
	sf::Vector2i* self = new sf::Vector2i(x, y);
	if (!self) {
		std::cerr << "Could not create sf_Vector2i in sf_Vector2i_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Vector2i>(self);
}

void* sf_Vector2i_del(sf_Vector2i obj) {
	sf::Vector2i* self = static_cast<sf::Vector2i*>(obj);
	delete self;
	return NULL;
}

int sf_Vector2i_get_x(sf_Vector2i self) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	return s->x;
}

void sf_Vector2i_set_x(sf_Vector2i self, int x) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	s->x = x;
}

int sf_Vector2i_get_y(sf_Vector2i self) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	return s->y;
}

void sf_Vector2i_set_y(sf_Vector2i self, int y) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	s->y = y;
}

float sf_Vector2i_length(sf_Vector2i self) {
	return std::sqrt(sf_Vector2i_length_squared(self));
}

float sf_Vector2i_length_squared(sf_Vector2i self) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	return s->lengthSquared();
}

sf_Vector2i sf_Vector2i_perpendicular(sf_Vector2i self) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i perp = s->perpendicular();
	sf::Vector2i* res = new sf::Vector2i(perp);
	return static_cast<sf_Vector2i>(res);
}

int sf_Vector2i_dot(sf_Vector2i self, sf_Vector2i rhs) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* r = static_cast<sf::Vector2i*>(rhs);
	return s->dot(*r);
}

int sf_Vector2i_cross(sf_Vector2i self, sf_Vector2i rhs) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* r = static_cast<sf::Vector2i*>(rhs);
	return s->cross(*r);
}

sf_Vector2i sf_Vector2i_component_wise_mul(sf_Vector2i self, sf_Vector2i rhs) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* r = static_cast<sf::Vector2i*>(rhs);
	sf::Vector2i wise = s->componentWiseMul(*r);
	sf::Vector2i* res = new sf::Vector2i(wise);
	return static_cast<sf_Vector2i>(res);
}

sf_Vector2i sf_Vector2i_component_wise_div(sf_Vector2i self, sf_Vector2i rhs) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* r = static_cast<sf::Vector2i*>(rhs);
	sf::Vector2i wise = s->componentWiseDiv(*r);
	sf::Vector2i* res = new sf::Vector2i(wise);
	return static_cast<sf_Vector2i>(res);
}

int sf_Vector2i_is_equal(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	return *s == *o;
}

int sf_Vector2i_is_greater(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	return s->lengthSquared() > o->lengthSquared();
}

int sf_Vector2i_is_lesser(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	return s->lengthSquared() < o->lengthSquared();
}

int sf_Vector2i_is_ne(sf_Vector2i self, sf_Vector2i other) {
	return !sf_Vector2i_is_equal(self, other);
}

int sf_Vector2i_is_ge(sf_Vector2i self, sf_Vector2i other) {
	return sf_Vector2i_is_greater(self, other) || sf_Vector2i_is_equal(self, other);
}

int sf_Vector2i_is_le(sf_Vector2i self, sf_Vector2i other) {
	return sf_Vector2i_is_lesser(self, other) || sf_Vector2i_is_equal(self, other);
}

sf_Vector2i sf_Vector2i_sub(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	sf::Vector2i* res = new sf::Vector2i(s->x - o->x, s->y - o->y);
	return res;
}

sf_Vector2i sf_Vector2i_add(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	sf::Vector2i* res = new sf::Vector2i(s->x + o->x, s->y + o->y);
	return res;
}

sf_Vector2i sf_Vector2i_mul(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	sf::Vector2i* res = new sf::Vector2i(s->x * o->x, s->y * o->y);
	return res;
}

sf_Vector2i sf_Vector2i_truediv(sf_Vector2i self, sf_Vector2i other) {
	sf::Vector2i* s = static_cast<sf::Vector2i*>(self);
	sf::Vector2i* o = static_cast<sf::Vector2i*>(other);
	sf::Vector2i* res = new sf::Vector2i(s->x / o->x, s->y / o->y);
	return res;
}
