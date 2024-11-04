cmake_minimum_required(VERSION 3.28)
project(Ceebles_Quest)

# Set the GBDK path
set(GBDK_DIR "G:/gbdk")


# Include directories
include_directories("${GBDK_DIR}/include" "${CMAKE_SOURCE_DIR}/include")

# Custom command to build the .gb file using lcc
add_custom_command(OUTPUT ${CMAKE_SOURCE_DIR}/build/game.gb
        COMMAND ${GBDK_DIR}/bin/lcc -I${GBDK_DIR}/include -I${CMAKE_SOURCE_DIR}/include -debug -o ${CMAKE_SOURCE_DIR}/build/game.gb ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/core/*.c ${CMAKE_SOURCE_DIR}/src/data/*.c
        DEPENDS ${CMAKE_SOURCE_DIR}/src/*.c ${CMAKE_SOURCE_DIR}/src/core/*.c ${CMAKE_SOURCE_DIR}/src/data/*.c
        COMMENT "Building game.gb with lcc")

# Custom target that depends on the .gb file
add_custom_target(Build_ROM ALL
        DEPENDS ${CMAKE_SOURCE_DIR}/build/game.gb)

# Ensure CMake knows about the source files (for IDEs)
file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(game EXCLUDE_FROM_ALL ${SOURCES}
        src/main.c)