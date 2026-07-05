#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics/Texture.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_color.h"

#include "../../headers/graphics/sf_int_rect.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_sprite.h"


sf_Sprite sf_Sprite_from_rect(const sf_Texture texture, const sf_IntRect rect) {
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	const sf::IntRect* r = static_cast<const sf::IntRect*>(rect);
	sf::Sprite* self = new sf::Sprite(*t, *r);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Sprite_from_rect!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Sprite>(self);
}

sf_Sprite sf_Sprite_init(const sf_Texture texture) {
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	sf::Sprite* self = new sf::Sprite(*t);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Sprite_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Sprite>(self);
}

void* sf_Sprite_del(sf_Sprite obj) {
	sf::Sprite* self = static_cast<sf::Sprite*>(obj);
	delete self;
	return NULL;
}

void sf_Sprite_set_texture(sf_Sprite self, const sf_Texture texture, int reset_rect) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	s->setTexture(*t, reset_rect);
}

void sf_Sprite_set_texture_rect(sf_Sprite self, const sf_IntRect rect) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	const sf::IntRect* r = static_cast<const sf::IntRect*>(rect);
	s->setTextureRect(*r);
}

void sf_Sprite_set_color(sf_Sprite self, sf_Color color) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setColor(*clr);
}

sf_Texture sf_Sprite_get_texture(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	return static_cast<sf_Texture>(new sf::Texture(s->getTexture()));
}

sf_IntRect sf_Sprite_get_texture_rect(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::IntRect r = s->getTextureRect();
	return sf_IntRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_Color sf_Sprite_get_color(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Color clr = s->getColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

sf_FloatRect sf_Sprite_get_local_bounds(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::FloatRect r = s->getLocalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_FloatRect sf_Sprite_get_global_bounds(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::FloatRect r = s->getGlobalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

void sf_Sprite_draw(sf_Sprite self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	const sf::RenderStates* st = static_cast<const sf::RenderStates*>(states);
	w->draw(*s, *st);
}

void sf_Sprite_set_position(sf_Sprite self, float left, float top) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	s->setPosition(sf::Vector2f(left, top));
}

void sf_Sprite_set_rotation(sf_Sprite self, sf_Angle angle) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->setRotation(*rot);
}

void sf_Sprite_set_scale(sf_Sprite self, float kx, float ky) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	s->setScale(sf::Vector2f(kx, ky));
}

void sf_Sprite_set_origin(sf_Sprite self, float ox, float oy) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	s->setOrigin(sf::Vector2f(ox, oy));
}

sf_Vector2f sf_Sprite_get_position(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Vector2f p = s->getPosition();
	return sf_Vector2f_init(p.x, p.y);
}

sf_Angle sf_Sprite_get_rotation(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Angle rot = s->getRotation();
	return sf_Angle_from_degrees(rot.asDegrees());
}

sf_Vector2f sf_Sprite_get_scale(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Vector2f sca = s->getScale();
	return sf_Vector2f_init(sca.x, sca.y);
}

sf_Vector2f sf_Sprite_get_origin(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Vector2f orig = s->getOrigin();
	return sf_Vector2f_init(orig.x, orig.y);
}

void sf_Sprite_move(sf_Sprite self, float dx, float dy) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	s->move(sf::Vector2f(dx, dy));
}

void sf_Sprite_rotate(sf_Sprite self, sf_Angle angle) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->rotate(*rot);
}

void sf_Sprite_scale(sf_Sprite self, float kx, float ky) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	s->scale(sf::Vector2f(kx, ky));
}

sf_Transform sf_Sprite_get_transform(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Transform* res = new sf::Transform(s->getTransform());
	return static_cast<sf_Transform>(res);
}

sf_Transform sf_Sprite_get_inverse_transform(sf_Sprite self) {
	sf::Sprite* s = static_cast<sf::Sprite*>(self);
	sf::Transform* res = new sf::Transform(s->getInverseTransform());
	return static_cast<sf_Transform>(res);
}
