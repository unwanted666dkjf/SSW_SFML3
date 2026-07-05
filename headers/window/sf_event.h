#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates an empty event of an unknown type with nullified sub-events.
 */
SFML_SIMPLE_WRAPPER_API sf_Event* sf_Event_init();

/**
 * Deletes object and returns NULL.
 * Does not delete or clear sub-events.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_del(sf_Event* obj);

/**
 * Deletes, cleans up, and nullifies sub-events.
 */
SFML_SIMPLE_WRAPPER_API void sf_Event_cleanup(sf_Event* self);

/**
 * Returns an event type constant.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_get_type(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_KeyPressed* sf_Event_get_key_pressed_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_KeyReleased* sf_Event_get_key_released_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_MouseButtonPressed* sf_Event_get_mouse_button_pressed_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_MouseButtonReleased* sf_Event_get_mouse_button_released_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_MouseMoved* sf_Event_get_mouse_moved_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_MouseMovedRaw* sf_Event_get_mouse_moved_raw_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_MouseWheelScrolled* sf_Event_get_mouse_wheel_scrolled_evt(sf_Event* self);

/**
 * Returns a sub-event. If the event is not initialized, the application terminates.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_Resized* sf_Event_get_resized_evt(sf_Event* self);


#ifdef __cplusplus
}
#endif


#endif
