file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(PikumaLessons ${ENGINE_SOURCES})

target_include_directories(PikumaLessons PUBLIC ${PROJECT_SOURCE_DIR}/include)