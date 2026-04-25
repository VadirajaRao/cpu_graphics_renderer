#include <stdio.h>
#include <stdlib.h>
#include "glTypes.h"
#include "error/glError.h"
#include "glShader.h"
#include "gles2.h"

// The first step in rendering any object is to ensure the pipeline is OK.
// Majority of the pipeline in the current specification is fixed and what is
// programmable are handled via shaders.
//
// There are two types of shaders we will need to work on:
//   1. Vertex shader
//   2. Fragment shader
//

// Linked list data pointing to shader object list
static t_list   *gs_p_shader_list       = NULL;
static t_list   *gs_p_shader_list_head  = NULL;
static GLuint   g_ui_shader_count       = 0;

GLuint glCreateShader(GLenum par_e_shader_type)
{
	// Setting GL_INVALID_OPERATION error code when the shader type is neither
	// vertex shader nor fragment shader
    if (
		(GL_VERTEX_SHADER != par_e_shader_type) &&
		(GL_FRAGMENT_SHADER != par_e_shader_type)
	)
	{
		// Though this not an actual OpenGL API, it is used to support the
		// glGetError() API defined by the specification
		glSetError(GL_INVALID_OPERATION);

		// As per the specification, 0 indicates no shader object is created
		return 0;
	}

	// Allocating memory to a shader object if valid shared object type
	// is selected
	t_shader_object *l_p_shader_object = (
		(t_shader_object *)malloc(sizeof(t_shader_object))
	);

	// If shader object cannot be allocated memory, then generate a log because
	// it is not certain which error code to raise in this scenario. Return  to
	// indicate shader object creation is a failure.
	if (NULL == l_p_shader_object)
	{
		printf("Unable to create shader object\n");
		return 0;
	}

	// Store the shader type into the shader object just created
	l_p_shader_object->shader_type = par_e_shader_type;

	// Since we will have many shader objects depending on the application need
	// Create a linked list to store the shader objects created
	t_list *l_p_shader_list_entry = (t_list *)malloc(sizeof(t_list));

	// If a linked list entry cannot be allocated memory, generate a log
	// because it is not certain which error code to raise in this scenario.
	// Return to indicate shader object creation is a failure, after freeing
	// up the memory allocated to shader object
	if (NULL == l_p_shader_list_entry)
	{
		free(l_p_shader_object);

		printf("Unable to add entry to shader object list\n");
		return 0;
	}

    // Make an entry into the shader object list
	if (gs_p_shader_list == NULL)
	{
		gs_p_shader_list        = l_p_shader_list_entry;
		gs_p_shader_list_head   = l_p_shader_list_entry;

		gs_p_shader_list->data  = l_p_shader_object;
		gs_p_shader_list->next  = NULL;
	}
	else
	{
		gs_p_shader_list->next = l_p_shader_list_entry;
		gs_p_shader_list = gs_p_shader_list->next;
		gs_p_shader_list->data = l_p_shader_object;
	}

	// Keep track of the number of shader objects created to assign an ID
	g_ui_shader_count += 1;

	// Update the shader object with an ID for further operations
	gs_p_shader_list->data->shader_id = g_ui_shader_count;

	// Return the shader ID
	return g_ui_shader_count;
}
