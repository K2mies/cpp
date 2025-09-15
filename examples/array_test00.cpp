#include <array>
#include <iostream>

int main()
{
	std::array<int, 3> my_array = {45, 23, 3};
//	std::array<int, 3> my_array{45, 23, 3}; //(also valid)
//	my_array.fill(10);
//	std::cout << my_array[1] << '\n';
	std::cout << my_array.size() << '\n';
	
	return (0);
}
