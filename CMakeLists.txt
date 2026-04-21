cmake_minimum_required(VERSION 4.2.3)
project(SoftGL LANGUAGES C)

# Enforcing C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Enforcing strict compilation procedure with warnings
# -Wall      : Enable all standard warnings
# -Wextra    : Enable extra warnings
# -Wpedantic : Enforce strict adherence to the ISO C Standard
add_compile_options(-Wall -Wextra -Wpedantic)

# Defining the output directory for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Including OpenGL ES2 library
add_subdirectory(opengl_es2)
