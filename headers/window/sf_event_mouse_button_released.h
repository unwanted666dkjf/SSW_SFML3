#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_BUTTON_RELEASED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_BUTTON_RELEASED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_MouseButtonReleased_del(sf_Event_MouseButtonReleased* obj);

/**
 * Code of the button that has been released.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonReleased_button(sf_Event_MouseButtonReleased* self);

/**
 * Position x of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonReleased_x(sf_Event_MouseButtonReleased* self);

/**
 * Position y of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonReleased_y(sf_Event_MouseButtonReleased* self);


#ifdef __cplusplus
}
#endif


#endif
