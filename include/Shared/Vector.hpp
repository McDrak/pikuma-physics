#pragma once

namespace PikumaLessons
{
	struct Vec2
	{
	public:
		Vec2()
			: m_X(0.f), m_Y(0.f)
		{
		}

		Vec2(const float x, const float y)
			: m_X(x), m_Y(y)
		{
		}

	private:
		float m_X;
		float m_Y;
	};
}