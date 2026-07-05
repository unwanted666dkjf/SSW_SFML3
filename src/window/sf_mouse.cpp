#include <SFML/System/Vector2.hpp>

#include <SFML/Window/Mouse.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../headers/system/sf_vector2i.h"

#include "../../headers/window/sf_mouse.h"


int sf_Mouse_is_button_pressed(int button) {
	return sf::Mouse::isButtonPressed(
		static_cast<sf::Mouse::Button>(button)
	);
}

sf_Vector2i sf_Mouse_get_position() {
	sf::Vector2i pos = sf::Mouse::getPosition();
	sf_Vector2i res = sf_Vector2i_init(pos.x, pos.y);
	return res;
}

sf_Vector2i sf_Mouse_get_position_relative(const sf_RenderWindow relative_to) {
	const sf::RenderWindow* wnd = static_cast<const sf::RenderWindow*>(relative_to);
	sf::Vector2i pos = sf::Mouse::getPosition(*wnd);
	sf_Vector2i res = sf_Vector2i_init(pos.x, pos.y);
	return res;
}

void sf_Mouse_set_position(int x, int y) {
	sf::Mouse::setPosition(sf::Vector2i(x, y));
}

void sf_Mouse_set_position_relative(int x, int y, const sf_RenderWindow relative_to) {
	const sf::RenderWindow* wnd = static_cast<const sf::RenderWindow*>(relative_to);
	sf::Mouse::setPosition(sf::Vector2i(x, y), *wnd);
}
