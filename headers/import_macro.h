#ifndef SFML_SIMPLE_WRAPPER_IMPORT_MACRO_H
#define SFML_SIMPLE_WRAPPER_IMPORT_MACRO_H


#if defined(_WIN32) || defined(_WIN64)
	#ifdef SFML_SIMPLE_WRAPPER_EXPORTS
		#define SFML_SIMPLE_WRAPPER_API __declspec(dllexport)
	#else
		#define SFML_SIMPLE_WRAPPER_API
	#endif
#else
	#ifdef SFML_SIMPLE_WRAPPER_EXPORTS
		#define SFML_SIMPLE_WRAPPER_API __attribute__((visibility("default")))
	#else
		#define SFML_SIMPLE_WRAPPER_API
	#endif
#endif


#endif
