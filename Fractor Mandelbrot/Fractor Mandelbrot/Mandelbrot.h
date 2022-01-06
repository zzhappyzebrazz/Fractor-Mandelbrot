#pragma once
#include <complex>

namespace programming {
	class Mandelbrot
	{
	public:
		static const int MAX_ITERATOR = 1500;

	public:
		Mandelbrot();
		virtual ~Mandelbrot();
		static int getIterators(double x, double y);
	};

}

