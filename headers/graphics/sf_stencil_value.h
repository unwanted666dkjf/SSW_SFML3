#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_VALUE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_VALUE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct a stencil value from a signed integer.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilValue sf_StencilValue_from_signed(int value);

/**
 * Construct a stencil value from an unsigned integer.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilValue sf_StencilValue_from_unsigned(unsigned int value);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_StencilValue_del(sf_StencilValue obj);

/**
 * Returns the stored stencil value.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_StencilValue_get_value(sf_StencilValue self);


#ifdef __cplusplus
}
#endif


#endif
