#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_WINDOW_CONSTANTS_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_WINDOW_CONSTANTS_H


#ifdef __cplusplus
extern "C" {
#endif


//!< No border / title bar (this flag and all others are mutually exclusive)
#define SFML_SIMPLE_WRAPPER_sf_Window_Style_None 0

//!< Title bar + fixed border
#define SFML_SIMPLE_WRAPPER_sf_Window_Style_Titlebar 1

//!< Title bar + resizable border + maximize button
#define SFML_SIMPLE_WRAPPER_sf_Window_Style_Resize 2

//!< Title bar + close button (see note)
#define SFML_SIMPLE_WRAPPER_sf_Window_Style_Close 4

//!< Default window style
#define SFML_SIMPLE_WRAPPER_sf_Window_Style_Default 7


//!< Floating window
#define SFML_SIMPLE_WRAPPER_sf_Window_State_Windowed 0

//!< Fullscreen window
#define SFML_SIMPLE_WRAPPER_sf_Window_State_Fullscreen 1


#ifdef __cplusplus
}
#endif


#endif
