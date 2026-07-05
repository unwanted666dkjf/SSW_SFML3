#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/Shader.hpp>

#include "../../headers/graphics/sf_shader.h"


namespace fs = std::filesystem;


sf_Shader sf_Shader_default() {
	sf::Shader* self = new sf::Shader();
	if (!self) {
		std::cerr << "Could not create sf_Shader in sf_Shader_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Shader>(self);
}

sf_Shader sf_Shader_init(const std_Path filepath, int shader_type) {
	const fs::path* path = static_cast<const fs::path*>(filepath);
	sf::Shader* self = new sf::Shader(*path, static_cast<sf::Shader::Type>(shader_type));
	if (!self) {
		std::cerr << "Could not create sf_Shader in sf_Shader_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Shader>(self);
}

sf_Shader sf_Shader_init_ex(
	const std_Path vertexShaderFilename,
	const std_Path fragmentShaderFilename
) {
	const fs::path* vertex_path = static_cast<const fs::path*>(vertexShaderFilename);
	const fs::path* fragment_path = static_cast<const fs::path*>(fragmentShaderFilename);
	sf::Shader* self = new sf::Shader(*vertex_path, *fragment_path);
	if (!self) {
		std::cerr << "Could not create sf_Shader in sf_Shader_init_ex!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Shader>(self);
}

sf_Shader sf_Shader_init_ex_ex(
	const std_Path vertexShaderFilename,
	const std_Path geometryShaderFilename,
	const std_Path fragmentShaderFilename
) {
	const fs::path* vertex_path = static_cast<const fs::path*>(vertexShaderFilename);
	const fs::path* geometry_path = static_cast<const fs::path*>(geometryShaderFilename);
	const fs::path* fragment_path = static_cast<const fs::path*>(fragmentShaderFilename);
	sf::Shader* self = new sf::Shader(*vertex_path, *geometry_path, *fragment_path);
	if (!self) {
		std::cerr << "Could not create sf_Shader in sf_Shader_init_ex_ex!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_Shader>(self);
}

void* sf_Shader_del(sf_Shader obj) {
	sf::Shader* self = static_cast<sf::Shader*>(obj);
	delete self;
	return NULL;
}

int sf_Shader_load(sf_Shader self, const std_Path filepath, int shader_type) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	const fs::path* path = static_cast<const fs::path*>(filepath);
	return s->loadFromFile(*path, static_cast<sf::Shader::Type>(shader_type));
}

int sf_Shader_load_ex(sf_Shader self,
	const std_Path vertexShaderFilename,
	const std_Path fragmentShaderFilename
) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	const fs::path* vertex_path = static_cast<const fs::path*>(vertexShaderFilename);
	const fs::path* fragment_path = static_cast<const fs::path*>(fragmentShaderFilename);
	return s->loadFromFile(*vertex_path, *fragment_path);
}

int sf_Shader_load_ex_ex(sf_Shader self,
	const std_Path vertexShaderFilename,
	const std_Path geometryShaderFilename,
	const std_Path fragmentShaderFilename
) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	const fs::path* vertex_path = static_cast<const fs::path*>(vertexShaderFilename);
	const fs::path* geometry_path = static_cast<const fs::path*>(geometryShaderFilename);
	const fs::path* fragment_path = static_cast<const fs::path*>(fragmentShaderFilename);
	return s->loadFromFile(*vertex_path, *geometry_path, *fragment_path);
}

void sf_Shader_set_uniform(sf_Shader self, const char* name, float x) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	s->setUniform(std::string(name), x);
}

void sf_Shader_set_uniform_vec2(sf_Shader self, const char* name, sf_Vector2f vec) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	sf::Vector2f* v = static_cast<sf::Vector2f*>(vec);
	s->setUniform(std::string(name), *v);
}

void sf_Shader_set_uniform_vec3(sf_Shader self, const char* name, sf_Vector3f vec) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	sf::Vector3f* v = static_cast<sf::Vector3f*>(vec);
	s->setUniform(std::string(name), *v);
}

void sf_Shader_set_uniform_i(sf_Shader self, const char* name, int x) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	s->setUniform(std::string(name), x);
}

void sf_Shader_set_uniform_vec2i(sf_Shader self, const char* name, sf_Vector2i vec) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	sf::Vector2i* v = static_cast<sf::Vector2i*>(vec);
	s->setUniform(std::string(name), *v);
}

unsigned int sf_Shader_get_native_handle(sf_Shader self) {
	sf::Shader* s = static_cast<sf::Shader*>(self);
	return s->getNativeHandle();
}

void sf_Shader_bind(const sf_Shader shader) {
	const sf::Shader* s = static_cast<const sf::Shader*>(shader);
	sf::Shader::bind(s);
}

int sf_Shader_is_available() {
	return sf::Shader::isAvailable();
}

int sf_Shader_is_geometry_available() {
	return sf::Shader::isGeometryAvailable();
}
