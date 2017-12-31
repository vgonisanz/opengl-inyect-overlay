# Compile full project
project(full)

include_directories(${FREETYPE_INCLUDE_DIRS})
add_executable(full full.c)
target_link_libraries(full ${STEAMLIKE_EXTRA_LIBS})

install(TARGETS full DESTINATION "${CMAKE_INSTALL_PREFIX}/concept/bin")

# Compile simple binary project
project(binary)

include_directories(${FREETYPE_INCLUDE_DIRS})
add_executable(binary binary.c)
target_link_libraries(binary ${STEAMLIKE_EXTRA_LIBS})

install(TARGETS binary DESTINATION "${CMAKE_INSTALL_PREFIX}/concept/bin")

# Install resources
install(FILES ${RESOURCES_PATH}/font.ttf DESTINATION ${CMAKE_INSTALL_PREFIX}/concept/bin/resources)
