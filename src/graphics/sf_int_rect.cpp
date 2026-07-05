#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics/Rect.hpp>

#include "../../headers/system/sf_vector2i.h"

#include "../../headers/graphics/sf_int_rect.h"


sf_IntRect sf_IntRect_default() {
	sf::IntRect* self = new sf::IntRect();
	if (!self) {
		std::cerr << "Could not create sf_IntRect in sf_IntRect_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_IntRect>(self);
}

sf_IntRect sf_IntRect_init(int left, int top, int width, int height) {
	sf::IntRect* self = new sf::IntRect(sf::Vector2i(left, top), sf::Vector2i(width, height));
	if (!self) {
		std::cerr << "Could not create sf_IntRect in sf_IntRect_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_IntRect>(self);
}

void* sf_IntRect_del(sf_IntRect obj) {
	sf::IntRect* self = static_cast<sf::IntRect*>(obj);
	delete self;
	return NULL;
}

sf_Vector2i sf_IntRect_get_lefttop(sf_IntRect self) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	return sf_Vector2i_init(s->position.x, s->position.y);
}

void sf_IntRect_set_lefttop(sf_IntRect self, int left, int top) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	s->position.x = left;
	s->position.y = top;
}

sf_Vector2i sf_IntRect_get_widthheight(sf_IntRect self) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	return sf_Vector2i_init(s->size.x, s->size.y);
}

void sf_IntRect_set_widthheight(sf_IntRect self, int width, int height) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	s->size.x = width;
	s->size.y = height;
}

sf_Vector2i sf_IntRect_get_center(sf_IntRect self) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	sf::Vector2i center = s->getCenter();
	return sf_Vector2i_init(center.x, center.y);
}

void sf_IntRect_set_center(sf_IntRect self, int cx, int cy) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	int top = cy - s->size.y / 2;
	int left = cx - s->size.x / 2;
	s->position.x = left;
	s->position.y = top;
}

int sf_IntRect_contains(sf_IntRect self, int x, int y) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	return s->contains(sf::Vector2i(x, y));
}

int sf_IntRect_is_empty(sf_IntRect self) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	return (
		s->position.x == 0
		&& s->position.y == 0
		&& s->size.x == 0
		&& s->size.y == 0
	);
}

sf_IntRect sf_IntRect_intersects(sf_IntRect self, sf_IntRect other) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	sf::IntRect* o = static_cast<sf::IntRect*>(other);
	std::optional<sf::IntRect> ins = s->findIntersection(*o);
	sf_IntRect intersection;
	if (ins.has_value()) {
		auto& intr = *ins;
		intersection = sf_IntRect_init(
			intr.position.x, intr.position.y,
			intr.size.x, intr.size.y
		);
	} else {
		intersection = sf_IntRect_default();
	}
	return intersection;
}

int sf_IntRect_is_equal(sf_IntRect self, sf_IntRect other) {
	sf::IntRect* s = static_cast<sf::IntRect*>(self);
	sf::IntRect* o = static_cast<sf::IntRect*>(other);
	return *s == *o;
}

int sf_IntRect_is_ne(sf_IntRect self, sf_IntRect other) {
	return !sf_IntRect_is_equal(self, other);
}
