#include <SFML/System/String.hpp>

#include <SFML/Window/Clipboard.hpp>

#include "../../headers/window/sf_clipboard.h"


sf_String sf_Clipboard_get_string() {
	sf::String s = sf::Clipboard::getString();
	sf::String* res = new sf::String(s);
	return static_cast<sf_String>(res);
}

void sf_Clipboard_set_string(const sf_String text) {
	const sf::String* s = static_cast<const sf::String*>(text);
	sf::Clipboard::setString(*s);
}
