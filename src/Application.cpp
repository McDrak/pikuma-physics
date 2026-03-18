#include "Application.hpp"

#include <SDL_events.h>
#include <SDL_timer.h>
#include <memory>

#include "Graphics.hpp"
#include "Physics/Constants.hpp"
#include "Physics/Particle.hpp"
#include "Physics/Vec2.hpp"

namespace PikumaLessons
{
	Application::Application()
		: m_IsRunning(false), m_TestParticle(nullptr), m_TimeSincePreviousFrame(0)
	{
	}

	auto Application::IsRunning() const -> bool
	{
		return m_IsRunning;
	}

	void Application::Setup()
	{
		m_IsRunning = Graphics::OpenWindow();

		constexpr float xTestPosition = 50.F;
		constexpr float yTestPosition = 50.F;
		constexpr float testMass = 1.F;
		m_TestParticle = std::make_unique<Particle>(xTestPosition, yTestPosition, testMass);
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
		// Calculate the amount of time until the target frame time is reached (in milliseconds)
		const int timeToWait = MILLISECONDS_PER_FRAME - static_cast<int>((SDL_GetTicks() - m_TimeSincePreviousFrame));
		if(timeToWait > 0)
		{
			SDL_Delay(timeToWait);
		}

		// Calculate delta time in seconds
		const float deltaTime = static_cast<float>((SDL_GetTicks() - m_TimeSincePreviousFrame)) / MILLISECONDS_PER_SECOND;

		MoveTestParticle(deltaTime);

		m_TimeSincePreviousFrame = SDL_GetTicks();
	}

	void Application::Render()
	{
		Graphics::ClearScreen(TEAL);
		if(m_TestParticle != nullptr)
		{
			Graphics::DrawFillCircle({ m_TestParticle->m_Position.m_X, m_TestParticle->m_Position.m_Y }, 4, WHITE);
		}
		Graphics::RenderFrame();
	}

	void Application::Destroy()
	{
		m_TestParticle.reset();

		Graphics::CloseWindow();
	}

	void Application::MoveTestParticle(const float deltaTime)
	{
		if(m_TestParticle == nullptr)
		{
			return;
		}

		constexpr float xTestVelocity = 100.F;
		constexpr float yTestVelocity = 30.F;
		m_TestParticle->m_Velocity = Vec2(xTestVelocity, yTestVelocity) * deltaTime;
		m_TestParticle->m_Position += m_TestParticle->m_Velocity;
	}
}
