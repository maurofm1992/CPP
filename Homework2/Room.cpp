//Mauricio Da Graca
//Homework number 2

//Libraries
#include <iostream>

//function definitions

using namespace std;
void square(double &width, double &length)
{
	cout << "Please enter the Width of the BEDROOM: ";
	cin >> width;

	//precision point.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//show the input to the user
	cout << "The width is: " << width << endl;

	cout << "Please enter the Length: ";
	cin >> length;

	//precision point.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//show the input to the user
	cout << "The width is: " << length << endl;
}

void square(float &width, float &length)
{
	
	
	cout << "Please enter the Width of the RUG: ";
	cin >> width;

	//precision point.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//show the input to the user
	cout << "The width is: " << width << endl;

	cout << "Please enter the Length: ";
	cin >> length;

	//precision point.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//show the input to the user
	cout << "The width is: " << length << endl;
}

void s_or_c(char &choose)
{
	cout << "----------------------------------------------------------" << endl;
	//promp the user to select the type of rug
	cout << "Please select one of the two shapes of the RUG:" << endl;
	cout << "'s' for Square" << endl;
	cout << "'c' for Circle" << endl;
	//get the rug from the user
	cin >> choose;
	
}
//area of the bedroom
double area(double &width, double &length)
{
	double area;
	area = width * length;
	return area;
}
//area of the rug
double area(float &width, float &length)
{
	double area;
	area = width * length;
	return area;
}
//area of the circle
double area(int &radio)
{
	double area_c, r2;
	double pi = 3.14159265;
	r2 = (radio * radio);
	area_c = pi * r2;

	return area_c;
}
int main()
{
	//variables declarations
	//_b: bedroom
	//_r: RUG
	//_c: circle
	double width_b, length_b;
	float width_r, length_r;
	char decision;
	double area_b, area_r, area_c;
	double percentage;
	int diameter , radio;

	cout << "Hello." << endl;
	cout << "*************************************************" << endl;

	square (width_b, length_b);

	area_b = area(width_b, length_b);
	cout << "The area of the room is: " << area_b << endl;

	s_or_c(decision);

	while (decision != 's' && decision != 'c')
	{
		cout << "ERROR. Please enter a valid option:" << endl;
		cin >> decision;
	}

	//if the user enters square
	if (decision == 's')
	{
		cout << "*************************************************" << endl;
		cout << "The type of rug is SQUARE." << endl;
		square(width_r, length_r);
		
		if (width_b < width_r)
		{
			cout << "*************************************************" << endl;
			cout << "ERROR. The width of the RUG is not going to fit in the BEDROOM." << endl;
			return 0;
		}
		else if (length_b < length_r)
		{
			cout << "*************************************************" << endl;
			cout << "ERROR. The length of the RUG is not going to fit in the BEDROOM." << endl;
			return 0;
		}

		area_r = area(width_r, length_r);
		
		cout << "---------------------------------------------------------------------" << endl;
		percentage = (area_r * 100) / area_b;
		cout << "The percentage of the room covered is =  %" << percentage << endl;
	}

	//if the user enters circle
	else if (decision == 'c')
	{
		cout << "*************************************************" << endl;
		cout << "The type of rug is a CIRCLE" << endl;
		cout << "Please enter the Diameter" << endl;
		cin >> diameter;

		if (diameter > width_b)
		{
			cout << "*************************************************" << endl;
			cout << "Sorry the diameter of the rug is bigger than the Width of the bedroom." << endl;
			return 0;
		}
		
		else if (diameter > length_b)
		{
			cout << "*************************************************" << endl;
			cout << "Sorry the diameter of the rug is bigger than the Length of the bedroom." << endl;
			return 0;
		}
		
		radio = diameter / 2;
		area_c = area (radio);
		cout << "The area of the circle is = " << area_c << endl;
		
		cout << "---------------------------------------------------------------------" << endl;
		percentage = (area_c * 100) / area_b;
		cout << "The percentage of the room covered is = " << percentage << "%" <<endl;

	}





}

