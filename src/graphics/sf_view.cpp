#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/View.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_view.h"

#include "../../headers/graphics/sf_float_rect.h"


sf_View sf_View_default() {
	sf::View* self = new sf::View();
	if (!self) {
		std::cerr << "Could not create sf_View in sf_View_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_View>(self);
}

sf_View sf_View_from_rect(const sf_FloatRect rect) {
	const sf::FloatRect* r = static_cast<const sf::FloatRect*>(rect);
	sf::View* self = new sf::View(*r);
	if (!self) {
		std::cerr << "Could not create sf_View in sf_View_from_rect!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_View>(self);
}

sf_View sf_View_init(float cx, float cy, float width, float height) {
	sf::View* self = new sf::View(sf::Vector2f(cx, cy), sf::Vector2f(width, height));
	if (!self) {
		std::cerr << "Could not create sf_View in sf_View_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_View>(self);
}

void* sf_View_del(sf_View obj) {
	sf::View* self = static_cast<sf::View*>(obj);
	delete self;
	return NULL;
}

void sf_View_set_center(sf_View self, float cx, float cy) {
	sf::View* s = static_cast<sf::View*>(self);
	s->setCenter(sf::Vector2f(cx, cy));
}

void sf_View_set_size(sf_View self, float width, float height) {
	sf::View* s = static_cast<sf::View*>(self);
	s->setSize(sf::Vector2f(width, height));
}

void sf_View_set_rotation(sf_View self, sf_Angle angle) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::Angle* a = static_cast<sf::Angle*>(angle);
	s->setRotation(*a);
}

void sf_View_set_viewport(sf_View self, const sf_FloatRect viewport) {
	sf::View* s = static_cast<sf::View*>(self);
	const sf::FloatRect* r = static_cast<const sf::FloatRect*>(viewport);
	s->setViewport(*r);
}

void sf_View_set_scissor(sf_View self, const sf_FloatRect scissor) {
	sf::View* s = static_cast<sf::View*>(self);
	const sf::FloatRect* r = static_cast<const sf::FloatRect*>(scissor);
	s->setScissor(*r);
}

sf_Vector2f sf_View_get_center(sf_View self) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::Vector2f c = s->getCenter();
	return sf_Vector2f_init(c.x, c.y);
}

sf_Vector2f sf_View_get_size(sf_View self) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::Vector2f size = s->getSize();
	return sf_Vector2f_init(size.x, size.y);
}

sf_Angle sf_View_get_rotation(sf_View self) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::Angle a = s->getRotation();
	return sf_Angle_from_degrees(a.asDegrees());
}

sf_FloatRect sf_View_get_viewport(sf_View self) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::FloatRect vp = s->getViewport();
	return sf_FloatRect_init(
		vp.position.x, vp.position.y,
		vp.size.x, vp.size.y
	);
}

sf_FloatRect sf_View_get_scissor(sf_View self) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::FloatRect sci = s->getScissor();
	return sf_FloatRect_init(
		sci.position.x, sci.position.y,
		sci.size.x, sci.size.y
	);
}

void sf_View_move(sf_View self, float dx, float dy) {
	sf::View* s = static_cast<sf::View*>(self);
	s->move(sf::Vector2f(dx, dy));
}

void sf_View_rotate(sf_View self, sf_Angle angle) {
	sf::View* s = static_cast<sf::View*>(self);
	sf::Angle* a = static_cast<sf::Angle*>(angle);
	s->rotate(*a);
}

void sf_View_zoom(sf_View self, float factor) {
	sf::View* s = static_cast<sf::View*>(self);
	s->zoom(factor);
}
