file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(PikumaLessons ${ENGINE_SOURCES})

target_include_directories(PikumaLessons PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link SDL2 and its libraries
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2Image_INCLUDE_DIRS})

target_link_libraries(PikumaLessons PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(PikumaLessons PRIVATE ${SDL2Image_LIBRARIES})
# target_link_libraries(PikumaLessons PRIVATE SDL2::gfx)