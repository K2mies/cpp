#include <iostream>

float divide(float f1, float f2)
{
	if (f1 == 0 && f2 == 0)
	{
		throw 17;
	}
	if (f2 == 0)
	{
		throw 15;
	}
	if (f1 == 0)
	{
		throw 16;
	}
	else
	{
		return (f1 / f2);
	}
}

int	main()
{
	float	f1;
	float	f2;

	std::cin >> f1;
	std::cin >> f2;
	try
	{
		std::cout << divide(f1, f2) << std::endl;
	}
	catch (int e)
	{
		if (e == 15 || e == 16)
		{
			std::cout << "Division by zero is undefined!" << std::endl;
		}
		else if (e == 17)
		{
			std::cout << "Cannot devide 0 by 0!" << std::endl;
		}
		else
		{
			std::cerr << "Error!" << std::endl;
		}	
	}

	std::cout << "TEST" << std::endl;
	return (0);
}
