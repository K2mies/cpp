#ifndef INTEGER_CLASS_HPP
#define INTEGER_CLASS_HPP

#include <iostream>

class Integer
{
public:
    Integer(int const n);
    ~Integer(void);

    int getValue(void);

    Integer & operator-(Integer const & rsh);
    Integer operator+(Integer const & rhs) const;
private:
    int _n;
};


std::ostream & operator<<(std::ostream & o, Integer const & rhs);
#endif
