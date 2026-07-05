#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_FACTOR_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_FACTOR_H


#ifdef __cplusplus
extern "C" {
#endif


// (0, 0, 0, 0)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_Zero 0

// (1, 1, 1, 1)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_One 1

// (src.r, src.g, src.b, src.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_SrcColor 2

// (1, 1, 1, 1) - (src.r, src.g, src.b, src.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_OneMinusSrcColor 3

// (dst.r, dst.g, dst.b, dst.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_DstColor 4

// (1, 1, 1, 1) - (dst.r, dst.g, dst.b, dst.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_OneMinusDstColor 5

// (src.a, src.a, src.a, src.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_SrcAlpha 6

// (1, 1, 1, 1) - (src.a, src.a, src.a, src.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_OneMinusSrcAlpha 7

// (dst.a, dst.a, dst.a, dst.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_DstAlpha 8

// (1, 1, 1, 1) - (dst.a, dst.a, dst.a, dst.a)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Factor_OneMinusDstAlpha 9


#ifdef __cplusplus
}
#endif


#endif
