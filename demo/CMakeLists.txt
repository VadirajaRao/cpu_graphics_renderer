add_executable(test_app1 test_app1.c)

target_link_libraries(test_app1 PRIVATE OpenGL::es2)

target_include_directories(test_app1
    PRIVATE ${CMAKE_SOURCE_DIR}/opengl_es2/include
)
