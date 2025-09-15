#include <iostream>

int	main()
{
	int	*int_ptr = new int[10];
	int_ptr[3] = 241;
	std::cout << "Value " << int_ptr[3] << '\n';
	std::cout << "Address " << &int_ptr[3] << '\n';
	// the [] brakets indicate that an array needs to be freed
	// and not just an individual element.
	delete[] int_ptr;
	return (0);
}
