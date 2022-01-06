#pragma
#include<iostream>
namespace programming {
	class Complex {
	private:
		double real;
		double imaginary;
	public:
		Complex();
		Complex(double real, double imaginary);
		Complex(const Complex& other);//copy constructor
		const Complex& operator=(const Complex& other); //assignment overloading
		double getReal() const { return real; }
		double getImaginary() const { return imaginary; }
		bool operator== (const Complex &other)const;
		bool operator!= (const Complex& other)const;
		Complex operator*() const;
	};
	std::ostream& operator<<(std::ostream& out, const Complex& self);
	Complex operator+(const Complex& lhs, const Complex& rhs);
	Complex operator-(const Complex& lhs, const Complex& rhs);

}