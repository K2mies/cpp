#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
//Using the orthodox canonical form we define various behaviour to creating the object

class Fixed
{
	public:
	//Orthodox canonical form-----------------------------------------
	//default constructor
		Fixed(void);
		
	//destructor
		~Fixed();

	//copy constructor: Creates a new object, as const
	//taking the getBits and copying it into the new instance/object
		Fixed(Fixed const &src);

	//Assignment - operator overload where we are saying how "=" works
	//rhs = right hand side
		Fixed &operator=(Fixed const &rhs);

	// Getters and setters---------------------------------------------
	// getter
		int	getRawBits(void) const;
	
	// setter
		void setRawBits(int const raw);

	private:
		int	_rawBits;
		static const int _bits = 8;
};

#endif
