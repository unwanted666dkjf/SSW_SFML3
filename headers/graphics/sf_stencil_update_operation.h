#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_UPDATE_OPERATION_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_UPDATE_OPERATION_H


#ifdef __cplusplus
extern "C" {
#endif


// If the stencil test passes, the value in the stencil buffer is not modified
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Keep 0

// If the stencil test passes, the value in the stencil buffer is set to zero
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Zero 1

// If the stencil test passes, the value in the stencil buffer is set to the new value
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Replace 2

// If the stencil test passes, the value in the stencil buffer is incremented and if required clamped
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Increment 3

// If the stencil test passes, the value in the stencil buffer is decremented and if required clamped
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Decrement 4

// If the stencil test passes, the value in the stencil buffer is bitwise inverted
#define SFML_SIMPLE_WRAPPER_sf_StencilUpdateOperation_Invert 5


#ifdef __cplusplus
}
#endif


#endif
