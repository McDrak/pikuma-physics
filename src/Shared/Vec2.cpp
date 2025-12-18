#include "Shared/Vec2.hpp"

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

	Vec2::Vec2(const float value)
		: m_X(value), m_Y(value)
	{
	}

	Vec2::Vec2(const Vec2& other)
		: m_X(other.GetX()), m_Y(other.GetY())
	{
	}

	Vec2::Vec2(Vec2&& other) noexcept
		: m_X(other.GetX()),
		  m_Y(other.GetY())
	{
	}

	std::ostream& operator<<(std::ostream& os, const Vec2& inVec)
	{
		os << inVec.GetX() << " " << inVec.GetY();
		return os;
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
		return std::sqrt(LengthSquared());
	}

	float Vec2::LengthSquared() const
	{
		return (m_X * m_X) + (m_Y * m_Y);
	}

	Vec2 Vec2::Normal() const
	{
		return { m_Y, -m_X };
	}

	Vec2 Vec2::Normalized() const
	{
		const float newX = std::abs(m_X / Length());
		const float newY = std::abs(m_Y / Length());
		return { newX, newY };
	}

	float Vec2::DotProduct(const Vec2& first, const Vec2& second)
	{
		return (first.m_X * second.m_X) + (first.m_Y * second.m_Y);
	}

	float Vec2::CrossProduct(const Vec2& first, const Vec2& second)
	{
		return (first.GetX() * second.GetY()) - (first.GetY() * second.GetX());
	}
}