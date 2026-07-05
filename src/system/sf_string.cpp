#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <SFML/System/String.hpp>

#include "../../headers/system/sf_string.h"


struct ssw_CStrBuf {
	unsigned long length;
	char* str_;
};

struct ssw_WCStrBuf {
	unsigned long length;
	wchar_t* str_;
};


sf_String sf_String_from_char(char c) {
	sf::String* self = new sf::String(c);
	if (!self) {
		std::cerr << "Could not create sf_String in sf_String_from_char!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_String>(self);
}

sf_String sf_String_from_wchar(wchar_t c) {
	sf::String* self = new sf::String(c);
	if (!self) {
		std::cerr << "Could not create sf_String in sf_String_from_wchar!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_String>(self);
}

sf_String sf_String_from_str(const char* str_) {
	sf::String* self = new sf::String(str_);
	if (!self) {
		std::cerr << "Could not create sf_String in sf_String_from_str!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_String>(self);
}

sf_String sf_String_from_wstr(const wchar_t* str_) {
	sf::String* self = new sf::String(str_);
	if (!self) {
		std::cerr << "Could not create sf_String in sf_String_from_wstr!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<sf_String>(self);
}

void* sf_String_del(sf_String obj) {
	sf::String* self = static_cast<sf::String*>(obj);
	delete self;
	return NULL;
}

ssw_CStrBuf* sf_String_to_ansi(sf_String self) {
	sf::String* s = static_cast<sf::String*>(self);
	std::string ansi = s->toAnsiString();
	return ssw_CStrBuf_init(ansi.c_str(), static_cast<unsigned long>(ansi.size()));
}

ssw_WCStrBuf* sf_String_to_wide(sf_String self) {
	sf::String* s = static_cast<sf::String*>(self);
	std::wstring wide = s->toWideString();
	return ssw_WCStrBuf_init(wide.c_str(), static_cast<unsigned long>(wide.size()));
}

unsigned int sf_String_get(sf_String self, unsigned long index) {
	sf::String* s = static_cast<sf::String*>(self);
	unsigned int c = static_cast<unsigned int>((*s)[index]);
	return c;
}

void sf_String_clear(sf_String self) {
	sf::String* s = static_cast<sf::String*>(self);
	s->clear();
}

unsigned long sf_String_size(sf_String self) {
	sf::String* s = static_cast<sf::String*>(self);
	return static_cast<unsigned long>(s->getSize());
}

int sf_String_is_empty(sf_String self) {
	sf::String* s = static_cast<sf::String*>(self);
	return static_cast<int>(s->isEmpty());
}

void sf_String_erase(sf_String self,
	unsigned long position,
	unsigned long count
) {
	sf::String* s = static_cast<sf::String*>(self);
	s->erase(position, count);
}

void sf_String_insert(sf_String self,
	unsigned long position,
	const sf_String str_
) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* other = static_cast<const sf::String*>(str_);
	s->insert(position, *other);
}

long sf_String_find(sf_String self,
	const sf_String str_,
	unsigned long start
) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* other = static_cast<const sf::String*>(str_);
	unsigned long res = static_cast<unsigned long>(s->find(*other, start));
	if (res == sf::String::InvalidPos) {
		return SFML_SIMPLE_WRAPPER_sf_String_STR_NOT_FOUND;
	}
	return static_cast<long>(res);
}

void sf_String_replace(sf_String self,
	unsigned long position,
	unsigned long length,
	const sf_String replace_with
) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* other = static_cast<const sf::String*>(replace_with);
	s->replace(position, length, *other);
}

void sf_String_replace_substrings(sf_String self,
	const sf_String search_for,
	const sf_String replace_with
) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* search = static_cast<const sf::String*>(search_for);
	const sf::String* repl = static_cast<const sf::String*>(replace_with);
	s->replace(*search, *repl);
}

sf_String sf_String_substring(sf_String self,
	unsigned long position,
	unsigned long length
) {
	sf::String* s = static_cast<sf::String*>(self);
	sf::String sub = s->substring(position, length);
	sf::String* res = new sf::String(sub);
	return static_cast<sf_String>(res);
}

sf_String sf_String_concat(sf_String self, const sf_String other) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* o = static_cast<const sf::String*>(other);
	sf::String co = *s + *o;
	sf::String* res = new sf::String(co);
	return static_cast<sf_String>(res);
}

int sf_String_is_equal(sf_String self, const sf_String other) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* o = static_cast<const sf::String*>(other);
	return *s == *o;
}

int sf_String_is_greater(sf_String self, const sf_String other) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* o = static_cast<const sf::String*>(other);
	return *s > *o;
}

int sf_String_is_lesser(sf_String self, const sf_String other) {
	sf::String* s = static_cast<sf::String*>(self);
	const sf::String* o = static_cast<const sf::String*>(other);
	return *s < *o;
}

