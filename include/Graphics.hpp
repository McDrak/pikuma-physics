#pragma once

#include <SDL_render.h>
#include <vector>

#include "Physics/Vec2.hpp"

namespace PikumaLessons
{
	struct Graphics {
		static int windowWidth;
		static int windowHeight;
		static SDL_Window* window;
		static SDL_Renderer* renderer;

		static int Width();
		static int Height();
		static bool OpenWindow();
		static void CloseWindow();
		static void ClearScreen(Uint32 color);
		static void RenderFrame();
		static void DrawLine(const Vec2& start, const Vec2& end, Uint32 color);
		static void DrawCircle(const Vec2& position, int radius, float angle, Uint32 color);
		static void DrawFillCircle(const Vec2& position, int radius, Uint32 color);
		static void DrawRect(const Vec2& position, int width, int height, Uint32 color);
		static void DrawFillRect(const Vec2& position, int width, int height, Uint32 color);
		static void DrawPolygon(const Vec2& position, const std::vector<Vec2>& vertices, Uint32 color);
		static void DrawFillPolygon(const Vec2& position, const std::vector<Vec2>& vertices, Uint32 color);
		static void DrawTexture(const Vec2& position, int width, int height, float rotation, SDL_Texture* texture);
	};
}