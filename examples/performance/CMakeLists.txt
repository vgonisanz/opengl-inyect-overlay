# Compile steamlike project
set(PROJ_NAME fakeperformancegame)
project(${PROJ_NAME})

include_directories( ${FREETYPE_INCLUDE_DIRS} )

add_executable(${PROJ_NAME}            performance.cpp)

target_link_libraries(${PROJ_NAME} ${STEAMLIKE_EXTRA_LIBS})

install(TARGETS ${PROJ_NAME} DESTINATION "${CMAKE_INSTALL_PREFIX}/performance/bin")
