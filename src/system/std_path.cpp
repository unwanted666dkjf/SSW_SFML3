#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <string>

#include <stdexcept>

#include <filesystem>

#include <SFML/System/String.hpp>

#include "../../headers/system/std_path.h"


namespace fs = std::filesystem;


static std::string wchar_to_utf8(const wchar_t* s);

// static std::u32string wchar_to_utf32(const wchar_t* s);

// static std::wstring wchar_to_utf16_string(const wchar_t* s);


std_Path std_Path_current_path() {
	fs::path c = fs::current_path();
	fs::path* res = new fs::path(c);
	return static_cast<std_Path>(res);
}

std_Path std_Path_from_char_str(const char* s) {
	fs::path* self = new fs::path(s);
	if (!self) {
		std::cerr << "Could not create std_Path in std_Path_from_char_str!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<std_Path>(self);
}

std_Path std_Path_from_wchar_str(const wchar_t* s) {
	fs::path* self;
	#ifdef _WIN32
		self = new fs::path(s);
	#else
		self = new fs::path(wchar_to_utf8(s));
	#endif
	if (!self) {
		std::cerr << "Could not create std_Path in std_Path_from_wchar_str!\n";
		std::exit(EXIT_FAILURE);
	}
	return static_cast<std_Path>(self);
}

void* std_Path_del(std_Path obj) {
	fs::path* self = static_cast<fs::path*>(obj);
	delete self;
	return NULL;
}

sf_String std_Path_sf_str(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	sf::String* res = new sf::String(s->wstring().c_str());
	return static_cast<sf_String>(res);
}

std_Path std_Path_relative_path(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path rel = s->relative_path();
	fs::path* res = new fs::path(rel);
	return static_cast<std_Path>(res);
}

std_Path std_Path_parent_path(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path parent_path = s->parent_path();
	fs::path* res = new fs::path(parent_path);
	return static_cast<std_Path>(res);
}

std_Path std_Path_root_name(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path root_name = s->root_name();
	fs::path* res = new fs::path(root_name);
	return static_cast<std_Path>(res);
}

std_Path std_Path_root_path(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path root_path = s->root_path();
	fs::path* res = new fs::path(root_path);
	return static_cast<std_Path>(res);
}

std_Path std_Path_root_directory(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path root_directory = s->root_directory();
	fs::path* res = new fs::path(root_directory);
	return static_cast<std_Path>(res);
}

std_Path std_Path_filename(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path filename = s->filename();
	fs::path* res = new fs::path(filename);
	return static_cast<std_Path>(res);
}

std_Path std_Path_stem(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path stem = s->stem();
	fs::path* res = new fs::path(stem);
	return static_cast<std_Path>(res);
}

std_Path std_Path_extension(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path ext = s->extension();
	fs::path* res = new fs::path(ext);
	return static_cast<std_Path>(res);
}

std_Path std_Path_add(std_Path self, const char* s) {
	fs::path* se = static_cast<fs::path*>(self);
	fs::path p = (*se) / s;
	fs::path* res = new fs::path(p);
	return static_cast<std_Path>(res);
}

std_Path std_Path_add_path(std_Path self, std_Path other) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path* o = static_cast<fs::path*>(other);
	fs::path p = (*s) / (*o);
	fs::path* res = new fs::path(p);
	return static_cast<std_Path>(res);
}

void std_Path_clear(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	s->clear();
}

void std_Path_remove_filename(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	s->remove_filename();
}

void std_Path_replace_filename(std_Path self, const std_Path replacement) {
	fs::path* s = static_cast<fs::path*>(self);
	const fs::path* r = static_cast<const fs::path*>(replacement);
	s->replace_filename(*r);
}

void std_Path_replace_extension(std_Path self, const std_Path replacement) {
	fs::path* s = static_cast<fs::path*>(self);
	const fs::path* r = static_cast<const fs::path*>(replacement);
	s->replace_extension(*r);
}

int std_Path_is_empty(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->empty();
}

int std_Path_has_root_path(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_root_path();
}

int std_Path_has_root_name(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_root_name();
}

