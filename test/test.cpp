#include <iostream>

#include "Shared/Vector.hpp"

int main()
{
	const PikumaLessons::Vec2 vec(5.f, 5.f);
	std::cout << vec.GetX() << " " << vec.GetY() << '\n';
	return 0;
}