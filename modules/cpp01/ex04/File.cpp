#include "File.hpp"


//Constructor
File::File(std::string &filename, std::ios::openmode mode)
{
    _file.open(filename, mode);
    if (!_file.is_open())
    {
        std::cerr << "Error: Could not open " << filename << " for reading." << std::endl;
    }
}

//Destructor
File::~File()
{
    _file.close();
}

//Public Member Functions
void    File::replace(std::string old, std::string replace)
{
    std::size_t pos = 0;

    while ((pos = _content.find(old, pos)) != std::string::npos)
    {
        _content.erase(pos, old.length());
        _content.insert(pos, replace);
        pos += replace.length();
    }
}

void    File::writeToFile(const std::string &newfile)
{
    std::ofstream outfile(newfile);
    if(!outfile)
    {
        std::cerr << "Error: could not open or create " << newfile << " for writing." << std::endl;
    }
    outfile << _content;
    outfile.close();
}

void    File::readFromFile()
{
    std::string line;

    while (std::getline(_file, line))
    {
        _content += line + "\n";

    }
}

