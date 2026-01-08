#include "Application.hpp"

#include <SDL_events.h>

#include "Graphics.hpp"

namespace PikumaLessons
{
	Application::Application()
		: m_IsRunning(false)
	{
	}

	auto Application::IsRunning() const -> bool
	{
		return m_IsRunning;
	}

	void Application::Setup()
	{
		m_IsRunning = Graphics::OpenWindow();

		// TODO: setup objects in the scene
	}

	void Application::Input()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case SDL_QUIT:
					m_IsRunning = false;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						m_IsRunning = false;
					}
					break;
				default:
					break;
			}
		}
	}

	void Application::Update()
	{
		// TODO: update all objects in the scene
	}

	void Application::Render()
	{
		Graphics::ClearScreen(0xFF056263);
		Graphics::DrawFillCircle({ 200, 200 }, 40, 0xFFFFFFFF);
		Graphics::RenderFrame();
	}

	void Application::Destroy()
	{
		// TODO: destroy all objects in the scene

		Graphics::CloseWindow();
	}
}