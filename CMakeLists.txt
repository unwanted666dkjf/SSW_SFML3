cmake_minimum_required(VERSION 3.18)

set(PROJECT SFML_SimpleWrapper)

project(${PROJECT})
# On windows, it is preferred to use msvc, on linux -- gcc.

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

option(BUILD_SHARED "Build as shared library" OFF)

option(BUILD_STATIC "Build as static library" ON)

if(NOT DEFINED CMAKE_BUILD_TYPE)
	set(BUILD_DEBUG ON)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")	# Affects only windows
	set(BUILD_DEBUG OFF)
else()
	set(BUILD_DEBUG OFF)
endif()

if(MSVC)
	set(CMAKE_C_FLAGS_DEBUG   "/Zi /Od /MTd")
  set(CMAKE_C_FLAGS_RELEASE "/O2 /DNDEBUG /MT /Gy")
  set(CMAKE_CXX_FLAGS_DEBUG   "/Zi /Od /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG /MT /Gy")
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
	set(CMAKE_C_FLAGS_DEBUG   "-g -O0")
	set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG -ffunction-sections -fdata-sections -Wl,--gc-sections")
	set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -ffunction-sections -fdata-sections -Wl,--gc-sections")
endif()

if(MSVC)
  add_compile_options(
    /W3 /permissive- 
  )
else()
  add_compile_options(
    -Wall -Wextra -Wpedantic
  )
endif()

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SFML_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

# SFML 3.2.0

if(WIN32)
	set(LIB_SFML_SYSTEM_DBG   "${SFML_LIB_DIR}/win/Debug/sfml-system-s-d.lib")
	set(LIB_SFML_WINDOW_DBG   "${SFML_LIB_DIR}/win/Debug/sfml-window-s-d.lib")
	set(LIB_SFML_GRAPHICS_DBG "${SFML_LIB_DIR}/win/Debug/sfml-graphics-s-d.lib")
	set(LIB_SFML_AUDIO_DBG    "${SFML_LIB_DIR}/win/Debug/sfml-audio-s-d.lib")

	set(LIB_SFML_SYSTEM_REL   "${SFML_LIB_DIR}/win/Release/sfml-system-s.lib")
	set(LIB_SFML_WINDOW_REL   "${SFML_LIB_DIR}/win/Release/sfml-window-s.lib")
	set(LIB_SFML_GRAPHICS_REL "${SFML_LIB_DIR}/win/Release/sfml-graphics-s.lib")
	set(LIB_SFML_AUDIO_REL    "${SFML_LIB_DIR}/win/Release/sfml-audio-s.lib")
else()
	set(SFML_LIBS_OS_DEP "${SFML_LIB_DIR}/lin")
	set(LIB_SFML_SYSTEM "${SFML_LIBS_OS_DEP}/libsfml-system-s.a")
	set(LIB_SFML_WINDOW "${SFML_LIBS_OS_DEP}/libsfml-window-s.a")
	set(LIB_SFML_GRAPHICS "${SFML_LIBS_OS_DEP}/libsfml-graphics-s.a")
	set(LIB_SFML_AUDIO "${SFML_LIBS_OS_DEP}/libsfml-audio-s.a")
endif()

