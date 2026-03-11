/* This file contains the basic datatypes defined by the OpenGL ES 2.0        */
/* specification. These datatypes will be used by the GL source code in this  */
/* project.                                                                   */

#ifndef __GL_TYPES_H__
#define __GL_TYPES_H__

/* +------------+-----------+--------------------------------------+ */
/* | Type       | Bit width | Description                          | */
/* +------------+-----------+--------------------------------------+ */
/* | GLboolean  | 1         | Boolean                              | */
/* | GLbyte     | 8         | Signed binary integer                | */
/* | GLubyte    | 8         | Unsigned binary integer              | */
/* | GLchar     | 8         | Characters making up strings         | */
/* | GLshort    | 16        | Signed 2's complement binary integer | */
/* | GLushort   | 16        | Unsigned binary integer              | */
/* | GLint      | 32        | Signed 2's complement binary integer | */
/* | GLuint     | 32        | Unsigned binary integer              | */
/* | GLfixed    | 32        | Signed 2's complement 16.16 scaled   | */
/* |            |           | integer                              | */
/* | GLsizei    | 32        | Non-negative binary integer size     | */
/* | GLenum     | 32        | Enumerated binary integer value      | */
/* | GLintptr   | 32        | Signed 2's complement binary integer | */
/* | GLsizeiptr | 32        | Non-negative binary integer size     | */
/* | GLbitfield | 32        | Bit field                            | */
/* | GLfloat    | 32        | Floating-point value                 | */
/* | GLclampf   | 32        | Floating-point value clamped to      | */
/* |            |           | [0, 1]                               | */
/* +------------+-----------+--------------------------------------+ */

typedef enum
{
    FALSE = 0,
    TRUE
} GLboolean;

typedef char GLbyte;

typedef unsigned char GLubyte;

typedef char GLchar;

typedef short int GLshort;

typedef short unsigned int GLushort;

typedef int GLint;

typedef unsigned int GLuint;

typedef int GLfixed;

typedef unsigned int GLsizei;

typedef unsigned int GLenum;

typedef int * GLintptr;

typedef int GLbitfield;

typedef float GLfloat;

typedef float GLclampf;

#endif /* __GL_TYPES_H__ */
