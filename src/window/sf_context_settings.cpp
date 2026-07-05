#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Window/ContextSettings.hpp>

#include "../../headers/window/sf_context_settings.h"


sf_ContextSettings sf_ContextSettings_get_default() {
	return sf_ContextSettings_init(
		0, 0, 0, 0, 1, 1, 
		static_cast<unsigned int>(sf::ContextSettings::Attribute::Debug)
	);
}

sf_ContextSettings sf_ContextSettings_init(
	int sRgbCapable,
	unsigned int depthBits,
	unsigned int stencilBits,
	unsigned int antiAliasingLevel,
	unsigned int majorVersion,
	unsigned int minorVersion,
	unsigned int attributeFlags
) {
	sf::ContextSettings* self = new sf::ContextSettings();
	if (!self) {
		std::cerr << "Could not create sf_ContextSettings in sf_ContextSettings_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->sRgbCapable       = sRgbCapable;
	self->depthBits         = depthBits;
	self->stencilBits       = stencilBits;
	self->antiAliasingLevel = antiAliasingLevel;
	self->majorVersion      = majorVersion;
	self->minorVersion      = minorVersion;
	self->attributeFlags    = attributeFlags;
	return static_cast<sf_ContextSettings>(self);
}

void* sf_ContextSettings_del(sf_ContextSettings obj) {
	sf::ContextSettings* self = static_cast<sf::ContextSettings*>(obj);
	delete self;
	return NULL;
}

int sf_ContextSettings_get_sRgbCapable(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->sRgbCapable;
}

unsigned int sf_ContextSettings_get_depth_bits(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->depthBits;
}

unsigned int sf_ContextSettings_get_stencil_bits(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->stencilBits;
}

unsigned int sf_ContextSettings_get_anti_aliasing_level(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->antiAliasingLevel;
}

unsigned int sf_ContextSettings_get_major_version(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->majorVersion;
}

unsigned int sf_ContextSettings_get_minor_version(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->minorVersion;
}

unsigned int sf_ContextSettings_get_attribute_flags(sf_ContextSettings self) {
	sf::ContextSettings* s = static_cast<sf::ContextSettings*>(self);
	return s->attributeFlags;
}
