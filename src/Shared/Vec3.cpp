#include "Shared/Vec3.hpp"

#include <complex>

namespace PikumaLessons
{
	Vec3::Vec3()
		: m_X(0.0f), m_Y(0.0f), m_Z(0.0f)
	{
	}

	Vec3::Vec3(const float x, const float y, const float z)
		: m_X(x), m_Y(y), m_Z(z)
	{
	}

	Vec3::Vec3(const float value)
		: m_X(value), m_Y(value), m_Z(value)
	{
	}

	Vec3::Vec3(const Vec3& other)
		: m_X(other.GetX()), m_Y(other.GetY()), m_Z(other.GetZ())
	{
	}

	Vec3::Vec3(Vec3&& other) noexcept
		: m_X(other.GetX()), m_Y(other.GetY()), m_Z(other.GetZ())
	{
	}

	auto operator<<(std::ostream& os, const Vec3& inVec) -> std::ostream&
	{
		os << inVec.GetX() << " " << inVec.GetY() << " " << inVec.GetZ();
		return os;
	}

	auto Vec3::operator=(const Vec3& other) -> Vec3&
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		m_Z = other.GetZ();
		return *this;
	}

	auto Vec3::operator=(Vec3&& other) noexcept -> Vec3&
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		m_Z = other.GetZ();
		return *this;
	}

	auto Vec3::operator+(const Vec3& other) const -> Vec3
	{
		return { m_X + other.m_X, m_Y + other.m_Y, m_Z + other.m_Z };
	}

	auto Vec3::operator-(const Vec3& other) const -> Vec3
	{
		return { m_X - other.m_X, m_Y - other.m_Y, m_Z - other.m_Z };
	}

	auto Vec3::operator*(const float scalar) const -> Vec3
	{
		return { m_X * scalar, m_Y * scalar, m_Z * scalar };
	}

	auto Vec3::Length() const -> float
	{
		return std::sqrt(LengthSquared());
	}

	auto Vec3::LengthSquared() const -> float
	{
		return (m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z);
	}

	auto Vec3::UnitVector() const -> Vec3
	{
		const float newX = std::abs(m_X / Length());
		const float newY = std::abs(m_Y / Length());
		const float newZ = std::abs(m_Z / Length());
		return { newX, newY, newZ };
	}

	auto Vec3::DotProduct(const Vec3& first, const Vec3& second) -> float
	{
		return (first.GetX() * second.GetX()) + (first.GetY() * second.GetY()) + (first.GetZ() * second.GetZ());
	}

	auto Vec3::CrossProduct(const Vec3& first, const Vec3& second) -> Vec3
	{
		const float newX = (first.GetY() * second.GetZ()) - (first.GetZ() * second.GetY());
		const float newY = (first.GetZ() * second.GetX()) - (first.GetX() * second.GetZ());
		const float newZ = (first.GetX() * second.GetY()) - (first.GetY() * second.GetX());
		return { newX, newY, newZ };
	}
}