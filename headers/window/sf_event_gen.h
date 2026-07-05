#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_GEN_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_EVENT_GEN_H


#include "./types.h"

#include "../graphics/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Constructs generator.
 * Created generator is basically,
 *C variant of: 'while (const std::optional event = window.pollEvent()'.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_Gen* sf_Event_Gen_init(sf_RenderWindow wnd);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Event_Gen_del(sf_Event_Gen* obj);

/**
 * Returns not 0 if there are events left, otherwise returns 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Event_Gen_has_next(sf_Event_Gen* self);

/**
 * Takes next event from 'window.pollEvent()', creates C-compatible event and
 *returns the result.
 */
SFML_SIMPLE_WRAPPER_API sf_Event* sf_Event_Gen_next(sf_Event_Gen* self);


#ifdef __cplusplus
}
#endif


#endif
