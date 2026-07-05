#include <SFML/System/Time.hpp>

#include <SFML/System/Sleep.hpp>

#include "../../headers/system/sf_sleep.h"


void sf_sleep(sf_Time duration) {
	sf::Time* t = static_cast<sf::Time*>(duration);
	sf::sleep(*t);
}
