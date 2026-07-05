#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_GLYPH_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_GLYPH_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Glyph_del(sf_Glyph obj);

/**
 * Returns offset to move horizontally to the next character.
 */
SFML_SIMPLE_WRAPPER_API float sf_Glyph_get_advance(sf_Glyph self);

/**
 * Returns left offset after forced autohint. Internally used by getKerning().
 */
SFML_SIMPLE_WRAPPER_API int sf_Glyph_get_lsb_delta(sf_Glyph self);

/**
 * Returns right offset after forced autohint. Internally used by getKerning().
 */
SFML_SIMPLE_WRAPPER_API int sf_Glyph_get_rsb_delta(sf_Glyph self);

/**
 * Returns copy of bounding rectangle of the glyph, in coordinates relative to the baseline.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Glyph_get_bounds(sf_Glyph self);

/**
 * Returns copy of texture coordinates of the glyph inside the font's texture.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_Glyph_get_texture_rect(sf_Glyph self);


#ifdef __cplusplus
}
#endif


#endif
