#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXTURE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXTURE_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Creates a texture with width 0 and height 0.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_default();

/**
 * Copy constructor.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_copy(const sf_Texture src);

/**
 * Construct the texture from a sub-rectangle of a file on disk
 * The `area` argument can be used to load only a sub-rectangle
 *of the whole image. If you want the entire image then leave
 *the default value (which is an empty `IntRect`).
 * If the `area` rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the `getMaximumSize` function.
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_from_area(
	const std_Path filename,
	int allow_sRgb,
	const sf_IntRect area
);

/**
 * Construct the texture from an image.
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the `getMaximumSize` function.
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_from_image(const sf_Image image, int allow_sRgb);

/**
 * Construct the texture from an image.
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the `getMaximumSize` function.
 *  The `area` argument is used to load only a sub-rectangle
 *of the whole image.
 * If the `area` rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_from_image_ex(
	const sf_Image image,
	int allow_sRgb,
	const sf_IntRect area
);

/**
 * Construct the texture from a file on disk
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the getMaximumSize function.
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Texture_init(const std_Path filename, int allow_sRgb);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Texture_del(sf_Texture obj);

/**
 * Resize the texture.
 * If this function fails, the texture is left unchanged.
 * 1 if resizing was successful, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_resize(sf_Texture self,
	unsigned int width,
	unsigned int height,
	int allow_sRgb
);

/**
 * Load the full texture from a file on disk.
 * If this function fails, the texture is left unchanged.
 * 1 if loading was successful, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_load_from_file(sf_Texture self, const std_Path filename, int allow_sRgb);

/**
 * Load the texture from a file on disk.
 * The `area` argument can be used to load only a sub-rectangle
 *of the whole image. If you want the entire image then leave
 *the default value (which is an empty `IntRect`).
 * If the `area` rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the `getMaximumSize` function.
 *
 * If this function fails, the texture is left unchanged.
 * 1 if loading was successful, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_load_from_file_ex(sf_Texture self,
	const std_Path filename,
	int allow_sRgb,
	const sf_IntRect area
);

/**
 * Load the full texture from an image.
 * If this function fails, the texture is left unchanged.
 * 1 if loading was successful, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_load_from_image(sf_Texture self, const sf_Image image, int allow_sRgb);

/**
 * Load the texture from an image.
 * The `area` argument can be used to load only a sub-rectangle
 *of the whole image. If you want the entire image then leave
 *the default value (which is an empty `IntRect`).
 * If the `area` rectangle crosses the bounds of the image, it
 *is adjusted to fit the image size.
 *
 * The maximum size for a texture depends on the graphics
 *driver and can be retrieved with the `getMaximumSize` function.
 *
 * If this function fails, the texture is left unchanged.
 * 1 if loading was successful, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_load_from_image_ex(sf_Texture self,
	const sf_Image image,
	int allow_sRgb,
	const sf_IntRect area
);

/**
 * Return the size of the texture.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2u sf_Texture_get_size(sf_Texture self);

/**
 * Update the texture from an image.
 * Although the source image can be smaller than the texture,
 *this function is usually used for updating the whole texture.
 * The other overload, which has an additional destination
 *argument, is more convenient for updating a sub-area of the
 *texture.
 *
 * No additional check is performed on the size of the image.
 * Passing an image bigger than the texture will lead to an
 *undefined behavior.
 *
 * This function does nothing if the texture was not
 *previously created.
 */
SFML_SIMPLE_WRAPPER_API void sf_Texture_update(sf_Texture self, const sf_Image image);

/**
 * Update a part of the texture from an image.
 * No additional check is performed on the size of the image.
 * Passing an invalid combination of image size and destination
 *will lead to an undefined behavior.
 *
 * This function does nothing if the texture was not
 *previously created.
 */
SFML_SIMPLE_WRAPPER_API void sf_Texture_update_ex(sf_Texture self,
	const sf_Image image,
	sf_Vector2u dest
);

/**
 * Returns 1 if smoothing is enabled, 0 if it is disabled.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_get_is_smooth(sf_Texture self);

/**
 * Enable(1) or disable(0) the smooth filter.
 * When the filter is activated, the texture appears smoother
 *so that pixels are less noticeable. However if you want
 *the texture to look exactly the same as its source file,
 *you should leave it disabled.
 * The smooth filter is disabled by default.
 */
SFML_SIMPLE_WRAPPER_API void sf_Texture_set_is_smooth(sf_Texture self, int enable_smooth);

/**
 * Returns 1 if the texture source is converted from sRGB, 0 if not.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_is_Srgb(sf_Texture self);

/**
 * Returns 1 if repeat mode is enabled, 0 if it is disabled.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_get_is_repeated(sf_Texture self);

/**
 * Enable or disable repeating.
 * Repeating is involved when using texture coordinates
 *outside the texture rectangle [0, 0, width, height].
 * In this case, if repeat mode is enabled, the whole texture
 *will be repeated as many times as needed to reach the
 *coordinate (for example, if the X texture coordinate is
 *3 * width, the texture will be repeated 3 times).
 * If repeat mode is disabled, the "extra space" will instead
 *be filled with border pixels.
 * Warning: on very old graphics cards, white pixels may appear
 *when the texture is repeated. With such cards, repeat mode
 *can be used reliably only if the texture has power-of-two
 *dimensions (such as 256x128).
 * Repeating is disabled by default.
 */
SFML_SIMPLE_WRAPPER_API void sf_Texture_set_is_repeated(sf_Texture self, int enable_repeating);

/**
 * Generate a mipmap using the current texture data.
 * Mipmaps are pre-computed chains of optimized textures. Each
 *level of texture in a mipmap is generated by halving each of
 *the previous level's dimensions. This is done until the final
 *level has the size of 1x1. The textures generated in this process may
 *make use of more advanced filters which might improve the visual quality
 *of textures when they are applied to objects much smaller than they are.
 * This is known as minification. Because fewer texels (texture elements)
 *have to be sampled from when heavily minified, usage of mipmaps
 *can also improve rendering performance in certain scenarios.
 *
 * Mipmap generation relies on the necessary OpenGL extension being
 *available. If it is unavailable or generation fails due to another
 *reason, this function will return `false`. Mipmap data is only valid from
 *the time it is generated until the next time the base level image is
 *modified, at which point this function will have to be called again to
 *regenerate it.
 * Returns 1 if mipmap generation was successful, 0 if unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API int sf_Texture_generate_mipmap(sf_Texture self);

/**
 * Get the underlying OpenGL handle of the texture.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Texture_get_native_handle(sf_Texture self);

/**
 * Bind a texture for rendering.
 * This function is not part of the graphics API, it mustn't be
 *used when drawing SFML entities. It must be used only if you
 *mix `sf::Texture` with OpenGL code.
 */
SFML_SIMPLE_WRAPPER_API void sf_Texture_bind(const sf_Texture texture, int coordinate_type);

/**
 * Get the maximum texture size allowed
 * This maximum size is defined by the graphics driver.
 * You can expect a value of 512 pixels for low-end graphics
 *card, and up to 8192 pixels or more for newer hardware.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Texture_get_maximum_size();


#ifdef __cplusplus
}
#endif


#endif
