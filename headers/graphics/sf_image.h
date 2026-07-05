#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_IMAGE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_IMAGE_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Constructs an image with width 0 and height 0.
 */
SFML_SIMPLE_WRAPPER_API sf_Image sf_Image_default();

/**
 * Construct the image from a file on disk.
 * The supported image formats are bmp, png, tga, jpg, gif,
 *psd, hdr, pic and pnm. Some format options are not supported,
 *like jpeg with arithmetic coding or ASCII pnm.
 *
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Image sf_Image_init(const std_Path path);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Image_del(sf_Image obj);

/**
 * Load the image from a file on disk.
 * The supported image formats are bmp, png, tga, jpg, gif,
 *psd, hdr, pic and pnm. Some format options are not supported,
 *like jpeg with arithmetic coding or ASCII pnm.
 * If this function fails, the image is left unchanged.
 * Returns 1 if successful, otherwise 0.
 */
SFML_SIMPLE_WRAPPER_API int sf_Image_load(sf_Image self, const std_Path path);

/**
 * Save the image to a file on disk.
 * The format of the image is automatically deduced from
 *the extension. The supported image formats are bmp, png,
 *tga and jpg. The destination file is overwritten
 *if it already exists. This function fails if the image is empty.
 */
SFML_SIMPLE_WRAPPER_API int sf_Image_save(sf_Image self, const std_Path path);

/**
 * Return the size (width and height) of the image.
 * Size of the image, in pixels.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2u sf_Image_get_size(sf_Image self);

/**
 * Get a read-only pointer to the array of pixels.
 * The returned value points to an array of RGBA pixels made of
 *8 bit integer components. The size of the array is
 *`width * height * 4 (getSize().x * getSize().y * 4)`.
 * Warning: the returned pointer may become invalid if you
 *modify the image, so you should never store it for too long.
 * If the image is empty, a null pointer is returned.
 */
SFML_SIMPLE_WRAPPER_API const unsigned char* sf_Image_get_pixels_ptr(sf_Image self);

/**
 * Flip the image horizontally (left <-> right).
 */
SFML_SIMPLE_WRAPPER_API void sf_Image_flip_horizontally(sf_Image self);

/*
 * Flip the image vertically (top <-> bottom),
 */
SFML_SIMPLE_WRAPPER_API void sf_Image_flip_vertically(sf_Image self);

/**
 * Create a transparency mask from a specified color-key.
 * This function sets the alpha value of every pixel matching
 *the given color to `alpha`, so that they
 *become transparent.
 */
SFML_SIMPLE_WRAPPER_API void sf_Image_create_mask_from_color(sf_Image self, sf_Color color, unsigned char alpha);


#ifdef __cplusplus
}
#endif


#endif
