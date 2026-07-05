#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_TYPES_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_TYPES_H


#include "../import_macro.h"


#ifdef __cplusplus
extern "C" {
#endif


struct SFML_SIMPLE_WRAPPER_API sf_Font_Info;

struct SFML_SIMPLE_WRAPPER_API ssw_Animation;


/**
 * Alternative type for sf::Font::Info.
 * Holds various information about a font.
 */
typedef struct sf_Font_Info sf_Font_Info;


/**
 * Structure that stores sf::Sprite pointers
 *and plays animation from them.
 * Animation is framerate-dependent.
 */
typedef struct ssw_Animation ssw_Animation;


/**
 * Opaque type for sf::RenderWindow.
 * Window that can serve as a target for 2D drawing.
 */
typedef void* sf_RenderWindow;

/**
 * Opaque type for sf::Image.
 * Class for loading, manipulating and saving images.
 */
typedef void* sf_Image;

/**
 * Opaque type for sf::Color.
 * Utility class for manipulating RGBA colors.
 */
typedef void* sf_Color;

/**
 * Opaque type for sf::StencilValue.
 * Stencil value type (also used as a mask).
 */
typedef void* sf_StencilValue;

/**
 * Opaque type for sf::StencilMode.
 * Stencil modes for drawing.
 */
typedef void* sf_StencilMode;


/**
 * Opaque type for sf::FloatRect.
 * Utility class for manipulating 2D axis aligned rectangles.
 */
typedef void* sf_FloatRect;


/**
 * Opaque type for sf::IntRect.
 * Utility class for manipulating 2D axis aligned rectangles.
 */
typedef void* sf_IntRect;


/**
 * Opaque type for sf::View.
 * 2D camera that defines what region is shown on screen.
 */
typedef void* sf_View;


/**
 * Opaque type for sf::Transform.
 * 3x3 transform matrix.
 */
typedef void* sf_Transform;


/**
 * Opaque type for sf::BlendMode.
 * Blending mode for drawing.
 */
typedef void* sf_BlendMode;


/**
 * Opaque type for sf::Texture.
 * Image living on the graphics card that can be used for drawing.
 */
typedef void* sf_Texture;


/**
 * Opaque type for sf::Shader.
 * Shader class (vertex, geometry and fragment).
 */
typedef void* sf_Shader;


/**
 * Opaque type for sf::RenderStates.
 * Define the states used for drawing to a `RenderTarget`
 */
typedef void* sf_RenderStates;


/**
 * Opaque type for sf::RectangleShape.
 * Specialized shape representing a rectangle.
 */
typedef void* sf_RectangleShape;


/**
 * Opaque type for sf::CircleShape.
 * Specialized shape representing a circle.
 */
typedef void* sf_CircleShape;


/**
 * Opaque type for sf::Text.
 * Graphical text that can be drawn to a render target.
 */
typedef void* sf_Text;


/**
 * Opaque type for sf::Sprite.
 * Drawable representation of a texture, with its
 *own transformations, color, etc.
 */
typedef void* sf_Sprite;


/**
 * Opaque type for sf::Glyph.
 * Structure describing a glyph.
 */
typedef void* sf_Glyph;


/**
 * Opaque type for sf::Font.
 * Class for loading and manipulating character fonts.
 */
typedef void* sf_Font;


#ifdef __cplusplus
}
#endif


#endif
