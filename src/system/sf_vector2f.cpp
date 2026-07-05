#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Angle.hpp>

#include <SFML/System/Vector2.hpp>

#include "../../headers/system/sf_vector2f.h"


sf_Vector2f sf_Vector2f_create_polar(float r, sf_Angle phi) {
	sf::Angle* a = static_cast<sf::Angle*>(phi);
	sf::Vector2f* self = new sf::Vector2f(r, *a);
	if (!self) {
		std::cerr << "Could not create sf_Vector2f in sf_Vector2f_create_polar!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Vector2f>(self);
}

sf_Vector2f sf_Vector2f_init(float x, float y) {
	sf::Vector2f* self = new sf::Vector2f(x, y);
	if (!self) {
		std::cerr << "Could not create sf_Vector2f in sf_Vector2f_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Vector2f>(self);
}

void* sf_Vector2f_del(sf_Vector2f obj) {
	sf::Vector2f* self = static_cast<sf::Vector2f*>(obj);
	delete self;
	return NULL;
}

float sf_Vector2f_get_x(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	return s->x;
}

void sf_Vector2f_set_x(sf_Vector2f self, float x) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	s->x = x;
}

float sf_Vector2f_get_y(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	return s->y;
}

void sf_Vector2f_set_y(sf_Vector2f self, float y) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	s->y = y;
}

float sf_Vector2f_length(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	return s->length();
}

float sf_Vector2f_length_squared(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	return s->lengthSquared();
}

sf_Vector2f sf_Vector2f_normalized(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f v = s->normalized();
	sf::Vector2f* res = new sf::Vector2f(v);
	return static_cast<sf_Vector2f>(res);
}

sf_Angle sf_Vector2f_angle_to(sf_Vector2f self, sf_Vector2f rhs) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* r = static_cast<sf::Vector2f*>(rhs);
	sf::Angle a = s->angleTo(*r);
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Vector2f_angle(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Angle a = s->angle();
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Vector2f sf_Vector2f_rotated_by(sf_Vector2f self, sf_Angle phi) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Angle* a = static_cast<sf::Angle*>(phi);
	sf::Vector2f rot = s->rotatedBy(*a);
	sf::Vector2f* res = new sf::Vector2f(rot);
	return static_cast<sf_Vector2f>(res);
}

sf_Vector2f sf_Vector2f_projected_onto(sf_Vector2f self, sf_Vector2f axis) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* aqua = static_cast<sf::Vector2f*>(axis);
	sf::Vector2f proj = s->projectedOnto(*aqua);
	sf::Vector2f* res = new sf::Vector2f(proj);
	return static_cast<sf_Vector2f>(res);
}

sf_Vector2f sf_Vector2f_perpendicular(sf_Vector2f self) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f perp = s->perpendicular();
	sf::Vector2f* res = new sf::Vector2f(perp);
	return static_cast<sf_Vector2f>(res);
}

float sf_Vector2f_dot(sf_Vector2f self, sf_Vector2f rhs) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* r = static_cast<sf::Vector2f*>(rhs);
	return s->dot(*r);
}

float sf_Vector2f_cross(sf_Vector2f self, sf_Vector2f rhs) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* r = static_cast<sf::Vector2f*>(rhs);
	return s->cross(*r);
}

sf_Vector2f sf_Vector2f_component_wise_mul(sf_Vector2f self, sf_Vector2f rhs) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* r = static_cast<sf::Vector2f*>(rhs);
	sf::Vector2f wise = s->componentWiseMul(*r);
	sf::Vector2f* res = new sf::Vector2f(wise);
	return static_cast<sf_Vector2f>(res);
}

sf_Vector2f sf_Vector2f_component_wise_div(sf_Vector2f self, sf_Vector2f rhs) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* r = static_cast<sf::Vector2f*>(rhs);
	sf::Vector2f wise = s->componentWiseDiv(*r);
	sf::Vector2f* res = new sf::Vector2f(wise);
	return static_cast<sf_Vector2f>(res);
}

int sf_Vector2f_is_equal(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	return *s == *o;
}

int sf_Vector2f_is_greater(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	return s->lengthSquared() > o->lengthSquared();
}

int sf_Vector2f_is_lesser(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	return s->lengthSquared() < o->lengthSquared();
}

int sf_Vector2f_is_ne(sf_Vector2f self, sf_Vector2f other) {
	return !sf_Vector2f_is_equal(self, other);
}

int sf_Vector2f_is_ge(sf_Vector2f self, sf_Vector2f other) {
	return sf_Vector2f_is_greater(self, other) || sf_Vector2f_is_equal(self, other);
}

int sf_Vector2f_is_le(sf_Vector2f self, sf_Vector2f other) {
	return sf_Vector2f_is_lesser(self, other) || sf_Vector2f_is_equal(self, other);
}

sf_Vector2f sf_Vector2f_sub(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	sf::Vector2f* res = new sf::Vector2f(s->x - o->x, s->y - o->y);
	return res;
}

sf_Vector2f sf_Vector2f_add(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	sf::Vector2f* res = new sf::Vector2f(s->x + o->x, s->y + o->y);
	return res;
}

sf_Vector2f sf_Vector2f_mul(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	sf::Vector2f* res = new sf::Vector2f(s->x * o->x, s->y * o->y);
	return res;
}

sf_Vector2f sf_Vector2f_truediv(sf_Vector2f self, sf_Vector2f other) {
	sf::Vector2f* s = static_cast<sf::Vector2f*>(self);
	sf::Vector2f* o = static_cast<sf::Vector2f*>(other);
	sf::Vector2f* res = new sf::Vector2f(s->x / o->x, s->y / o->y);
	return res;
}
