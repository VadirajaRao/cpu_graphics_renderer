#include <stdio.h>
#include <stdlib.h>
#include "gles2.h"

int main()
{
    GLuint l_u32_vertex_shader_id;

    printf("Creating vertex shader...\n");

    l_u32_vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    if (l_u32_vertex_shader_id == 0)
    {
        fprintf(
            stderr,
            "  [ERR] test_app: Unable to create vertex shader\n"
        );

        exit(1);
    }

    printf(
        "Vertex shader created successfully with shader ID: %u\n",
        l_u32_vertex_shader_id
    );

    return 0;
}
