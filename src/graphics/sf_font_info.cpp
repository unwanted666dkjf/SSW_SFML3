#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Font.hpp>

#include "../../headers/graphics/sf_font_info.h"


struct sf_Font_Info {
	int has_kerning;
	int has_vertical_metrics;
	unsigned long long id;
	char* family;
};


sf_Font_Info* sf_Font_Info_from_real(const sf::Font::Info& real) {
	sf_Font_Info* self = static_cast<sf_Font_Info*>(
		std::malloc(sizeof(sf_Font_Info))
	);
	if (!self) {
		std::cerr << "Could not create sf_Font_Info in sf_Font_Info_from_real!\n";
		std::exit(EXIT_FAILURE);
	}
	self->family = static_cast<char*>(
		std::malloc(sizeof(char) * (real.family.size() + 1))
	);
	if (!self->family) {
		std::cerr << "Could not create char array \'family\' for sf_Font_Info in sf_Font_Info_from_real!\n";
		std::exit(EXIT_FAILURE);
	}
	unsigned long i = 0;
	for (; i < real.family.size(); i++) {
		self->family[i] = real.family[i];
	}
	self->family[i] = '\0';
	self->has_kerning          = real.hasKerning;
	self->has_vertical_metrics = real.hasVerticalMetrics;
	return self;
}

void* sf_Font_Info_del(sf_Font_Info* obj) {
	std::free(obj->family);
	std::free(obj);
	return NULL;
}

unsigned long long sf_Font_Info_get_id(sf_Font_Info* self) {
	return self->id;
}

const char* sf_Font_Info_get_family(sf_Font_Info* self) {
	return self->family;
}

int sf_Font_Info_get_has_kerning(sf_Font_Info* self) {
	return self->has_kerning;
}

int sf_Font_Info_get_has_vertical_metrics(sf_Font_Info* self) {
	return self->has_vertical_metrics;
}
