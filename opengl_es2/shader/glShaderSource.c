void glShaderSource (
	GLuint par_ui_shader,
	GLsizei par_sz_count,
	const GLchar **par_p_string,
	const GLint *length
)
{
	if (par_ui_shader == 0)
	{
		glSetError(GL_INVALID_VALUE);
		return;
	}

	return;
}
	
