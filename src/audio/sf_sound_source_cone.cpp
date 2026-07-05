#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Angle.hpp>

#include <SFML/Audio/SoundSource.hpp>

#include "../../headers/system/sf_angle.h"

#include "../../headers/audio/sf_sound_source_cone.h"


sf_SoundSource_Cone sf_SoundSource_Cone_from_real(const sf::SoundSource::Cone& real) {
	sf::SoundSource::Cone* self = new sf::SoundSource::Cone();
	if (!self) {
		std::cerr << "Could not create sf_SoundSource_Cone in sf_SoundSource_Cone_from_real!\n";
		std::exit(EXIT_FAILURE);
	}
	self->innerAngle = sf::degrees(real.innerAngle.asDegrees());
	self->outerAngle = sf::degrees(real.outerAngle.asDegrees());
	self->outerGain  = real.outerGain;
	return static_cast<sf_SoundSource_Cone>(self);
}

sf_SoundSource_Cone sf_SoundSource_Cone_init(
	sf_Angle inner_angle,
	sf_Angle outer_angle,
	float outer_gain
) {
	sf::Angle* inner = static_cast<sf::Angle*>(inner_angle);
	sf::Angle* outer = static_cast<sf::Angle*>(outer_angle);
	sf::SoundSource::Cone* self = new sf::SoundSource::Cone();
	if (!self) {
		std::cerr << "Could not create sf_SoundSource_Cone in sf_SoundSource_Cone_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->innerAngle = sf::degrees(inner->asDegrees());
	self->outerAngle = sf::degrees(outer->asDegrees());
	self->outerGain  = outer_gain;
	return static_cast<sf_SoundSource_Cone>(self);
}

void* sf_SoundSource_Cone_del(sf_SoundSource_Cone obj) {
	sf::SoundSource::Cone* self = static_cast<sf::SoundSource::Cone*>(obj);
	delete self;
	return NULL;
}

sf_Angle sf_SoundSource_Cone_get_inner_angle(sf_SoundSource_Cone self) {
	sf::SoundSource::Cone* s = static_cast<sf::SoundSource::Cone*>(self);
	return sf_Angle_from_degrees(s->innerAngle.asDegrees());
}

sf_Angle sf_SoundSource_Cone_get_outer_angle(sf_SoundSource_Cone self) {
	sf::SoundSource::Cone* s = static_cast<sf::SoundSource::Cone*>(self);
	return sf_Angle_from_degrees(s->outerAngle.asDegrees());
}

float sf_SoundSource_Cone_get_outer_gain(sf_SoundSource_Cone self) {
	sf::SoundSource::Cone* s = static_cast<sf::SoundSource::Cone*>(self);
	return s->outerGain;
}
