//Mauricio Da Graca
//foundations
//Homework 5

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string> 
using namespace std;

class Rational
{
public:

	Rational(int a, int b) : first(a), second(b) { }
	Rational(int whole_number) : first(whole_number), second(1) { }
	Rational() : first(0), second(1) { }

	int real() const { return first; }
	int imag() const { return second; }

private:

	int first, second;

	friend int real(const Rational&);
	friend int imag(const Rational&);

	// istream and ostream overload operators.
	friend istream& operator>> (istream&, Rational&);
	friend ostream& operator<< (ostream&, const Rational&);

	//mathematical functions
	friend Rational operator + (const Rational&, const Rational&);
	friend Rational operator - (const Rational&, const Rational&);
	friend Rational operator * (const Rational&, const Rational&);
	friend Rational operator / (const Rational&, const Rational&);
	friend bool operator <= (const Rational&, const Rational&);
	friend bool operator < (const Rational&, const Rational&);
	friend bool operator >= (const Rational&, const Rational&);
	friend bool operator > (const Rational&, const Rational&);
	friend bool operator == (const Rational&, const Rational&);
	friend Rational operator - (const Rational&);
};