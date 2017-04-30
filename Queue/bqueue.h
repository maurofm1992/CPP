//Mauricio Da Graca
//.h file

#pragma once
#include <iostream>
using namespace std;

class bqnode
{
public:
	int time;
	bqnode *prev, *next;
};

class BQUEUE
{
public:
	BQUEUE();		//default constructor
	~BQUEUE();		//Destructor
	BQUEUE(const BQUEUE &);		//Copy constructor
	bool Empty(){ return back == 0; }
	void Enqueue(int);	//adds to the list
	void Dequeue();		//removes from the list
	void Print();		//accessor
private:
	bqnode *back;
};