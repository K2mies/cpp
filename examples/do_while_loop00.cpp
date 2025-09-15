#include <iostream>

int	main()
{
	int	work_items = 10;
	do 
	{
		std::cout << "Work items " << work_items << '\n';
		work_items--;
	}
	while (work_items > 0);
	return (0);
}
