#ifndef SFML_SIMPLE_WRAPPER_WINDOW_SF_CLIPBOARD_H
#define SFML_SIMPLE_WRAPPER_WINDOW_SF_CLIPBOARD_H


#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * This function returns the content of the clipboard
 *as a string. If the clipboard does not c*ontain string
 *it returns an empty `sf::String` object.
 */
SFML_SIMPLE_WRAPPER_API sf_String sf_Clipboard_get_string();

/**
 * This function sets the content of the clipboard as a string.
 *
 * Due to limitations on some operating systems,
 *setting the clipboard contents is only
 *guaranteed to work if there is currently an
 *open window for which events are being handled.
 */
SFML_SIMPLE_WRAPPER_API void sf_Clipboard_set_string(const sf_String text);


#ifdef __cplusplus
}
#endif


#endif
