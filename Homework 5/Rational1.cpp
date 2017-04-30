//Mauricio Da Graca
//foundations
//Homework 5

#include "Rational1.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string> 

ostream& operator<< (ostream& x, const Rational& y)
{
	x << "(" << y.first << ", " << y.second << ")";
	return x;
}

istream& operator>> (istream& ins, Rational& z)
{
	int real, imaginary;
	char slash;

	ins >> real;

	//get the back slide from the user.
	ins >> slash;

	while (slash != '/') //complex number must have a back slide next 
		//if not, let the user know hot to input
	{
		cout << "\nWrong way of input."
			<< "The correct input should be: x/z.";
		ins >> slash;
	}

	//now get the imaginary part
	ins >> imaginary;


	z = Rational(real, imaginary);
	return ins;
}

int imag(const Rational& a)
{
	return a.imag();
}

int real(const Rational& a)
{
	return a.real();
}

Rational operator + (const Rational& a, const Rational& b)
{
	return Rational((real(a) * imag(b) + imag(a) * real(b)) / (imag(a) * imag(b)));
}

Rational operator - (const Rational& a, const Rational& b)
{
	return Rational((real(a) * imag(b) - imag(a) * real(b)) / (imag(a) * imag(b)));
}

Rational operator * (const Rational& a, const Rational& b)
{
	return Rational((real(a) * real(b)) / (imag(a) * imag(b)));
}

Rational operator / (const Rational& a, const Rational& b)
{
	return Rational((real(a) * imag(b)) / real(b) * imag(a));
}
bool operator <= (const Rational& a, const Rational& b)
{
	return (real(a) * imag(b)) <= (real(b) * imag(a));
}

bool operator < (const Rational& a, const Rational& b)
{
	return (real(a) * imag(b)) < (real(b) * imag(a));
}

bool operator >= (const Rational& a, const Rational& b)
{
	return (real(a) * imag(b)) >= (real(b) * imag(a));
}

bool operator > (const Rational& a, const Rational& b)
{
	return (real(a) * imag(b)) > (real(b) * imag(a));
}

bool operator == (const Rational& a, const Rational& b)
{
	return (real(a) * imag(b) == (real(b) * imag(a)));
}

Rational operator - (const Rational& a)
{
	return (-(real(a) && imag(a)) == (-real(a) && imag(a)));
}