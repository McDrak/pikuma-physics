#include "Application.hpp"

#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_timer.h>
#include <algorithm>
#include <memory>

#include "Graphics.hpp"
#include "Physics/Constants.hpp"
#include "Physics/Particle.hpp"

namespace PikumaLessons
{
	Application::Application(const int testParticlesAmount)
		: m_IsRunning(false), m_ParticlesAmount(testParticlesAmount), m_TimeSincePreviousFrame(0)
	{
		m_Particles.reserve(m_ParticlesAmount);
	}

	void Application::Run()
	{
		Setup();

		while (IsRunning())
		{
			Input();
			Update();
			Render();
		}

		Destroy();
	}

	void Application::Setup()
	{
		m_IsRunning = Graphics::OpenWindow();

		for(int currentParticleIndex = 0; currentParticleIndex < m_ParticlesAmount; currentParticleIndex++)
		{
			const float xTestPosition = 50.F + (20.F * currentParticleIndex);
			const float yTestPosition = 50.F;
			const float testMass = 1.F + (1.F * currentParticleIndex);
			const int testRadius = 4 + (1 * currentParticleIndex);
			m_Particles.push_back(std::make_unique<Particle>(xTestPosition, yTestPosition, testMass, testRadius));
		}
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
				{
					constexpr float keyboardForce = 50.F * PIXELS_PER_METER;
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						m_IsRunning = false;
					}
					else if(event.key.keysym.sym == SDLK_UP)
					{
						m_KeyboardPushForce.m_Y = -keyboardForce;
					}
					else if(event.key.keysym.sym == SDLK_DOWN)
					{
						m_KeyboardPushForce.m_Y = keyboardForce;
					}
					else if(event.key.keysym.sym == SDLK_LEFT)
					{
						m_KeyboardPushForce.m_X = -keyboardForce;
					}
					else if(event.key.keysym.sym == SDLK_RIGHT)
					{
						m_KeyboardPushForce.m_X = keyboardForce;
					}
					break;
				}
				case SDL_KEYUP:
				{
					if(event.key.keysym.sym == SDLK_UP)
					{
						m_KeyboardPushForce.m_Y = 0.F;
					}
					if(event.key.keysym.sym == SDLK_DOWN)
					{
						m_KeyboardPushForce.m_Y = 0.F;
					}
					if(event.key.keysym.sym == SDLK_LEFT)
					{
						m_KeyboardPushForce.m_X = 0.F;
					}
					if(event.key.keysym.sym == SDLK_RIGHT)
					{
						m_KeyboardPushForce.m_X = 0.F;
					}
					break;
				}
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
		float deltaTime = static_cast<float>((SDL_GetTicks() - m_TimeSincePreviousFrame)) / MILLISECONDS_PER_SECOND;
		// Non-deterministic delta time
		// TODO: Check in the future to maybe have fixed and non-fixed delta times
		deltaTime = std::min(deltaTime, MAX_DELTA_TIME);

		for(auto& currentParticle : m_Particles)
		{
			MoveTestParticle(deltaTime, currentParticle);
		}

		m_TimeSincePreviousFrame = SDL_GetTicks();
	}

	void Application::Render()
	{
		Graphics::ClearScreen(TEAL);

		for(auto& currentParticle : m_Particles)
		{
			if(currentParticle != nullptr)
			{
				Graphics::DrawFillCircle(currentParticle->m_Position, currentParticle->m_Radius, WHITE);
			}
		}

		Graphics::RenderFrame();
	}

	void Application::Destroy()
	{
		// For testing purposes, I'm clearing here the test particle here
		for(auto& currentParticle : m_Particles)
		{
			currentParticle.reset();
		}

		Graphics::CloseWindow();
	}

	void Application::MoveTestParticle(const float deltaTime, std::unique_ptr<Particle>& testParticle)
	{
		if(testParticle == nullptr)
		{
			return;
		}

		// Weight = mass * gravity ONLY in the Y axis
		constexpr float xWeightForce = 0.F * PIXELS_PER_METER;
		const float yWeightForce = testParticle->m_Mass * 9.8F * PIXELS_PER_METER;
		testParticle->AddForce({ xWeightForce, yWeightForce });

		testParticle->AddForce(m_KeyboardPushForce);

		testParticle->Integrate(deltaTime);

		// Hardcoded boundary checks
		if((testParticle->m_Position.m_X - testParticle->m_Radius) <= 0)
		{
			testParticle->m_Position.m_X = testParticle->m_Radius;
			testParticle->m_Velocity.m_X *= -1.F;
		}
		else if((testParticle->m_Position.m_X + testParticle->m_Radius) >= Graphics::windowWidth)
		{
			testParticle->m_Position.m_X = Graphics::windowWidth - testParticle->m_Radius;
			testParticle->m_Velocity.m_X *= -1.F;
		}

		if((testParticle->m_Position.m_Y - testParticle->m_Radius) <= 0)
		{
			testParticle->m_Position.m_Y = testParticle->m_Radius;
			testParticle->m_Velocity.m_Y *= -1.F;
		}
		else if((testParticle->m_Position.m_Y + testParticle->m_Radius) >= Graphics::windowHeight)
		{
			testParticle->m_Position.m_Y = Graphics::windowHeight - testParticle->m_Radius;
			testParticle->m_Velocity.m_Y *= -1.F;
		}
	}
}
