add_library(SDL2_gfx STATIC
        SDL2_gfxPrimitives.c
        SDL2_rotozoom.c
        SDL2_imageFilter.c
)

target_link_libraries(SDL2_gfx PUBLIC SDL2::SDL2)

add_library(SDL2::gfx ALIAS SDL2_gfx)