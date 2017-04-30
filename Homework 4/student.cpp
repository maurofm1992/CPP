//Mauricio Da Graca
//Foundations main file
//05/27/15
/*This programm will evaluate all the grades of a student and at the end will
give the studen tthe final grade and the final letterg grade.
*/

#include "student.h"


void Studentrecord::set(string lastname, string firstname, int quiz1, int quiz2, int m, int f)
{

	last_name = lastname;
	first_name = firstname;
	quiz_one = quiz1;
	quiz_two = quiz2;
	mid_term = m;
	final_exam = f;
}

void Studentrecord::print()
{

	cout << first_name << " " << last_name << endl;
	cout << "Quiz#1 = " << quiz_one << endl;
	cout << "Quiz#2 = " << quiz_two << endl;
	cout << "Midterm = " << mid_term << endl;
	cout << "Final = " << final_exam << endl;
	cout << endl;

}

void Studentrecord::percentage()
{
	double quiz25;
	double quiz25p;
	double midterm25p;
	double finalp50;

	//Calculations for all the test and quizes
	quiz25 = (quiz_one + quiz_two) / 2;
	quiz25p = quiz25 * .25;

	midterm25p = mid_term * .25;

	finalp50 = final_exam * .50;

	//The final grade

	//precision point.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	percentage_f = (quiz25p + midterm25p + finalp50);
	cout << "The final grade is: " << percentage_f << endl;
}


void Studentrecord::final_letter()
{
	if (percentage_f >= 90)
	{
		letter_grade = 'A';
	}

	else if (percentage_f <= 89 || percentage_f >= 80)
	{
		letter_grade = 'B';
	}

	else if (percentage_f <= 79 || percentage_f >= 70)
	{
		letter_grade = 'C';
	}

	else if (percentage_f <= 69 || percentage_f >= 60)
	{
		letter_grade = 'D';
	}

	else
		letter_grade = 'F';

	cout << "Your letter grade is = " << letter_grade << endl;
	cout << endl;
}

void Studentrecord::print2(ofstream& output)
{

	output << last_name << " " << first_name << " "
		<< quiz_one << " " << quiz_two << " " << mid_term
		<< " " << final_exam << "--" << percentage_f << " " << letter_grade << endl;
	cout << endl;


}