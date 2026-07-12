#include <stdio.h>

#include <stdlib.h>

#include "headers/system/sf_clock.h"

#include "headers/system/sf_time.h"

#include "headers/system/sf_string.h"

#include "headers/system/sf_vector2u.h"

#include "headers/system/sf_vector2f.h"

#include "headers/system/std_path.h"

#include "headers/system/sf_string.h"

#include "headers/window/sf_keys.h"

#include "headers/window/sf_event.h"

#include "headers/window/sf_event_gen.h"

#include "headers/window/sf_event_types.h"

#include "headers/window/sf_event_key_pressed.h"

#include "headers/window/sf_event_mouse_button_pressed.h"

#include "headers/window/sf_keyboard.h"

#include "headers/window/sf_video_mode.h"

#include "headers/window/sf_video_modes_gen.h"

#include "headers/window/sf_mouse_button.h"

#include "headers/window/sf_window_constants.h"

#include "headers/window/sf_context_settings.h"

#include "headers/graphics/sf_view.h"

#include "headers/graphics/sf_image.h"

#include "headers/graphics/sf_color.h"

#include "headers/graphics/sf_sprite.h"

#include "headers/graphics/sf_texture.h"

#include "headers/graphics/animation.h"

#include "headers/graphics/useful_funcs.h"

#include "headers/graphics/sf_render_states.h"

#include "headers/graphics/sf_render_window.h"

#include "headers/audio/sf_music.h"

#include "headers/audio/sf_sound.h"

#include "headers/audio/sf_sound_buffer.h"


