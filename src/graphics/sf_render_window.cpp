#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../../headers/system/sf_vector2u.h"

#include "../../headers/system/sf_vector2i.h"

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/window/sf_event_gen.h"

#include "../../headers/window/sf_context_settings.h"

#include "../../headers/graphics/sf_int_rect.h"

#include "../../headers/graphics/sf_render_window.h"


sf_RenderWindow sf_RenderWindow_default() {
	sf::RenderWindow* self = new sf::RenderWindow();
	if (!self) {
		std::cerr << "Could not create sf_RenderWindow in sf_RenderWindow_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderWindow>(self);
}

sf_RenderWindow sf_RenderWindow_init(
	sf_VideoMode mode,
	const sf_String title,
	int state
) {
	sf::VideoMode* m = static_cast<sf::VideoMode*>(mode);
	const sf::String* str = static_cast<const sf::String*>(title);
	sf::RenderWindow* self = new sf::RenderWindow(*m, *str, static_cast<sf::State>(state));
	if (!self) {
		std::cerr << "Could not create sf_RenderWindow in sf_RenderWindow_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderWindow>(self);
}

sf_RenderWindow sf_RenderWindow_init_ex(
	sf_VideoMode mode,
	const sf_String title,
	unsigned int style,
	int state,
	const sf_ContextSettings settings
) {
	sf::VideoMode* m = static_cast<sf::VideoMode*>(mode);
	const sf::String* str = static_cast<const sf::String*>(title);
	const sf::ContextSettings* sett = static_cast<const sf::ContextSettings*>(settings);
	sf::RenderWindow* self = new sf::RenderWindow(*m, *str, style, static_cast<sf::State>(state), *sett);
	if (!self) {
		std::cerr << "Could not create sf_RenderWindow in sf_RenderWindow_init_ex!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderWindow>(self);
}

void* sf_RenderWindow_del(sf_RenderWindow obj) {
	sf::RenderWindow* self = static_cast<sf::RenderWindow*>(obj);
	delete self;
	return NULL;
}

sf_Vector2u sf_RenderWindow_get_size(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Vector2u size = s->getSize();
	return sf_Vector2u_init(size.x, size.y);
}

void sf_RenderWindow_set_icon(sf_RenderWindow self, const sf_Image icon) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::Image* img = static_cast<const sf::Image*>(icon);
	s->setIcon(*img);
}

int sf_RenderWindow_is_Srgb(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	return s->isSrgb();
}

int sf_RenderWindow_set_active(sf_RenderWindow self, int is_active) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	return s->setActive(is_active);
}

void sf_RenderWindow_create(sf_RenderWindow self,
	sf_VideoMode mode,
	const sf_String title,
	int state
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::VideoMode* m = static_cast<sf::VideoMode*>(mode);
	const sf::String* str = static_cast<const sf::String*>(title);
	s->create(*m, *str, static_cast<sf::State>(state));
}

void sf_RenderWindow_create_ex(sf_RenderWindow self,
	sf_VideoMode mode,
	const sf_String title,
	unsigned int style,
	int state,
	const sf_ContextSettings settings
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::VideoMode* m = static_cast<sf::VideoMode*>(mode);
	const sf::String* str = static_cast<const sf::String*>(title);
	const sf::ContextSettings* sett = static_cast<const sf::ContextSettings*>(settings);
	s->create(*m, *str, style, static_cast<sf::State>(state), *sett);
}

void sf_RenderWindow_close(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->close();
}

sf_ContextSettings sf_RenderWindow_get_settings(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::ContextSettings settings = s->getSettings();
	return sf_ContextSettings_init(
		settings.sRgbCapable,
		settings.depthBits,
		settings.stencilBits,
		settings.antiAliasingLevel,
		settings.majorVersion,
		settings.minorVersion,
		settings.attributeFlags
	);
}

void sf_RenderWindow_set_vertical_sync_enabled(sf_RenderWindow self, int is_enabled) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setVerticalSyncEnabled(is_enabled);
}

void sf_RenderWindow_set_framerate_limit(sf_RenderWindow self, unsigned int limit) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setFramerateLimit(limit);
}

void sf_RenderWindow_display(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->display();
}

int sf_RenderWindow_is_open(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	return s->isOpen();
}

sf_Event_Gen* sf_RenderWindow_poll_event(sf_RenderWindow self) {
	return sf_Event_Gen_init(self);
}

sf_Vector2i sf_RenderWindow_get_position(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Vector2i pos = s->getPosition();
	return sf_Vector2i_init(pos.x, pos.y);
}

void sf_RenderWindow_set_position(sf_RenderWindow self, int x, int y) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setPosition(sf::Vector2i(x, y));
}

void sf_RenderWindow_move(sf_RenderWindow self, int dx, int dy) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Vector2i pos = s->getPosition();
	s->setPosition(sf::Vector2i(pos.x + dx, pos.y + dy));
}

