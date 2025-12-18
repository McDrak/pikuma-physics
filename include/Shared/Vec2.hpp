#pragma once

#include <iosfwd>

namespace PikumaLessons
{
	struct Vec2
	{
	public:
		Vec2();
		Vec2(float x, float y);
		explicit Vec2(float value);
		Vec2(const Vec2& other);
		Vec2(Vec2&& other) noexcept;
		~Vec2() = default;

		friend std::ostream& operator<<(std::ostream& os, const Vec2& inVec);
		Vec2& operator=(const Vec2& other);
		Vec2& operator=(Vec2&& other) noexcept;
		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		Vec2 operator*(float scalar) const;

		[[nodiscard]] float GetX() const { return m_X; }
		[[nodiscard]] float GetY() const { return m_Y; }
		void SetX(const float newX) { m_X = newX; }
		void SetY(const float newY) { m_Y = newY; }

		[[nodiscard]] float Length() const;
		[[nodiscard]] float LengthSquared() const;
		[[nodiscard]] Vec2 Normal() const;
		[[nodiscard]] Vec2 Normalized() const;

		static float DotProduct(const Vec2& first, const Vec2& second);
		static float CrossProduct(const Vec2& first, const Vec2& second);

	private:
		float m_X;
		float m_Y;
	};
}