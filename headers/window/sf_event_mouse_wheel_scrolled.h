#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_WHEEL_SCROLLED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_WHEEL_SCROLLED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_MouseWheelScrolled_del(sf_Event_MouseWheelScrolled* obj);

/**
 * Which wheel (for mice with multiple ones).
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseWheelScrolled_wheel(sf_Event_MouseWheelScrolled* self);

/**
 * Wheel offset (positive is up/left, negative is down/right).
 * High-precision mice may use non-integral offsets.
 */
SFML_SIMPLE_WRAPPER_API float sf_Event_MouseWheelScrolled_delta(sf_Event_MouseWheelScrolled* self);

/**
 * Position x of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseWheelScrolled_x(sf_Event_MouseWheelScrolled* self);

/**
 * Position y of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseWheelScrolled_y(sf_Event_MouseWheelScrolled* self);


#ifdef __cplusplus
}
#endif


#endif
