#ifndef __GL_TYPES_H__
#define __GL_TYPES_H__

typedef unsigned int GLuint;
typedef unsigned int GLenum;
typedef void GLvoid;
typedef unsigned int GLsizei;
typedef char GLchar;
typedef int GLint;

enum GLShaderType
{
    GL_VERTEX_SHADER = 0x0,
    GL_FRAGMENT_SHADER,
    GL_GEOMETRY_SHADER
};

enum GLErrorType
{
    GL_SUCCESS = 0x0,
    GL_INVALID_VALUE,
    GL_INVALID_OPERATION
};

GLuint glCreateShader(GLenum par_e_shader_type);
GLvoid glShaderSource(
    GLuint          par_u_shader_id,
    GLsizei         par_s_line_count,
    const GLchar    **par_ppc_shader_source,
    const GLint     *par_pi_line_lengths
);
GLenum glGetError(void);

#endif /* __GL_TYPES_H__ */