#include <iostream>
#include <array>

//T = type
//template<typename T>
//void print_array(T array)
//{
//	for (auto value : array)
//	{
//		std::cout << value << ' ';
//	}
//	std::cout << '\n';
//}

//must use --std=c++20 in the compiler (either Make file or command line)
//ie: g++ function 03.cpp -o template --std=c++20
void print_array(auto array)
{
	for (auto value : array)
	{
		std::cout << value << ' ';
	}
	std::cout << '\n';
}
int	main()
{
	std::array<int, 4> my_int_array = {1, 2, 3, 4};
//	print_array<std::array<int, 3>>(my_int_array);
	print_array(my_int_array);
	std::array<float, 3> my_float_array = {1.1f, 2.2f, 3.3f};
//	print_array<std::array<float, 3>>(my_float_array);
	print_array(my_float_array);
	return (0);
}
