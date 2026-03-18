#pragma once

#include "Physics/Vec2.hpp"

namespace PikumaLessons
{
	struct Particle
	{
		Vec2 m_Position;
		Vec2 m_Velocity;
		Vec2 m_Acceleration;
		float m_Mass;

		Particle(float x, float y, float mass);
		~Particle();
	};
}
