#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct record {
	string name;
	string street;
	string city;
	string state;
	string zip;
};

// Returns true if tofind is a substring of str.
// Will return false if tofind is empty.
bool contains(string str, string tofind);

//Pre-condition: the contacts should be already store in the structure.
//Post-condition: The contatcs are shown in the screen for the user.
void print_list(record s[], int size);

//Pre-condition: The desire city that is going to be searched for is already declared and initialized.
//Post-condition: Shows the addresses of only the ones that have the targeted address.
void find_address(record s[], string target_city, int size);

//Pre-condition: The desire zip range is already declared and initialized.
//Post-condition: shows the range of the zip codes that are inside the address book.
void find_in_zip_range(record s[], string beggining, string end, int size);


int main()
{
	// Create data structure to store customer information (up to 100 addresses)
	record customer_list[100];

	string xml_file;
	xml_file = "address.xml";
	ifstream doc_input;
	string line;
	unsigned int pos = 0;
	//Variables that are the target in the program
	string city = "Davie";
	string zip_one = "33310";
	string zip_two = "33320";
	// Read XML file
	doc_input.open(xml_file);
	if (doc_input.fail())
	{
		cout << "Could not open input file" << endl;
		exit(1);
	}

	// Parse XML file and populate address book
	while (!doc_input.eof())
	{
		getline(doc_input, line);
		while ((!contains(line, "address_book")) &&
			(!contains(line, "contact")))
		{
			getline(doc_input, line);
		}

		if (!contains(line, "/address_book")) {
			// Keep going until we hit the </address_book> tag
			getline(doc_input, line);
			while (!contains(line, "/contact")) {
				unsigned long tagStart = line.find("<");
				unsigned long tagEnd = line.find(">");
				if (contains(line, "<")) {
					string tag = line.substr(tagStart + 1, tagEnd - tagStart - 1);
					unsigned long closeTag = line.find("</");
					string value = line.substr(tagEnd + 1, closeTag - tagEnd - 1);
					if (tag == "name")
						customer_list[pos].name = value;
					else if (tag == "street")
						customer_list[pos].street = value;
					else if (tag == "city")
						customer_list[pos].city = value;
					else if (tag == "state")
						customer_list[pos].state = value;
					else if (tag == "zip")
						customer_list[pos].zip = value;
				}
				getline(doc_input, line);
			}
			pos++;
		}
	}

	// Print customer list
	print_list(customer_list, pos);

	cout << "----------------------------------------------------------------------" << endl;
	cout << "Addresses in Davie: " << endl << endl;

	//find the address in palmdale
	find_address(customer_list, city, pos);

	cout << "----------------------------------------------------------------------" << endl;
	cout << "Range of Zipcodes: " << endl << endl;

	//finds the range of the zip codes desired.
	find_in_zip_range(customer_list, zip_one, zip_two, pos);


	return 0;
}

// Returns true if tofind is a substring of str. Will return false if tofind is empty.
bool contains(string str, string tofind)
{
	return (str.find(tofind) != string::npos);
}

// Print customer list
void print_list(record s[], int size) 
{
	cout << "We have " << size << " customers!" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << s[i].name << endl;
		cout << s[i].street << endl;
		cout << s[i].city << ", " << s[i].state << " " << s[i].zip << endl << endl;
		
	}
}

void find_address(record s[], string target_city, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (target_city == s[i].city)
		{
			cout << s[i].name << endl;
			cout << s[i].street << endl;
			cout << s[i].city << ", " << s[i].state << " " << s[i].zip << endl << endl;
		}
	}
}

void find_in_zip_range(record s[], string beggining, string end, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (s[i].zip >= beggining && s[i].zip <= end)
		{
			cout << s[i].name << endl;
			cout << s[i].street << endl;
			cout << s[i].city << ", " << s[i].state << " " << s[i].zip << endl << endl;
		}
	}
}