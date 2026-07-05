#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/RenderStates.hpp>

#include "../../headers/graphics/sf_blend_mode.h"

#include "../../headers/graphics/sf_stencil_mode.h"

#include "../../headers/graphics/sf_render_states.h"


sf_RenderStates sf_RenderStates_default() {
	sf::RenderStates* self = new sf::RenderStates();
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_default!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_from_blend_mode(const sf_BlendMode mode) {
	const sf::BlendMode* m = static_cast<const sf::BlendMode*>(mode);
	sf::RenderStates* self = new sf::RenderStates(*m);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_from_blend_mode!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_from_stencil_mode(const sf_StencilMode mode) {
	const sf::StencilMode* m = static_cast<const sf::StencilMode*>(mode);
	sf::RenderStates* self = new sf::RenderStates(*m);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_from_stencil_mode!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_from_transform(const sf_Transform transform) {
	const sf::Transform* t = static_cast<const sf::Transform*>(transform);
	sf::RenderStates* self = new sf::RenderStates(*t);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_from_transform!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_from_texture(const sf_Texture texture) {
	const sf::Texture* t = static_cast<const sf::Texture*>(texture);
	sf::RenderStates* self = new sf::RenderStates(t);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_from_texture!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_from_shader(const sf_Shader shader) {
	const sf::Shader* s = static_cast<const sf::Shader*>(shader);
	sf::RenderStates* self = new sf::RenderStates(s);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_from_shader!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

sf_RenderStates sf_RenderStates_init(
	const sf_BlendMode blend_mode,
	const sf_StencilMode stencil_mode,
	const sf_Transform transform,
	int coordinate_type,
	const sf_Texture texture,
	const sf_Shader shader
) {
	const sf::BlendMode* bmode   = static_cast<const sf::BlendMode*>(blend_mode);
	const sf::StencilMode* smode = static_cast<const sf::StencilMode*>(stencil_mode);
	const sf::Transform* tform   = static_cast<const sf::Transform*>(transform);
	const sf::Texture* text      = static_cast<const sf::Texture*>(texture);
	const sf::Shader* sha        = static_cast<const sf::Shader*>(shader);
	sf::RenderStates* self = new sf::RenderStates(
		*bmode,
		*smode,
		*tform,
		static_cast<sf::CoordinateType>(coordinate_type),
		text,
		sha
	);
	if (!self) {
		std::cerr << "Could not create sf_RenderStates in sf_RenderStates_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_RenderStates>(self);
}

void* sf_RenderStates_del(sf_RenderStates obj) {
	sf::RenderStates* self = static_cast<sf::RenderStates*>(obj);
	delete self;
	return NULL;
}

sf_BlendMode sf_RenderStates_blend_mode(sf_RenderStates self) {
	sf::RenderStates* s = static_cast<sf::RenderStates*>(self);
	return sf_BlendMode_init(
		static_cast<int>(s->blendMode.colorSrcFactor),
		static_cast<int>(s->blendMode.colorDstFactor),
		static_cast<int>(s->blendMode.colorEquation),
		static_cast<int>(s->blendMode.alphaSrcFactor),
		static_cast<int>(s->blendMode.alphaDstFactor),
		static_cast<int>(s->blendMode.alphaEquation)
	);
}

sf_StencilMode sf_RenderStates_stencil_mode(sf_RenderStates self) {
	sf::RenderStates* s = static_cast<sf::RenderStates*>(self);
	return sf_StencilMode_from_int(
		static_cast<int>(s->stencilMode.stencilOnly),
		static_cast<int>(s->stencilMode.stencilComparison),
		static_cast<int>(s->stencilMode.stencilUpdateOperation),
		static_cast<int>(s->stencilMode.stencilReference.value),
		static_cast<int>(s->stencilMode.stencilMask.value)
	);
}

sf_Transform sf_RenderStates_transform(sf_RenderStates self) {
	sf::RenderStates* s = static_cast<sf::RenderStates*>(self);
	return static_cast<sf_Transform>(new sf::Transform(s->transform));
}

int sf_RenderStates_coordinate_type(sf_RenderStates self) {
	sf::RenderStates* s = static_cast<sf::RenderStates*>(self);
	return static_cast<int>(s->coordinateType);
}
