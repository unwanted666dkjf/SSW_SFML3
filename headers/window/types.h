#ifndef SFML_SIMPLE_WRAPPER_WINDOW_TYPES_H
#define SFML_SIMPLE_WRAPPER_WINDOW_TYPES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct SFML_SIMPLE_WRAPPER_API sf_Event;

struct SFML_SIMPLE_WRAPPER_API sf_Event_Gen;

struct SFML_SIMPLE_WRAPPER_API sf_Event_Resized;

struct SFML_SIMPLE_WRAPPER_API sf_Event_KeyPressed;

struct SFML_SIMPLE_WRAPPER_API sf_Event_KeyReleased;

struct SFML_SIMPLE_WRAPPER_API sf_Event_MouseWheelScrolled;

struct SFML_SIMPLE_WRAPPER_API sf_Event_MouseButtonPressed;

struct SFML_SIMPLE_WRAPPER_API sf_Event_MouseButtonReleased;

struct SFML_SIMPLE_WRAPPER_API sf_Event_MouseMoved;

struct SFML_SIMPLE_WRAPPER_API sf_Event_MouseMovedRaw;

struct SFML_SIMPLE_WRAPPER_API sf_VideoModes_Gen;


#if defined(_WIN32) || defined(_WIN64)
	#include <windows.h>


	typedef HWND sf_WindowHandle;
#elif defined(__linux__)
	typedef unsigned long sf_WindowHandle;
#else
	typedef void* sf_WindowHandle;
#endif


/**
 * sf::Event alternative for C.
 * Note: event does not owns it's members, you have to do cleanup yourself.
 */
typedef struct sf_Event sf_Event;


/**
 * Generator.
 * Basically, C variant of: 'while (const std::optional event = window.pollEvent()'.
 * Supported events:
 * - sf::Event::Closed(only as type);
 * - sf::Event::FocusLost(only as type);
 * - sf::Event::FocusGained(only as type);
 * - sf::Event::MouseEntered(only as type);
 * - sf::Event::MouseLeft(only as type);
 * - sf_Event_Resized;
 * - sf_Event_KeyPressed;
 * - sf_Event_KeyReleased;
 * - sf_Event_MouseWheelScrolled;
 * - sf_Event_MouseButtonPressed;
 * - sf_Event_MouseButtonReleased;
 * - sf_Event_MouseMoved;
 * - sf_Event_MouseMovedRaw.
 */
typedef struct sf_Event_Gen sf_Event_Gen;


/**
 * Alternative of sf::Event's sf::Event::Resized component.
 */
typedef struct sf_Event_Resized sf_Event_Resized;


/**
 * Alternative of sf::Event's sf::Event::KeyPressed component.
 */
typedef struct sf_Event_KeyPressed sf_Event_KeyPressed;


/**
 * Alternative of sf::Event's sf::Event::KeyReleased component.
 */
typedef struct sf_Event_KeyReleased sf_Event_KeyReleased;


/**
 * Alternative of sf::Event's sf::Event::MouseWheelScrolled component.
 */
typedef struct sf_Event_MouseWheelScrolled sf_Event_MouseWheelScrolled;


/**
 * Alternative of sf::Event's sf::Event::MouseButtonPressed component.
 */
typedef struct sf_Event_MouseButtonPressed sf_Event_MouseButtonPressed;


/**
 * Alternative of sf::Event's sf::Event::MouseButtonReleased component.
 */
typedef struct sf_Event_MouseButtonReleased sf_Event_MouseButtonReleased;


/**
 * Alternative of sf::Event's sf::Event::MouseMoved component.
 */
typedef struct sf_Event_MouseMoved sf_Event_MouseMoved;


/**
 * Alternative of sf::Event's sf::Event::MouseMovedRaw component.
 */
typedef struct sf_Event_MouseMovedRaw sf_Event_MouseMovedRaw;


/**
 * Generator.
 * Retrieve all the video modes supported in fullscreen mode.
 * When creating a fullscreen window, the video mode is restricted
 *to be compatible with what the graphics driver and monitor
 *support. This generator returns all video modes that can
 *be used in fullscreen mode.
 * The first element will always give the best mode
 *(higher width, height and bits-per-pixel).
 */
typedef struct sf_VideoModes_Gen sf_VideoModes_Gen;


/**
 * Opaque type for sf::VideoMode.
 * VideoMode defines a video mode (size, bpp)
 */
typedef void* sf_VideoMode;


/**
 * Opaque type for sf::ContextSettings.
 * ContextSettings allows to define several advanced settings
 *of the OpenGL context attache*d to a window. All these
 *settings with the exception of the compatibility flag
 *and anti-aliasing level have no impact on the regular
 *SFML rendering (graphics module), so you may need to use
 *this structure only if you're using SFML as a windowing
 *system for custom OpenGL rendering.
 *
 * The depthBits and stencilBits members define the number
 *of bits per pixel requested for the (respectively) depth
 *and stencil buffers.
 *
 * antiAliasingLevel represents the requested number of
 *multisampling levels for anti-aliasing.
 *
 * majorVersion and minorVersion define the version of the
 *OpenGL context that you want. Only versions greater or
 *equal to 3.0 are relevant; versions lesser than 3.0 are
 *all handled the same way (i.e. you can use any version
 *< 3.0 if you don't want an OpenGL 3 context).
 *
 * When requesting a context with a version greater or equal
 *to 3.2, you have the option of specifying whether the
 *context should follow the core or compatibility profile
 *of all newer (>= 3.2) OpenGL specifications. For versions
 *3.0 and 3.1 there is only the core profile. By default
 *a compatibility context is created. You only need to specify
 *the core flag if you want a core profile context to use with
 *your own OpenGL rendering.
 *<b>Warning: The graphics module will not function if you
 *request a core profile context. Make sure the attributes are
 *set to Default if you want to use the graphics module.</b>
 *
 * Setting the debug attribute flag will request a context with
 *additional debugging features enabled. Depending on the
 *system, this might be required for advanced OpenGL debugging.
 *OpenGL debugging is disabled by default.
 *
 * <b>Special Note for macOS:</b>
 *Apple only supports choosing between either a legacy context
 *(OpenGL 2.1) or a core context (OpenGL version depends on the
 *operating system version but is at least 3.2). Compatibility
 *contexts are not supported. Further information is available on the
 *<a href="https://developer.apple.com/opengl/capabilities/index.html">
 *OpenGL Capabilities Tables</a> page. macOS also currently does
 *not support debug contexts.
 *
 * Please note that these values are only a hint.
 *No failure will be reported if one or more of these values
 *are not supported by the system; instead, SFML will try to
 *find the closest valid match. You can then retrieve the
 *settings that the window actually used to create its context,
 *with `Window::getSettings()`.
 */
typedef void* sf_ContextSettings;


#ifdef __cplusplus
}
#endif


#endif
