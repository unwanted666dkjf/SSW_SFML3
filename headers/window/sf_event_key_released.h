#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_KEY_RELEASED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_KEY_RELEASED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_KeyReleased_del(sf_Event_KeyReleased* obj);

/**
 * Code of the key that has been released.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_keycode(sf_Event_KeyReleased* self);

/**
 * Physical code of the key that has been released.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_scancode(sf_Event_KeyReleased* self);

/**
 * Is the Alt key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_alt(sf_Event_KeyReleased* self);

/**
 * Is the Control key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_control(sf_Event_KeyReleased* self);

/**
 * Is the Shift key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_shift(sf_Event_KeyReleased* self);

/**
 * Is the System key pressed?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_system(sf_Event_KeyReleased* self);

/**
 * Is the CapsLock key toggled?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_caps_lock(sf_Event_KeyReleased* self);

/**
 * Is the NumLock key toggled?
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_num_lock(sf_Event_KeyReleased* self);

/**
 * Is the ScrollLock key toggled? (Not supported on macOS)
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_KeyReleased_is_scroll_lock(sf_Event_KeyReleased* self);


#ifdef __cplusplus
}
#endif


#endif
