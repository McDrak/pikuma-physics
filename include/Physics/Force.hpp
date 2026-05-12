#pragma once

#include "Physics/Particle.hpp"

namespace PikumaLessons
{
	struct Force
	{
		static auto GetDragForce(const Particle& particle, float k) -> Vec2;
		static auto GetFrictionForce(const Particle& particle, float k) -> Vec2;
	};
}
