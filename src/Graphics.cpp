#include "Graphics.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2_gfxPrimitives.h"

// TODO: There are a lot of changes that could be done in this and the .hpp file. Hopefully they'll be done in the future.

namespace PikumaLessons
{
	SDL_Window* Graphics::window = nullptr;
	SDL_Renderer* Graphics::renderer = nullptr;
	int Graphics::windowWidth = 0;
	int Graphics::windowHeight = 0;

	int Graphics::Width()
	{
		return windowWidth;
	}

	int Graphics::Height()
	{
		return windowHeight;
	}

	bool Graphics::OpenWindow()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			std::cerr << "Error initializing SDL" << std::endl;
			return false;
		}
		SDL_DisplayMode display_mode;
		SDL_GetCurrentDisplayMode(0, &display_mode);
		windowWidth = display_mode.w;
		windowHeight = display_mode.h;
		window = SDL_CreateWindow(nullptr, 0, 0, windowWidth, windowHeight, SDL_WINDOW_BORDERLESS);
		if (!window)
		{
			std::cerr << "Error creating SDL window" << std::endl;
			return false;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (!renderer)
		{
			std::cerr << "Error creating SDL renderer" << std::endl;
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
		lineColor(renderer, start.GetX(), start.GetY(), end.GetX(), end.GetY(), color);
	}

	void Graphics::DrawCircle(const Vec2& position, const int radius, const float angle, const Uint32 color)
	{
		circleColor(renderer, position.GetX(), position.GetY(), radius, color);
		lineColor(renderer, position.GetX(), position.GetY(), position.GetX() + cos(angle) * radius, position.GetY() + sin(angle) * radius, color);
	}

	void Graphics::DrawFillCircle(const Vec2& position, const int radius, const Uint32 color)
	{
		filledCircleColor(renderer, position.GetX(), position.GetY(), radius, color);
	}

	void Graphics::DrawRect(const Vec2& position, const int width, const int height, const Uint32 color)
	{
		lineColor(renderer, position.GetX() - width / 2.0, position.GetY() - height / 2.0, position.GetX() + width / 2.0, position.GetY() - height / 2.0, color);
		lineColor(renderer, position.GetX() + width / 2.0, position.GetY() - height / 2.0, position.GetX() + width / 2.0, position.GetY() + height / 2.0, color);
		lineColor(renderer, position.GetX() + width / 2.0, position.GetY() + height / 2.0, position.GetX() - width / 2.0, position.GetY() + height / 2.0, color);
		lineColor(renderer, position.GetX() - width / 2.0, position.GetY() + height / 2.0, position.GetX() - width / 2.0, position.GetY() - height / 2.0, color);
	}

	void Graphics::DrawFillRect(const Vec2& position, const int width, const int height, const Uint32 color)
	{
		boxColor(renderer, position.GetX() - width / 2.0, position.GetY() - height / 2.0, position.GetX() + width / 2.0, position.GetY() + height / 2.0, color);
	}

	void Graphics::DrawPolygon(const Vec2& position, const std::vector<Vec2>& vertices, const Uint32 color)
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			int currIndex = i;
			int nextIndex = (i + 1) % vertices.size();
			lineColor(renderer,
			          vertices[currIndex].GetX(),
			          vertices[currIndex].GetY(),
			          vertices[nextIndex].GetX(),
			          vertices[nextIndex].GetY(),
			          color);
		}
		filledCircleColor(renderer, position.GetX(), position.GetY(), 1, color);
	}

	void Graphics::DrawFillPolygon(const Vec2& position, const std::vector<Vec2>& vertices, const Uint32 color)
	{
		std::vector<short> vx;
		std::vector<short> vy;
		for (int i = 0; i < vertices.size(); i++)
		{
			vx.push_back(static_cast<int>(vertices[i].GetX()));
		}
		for (int i = 0; i < vertices.size(); i++)
		{
			vy.push_back(static_cast<int>(vertices[i].GetY()));
		}
		filledPolygonColor(renderer, &vx[0], &vy[0], vertices.size(), color);
		filledCircleColor(renderer, position.GetX(), position.GetY(), 1, 0xFF000000);
	}

	void Graphics::DrawTexture(const Vec2& position,  const int width, const int height, const float rotation, SDL_Texture* texture)
	{
		SDL_Rect dstRect = {position.GetX() - (width / 2), position.GetY() - (height / 2), width, height};
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