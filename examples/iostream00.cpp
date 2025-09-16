#include <iostream>
#include <string>

int main()
{
   // char    buf[510];
    std::string buf;

    std::cout << "Hello world!" << std::endl;

    std::cout << "input a word: ";
    //   std::cin >> buf;
    std::getline(std::cin, buf);
    std::cout << "you entered [" << buf << "]" << std::endl;
    return (0);
}
