#include <iostream>

class Printer
{
	private:
		std::string _name;
		int			_availablePaper;
	public:
		Printer(std::string name, int paper)
		{
			_name = name;
			_availablePaper = paper;
		}
		void Print(std::string txtDoc)
		{
			int	requiredPaper = txtDoc.length() / 10;
			
			if (requiredPaper > _availablePaper)
			{
				throw "...No paper";
				//throw 101;
			}
			std::cout << "Printing..." << txtDoc << std::endl;
			_availablePaper -= requiredPaper;
		}
};

int	main()
{
	Printer myPrinter("HP DekJet 1234", 10);

	try
	{
		myPrinter.Print("Hello, my name is Saldina. I am a Software Engineer.");
		myPrinter.Print("Hello, my name is Saldina. I am a Software Engineer.");
		myPrinter.Print("Hello, my name is Saldina. I am a Software Engineer.");
	}
	catch(const char *txtException)
	{
		std::cout << "Exception: " << txtException << std::endl;
	}
	catch (int exCode)
	{
		std::cout << "Exception: " << exCode << std::endl;
	}
	catch(...) //Default Handler: handles any type of throw exception 
	{
		std::cout << "Exception happened!" << std::endl;
	}
	
	return (0);
}
