#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RECTANGLE_SHAPE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RECTANGLE_SHAPE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor.
 */
SFML_SIMPLE_WRAPPER_API sf_RectangleShape sf_RectangleShape_init(float width, float height);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_RectangleShape_del(sf_RectangleShape obj);

/**
 * Get the size of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_size(sf_RectangleShape self);

/**
 * Set the size of the rectangle.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_size(sf_RectangleShape self, float width, float height);

/**
 * Get the number of points defining the shape.
 */
SFML_SIMPLE_WRAPPER_API unsigned long sf_RectangleShape_get_point_count(sf_RectangleShape self);

/**
 * Get a point of the rectangle.
 * The returned point is in local coordinates, that is,
 *the shape's transforms (position, rotation, scale) are
 *not taken into account.
 * The result is undefined if `index` is out of the valid range.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_point(sf_RectangleShape self, unsigned long index);

/**
 * Get the geometric center of the rectangle.
 * The returned point is in local coordinates, that is,
 *the shape's transforms *(position, rotation, scale) are
 *not taken into account.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_geometric_center(sf_RectangleShape self);

/**
 * Draw a drawable object to the wnd. Uses sf::RenderStates for drawing.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_draw(sf_RectangleShape self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
);

/**
 * Change the source texture of the shape.
 * The `texture` argument refers to a texture that must
 *exist as long as the shape uses it. Indeed, the shape
 *doesn't store its own copy of the texture, but rather keeps
 *a pointer to the one that you passed to this function.
 * If the source texture is destroyed and the shape tries to
 *use it, the behavior is undefined.
 *`texture` can be a null pointer to disable texturing.
 * If `resetRect` is 1, the `TextureRect` property of
 *the shape is automatically adjusted to the size of the new
 *texture. If it is 0, the texture rect is left unchanged.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_texture(sf_RectangleShape self,
	const sf_Texture texture,
	int reset_rect
);

/**
 * Set the sub-rectangle of the texture that the shape will display.
 * The texture rect is useful when you don't want to display
 *the whole texture, but rather a part of it.
 * By default, the texture rect covers the entire texture.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_texture_rect(sf_RectangleShape self, const sf_IntRect rect);

/**
 * Set the fill color of the shape.
 * This color is modulated (multiplied) with the shape's
 *texture if any. It can be used to colorize the shape,
 *or change its global opacity.
 * You can use `sf::Color::Transparent` to make the inside of
 *the shape transparent, and have the outline alone.
 * By default, the shape's fill color is opaque white.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_fill_color(sf_RectangleShape self, sf_Color color);

/**
 * Set the outline color of the shape.
 * By default, the shape's outline color is opaque white.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_outline_color(sf_RectangleShape self, sf_Color color);

/**
 * Set the thickness of the shape's outline.
 * Note that negative values are allowed (so that the outline
 *expands towards the center of the shape), and using zero
 *disables the outline.
 * By default, the outline thickness is 0.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_outline_thickness(sf_RectangleShape self, float thickness);

/**
 * Set the limit on the ratio between miter length and outline thickness.
 * Outline segments around each shape corner are joined either
 *with a miter or a bevel join.
 * - A miter join is formed by extending outline segments until
 *   they intersect. The distance between the point of
 *   intersection and the shape's corner is the miter length.
 * - A bevel join is formed by connecting outline segments with
 *   a straight line perpendicular to the corner's bissector.
 *
 * The miter limit is used to determine whether ouline segments
 *around a corner are joined with a bevel or a miter.
 * When the ratio between the miter length and outline thickness
 *exceeds the miter limit, a bevel is used instead of a miter.
 *
 * The miter limit is linked to the maximum inner angle of a
 *corner below which a bevel is used by the following formula:
 *
 * miterLimit = 1 / sin(angle / 2)
 *
 * The miter limit must be greater than or equal to 1.
 * By default, the miter limit is 10.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_miter_limit(sf_RectangleShape self, float limit);

/**
 * Get the copy of source texture of the shape.
 * If the shape has no source texture, undefined behaviour is guaranteed.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_RectangleShape_get_texture(sf_RectangleShape self);

/**
 * Get the copy of sub-rectangle of the texture displayed by the shape.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_RectangleShape_get_texture_rect(sf_RectangleShape self);

/**
 * Get the fill color of the shape.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_RectangleShape_get_fill_color(sf_RectangleShape self);

/**
 * Get the outline color of the shape.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_RectangleShape_get_outline_color(sf_RectangleShape self);

/**
 * Get the outline thickness of the shape.
 */
SFML_SIMPLE_WRAPPER_API float sf_RectangleShape_get_outline_thickness(sf_RectangleShape self);

/**
 * Get the limit on the ratio between miter length and outline thickness.
 */
SFML_SIMPLE_WRAPPER_API float sf_RectangleShape_get_miter_limit(sf_RectangleShape self);

/**
 * Get the global (non-minimal) bounding rectangle of the entity.
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *shape in the global 2D world's coordinate system.
 *
 * This function does not necessarily return the _minimal_
 *bounding rectangle. It merely ensures that the returned
 *rectangle covers all the vertices (but possibly more).
 * This allows for a fast approximation of the bounds as a
 *first check; you may want to use more precise checks
 *on top of that.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_RectangleShape_get_global_bounds(sf_RectangleShape self);

/**
 * Get the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_RectangleShape_get_local_bounds(sf_RectangleShape self);

/**
 * Set the position of the object.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_position(sf_RectangleShape self, float left, float top);

/**
 * Set the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_rotation(sf_RectangleShape self, sf_Angle angle);

/**
 * Set the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_scale(sf_RectangleShape self, float kx, float ky);

/**
 * Set the local origin of the object.
 * The origin of an object defines the center point for
 *all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 *top-left corner of the object, and ignore all
 *transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_set_origin(sf_RectangleShape self, float ox, float oy);

/**
 * Get the position of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_position(sf_RectangleShape self);

/**
 * Get the orientation of the object.
 * The rotation is always in the range [0, 360].
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_RectangleShape_get_rotation(sf_RectangleShape self);

/**
 * Get the current scale of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_scale(sf_RectangleShape self);

/**
 * Get the local origin of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RectangleShape_get_origin(sf_RectangleShape self);

/**
 * Move the object by a given offset.
 * This function adds to the current position of the object,
 *unlike `setPosition` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_move(sf_RectangleShape self, float dx, float dy);

/**
 * Rotate the object.
 * This function adds to the current rotation of the object,
 *unlike `setRotation` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_rotate(sf_RectangleShape self, sf_Angle angle);

/**
 * Scale the object
 * This function multiplies the current scale of the object,
 *unlike `setScale` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_RectangleShape_scale(sf_RectangleShape self, float kx, float ky);

/**
 * Get the copy of combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_RectangleShape_get_transform(sf_RectangleShape self);

/**
 * Get the copy of inverse of the combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_RectangleShape_get_inverse_transform(sf_RectangleShape self);


#ifdef __cplusplus
}
#endif


#endif
