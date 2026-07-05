#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Glyph.hpp>

#include "../../headers/graphics/sf_int_rect.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/sf_glyph.h"


sf_Glyph sf_Glyph_from_real(const sf::Glyph& real) {
	sf::Glyph* self = new sf::Glyph();
	if (!self) {
		std::cerr << "Could not create sf_Glyph in sf_Glyph_from_real!\n";
		std::exit(EXIT_FAILURE);
	}
	self->advance     = real.advance;
	self->lsbDelta    = real.lsbDelta;
	self->rsbDelta    = real.rsbDelta;
	self->bounds      = sf::FloatRect(real.bounds.position, real.bounds.size);
	self->textureRect = sf::IntRect(real.textureRect.position, real.textureRect.size);
	return static_cast<sf_Glyph>(self);
}

sf_Glyph sf_Glyph_copy(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return sf_Glyph_from_real(*s);
}

void* sf_Glyph_del(sf_Glyph obj) {
	sf::Glyph* self = static_cast<sf::Glyph*>(obj);
	delete self;
	return NULL;
}

float sf_Glyph_get_advance(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return s->advance;
}

int sf_Glyph_get_lsb_delta(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return s->lsbDelta;
}

int sf_Glyph_get_rsb_delta(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return s->rsbDelta;
}

sf_FloatRect sf_Glyph_get_bounds(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return sf_FloatRect_init(
		s->bounds.position.x, s->bounds.position.y,
		s->bounds.size.x, s->bounds.size.y
	);
}

sf_IntRect sf_Glyph_get_texture_rect(sf_Glyph self) {
	sf::Glyph* s = static_cast<sf::Glyph*>(self);
	return sf_IntRect_init(
		s->textureRect.position.x, s->textureRect.position.y,
		s->textureRect.size.x, s->textureRect.size.y
	);
}
