#include <cmath>

#include <SFML/System/Angle.hpp>

#include <SFML/Graphics/Rect.hpp>

#include <SFML/Graphics/Color.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/useful_funcs.h"

#include "../../headers/graphics/sf_render_window.h"


#ifdef _WIN32


	#include <windows.h>


	#define WIN32_LEAN_AND_MEAN

	#ifndef GWL_EXSTYLE
		#define GWL_EXSTYLE (-20)
	#endif
	
	#ifndef SWP_NOSIZE
		#define SWP_NOSIZE (0x0001)
	#endif

	#ifndef SWP_NOMOVE
		#define SWP_NOMOVE (0x0002)
	#endif

	#ifndef SWP_SHOWWINDOW
		#define SWP_SHOWWINDOW (0x0040)
	#endif


	int ssw_set_wnd_topmost(sf_RenderWindow wnd) {
		sf_WindowHandle hwnd = sf_RenderWindow_get_native_handle(wnd);
		if (IsIconic(hwnd)) {
			ShowWindow(hwnd, SW_RESTORE);
		}
		if (!SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW)) {
			return 0;
		}
		if (SetForegroundWindow(hwnd)) {
			return 1;
		}
		return 0;
	}

	int ssw_set_wnd_alpha(sf_RenderWindow wnd, unsigned char alpha) {
		sf_WindowHandle hwnd = sf_RenderWindow_get_native_handle(wnd);
		LONG_PTR ex = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
		SetWindowLongPtr(hwnd, GWL_EXSTYLE, ex | WS_EX_LAYERED);
		return SetLayeredWindowAttributes(hwnd, 0, alpha, LWA_ALPHA);
	}

	int ssw_make_wnd_clr_transparent(sf_RenderWindow wnd, sf_Color clr) {
		sf::Color* rgba = static_cast<sf::Color*>(clr);
		sf_WindowHandle hwnd = sf_RenderWindow_get_native_handle(wnd);

		LONG_PTR ex = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
		SetWindowLongPtr(hwnd, GWL_EXSTYLE, ex | WS_EX_LAYERED);

		COLORREF colorkey = (COLORREF)(rgba->r) | ((COLORREF)(rgba->g) << 8) | ((COLORREF)(rgba->b) << 16);
		return SetLayeredWindowAttributes(hwnd, colorkey, 0, LWA_COLORKEY) != 0;
	}


#else


	int ssw_set_wnd_topmost(sf_RenderWindow wnd) {
		(void)wnd;
		return 0;
	}

	int ssw_set_wnd_alpha(sf_RenderWindow wnd, unsigned char alpha) {
		(void)wnd;
		(void)alpha;
		return 0;
	}

	int ssw_make_wnd_clr_transparent(sf_RenderWindow wnd, sf_Color clr) {
		(void)clr;
		(void)wnd;
		return 0;
	}


#endif


int ssw_is_frect_on_screen(sf_FloatRect rect, sf_RenderWindow wnd) {
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	sf::FloatRect* r = static_cast<sf::FloatRect*>(rect);
	sf::View wnd_view = w->getView();
	sf::Vector2f view_size = wnd_view.getSize();
	sf::Vector2f view_center = wnd_view.getCenter();
	sf::FloatRect view_rect = sf::FloatRect(
		sf::Vector2f(
			view_center.x - view_size.x / 2,
			view_center.y - view_size.y / 2
		),
		sf::Vector2f(view_size.x, view_size.y)
	);
	std::optional<sf::FloatRect> ins = view_rect.findIntersection(*r);
	return ins.has_value();
}

float ssw_radians_to_degrees(float radians) {
	return radians * 180 / SIMPLE_SFML_WRAPPER_PI;
}

float ssw_degrees_to_radians(float degrees) {
	return degrees * SIMPLE_SFML_WRAPPER_PI / 180;
}

sf_Vector2f ssw_get_offset_with_angle(float value, sf_Angle angle) {
	sf::Angle* a = static_cast<sf::Angle*>(angle);
	float radians = a->asRadians();
	return sf_Vector2f_init(
		value * static_cast<float>(std::cos(radians)),
		value * static_cast<float>(std::sin(radians))
	);
}

sf_Vector2f ssw_keep_frect_on_area(sf_FloatRect rect, sf_FloatRect rect_area) {
	sf::FloatRect* r = static_cast<sf::FloatRect*>(rect);
	sf::FloatRect* ar = static_cast<sf::FloatRect*>(rect_area);
	float left = r->position.x;
	float top = r->position.y;
	if (left < ar->position.x) {
		left = ar->position.x;
	}
	if ((left + r->size.x) > (ar->position.x + ar->size.x)) {
		left = ar->position.x + ar->size.x - r->size.x;
	}
	if (top < ar->position.y) {
		top = ar->position.y;
	}
	if ((top + r->size.y) > (ar->position.y + ar->size.y)) {
		top = ar->position.y + ar->size.y - r->size.y;
	}
	return sf_Vector2f_init(left, top);
}

void ssw_flip_sprite(sf_Sprite sprite, int flip_x, int flip_y, int global_coords) {
	if (!(flip_x || flip_y)) {
		return;
	}
	sf::Sprite* s = static_cast<sf::Sprite*>(sprite);
	sf::Vector2f current_scale = s->getScale();
	sf::FloatRect old_rect = (global_coords) ? s->getGlobalBounds() : s->getLocalBounds();
	float kx = current_scale.x, ky = current_scale.y;
	if (flip_x) {
		kx *= -1;
	}
	if (flip_y) {
		ky *= -1;
	}
	s->setScale(sf::Vector2f(kx, ky));
	sf::FloatRect new_rect = (global_coords) ? s->getGlobalBounds() : s->getLocalBounds();
	float dx = old_rect.position.x - new_rect.position.x;
	float dy = old_rect.position.y - new_rect.position.y;
	s->move(sf::Vector2f(dx, dy));
}

sf_Vector2f ssw_get_new_scale(
	float new_width, 	 float new_height,
	float current_width, float current_height,
	int   keep_width,	 int   keep_height
) {
	if (!((int)current_width && (int)current_height)) {
		return sf_Vector2f_init(1.f, 1.f);
	}
	if (keep_width && !keep_height) {
		float kwh = current_width / current_height;
		new_height = new_width / kwh;
	}
	if (keep_height && !keep_width) {
		float khw = current_height / current_width;
		new_width = new_height / khw;
	}
	return sf_Vector2f_init(
		new_width / current_width,
		new_height / current_height
	);
}
