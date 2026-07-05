#include <iostream>

#include <cmath>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector2.hpp>

#include "../../headers/system/sf_vector2u.h"


sf_Vector2u sf_Vector2u_init(unsigned int x, unsigned int y) {
	sf::Vector2u* self = new sf::Vector2u(x, y);
	if (!self) {
		std::cerr << "Could not create sf_Vector2u in sf_Vector2u_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Vector2u>(self);
}

void* sf_Vector2u_del(sf_Vector2u obj) {
	sf::Vector2u* self = static_cast<sf::Vector2u*>(obj);
	delete self;
	return NULL;
}

unsigned int sf_Vector2u_get_x(sf_Vector2u self) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	return s->x;
}

void sf_Vector2u_set_x(sf_Vector2u self, unsigned int x) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	s->x = x;
}

unsigned int sf_Vector2u_get_y(sf_Vector2u self) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	return s->y;
}

void sf_Vector2u_set_y(sf_Vector2u self, unsigned int y) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	s->y = y;
}

float sf_Vector2u_length(sf_Vector2u self) {
	return std::sqrt(sf_Vector2u_length_squared(self));
}

float sf_Vector2u_length_squared(sf_Vector2u self) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	return s->lengthSquared();
}

sf_Vector2u sf_Vector2u_perpendicular(sf_Vector2u self) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u perp = s->perpendicular();
	sf::Vector2u* res = new sf::Vector2u(perp);
	return static_cast<sf_Vector2u>(res);
}

unsigned int sf_Vector2u_dot(sf_Vector2u self, sf_Vector2u rhs) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* r = static_cast<sf::Vector2u*>(rhs);
	return s->dot(*r);
}

unsigned int sf_Vector2u_cross(sf_Vector2u self, sf_Vector2u rhs) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* r = static_cast<sf::Vector2u*>(rhs);
	return s->cross(*r);
}

sf_Vector2u sf_Vector2u_component_wise_mul(sf_Vector2u self, sf_Vector2u rhs) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* r = static_cast<sf::Vector2u*>(rhs);
	sf::Vector2u wise = s->componentWiseMul(*r);
	sf::Vector2u* res = new sf::Vector2u(wise);
	return static_cast<sf_Vector2u>(res);
}

sf_Vector2u sf_Vector2u_component_wise_div(sf_Vector2u self, sf_Vector2u rhs) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* r = static_cast<sf::Vector2u*>(rhs);
	sf::Vector2u wise = s->componentWiseDiv(*r);
	sf::Vector2u* res = new sf::Vector2u(wise);
	return static_cast<sf_Vector2u>(res);
}

int sf_Vector2u_is_equal(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	return *s == *o;
}

int sf_Vector2u_is_greater(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	return s->lengthSquared() > o->lengthSquared();
}

int sf_Vector2u_is_lesser(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	return s->lengthSquared() < o->lengthSquared();
}

int sf_Vector2u_is_ne(sf_Vector2u self, sf_Vector2u other) {
	return !sf_Vector2u_is_equal(self, other);
}

int sf_Vector2u_is_ge(sf_Vector2u self, sf_Vector2u other) {
	return sf_Vector2u_is_greater(self, other) || sf_Vector2u_is_equal(self, other);
}

int sf_Vector2u_is_le(sf_Vector2u self, sf_Vector2u other) {
	return sf_Vector2u_is_lesser(self, other) || sf_Vector2u_is_equal(self, other);
}

sf_Vector2u sf_Vector2u_sub(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	sf::Vector2u* res = new sf::Vector2u(s->x - o->x, s->y - o->y);
	return res;
}

sf_Vector2u sf_Vector2u_add(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	sf::Vector2u* res = new sf::Vector2u(s->x + o->x, s->y + o->y);
	return res;
}

sf_Vector2u sf_Vector2u_mul(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	sf::Vector2u* res = new sf::Vector2u(s->x * o->x, s->y * o->y);
	return res;
}

sf_Vector2u sf_Vector2u_truediv(sf_Vector2u self, sf_Vector2u other) {
	sf::Vector2u* s = static_cast<sf::Vector2u*>(self);
	sf::Vector2u* o = static_cast<sf::Vector2u*>(other);
	sf::Vector2u* res = new sf::Vector2u(s->x / o->x, s->y / o->y);
	return res;
}
