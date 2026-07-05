#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_VIEW_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_VIEW_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor.
 * This constructor creates a default view of (0, 0, 1000, 1000).
 */
SFML_SIMPLE_WRAPPER_API sf_View sf_View_default();

/**
 * Construct the view from a rectangle.
 */
SFML_SIMPLE_WRAPPER_API sf_View sf_View_from_rect(const sf_FloatRect rect);

/**
 * Construct the view from given parameters: center(cx, cy) and size(width, height).
 */
SFML_SIMPLE_WRAPPER_API sf_View sf_View_init(float cx, float cy, float width, float height);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_View_del(sf_View obj);

/**
 * Set the center of the view.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_set_center(sf_View self, float cx, float cy);

/**
 * Set the size of the view.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_set_size(sf_View self, float width, float height);

/**
 * Set the orientation of the view.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_set_rotation(sf_View self, sf_Angle angle);

/**
 * Set the target viewport.
 * The viewport is the rectangle into which the contents of the
 *view are displayed, expressed as a factor (between 0 and 1)      *
 *of the size of the RenderTarget to which the view is applied.
 * For example, a view which takes the left side of the target would
 *be defined with `view.setViewport(sf::FloatRect({0.f, 0.f}, {0.5f, 1.f}))`.
 * By default, a view has a viewport which covers the entire target.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_set_viewport(sf_View self, const sf_FloatRect viewport);

/**
 * Set the target scissor rectangle.
 * The scissor rectangle, expressed as a factor (between 0 and 1) of
 *the RenderTarget*, specifies the region of the RenderTarget whose
 *pixels are able to be modified by draw or clear operations.
 * Any pixels which lie outside of the scissor rectangle will
 *not be modified by draw or clear operations.
 * For example, a scissor rectangle which only allows modifications
 *to the right side of the target would be defined
 *with `view.setScissor(sf::FloatRect({0.5f, 0.f}, {0.5f, 1.f}))`.
 * By default, a view has a scissor rectangle which allows
 *modifications to the entire target. This is equivalent to
 *disabling the scissor test entirely. Passing the default
 *scissor rectangle to this function will also disable
 *scissor testing.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_set_scissor(sf_View self, const sf_FloatRect scissor);

/**
 * Get the center of the view.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_View_get_center(sf_View self);

/**
 * Get the size of the view.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_View_get_size(sf_View self);

/**
 * Get the current orientation of the view.
 */
SFML_SIMPLE_WRAPPER_API sf_Angle sf_View_get_rotation(sf_View self);

/**
 * Get the copy of target viewport rectangle of the view.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_View_get_viewport(sf_View self);

/**
 * Get the copy of scissor rectangle of the view.
 */
SFML_SIMPLE_WRAPPER_API sf_FloatRect sf_View_get_scissor(sf_View self);

/**
 * Move the view relative to its current position.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_move(sf_View self, float dx, float dy);

/**
 * Rotate the view relative to its current orientation.
 */
SFML_SIMPLE_WRAPPER_API void sf_View_rotate(sf_View self, sf_Angle angle);

/**
 * Resize the view rectangle relative to its current size
 * Resizing the view simulates a zoom, as the zone displayed on
 *screen grows or shrinks.
 *\a factor is a multiplier:
 *\li 1 keeps the size unchanged
 *\li > 1 makes the view bigger (objects appear smaller)
 *\li < 1 makes the view smaller (objects appear bigger)
 */
SFML_SIMPLE_WRAPPER_API void sf_View_zoom(sf_View self, float factor);


#ifdef __cplusplus
}
#endif


#endif
