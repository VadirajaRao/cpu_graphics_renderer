#ifndef __GLES2_H__
#define __GLES2_H__

#include "glTypes.h"

/* *******/
/* Error */
/* *******/
/* Enumeration */
enum GL_ERROR_CODE
{
	GL_NO_ERROR = 0,
	GL_INVALID_ENUM,
	GL_INVALID_FRAMEBUFFER_OPERATION,
	GL_INVALID_VALUE,
	GL_INVALID_OPERATION,
	GL_OUT_OF_MEMORY,
	GL_ERROR_CODE_MAX
};

/* Function Prototype */
GLenum glGetError(void);

/* ********/
/* Shader */
/* ********/
/* Enumeration */
typedef enum
{
	GL_VERTEX_SHADER = 0U,
	GL_FRAGMENT_SHADER
} t_gl_shader_type;

/* Function Prototype */
GLuint glCreateShader(GLenum a_e_shader_type);

void glShaderSource(
	GLuint      a_u32_shader,
	GLsizei     a_sz_count,
	const char  **a_ppc_string,
	GLint       *a_pi32_length
);

#endif /* __GLES2_H__ */
