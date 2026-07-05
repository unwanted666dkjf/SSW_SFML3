#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector3.hpp>

#include "../../headers/system/sf_vector3f.h"


sf_Vector3f sf_Vector3f_init(float x, float y, float z) {
	sf::Vector3f* self = new sf::Vector3f(x, y, z);
	if (!self) {
		std::cerr << "Could not create sf_Vector3f in sf_Vector3f_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Vector3f>(self);
}

void* sf_Vector3f_del(sf_Vector3f obj) {
	sf::Vector3f* self = static_cast<sf::Vector3f*>(obj);
	delete self;
	return NULL;
}

float sf_Vector3f_get_x(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	return s->x;
}

void sf_Vector3f_set_x(sf_Vector3f self, float x) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	s->x = x;
}

float sf_Vector3f_get_y(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	return s->y;
}

void sf_Vector3f_set_y(sf_Vector3f self, float y) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	s->y = y;
}

float sf_Vector3f_get_z(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	return s->z;
}

void sf_Vector3f_set_z(sf_Vector3f self, float z) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	s->z = z;
}

float sf_Vector3f_length(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	return s->length();
}

float sf_Vector3f_length_squared(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	return s->lengthSquared();
}

sf_Vector3f sf_Vector3f_normalized(sf_Vector3f self) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f v = s->normalized();
	sf::Vector3f* res = new sf::Vector3f(v);
	return static_cast<sf_Vector3f>(res);
}

float sf_Vector3f_dot(sf_Vector3f self, sf_Vector3f rhs) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* r = static_cast<sf::Vector3f*>(rhs);
	return s->dot(*r);
}

sf_Vector3f sf_Vector3f_cross(sf_Vector3f self, sf_Vector3f rhs) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* r = static_cast<sf::Vector3f*>(rhs);
	sf::Vector3f c = s->cross(*r);
	sf::Vector3f* res = new sf::Vector3f(c);
	return static_cast<sf_Vector3f>(res);
}

sf_Vector3f sf_Vector3f_component_wise_mul(sf_Vector3f self, sf_Vector3f rhs) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* r = static_cast<sf::Vector3f*>(rhs);
	sf::Vector3f wise = s->componentWiseMul(*r);
	sf::Vector3f* res = new sf::Vector3f(wise);
	return static_cast<sf_Vector3f>(res);
}

sf_Vector3f sf_Vector3f_component_wise_div(sf_Vector3f self, sf_Vector3f rhs) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* r = static_cast<sf::Vector3f*>(rhs);
	sf::Vector3f wise = s->componentWiseDiv(*r);
	sf::Vector3f* res = new sf::Vector3f(wise);
	return static_cast<sf_Vector3f>(res);
}

int sf_Vector3f_is_equal(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	return *s == *o;
}

int sf_Vector3f_is_greater(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	return s->lengthSquared() > o->lengthSquared();
}

int sf_Vector3f_is_lesser(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	return s->lengthSquared() < o->lengthSquared();
}

int sf_Vector3f_is_ne(sf_Vector3f self, sf_Vector3f other) {
	return !sf_Vector3f_is_equal(self, other);
}

int sf_Vector3f_is_ge(sf_Vector3f self, sf_Vector3f other) {
	return sf_Vector3f_is_greater(self, other) || sf_Vector3f_is_equal(self, other);
}

int sf_Vector3f_is_le(sf_Vector3f self, sf_Vector3f other) {
	return sf_Vector3f_is_lesser(self, other) || sf_Vector3f_is_equal(self, other);
}

sf_Vector3f sf_Vector3f_sub(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	sf::Vector3f* res = new sf::Vector3f(
		s->x - o->x,
		s->y - o->y,
		s->z - o->z
	);
	return res;
}

sf_Vector3f sf_Vector3f_add(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	sf::Vector3f* res = new sf::Vector3f(
		s->x + o->x,
		s->y + o->y,
		s->z + o->z
	);
	return res;
}

sf_Vector3f sf_Vector3f_mul(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	sf::Vector3f* res = new sf::Vector3f(
		s->x * o->x,
		s->y * o->y,
		s->z * o->z
	);
	return res;
}

sf_Vector3f sf_Vector3f_truediv(sf_Vector3f self, sf_Vector3f other) {
	sf::Vector3f* s = static_cast<sf::Vector3f*>(self);
	sf::Vector3f* o = static_cast<sf::Vector3f*>(other);
	sf::Vector3f* res = new sf::Vector3f(
		s->x / o->x,
		s->y / o->y,
		s->z / o->z
	);
	return res;
}
