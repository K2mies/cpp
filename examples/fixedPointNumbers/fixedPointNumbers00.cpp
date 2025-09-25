#include <iostream>


//template<size_t dp>
//constexpr int32_t	DoubleToFixed(double d)
//{
//	return int32_t(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
//}
//
//template<size_t dp>
//constexpr double FixedToDouble(int32_t d)
//{
//	return (double(d) / double(1 << dp));
//}

template<typename T, typename T2, size_t dp>
class Fixed
{
	public:
		T value = T(0);

		constexpr Fixed() = default;
		constexpr Fixed(const double d)
		{
			value = T(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
		}

		constexpr operator double() const
		{
			return double(value) / double(1 << dp);
		}
	private:
		static constexpr Fixed form(T v) {Fixed k; k.value = v; return k;}
	public:
		//Assign
		constexpr Fixed &operator = (const Fixed &f) = default;

		// Negate Unary
		constexpr Fixed operator - () const
		{
			return (form(-this->value));
		}
		
		//Addition
		constexpr	Fixed operator + (const Fixed &f) const
		{
			return (form(this->value + f.value));
		}
		// Plus equals
		constexpr Fixed &operator += (const Fixed &f)
		{
			this->value += f.value; return (*this);

		}
		//Subtraction
		constexpr	Fixed operator - (const Fixed &f) const
		{
			return (form(this->value - f.value));
		}
		// Minus equals
		constexpr Fixed &operator -= (const Fixed &f)
		{
			this->value -= f.value; return (*this);
		}
		
		//Multiplacation
		constexpr Fixed operator * (const Fixed &f) const
		{
			return (form(T2(this->value) * T2(f.value)) >> dp);
		}
		//Times equals
		constexpr Fixed &operator *= (const Fixed &f)
		{
			this->value = (T2(this->value) * T2(f.value)) >> dp; return (*this);
		}

		//Devision
		constexpr Fixed operator / (const Fixed &f) const
		{
			return (form(((T2(this->value) << dp) / T2(f.value))));
		}
		//Devision equal
		constexpr Fixed &operator /= (const Fixed &f)
		{
			this->value = ((T2(this->value) << dp) / T2(f.value)); return (*this);
		}
};

int main()
{

	using fp16_16 = Fixed<int32_t, int64_t, 16>;
	
	constexpr fp16_16 a(5.6);
	constexpr fp16_16 b(2.7);

	constexpr double z = double(a + b);

	std::cout << "z = " << z << std::endl;
//	//16.16
//	constexpr int32_t a = DoubleToFixed<16>(5.6);
//	constexpr int32_t b = DoubleToFixed<16>(2.7);
//
//	constexpr int32_t c = a + b;
//	constexpr int32_t d = a - b;
//
//	constexpr int32_t e = (int64_t(a) * int64_t(b)) >> 16;
//	constexpr int32_t f = (int64_t(a) / int64_t(b)) << 16;
//	constexpr int32_t g = (int64_t(a) << 16) / int64_t(b);
//
//	constexpr double z = FixedToDouble<16>(d);
//
//	std::cout << "a = " << FixedToDouble<16>(a) << std::endl;
//	std::cout << "b = " << FixedToDouble<16>(b) << std::endl;
//	std::cout << "a + b = " << FixedToDouble<16>(c) << std::endl;
//	std::cout << "a - b = " << FixedToDouble<16>(d) << std::endl;
//	std::cout << "a * b = " << FixedToDouble<16>(e) << std::endl;
//	std::cout << "a / b = " << FixedToDouble<16>(f) << "	(A / B * 2^16)(low precision)"<< std::endl;
//	std::cout << "a / b = " << FixedToDouble<16>(g) << "	(A * 2^16 / B)(higher precision)"<< std::endl;
	// A / B * 2^16 (not very accurate, low precision)
	// A * 2^16 / B (loses less information)

	return (0);
}
