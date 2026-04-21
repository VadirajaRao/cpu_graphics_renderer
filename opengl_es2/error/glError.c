#include "glTypes.h"
#include "glError.h"

GLenum g_e_error_code;

GLenum glGetError(void)
{
	GLenum l_e_error_code;

	l_e_error_code = g_e_error_code;

	g_e_error_code = GL_NO_ERROR;

	return l_e_error_code;
}

void glSetError(GLenum par_e_error_code)
{
	if (par_e_error_code < GL_ERROR_CODE_MAX)
	{
		g_e_error_code = par_e_error_code;
	}
}
