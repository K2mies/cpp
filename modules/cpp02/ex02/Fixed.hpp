#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{

private:
// PIRVATE MEMBER VARIABLES============================================*
	int	_rawBits;
	static const int _bits = 8;
public:
// CONSTRUCTION========================================================*
	// default constructor
		Fixed(void);
	// takes const int as parameter
		Fixed(const int raw);
	// takes const  float as a parameter
		Fixed(const float raw);
// COPYING=============================================================*
	// taking the getBits and copying it into a new instance
		Fixed(Fixed const &src);
// DESTRUCTION=========================================================*
	// Destructor
		~Fixed();
// OPERATOR OVERLOADING================================================*
	// assignment - operator overload where we say how does '=' work
		Fixed &operator=(Fixed const &rhs);
// COMPARASON OPERATORS================================================*
		bool operator	>	(const Fixed &rh)	const;
		bool operator	<	(const Fixed &rh)	const;
		bool operator	>=	(const Fixed &rh)	const;
		bool operator	<=	(const Fixed &rh)	const;
		bool operator	==	(const Fixed &rh)	const;
		bool operator	!=	(const Fixed &rh)	const;
// ARITHMETIC OPERATORS================================================*
		Fixed operator	+	(const Fixed &rhs)	const;
		Fixed operator	-	(const Fixed &rhs)	const;
		Fixed operator	*	(const Fixed &rhs)	const;
		Fixed operator	/	(const Fixed &rhs)	const;
// INCREMENT AND DECREMENT OPERATORS===================================*
		Fixed &operator	++(void);			// prefix
		Fixed &operator	--(void);			// prefix
		Fixed operator	++(int);			// postfix
		Fixed operator	--(int);			// postfix
// MEMBER FUNCTIONS====================================================*
	// GETTERS/SETTERS=================================================*
	//GET
		int		getRawBits(void) const;
	//SET
		void	setRawBits(int const raw);
	// CONVERSION======================================================*
		float	toFloat(void)	const;
		int		toInt(void)		const;
	// STATIC MIN/MAX==================================================*
		static	Fixed &min(Fixed &a, Fixed &b);
		static	Fixed &max(Fixed &a, Fixed &b);
		static	Fixed const &min(Fixed const &a, Fixed const &b);
		static	Fixed const &max(Fixed const &a, Fixed const &b);
};

// OUTPUT OPERATOR OVERLOAD============================================*
/*output - operator overload where we say how does '<<' work*/
std::ostream &operator<<(std::ostream &stream, Fixed const &f);
#endif
