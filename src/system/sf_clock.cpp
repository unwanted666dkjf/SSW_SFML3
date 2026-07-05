#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/Time.hpp>

#include <SFML/System/Clock.hpp>

#include "../../headers/system/sf_clock.h"


sf_Clock sf_Clock_init() {
	sf::Clock* self = new sf::Clock();
	if (!self) {
		std::cerr << "Could not create sf_Clock in sf_Clock_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->stop();
	return self;
}

void* sf_Clock_del(sf_Clock obj) {
	sf::Clock* self = static_cast<sf::Clock*>(obj);
	delete self;
	return NULL;
}

sf_Time sf_Clock_get_elapsed_time(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	sf::Time t = s->getElapsedTime();
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

int sf_Clock_is_running(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	return s->isRunning();
}

void sf_Clock_start(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	s->start();
}

void sf_Clock_stop(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	s->stop();
}

sf_Time sf_Clock_restart(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	sf::Time t = s->restart();
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}

sf_Time sf_Clock_reset(sf_Clock self) {
	sf::Clock* s = static_cast<sf::Clock*>(self);
	sf::Time t = s->reset();
	sf::Time* res = new sf::Time(t);
	return static_cast<sf_Time>(res);
}
