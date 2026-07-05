#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Texture.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics/CircleShape.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_color.h"

#include "../../headers/graphics/sf_int_rect.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_circle_shape.h"


sf_CircleShape sf_CircleShape_init(float radius, unsigned long pointCount) {
	sf::CircleShape* self = new sf::CircleShape(radius, pointCount);
	if (!self) {
		std::cerr << "Could not create sf_CircleShape in sf_CircleShape_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_CircleShape>(self);
}

void* sf_CircleShape_del(sf_CircleShape obj) {
	sf::CircleShape* self = static_cast<sf::CircleShape*>(obj);
	delete self;
	return NULL;
}

float sf_CircleShape_get_radius(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	return s->getRadius();
}

void sf_CircleShape_set_radius(sf_CircleShape self, float radius) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setRadius(radius);
}

unsigned long sf_CircleShape_get_point_count(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	return static_cast<unsigned long>(s->getPointCount());
}

void sf_CircleShape_set_point_count(sf_CircleShape self, unsigned long point_count) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setPointCount(point_count);
}

sf_Vector2f sf_CircleShape_get_point(sf_CircleShape self, unsigned long index) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Vector2f p = s->getPoint(index);
	return sf_Vector2f_init(p.x, p.y);
}

sf_Vector2f sf_CircleShape_get_geometric_center(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Vector2f p = s->getGeometricCenter();
	return sf_Vector2f_init(p.x, p.y);
}

void sf_CircleShape_draw(sf_CircleShape self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	const sf::RenderStates* st = static_cast<const sf::RenderStates*>(states);
	w->draw(*s, *st);
}

void sf_CircleShape_set_texture(sf_CircleShape self,
	const sf_Texture texture,
	int reset_rect
) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	s->setTexture(t, reset_rect);
}

void sf_CircleShape_set_texture_rect(sf_CircleShape self, const sf_IntRect rect) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	const sf::IntRect* r = static_cast<const sf::IntRect*>(rect);
	s->setTextureRect(*r);
}

void sf_CircleShape_set_fill_color(sf_CircleShape self, sf_Color color) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setFillColor(*clr);
}

void sf_CircleShape_set_outline_color(sf_CircleShape self, sf_Color color) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setOutlineColor(*clr);
}

void sf_CircleShape_set_outline_thickness(sf_CircleShape self, float thickness) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setOutlineThickness(thickness);
}

void sf_CircleShape_set_miter_limit(sf_CircleShape self, float limit) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setMiterLimit(limit);
}

sf_Texture sf_CircleShape_get_texture(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	return static_cast<sf_Texture>(new sf::Texture(*(s->getTexture())));
}

sf_IntRect sf_CircleShape_get_texture_rect(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::IntRect r = s->getTextureRect();
	return sf_IntRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_Color sf_CircleShape_get_fill_color(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Color clr = s->getFillColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

sf_Color sf_CircleShape_get_outline_color(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Color clr = s->getOutlineColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

float sf_CircleShape_get_outline_thickness(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	return s->getOutlineThickness();
}

float sf_CircleShape_get_miter_limit(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	return s->getMiterLimit();
}

sf_FloatRect sf_CircleShape_get_global_bounds(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::FloatRect r = s->getGlobalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_FloatRect sf_CircleShape_get_local_bounds(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::FloatRect r = s->getLocalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

void sf_CircleShape_set_position(sf_CircleShape self, float left, float top) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setPosition(sf::Vector2f(left, top));
}

void sf_CircleShape_set_rotation(sf_CircleShape self, sf_Angle angle) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->setRotation(*rot);
}

void sf_CircleShape_set_scale(sf_CircleShape self, float kx, float ky) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setScale(sf::Vector2f(kx, ky));
}

void sf_CircleShape_set_origin(sf_CircleShape self, float ox, float oy) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->setOrigin(sf::Vector2f(ox, oy));
}

sf_Vector2f sf_CircleShape_get_position(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Vector2f p = s->getPosition();
	return sf_Vector2f_init(p.x, p.y);
}

sf_Angle sf_CircleShape_get_rotation(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Angle rot = s->getRotation();
	return sf_Angle_from_degrees(rot.asDegrees());
}

sf_Vector2f sf_CircleShape_get_scale(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Vector2f sca = s->getScale();
	return sf_Vector2f_init(sca.x, sca.y);
}

sf_Vector2f sf_CircleShape_get_origin(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Vector2f orig = s->getOrigin();
	return sf_Vector2f_init(orig.x, orig.y);
}

void sf_CircleShape_move(sf_CircleShape self, float dx, float dy) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->move(sf::Vector2f(dx, dy));
}

void sf_CircleShape_rotate(sf_CircleShape self, sf_Angle angle) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->rotate(*rot);
}

void sf_CircleShape_scale(sf_CircleShape self, float kx, float ky) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	s->scale(sf::Vector2f(kx, ky));
}

sf_Transform sf_CircleShape_get_transform(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Transform* res = new sf::Transform(s->getTransform());
	return static_cast<sf_Transform>(res);
}

sf_Transform sf_CircleShape_get_inverse_transform(sf_CircleShape self) {
	sf::CircleShape* s = static_cast<sf::CircleShape*>(self);
	sf::Transform* res = new sf::Transform(s->getInverseTransform());
	return static_cast<sf_Transform>(res);
}
