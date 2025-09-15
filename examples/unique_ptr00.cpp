#include <iostream>
#include <memory>

int	main()
{
//	std::unique_ptr<int[]> ptr(new int[10]);
	auto ptr = std::make_unique<int[]>(10);
	for(int i = 0; i < 10; i++)
	{
		ptr[i] = i * i;
	}
//	std::cout << ptr[4] << '\n';
//	std::cout << ptr[7] << '\n';
	for(int i = 0; i < 10; i++)
	{
		std::cout << i << '\n';
	}
	return (0);
}
