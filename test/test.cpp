#include "Application.hpp"

int main()
{
	constexpr int testParticlesAmount = 5;
	PikumaLessons::Application app(testParticlesAmount);
	app.Run();

	return 0;
}
