file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(PikumaLessons ${ENGINE_SOURCES})

target_include_directories(PikumaLessons PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link SDL2 and its libraries
target_link_libraries(PikumaLessons PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(PikumaLessons PRIVATE SDL2_image::SDL2_image-static)
target_link_libraries(PikumaLessons PRIVATE SDL2::gfx)
