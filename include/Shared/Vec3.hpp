#pragma once

#include <iosfwd>

namespace PikumaLessons
{
	struct Vec3
	{
	public:
		Vec3();
		Vec3(float x, float y, float z);
		explicit Vec3(float value);
		Vec3(const Vec3& other);
		Vec3(Vec3&& other) noexcept;
		~Vec3() = default;

		friend std::ostream& operator<<(std::ostream& os, const Vec3& inVec);
		Vec3& operator=(const Vec3& other);
		Vec3& operator=(Vec3&& other) noexcept;
		Vec3 operator+(const Vec3& other) const;
		Vec3 operator-(const Vec3& other) const;
		Vec3 operator*(float scalar) const;

		[[nodiscard]] float GetX() const { return m_X; }
		[[nodiscard]] float GetY() const { return m_Y; }
		[[nodiscard]] float GetZ() const { return m_Z; }
		void SetX(const float newX) { m_X = newX; }
		void SetY(const float newY) { m_Y = newY; }
		void SetZ(const float newZ) { m_Z = newZ; }

		[[nodiscard]] float Length() const;
		[[nodiscard]] float LengthSquared() const;
		[[nodiscard]] Vec3 Normalized() const;

		static float DotProduct(const Vec3& first, const Vec3& second);
		static Vec3 CrossProduct(const Vec3& first, const Vec3& second);

	private:
		float m_X;
		float m_Y;
		float m_Z;
	};
}