#include "Physics/Vec2.hpp"

#include <cmath>
#include <ostream>
#include <iostream>

namespace PikumaLessons
{
	Vec2::Vec2()
		: m_X(0.F), m_Y(0.F)
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
		: m_X(other.m_X), m_Y(other.m_Y)
	{
	}

	Vec2::Vec2(Vec2&& other) noexcept
		: m_X(other.m_X),
		  m_Y(other.m_Y)
	{
	}

	auto operator<<(std::ostream& os, const Vec2& inVec) -> std::ostream&
	{
		os << inVec.m_X << " " << inVec.m_Y;
		return os;
	}

	auto Vec2::operator=(const Vec2& other) -> Vec2&
	{
		m_X = other.m_X;
		m_Y = other.m_Y;
		return *this;
	}

	auto Vec2::operator=(Vec2&& other) noexcept -> Vec2&
	{
		m_X = other.m_X;
		m_Y = other.m_Y;
		return *this;
	}

	auto Vec2::operator+(const Vec2& other) const -> Vec2
	{
		return { m_X + other.m_X, m_Y + other.m_Y };
	}

	auto Vec2::operator-(const Vec2& other) const -> Vec2
	{
		return { m_X - other.m_X, m_Y - other.m_Y };
	}

	auto Vec2::operator*(const float scalar) const -> Vec2
	{
		return { m_X * scalar, m_Y * scalar };
	}

	auto Vec2::operator/(float scalar) const -> Vec2
	{
		return { m_X / scalar, m_Y / scalar };
	}

	auto Vec2::operator+=(const Vec2& other) -> Vec2&
	{
		m_X += other.m_X;
		m_Y += other.m_Y;
		return *this;
	}
	auto Vec2::operator-=(const Vec2& other) -> Vec2&
	{
		m_X -= other.m_X;
		m_Y -= other.m_Y;
		return *this;
	}

	auto Vec2::operator*=(float scalar) -> Vec2&
	{
		m_X *= scalar;
		m_Y *= scalar;
		return *this;
	}

	auto Vec2::operator/=(float scalar) -> Vec2&
	{
		m_X /= scalar;
		m_Y /= scalar;
		return *this;
	}

	auto Vec2::Length() const -> float
	{
		return std::sqrt(LengthSquared());
	}

	auto Vec2::LengthSquared() const -> float
	{
		return (m_X * m_X) + (m_Y * m_Y);
	}

	auto Vec2::Normal() const -> Vec2
	{
		Vec2 newNormal = { m_Y, -m_X };
		return newNormal.Normalize();
	}

	auto Vec2::Normalize() -> Vec2&
	{
		const float vecLength = Length();
		if(vecLength != 0.F)
		{
			m_X /= vecLength;
			m_Y /= vecLength;
		}

		return *this;
	}

	auto Vec2::UnitVector() const -> Vec2
	{
		const float vecLength = Length();
		if(vecLength == 0.F)
		{
			return { 0.F, 0.F };
		}

		const float newX = m_X / vecLength;
		const float newY = m_Y / vecLength;

		return { newX, newY };
	}

	auto Vec2::Rotate(const float angle) const -> Vec2
	{
		const float newX = (m_X * std::cos(angle)) - (m_Y * std::sin(angle));
		const float newY = (m_X * std::sin(angle)) + (m_Y * std::cos(angle));

		return { newX, newY };
	}

	auto Vec2::DotProduct(const Vec2& first, const Vec2& second) -> float
	{
		return (first.m_X * second.m_X) + (first.m_Y * second.m_Y);
	}

	auto Vec2::CrossProduct(const Vec2& first, const Vec2& second) -> float
	{
		return (first.m_X * second.m_Y) - (first.m_Y * second.m_X);
	}
}
