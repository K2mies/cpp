#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_rawBits;
		static const int _bits = 8;

	public:
	//Constructors
		// Default Constructor
		Fixed(void);
		// takes const int as parameter
		Fixed(const int raw);
		// takes const float as parameter
		Fixed(const float raw);
	//Destructors
		~Fixed();

	// copying - create new object, as const
		//taking the getBits and copying it into the new instance
		Fixed(Fixed const &src);
	//operator overloading
		//assignment - operator overload where we say how does '=' work
		Fixed &operator=(Fixed const &rhs);
	//Member functions
		//GET
		int	getRawBits(void) const;
		//SET
		void	setRawBits(int const raw);
	//Conversion
		float	toFloat(void) const;
		int		toInt(void) const;	
};

//output - operator overload where we say how does the '<<' work
std::ostream &operator<<(std::ostream &stream, Fixed const &f);

#endif
