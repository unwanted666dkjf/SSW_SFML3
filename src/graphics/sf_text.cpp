#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics/Text.hpp>

#include "../../headers/system/sf_string.h"

#include "../../headers/system/sf_angle.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_color.h"

#include "../../headers/graphics/sf_text.h"


sf_Text sf_Text_init(
	const sf_Font fnt,
	sf_String str_,
	unsigned int character_size
) {
	sf::String* s = static_cast<sf::String*>(str_);
	const sf::Font* f = static_cast<const sf::Font*>(fnt);
	sf::Text* self = new sf::Text(*f, *s, character_size);
	if (!self) {
		std::cerr << "Could not create sf_Text in sf_Text_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Text>(self);
}

void* sf_Text_del(sf_Text obj) {
	sf::Text* self = static_cast<sf::Text*>(obj);
	delete self;
	return NULL;
}

void sf_Text_set_string(sf_Text self, const sf_String str_) {
	sf::Text* s = static_cast<sf::Text*>(self);
	const sf::String* str = static_cast<const sf::String*>(str_);
	s->setString(*str);
}

void sf_Text_set_font(sf_Text self, const sf_Font fnt) {
	sf::Text* s = static_cast<sf::Text*>(self);
	const sf::Font* f = static_cast<const sf::Font*>(fnt);
	s->setFont(*f);
}

void sf_Text_set_character_size(sf_Text self, unsigned int character_size) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setCharacterSize(character_size);
}

void sf_Text_set_line_spacing(sf_Text self, float spacing_factor) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setLineSpacing(spacing_factor);
}

void sf_Text_set_letter_spacing(sf_Text self, float spacing_factor) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setLetterSpacing(spacing_factor);
}

void sf_Text_set_style(sf_Text self, unsigned int text_style) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setStyle(text_style);
}

void sf_Text_set_fill_color(sf_Text self, sf_Color color) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setFillColor(*clr);
}

void sf_Text_set_outline_color(sf_Text self, sf_Color color) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->setOutlineColor(*clr);
}

void sf_Text_set_outline_thickness(sf_Text self, float thickness) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setOutlineThickness(thickness);
}

void sf_Text_set_line_alignment(sf_Text self, int line_alignment) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setLineAlignment(static_cast<sf::Text::LineAlignment>(line_alignment));
}

void sf_Text_set_text_orientation(sf_Text self, int text_orientation) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setTextOrientation(static_cast<sf::Text::TextOrientation>(text_orientation));
}

sf_String sf_Text_get_string(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return sf_String_from_str(s->getString().toAnsiString().c_str());
}

unsigned int sf_Text_get_character_size(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return s->getCharacterSize();
}

float sf_Text_get_letter_spacing(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return s->getLetterSpacing();
}

float sf_Text_get_line_spacing(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return s->getLineSpacing();
}

unsigned int sf_Text_get_style(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return s->getStyle();
}

sf_Color sf_Text_get_fill_color(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Color clr = s->getFillColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

sf_Color sf_Text_get_outline_color(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Color clr = s->getOutlineColor();
	return sf_Color_from_rgba(clr.r, clr.g, clr.b, clr.a);
}

float sf_Text_get_outline_thickness(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return s->getOutlineThickness();
}

int sf_Text_get_line_alignment(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return static_cast<int>(
		s->getLineAlignment()
	);
}

int sf_Text_get_text_orientation(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return static_cast<int>(
		s->getTextOrientation()
	);
}

int sf_Text_get_cluster_grouping(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	return static_cast<int>(
		s->getClusterGrouping()
	);
}

void sf_Text_set_cluster_grouping(sf_Text self, int cluster_grouping) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setClusterGrouping(
		static_cast<sf::Text::ClusterGrouping>(cluster_grouping)
	);
}

sf_FloatRect sf_Text_get_local_bounds(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::FloatRect r = s->getLocalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_FloatRect sf_Text_get_global_bounds(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::FloatRect r = s->getGlobalBounds();
	return sf_FloatRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

void sf_Text_draw(sf_Text self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	const sf::RenderStates* st = static_cast<const sf::RenderStates*>(states);
	w->draw(*s, *st);
}

void sf_Text_set_position(sf_Text self, float left, float top) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setPosition(sf::Vector2f(left, top));
}

void sf_Text_set_rotation(sf_Text self, sf_Angle angle) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->setRotation(*rot);
}

void sf_Text_set_scale(sf_Text self, float kx, float ky) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setScale(sf::Vector2f(kx, ky));
}

void sf_Text_set_origin(sf_Text self, float ox, float oy) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->setOrigin(sf::Vector2f(ox, oy));
}

sf_Vector2f sf_Text_get_position(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Vector2f p = s->getPosition();
	return sf_Vector2f_init(p.x, p.y);
}

sf_Angle sf_Text_get_rotation(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Angle rot = s->getRotation();
	return sf_Angle_from_degrees(rot.asDegrees());
}

sf_Vector2f sf_Text_get_scale(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Vector2f sca = s->getScale();
	return sf_Vector2f_init(sca.x, sca.y);
}

sf_Vector2f sf_Text_get_origin(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Vector2f orig = s->getOrigin();
	return sf_Vector2f_init(orig.x, orig.y);
}

void sf_Text_move(sf_Text self, float dx, float dy) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->move(sf::Vector2f(dx, dy));
}

void sf_Text_rotate(sf_Text self, sf_Angle angle) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Angle* rot = static_cast<sf::Angle*>(angle);
	s->rotate(*rot);
}

void sf_Text_scale(sf_Text self, float kx, float ky) {
	sf::Text* s = static_cast<sf::Text*>(self);
	s->scale(sf::Vector2f(kx, ky));
}

sf_Transform sf_Text_get_transform(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Transform* res = new sf::Transform(s->getTransform());
	return static_cast<sf_Transform>(res);
}

sf_Transform sf_Text_get_inverse_transform(sf_Text self) {
	sf::Text* s = static_cast<sf::Text*>(self);
	sf::Transform* res = new sf::Transform(s->getInverseTransform());
	return static_cast<sf_Transform>(res);
}
