#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_RESIZED_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_RESIZED_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_Resized_del(sf_Event_Resized* obj);

/**
 * Returns new width.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Event_Resized_get_width(sf_Event_Resized* self);

/**
 * Returns new height.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Event_Resized_get_height(sf_Event_Resized* self);


#ifdef __cplusplus
}
#endif


#endif