set(SOURCES
	src/system/std_walk.cpp
	src/system/std_path.cpp
	src/system/sf_time.cpp
	src/system/sf_sleep.cpp
	src/system/sf_clock.cpp
	src/system/sf_angle.cpp
	src/system/sf_string.cpp
	src/system/sf_vector2f.cpp
	src/system/sf_vector2i.cpp
	src/system/sf_vector2u.cpp
	src/system/sf_vector3f.cpp

	src/window/sf_keyboard.cpp
	src/window/sf_clipboard.cpp
	src/window/sf_mouse.cpp
	src/window/sf_event.cpp
	src/window/sf_event_gen.cpp
	src/window/sf_event_resized.cpp
	src/window/sf_event_key_pressed.cpp
	src/window/sf_event_key_released.cpp
	src/window/sf_event_mouse_moved.cpp
	src/window/sf_event_mouse_moved_raw.cpp
	src/window/sf_event_mouse_wheel_scrolled.cpp
	src/window/sf_event_mouse_button_pressed.cpp
	src/window/sf_event_mouse_button_released.cpp
	src/window/sf_video_mode.cpp
	src/window/sf_context_settings.cpp
	src/window/sf_video_modes_gen.cpp

	src/graphics/animation.cpp
	src/graphics/sf_glyph.cpp
	src/graphics/sf_font.cpp
	src/graphics/sf_font_info.cpp
	src/graphics/sf_text.cpp
	src/graphics/sf_image.cpp
	src/graphics/sf_color.cpp
	src/graphics/sf_view.cpp
	src/graphics/sf_sprite.cpp
	src/graphics/sf_texture.cpp
	src/graphics/sf_int_rect.cpp
	src/graphics/sf_float_rect.cpp
	src/graphics/sf_transform.cpp
	src/graphics/sf_render_states.cpp
	src/graphics/sf_render_window.cpp
	src/graphics/sf_stencil_value.cpp
	src/graphics/sf_stencil_mode.cpp
	src/graphics/sf_blend_mode.cpp
	src/graphics/sf_shader.cpp
	src/graphics/sf_circle_shape.cpp
	src/graphics/sf_rectangle_shape.cpp
	src/graphics/useful_funcs.cpp

	src/audio/sf_listener.cpp
	src/audio/sf_listener_cone.cpp
	src/audio/sf_music.cpp
	src/audio/sf_sound.cpp
	src/audio/sf_sound_buffer.cpp
	src/audio/sf_sound_buffer_recorder.cpp
	src/audio/sf_sound_source_cone.cpp
	src/audio/sf_sound_recorder_gen.cpp
	src/audio/sf_input_sound_file.cpp
	src/audio/sf_playback_device.cpp
	src/audio/sf_playback_device_gen.cpp
)

if(BUILD_SHARED)
	add_library(${PROJECT} SHARED ${SOURCES})
	target_compile_definitions(${PROJECT}
		PRIVATE SFML_SIMPLE_WRAPPER_EXPORTS
	)
elseif(BUILD_STATIC)
	add_library(${PROJECT} STATIC ${SOURCES})
else()
	list(APPEND SOURCES main.c)
	add_executable(${PROJECT} ${SOURCES})
endif()

target_include_directories(${PROJECT} PRIVATE "${INCLUDE_DIR}")

target_compile_definitions(${PROJECT} PRIVATE SFML_STATIC)

if(UNIX AND NOT APPLE)
	cmake_policy(SET CMP0072 NEW)
	set(OpenGL_GL_PREFERENCE GLVND)
	find_package(OpenGL REQUIRED)
	target_link_libraries(${PROJECT} PRIVATE
		X11 Xrandr Xcursor Xinerama Xi Xxf86vm
		xkbcommon-x11 Xrender freetype harfbuzz
		ogg vorbisfile FLAC vorbis vorbisenc
		-Wl,--whole-archive "${LIB_SFML_SYSTEM}" -Wl,--no-whole-archive
		"${LIB_SFML_WINDOW}" "${LIB_SFML_GRAPHICS}" "${LIB_SFML_AUDIO}"
		udev pthread dl OpenGL::GL
	)
else()
	target_link_libraries(${PROJECT} PRIVATE
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/FLACd.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/freetyped.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/harfbuzzd.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/oggd.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/vorbisd.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/vorbisencd.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/vorbisfiled.lib>
		$<$<CONFIG:Debug>:${SFML_LIB_DIR}/win/Debug/sfml-main-d.lib>

		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/FLAC.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/freetype.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/harfbuzz.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/ogg.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/vorbis.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/vorbisenc.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/vorbisfile.lib>
		$<$<CONFIG:Release>:${SFML_LIB_DIR}/win/Release/sfml-main.lib>

		$<$<CONFIG:Debug>:${LIB_SFML_SYSTEM_DBG}>
		$<$<CONFIG:Debug>:${LIB_SFML_WINDOW_DBG}>
		$<$<CONFIG:Debug>:${LIB_SFML_GRAPHICS_DBG}>
		$<$<CONFIG:Debug>:${LIB_SFML_AUDIO_DBG}>

		$<$<CONFIG:Release>:${LIB_SFML_SYSTEM_REL}>
		$<$<CONFIG:Release>:${LIB_SFML_WINDOW_REL}>
		$<$<CONFIG:Release>:${LIB_SFML_GRAPHICS_REL}>
		$<$<CONFIG:Release>:${LIB_SFML_AUDIO_REL}>

		winmm ws2_32 opengl32 gdi32
	)
endif()