int sf_String_is_ne(sf_String self, const sf_String other) {
	return !sf_String_is_equal(self, other);
}

int sf_String_is_ge(sf_String self, const sf_String other) {
	return sf_String_is_equal(self, other) || sf_String_is_greater(self, other);
}

int sf_String_is_le(sf_String self, const sf_String other) {
	return sf_String_is_equal(self, other) || sf_String_is_lesser(self, other);
}


static ssw_CStrBuf* ssw_CStrBuf_get_empty(unsigned long length) {
	ssw_CStrBuf* self = static_cast<ssw_CStrBuf*>(
		std::malloc(sizeof(ssw_CStrBuf))
	);
	if (!self) {
		std::cerr << "Could not create ssw_CStrBuf in ssw_CStrBuf_get_empty!\n";
		std::exit(EXIT_FAILURE);
	}
	self->str_ = static_cast<char*>(
		std::malloc(sizeof(char) * (length + 1))
	);
	if (!self->str_) {
		std::cerr << "Could not create char* in ssw_CStrBuf_get_empty!\n";
		std::exit(EXIT_FAILURE);
	}
	self->str_[0] = '\0';
	return self;
}

ssw_CStrBuf* ssw_CStrBuf_cast_char_str(char* str_) {
	ssw_CStrBuf* self = static_cast<ssw_CStrBuf*>(
		std::malloc(sizeof(ssw_CStrBuf))
	);
	if (!self) {
		std::cerr << "Could not create ssw_CStrBuf in ssw_CStrBuf_cast_char_str!\n";
		std::exit(EXIT_FAILURE);
	}
	self->length = 0;
	for(; str_[self->length] != '\0'; self->length++);
	self->str_ = str_;
	return self;
}

ssw_CStrBuf* ssw_CStrBuf_init(const char* str_, unsigned long length) {
	ssw_CStrBuf* self = ssw_CStrBuf_get_empty(length);
	unsigned long i = 0;
	for (; str_[i] != '\0'; i++) {
		self->str_[i] = str_[i];
	}
	self->str_[i] = '\0';
	self->length = i;
	return self;
}

void* ssw_CStrBuf_del(ssw_CStrBuf* obj) {
	std::free(obj->str_);
	std::free(obj);
	return NULL;
}

const char* ssw_CStrBuf_str(ssw_CStrBuf* self) {
	return self->str_;
}

unsigned long ssw_CStrBuf_length(ssw_CStrBuf* self) {
	return self->length;
}


static ssw_WCStrBuf* ssw_WCStrBuf_get_empty(unsigned long length) {
	ssw_WCStrBuf* self = static_cast<ssw_WCStrBuf*>(
		std::malloc(sizeof(ssw_WCStrBuf))
	);
	if (!self) {
		std::cerr << "Could not create ssw_WCStrBuf in ssw_WCStrBuf_get_empty!\n";
		std::exit(EXIT_FAILURE);
	}
	self->str_ = static_cast<wchar_t*>(
		std::malloc(sizeof(wchar_t) * (length + 1))
	);
	if (!self->str_) {
		std::cerr << "Could not create wchar_t* in ssw_WCStrBuf_get_empty!\n";
		std::exit(EXIT_FAILURE);
	}
	self->str_[0] = L'\0';
	return self;
}

ssw_WCStrBuf* ssw_WCStrBuf_cast_wchar_str(wchar_t* str_) {
	ssw_WCStrBuf* self = static_cast<ssw_WCStrBuf*>(
		std::malloc(sizeof(ssw_WCStrBuf))
	);
	if (!self) {
		std::cerr << "Could not create ssw_WCStrBuf in ssw_WCStrBuf_cast_wchar_str!\n";
		std::exit(EXIT_FAILURE);
	}
	self->length = 0;
	for(; str_[self->length] != L'\0'; self->length++);
	self->str_ = str_;
	return self;
}

ssw_WCStrBuf* ssw_WCStrBuf_init(const wchar_t* str_, unsigned long length) {
	ssw_WCStrBuf* self = ssw_WCStrBuf_get_empty(length);
	unsigned long i = 0;
	for (; str_[i] != L'\0'; i++) {
		self->str_[i] = str_[i];
	}
	self->str_[i] = L'\0';
	self->length = i;
	return self;
}

void* ssw_WCStrBuf_del(ssw_WCStrBuf* obj) {
	std::free(obj->str_);
	std::free(obj);
	return NULL;
}

const wchar_t* ssw_WCStrBuf_str(ssw_WCStrBuf* self) {
	return self->str_;
}

unsigned long ssw_WCStrBuf_length(ssw_WCStrBuf* self) {
	return self->length;
}