int std_Path_has_root_directory(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_root_directory();
}

int std_Path_has_relative_path(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_relative_path();
}

int std_Path_has_filename(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_filename();
}

int std_Path_has_stem(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_stem();
}

int std_Path_has_extension(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->has_extension();
}

int std_Path_is_absolute(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return s->is_absolute();
}

int std_Path_is_relative(std_Path self) {
	return !std_Path_is_absolute(self);
}

int std_Path_exists(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return fs::exists(*s);
}

int std_Path_is_directory(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return fs::is_directory(*s);
}

int std_Path_is_regular_file(std_Path self) {
	fs::path* s = static_cast<fs::path*>(self);
	return fs::is_regular_file(*s);
}

int std_Path_is_equal(std_Path self, std_Path other) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path* o = static_cast<fs::path*>(other);
	return *s == *o;
}

int std_Path_is_ne(std_Path self, std_Path other) {
	return !std_Path_is_equal(self, other);
}

int std_Path_is_equivalent(std_Path self, std_Path other) {
	fs::path* s = static_cast<fs::path*>(self);
	fs::path* o = static_cast<fs::path*>(other);
	if (!(fs::exists(*s) && fs::exists(*o))) {
		return 0;
	}
	return fs::equivalent(*s, *o);
}


std::string wchar_to_utf8(const wchar_t* s) {
	if (!s) throw std::invalid_argument("null wchar_t*");

	std::string out;
	for (const wchar_t* p = s; *p; ++p) {
		uint32_t cp = static_cast<uint32_t>(*p);

		if (cp >= 0xD800 && cp <= 0xDFFF)
			throw std::runtime_error("invalid surrogate in wchar_t");

		if (cp <= 0x7F) {
			out.push_back(static_cast<char>(cp));
		} else if (cp <= 0x7FF) {
			out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
			out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
		} else if (cp <= 0xFFFF) {
			out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
			out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
			out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
		} else if (cp <= 0x10FFFF) {
			out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
			out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
			out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
			out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
		} else {
			throw std::runtime_error("code point out of range");
		}
	}
	return out;
}


/**
std::u32string wchar_to_utf32(const wchar_t* s) {
    if (!s) throw std::invalid_argument("null wchar_t*");

    std::u32string out;
    for (const wchar_t* p = s; *p; ++p) {
        uint32_t cp = static_cast<uint32_t>(*p);

        if (cp >= 0xD800 && cp <= 0xDFFF)
            throw std::runtime_error("invalid surrogate in wchar_t");

        if (cp > 0x10FFFF)
            throw std::runtime_error("code point out of range");

        out.push_back(static_cast<char32_t>(cp));
    }
    return out;
}
*/

/**
std::wstring wchar_to_utf16_string(const wchar_t* s) {
    if (!s) throw std::invalid_argument("null wchar_t*");

    std::wstring out;
    for (const wchar_t* p = s; *p; ++p) {
        uint32_t cp = static_cast<uint32_t>(*p);

        if (cp >= 0xD800 && cp <= 0xDFFF)
            throw std::runtime_error("invalid surrogate in wchar_t");

        if (cp <= 0xFFFF) {
            out.push_back(static_cast<wchar_t>(cp));
        } else if (cp <= 0x10FFFF) {
            cp -= 0x10000;
            wchar_t high = static_cast<wchar_t>(0xD800 + (cp >> 10));
            wchar_t low  = static_cast<wchar_t>(0xDC00 + (cp & 0x3FF));
            out.push_back(high);
            out.push_back(low);
        } else {
            throw std::runtime_error("code point out of range");
        }
    }
    return out;
}
*/

/**
#ifdef _WIN32

	#include <windows.h>

	
	static std::wstring ansi_to_wstring(const char* s) {
    	if (!s) return {};

    	int len = lstrlenA(s);
    	if (len == 0) return {};

    	int wlen = MultiByteToWideChar(CP_ACP, 0, s, len, nullptr, 0);
    	std::wstring out(wlen, L'\0');

    	MultiByteToWideChar(CP_ACP, 0, s, len, out.data(), wlen);
    	return out;
	}

#endif
*/
