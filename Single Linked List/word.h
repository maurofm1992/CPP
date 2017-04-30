//Mauricio Da Graca.
//Assignment 4.
//This is the .h file.
#include <iostream>
#include <string>

using  namespace std;

#ifndef word_H
#define word_h

typedef char word_type;
//declaration for a node in the list
class character
{
public:
	word_type symbol; //Data of the node.
	character *next; //Points to the next node.
};

//declaration of a list class
class WORD
{
public:
	WORD();//default constructor
	WORD(const string & w); //explicit.
	WORD(const WORD & w);//copy value constructor.
	int WORD::Length();
	WORD::~WORD();
	bool Is_Empty(){ return front == 0; }; //accessor
	void Insert(const word_type & w); //Inserts the characters in the list.
	void Insert(WORD & key, int pos); //Inserts the copy of word B into word A.
	void Remove(WORD &); // Deletes the first occurrence of word B from word A if it is there; 
							   //remember A is the current object;
	void RemoveALL(WORD &);// Deletes all the occurrences of word B from word A if it is there; 
							   //remember A is the current object;
	bool IsEqual(WORD &);	//returns true if two words are equal.
	character * Search(const WORD &); // Lokks for an specific set of characaters inside the list.
	friend ostream & operator<<(ostream & out, const WORD &front);
	WORD & operator =(const string Org); // overloads the = operator without chaining.
	WORD & operator =(const WORD & Org); // overloads the = operator with chaining.
	WORD & operator +(const WORD Org); // overloads the operator + without chaining adds word b in the back of word a. 
										 //(a current object).
	//WORD & operator -(const string Org);

private:

	character *front, *back;

};

#endif











