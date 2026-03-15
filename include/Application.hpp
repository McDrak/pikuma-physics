#pragma once
#include <cstdint>

namespace PikumaLessons
{
	class Application
	{
		uint8_t m_IsRunning : 1;

	public:
		Application();

		[[nodiscard]] auto IsRunning() const -> bool;

		void Setup();
		void Input();
		void Update();
		void Render();
		void Destroy();
	};
}
