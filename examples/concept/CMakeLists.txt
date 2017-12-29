# Compile full project
project(full)

include_directories(${FREETYPE_INCLUDE_DIRS})
add_executable(full full.c)
target_link_libraries(full glfw ftgl ${OPENGL_gl_LIBRARY})

install(TARGETS full DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

# Compile simple binary project
project(binary)

include_directories(${FREETYPE_INCLUDE_DIRS})
add_executable(binary binary.c)
target_link_libraries(binary glfw ftgl ${OPENGL_gl_LIBRARY})

install(TARGETS binary DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

# Install resources
install(FILES ${RESOURCES_PATH}/font.ttf DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/resources)
