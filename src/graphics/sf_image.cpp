#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <filesystem>

#include <SFML/Graphics/Image.hpp>

#include "../../headers/system/sf_vector2u.h"

#include "../../headers/graphics/sf_image.h"


namespace fs = std::filesystem;


sf_Image sf_Image_default() {
	sf::Image* res = new sf::Image();
	if (!res) {
		std::cerr << "Could not create sf_Image in sf_Image_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Image>(res);
}

sf_Image sf_Image_init(const std_Path path) {
	const fs::path* p = static_cast<const fs::path*>(path);
	sf::Image* res = new sf::Image(*p);
	if (!res) {
		std::cerr << "Could not create sf_Image in sf_Image_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Image>(res);
}

void* sf_Image_del(sf_Image obj) {
	sf::Image* self = static_cast<sf::Image*>(obj);
	delete self;
	return NULL;
}

int sf_Image_load(sf_Image self, const std_Path path) {
	sf::Image* s = static_cast<sf::Image*>(self);
	const fs::path* p = static_cast<const fs::path*>(path);
	return s->loadFromFile(*p);
}

int sf_Image_save(sf_Image self, const std_Path path) {
	sf::Image* s = static_cast<sf::Image*>(self);
	const fs::path* p = static_cast<const fs::path*>(path);
	return s->saveToFile(*p);
}

sf_Vector2u sf_Image_get_size(sf_Image self) {
	sf::Image* s = static_cast<sf::Image*>(self);
	sf::Vector2u size = s->getSize();
	return sf_Vector2u_init(size.x, size.y);
}

const unsigned char* sf_Image_get_pixels_ptr(sf_Image self) {
	sf::Image* s = static_cast<sf::Image*>(self);
	return s->getPixelsPtr();
}

void sf_Image_flip_horizontally(sf_Image self) {
	sf::Image* s = static_cast<sf::Image*>(self);
	s->flipHorizontally();
}

void sf_Image_flip_vertically(sf_Image self) {
	sf::Image* s = static_cast<sf::Image*>(self);
	s->flipVertically();
}

void sf_Image_create_mask_from_color(sf_Image self, sf_Color color, unsigned char alpha) {
	sf::Image* s = static_cast<sf::Image*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->createMaskFromColor(*clr, alpha);
}
