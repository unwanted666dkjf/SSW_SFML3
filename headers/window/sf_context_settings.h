#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_CONTEXT_SETTINGS_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_CONTEXT_SETTINGS_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


// Non-debug, compatibility context (this and the core attribute are mutually exclusive)
#define SFML_SIMPLE_WRAPPER_sf_ContextSettings_Attribute_Default 0

// Core attribute
#define SFML_SIMPLE_WRAPPER_sf_ContextSettings_Attribute_Core 1

// Debug attribute
#define SFML_SIMPLE_WRAPPER_sf_ContextSettings_Attribute_Debug 4


/**
 * Default sf_ContextSettings.
 */
SFML_SIMPLE_WRAPPER_API sf_ContextSettings sf_ContextSettings_get_default();

/**
 * Constructs sf_ContextSettings from given parameters.
 */
SFML_SIMPLE_WRAPPER_API sf_ContextSettings sf_ContextSettings_init(
	int sRgbCapable,
	unsigned int depthBits,
	unsigned int stencilBits,
	unsigned int antiAliasingLevel,
	unsigned int majorVersion,
	unsigned int minorVersion,
	unsigned int attributeFlags
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_ContextSettings_del(sf_ContextSettings obj);

/**
 * Returns sRgbCapable.
 */
SFML_SIMPLE_WRAPPER_API int sf_ContextSettings_get_sRgbCapable(sf_ContextSettings self);

/**
 * Returns depthBits.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_depth_bits(sf_ContextSettings self);

/**
 * Returns stencilBits.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_stencil_bits(sf_ContextSettings self);

/**
 * Returns antiAliasingLevel.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_anti_aliasing_level(sf_ContextSettings self);

/**
 * Returns majorVersion.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_major_version(sf_ContextSettings self);

/**
 * Returns minorVersion.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_minor_version(sf_ContextSettings self);

/**
 * Returns attributeFlags.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_ContextSettings_get_attribute_flags(sf_ContextSettings self);


#ifdef __cplusplus
}
#endif


#endif
