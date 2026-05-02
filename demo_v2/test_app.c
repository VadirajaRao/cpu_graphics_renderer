#include <stdio.h>
#include "glTypes.h"

GLchar *gs_ppc_vertex_shader_source[36] =
{
    "#include <stdio.h>\n",
    "\n",
    "int main()\n",
    "{\n",
    "    printf(\"Hello, World!\\n\");\n",
    "    return 0;\n",
    "}\n"
};

int main(void)
{
    GLuint l_u_vertex_shader_id = 0;
    GLenum l_e_error = GL_SUCCESS;

    l_u_vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);

    if (l_u_vertex_shader_id == 0)
    {
        fprintf(
            stderr,
            "  [ERR] main: Failed to create vertex shader. GL Error: %u\n",
            glGetError()
        );
    }

    glShaderSource(
        l_u_vertex_shader_id,
        7,
        (const GLchar **)gs_ppc_vertex_shader_source,
        NULL
    );

    l_e_error = glGetError();
    if (l_e_error != GL_SUCCESS)
    {
        fprintf(
            stderr,
            "  [ERR] main: Failed to set vertex shader source. GL Error: %u\n",
            l_e_error
        );
    }

    printf("Program execution complete\n");

    return 0;
}