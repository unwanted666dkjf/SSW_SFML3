#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_SPRITE_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_SPRITE_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct the sprite from a sub-rectangle of a source texture.
 */
SFML_SIMPLE_WRAPPER_API sf_Sprite sf_Sprite_from_rect(const sf_Texture texture, const sf_IntRect rect);

/**
 * Construct the sprite from a source texture.
 */
SFML_SIMPLE_WRAPPER_API sf_Sprite sf_Sprite_init(const sf_Texture texture);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Sprite_del(sf_Sprite obj);

/**
 * Change the source texture of the sprite.
 * The `texture` argument refers to a texture that must
 *exist as long as the sprite uses it. Indeed, the sprite
 *doesn't store its own copy of the texture, but rather keeps
 *a pointer to the one that you passed to this function.
 * If the source texture is destroyed and the sprite tries to
 *use it, the behavior is undefined.
 * If `resetRect` is `true`, the `TextureRect` property of
 *the sprite is automatically adjusted to the size of the new
 *texture. If it is `false`, the texture rect is left unchanged.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_texture(sf_Sprite self, const sf_Texture texture, int reset_rect);

/**
 * Set the sub-rectangle of the texture that the sprite will display.
 * The texture rect is useful when you don't want to display
 *the whole texture, but rather a part of it.
 * By default, the texture rect covers the entire texture.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_texture_rect(sf_Sprite self, const sf_IntRect rect);

/**
 * Set the global color of the sprite.
 * This color is modulated (multiplied) with the sprite's
 *texture. It can be used to colorize the sprite, or change
 *its global opacity.
 * By default, the sprite's color is opaque white.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_color(sf_Sprite self, sf_Color color);

/**
 * Get the copy of source texture of the sprite.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Sprite_get_texture(sf_Sprite self);

/**
 * Get the copy of sub-rectangle of the texture displayed by the sprite.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_Sprite_get_texture_rect(sf_Sprite self);

/**
 * Get the global color of the sprite.
 */
SFML_SIMPLE_WRAPPER_API sf_Color sf_Sprite_get_color(sf_Sprite self);

/**
 * Get the local bounding rectangle of the entity.
 * The returned rectangle is in local coordinates, which means
 *that it ignores the transformations (translation, rotation,
 *scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *entity in the entity's coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Sprite_get_local_bounds(sf_Sprite self);

/**
 * Get the global bounding rectangle of the entity.
 * The returned rectangle is in global coordinates, which means
 *that it takes into account the transformations (translation,
 *rotation, scale, ...) that are applied to the entity.
 * In other words, this function returns the bounds of the
 *sprite in the global 2D world's coordinate system.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_Sprite_get_global_bounds(sf_Sprite self);

/**
 * Draw a drawable object to the wnd. Uses sf::RenderStates for drawing.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_draw(sf_Sprite self,
	sf_RenderWindow wnd,
	const sf_RenderStates states
);

/**
 * Set the position of the object.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_position(sf_Sprite self, float left, float top);

/**
 * Set the orientation of the object.
 * This function completely overwrites the previous rotation.
 * See the rotate function to add an angle based on the previous rotation instead.
 * The default rotation of a transformable object is 0.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_rotation(sf_Sprite self, sf_Angle angle);

/**
 * Set the scale factors of the object.
 * This function completely overwrites the previous scale.
 * See the scale function to add a factor based on the previous scale instead.
 * The default scale of a transformable object is (1, 1).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_scale(sf_Sprite self, float kx, float ky);

/**
 * Set the local origin of the object.
 * The origin of an object defines the center point for
 *all transformations (position, scale, rotation).
 * The coordinates of this point must be relative to the
 *top-left corner of the object, and ignore all
 *transformations (position, scale, rotation).
 * The default origin of a transformable object is (0, 0).
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_set_origin(sf_Sprite self, float ox, float oy);

/**
 * Get the position of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Sprite_get_position(sf_Sprite self);

/**
 * Get the orientation of the object.
 * The rotation is always in the range [0, 360].
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_Sprite_get_rotation(sf_Sprite self);

/**
 * Get the current scale of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Sprite_get_scale(sf_Sprite self);

/**
 * Get the local origin of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_Sprite_get_origin(sf_Sprite self);

/**
 * Move the object by a given offset.
 * This function adds to the current position of the object,
 *unlike `setPosition` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_move(sf_Sprite self, float dx, float dy);

/**
 * Rotate the object.
 * This function adds to the current rotation of the object,
 *unlike `setRotation` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_rotate(sf_Sprite self, sf_Angle angle);

/**
 * Scale the object
 * This function multiplies the current scale of the object,
 *unlike `setScale` which overwrites it.
 */
SFML_SIMPLE_WRAPPER_API void sf_Sprite_scale(sf_Sprite self, float kx, float ky);

/**
 * Get the copy of combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Sprite_get_transform(sf_Sprite self);

/**
 * Get the copy of inverse of the combined transform of the object.
 */
SFML_SIMPLE_WRAPPER_API sf_Transform sf_Sprite_get_inverse_transform(sf_Sprite self);


#ifdef __cplusplus
}
#endif


#endif
