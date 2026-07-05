#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_MOVED_RAW_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_MOUSE_MOVED_RAW_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_MouseMovedRaw_del(sf_Event_MouseMovedRaw* obj);

/**
 * Delta x movement of the mouse since the last event.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseMovedRaw_delta_x(sf_Event_MouseMovedRaw* self);

/**
 * Delta y movement of the mouse since the last event.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_MouseMovedRaw_delta_y(sf_Event_MouseMovedRaw* self);


#ifdef __cplusplus
}
#endif


#endif
