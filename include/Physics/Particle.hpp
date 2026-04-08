#pragma once

#include "Physics/Vec2.hpp"

namespace PikumaLessons
{
	struct Particle
	{
		Vec2 m_Position;
		Vec2 m_Velocity;
		Vec2 m_Acceleration;
		Vec2 m_ForcesSum;
		float m_Mass;
		float m_InvMass;
		// Temporal Testing Radius
		int m_Radius;

		explicit Particle(float x, float y, float mass, int radius);
		Particle(const Particle& other);
		Particle(Particle&& other) noexcept;
		~Particle();

		friend auto operator<<(std::ostream& os, const Particle& inParticle) -> std::ostream&;
		auto operator=(const Particle& other) -> Particle&;
		auto operator=(Particle&& other) noexcept -> Particle&;

		void AddForce(const Vec2& force);
		void ClearForces();
		// Integration of the acceleration and velocty to find the new position, using the Euler technique
		void Integrate(float deltaTime);
	};
}
