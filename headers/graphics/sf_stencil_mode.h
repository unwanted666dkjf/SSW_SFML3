#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_MODE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_MODE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Constructs default sf::StencilMode.
 * Values are:
 * - self->stencilComparison      = sf::StencilComparison::Always;
 * - self->stencilUpdateOperation = sf::St*encilUpdateOperation::Keep;
 * - self->stencilReference       = sf::StencilValue(0);
 * - self->stencilMask            = sf::StencilValue(~0u);
 * - self->stencilOnly            = false;
 */
SFML_SIMPLE_WRAPPER_API sf_StencilMode sf_StencilMode_default();

/**
 * Constructs sf::StencilMode from integer values.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilMode sf_StencilMode_from_int(
	int stencilOnly,
	int stencilComparison,
	int stencilUpdateOperation,
	int stencilReference,
	int stencilMask
);

/**
 * Constructs sf::StencilMode from given parameters.
 * Given 'stencilReference' and 'stencilMask' will be copied.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilMode sf_StencilMode_init(
	int stencilOnly,
	int stencilComparison,
	int stencilUpdateOperation,
	sf_StencilValue stencilReference,
	sf_StencilValue stencilMask
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_StencilMode_del(sf_StencilMode obj);

/**
 * Returns value of stencilOnly.
 */
SFML_SIMPLE_WRAPPER_API int sf_StencilMode_get_stencil_only(sf_StencilMode self);

/**
 * Returns value of stencilComparison.
 */
SFML_SIMPLE_WRAPPER_API int sf_StencilMode_get_stencil_comparison(sf_StencilMode self);

/**
 * Returns value of stencilUpdateOperation.
 */
SFML_SIMPLE_WRAPPER_API int sf_StencilMode_get_stencil_update_operation(sf_StencilMode self);

/**
 * Returns copy of stencilReference value.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilValue sf_StencilMode_get_stencil_reference(sf_StencilMode self);

/**
 * Returns copy of stencilMask value.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilValue sf_StencilMode_get_stencil_mask(sf_StencilMode self);

/**
 * Returns 1 if stencil modes are equal, 0 if they are different.
 */
SFML_SIMPLE_WRAPPER_API int sf_StencilMode_is_equal(sf_StencilMode self, const sf_StencilMode other);

/**
 * Returns 0 if stencil modes are equal, 1 if they are different.
 */
SFML_SIMPLE_WRAPPER_API int sf_StencilMode_is_ne(sf_StencilMode self, const sf_StencilMode other);


#ifdef __cplusplus
}
#endif


#endif
