#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_MOUSE_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_MOUSE_H


#include "../system/types.h"

#include "../graphics/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Check if a mouse button is pressed.
 * Checking the state of buttons `Mouse::Button::Extra1` and
 *`Mouse::Button::Extra2` is not supported on Linux with X11.
 * Returns 1 if the button is pressed, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Mouse_is_button_pressed(int button);

/**
 * Returns current position of the mouse.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Mouse_get_position();

/**
 * This function returns the current position of the mouse
 *cursor, relative to the given window.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_Mouse_get_position_relative(const sf_RenderWindow relative_to);

/**
 * This function sets the global position of the mouse
 *cursor on the desktop.
 */
SFML_SIMPLE_WRAPPER_API void sf_Mouse_set_position(int x, int y);

/**
 * This function sets the current position of the mouse
 *cursor, relative to the given window.
 */
SFML_SIMPLE_WRAPPER_API void sf_Mouse_set_position_relative(int x, int y, const sf_RenderWindow relative_to);


#ifdef __cplusplus
}
#endif


#endif
