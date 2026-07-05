#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_ANIMATION_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_ANIMATION_H


#include "./types.h"


#ifdef __cplusplus
extern "C" {
#endif


#define SFML_SIMPLE_WRAPPER_ssw_Animation_SpriteNotFound (-1)


/**
 * Creates a new animation that can have a maximum of 'size' sprites.
 * 'size' cannot be lesser than 1.
 * 'animation_speed' cannot be negative.
 */
SFML_SIMPLE_WRAPPER_API ssw_Animation* ssw_Animation_init(unsigned long size, float animation_speed);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* ssw_Animation_del(ssw_Animation* obj);

/**
 * Draws the current sprite from the animation on the window.
 * If there are no sprites, it gives a warning and does nothing.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_draw(ssw_Animation* self,
	sf_RenderWindow wnd,
	const sf_RenderStates render_states
);

/**
 * Moves the current sprite from the animation using the 'dx' and 'dy' offsets.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_move(ssw_Animation* self, float dx, float dy);

/**
 * Flips all sprites from the animation.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_flip(ssw_Animation* self, int flip_x, int flip_y, int global_coords);

/**
 * Sets the position of the current sprite from the animation.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_set_position(ssw_Animation* self, float left, float top);

/**
 * Resizes all sprites in the animation.
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_resize(ssw_Animation* self,
	float width,  float height,
	int   keep_w, int keep_h
);

/**
 * Resizes all sprites in the animation using 'kx' and 'ky'.
 * Scaling occurs relative to the current sprite size.
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 */
SFML_SIMPLE_WRAPPER_API void ssw_Animation_scale(ssw_Animation* self,
	float kx,     float ky,
	int   keep_w, int keep_h
);

/**
 * Calculates the index of the next sprite for the animation,
 *replaces the current sprite, and returns the index of the sprite.
 * If the current sprite or the next sprite does not exist, shows
 *a warning message and does nothing.
 */
SFML_SIMPLE_WRAPPER_API unsigned long ssw_Animation_update(ssw_Animation* self);

/**
 * Creates a new sprite for the animation using given parameters.
 * Does not own the textures themselves, i.e. you will need to delete them yourself.
 * If the sprite is created, it returns 1, otherwise 0.
 * Of the inner array is full and can no longer accept elements returns 0 either.
 * If 'keep_w' is not 0, it will preserve the width-to-height ratio.
 * If 'keep_h' is not 0, it will preserve the height-to-width ratio.
 * If 'keep_w' and 'keep_h' are not 0, both will be ignored.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_add_item(ssw_Animation* self,
	const sf_Texture texture,
	float width,  float height,
	int   keep_w, int keep_h
);

/**
 * Returns a pointer to the current sprite from the animation.
 * If there are no sprites in the animation, it will return NULL.
 */
SFML_SIMPLE_WRAPPER_API sf_Sprite ssw_Animation_get_current(ssw_Animation* self);

/**
 * Returns a sprite from animation by index.
 * If there are no sprites in the animation, it will return NULL.
 * If the index exceeds the maximum allowed, it will also return NULL.
 */
SFML_SIMPLE_WRAPPER_API sf_Sprite ssw_Animation_get_sprite(ssw_Animation* self, unsigned long ind);

/**
 * Returns length(number of sprites) of the animation.
 */
SFML_SIMPLE_WRAPPER_API unsigned long ssw_Animation_get_length(ssw_Animation* self);

/**
 * Returns size(capacity) of the animation.
 */
SFML_SIMPLE_WRAPPER_API unsigned long ssw_Animation_get_size(ssw_Animation* self);

/**
 * Returns index of current active sprite.
 * If there are no sprites, returns 'ssw_Animation_SpriteNotFound'.
 */
SFML_SIMPLE_WRAPPER_API long ssw_Animation_get_cur_ind(ssw_Animation* self);

/**
 * Returns 1 if the current index is the same as the end of the animation index, otherwise 0.
 * If there are no sprites in the animation, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_get_is_end(ssw_Animation* self);

/**
 * Returns 1 if the current index is the same as the start of the animation index, otherwise 0.
 * If there are no sprites in the animation, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_get_is_start(ssw_Animation* self);

/**
 * Returns 1 if the index of the current sprite from the animation is between
 *zero and the number of sprites in the animation.
 * If there are no sprites in the animation, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_get_is_running(ssw_Animation* self);

/**
 * If there are no sprites in the animation, returns 1. Otherwise, returns 0.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_get_is_empty(ssw_Animation* self);

/**
 * Returns 1 if the inner array is full and can no longer accept elements.
 */
SFML_SIMPLE_WRAPPER_API int ssw_Animation_get_is_full(ssw_Animation* self);

/**
 * Returns the global boundaries of the current sprite from the animation.
 * If there are no sprites in the animation, returns an empty rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect ssw_Animation_cur_global_bounds(ssw_Animation* self);

/**
 * Returns the local boundaries of the current sprite from the animation.
 * If there are no sprites in the animation, returns an empty rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect ssw_Animation_cur_local_bounds(ssw_Animation* self);


#ifdef __cplusplus
}
#endif


#endif
