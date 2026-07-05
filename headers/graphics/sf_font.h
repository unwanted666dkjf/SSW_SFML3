#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FONT_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_FONT_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Construct an empty font that does not contain any glyphs.
 */
SFML_SIMPLE_WRAPPER_API sf_Font sf_Font_default();

/**
 * Construct the font from a file.
 * The supported font formats are: TrueType, Type 1, CFF,
 *OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
 * Note that this function knows nothing about the standard
 *fonts installed on the user's system, thus you can't
 *load them directly.
 *
 * warning: SFML cannot preload all the font data in this
 *function, so the file has to remain accessible until
 *the `sf::Font` object opens a new font or is destroyed.
 * Throws sf::Exception if opening was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Font sf_Font_init(const std_Path filepath);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Font_del(sf_Font obj);

/**
 * Open the font from a file.
 * The supported font formats are: TrueType, Type 1, CFF,
 *OpenType, SFNT, X11 PCF, Windows FNT, BDF, PFR and Type 42.
 * Note that this function knows nothing about the standard
 *fonts installed on the user's system, thus you can't
 *load them directly.
 *
 * warning: SFML cannot preload all the font data in this
 *function, so the file has to remain accessible until
 *the `sf::Font` object opens a new font or is destroyed.
 * Returns 1 if opening succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Font_open(sf_Font self, const std_Path filepath);

/**
 * Get the copy of font information.
 */
SFML_SIMPLE_WRAPPER_API sf_Font_Info* sf_Font_get_info(sf_Font self);

/**
 * Retrieve a copy of glyph of the font by glyph ID.
 * If the font is a bitmap font, not all character sizes
 *might be available. If the glyph is not available at the
 *requested size, an empty glyph is returned.
 *
 * This function is only useful for getting the glyphs
 *returned in the data from calling `shape`.
 *
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 *
 * \param id               ID of the glyph to get
 * \param characterSize    Reference character size
 * \param bold             Retrieve the bold version or the regular one?
 * \param outlineThickness Thickness of outline (when != 0 the glyph will not be filled)
 *
 * \return The glyph corresponding to `id` and `characterSize`
 */
SFML_SIMPLE_WRAPPER_API sf_Glyph sf_Font_get_glyph_by_id(sf_Font self,
	unsigned int id,
	unsigned int character_size,
	int retrieve_bold,
	float outline_thickness
);

/**
 * Retrieve a copy of glyph of the font.
 * If the font is a bitmap font, not all character sizes
 *might be available. If the glyph is not available at the
 *requested size, an empty glyph is returned.
 *
 * You may want to use `hasGlyph` to determine if the
 *glyph exists before requesting it. If the glyph does not
 *exist, a font specific default is returned.
 *
 * Be aware that using a negative value for the outline
 *thickness will cause distorted rendering.
 *
 * \param codePoint        Unicode code point of the character to get
 * \param characterSize    Reference character size
 * \param bold             Retrieve the bold version or the regular one?
 * \param outlineThickness Thickness of outline (when != 0 the glyph will not be filled)
 *
 * \return The glyph corresponding to `codePoint` and `characterSize`
 */
SFML_SIMPLE_WRAPPER_API sf_Glyph sf_Font_get_glyph(sf_Font self,
	unsigned int code_point,
	unsigned int character_size,
	int retrieve_bold,
	float outline_thickness
);

/**
 * Determine if this font has a glyph representing the requested code point
 * Most fonts only include a very limited selection of glyphs from
 *specific Unicode subsets, like Latin, Cyrillic, or Asian characters.
 *
 * While code points without representation will return a font specific
 *default character, it might be useful to verify whether specific
 *code points are included to determine whether a font is suited
 *to display text in a specific language.
 * Returns 1 if the codepoint has a glyph representation, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Font_has_glyph(sf_Font self, unsigned int code_point);

/**
 * Get the kerning offset of two glyphs
 * The kerning is an extra offset (negative) to apply between two
 *glyphs when rendering them, to make the pair look more "natural".
 * For example, the pair "AV" have a special kerning to make them
 *closer than other characters. Most of the glyphs pairs have a
 *kerning offset of zero, though.
 *
 * \param first         Unicode code point of the first character
 * \param second        Unicode code point of the second character
 * \param characterSize Reference character size
 * \param bold          Retrieve the bold version or the regular one?
 *
 * \return Kerning value for `first` and `second`, in pixels
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_kerning(sf_Font self,
	unsigned int first,
	unsigned int second,
	unsigned int character_size,
	int retrieve_bold
);

/**
 * Get the ascent.
 * The ascent is the largest distance between the baseline and
 *the top of all glyphs in the font.
 *
 * Be aware that there is no uniform definition of how the
 *ascent is calculated. It can vary from font to font.
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_ascent(sf_Font self, unsigned int character_size);

/**
 * Get the descent
 * The descent is the largest distance between the baseline and
 *the bottom of all glyphs in the font.
 *
 * Be aware that there is no uniform definition of how the
 *descent is calculated. It can vary from font to font.
 *
 * The descent shares the same coordinate system as the
 *ascent. This means that it will be negative for distances
 *below the baseline.
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_descent(sf_Font self, unsigned int character_size);

/**
 * Get the line spacing.
 * Line spacing is the vertical offset to apply between two
 *consecutive lines of text.
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_line_spacing(sf_Font self, unsigned int character_size);

/**
 * Get the position of the underline.
 * Underline position is the vertical offset to apply between the
 *baseline and the underline.
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_underline_position(sf_Font self, unsigned int character_size);

/**
 * Get the thickness of the underline.
 * Underline thickness is the vertical size of the underline.
 */
SFML_SIMPLE_WRAPPER_API float sf_Font_get_underline_thickness(sf_Font self, unsigned int character_size);

/**
 * Retrieve the copy of texture containing the loaded glyphs of a certain size.
 * The contents of the returned texture changes as more glyphs
 *are requested, thus it is not very relevant. It is mainly
 *used internally by `sf::Text`.
 */
SFML_SIMPLE_WRAPPER_API sf_Texture sf_Font_get_texture(sf_Font self, unsigned int character_size);

/**
 * Tell whether the smooth filter is enabled or not.
 * Returns 1 if smoothing is enabled, 0 if it is disabled.
 */
SFML_SIMPLE_WRAPPER_API int sf_Font_get_is_smooth(sf_Font self);

/**
 * Enable or disable the smooth filter.
 * When the filter is activated, the font appears smoother
 *so that pixels are less noticeable. However if you want
 *the font to look exactly the same as its source file,
 *you should disable it.
 * The smooth filter is enabled by default.
 */
SFML_SIMPLE_WRAPPER_API void sf_Font_set_is_smooth(sf_Font self, int is_smooth);


#ifdef __cplusplus
}
#endif


#endif
