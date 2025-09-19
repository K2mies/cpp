#include <iostream>

int	main()
{
	int	a = 1;
	int	b = 2;
	int	&ref = a;
	ref = b;
	std::cout << "a is : " << a << std::endl;
	std::cout << "b is : " << b << std::endl;
}
