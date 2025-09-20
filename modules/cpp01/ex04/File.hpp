#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>

class File
{
public:
    File(std::string &filename, std::ios::openmode mode);
    ~File();
    void    replace(std::string old, std::string replace);
    void    readFromFile();
    void    writeToFile(const std::string &newfile);
private:
    std::string _content;
    std::fstream _file;
};

#endif
