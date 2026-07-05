#ifndef SFML_SIMPLE_WRAPPER_GRAPHICS_SF_SHADER_H
#define SFML_SIMPLE_WRAPPER_GRAPHICS_SF_SHADER_H


#include "./types.h"

#include "../system/types.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Default constructor
 * This constructor creates an empty shader.
 *
 * Binding an empty shader has the same effect as not
 *binding any shader.
 */
SFML_SIMPLE_WRAPPER_API sf_Shader sf_Shader_default();

/**
 * Construct from a shader file.
 * This constructor loads a single shader, vertex, geometry or
 *fragment, identified by the second argument.
 * The source must be a text file containing a valid
 *shader in GLSL language. GLSL is a C-like language
 *dedicated to OpenGL shaders; you'll probably need to
 *read a good documentation for it before writing your
 *own shaders.
 * Throws sf::Exception if loading was unsuccessful.
 */
SFML_SIMPLE_WRAPPER_API sf_Shader sf_Shader_init(const std_Path filepath, int shader_type);

/**
 * Construct from vertex and fragment shader files
 * This constructor loads both the vertex and the fragment
 *shaders. If one of them fails to load, the shader is left
 *empty (the valid shader is unloaded).
 * The sources must be text files containing valid shaders
 *in GLSL language. GLSL is a C-like language dedicated to
 *OpenGL shaders; you'll probably need to read a good documentation
 *for it before writing your own shaders.
 * Throws sf::Exception if loading was unsuccessful
 */
SFML_SIMPLE_WRAPPER_API sf_Shader sf_Shader_init_ex(
	const std_Path vertexShaderFilename,
	const std_Path fragmentShaderFilename
);

/**
 * Construct from vertex and fragment shader files
 * This constructor loads the vertex, geometry and fragment
 *shaders. If one of them fails to load, the shader is left
 *empty (the valid shader is unloaded).
 * The sources must be text files containing valid shaders
 *in GLSL language. GLSL is a C-like language dedicated to
 *OpenGL shaders; you'll probably need to read a good documentation
 *for it before writing your own shaders.
 * Throws sf::Exception if loading was unsuccessful
 */
SFML_SIMPLE_WRAPPER_API sf_Shader sf_Shader_init_ex_ex(	// =)
	const std_Path vertexShaderFilename,
	const std_Path geometryShaderFilename,
	const std_Path fragmentShaderFilename
);

/**
 * Deletes object and returns NULL.
 */
SFML_SIMPLE_WRAPPER_API void* sf_Shader_del(sf_Shader obj);

/**
 * Load the vertex, geometry or fragment shader from a file.
 * 1 if loading succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Shader_load(sf_Shader self, const std_Path filepath, int shader_type);

/**
 * Load both the vertex and fragment shaders from files.
 * If one of them fails to load, the shader is left empty (the valid shader is unloaded).
 * 1 if loading succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Shader_load_ex(sf_Shader self,
	const std_Path vertexShaderFilename,
	const std_Path fragmentShaderFilename
);

/**
 * Load the vertex, geometry and fragment shaders from files.
 * If one of them fails to load, the shader is left empty (the valid shader is unloaded).
 * 1 if loading succeeded, 0 if it failed.
 */
SFML_SIMPLE_WRAPPER_API int sf_Shader_load_ex_ex(sf_Shader self,	// Will I eventually write triple ex?
	const std_Path vertexShaderFilename,
	const std_Path geometryShaderFilename,
	const std_Path fragmentShaderFilename
);

/**
 * Specify value for \p float uniform.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_set_uniform(sf_Shader self, const char* name, float x);

/**
 * Specify value for \p vec2 uniform.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_set_uniform_vec2(sf_Shader self, const char* name, sf_Vector2f vec);

/**
 * Specify value for \p vec3 uniform.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_set_uniform_vec3(sf_Shader self, const char* name, sf_Vector3f vec);

/**
 * Specify value for \p int uniform.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_set_uniform_i(sf_Shader self, const char* name, int x);

/**
 * Specify value for \p vec2i uniform.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_set_uniform_vec2i(sf_Shader self, const char* name, sf_Vector2i vec);

/**
 * Get the underlying OpenGL handle of the shader.
 * You shouldn't need to use this function, unless you have
 *very specific stuff to implement that SFML doesn't support,
 *or implement a temporary workaround until a bug is fixed.
 * Returns OpenGL handle of the shader or 0 if not yet loaded.
 */
SFML_SIMPLE_WRAPPER_API unsigned int sf_Shader_get_native_handle(sf_Shader self);

/**
 * Bind a shader for rendering
 * This function is not part of the graphics API, it mustn't be
 *used when drawing SFML entities. It must be used only if you
 *mix `sf::Shader` with OpenGL code.
 */
SFML_SIMPLE_WRAPPER_API void sf_Shader_bind(const sf_Shader shader);

/**
 * Tell whether or not the system supports shaders.
 * This function should always be called before using
 *the shader features. If it returns `false`, then
 *any attempt to use `sf::Shader` will fail.
 * Returns 1 if shaders are supported, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Shader_is_available();

/**
 * Tell whether or not the system supports geometry shaders.
 * This function should always be called before using
 *the geometry shader features. If it returns `false`, then
 *any attempt to use `sf::Shader` geometry shader features will fail.
 *
 * This function can only return `true` if isAvailable() would also
 *return `true`, since shaders in general have to be supported in
 *order for geometry shaders to be supported as well.
 *
 * Note: The first call to this function, whether by your
 *code or SFML will result in a context switch.
 * Returns 1 if geometry shaders are supported, 0 otherwise.
 */
SFML_SIMPLE_WRAPPER_API int sf_Shader_is_geometry_available();


#ifdef __cplusplus
}
#endif


#endif
