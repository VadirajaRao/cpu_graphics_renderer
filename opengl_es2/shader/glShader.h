#ifndef __GL_SHADER_H__
#define __GL_SHADER_H__

// A shader is represented internally through shader object which stores the
// following information:
//   * Shader ID
//   * Type of shader
//   * Shader source code
//   * Compiled shader binary
typedef struct
{
    GLuint      shader_id;
    GLenum      shader_type;
    GLchar      *shader_source;
    GLchar      *shader_binary;
    GLint       shader_source_fd;
} t_shader_object;

// typedef enum
// {
//     GL_VERTEX_SHADER = 0U,
//     GL_FRAGMENT_SHADER
// } t_gl_shader_type;

// A general linked list to store information by allocating memory dynamically
typedef struct s_list
{
    t_shader_object *data;
    struct s_list   *next;
} t_list;

#endif /* __GL_SHADER_H__ */
