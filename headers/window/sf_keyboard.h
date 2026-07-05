#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_KEYBOARD_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_KEYBOARD_H


#include "../system/types.h"

#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SFML_SIMPLE_WRAPPER_sf_Keyboard_KeyCount (78)

#define SFML_SIMPLE_WRAPPER_sf_Keyboard_ScancodeCount (327)


/**
 * Returns 1 if a key is pressed, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Keyboard_is_key_pressed(int key);

/**
 * Returns 1 if a key with that scancode is pressed, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Keyboard_is_scancode_pressed(int scancode);

/**
 * Localize a physical key to a logical one.
 * Returns the key corresponding to the scancode under the current keyboard
 *layout used by the operating system, or `sf::Keyboard::Key::Unknown`
 *when the scancode cannot be mapped to a Key.
 */
SFML_SIMPLE_WRAPPER_API int sf_Keyboard_localize(int scancode);

/**
 * Identify the physical key corresponding to a logical one.
 * Returns the scancode corresponding to the key under the current keyboard
 *layout used by the op*erating system, or `sf::Keyboard::Scan::Unknown` when
 *the key cannot be mapped to a `sf::Keyboard::Scancode`.
 */
SFML_SIMPLE_WRAPPER_API int sf_Keyboard_delocalize(int key);

/**
 * Provide a string representation for a given scancode.
 * The returned string is a short, non-technical description of the
 *key represented with the given scancode. Most effectively used in
 *user interfaces, as the description for the key takes the users
 *keyboard layout into consideration.
 * Warning: the result is OS-dependent.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_Keyboard_get_description(int scancode);

/**
 * Show or hide the virtual keyboard.
 * The virtual keyboard is not supported on all systems.
 *It will typically be implemented on mobile OSes(Android, iOS)
 *but not on desktop OSes (Windows, Linux, ...).
 */
SFML_SIMPLE_WRAPPER_API void sf_Keyboard_set_virtual_keyboard_visible(int visible);


#ifdef __cplusplus
}
#endif


#endif
