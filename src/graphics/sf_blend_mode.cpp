#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/BlendMode.hpp>

#include "../../headers/graphics/sf_blend_mode.h"


sf_BlendMode sf_BlendMode_default() {
	sf::BlendMode* self = new sf::BlendMode();
	if (!self) {
		std::cerr << "Could not create sf_BlendMode in sf_BlendMode_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_BlendMode>(self);
}

sf_BlendMode sf_BlendMode_init(
	int colorSourceFactor,
	int colorDestinationFactor,
	int colorBlendEquation,
	int alphaSourceFactor,
	int alphaDestinationFactor,
	int alphaBlendEquation
) {
	sf::BlendMode* self = new sf::BlendMode(
		static_cast<sf::BlendMode::Factor>(colorSourceFactor),
		static_cast<sf::BlendMode::Factor>(colorDestinationFactor),
		static_cast<sf::BlendMode::Equation>(colorBlendEquation),
		static_cast<sf::BlendMode::Factor>(alphaSourceFactor),
		static_cast<sf::BlendMode::Factor>(alphaDestinationFactor),
		static_cast<sf::BlendMode::Equation>(alphaBlendEquation)
	);
	if (!self) {
		std::cerr << "Could not create sf_BlendMode in sf_BlendMode_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

void* sf_BlendMode_del(sf_BlendMode obj) {
	sf::BlendMode* self = static_cast<sf::BlendMode*>(obj);
	delete self;
	return NULL;
}

int sf_BlendMode_get_clr_src_factor(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->colorSrcFactor);
}

int sf_BlendMode_get_clr_dst_factor(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->colorDstFactor);
}

int sf_BlendMode_get_clr_blend_equation(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->colorEquation);
}

int sf_BlendMode_get_alpha_src_factor(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->alphaSrcFactor);
}

int sf_BlendMode_get_alpha_dst_factor(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->alphaDstFactor);
}

int sf_BlendMode_get_alpha_equation(sf_BlendMode self) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	return static_cast<int>(s->alphaEquation);
}

int sf_BlendMode_is_equal(sf_BlendMode self, const sf_BlendMode other) {
	sf::BlendMode* s = static_cast<sf::BlendMode*>(self);
	const sf::BlendMode* o = static_cast<const sf::BlendMode*>(other);
	return *s == *o;
}

int sf_BlendMode_is_ne(sf_BlendMode self, const sf_BlendMode other) {
	return !sf_BlendMode_is_equal(self, other);
}
