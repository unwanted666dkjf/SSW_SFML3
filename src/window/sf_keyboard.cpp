#include <SFML/System/String.hpp>

#include <SFML/Window/Keyboard.hpp>

#include "../../headers/window/sf_keyboard.h"


int sf_Keyboard_is_key_pressed(int key) {
	return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key));
}

int sf_Keyboard_is_scancode_pressed(int scancode) {
	return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Scancode>(scancode));
}

int sf_Keyboard_localize(int scancode) {
	return static_cast<int>(
		sf::Keyboard::localize(static_cast<sf::Keyboard::Scancode>(scancode))
	);
}

int sf_Keyboard_delocalize(int key) {
	return static_cast<int>(
		sf::Keyboard::delocalize(static_cast<sf::Keyboard::Key>(key))
	);
}

sf_String sf_Keyboard_get_description(int scancode) {
	sf::String des = sf::Keyboard::getDescription(static_cast<sf::Keyboard::Scancode>(scancode));
	sf::String* res = new sf::String(des);
	return static_cast<sf_String>(res);
}

void sf_Keyboard_set_virtual_keyboard_visible(int visible) {
	sf::Keyboard::setVirtualKeyboardVisible(visible);
}
