#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXT_LINE_ALIGNMENT_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_TEXT_LINE_ALIGNMENT_H


#ifdef __cplusplus
extern "C" {
#endif


// Automatically align lines by script direction, left-align left-to-right text and right-align right-to-left text
#define SFML_SIMPLE_WRAPPER_sf_Text_LineAlignment_Default 0

// Force align all lines to the left, regardless of script direction
#define SFML_SIMPLE_WRAPPER_sf_Text_LineAlignment_Left 1

// Force align all lines centrally
#define SFML_SIMPLE_WRAPPER_sf_Text_LineAlignment_Center 2

// Force align lines to the right, regardless of script direction
#define SFML_SIMPLE_WRAPPER_sf_Text_LineAlignment_Right 3


#ifdef __cplusplus
}
#endif


#endif
