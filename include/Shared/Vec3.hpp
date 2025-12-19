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

		friend auto operator<<(std::ostream& os, const Vec3& inVec) -> std::ostream&;
		auto operator=(const Vec3& other) -> Vec3&;
		auto operator=(Vec3&& other) noexcept -> Vec3&;
		auto operator+(const Vec3& other) const -> Vec3;
		auto operator-(const Vec3& other) const -> Vec3;
		auto operator*(float scalar) const -> Vec3;

		[[nodiscard]] auto GetX() const -> float { return m_X; }
		[[nodiscard]] auto GetY() const -> float { return m_Y; }
		[[nodiscard]] auto GetZ() const -> float { return m_Z; }
		void SetX(const float newX) { m_X = newX; }
		void SetY(const float newY) { m_Y = newY; }
		void SetZ(const float newZ) { m_Z = newZ; }

		[[nodiscard]] auto Length() const -> float;
		[[nodiscard]] auto LengthSquared() const -> float;
		[[nodiscard]] auto UnitVector() const -> Vec3;

		static auto DotProduct(const Vec3& first, const Vec3& second) -> float;
		static auto CrossProduct(const Vec3& first, const Vec3& second) -> Vec3;

	private:
		float m_X;
		float m_Y;
		float m_Z;
	};
}