//Mauricio Da Graca
//Foundations .h file
//05/27/15
/*This programm will evaluate all the grades of a student and at the end will
give the studen tthe final grade and the final letterg grade.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string> 
using namespace std;

//Class for student
class Studentrecord
{
public:
	void set(string lastname, string firstname, int quiz1, int quiz2, int m, int f);
	//Pre-condition: The file has to be open and the variables inside that document 
	//has to be passed as arguments
	//Post-condition: The variables are setted to be at the private variables of the class.
	void print();
	//prints on the screen the students that will be displayed on the document.

	void percentage();
	//Pre-condition: The values of the grades have to be already set
	//Post-condition: will give the total percentage of the grade based on all the test and quizes.

	void final_letter();
	//Pre-condition: The value of the final grade should be already set
	//post condition: The useer will be abble to see the letter grade for the final.
	void print2(ofstream& output);
	//Pre-condition: All the variables are already set to be at the variablesof the class
	//Post-condition: prints the last name, first name, the two quizes, midterm, final, 
	//final average, and your letter grade

private:
	string first_name;
	string last_name;
	int quiz_one;
	int quiz_two;
	int mid_term;
	int final_exam;
	double percentage_f;
	char letter_grade;
};
