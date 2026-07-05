#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/Rect.hpp>

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_float_rect.h"


sf_FloatRect sf_FloatRect_default() {
	sf::FloatRect* self = new sf::FloatRect();
	if (!self) {
		std::cerr << "Could not create sf_FloatRect in sf_FloatRect_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_FloatRect>(self);
}

sf_FloatRect sf_FloatRect_init(float left, float top, float width, float height) {
	sf::FloatRect* self = new sf::FloatRect(sf::Vector2f(left, top), sf::Vector2f(width, height));
	if (!self) {
		std::cerr << "Could not create sf_FloatRect in sf_FloatRect_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_FloatRect>(self);
}

void* sf_FloatRect_del(sf_FloatRect obj) {
	sf::FloatRect* self = static_cast<sf::FloatRect*>(obj);
	delete self;
	return NULL;
}

sf_Vector2f sf_FloatRect_get_lefttop(sf_FloatRect self) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	return sf_Vector2f_init(s->position.x, s->position.y);
}

void sf_FloatRect_set_lefttop(sf_FloatRect self, float left, float top) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	s->position.x = left;
	s->position.y = top;
}

sf_Vector2f sf_FloatRect_get_widthheight(sf_FloatRect self) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	return sf_Vector2f_init(s->size.x, s->size.y);
}

void sf_FloatRect_set_widthheight(sf_FloatRect self, float width, float height) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	s->size.x = width;
	s->size.y = height;
}

sf_Vector2f sf_FloatRect_get_center(sf_FloatRect self) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	sf::Vector2f center = s->getCenter();
	return sf_Vector2f_init(center.x, center.y);
}

void sf_FloatRect_set_center(sf_FloatRect self, float cx, float cy) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	float top = cy - s->size.y / 2;
	float left = cx - s->size.x / 2;
	s->position.x = left;
	s->position.y = top;
}

int sf_FloatRect_contains(sf_FloatRect self, float x, float y) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	return s->contains(sf::Vector2f(x, y));
}

int sf_FloatRect_is_empty(sf_FloatRect self) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	return (
		s->position.x == 0
		&& s->position.y == 0
		&& s->size.x == 0
		&& s->size.y == 0
	);
}

sf_FloatRect sf_FloatRect_intersects(sf_FloatRect self, sf_FloatRect other) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	sf::FloatRect* o = static_cast<sf::FloatRect*>(other);
	std::optional<sf::FloatRect> ins = s->findIntersection(*o);
	sf_FloatRect intersection;
	if (ins.has_value()) {
		auto& intr = *ins;
		intersection = sf_FloatRect_init(
			intr.position.x, intr.position.y,
			intr.size.x, intr.size.y
		);
	} else {
		intersection = sf_FloatRect_default();
	}
	return intersection;
}

int sf_FloatRect_is_equal(sf_FloatRect self, sf_FloatRect other) {
	sf::FloatRect* s = static_cast<sf::FloatRect*>(self);
	sf::FloatRect* o = static_cast<sf::FloatRect*>(other);
	return *s == *o;
}

int sf_FloatRect_is_ne(sf_FloatRect self, sf_FloatRect other) {
	return !sf_FloatRect_is_equal(self, other);
}
