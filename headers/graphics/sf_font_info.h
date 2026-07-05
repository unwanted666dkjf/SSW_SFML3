#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FONT_INFO_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FONT_INFO_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Font_Info_del(sf_Font_Info* obj);

/**
 * Returns unique ID that identifies the font.
 */
SFML_SIMPLE_WRAPPER_API unsigned long long sf_Font_Info_get_id(sf_Font_Info* self);

/**
 * Returns the font family.
 */
SFML_SIMPLE_WRAPPER_API const char* sf_Font_Info_get_family(sf_Font_Info* self);

/**
 * Returns has kerning information.
 */
SFML_SIMPLE_WRAPPER_API int sf_Font_Info_get_has_kerning(sf_Font_Info* self);

/**
 * Returns has native vertical metrics.
 */
SFML_SIMPLE_WRAPPER_API int sf_Font_Info_get_has_vertical_metrics(sf_Font_Info* self);


#ifdef __cplusplus
}
#endif


#endif
