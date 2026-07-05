#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Texture.hpp>

#include "../../headers/system/sf_vector2u.h"

#include "../../headers/graphics/sf_texture.h"


namespace fs = std::filesystem;


sf_Texture sf_Texture_default() {
	sf::Texture* self = new sf::Texture();
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

sf_Texture sf_Texture_copy(const sf_Texture src) {
	const sf::Texture* source = static_cast<const sf::Texture*>(src);
	sf::Texture* self = new sf::Texture(*source);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_copy!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

sf_Texture sf_Texture_from_area(
	const std_Path filename,
	int allow_sRgb,
	const sf_IntRect area
) {
	const fs::path* fname = static_cast<const fs::path*>(filename);
	const sf::IntRect* rect = static_cast<const sf::IntRect*>(area);
	sf::Texture* self = new sf::Texture(*fname, allow_sRgb, *rect);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_from_area!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

sf_Texture sf_Texture_from_image(const sf_Image image, int allow_sRgb) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	sf::Texture* self = new sf::Texture(*img, allow_sRgb);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_from_image!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

sf_Texture sf_Texture_from_image_ex(
	const sf_Image image,
	int allow_sRgb,
	const sf_IntRect area
) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	const sf::IntRect* rect = static_cast<const sf::IntRect*>(area);
	sf::Texture* self = new sf::Texture(*img, allow_sRgb, *rect);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_from_image_ex!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

sf_Texture sf_Texture_init(const std_Path filename, int allow_sRgb) {
	const fs::path* fname = static_cast<const fs::path*>(filename);
	sf::Texture* self = new sf::Texture(*fname, allow_sRgb);
	if (!self) {
		std::cerr << "Could not create sf_Texture in sf_Texture_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Texture>(self);
}

void* sf_Texture_del(sf_Texture obj) {
	sf::Texture* self = static_cast<sf::Texture*>(obj);
	delete self;
	return NULL;
}

int sf_Texture_resize(sf_Texture self,
	unsigned int width,
	unsigned int height,
	int allow_sRgb
) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->resize(sf::Vector2u(width, height), allow_sRgb);
}

int sf_Texture_load_from_file(sf_Texture self, const std_Path filename, int allow_sRgb) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	const fs::path* fname = static_cast<const fs::path*>(filename);
	return s->loadFromFile(*fname, allow_sRgb, sf::IntRect());
}

int sf_Texture_load_from_file_ex(sf_Texture self,
	const std_Path filename,
	int allow_sRgb,
	const sf_IntRect area
) {
	const fs::path* fname = static_cast<const fs::path*>(filename);
	const sf::IntRect* rect = static_cast<const sf::IntRect*>(area);
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->loadFromFile(*fname, allow_sRgb, *rect);
}

int sf_Texture_load_from_image(sf_Texture self, const sf_Image image, int allow_sRgb) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	const sf::Image* img = static_cast<const sf::Image*>(image);
	return s->loadFromImage(*img, allow_sRgb, sf::IntRect());
}

int sf_Texture_load_from_image_ex(sf_Texture self,
	const sf_Image image,
	int allow_sRgb,
	const sf_IntRect area
) {
	const sf::Image* img = static_cast<const sf::Image*>(image);
	const sf::IntRect* rect = static_cast<const sf::IntRect*>(area);
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->loadFromImage(*img, allow_sRgb, *rect);
}

sf_Vector2u sf_Texture_get_size(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	sf::Vector2u size = s->getSize();
	return sf_Vector2u_init(size.x, size.y);
}

void sf_Texture_update(sf_Texture self, const sf_Image image) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	const sf::Image* img = static_cast<const sf::Image*>(image);
	s->update(*img);
}

void sf_Texture_update_ex(sf_Texture self,
	const sf_Image image,
	sf_Vector2u dest
) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	const sf::Image* img = static_cast<const sf::Image*>(image);
	sf::Vector2u* dst = static_cast<sf::Vector2u*>(dest);
	s->update(*img, *dst);
}

int sf_Texture_get_is_smooth(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->isSmooth();
}

void sf_Texture_set_is_smooth(sf_Texture self, int enable_smooth) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	s->setSmooth(enable_smooth);
}

int sf_Texture_is_Srgb(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->isSrgb();
}

int sf_Texture_get_is_repeated(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->isRepeated();
}

void sf_Texture_set_is_repeated(sf_Texture self, int enable_repeating) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	s->setRepeated(enable_repeating);
}

int sf_Texture_generate_mipmap(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->generateMipmap();
}

unsigned int sf_Texture_get_native_handle(sf_Texture self) {
	sf::Texture* s = static_cast<sf::Texture*>(self);
	return s->getNativeHandle();
}

void sf_Texture_bind(const sf_Texture texture, int coordinate_type) {
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	sf::Texture::bind(t, static_cast<sf::CoordinateType>(coordinate_type));
}

unsigned int sf_Texture_get_maximum_size() {
	return sf::Texture::getMaximumSize();
}
