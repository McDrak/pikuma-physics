#include <iostream>

#include "Shared/Vec2.hpp"
#include "Shared/Vec3.hpp"

int main()
{
	std::cout << "Vec2" << '\n';

	const PikumaLessons::Vec2 vec(2.f, -4.f);
	const PikumaLessons::Vec2 vec2(-9.f, 15.f);

	std::cout << vec << '\n';
	std::cout << vec2 << '\n';
	std::cout << vec + vec2 << '\n';
	std::cout << vec - vec2 << '\n';
	std::cout << vec * 2.f << '\n';
	std::cout << vec.LengthSquared() << '\n';
	std::cout << vec.Length() << '\n';
	std::cout << vec.Normal() << '\n';
	std::cout << vec.Normalized() << '\n';
	std::cout << PikumaLessons::Vec2::DotProduct(vec, vec2) << '\n';
	std::cout << PikumaLessons::Vec2::CrossProduct(vec, vec2) << '\n';

	std::cout << "Vec3" << '\n';

	const PikumaLessons::Vec3 vec3(1.f, 6.f, -8.f);
	const PikumaLessons::Vec3 vec4(4.f, -2.f, -1.f);

	std::cout << vec3 << '\n';
	std::cout << vec4 << '\n';
	std::cout << vec3 + vec4 << '\n';
	std::cout << vec3 - vec4 << '\n';
	std::cout << vec3 * 2.f << '\n';
	std::cout << vec3.LengthSquared() << '\n';
	std::cout << vec3.Length() << '\n';
	std::cout << vec3.Normalized() << '\n';
	std::cout << PikumaLessons::Vec3::DotProduct(vec3, vec4) << '\n';
	std::cout << PikumaLessons::Vec3::CrossProduct(vec3, vec4) << '\n';

	return 0;
}