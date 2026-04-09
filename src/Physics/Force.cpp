#include "Physics/Force.hpp"

namespace PikumaLessons
{
	auto Force::GetDragForce(const Particle& particle, const float k) -> Vec2
	{
		if(particle.m_Velocity.LengthSquared() <= 0.F)
		{
			return { 0.F, 0.F };
		}

		const Vec2 dragDirection = particle.m_Velocity.UnitVector() * -1.F;
		const float dragMagnitude = k * particle.m_Velocity.LengthSquared();

		return dragDirection * dragMagnitude;
	}
}
