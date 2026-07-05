#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/Graphics/StencilMode.hpp>

#include "../../headers/graphics/sf_stencil_mode.h"

#include "../../headers/graphics/sf_stencil_value.h"


sf_StencilMode sf_StencilMode_default() {
	sf::StencilMode* self = new sf::StencilMode();
	if (!self) {
		std::cerr << "Could not create sf_StencilMode in sf_StencilMode_default!\n";
		std::exit(EXIT_FAILURE);
	}
	self->stencilComparison      = sf::StencilComparison::Always;
	self->stencilUpdateOperation = sf::StencilUpdateOperation::Keep;
	self->stencilReference       = sf::StencilValue(0);
	self->stencilMask            = sf::StencilValue(~0u);
	self->stencilOnly            = false;
	return static_cast<sf_StencilMode>(self);
}

sf_StencilMode sf_StencilMode_from_int(
	int stencilOnly,
	int stencilComparison,
	int stencilUpdateOperation,
	int stencilReference,
	int stencilMask
) {
	sf::StencilMode* self = new sf::StencilMode();
	if (!self) {
		std::cerr << "Could not create sf_StencilMode in sf_StencilMode_from_int!\n";
		std::exit(EXIT_FAILURE);
	}
	self->stencilComparison      = static_cast<sf::StencilComparison>(stencilComparison);
	self->stencilUpdateOperation = static_cast<sf::StencilUpdateOperation>(stencilUpdateOperation);
	self->stencilReference       = sf::StencilValue(stencilReference);
	self->stencilMask            = sf::StencilValue(stencilMask);
	self->stencilOnly            = stencilOnly;
	return static_cast<sf_StencilMode>(self);
}

sf_StencilMode sf_StencilMode_init(
	int stencilOnly,
	int stencilComparison,
	int stencilUpdateOperation,
	sf_StencilValue stencilReference,
	sf_StencilValue stencilMask
) {
	sf::StencilMode* self = new sf::StencilMode();
	if (!self) {
		std::cerr << "Could not create sf_StencilMode in sf_StencilMode_init!\n";
		std::exit(EXIT_FAILURE);
	}
	self->stencilComparison      = static_cast<sf::StencilComparison>(stencilComparison);
	self->stencilUpdateOperation = static_cast<sf::StencilUpdateOperation>(stencilUpdateOperation);
	self->stencilReference       = sf::StencilValue(sf_StencilValue_get_value(stencilReference));
	self->stencilMask            = sf::StencilValue(sf_StencilValue_get_value(stencilMask));
	self->stencilOnly            = stencilOnly;
	return static_cast<sf_StencilMode>(self);
}

void* sf_StencilMode_del(sf_StencilMode obj) {
	sf::StencilMode* self = static_cast<sf::StencilMode*>(obj);
	delete self;
	return NULL;
}

int sf_StencilMode_get_stencil_only(sf_StencilMode self) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	return s->stencilOnly;
}

int sf_StencilMode_get_stencil_comparison(sf_StencilMode self) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	return static_cast<int>(s->stencilComparison);
}

int sf_StencilMode_get_stencil_update_operation(sf_StencilMode self) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	return static_cast<int>(s->stencilUpdateOperation);
}

sf_StencilValue sf_StencilMode_get_stencil_reference(sf_StencilMode self) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	sf::StencilValue* res = new sf::StencilValue(s->stencilReference.value);
	return static_cast<sf_StencilValue>(res);
}

sf_StencilValue sf_StencilMode_get_stencil_mask(sf_StencilMode self) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	sf::StencilValue* res = new sf::StencilValue(s->stencilMask.value);
	return static_cast<sf_StencilValue>(res);
}

int sf_StencilMode_is_equal(sf_StencilMode self, const sf_StencilMode other) {
	sf::StencilMode* s = static_cast<sf::StencilMode*>(self);
	const sf::StencilMode* o = static_cast<const sf::StencilMode*>(other);
	return *s == *o;
}

int sf_StencilMode_is_ne(sf_StencilMode self, const sf_StencilMode other) {
	return !sf_StencilMode_is_equal(self, other);
}
