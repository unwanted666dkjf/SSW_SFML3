#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_BUTTON_PRESSED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_BUTTON_PRESSED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_MouseButtonPressed_del(sf_Event_MouseButtonPressed* obj);

/**
 * Code of the button that has been pressed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonPressed_button(sf_Event_MouseButtonPressed* self);

/**
 * Position x of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonPressed_x(sf_Event_MouseButtonPressed* self);

/**
 * Position y of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseButtonPressed_y(sf_Event_MouseButtonPressed* self);


#ifdef __cplusplus
}
#endif


#endif
