# Module step I: Set up project name
# ------------------------------------------------------------------------------------------------------
set(PROJ_NAME simpleoverlay)

project(${PROJ_NAME})

# Module step II: Add the given directories to those the compiler uses to search for include files
# ------------------------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES( ${FREETYPE_INCLUDE_DIRS}  )

# Module step III: Create variables with all includes and sources. You can add them manually in a VAR.
# ------------------------------------------------------------------------------------------------------
#FILE(GLOB ${PROJ_NAME}_HEADERS
#    "include/*.h"
#    "include/*.hpp"
#)
FILE(GLOB ${PROJ_NAME}_SRC
    "src/*.c"
    "src/*.cpp"
)

# Module step IV: List of linker search directories. Path to headers needed by the project.
# ------------------------------------------------------------------------------------------------------
#LINK_DIRECTORIES( ${DIR1} ${DIR2} ...)

# Module step V: Create a library using the specified source files and build type in current project.
# ------------------------------------------------------------------------------------------------------
ADD_LIBRARY(${PROJ_NAME} SHARED ${${PROJ_NAME}_HEADERS} ${${PROJ_NAME}_SRC} )

# Module step VI: Link a target to given libraries. Set the name of libraries needed by the project.
# ------------------------------------------------------------------------------------------------------
#TARGET_LINK_LIBRARIES(${PROJ_NAME} project-dependency1)

# Module step VII: Specify rules to run at install time. Copy generated library and PUBLIC headers to a destination.
# ------------------------------------------------------------------------------------------------------
INSTALL(FILES ${${PROJ_NAME}_HEADERS}
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/${PROJ_NAME}"
        )

INSTALL(TARGETS ${PROJ_NAME}
        DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
        )
