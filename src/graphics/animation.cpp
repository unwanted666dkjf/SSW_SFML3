#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics/Texture.hpp>

#include <SFML/Graphics/Sprite.hpp>

#include "../../headers/system/sf_vector2f.h"

#include "../../headers/graphics/sf_sprite.h"

#include "../../headers/graphics/useful_funcs.h"

#include "../../headers/graphics/sf_float_rect.h"

#include "../../headers/graphics/animation.h"


static sf::Sprite* ssw_Animation_cur_sprite(ssw_Animation* self);


struct ssw_Animation {
	float last_ind;
	float animation_speed;
	unsigned long size;
	unsigned long length;
	unsigned long cur_ind;
	sf::Sprite** sprites;
};

ssw_Animation* ssw_Animation_init(unsigned long size, float animation_speed) {
	ssw_Animation* self = new ssw_Animation();
	if (!self) {
		std::cerr << "Could not create ssw_Animation in ssw_Animation_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->animation_speed = animation_speed;
	if (self->animation_speed < 0) {
		self->animation_speed *= -1;
	}
	self->size            = size;
	if (self->size < 1) {
		self->size = 1;
	}
	self->sprites = static_cast<sf::Sprite**>(
		std::malloc(sizeof(sf::Sprite*) * self->size)
	);
	if (!self->sprites) {
		std::cerr << "Could not create array of sf::Sprite* in ssw_Animation_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->cur_ind  = 0;
	self->length   = 0;
	self->last_ind = 0.f;
	return self;
}

void* ssw_Animation_del(ssw_Animation* obj) {
	for (unsigned long i = 0; i < obj->length; i++) {
		sf::Sprite* s = obj->sprites[i];
		delete s;
	}
	std::free(obj->sprites);
	delete obj;
	return NULL;
}

void ssw_Animation_draw(ssw_Animation* self,
	sf_RenderWindow wnd,
	const sf_RenderStates render_states
) {
	sf::Sprite* cur = ssw_Animation_cur_sprite(self);
	if (!cur) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_draw!\n";
		return;
	}
	sf::RenderWindow* w = static_cast<sf::RenderWindow*>(wnd);
	const sf::RenderStates* st = static_cast<const sf::RenderStates*>(render_states);
	w->draw(*cur, *st);
}

void ssw_Animation_move(ssw_Animation* self, float dx, float dy) {
	sf::Sprite* cur = ssw_Animation_cur_sprite(self);
	if (!cur) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_move!\n";
	} else {
		cur->move(sf::Vector2f(dx, dy));
	}
}

void ssw_Animation_flip(ssw_Animation* self, int flip_x, int flip_y, int global_coords) {
	for (unsigned long i = 0; i < self->length; i++) {
		sf::Sprite* sprite = self->sprites[i];
		ssw_flip_sprite(
			static_cast<sf_Sprite>(sprite),
			flip_x, flip_y,
			global_coords
		);
	}
}

void ssw_Animation_set_position(ssw_Animation* self, float left, float top) {
	sf::Sprite* cur = ssw_Animation_cur_sprite(self);
	if (!cur) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_set_position!\n";
	} else {
		cur->setPosition(sf::Vector2f(left, top));
	}
}

void ssw_Animation_resize(ssw_Animation* self,
	float width,  float height,
	int   keep_w, int keep_h
) {
	for (unsigned long i = 0; i < self->length; i++) {
		sf::Sprite* sprite = self->sprites[i];
		sf::Vector2f old_pos = sprite->getPosition();
		float old_height = sprite->getGlobalBounds().size.y;
		sf::Vector2u texture_size = sprite->getTexture().getSize();
		sf_Vector2f scale = ssw_get_new_scale(
			width, 	        height,
			texture_size.x, texture_size.y,
			keep_w,         keep_h
		);
		sprite->setScale(
			*(static_cast<sf::Vector2f*>(scale))
		);
		scale = sf_Vector2f_del(scale);
		sprite->setPosition(old_pos);
		float new_height = sprite->getGlobalBounds().size.y;
		float dy = old_height - new_height;
		sprite->move(sf::Vector2f(0, dy));
	}
}

void ssw_Animation_scale(ssw_Animation* self,
	float kx,     float ky,
	int   keep_w, int keep_h
) {
	for (unsigned long i = 0; i < self->length; i++) {
		sf::Sprite* sprite = self->sprites[i];
		sf::Vector2f old_pos = sprite->getPosition();
		sf::FloatRect old_bounds = sprite->getGlobalBounds();
		float old_height = old_bounds.size.y;
		float width = old_bounds.size.x * kx;
		float height = old_bounds.size.y * ky;
		sf::Vector2u texture_size = sprite->getTexture().getSize();
		sf_Vector2f scale = ssw_get_new_scale(
			width, 	        height,
			texture_size.x, texture_size.y,
			keep_w,         keep_h
		);
		sprite->setScale(
			*(static_cast<sf::Vector2f*>(scale))
		);
		scale = sf_Vector2f_del(scale);
		sprite->setPosition(old_pos);
		float new_height = sprite->getGlobalBounds().size.y;
		float dy = old_height - new_height;
		sprite->move(sf::Vector2f(0, dy));
	}
}

