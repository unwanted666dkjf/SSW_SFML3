#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_KEY_PRESSED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_KEY_PRESSED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_KeyPressed_del(sf_Event_KeyPressed* obj);

/**
 * Code of the key that has been pressed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_keycode(sf_Event_KeyPressed* self);

/**
 * Physical code of the key that has been pressed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_scancode(sf_Event_KeyPressed* self);

/**
 * Is the Alt key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_alt(sf_Event_KeyPressed* self);

/**
 * Is the Control key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_control(sf_Event_KeyPressed* self);

/**
 * Is the Shift key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_shift(sf_Event_KeyPressed* self);

/**
 * Is the System key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_system(sf_Event_KeyPressed* self);

/**
 * Is the CapsLock key toggled?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_caps_lock(sf_Event_KeyPressed* self);

/**
 * Is the NumLock key toggled?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_num_lock(sf_Event_KeyPressed* self);

/**
 * Is the ScrollLock key toggled? (Not supported on macOS)
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyPressed_is_scroll_lock(sf_Event_KeyPressed* self);


#ifdef __cplusplus
}
#endif


#endif
