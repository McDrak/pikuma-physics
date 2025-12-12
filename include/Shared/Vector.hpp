#pragma once

namespace PikumaLessons
{
	struct Vec2
	{
	public:
		Vec2();
		Vec2(float x, float y);
		Vec2(const Vec2& other);
		Vec2(Vec2&& other) noexcept;
		~Vec2() = default;

		Vec2& operator=(const Vec2& other);
		Vec2& operator=(Vec2&& other) noexcept;
		Vec2 operator+(const Vec2& other) const;
		Vec2 operator-(const Vec2& other) const;
		Vec2 operator*(float scalar) const;

		[[nodiscard]] float GetX() const { return m_X; }
		[[nodiscard]] float GetY() const { return m_Y; }
		void SetX(const float x) { m_X = x; }
		void SetY(const float y) { m_Y = y; }

		float Length() const;
		float LenghtSquared() const;

	private:
		float m_X;
		float m_Y;
	};
}