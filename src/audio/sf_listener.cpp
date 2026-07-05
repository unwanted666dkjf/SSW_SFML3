#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Audio/Listener.hpp>

#include "../../headers/system/sf_vector3f.h"

#include "../../headers/audio/sf_listener.h"


sf_Listener_Cone sf_Listener_Cone_from_real(const sf::Listener::Cone& real);


void sf_Listener_set_global_volume(float volume) {
	sf::Listener::setGlobalVolume(volume);
}

float sf_Listener_get_global_volume() {
	return sf::Listener::getGlobalVolume();
}

void sf_Listener_set_position(const sf_Vector3f position) {
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(position);
	sf::Listener::setPosition(*v);
}

sf_Vector3f sf_Listener_get_position() {
	sf::Vector3f v = sf::Listener::getPosition();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

void sf_Listener_set_direction(const sf_Vector3f direction) {
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(direction);
	sf::Listener::setDirection(*v);
}

sf_Vector3f sf_Listener_get_direction() {
	sf::Vector3f v = sf::Listener::getDirection();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

void sf_Listener_set_velocity(const sf_Vector3f velocity) {
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(velocity);
	sf::Listener::setVelocity(*v);
}

sf_Vector3f sf_Listener_get_velocity() {
	sf::Vector3f v = sf::Listener::getVelocity();
	return sf_Vector3f_init(v.x, v.y, v.z);
}

void sf_Listener_set_cone(const sf_Listener_Cone cone) {
	const sf::Listener::Cone* c = static_cast<const sf::Listener::Cone*>(cone);
	sf::Listener::setCone(*c);
}

sf_Listener_Cone sf_Listener_get_cone() {
	return sf_Listener_Cone_from_real(sf::Listener::getCone());
}

void sf_Listener_set_up_vector(const sf_Vector3f vec) {
	const sf::Vector3f* v = static_cast<const sf::Vector3f*>(vec);
	sf::Listener::setUpVector(*v);
}

sf_Vector3f sf_Listener_get_up_vector() {
	sf::Vector3f v = sf::Listener::getUpVector();
	return sf_Vector3f_init(v.x, v.y, v.z);
}
