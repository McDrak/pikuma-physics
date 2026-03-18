#pragma once

#include "Physics/Particle.hpp"

#include "SDL2/SDL_stdinc.h"

#include <cstdint>
#include <memory>

namespace PikumaLessons
{
	class Application
	{
		uint8_t m_IsRunning : 1;
		std::unique_ptr<Particle> m_TestParticle;
		Uint32 m_TimeSincePreviousFrame;

	public:
		Application();

		[[nodiscard]] auto IsRunning() const -> bool;

		void Setup();
		void Input();
		void Update();
		void Render();
		void Destroy();

		void MoveTestParticle(float deltaTime);
	};
}
