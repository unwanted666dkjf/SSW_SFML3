#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Time.hpp>

#include "../../headers/system/sf_time.h"


sf_Time sf_Time_from_seconds(float amount) {
	sf::Time* self = new sf::Time(sf::seconds(amount));
	if (!self) {
		std::cerr << "Could not create sf_Time in sf_Time_from_seconds!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Time>(self);
}

sf_Time sf_Time_from_milliseconds(long amount) {
	sf::Time* self = new sf::Time(sf::milliseconds(amount));
	if (!self) {
		std::cerr << "Could not create sf_Time in sf_Time_from_milliseconds!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Time>(self);
}

sf_Time sf_Time_from_microseconds(long long amount) {
	sf::Time* self = new sf::Time(sf::microseconds(amount));
	if (!self) {
		std::cerr << "Could not create sf_Time in sf_Time_from_microseconds!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Time>(self);
}

void* sf_Time_del(sf_Time obj) {
	sf::Time* self = static_cast<sf::Time*>(obj);
	delete self;
	return NULL;
}

float sf_Time_as_seconds(sf_Time self) {
	sf::Time* s = static_cast<sf::Time*>(self);
	return s->asSeconds();
}

long sf_Time_as_milliseconds(sf_Time self) {
	sf::Time* s = static_cast<sf::Time*>(self);
	return s->asMilliseconds();
}

long long sf_Time_as_microseconds(sf_Time self) {
	sf::Time* s = static_cast<sf::Time*>(self);
	return s->asMicroseconds();
}

int sf_Time_is_equal(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	return *s == *o;
}

int sf_Time_is_greater(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	return *s > *o;
}

int sf_Time_is_lesser(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	return *s < *o;
}

int sf_Time_is_ne(sf_Time self, const sf_Time other) {
	return !sf_Time_is_equal(self, other);
}

int sf_Time_is_ge(sf_Time self, const sf_Time other) {
	return sf_Time_is_greater(self, other) || sf_Time_is_equal(self, other);
}

int sf_Time_is_le(sf_Time self, const sf_Time other) {
	return sf_Time_is_lesser(self, other) || sf_Time_is_equal(self, other);
}

sf_Time sf_Time_add(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	sf::Time t = sf::microseconds(s->asMicroseconds() + o->asMicroseconds());
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

sf_Time sf_Time_sub(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	sf::Time t = sf::microseconds(s->asMicroseconds() - o->asMicroseconds());
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

sf_Time sf_Time_mul(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	sf::Time t = sf::seconds(s->asSeconds() * o->asSeconds());
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

sf_Time sf_Time_truediv(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	sf::Time t = sf::seconds(s->asSeconds() / o->asSeconds());
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

sf_Time sf_Time_mod(sf_Time self, const sf_Time other) {
	sf::Time* s = static_cast<sf::Time*>(self);
	const sf::Time* o = static_cast<const sf::Time*>(other);
	sf::Time t = sf::microseconds(s->asMicroseconds() % o->asMicroseconds());
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}
