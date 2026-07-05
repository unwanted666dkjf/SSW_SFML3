#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_MOVED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_MOVED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_MouseMoved_del(sf_Event_MouseMoved* obj);

/**
 * Position x of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseMoved_x(sf_Event_MouseMoved* self);

/**
 * Position y of the mouse pointer, relative to the top left of the owner window.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseMoved_y(sf_Event_MouseMoved* self);


#ifdef __cplusplus
}
#endif


#endif
