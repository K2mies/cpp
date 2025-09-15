#include <iostream>
#include <array>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "no arguments";
    else
    {
        for(int i = 1; i < argc; i++)
        {
            std::string str = argv[i];
            for (auto &letter : str)
            {
                letter = std::toupper(letter);
            }
            std::cout << str;
            if (i != argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return (0);
}
