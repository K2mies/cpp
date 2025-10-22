#include <iostream>
#include <iomanip>

int	main()
{
	bool b = 35;
	std::cout << "bool of 35 =: " << b << std::endl;
	int	i = b;
	std::cout << "int i =: " << i << std::endl;
	i = 3.14;
	std::cout << "int i =: " << i << std::endl;
	double pi = i;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double pi =: " << pi << std::endl;
	unsigned char c = -1;
	std::cout << "unsigned char c=: " << c << std::endl;
	unsigned int u = -1;
	std::cout << "unsigned int u=: " << u << std::endl;
	return (0);
}