static unsigned long ssw_Animation_next_ind(ssw_Animation* self) {
	unsigned long ind = static_cast<unsigned long>(self->last_ind);
	self->last_ind += self->animation_speed;
	if (ind >= self->length) {
		ind = 0;
		self->last_ind = 0.f;
	}
	return ind;
}

unsigned long ssw_Animation_update(ssw_Animation* self) {
	unsigned long ind = ssw_Animation_next_ind(self);
	if (self->cur_ind == ind) {
		return self->cur_ind;
	}
	sf::Sprite* last = ssw_Animation_cur_sprite(self);
	if (!last) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_update!\n";
		return self->cur_ind;
	}
	sf::Vector2f old_pos = last->getPosition();
	sf::FloatRect old_bounds = last->getGlobalBounds();
	self->cur_ind = ind;
	sf::Sprite* cur = ssw_Animation_cur_sprite(self);
	if (!cur) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_update!\n";
		return self->cur_ind;
	}
	sf::FloatRect cur_bounds = cur->getGlobalBounds();
	cur->setPosition(old_pos);
	float dy = old_bounds.size.y - cur_bounds.size.y;
	cur->move(sf::Vector2f(0, dy));
	return self->cur_ind;
}

int ssw_Animation_add_item(ssw_Animation* self,
	const sf_Texture texture,
	float width,  float height,
	int   keep_w, int keep_h
) {
	if (self->length >= self->size) {
		return 0;
	}
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	sf::Sprite* item = new sf::Sprite(*t);
	if (!item) {
		std::cerr << "Could not create new sf::Sprite* in ssw_Animation_add_item!\n";
		return 0;
	}
	sf::Vector2u texture_size = t->getSize();
	sf_Vector2f scale = ssw_get_new_scale(
		width,          height,
		texture_size.x, texture_size.y,
		keep_w,         keep_h
	);
	item->setScale(
		*(static_cast<sf::Vector2f*>(scale))
	);
	scale = sf_Vector2f_del(scale);
	self->sprites[self->length] = item;
	self->length++;
	return 1;
}

sf_Sprite ssw_Animation_get_current(ssw_Animation* self) {
	return static_cast<sf_Sprite>(ssw_Animation_cur_sprite(self));
}

sf_Sprite ssw_Animation_get_sprite(ssw_Animation* self, unsigned long ind) {
	if (ind >= self->length || self->length < 1) {
		return NULL;
	}
	return static_cast<sf_Sprite>(self->sprites[ind]);
}

unsigned long ssw_Animation_get_length(ssw_Animation* self) {
	return self->length;
}

unsigned long ssw_Animation_get_size(ssw_Animation* self) {
	return self->size;
}

long ssw_Animation_get_cur_ind(ssw_Animation* self) {
	if (self->length < 1) {
		return SFML_SIMPLE_WRAPPER_ssw_Animation_SpriteNotFound;
	}
	return self->cur_ind;
}

sf_FloatRect ssw_Animation_cur_global_bounds(ssw_Animation* self) {
	sf::Sprite* sprite = ssw_Animation_cur_sprite(self);
	if (!sprite) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_cur_global_bounds!\n";
		return sf_FloatRect_default();
	}
	return sf_Sprite_get_global_bounds(static_cast<sf_Sprite>(sprite));
}

sf_FloatRect ssw_Animation_cur_local_bounds(ssw_Animation* self) {
	sf::Sprite* sprite = ssw_Animation_cur_sprite(self);
	if (!sprite) {
		std::cerr << "Attempting to use NULL sf::Sprite* in ssw_Animation_cur_local_bounds!\n";
		return sf_FloatRect_default();
	}
	return sf_Sprite_get_local_bounds(static_cast<sf_Sprite>(sprite));
}

int ssw_Animation_get_is_end(ssw_Animation* self) {
	if (self->length < 1) {
		return 0;
	}
	return (long)(self->cur_ind) == ((long)self->length - 1);
}

int ssw_Animation_get_is_start(ssw_Animation* self) {
	if (self->length < 1) {
		return 0;
	}
	return self->cur_ind == 0;
}

int ssw_Animation_get_is_running(ssw_Animation* self) {
	if (self->length < 1) {
		return 0;
	}
	return self->cur_ind < self->length;
}

int ssw_Animation_get_is_empty(ssw_Animation* self) {
	return self->length == 0;
}

int ssw_Animation_get_is_full(ssw_Animation* self) {
	return self->length >= self->size;
}


sf::Sprite* ssw_Animation_cur_sprite(ssw_Animation* self) {
	if (self->length < 1) {
		return NULL;
	}
	return self->sprites[self->cur_ind];
}
