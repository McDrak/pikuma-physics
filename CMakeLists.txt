cmake_minimum_required(VERSION 3.25)
project(PikumaPhysics VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

# Fetching SDL2
FetchContent_Declare(
        SDL2
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-2.32.10
        GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(SDL2)

# Fetching SDL_image
FetchContent_Declare(
        SDL_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG release-2.8.8
        GIT_PROGRESS TRUE
)
# Fix for SDL2 and SDL_Image to not block each other configurations
set(SDL2IMAGE_INSTALL OFF)
set(BUILD_SHARED_LIBS FALSE)
FetchContent_MakeAvailable(SDL_image)

add_subdirectory(vendor)
add_subdirectory(src)
add_subdirectory(test)
