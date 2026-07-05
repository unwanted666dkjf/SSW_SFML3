#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RENDER_WINDOW_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_RENDER_WINDOW_H


#include "./types.h"

#include "../system/types.h"

#include "../window/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * This constructor doesn't actually create the window,
 *use the other constructors or call `create()` to do so.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderWindow sf_RenderWindow_default();

/**
 * This constructor creates the window with the size and pixel depth defined in
 *`mode`. If `state` is `State::Fullscreen`, then `mode` must be a valid video mode.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderWindow sf_RenderWindow_init(
	sf_VideoMode mode,
	const sf_String title,
	int state
);

/**
 * Construct a new window
 * This constructor creates the window with the size and pixel
 *depth defined in `mode`. An optional style can be passed to
 *customize the look and behavior of the window (borders,
 *title bar, resizable, closable, ...).
 *
 * The last parameter specifying
 *advanced OpenGL context settings such as anti-aliasing,
 *depth-buffer bits, etc. You shouldn't care about these
 *parameters for a regular usage of the graphics module.
 */
SFML_SIMPLE_WRAPPER_API sf_RenderWindow sf_RenderWindow_init_ex(
	sf_VideoMode mode,
	const sf_String title,
	unsigned int style,
	int state,
	const sf_ContextSettings settings
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_RenderWindow_del(sf_RenderWindow obj);

/**
 * Get the size of the rendering region of the window.
 * The size doesn't include the titlebar and borders of the window.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2u sf_RenderWindow_get_size(sf_RenderWindow self);

/**
 * Change the window's icon.
 * The image is copied, so you need not keep the
 *source alive after calling this function.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_icon(sf_RenderWindow self, const sf_Image icon);

/**
 * Tell if the window will use sRGB encoding when drawing on it.
 * You can request sRGB encoding for a window by having the
 *sRgbCapable flag set in the `ContextSettings`.
 * 1 if the window use sRGB encoding, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_RenderWindow_is_Srgb(sf_RenderWindow self);

/**
 * Activate or deactivate the window as the current target for OpenGL rendering.
 * A window is active only on the current thread, if you want to
 *make it active on another thread you have to deac*tivate it
 *on the previous thread first if it was active.
 * Only one window can be active on a thread at a time, thus
 *the window previously active (if any) automatically gets deactivated.
 * This is not to be confused with `requestFocus()`.
 * 1 to activate, 0 to deactivate.
 * 1 if operation was successful, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_RenderWindow_set_active(sf_RenderWindow self, int is_active);

/**
 * Create (or recreate) the window.
 * If the window was already created, it closes it first.
 * If `state` is `State::Fullscreen`, then `mode` must be
 *a valid video mode.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_create(sf_RenderWindow self,
	sf_VideoMode mode,
	const sf_String title,
	int state
);

/**
 * Create (or recreate) the window.
 * If the window was already created, it closes it first.
 * If `state` is `State::Fullscreen`, then `mode` must be
 *a valid video mode.
 * The last parameter is a structure specifying advanced OpenGL
 *context settings such as anti-aliasing, depth-buffer bits, etc.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_create_ex(sf_RenderWindow self,
	sf_VideoMode mode,
	const sf_String title,
	unsigned int style,
	int state,
	const sf_ContextSettings settings
);

/**
 * Close the window and destroy all the attached resources.
 * After calling this function, the `sf::Window` instance remains
 *valid and you can call `create()` to recre*ate the window.
 * All other functions such as `pollEvent()` or `display()` will
 *still work (i.e. you don't have to test `isOpen()` every time),
 *and will have no effect on closed windows.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_close(sf_RenderWindow self);

/**
 * Get the copy of the settings of the OpenGL context of the window.
 * Note that these settings may be different from what was
 *passed to the constructor or *the `create()` function,
 *if one or more settings were not supported. In this case,
 *SFML chose the closest match.
 */
SFML_SIMPLE_WRAPPER_API sf_ContextSettings sf_RenderWindow_get_settings(sf_RenderWindow self);

/**
 * Enable or disable vertical synchronization.
 * Activating vertical synchronization will limit the number
 *of frames displayed to the refresh rate of the m*onitor.
 * This can avoid some visual artifacts, and limit the framerate
 *to a good value (but not constant across different computers).
 * Vertical synchronization is disabled by default.
 * 1 to enable v-sync, 0 to deactivate it
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_vertical_sync_enabled(sf_RenderWindow self, int is_enabled);

/**
 * Limit the framerate to a maximum fixed frequency.
 * If a limit is set, the window will use a small delay after
 *each call to `d*isplay()` to ensure that the current frame
 *lasted long enough to match the framerate limit.
 * SFML will try to match the given limit as much as it can,
 *but since it internally uses `sf::sleep`, whose precision
 *depends on the underlying OS, the results may be a little
 *imprecise as well (for example, you can get 65 FPS when requesting 60).
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_framerate_limit(sf_RenderWindow self, unsigned int limit);

/**
 * Display on screen what has been rendered to the window so far.
 * This function is typically called after all OpenGL rendering
 *has been done* for the current frame, in order to show it on screen.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_display(sf_RenderWindow self);

/**
 * Tell whether or not the window is open.
 * This function returns whether or not the window exists.
 * Note that a hidden window (`setVisible(false)`) is open
 *(therefore this function would return `1`).
 * 1 if the window is open, 0 if it has been closed.
 */
SFML_SIMPLE_WRAPPER_API int sf_RenderWindow_is_open(sf_RenderWindow self);

/**
 * Returns sf_Event_Gen generator.
 * Generator calls 'const std::optional event = window.pollEvent()' and pops
 *the next event as sf_Event* from the front of the FIFO event queue, if any, and returns it.
 */
SFML_SIMPLE_WRAPPER_API sf_Event_Gen* sf_RenderWindow_poll_event(sf_RenderWindow self);

/**
 * Get the position of the window.
 * Returns position of the window, in pixels.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_RenderWindow_get_position(sf_RenderWindow self);

/**
 * Changes the position of the window on screen.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_position(sf_RenderWindow self, int x, int y);

/**
 * Moves the window across the screen using dx and dy offsets.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_move(sf_RenderWindow self, int dx, int dy);

/**
 * Changes the size of the rendering region of the window.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
);

/**
 * Change the title of the window.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_title(sf_RenderWindow self, const sf_String title);

/**
 * Show or hide the window.
 * The window is shown by default.
 * 1 to show the window, 0 to hide it.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_visible(sf_RenderWindow self, int is_visible);

/**
 * Show or hide the mouse cursor.
 * The mouse cursor is visible by default.
 * On Windows, this function needs to be called from the thread that created the window.
 * 1 to show the mouse cursor, 0 to hide it.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_mouse_cursor_visible(sf_RenderWindow self, int is_visible);

/**
 * Grab or release the mouse cursor.
 * If set, grabs the mouse cursor inside this window's client
 *area so it may no longer be moved outside its bounds.
 * Note that grabbing is only active while the window has focus.
 * 1 to enable, 0 to disable.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_mouse_cursor_grabbed(sf_RenderWindow self, int is_grabbed);

/**
 * Enable or disable automatic key-repeat.
 * If key repeat is enabled, you will receive repeated
 * KeyPressed events while keeping a* key pressed. If it is disabled,
 *you will only get a single event when the key is pressed.
 * Key repeat is enabled by default.
 * 1 to enable, 0 to disable.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_key_repeat_enabled(sf_RenderWindow self, int is_enabled);

/**
 * Request the current window to be made the active foreground window.
 * At any given time, only one window may have the input focus
 *to receive input events such as keystrokes or *mouse events.
 * If a window requests focus, it only hints to the operating
 *system, that it would like to be focused. The operating system
 *is free to deny the request.
 * This is not to be confused with `setActive()`.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_request_focus(sf_RenderWindow self);

/**
 * Check whether the window has the input focus.
 * At any given time, only one window may have the input focus
 *to receive input events such as keystrokes or most mouse events.
 * 1 if window has focus, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_RenderWindow_has_focus(sf_RenderWindow self);

/**
 * Get the OS-specific handle of the window.
 * The type of the returned handle is `sf::WindowHandle`,
 *which is a type alias to the handle type defined by the O*S.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 */
SFML_SIMPLE_WRAPPER_API sf_WindowHandle sf_RenderWindow_get_native_handle(sf_RenderWindow self);

/**
 * Set the minimum window rendering region size.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_minimum_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
);

/**
 * Unset the minimum window rendering region size.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_unset_minimum_size(sf_RenderWindow self);

/**
 * Set the maximum window rendering region size.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_maximum_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
);

/**
 * Unset the maximum window rendering region size.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_unset_maximum_size(sf_RenderWindow self);

/**
 * Clear the entire target with a single color.
 * This function is usually called once every frame,
 *to clear the previous contents of the target.
 * Given color will be used to clear the render target.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_clear(sf_RenderWindow self, sf_Color color);

/**
 * Clear the stencil buffer to a specific value.
 * The specified value is truncated to the bit width of
 *the current stencil buffer.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_clear_stencil(sf_RenderWindow self, sf_StencilValue value);

/**
 * Clear the entire target with a single color and stencil value.
 * The specified stencil value is truncated to the bit
 *width of the current stencil buffer.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_clear_ex(sf_RenderWindow self,
	sf_Color color,
	sf_StencilValue value
);

/**
 * Change the current active view
 * The view is like a 2D camera, it controls which part of
 *the 2D scene is visible, and how it is viewed in the
 *render target.
 * The new view will affect everything that is drawn, until
 *another view is set.
 * The render target keeps its own copy of the view object,
 *so it is not necessary to keep the original one alive
 *after calling this function.
 * To restore the original view of the target, you can pass
 *the result of `getDefaultView()` to this function.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_set_view(sf_RenderWindow self, const sf_View view);

/**
 * Get the copy of view currently in use in the render target.
 */
SFML_SIMPLE_WRAPPER_API sf_View sf_RenderWindow_get_view(sf_RenderWindow self);

/**
 * Get the copy of default view of the render target.
 * The default view has the initial size of the render target,
 *and never changes after the target has been created.
 */
SFML_SIMPLE_WRAPPER_API sf_View sf_RenderWindow_get_default_view(sf_RenderWindow self);

/**
 * Get the viewport of a view, applied to this render target.
 * The viewport is defined in the view as a ratio, this function
 *simply applies this ratio to t*he current dimensions of the
 *render target to calculate the pixels rectangle that the viewport
 *actually covers in the target.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_RenderWindow_get_viewport(sf_RenderWindow self, const sf_View view);

/**
 * Get the scissor rectangle of a view, applied to this render target.
 * The scissor rectangle is defined in the view as a ratio. This
 *function simply applies this ratio to the current dimensi*ons
 *of the render target to calculate the pixels rectangle
 *that the scissor rectangle actually covers in the target.
 */
SFML_SIMPLE_WRAPPER_API sf_IntRect sf_RenderWindow_get_scissor(sf_RenderWindow self, const sf_View view);

/**
 * Convert a point from target coordinates to world coordinates, using the current view.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RenderWindow_map_pixel_to_coords(sf_RenderWindow self, int x, int y);

/**
 * Convert a point from target coordinates to world coordinates.
 * This function finds the 2D position that matches the
 *given pixel of* the render target. In other words, it does
 *the inverse of what the graphics card does, to find the
 *initial position of a rendered pixel.
 *
 * Initially, both coordinate systems (world units and target pixels)
 *match perfectly. But if you define a custom view or resize your
 *render target, this assertion is not `true` anymore, i.e. a point
 *located at (10, 50) in your render target may map to the point
 *(150, 75) in your 2D world -- if the view is translated by (140, 25).
 *
 * For render-windows, this function is typically used to find
 *which point (or object) is located below the mouse cursor.
 *
 * This version uses a custom view for calculations, see the other
 *overload of the function if you want to use the current view of the
 *render target.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2f sf_RenderWindow_map_pixel_to_coords_ex(sf_RenderWindow self,
	int x, int y,
	const sf_View view
);

/**
 * Convert a point from world coordinates to target coordinates, using the current view.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_RenderWindow_map_coords_to_pixel(sf_RenderWindow self, float x, float y);

/**
 * Convert a point from world coordinates to target coordinates.
 * This function finds the pixel of the render target that matches
 *the given 2D point. In other words, it goes through the same process
 *as the graphics card, to compute the final position of a rendered point.
 *
 * Initially, both coordinate systems (world units and target pixels)
 *match perfectly. But if you define a custom view or resize your
 *render target, this assertion is not `true` anymore, i.e. a point
 *located at (150, 75) in your 2D world may map to the pixel
 *(10, 50) of your render target -- if the view is translated by (140, 25).
 *
 * This version uses a custom view for calculations, see the other
 *overload of the function if you want to use the current view of the
 *render target.
 */
SFML_SIMPLE_WRAPPER_API sf_Vector2i sf_RenderWindow_map_coords_to_pixel_ex(sf_RenderWindow self,
	float x, float y,
	const sf_View view
);

/**
 * Save the current OpenGL render states and matrices
 * This function can be used when you mix SFML drawing
 *and direct OpenGL rendering. Combined with popGLStates,
 *it ensures that:
 * \li SFML's internal states are not messed up by your OpenGL code
 * \li your OpenGL states are not modified by a call to a SFML function
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_push_gl_states(sf_RenderWindow self);

/**
 * Restore the previously saved OpenGL render states and matrices.
 * See the description of `pushGLStates` to get a detailed description of these functions.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_pop_gl_states(sf_RenderWindow self);

/**
 * Reset the internal OpenGL states so that the target is ready for drawing.
 * This function can be used when you mix SFML drawing
 *and direct OpenGL rendering, if you choose not to use
 *`pushGLStates`/`popGLStates`. It makes sure that all OpenGL
 *states needed by SFML are set, so that subsequent `draw()`
 *calls will work as expected.
 */
SFML_SIMPLE_WRAPPER_API void sf_RenderWindow_reset_gl_states(sf_RenderWindow self);


#ifdef __cplusplus
}
#endif


#endif
