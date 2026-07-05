#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Angle.hpp>

#include "../../headers/system/sf_angle.h"


sf_Angle sf_Angle_from_degrees(float angle) {
	sf::Angle* self = new sf::Angle(sf::degrees(angle));
	if (!self) {
		std::cerr << "Could not create sf_Angle in sf_Angle_from_degrees!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Angle>(self);
}

sf_Angle sf_Angle_from_radians(float angle) {
	sf::Angle* self = new sf::Angle(sf::radians(angle));
	if (!self) {
		std::cerr << "Could not create sf_Angle in sf_Angle_from_radians!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Angle>(self);
}

void* sf_Angle_del(sf_Angle obj) {
	sf::Angle* self = static_cast<sf::Angle*>(obj);
	delete self;
	return NULL;
}

float sf_Angle_as_degrees(sf_Angle self) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	return s->asDegrees();
}

float sf_Angle_as_radians(sf_Angle self) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	return s->asRadians();
}

sf_Angle sf_Angle_wrap_signed(sf_Angle self) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	sf::Angle wrapped = s->wrapSigned();
	sf::Angle* res = new sf::Angle(wrapped);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Angle_wrap_unsigned(sf_Angle self) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	sf::Angle wrapped = s->wrapUnsigned();
	sf::Angle* res = new sf::Angle(wrapped);
	return static_cast<sf_Angle>(res);
}

int sf_Angle_is_equal(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	return *s == *o;
}

int sf_Angle_is_greater(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	return *s > *o;
}

int sf_Angle_is_lesser(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	return *s < *o;
}

int sf_Angle_is_ne(sf_Angle self, const sf_Angle other) {
	return !sf_Angle_is_equal(self, other);
}

int sf_Angle_is_ge(sf_Angle self, const sf_Angle other) {
	return sf_Angle_is_greater(self, other) || sf_Angle_is_equal(self, other);
}

int sf_Angle_is_le(sf_Angle self, const sf_Angle other) {
	return sf_Angle_is_lesser(self, other) || sf_Angle_is_equal(self, other);
}

sf_Angle sf_Angle_sub(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	sf::Angle a = sf::degrees(s->asDegrees() - o->asDegrees());
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Angle_add(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	sf::Angle a = sf::degrees(s->asDegrees() + o->asDegrees());
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Angle_mul(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	sf::Angle a = sf::degrees(s->asDegrees() * o->asDegrees());
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Angle_truediv(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	sf::Angle a = sf::degrees(s->asDegrees() / o->asDegrees());
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}

sf_Angle sf_Angle_mod(sf_Angle self, const sf_Angle other) {
	sf::Angle* s = static_cast<sf::Angle*>(self);
	const sf::Angle* o = static_cast<const sf::Angle*>(other);
	sf::Angle a = *s % *o;
	sf::Angle* res = new sf::Angle(a);
	return static_cast<sf_Angle>(res);
}
