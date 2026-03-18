#pragma once

#include "SDL2/SDL_stdinc.h"

namespace PikumaLessons
{
	constexpr int FPS = 60;
	constexpr int MILLISECONDS_PER_FRAME = 1000 / FPS;
	constexpr float MILLISECONDS_PER_SECOND = 1000.F;
	constexpr float RADIAN_CONVERSION_FACTOR = 57.2958F;
	constexpr float DRAW_WIDTH_RATIO = 2.F;
	constexpr float DRAW_HEIGHT_RATIO = 2.F;

	constexpr Uint32 BLACK = 0xFF000000;
	constexpr Uint32 WHITE = 0xFFFFFFFF;
	constexpr Uint32 TEAL = 0xFF056263;
	constexpr Uint8 RED_BIT_MOVEMENT = 16;
	constexpr Uint8 GREEN_BIT_MOVEMENT = 8;
	constexpr Uint8 BLUE_BIT_MOVEMENT = 0;
	constexpr Uint8 COLOR_ALPHA = 255;
}
