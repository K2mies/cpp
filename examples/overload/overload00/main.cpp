#include "Overload00.hpp"

int	main()
{
	char const c = 'a';
	int const n = 42;
	float const z = 3.14;
	Sample	sample;
	Sample	sample_reference;

	sample.bar(c);
	sample.bar(n);
	sample.bar(z);
	sample.bar(sample_reference);

}
