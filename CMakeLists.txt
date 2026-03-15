cmake_minimum_required(VERSION 3.25)
project(PikumaPhysics VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Sets Module Path to find custom Find.cmake files
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Finds SDL2 + SDL2_image + SDL2_gfx
find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2_image REQUIRED)
find_package(SDL2_gfx REQUIRED)

add_subdirectory(src)
add_subdirectory(test)

# Create a symlink for the compile_commands file in order to have it in the root folder, that way the text editor/IDE can pick it up.
execute_process(
	COMMAND ${CMAKE_COMMAND} -E create_symlink
		${CMAKE_BINARY_DIR}/compile_commands.json
		${CMAKE_SOURCE_DIR}/compile_commands.json
)
