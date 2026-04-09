#pragma once

#include "Physics/Particle.hpp"

#include <SDL2/SDL_rect.h>
#include "SDL2/SDL_stdinc.h"

#include <cstdint>
#include <memory>
#include <vector>

namespace PikumaLessons
{
	class Application
	{
		uint8_t m_IsRunning : 1;
		Uint32 m_TimeSincePreviousFrame;
		SDL_Rect m_LiquidRectangle;

		// Test particles
		int m_ParticlesAmount;
		std::vector<std::unique_ptr<Particle>> m_Particles;

		// Test keyboard force
		Vec2 m_KeyboardPushForce;

		void Setup();
		void Input();
		void Update();
		void Render();
		void Destroy();

	public:
		explicit Application(int testParticlesAmount);

		[[nodiscard]] auto IsRunning() const -> bool { return m_IsRunning; }

		void Run();

		void MoveTestParticle(float deltaTime, std::unique_ptr<Particle>& testParticle);
	};
}
