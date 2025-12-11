#include <iostream>

#include "Shared/Vector.hpp"

int main()
{
	const PikumaLessons::Vec2 vec(5.f, 5.f);
	std::cout << vec.m_X << " " << vec.m_Y << '\n';
	return 0;
}