int main(void) {
	std_Path wnd_icon_path = std_Path_from_char_str("./virus.png");
	sf_Image wnd_icon = sf_Image_default();
	if (!sf_Image_load(wnd_icon, wnd_icon_path)) {
		printf("Could not load wnd_icon!\n");
	}
	wnd_icon_path = std_Path_del(wnd_icon_path);

	sf_VideoMode desktop_mode = sf_VideoMode_get_desktop_mode();
	unsigned int width = sf_VideoMode_width(desktop_mode);
//	unsigned int heigth = sf_VideoMode_height(desktop_mode);

	desktop_mode = sf_VideoMode_del(desktop_mode);

	unsigned int size = width / 30;
	unsigned int framerate_limit = 25;
	sf_VideoMode wnd_mode = sf_VideoMode_init(size * 13, size * 10, 32);
	sf_String wnd_title = sf_String_from_str("SIMPLE_SFML3_WRAPPER");
	sf_ContextSettings default_settings = sf_ContextSettings_get_default();
	sf_RenderWindow wnd = sf_RenderWindow_init_ex(
		wnd_mode,
		wnd_title,
		SFML_SIMPLE_WRAPPER_sf_Window_Style_Default,
		SFML_SIMPLE_WRAPPER_sf_Window_State_Windowed,
		default_settings
	);
	sf_RenderWindow_set_icon(wnd, wnd_icon);
	sf_RenderWindow_set_position(wnd, size * 10, size * 6);

	wnd_title = sf_String_del(wnd_title);
	wnd_mode = sf_VideoMode_del(wnd_mode);
	wnd_icon = sf_Image_del(wnd_icon);
	default_settings = sf_ContextSettings_del(default_settings);

	sf_Texture texture = sf_Texture_default();
	std_Path texture_path = std_Path_from_char_str("./free.png");
	if (!sf_Texture_load_from_file(texture, texture_path, 0)) {
		printf("Could not load texture!\n");
	}
	texture_path = std_Path_del(texture_path);

	sf_Sprite sprite = sf_Sprite_init(texture);
	sf_Vector2u texture_size = sf_Texture_get_size(texture);
	sf_Vector2f scale = ssw_get_new_scale(
		size, size * 3,
		sf_Vector2u_get_x(texture_size), sf_Vector2u_get_y(texture_size),
		0, 1
	);
	texture_size = sf_Vector2u_del(texture_size);
	sf_Sprite_set_scale(sprite, sf_Vector2f_get_x(scale), sf_Vector2f_get_y(scale));
	scale = sf_Vector2f_del(scale);
	sf_Sprite_set_position(sprite, size * 3, size * 4);

	std_Path texturep_thing0 = std_Path_from_char_str("./Thing/0.png");
	std_Path texturep_thing1 = std_Path_from_char_str("./Thing/1.png");
	std_Path texturep_thing2 = std_Path_from_char_str("./Thing/2.png");
	std_Path texturep_thing3 = std_Path_from_char_str("./Thing/3.png");
	std_Path texturep_thing4 = std_Path_from_char_str("./Thing/4.png");
	std_Path texturep_thing5 = std_Path_from_char_str("./Thing/5.png");

	float animation_speed = .15 * 25. / framerate_limit;
	float thing_width = size, thing_height = size * 4;
	int tkeep_w = 0, tkeep_h = 1;
	ssw_Animation* thing_anime = ssw_Animation_init(6, animation_speed);

	sf_Texture texture_thing0 = sf_Texture_init(texturep_thing0, 0);
	sf_Texture texture_thing1 = sf_Texture_init(texturep_thing1, 0);
	sf_Texture texture_thing2 = sf_Texture_init(texturep_thing2, 0);
	sf_Texture texture_thing3 = sf_Texture_init(texturep_thing3, 0);
	sf_Texture texture_thing4 = sf_Texture_init(texturep_thing4, 0);
	sf_Texture texture_thing5 = sf_Texture_init(texturep_thing5, 0);

	ssw_Animation_add_item(thing_anime, texture_thing0, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_add_item(thing_anime, texture_thing1, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_add_item(thing_anime, texture_thing2, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_add_item(thing_anime, texture_thing3, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_add_item(thing_anime, texture_thing4, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_add_item(thing_anime, texture_thing5, thing_width, thing_height, tkeep_w, tkeep_h);
	ssw_Animation_set_position(thing_anime, size * 6, size * 5);

	texturep_thing0 = std_Path_del(texturep_thing0);
	texturep_thing1 = std_Path_del(texturep_thing1);
	texturep_thing2 = std_Path_del(texturep_thing2);
	texturep_thing3 = std_Path_del(texturep_thing3);
	texturep_thing4 = std_Path_del(texturep_thing4);
	texturep_thing5 = std_Path_del(texturep_thing5);

	sf_RenderStates render_states = sf_RenderStates_default();

	sf_Music mus = sf_Music_default();
	std_Path mus_path = std_Path_from_char_str("./afterlife.ogg");
	if (!sf_Music_open(mus, mus_path)) {
		printf("Could not open music!\n");
	} else {
		sf_Music_set_volume(mus, 80);
		sf_Music_set_is_loop(mus, 1);
//		sf_Music_play(mus);
	}
	mus_path = std_Path_del(mus_path);

	std_Path snd_path = std_Path_from_char_str("./Crystall.ogg");
	sf_SoundBuffer snd_buf = sf_SoundBuffer_init(snd_path);
	snd_path = std_Path_del(snd_path);
	sf_Sound snd = sf_Sound_init(snd_buf);

	float rotation_speed = 90.f;

	sf_Clock clock = sf_Clock_init();
	unsigned int wnd_speed = size * 6;
	sf_Color bg_clr = sf_Color_from_rgb(120, 219, 226);
	sf_RenderWindow_set_framerate_limit(wnd, framerate_limit);
	sf_Clock_start(clock);
	while (sf_RenderWindow_is_open(wnd)) {

		sf_Time time = sf_Clock_restart(clock);
		float seconds = sf_Time_as_seconds(time);
		unsigned int offset = (unsigned int)(wnd_speed * seconds);
		time = sf_Time_del(time);

		sf_Event_Gen* evt_gen = sf_RenderWindow_poll_event(wnd);
		while (sf_Event_Gen_has_next(evt_gen)) {
			sf_Event* evt = sf_Event_Gen_next(evt_gen);
			int evt_type = sf_Event_get_type(evt);
			if (evt_type == SFML_SIMPLE_WRAPPER_sf_Event_Type_Closed) {
				sf_RenderWindow_close(wnd);
				sf_Event_cleanup(evt);
				evt = sf_Event_del(evt);
				break;
			} else if (evt_type == SFML_SIMPLE_WRAPPER_sf_Event_Type_KeyPressed) {
				sf_Event_KeyPressed* key_pressed = sf_Event_get_key_pressed_evt(evt);
				int key = sf_Event_KeyPressed_keycode(key_pressed);
				if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_W) {
					printf("pressed W.\n");
					sf_RenderWindow_move(wnd, 0, -offset);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_S) {
					printf("pressed S.\n");
					sf_RenderWindow_move(wnd, 0, offset);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_X) {
					ssw_flip_sprite(sprite, 1, 0, 1);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_Y) {
					ssw_flip_sprite(sprite, 0, 1, 1);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_Z) {
					sf_Sound_play(snd);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_R) {
					float rot = rotation_speed * seconds;
					ssw_rotate_sprite(sprite, rot, 1);
				} else if (key == SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_T) {
					ssw_set_rotation_sprite(sprite, 0, 1);
				}
			} else if (evt_type == SFML_SIMPLE_WRAPPER_sf_Event_Type_MouseButtonPressed) {
				sf_Event_MouseButtonPressed* mouse_pressed = sf_Event_get_mouse_button_pressed_evt(evt);
				int mouse_btn = sf_Event_MouseButtonPressed_button(mouse_pressed);
				if (mouse_btn == SFML_SIMPLE_WRAPPER_sf_Mouse_Button_Left) {
					printf("pressed left\n");
					sf_RenderWindow_move(wnd, -offset, 0);
				} else if (mouse_btn == SFML_SIMPLE_WRAPPER_sf_Mouse_Button_Right) {
					printf("pressed right\n");
					sf_RenderWindow_move(wnd, offset, 0);
				}
			}

			sf_Event_cleanup(evt);
			evt = sf_Event_del(evt);
		}

		evt_gen = sf_Event_Gen_del(evt_gen);

		sf_RenderWindow_clear(wnd, bg_clr);

		sf_Sprite_draw(sprite, wnd, render_states);
		ssw_Animation_draw(thing_anime, wnd, render_states);

		sf_RenderWindow_display(wnd);

		if (sf_Keyboard_is_key_pressed(SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_A)) {
			sf_RenderWindow_move(wnd, -offset, 0);
		} else {
			if (sf_Keyboard_is_key_pressed(SFML_SIMPLE_WRAPPER_sf_Keyboard_Key_D)) {
				sf_RenderWindow_move(wnd, offset, 0);
			}
		}

		ssw_Animation_update(thing_anime);
	}

	mus = sf_Music_del(mus);
	clock = sf_Clock_del(clock);
	bg_clr = sf_Color_del(bg_clr);
	wnd = sf_RenderWindow_del(wnd);
	sprite = sf_Sprite_del(sprite);
	snd = sf_Sound_del(snd);
	snd_buf = sf_SoundBuffer_del(snd_buf);
	texture = sf_Texture_del(texture);
	texture_thing0 = sf_Texture_del(texture_thing0);
	texture_thing1 = sf_Texture_del(texture_thing1);
	texture_thing2 = sf_Texture_del(texture_thing2);
	texture_thing3 = sf_Texture_del(texture_thing3);
	texture_thing4 = sf_Texture_del(texture_thing4);
	texture_thing5 = sf_Texture_del(texture_thing5);
	thing_anime = ssw_Animation_del(thing_anime);
	render_states = sf_RenderStates_del(render_states);
	printf("end!\n");
	return 0;
}


// cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
// cmake --build build --config Release
