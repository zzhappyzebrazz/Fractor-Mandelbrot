#include "Mandelbrot.h"
programming::Mandelbrot::Mandelbrot()
{
}
programming::Mandelbrot::~Mandelbrot()
{
}
int programming::Mandelbrot::getIterators(double x, double y)
{
	std::complex<double> z = 0;
	std::complex<double> c(x, y);
	int iterators = 0;
	while (iterators < MAX_ITERATOR) {
		z = z * z + c;



		if (abs(z) > 2) //Mandelbrot has a set of z and c that make a rule, abs(z) will not be greater than 2
		{
			break;//break the Mandelbrot rule
		}

		iterators++;
	}
	return iterators;
}
