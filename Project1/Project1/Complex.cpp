#include "Complex.h"

namespace programming {
	Complex::Complex() : real(0), imaginary(0) {
		//TODO 
	}
	Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {
	}
	Complex::Complex(const Complex& other) {//copy constructor
		std::cout << "Copy\n" << std::flush;
		real = other.real;
		imaginary = other.imaginary;
	}
	const Complex& Complex::operator=(const Complex& other)
	{
		// TODO: insert return statement here
		real = other.real;
		imaginary = other.imaginary;
		std::cout << "Assignment\n" << std::flush;
		return *this;
	}
	std::ostream& operator<<(std::ostream& out, const Complex& self)
	{
		// TODO: insert return statement here
		std::cout << "(" << self.getReal() << ", " << self.getImaginary() << ")";
		return out;
	}
	Complex operator+(const Complex& lhs, const Complex& rhs)
	{

		return Complex(lhs.getReal() + rhs.getReal(), lhs.getImaginary() + rhs.getImaginary());
	}
	Complex operator-(const Complex& lhs, const Complex& rhs)
	{
		return Complex(lhs.getReal() - rhs.getReal(), lhs.getImaginary() - rhs.getImaginary());
	}
	bool Complex::operator==(const Complex&other) const
	{
	/*	if (this->getReal() == other.getReal() && this->getImaginary() == other.getImaginary())
			return true;
		else return false;*/
		return real == other.getReal() && imaginary == other.getImaginary();
	}
	bool Complex::operator!=(const Complex& other) const
	{
		return real != other.getReal() && imaginary != other.getImaginary();
	}
	Complex Complex::operator*() const
	{
		return Complex(real, -imaginary);
	}
}