#include "Shared/Vector.hpp"

#include <complex>

namespace PikumaLessons
{
	Vec2::Vec2()
		: m_X(0.f), m_Y(0.f)
	{
	}

	Vec2::Vec2(const float x, const float y)
		: m_X(x), m_Y(y)
	{
	}

	Vec2::Vec2(const Vec2& other)
		: m_X(other.GetX()), m_Y(other.GetY())
	{
	}

	Vec2::Vec2(Vec2&& other) noexcept
		: m_X(other.GetX()), m_Y(other.GetY())
	{
	}

	Vec2& Vec2::operator=(const Vec2& other)
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		return *this;
	}

	Vec2& Vec2::operator=(Vec2&& other) noexcept
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		return *this;
	}

	Vec2 Vec2::operator+(const Vec2& other) const
	{
		return { m_X + other.GetX(), m_Y + other.GetY() };
	}

	Vec2 Vec2::operator-(const Vec2& other) const
	{
		return { m_X - other.GetX(), m_Y - other.GetY() };
	}

	Vec2 Vec2::operator*(const float scalar) const
	{
		return { m_X * scalar, m_Y * scalar };
	}

	float Vec2::Length() const
	{
		return std::sqrt(LenghtSquared());
	}

	float Vec2::LenghtSquared() const
	{
		return (m_X * m_X) + (m_Y * m_Y);
	}
}