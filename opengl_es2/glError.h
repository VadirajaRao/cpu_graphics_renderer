#ifndef __GL_ERROR_H__
#define __GL_ERROR_H__

extern GLenum g_e_error_code;

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

GLenum glGetError(void);
void glSetError(GLenum par_e_error_code);

#endif /* __GL_ERROR_H__ */
