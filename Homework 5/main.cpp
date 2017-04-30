// Mauricio Da Graca	
// Foundations 
// 05/31/2015
// Homework 5
/*In this homework we will define class	for rational numbers1.
Represent rational numbers as two values of type int,
one for the numerator and one for the denominator.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "Rational1.h"

using namespace std;




int main()
{
	Rational a(3, 5); //a = 3/5
	Rational b(5); //b = 5/1
	Rational c; // c = 0/1     
	Rational d = a + b;
	Rational e, f, g, h, i, j, k;

	cout << "This is to test the Constructors." << endl;

	//test the constructors
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "Enter a rational number: ";
	cin >> e;

	cout << "e = " << e << endl << endl;

	//TEST THE IMPLEMENTATION
	cout << "Test the implementations." << endl << endl;

	f = -a; // f = - 1/2      

	if (a < d)
	{
		g = e - a;
	}

	if (f == (-a))
	{
		h = a * d; // h = 7/4     
	}

	if (h > c)
	{
		i = a / b; // i = 1/6    
	}

	if (a <= d)
	{
		j = i - c; // j = 1/6     
	}

	if (d >= c)
	{
		k = 2 * a + b - (c / d); // k = 4    
	}

	//Show the results after the operations.
	cout << "These are my rational numbers..." << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "f = " << f << endl;
	cout << "g = " << g << endl;
	cout << "h = " << h << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << k << endl;

	return 0;

}

