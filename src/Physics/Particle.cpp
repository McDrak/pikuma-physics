#include "Physics/Particle.hpp"

#include <ostream>
#include <iostream>

namespace PikumaLessons
{
	Particle::Particle(const float x, const float y, const float mass, const int radius)
		: m_Position(x, y), m_Velocity(0.F), m_Acceleration(0.F), m_Mass(mass), m_Radius(radius)
	{
		std::cout << "Particle Constructor Called!" << '\n';
	}

	Particle::Particle(const Particle& other)
		: m_Position(other.m_Position), m_Velocity(other.m_Velocity), m_Acceleration(other.m_Acceleration), m_Mass(other.m_Mass), m_Radius(other.m_Radius)
	{
		std::cout << "Particle Copy Constructor Called!" << '\n';
	}

	Particle::Particle(Particle&& other) noexcept
	: m_Position(std::move(other.m_Position)), m_Velocity(std::move(other.m_Velocity)), m_Acceleration(std::move(other.m_Acceleration)), m_Mass(other.m_Mass), m_Radius(other.m_Radius)
	{
		std::cout << "Particle Move Constructor Called!" << '\n';
	}

	Particle::~Particle()
	{
		std::cout << "Particle Destructor Called!" << '\n';
	}

	auto operator<<(std::ostream& os, const Particle& inParticle) -> std::ostream&
	{
		os << inParticle.m_Position << " " << inParticle.m_Velocity << " " << inParticle.m_Acceleration << " " << inParticle.m_Mass << " " << inParticle.m_Radius;
		return os;
	}

	auto Particle::operator=(const Particle& other) -> Particle&
	{
		m_Position = other.m_Position;
		m_Velocity = other.m_Velocity;
		m_Acceleration = other.m_Acceleration;
		m_Mass = other.m_Mass;
		m_Radius = other.m_Radius;
		return *this;
	}

	auto Particle::operator=(Particle&& other) noexcept -> Particle&
	{
		m_Position = std::move(other.m_Position);
		m_Velocity  = std::move(other.m_Velocity);
		m_Acceleration = std::move(other.m_Acceleration);
		m_Mass = other.m_Mass;
		m_Radius = other.m_Radius;
		return *this;
	}
}
