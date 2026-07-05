#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RENDER_STATES_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RENDER_STATES_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor
 * Constructing a default set of render states is equivalent
 *to using `sf::RenderStates::Default`.
 * The default set defines:
 * \li the `BlendAlpha` blend mode
 * \li the default `StencilMode` (no stencil)
 * \li the identity transform
 * \li a `nullptr` texture
 * \li a `nullptr` shader
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_default();

/**
 * Construct a default set of render states with a custom blend mode.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_from_blend_mode(const sf_BlendMode mode);

/**
 * Construct a default set of render states with a custom stencil mode.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_from_stencil_mode(const sf_StencilMode mode);

/**
 * Construct a default set of render states with a custom transform.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_from_transform(const sf_Transform transform);

/**
 * Construct a default set of render states with a custom texture.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_from_texture(const sf_Texture texture);

/**
 * Construct a default set of render states with a custom shader.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_from_shader(const sf_Shader shader);

/**
 * Construct a set of render states with all its attributes.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderStates sf_RenderStates_init(
	const sf_BlendMode blend_mode,
	const sf_StencilMode stencil_mode,
	const sf_Transform transform,
	int coordinate_type,
	const sf_Texture texture,
	const sf_Shader shader
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_RenderStates_del(sf_RenderStates obj);

/**
 * Returns the copy of blending mode.
 */
SFML_SIMPLE_WRAPPER_API sf_BlendMode sf_RenderStates_blend_mode(sf_RenderStates self);

/**
 * Returns the copy of stencil mode.
 */
SFML_SIMPLE_WRAPPER_API sf_StencilMode sf_RenderStates_stencil_mode(sf_RenderStates self);

/**
 * Returns the copy of transform.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_RenderStates_transform(sf_RenderStates self);

/**
 * Returns texture coordinate type.
 */
SFML_SIMPLE_WRAPPER_API int sf_RenderStates_coordinate_type(sf_RenderStates self);


#ifdef __cplusplus
}
#endif


#endif
