#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "glTypes.h"

static GLenum gs_e_gl_error;
static GLuint gs_u_shader_id_counter;

GLenum glGetError(void)
{
    GLenum l_e_error = gs_e_gl_error;

    gs_e_gl_error = GL_SUCCESS;

    return l_e_error;
}

GLuint glCreateShader(GLenum par_e_shader_type)
{
    if ((par_e_shader_type != GL_VERTEX_SHADER) &&
        (par_e_shader_type != GL_FRAGMENT_SHADER))
    {
        fprintf(
            stderr,
            "  [ERR] glCreateShader: Invalid shader type: %u\n",
            par_e_shader_type
        );

        gs_e_gl_error = GL_INVALID_VALUE;

        return 0;
    }

    gs_u_shader_id_counter++;

    return gs_u_shader_id_counter;
}

GLvoid glShaderSource(
    GLuint par_u_shader_id,
    GLsizei par_s_line_count,
    const GLchar **par_ppc_shader_source,
    const GLint *par_pi_line_lengths
)
{
    (void) par_pi_line_lengths;

    if (par_u_shader_id == 0)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Invalid shader ID: %u\n",
            par_u_shader_id
        );

        gs_e_gl_error = GL_INVALID_VALUE;

        return;
    }

    if (par_s_line_count == 0)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Invalid shader source line count\n"
        );

        gs_e_gl_error = GL_INVALID_VALUE;

        return;
    }

    if (par_ppc_shader_source == NULL)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Shader source is not provided\n"
        );

        gs_e_gl_error = GL_INVALID_VALUE;

        return;
    }

    GLchar l_str_shader_source[] = "/tmp/softgl/shader_source_XXXXXX";

    mkdir("/tmp/softgl", 0755);

    GLint l_i_shader_fd = mkstemp(l_str_shader_source);
    if (l_i_shader_fd == -1)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Unable to create a temporary shader source"
            " file for compilation: %s\n"
            "                        ERRNO: %d\n",
            l_str_shader_source,
            errno
        );

        return;
    }

    GLchar l_str_shader_source_file[256];
    snprintf(
        l_str_shader_source_file,
        sizeof(l_str_shader_source_file),
        "%s.c",
        l_str_shader_source
    );

    if (rename(l_str_shader_source, l_str_shader_source_file) == -1)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Temporary file rename failed\n"
        );

        close(l_i_shader_fd);

        return;
    }

    FILE *l_p_shader_file = fdopen(l_i_shader_fd, "w+");
    if (l_p_shader_file == NULL)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Unable to open temporary shader source\n"
        );

        close(l_i_shader_fd);

        return;
    }

    for (GLsizei i = 0; i < par_s_line_count; i++)
    {
        fprintf(
            l_p_shader_file,
            "%s", par_ppc_shader_source[i]
        );
    }

    return;
}