void sf_RenderWindow_set_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setSize(sf::Vector2u(width, height));
}

void sf_RenderWindow_set_title(sf_RenderWindow self, const sf_String title) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::String* str = static_cast<const sf::String*>(title);
	s->setTitle(*str);
}

void sf_RenderWindow_set_visible(sf_RenderWindow self, int is_visible) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setVisible(is_visible);
}

void sf_RenderWindow_set_mouse_cursor_visible(sf_RenderWindow self, int is_visible) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMouseCursorVisible(is_visible);
}

void sf_RenderWindow_set_mouse_cursor_grabbed(sf_RenderWindow self, int is_grabbed) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMouseCursorGrabbed(is_grabbed);
}

void sf_RenderWindow_set_key_repeat_enabled(sf_RenderWindow self, int is_enabled) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setKeyRepeatEnabled(is_enabled);
}

void sf_RenderWindow_request_focus(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->requestFocus();
}

int sf_RenderWindow_has_focus(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	return s->hasFocus();
}

sf_WindowHandle sf_RenderWindow_get_native_handle(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	return s->getNativeHandle();
}

void sf_RenderWindow_set_minimum_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMinimumSize(sf::Vector2u(width, height));
}

void sf_RenderWindow_unset_minimum_size(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMinimumSize(std::nullopt);
}

void sf_RenderWindow_set_maximum_size(sf_RenderWindow self,
	unsigned int width,
	unsigned int height
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMaximumSize(sf::Vector2u(width, height));
}

void sf_RenderWindow_unset_maximum_size(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->setMaximumSize(std::nullopt);
}

void sf_RenderWindow_clear(sf_RenderWindow self, sf_Color color) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->clear(*clr);
}

void sf_RenderWindow_clear_stencil(sf_RenderWindow self, sf_StencilValue value) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::StencilValue* v = static_cast<sf::StencilValue*>(value);
	s->clearStencil(*v);
}

void sf_RenderWindow_clear_ex(sf_RenderWindow self,
	sf_Color color,
	sf_StencilValue value
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::StencilValue* v = static_cast<sf::StencilValue*>(value);
	sf::Color* clr = static_cast<sf::Color*>(color);
	s->clear(*clr, *v);
}

void sf_RenderWindow_set_view(sf_RenderWindow self, const sf_View view) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::View* v = static_cast<const sf::View*>(view);
	s->setView(*v);
}

sf_View sf_RenderWindow_get_view(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::View* res = new sf::View(s->getView());
	return static_cast<sf_View>(res);
}

sf_View sf_RenderWindow_get_default_view(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::View* res = new sf::View(s->getDefaultView());
	return static_cast<sf_View>(res);
}

sf_IntRect sf_RenderWindow_get_viewport(sf_RenderWindow self, const sf_View view) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::View* v = static_cast<const sf::View*>(view);
	sf::IntRect r = s->getViewport(*v);
	return sf_IntRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_IntRect sf_RenderWindow_get_scissor(sf_RenderWindow self, const sf_View view) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::View* v = static_cast<const sf::View*>(view);
	sf::IntRect r = s->getScissor(*v);
	return sf_IntRect_init(
		r.position.x, r.position.y,
		r.size.x, r.size.y
	);
}

sf_Vector2f sf_RenderWindow_map_pixel_to_coords(sf_RenderWindow self, int x, int y) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Vector2f v = s->mapPixelToCoords(sf::Vector2i(x, y));
	return sf_Vector2f_init(v.x, v.y);
}

sf_Vector2f sf_RenderWindow_map_pixel_to_coords_ex(sf_RenderWindow self,
	int x, int y,
	const sf_View view
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::View* v = static_cast<const sf::View*>(view);
	sf::Vector2f co = s->mapPixelToCoords(sf::Vector2i(x, y), *v);
	return sf_Vector2f_init(co.x, co.y);
}

sf_Vector2i sf_RenderWindow_map_coords_to_pixel(sf_RenderWindow self, float x, float y) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	sf::Vector2i v = s->mapCoordsToPixel(sf::Vector2f(x, y));
	return sf_Vector2i_init(v.x, v.y);
}

sf_Vector2i sf_RenderWindow_map_coords_to_pixel_ex(sf_RenderWindow self,
	float x, float y,
	const sf_View view
) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	const sf::View* v = static_cast<const sf::View*>(view);
	sf::Vector2i pi = s->mapCoordsToPixel(sf::Vector2f(x, y), *v);
	return sf_Vector2i_init(pi.x, pi.y);
}

void sf_RenderWindow_push_gl_states(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->pushGLStates();
}

void sf_RenderWindow_pop_gl_states(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->popGLStates();
}

void sf_RenderWindow_reset_gl_states(sf_RenderWindow self) {
	sf::RenderWindow* s = static_cast<sf::RenderWindow*>(self);
	s->resetGLStates();
}
