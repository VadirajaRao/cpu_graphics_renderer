/* ****************************************************************************/
/* NOTES:                                                                     */
/* Trying to implement creation of GL_VERTEX_SHADER                           */
/*                                                                            */
/* You need a shader object first. You either load a shader code here to be   */
/* compiled or a shader code that's precompiled.                              */
/*                                                                            */
/* These are two separate features. The specification requires one of them to */
/* be supported. The support can be identified by `GL_SHADER_COMPILER` or     */
/* `GL_NUM_SHADER_BINARY_FORMATS` values respectively.                        */
/*                                                                            */
/* If shader source is provided, then compilation shall happen at this stage. */
/*                                                                            */
/* In essence shader object shall store two information:                      */
/*   1. shader source before compilation (if used)                            */
/*   2. compiled shader code                                                  */
/*                                                                            */
/* You need a second object called "program object". The shader object will   */
/* be linked to this.                                                         */
/*                                                                            */
/* The program object is then linked which creates the executable code from   */
/* all the compiled shader objects. This implies a single program object can  */
/* be linked with multiple shader objects.                                    */
/*                                                                            */
/* A single program object must contain both a vertex and a fragment shader.  */
/*                                                                            */
/* You have to mark a program object as a current program object. Based on    */
/* marking, it is clear which vertex shader and fragment shader code to be    */
/* used for processing.                                                       */
/* This is where we may have to bring in the concept of context into picture  */
/* ****************************************************************************/
#include "glTypes.h"
#include "glShader.h"

typedef struct
{
	/* Shader object data */
} t_shader_object;

// As per the specification, we can have many many shader objects with each
// having different shader sources and different shader types. The specification
// does not specify the minimum or maximum number of shader objects that needs
// to be supported. Currently, I am setting an artifical limit of 32 shader
// objects.
#define MAX_SHADER_OBJECTS (32U)
static t_shader_object g_s_shader_object_list[MAX_SHADER_OBJECTS];

// Maintaining a counter to ensure valid shaders are only created. If all
// shader objects are created should return 0
static GLuint g_ui_shader_object_count = (
	(GLuint)(sizeof(t_shader_object) / sizeof(g_s_shader_object_list))
);

GLuint glCreateShader(GLenum par_e_shader_type)
{
    if (
        (GL_VERTEX_SHADER == par_e_shader_type) ||
        (GL_FRAGMENT_SHADER == par_e_shader_type)
    )
    {
	/* Set GL_INVALID_OPERATION error because the provided name */
	/* identifies an object that is not the expected type       */
		glSetError(GL_INVALID_OPERATION);

		return 0;
    }

	if (g_s_shader_object_list == 0)
	{
		return 0;
	}

	g_ui_shader_object_count -= 1;

	return ((GLuint)(MAX_SHADER_OBJECTS - g_ui_shader_object_count));
}
