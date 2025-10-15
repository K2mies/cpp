#include <iostream>

int	main()
{
	try
	{
		try
		{
			throw "a character exception";
		}
		catch(const char *e)
		{
			std::cout << "Character type in innter block --> " << e << std::endl;
			std::cout << "rethrowing the exception" << std::endl;
				throw;
		}
	}
	catch(const char *e)
	{
		std::cout << "Character type in outer block --> " << e << std::endl;
	}
	catch(...)
	{
		std::cout << "Unexpected exception in outer block --> " << std::endl;
	}
}
