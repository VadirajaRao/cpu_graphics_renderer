#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "glTypes.h"
#include "glShader.h"

extern t_list *gs_p_shader_list;

static inline void validate_shader_id(GLuint par_u32_shader)
{
    if (par_u32_shader == 0)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Given shader ID is invalid\n"
        );
    }
}

static inline void validate_line_count(GLsizei par_sz_count)
{
    if (par_sz_count == 0)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Shader source does not have any lines\n"
        );
    }
}

static inline void validate_shader_source(const char **par_ppc_string)
{
    if (par_ppc_string == NULL)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: No shader source specified\n"
        );
    }
}

static inline void validate_line_length(GLint *par_i32_length)
{
    if (par_i32_length != NULL)
    {
        fprintf(
            stderr,
            "  [ERR] glShaderSource: Only null terminate shader source lines"
            " are accepted\n"
        );
    }
}

void glShaderSource(
	GLuint      par_u32_shader,
	GLsizei     par_sz_count,
	const char  **par_ppc_string,
	GLint       *par_i32_length
)
{
    validate_shader_id(par_u32_shader);
    validate_line_count(par_sz_count);
    validate_shader_source(par_ppc_string);
    validate_line_length(par_i32_length);

	char l_str_shader_source[] = "/tmp/softgl/shader_source_XXXXXX.c";

	int l_i32_shader_fd = mkstemp(l_str_shader_source);
	if (l_i32_shader_fd == -1)
	{
		fprintf(
			stderr,
			"  [ERR] glShaderSource: Unable to create a temporary shader source"
			" file at %s\n",
			l_str_shader_source
		);

		return;
	}

	// Store the file descriptor in the shader object
	t_list *ls_p_shader_list = gs_p_shader_list;
	GLboolean l_b_flag = FALSE;

	do
	{
		if (ls_p_shader_list->data->shader_id == par_u32_shader)
		{
			ls_p_shader_list->data->shader_source_fd = l_i32_shader_fd;
			l_b_flag = TRUE;
		}
		else
		{
			if (ls_p_shader_list->next != NULL)
			{
				ls_p_shader_list = ls_p_shader_list->next;
			}
		}
	} while(!l_b_flag);

	unlink(l_str_shader_source);

	FILE *l_p_shader_fp = fdopen(l_i32_shader_fd, "w+");
	if (!l_p_shader_fp)
	{
		fprintf(
			stderr,
			"  [ERR] glShaderSource: Unable to open shader source file\n"
		);

		close(l_i32_shader_fd);

		return;
	}

	// Write to file using fprintf
	for (GLsizei i = 0; i < par_sz_count; i++)
	{
		fprintf(
			l_p_shader_fp,
			"%s", par_ppc_string[i]
		);
	}

	fclose(l_p_shader_fp);

	return;
}
