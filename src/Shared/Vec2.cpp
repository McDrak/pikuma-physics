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

	auto operator<<(std::ostream& os, const Vec2& inVec) -> std::ostream&
	{
		os << inVec.GetX() << " " << inVec.GetY();
		return os;
	}

	auto Vec2::operator=(const Vec2& other) -> Vec2&
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		return *this;
	}

	auto Vec2::operator=(Vec2&& other) noexcept -> Vec2&
	{
		m_X = other.GetX();
		m_Y = other.GetY();
		return *this;
	}

	auto Vec2::operator+(const Vec2& other) const -> Vec2
	{
		return { m_X + other.GetX(), m_Y + other.GetY() };
	}

	auto Vec2::operator-(const Vec2& other) const -> Vec2
	{
		return { m_X - other.GetX(), m_Y - other.GetY() };
	}

	auto Vec2::operator*(const float scalar) const -> Vec2
	{
		return { m_X * scalar, m_Y * scalar };
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
		return { m_Y, -m_X };
	}

	auto Vec2::UnitVector() const -> Vec2
	{
		const float newX = std::abs(m_X / Length());
		const float newY = std::abs(m_Y / Length());
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
		return (first.GetX() * second.GetY()) - (first.GetY() * second.GetX());
	}
}