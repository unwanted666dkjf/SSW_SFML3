#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Transform.hpp>

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_transform.h"


sf_Transform sf_Transform_default() {
	sf::Transform* self = new sf::Transform();
	if (!self) {
		std::cerr << "Could not create sf_Transform in sf_Transform_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Transform>(self);
}

sf_Transform sf_Transform_init(
	float a00, float a01, float a02,
	float a10, float a11, float a12,
	float a20, float a21, float a22
) {
	sf::Transform* self = new sf::Transform(
		a00, a01, a02,
		a10, a11, a12,
		a20, a21, a22
	);
	if (!self) {
		std::cerr << "Could not create sf_Transform in sf_Transform_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Transform>(self);
}

void* sf_Transform_del(sf_Transform obj) {
	sf::Transform* self = static_cast<sf::Transform*>(obj);
	delete self;
	return NULL;
}

const float* sf_Transform_get_matrix(sf_Transform self) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	return s->getMatrix();
}

sf_Transform sf_Transform_get_inverse(sf_Transform self) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	sf::Transform* res = new sf::Transform(s->getInverse());
	return static_cast<sf_Transform>(res);
}

sf_Vector2f sf_Transform_transform_point(sf_Transform self, float x, float y) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	sf::Vector2f p = s->transformPoint(sf::Vector2f(x, y));
	return sf_Vector2f_init(p.x, p.y);
}

sf_FloatRect sf_Transform_transform_rect(sf_Transform self, const sf_FloatRect rect) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	const sf::FloatRect* r = static_cast<const sf::FloatRect*>(rect);
	sf::FloatRect res = s->transformRect(*r);
	return sf_FloatRect_init(
		res.position.x, res.position.y,
		res.size.x, res.size.y
	);
}

void sf_Transform_combine(sf_Transform self, const sf_Transform transform) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	const sf::Transform* t = static_cast<const sf::Transform*>(transform);
	s->combine(*t);
}

void sf_Transform_translate(sf_Transform self, float dx, float dy) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	s->translate(sf::Vector2f(dx, dy));
}

void sf_Transform_rotate(sf_Transform self, sf_Angle angle) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	sf::Angle* a = static_cast<sf::Angle*>(angle);
	s->rotate(*a);
}

void sf_Transform_rotate_center(sf_Transform self, sf_Angle angle, float cx, float cy) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	sf::Angle* a = static_cast<sf::Angle*>(angle);
	s->rotate(*a, sf::Vector2f(cx, cy));
}

void sf_Transform_scale(sf_Transform self, float kx, float ky) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	s->scale(sf::Vector2f(kx, ky));
}

void sf_Transform_scale_center(sf_Transform self,
	float kx, float ky,
	float cx, float cy
) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	s->scale(sf::Vector2f(kx, ky), sf::Vector2f(cx, cy));
}

int sf_Transform_is_equal(sf_Transform self, const sf_Transform other) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	const sf::Transform* o = static_cast<const sf::Transform*>(other);
	return *s == *o;
}

int sf_Transform_is_ne(sf_Transform self, const sf_Transform other) {
	return !sf_Transform_is_equal(self, other);
}

sf_Transform sf_Transform_mul(sf_Transform self, const sf_Transform other) {
	sf::Transform* s = static_cast<sf::Transform*>(self);
	const sf::Transform* o = static_cast<const sf::Transform*>(other);
	sf::Transform m = (*s) * (*o);
	sf::Transform* res = new sf::Transform(m);
	return static_cast<sf_Transform>(res);
}

sf_Vector2f sf_Transform_mul_vector(sf_Transform self, sf_Vector2f vector) {
	sf::Vector2f* v = static_cast<sf::Vector2f*>(vector);
	return sf_Transform_transform_point(self, v->x, v->y);
}
