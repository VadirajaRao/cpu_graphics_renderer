# Process subdirectories to obtain the source string
add_subdirectory(error)
add_subdirectory(shader)

# Define the target library
add_library(opengl_es2 STATIC
  ${ERROR_SOURCES}
  ${SHADER_SOURCES}
)

# Set the include directory
target_include_directories(opengl_es2
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(OpenGL::es2 ALIAS opengl_es2)
