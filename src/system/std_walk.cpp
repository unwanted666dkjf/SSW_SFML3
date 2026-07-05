#include <iostream>

#include <cstdlib>

#include <cstddef>

#include <filesystem>

#include "../../headers/system/std_path.h"

#include "../../headers/system/std_walk.h"


namespace fs = std::filesystem;


struct std_WalkGen {
	fs::directory_iterator* start;
	fs::directory_iterator* end;
};


struct std_WalkGenRecurse {
	fs::recursive_directory_iterator* start;
	fs::recursive_directory_iterator* end;
};


std_WalkGen* std_WalkGen_init(
	const std_Path start_dir,
	int follow_symlinks,
	int skip_permission_denied
) {
	std_WalkGen* self = new std_WalkGen();
	if (!self) {
		std::cerr << "Could not create std_WalkGen in std_WalkGen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	fs::directory_options opts = fs::directory_options::none;
	if (follow_symlinks) {
		opts |= fs::directory_options::follow_directory_symlink;
	}
	if (skip_permission_denied) {
		opts |= fs::directory_options::skip_permission_denied;
	}
	const fs::path* p = static_cast<const fs::path*>(start_dir);
	try {
		self->start = new fs::directory_iterator(*p, opts);
	} catch (const fs::filesystem_error&) {
		std::cerr << "Could not create std::filesystem::directory_iterator start in std_WalkGen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	try {
		self->end = new fs::directory_iterator();
	} catch (const fs::filesystem_error&) {
		std::cerr << "Could not create std::filesystem::directory_iterator end in std_WalkGen_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

void* std_WalkGen_del(std_WalkGen* obj) {
	delete obj->start;
	delete obj->end;
	delete obj;
	return NULL;
}

int std_WalkGen_has_next(std_WalkGen* self) {
	if (!self->start) {
		return 0;
	}
	return *(self->start) != *(self->end);
}

std_Path std_WalkGen_next(std_WalkGen* self) {
	auto const& entry = *(*self->start);
	std_Path res = static_cast<std_Path>(new fs::path(entry.path()));
	++(*self->start);
	return res;
}


std_WalkGenRecurse* std_WalkGenRecurse_init(
	const std_Path start_dir,
	int follow_symlinks,
	int skip_permission_denied
) {
	std_WalkGenRecurse* self = new std_WalkGenRecurse();
	if (!self) {
		std::cerr << "Could not create std_WalkGenRecurse in std_WalkGenRecurse_init!\n";
		std::exit(EXIT_FAILURE);
	}
	fs::directory_options opts = fs::directory_options::none;
	if (follow_symlinks) {
		opts |= fs::directory_options::follow_directory_symlink;
	}
	if (skip_permission_denied) {
		opts |= fs::directory_options::skip_permission_denied;
	}
	const fs::path* p = static_cast<const fs::path*>(start_dir);
	try {
		self->start = new fs::recursive_directory_iterator(*p, opts);
	} catch (const fs::filesystem_error&) {
		std::cerr << "Could not create std::filesystem::recursive_directory_iterator start in std_WalkGenRecurse_init!\n";
		std::exit(EXIT_FAILURE);
	}
	try {
		self->end = new fs::recursive_directory_iterator();
	} catch (const fs::filesystem_error&) {
		std::cerr << "Could not create std::filesystem::recursive_directory_iterator end in std_WalkGenRecurse_init!\n";
		std::exit(EXIT_FAILURE);
	}
	return self;
}

void* std_WalkGenRecurse_del(std_WalkGenRecurse* obj) {
	delete obj->end;
	delete obj->start;
	delete obj;
	return NULL;
}

int std_WalkGenRecurse_has_next(std_WalkGenRecurse* self) {
	if (!self->start) {
		return 0;
	}
	return *(self->start) != *(self->end);
}

std_Path std_WalkGenRecurse_next(std_WalkGenRecurse* self) {
	auto const& entry = *(*self->start);
	std_Path res = static_cast<std_Path>(new fs::path(entry.path()));
	++(*self->start);
	return res;
}
