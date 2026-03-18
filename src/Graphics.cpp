#include "Graphics.hpp"

#include <iostream>

#include "SDL2/SDL2_gfxPrimitives.h"
#include "SDL2/SDL_error.h"

// TODO: There are a lot of changes that could be done in this and the .hpp file. Hopefully they'll be done in the future.

namespace PikumaLessons
{
	SDL_Window* Graphics::window = nullptr;
	SDL_Renderer* Graphics::renderer = nullptr;
	int Graphics::windowWidth = 0;
	int Graphics::windowHeight = 0;

	auto Graphics::Width() -> int
	{
		return windowWidth;
	}

	auto Graphics::Height() -> int
	{
		return windowHeight;
	}

	auto Graphics::OpenWindow() -> bool
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cerr << "Error initializing SDL with error -> " << SDL_GetError() << '\n';
			return false;
		}

		SDL_DisplayMode displayMode;
		SDL_GetCurrentDisplayMode(0, &displayMode);
		windowWidth = displayMode.w;
		windowHeight = displayMode.h;

		window = SDL_CreateWindow(nullptr, 0, 0, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);
		if (window == nullptr)
		{
			std::cerr << "Error creating SDL window" << '\n';
			return false;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr)
		{
			std::cerr << "Error creating SDL renderer" << '\n';
			return false;
		}

		return true;
	}

	void Graphics::ClearScreen(const Uint32 color)
	{
		SDL_SetRenderDrawColor(renderer, color >> 16, color >> 8, color, 255);
		SDL_RenderClear(renderer);
	}

	void Graphics::RenderFrame()
	{
		SDL_RenderPresent(renderer);
	}

	void Graphics::DrawLine(const Vec2& start, const Vec2& end, const Uint32 color)
	{
		lineColor(renderer, start.m_X, start.m_Y, end.m_X, end.m_Y, color);
	}

	void Graphics::DrawCircle(const Vec2& position, const int radius, const float angle, const Uint32 color)
	{
		circleColor(renderer, position.m_X, position.m_Y, radius, color);
		lineColor(renderer, position.m_X, position.m_Y, position.m_X + cos(angle) * radius, position.m_Y + sin(angle) * radius, color);
	}

	void Graphics::DrawFillCircle(const Vec2& position, const int radius, const Uint32 color)
	{
		filledCircleColor(renderer, position.m_X, position.m_Y, radius, color);
	}

	void Graphics::DrawRect(const Vec2& position, const int width, const int height, const Uint32 color)
	{
		lineColor(renderer, position.m_X - width / 2.0, position.m_Y - height / 2.0, position.m_X + width / 2.0, position.m_Y - height / 2.0, color);
		lineColor(renderer, position.m_X + width / 2.0, position.m_Y - height / 2.0, position.m_X + width / 2.0, position.m_Y + height / 2.0, color);
		lineColor(renderer, position.m_X + width / 2.0, position.m_Y + height / 2.0, position.m_X - width / 2.0, position.m_Y + height / 2.0, color);
		lineColor(renderer, position.m_X - width / 2.0, position.m_Y + height / 2.0, position.m_X - width / 2.0, position.m_Y - height / 2.0, color);
	}

	void Graphics::DrawFillRect(const Vec2& position, const int width, const int height, const Uint32 color)
	{
		boxColor(renderer, position.m_X - width / 2.0, position.m_Y - height / 2.0, position.m_X + width / 2.0, position.m_Y + height / 2.0, color);
	}

	void Graphics::DrawPolygon(const Vec2& position, const std::vector<Vec2>& vertices, const Uint32 color)
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			int currIndex = i;
			int nextIndex = (i + 1) % vertices.size();
			lineColor(renderer,
			          vertices[currIndex].m_X,
			          vertices[currIndex].m_Y,
			          vertices[nextIndex].m_X,
			          vertices[nextIndex].m_Y,
			          color);
		}
		filledCircleColor(renderer, position.m_X, position.m_Y, 1, color);
	}

	void Graphics::DrawFillPolygon(const Vec2& position, const std::vector<Vec2>& vertices, const Uint32 color)
	{
		std::vector<short> vx;
		std::vector<short> vy;
		for (int i = 0; i < vertices.size(); i++)
		{
			vx.push_back(static_cast<int>(vertices[i].m_X));
		}
		for (int i = 0; i < vertices.size(); i++)
		{
			vy.push_back(static_cast<int>(vertices[i].m_Y));
		}
		filledPolygonColor(renderer, &vx[0], &vy[0], vertices.size(), color);
		filledCircleColor(renderer, position.m_X, position.m_Y, 1, 0xFF000000);
	}

	void Graphics::DrawTexture(const Vec2& position,  const int width, const int height, const float rotation, SDL_Texture* texture)
	{
		SDL_Rect dstRect = {position.m_X - (width / 2), position.m_Y - (height / 2), width, height};
		float rotationDeg = rotation * 57.2958;
		SDL_RenderCopyEx(renderer, texture, nullptr, &dstRect, rotationDeg, nullptr, SDL_FLIP_NONE);
	}

	void Graphics::CloseWindow()
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
}
