#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_COMPARISON_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_STENCIL_COMPARISON_H


#ifdef __cplusplus
extern "C" {
#endif


// The stencil test never passes
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_Never 0

// The stencil test passes if the new value is less than the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_Less 1

// The stencil test passes if the new value is less than or equal to the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_LessEqual 2

// The stencil test passes if the new value is greater than the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_Greater 3

// The stencil test passes if the new value is greater than or equal to the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_GreaterEqual 4

// The stencil test passes if the new value is strictly equal to the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_Equal 5

// The stencil test passes if the new value is strictly unequal to the value in the stencil buffer
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_NotEqual 6

// The stencil test always passes
#define SFML_SIMPLE_WRAPPER_sf_StencilComparison_Always 7


#ifdef __cplusplus
}
#endif


#endif
