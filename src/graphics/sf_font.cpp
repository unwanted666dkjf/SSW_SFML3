#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <filesystem>

#include <SFML/Graphics/Font.hpp>

#include "../../headers/graphics/sf_font.h"


namespace fs = std::filesystem;


sf_Glyph sf_Glyph_from_real(const sf::Glyph& real);

sf_Font_Info* sf_Font_Info_from_real(const sf::Font::Info& real);


sf_Font sf_Font_default() {
	sf::Font* self = new sf::Font();
	if (!self) {
		std::cerr << "Could not create sf_Font in sf_Font_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Font>(self);
}

sf_Font sf_Font_init(const std_Path filepath) {
	const fs::path* p = static_cast<const fs::path*>(filepath);
	sf::Font* self = new sf::Font(*p);
	if (!self) {
		std::cerr << "Could not create sf_Font in sf_Font_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Font>(self);
}

void* sf_Font_del(sf_Font obj) {
	sf::Font* self = static_cast<sf::Font*>(obj);
	delete self;
	return NULL;
}

int sf_Font_open(sf_Font self, const std_Path filepath) {
	sf::Font* s = static_cast<sf::Font*>(self);
	const fs::path* p = static_cast<const fs::path*>(filepath);
	return s->openFromFile(*p);
}

sf_Font_Info* sf_Font_get_info(sf_Font self) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return sf_Font_Info_from_real(s->getInfo());
}

sf_Glyph sf_Font_get_glyph_by_id(sf_Font self,
	unsigned int id,
	unsigned int character_size,
	int retrieve_bold,
	float outline_thickness
) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return sf_Glyph_from_real(
		s->getGlyphById(id, character_size, retrieve_bold, outline_thickness)
	);
}

sf_Glyph sf_Font_get_glyph(sf_Font self,
	unsigned int code_point,
	unsigned int character_size,
	int retrieve_bold,
	float outline_thickness
) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return sf_Glyph_from_real(
		s->getGlyph(code_point, character_size, retrieve_bold, outline_thickness)
	);
}

int sf_Font_has_glyph(sf_Font self, unsigned int code_point) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->hasGlyph(code_point);
}

float sf_Font_get_kerning(sf_Font self,
	unsigned int first,
	unsigned int second,
	unsigned int character_size,
	int retrieve_bold
) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getKerning(
		static_cast<char32_t>(first),
		static_cast<char32_t>(second),
		character_size,
		retrieve_bold
	);
}

float sf_Font_get_ascent(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getAscent(character_size);
}

float sf_Font_get_descent(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getDescent(character_size);
}

float sf_Font_get_line_spacing(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getLineSpacing(character_size);
}

float sf_Font_get_underline_position(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getUnderlinePosition(character_size);
}

float sf_Font_get_underline_thickness(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->getUnderlineThickness(character_size);
}

sf_Texture sf_Font_get_texture(sf_Font self, unsigned int character_size) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return static_cast<sf_Texture>(new sf::Texture(s->getTexture(character_size)));
}

int sf_Font_get_is_smooth(sf_Font self) {
	sf::Font* s = static_cast<sf::Font*>(self);
	return s->isSmooth();
}

void sf_Font_set_is_smooth(sf_Font self, int is_smooth) {
	sf::Font* s = static_cast<sf::Font*>(self);
	s->setSmooth(is_smooth);
}
