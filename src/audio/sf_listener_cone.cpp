#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Angle.hpp>

#include <SFML/Audio/Listener.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/audio/sf_listener_cone.h"


sf_Listener_Cone sf_Listener_Cone_from_real(const sf::Listener::Cone& real) {
	sf::Listener::Cone* self = new sf::Listener::Cone();
	if (!self) {
		std::cerr << "Could not create sf_Listener_Cone in sf_Listener_Cone_from_real!\n";
		std::exit(EXIT_FAILURE);
	}
	self->innerAngle = sf::degrees(real.innerAngle.asDegrees());
	self->outerAngle = sf::degrees(real.outerAngle.asDegrees());
	self->outerGain  = real.outerGain;
	return static_cast<sf_Listener_Cone>(self);
}

sf_Listener_Cone sf_Listener_Cone_init(
	sf_Angle inner_angle,
	sf_Angle outer_angle,
	float outer_gain
) {
	sf::Angle* inner = static_cast<sf::Angle*>(inner_angle);
	sf::Angle* outer = static_cast<sf::Angle*>(outer_angle);
	sf::Listener::Cone* self = new sf::Listener::Cone();
	if (!self) {
		std::cerr << "Could not create sf_Listener_Cone in sf_Listener_Cone_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->innerAngle = sf::degrees(inner->asDegrees());
	self->outerAngle = sf::degrees(outer->asDegrees());
	self->outerGain  = outer_gain;
	return static_cast<sf_Listener_Cone>(self);
}

void* sf_Listener_Cone_del(sf_Listener_Cone obj) {
	sf::Listener::Cone* self = static_cast<sf::Listener::Cone*>(obj);
	delete self;
	return NULL;
}

sf_Angle sf_Listener_Cone_get_inner_angle(sf_Listener_Cone self) {
	sf::Listener::Cone* s = static_cast<sf::Listener::Cone*>(self);
	return sf_Angle_from_degrees(s->innerAngle.asDegrees());
}

sf_Angle sf_Listener_Cone_get_outer_angle(sf_Listener_Cone self) {
	sf::Listener::Cone* s = static_cast<sf::Listener::Cone*>(self);
	return sf_Angle_from_degrees(s->outerAngle.asDegrees());
}

float sf_Listener_Cone_get_outer_gain(sf_Listener_Cone self) {
	sf::Listener::Cone* s = static_cast<sf::Listener::Cone*>(self);
	return s->outerGain;
}
