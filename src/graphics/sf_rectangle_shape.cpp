#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Texture.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics/RectangleShape.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_color.h"

#include "../../headers/graphics/sf_int_rect.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_rectangle_shape.h"


sf_RectangleShape sf_RectangleShape_init(float width, float height) {
	sf::RectangleShape* self = new sf::RectangleShape(sf::Vector2f(width, height));
	if (!self) {
		std::cerr << "Could not create sf_RectangleShape in sf_RectangleShape_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RectangleShape>(self);
}

void* sf_RectangleShape_del(sf_RectangleShape obj) {
	sf::RectangleShape* self = static_cast<sf::RectangleShape*>(obj);
	delete self;
	return NULL;
}

sf_Vector2f sf_RectangleShape_get_size(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f v = s->getSize();
	return sf_Vector2f_init(v.x, v.y);
}

void sf_RectangleShape_set_size(sf_RectangleShape self, float width, float height) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setSize(sf::Vector2f(width, height));
}

unsigned long sf_RectangleShape_get_point_count(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	return static_cast<unsigned long>(s->getPointCount());
}

sf_Vector2f sf_RectangleShape_get_point(sf_RectangleShape self, unsigned long index) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f v = s->getPoint(index);
	return sf_Vector2f_init(v.x, v.y);
}

sf_Vector2f sf_RectangleShape_get_geometric_center(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f v = s->getGeometricCenter();
	return sf_Vector2f_init(v.x, v.y);
}

void sf_RectangleShape_draw(sf_RectangleShape self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	const sf::RenderStates* st = static_cast<const sf::RenderStates*>(states);
	w->draw(*s, *st);
}

void sf_RectangleShape_set_texture(sf_RectangleShape self,
	const sf_Texture texture,
	int reset_rect
) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	s->setTexture(t, reset_rect);
}

void sf_RectangleShape_set_texture_rect(sf_RectangleShape self, const sf_IntRect rect) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	const sf::IntRect* r = static_cast<const sf::IntRect*>(rect);
	s->setTextureRect(*r);
}

void sf_RectangleShape_set_fill_color(sf_RectangleShape self, sf_Color color) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setFillColor(*clr);
}

void sf_RectangleShape_set_outline_color(sf_RectangleShape self, sf_Color color) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setOutlineColor(*clr);
}

void sf_RectangleShape_set_outline_thickness(sf_RectangleShape self, float thickness) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setOutlineThickness(thickness);
}

void sf_RectangleShape_set_miter_limit(sf_RectangleShape self, float limit) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setMiterLimit(limit);
}

sf_Texture sf_RectangleShape_get_texture(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	return static_cast<sf_Texture>(new sf::Texture(*(s->getTexture())));
}

sf_IntRect sf_RectangleShape_get_texture_rect(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::IntRect r = s->getTextureRect();
	return sf_IntRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_Color sf_RectangleShape_get_fill_color(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Color clr = s->getFillColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

sf_Color sf_RectangleShape_get_outline_color(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Color clr = s->getOutlineColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

float sf_RectangleShape_get_outline_thickness(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	return s->getOutlineThickness();
}

float sf_RectangleShape_get_miter_limit(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	return s->getMiterLimit();
}

sf_FloatRect sf_RectangleShape_get_global_bounds(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::FloatRect r = s->getGlobalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_FloatRect sf_RectangleShape_get_local_bounds(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::FloatRect r = s->getLocalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

void sf_RectangleShape_set_position(sf_RectangleShape self, float left, float top) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setPosition(sf::Vector2f(left, top));
}

void sf_RectangleShape_set_rotation(sf_RectangleShape self, sf_Angle angle) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->setRotation(*rot);
}

void sf_RectangleShape_set_scale(sf_RectangleShape self, float kx, float ky) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setScale(sf::Vector2f(kx, ky));
}

void sf_RectangleShape_set_origin(sf_RectangleShape self, float ox, float oy) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->setOrigin(sf::Vector2f(ox, oy));
}

sf_Vector2f sf_RectangleShape_get_position(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f p = s->getPosition();
	return sf_Vector2f_init(p.x, p.y);
}

sf_Angle sf_RectangleShape_get_rotation(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Angle rot = s->getRotation();
	return sf_Angle_from_degrees(rot.asDegrees());
}

sf_Vector2f sf_RectangleShape_get_scale(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f sca = s->getScale();
	return sf_Vector2f_init(sca.x, sca.y);
}

sf_Vector2f sf_RectangleShape_get_origin(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Vector2f orig = s->getOrigin();
	return sf_Vector2f_init(orig.x, orig.y);
}

void sf_RectangleShape_move(sf_RectangleShape self, float dx, float dy) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->move(sf::Vector2f(dx, dy));
}

void sf_RectangleShape_rotate(sf_RectangleShape self, sf_Angle angle) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->rotate(*rot);
}

void sf_RectangleShape_scale(sf_RectangleShape self, float kx, float ky) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	s->scale(sf::Vector2f(kx, ky));
}

sf_Transform sf_RectangleShape_get_transform(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Transform* res = new sf::Transform(s->getTransform());
	return static_cast<sf_Transform>(res);
}

sf_Transform sf_RectangleShape_get_inverse_transform(sf_RectangleShape self) {
	sf::RectangleShape* s = static_cast<sf::RectangleShape*>(self);
	sf::Transform* res = new sf::Transform(s->getInverseTransform());
	return static_cast<sf_Transform>(res);
}
