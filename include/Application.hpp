#pragma once
#include <cstdint>

namespace PikumaLessons
{
	class Application
	{
	public:
		Application();
		~Application() = default;

		[[nodiscard]] auto IsRunning() const -> bool;
		void Setup();
		void Input();
		void Update();
		void Render();
		void Destroy();

	private:
		uint8_t m_IsRunning : 1;
	};
}