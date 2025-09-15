#include <iostream>
#include <memory>

int	main()
{
//	std::shared_ptr<int[]> ptr1(new int[10]);
	auto ptr1 = std::make_shared<int[]>(10);
	auto ptr2 = ptr1;
	std::cout << "Reference count: " << ptr2.use_count() << '\n';
	return (0);
}
