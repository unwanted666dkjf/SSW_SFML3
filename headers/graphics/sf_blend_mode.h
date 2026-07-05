#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Constructs a blending mode that does alpha blending.
 */
SFML_SIMPLE_WRAPPER_API sf_BlendMode sf_BlendMode_default();

/**
 *  Constructs the blend mode given the factors and equation.
 * \param colorSourceFactor      Specifies how to compute the source factor for the color channels.
 * \param colorDestinationFactor Specifies how to compute the destination factor for the color channels.
 * \param colorBlendEquation     Specifies how to combine the source and destination colors.
 * \param alphaSourceFactor      Specifies how to compute the source factor.
 * \param alphaDestinationFactor Specifies how to compute the destination factor.
 * \param alphaBlendEquation     Specifies how to combine the source and destination alphas.
 */
SFML_SIMPLE_WRAPPER_API sf_BlendMode sf_BlendMode_init(
	int colorSourceFactor,
	int colorDestinationFactor,
	int colorBlendEquation,
	int alphaSourceFactor,
	int alphaDestinationFactor,
	int alphaBlendEquation
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_BlendMode_del(sf_BlendMode obj);

/**
 * Returns source blending factor for the color channels.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_clr_src_factor(sf_BlendMode self);

/**
 * Returns destination blending factor for the color channels.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_clr_dst_factor(sf_BlendMode self);

/**
 * Returns blending equation for the color channels.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_clr_blend_equation(sf_BlendMode self);

/**
 * Returns source blending factor for the alpha channel.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_alpha_src_factor(sf_BlendMode self);

/**
 * Returns destination blending factor for the alpha channel.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_alpha_dst_factor(sf_BlendMode self);

/**
 * Returns blending equation for the alpha channel.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_get_alpha_equation(sf_BlendMode self);

/**
 * Returns 1 if 'self' if 'self' is equal to 'other', otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_is_equal(sf_BlendMode self, const sf_BlendMode other);

/**
 * Returns 0 if 'self' if 'self' is equal to 'other', otherwise 1.
 */
SFML_SIMPLE_WRAPPER_API int sf_BlendMode_is_ne(sf_BlendMode self, const sf_BlendMode other);


#ifdef __cplusplus
}
#endif


#endif
