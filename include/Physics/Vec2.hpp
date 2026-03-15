#pragma once

#include <iosfwd>

namespace PikumaLessons
{
	struct Vec2
	{
		float m_X;
		float m_Y;

		Vec2();
		Vec2(float x, float y);
		explicit Vec2(float value);
		Vec2(const Vec2& other);
		Vec2(Vec2&& other) noexcept;
		~Vec2() = default;

		friend auto operator<<(std::ostream& os, const Vec2& inVec) -> std::ostream&;
		auto operator=(const Vec2& other) -> Vec2&;
		auto operator=(Vec2&& other) noexcept -> Vec2&;
		auto operator+(const Vec2& other) const -> Vec2;
		auto operator-(const Vec2& other) const -> Vec2;
		auto operator*(float scalar) const -> Vec2;

		[[nodiscard]] auto Length() const -> float;
		[[nodiscard]] auto LengthSquared() const -> float;
		[[nodiscard]] auto Normal() const -> Vec2;
		[[nodiscard]] auto Normalize() -> Vec2&;
		[[nodiscard]] auto UnitVector() const -> Vec2;
		[[nodiscard]] auto Rotate(float angle) const -> Vec2;

		static auto DotProduct(const Vec2& first, const Vec2& second) -> float;
		static auto CrossProduct(const Vec2& first, const Vec2& second) -> float;
	};
}
