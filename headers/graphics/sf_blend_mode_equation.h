#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_EQUATION_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_BLEND_MODE_EQUATION_H


#ifdef __cplusplus
extern "C" {
#endif


// Pixel = Src * SrcFactor + Dst * DstFactor
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Equation_Add 0

// Pixel = Src * SrcFactor - Dst * DstFactor
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Equation_Subtract 1

// Pixel = Dst * DstFactor - Src * SrcFactor
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Equation_ReverseSubtract 2

// Pixel = min(Dst, Src)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Equation_Min 3

// Pixel = max(Dst, Src)
#define SFML_SIMPLE_WRAPPER_sf_BlendMode_Equation_Max 4


#ifdef __cplusplus
}
#endif


#endif
