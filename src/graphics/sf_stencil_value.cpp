#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/StencilMode.hpp>

#include "../../headers/graphics/sf_stencil_value.h"


sf_StencilValue sf_StencilValue_from_signed(int value) {
	sf::StencilValue* self = new sf::StencilValue(value);
	if (!self) {
		std::cerr << "Could not create sf_StencilValue in sf_StencilValue_from_signed!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_StencilValue>(self);
}

sf_StencilValue sf_StencilValue_from_unsigned(unsigned int value) {
	sf::StencilValue* self = new sf::StencilValue(value);
	if (!self) {
		std::cerr << "Could not create sf_StencilValue in sf_StencilValue_from_unsigned!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_StencilValue>(self);
}

void* sf_StencilValue_del(sf_StencilValue obj) {
	sf::StencilValue* self = static_cast<sf::StencilValue*>(obj);
	delete self;
	return NULL;
}

unsigned int sf_StencilValue_get_value(sf_StencilValue self) {
	sf::StencilValue* s = static_cast<sf::StencilValue*>(self);
	return s->value;
}
