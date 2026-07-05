#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXT_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXT_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the text from a string, font and size
 * Note that if the used font is a bitmap font, it is not
 *scalable, thus not all requested sizes will be available
 *to use. This needs to be taken into consideration when
 *setting the character size. If you need to display text
 *of a certain size, make sure the corresponding bitmap
 *font that supports that size is used.
 */
SFML_SIMPLE_WRAPPER_API sf_Text sf_Text_init(
	const sf_Font fnt,
	sf_String str_,
	unsigned int character_size
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Text_del(sf_Text obj);

/**
 * Set the text's string.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_string(sf_Text self, const sf_String str_);

/**
 * Set the text's font.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_font(sf_Text self, const sf_Font fnt);

/**
 * Set the character size.
 * The default size is 30.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_character_size(sf_Text self, unsigned int character_size);

/**
 * Set the line spacing factor.
 * The default spacing between lines is defined by the font.
 * This method enables you to set a factor for the spacing
 *between lines. By default the line spacing factor is 1.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_line_spacing(sf_Text self, float spacing_factor);

/**
 * Set the letter spacing factor.
 * The default spacing between letters is defined by the font.
 * This factor doesn't directly apply to the existing
 *spacing between each character, it rather adds a fixed
 *space between them which is calculated from the font
 *metrics and the character size.
 * Note that factors below 1 (including negative numbers) bring
 *characters closer to each other.
 * By default the letter spacing factor is 1.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_letter_spacing(sf_Text self, float spacing_factor);

/**
 * Set the text's style.
 * You can pass a combination of one or more styles, for
 *example `sf::Text::Bold | sf::Text::Italic`.
 * The default style is `sf::Text::Regular`.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_style(sf_Text self, unsigned int text_style);

/**
 * Set the fill color of the text.
 * By default, the text's fill color is opaque white.
 * Setting the fill color to a transparent color with an outline
 *will cause the outline to be displayed in the fill area of the text.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_fill_color(sf_Text self, sf_Color color);

/**
 * Set the outline color of the text.
 * By default, the text's outline color is opaque black.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_outline_color(sf_Text self, sf_Color color);

/**
 * Set the thickness of the text's outline
 * By default, the outline thickness is 0.
 *
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_outline_thickness(sf_Text self, float thickness);

/**
 * Set the line alignment for a multi-line text.
 * By default, the lines will be aligned according to the
 *direction of the line's script. Left-to-right scripts
 *will be aligned to the left and right-to-left scripts
 *will be aligned to the right.
 *
 * Forcing alignment will ignore script direction and always
 *align according to the requested line alignment.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_line_alignment(sf_Text self, int line_alignment);

/**
 * Set the text orientation.
 * By default, the lines will have horizontal orientation.
 *
 * Be aware that most fonts don't natively support vertical
 *orientations. Fonts that are the most likely to natively
 *support vertical orientations are those whose scripts
 *also support vertical orientations e.g. east asian scripts.
 *
 * If a font does not natively support vertical orientation,
 *vertical metrics might still be provided for shaping.
 * In this case, they are very likely to be emulated and might
 *not result in good visual output.
 *
 * Some metrics such as advance and baseline position will
 *be rotated so they match the vertical axis.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_text_orientation(sf_Text self, int text_orientation);

/**
 * Get the copy of text's string.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_Text_get_string(sf_Text self);

/**
 * Get the character size.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Text_get_character_size(sf_Text self);

/**
 * Get the size of the letter spacing factor.
 */
SFML_SIMPLE_WRAPPER_API float sf_Text_get_letter_spacing(sf_Text self);

/**
 * Get the size of the line spacing factor.
 */
SFML_SIMPLE_WRAPPER_API float sf_Text_get_line_spacing(sf_Text self);

/**
 * Get the text's style.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Text_get_style(sf_Text self);

/**
 * Get the fill color of the text.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Text_get_fill_color(sf_Text self);

/**
 * Get the outline color of the text.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Text_get_outline_color(sf_Text self);

/**
 * Get the outline thickness of the text.
 */
SFML_SIMPLE_WRAPPER_API float sf_Text_get_outline_thickness(sf_Text self);

/**
 * Get the line alignment for a multi-line text.
 */
SFML_SIMPLE_WRAPPER_API int sf_Text_get_line_alignment(sf_Text self);

/**
 * Get the text orientation.
 */
SFML_SIMPLE_WRAPPER_API int sf_Text_get_text_orientation(sf_Text self);

/**
 * Return the cluster grouping algorithm in use.
 */
SFML_SIMPLE_WRAPPER_API int sf_Text_get_cluster_grouping(sf_Text self);

/**
 * Set the cluster grouping algorithm to use.
 * By default, character cluster grouping is used.
 *
 * Character cluster grouping is good enough to be able to
 *position cursors in most scenarios. If more coarse-grained
 *grouping is required, grapheme grouping can be selected.
 *
 * Cluster grouping can also be disabled if necessary.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_cluster_grouping(sf_Text self, int cluster_grouping);

/**
 * Get the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Text_get_local_bounds(sf_Text self);

/**
 * Get the global bounding rectangle of the entity.
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *text in the global 2D world's coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Text_get_global_bounds(sf_Text self);

/**
 * Draw a drawable object to the wnd. Uses sf::RenderStates for drawing.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_draw(sf_Text self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
);

/**
 * Set the position of the object.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_position(sf_Text self, float left, float top);

/**
 * Set the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_rotation(sf_Text self, sf_Angle angle);

/**
 * Set the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_scale(sf_Text self, float kx, float ky);

/**
 * Set the local origin of the object.
 * The origin of an object defines the center point for
 *all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 *top-left corner of the object, and ignore all
 *transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_set_origin(sf_Text self, float ox, float oy);

/**
 * Get the position of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Text_get_position(sf_Text self);

/**
 * Get the orientation of the object.
 * The rotation is always in the range [0, 360].
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Text_get_rotation(sf_Text self);

/**
 * Get the current scale of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Text_get_scale(sf_Text self);

/**
 * Get the local origin of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Text_get_origin(sf_Text self);

/**
 * Move the object by a given offset.
 * This function adds to the current position of the object,
 *unlike `setPosition` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_move(sf_Text self, float dx, float dy);

/**
 * Rotate the object.
 * This function adds to the current rotation of the object,
 *unlike `setRotation` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_rotate(sf_Text self, sf_Angle angle);

/**
 * Scale the object
 * This function multiplies the current scale of the object,
 *unlike `setScale` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Text_scale(sf_Text self, float kx, float ky);

/**
 * Get the copy of combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Text_get_transform(sf_Text self);

/**
 * Get the copy of inverse of the combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Text_get_inverse_transform(sf_Text self);


#ifdef __cplusplus
}
#endif


#endif
