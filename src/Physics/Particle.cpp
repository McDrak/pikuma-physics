#include "Physics/Particle.hpp"

#include <iostream>

namespace PikumaLessons
{
	Particle::Particle(const float x, const float y, const float mass)
		: m_Position(x, y), m_Velocity(0.F), m_Acceleration(0.F), m_Mass(mass)
	{
		std::cout << "Particle Constructor Called!" << '\n';
	}

	Particle::~Particle()
	{
		std::cout << "Particle Destructor Called!" << '\n';
	}
}
