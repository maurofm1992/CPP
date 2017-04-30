//Mauricio Da Graca
//Assignment 4.
// This is the cpp file.
///////////////////////////////////////////////////////////////

#include "word.h"
#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Word
//Precondition: Constructor has not been invoked.
//Postcondition: count=0, array DB of size capacity = 10.
//Description: Constructs an instance of a TLIST object.

WORD::WORD()
{
	//Set the back and the front to 0.
	front = back = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: WORD (copy constructor.)
//Precondition: constructor has been invoked
//Postcondition: deep copy of one member to the other.
WORD::WORD(const WORD & w)
{
	front = back = 0;
	character *p = w.front;

	while (p != 0)
	{
		Insert(p->symbol);
		p = p->next;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: WORD (explicit value constructor.)
//Precondition: constructor has been invoked
//Postcondition: The list is filled with specific string values.
WORD::WORD(const string & w)
{
	back = front = 0;
	int i;

	for (i = 0; i < w.length(); i++)
	{
		Insert(w[i]);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~WORD
//Precondition: constructor has been invoked
//Postcondition: deallocates all the memory allocated for the word.
WORD::~WORD()
{
	while (front != 0)
	{
		character *p = front;
		front = front->next;
		delete p;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Insert
//Precondition: Constructor has been called.
//Postcondition: inserts the character in each node of the list.
void WORD::Insert(const word_type & w)
{
	character *p = new character;
	p->symbol = w;
	p->next = 0;


	if (front == 0)
	{
		front = back = p;
	}

	else
	{
		character *curr, *prev;

		curr = prev = front;

		while (curr != 0)
		{
			prev = curr;
			curr = curr->next;
		}

		p->next = curr;
		prev->next = p;
		back = p;

	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Insert
//Precondition: constructor has been called
//Postcondition: It inserts a list in an specific position of the current lists
void WORD::Insert(WORD & key, int pos)
{
	WORD *p = this;
	WORD *x = new WORD;
	*x = key;
	int length = 0;
	length = (*this).Length();
	
	if (key.Length() == 0)
	{
		x->front = front;
	}
	
	else if (pos <= 1)
	{
		x->back->next = p->front;
		p->front = x->front;
	}
	else if(pos >= 2 && pos >= length)
	{
		p->back->next = x->front;
	}
	
	else 
	{
		character *p = front;

		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}

		x->back->next = p->next;
		p->next = x->front;

	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Size
//Precondition: none.
//Postcondition: counts how many elements are inside the linked list.
int WORD::Length()
{
	int count = 0;
	character *temp = front;
	if (front == 0) // check if the word is empty
	{
		cout << "The word is empty" << endl;
	}
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove
//Precondition: a linked list is passed as an argument to the function (the target)
//Postcondition: deletes the first ocurrence of the element in the list.
void WORD::Remove(WORD & key)
{
	character *loc_ptr;
	while (key.front != 0)
	{
			if (key.front->symbol == front->symbol)
			{
				loc_ptr = front;
				front = front->next;
				delete loc_ptr;
			}
			key.front = key.front->next;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: a linked list is passed as an argument to the function(the target)
//Postcondition: deletes every ocurrence of the specific character from the list.
void WORD::RemoveALL(WORD & key)
{
	character *loc_ptr;
	while (key.front != 0) 
	{
		while (front != 0) 
		{
			if (Is_Empty())
			{
				cout << "WORD is empty cannot remove\n";
			}
			else if (key.front->symbol == front->symbol)
			{
				loc_ptr = front;
				front = front->next;
				delete loc_ptr;
			}
			else
			{
				character *fwd_ptr = front, *pre_ptr = front;
				while (fwd_ptr != 0 && (fwd_ptr->symbol != key.front->symbol))
				{
					pre_ptr = fwd_ptr;
					fwd_ptr = fwd_ptr->next;
				}
				if (fwd_ptr == 0)
				{
					break;
				}
				else 
				{
					pre_ptr->next = fwd_ptr->next;
					delete fwd_ptr;
				}
			}
		}
		key.front = key.front->next;
	}


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Is Equal
//Precondition: Alinked list is passed as an argument.
//Postcondition: compares to linked list to see if they are equal, if they are equal,
//				 it returns true.
bool WORD::IsEqual(WORD & key)
{
	character *p = key.front;
	character *k = this->front;

	if ((*this).Length() >= key.Length())
	{
		while (p != 0 && k != 0)
		{
			if (p->symbol == k->symbol)
			{
				p = p->next;
				k = k->next;
			}
			else
			{
				return false;
			}
		}
		if (p == 0 && k == 0)
		{
			return true;
		}
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: operator =.
//Precondition: the default constructor has to be called already.
//Postcondition: overloads the = without chaining and assigns the string to the list.

WORD & WORD::operator =(const string Org)
{
	int i;
	WORD *figo = new WORD;
	figo = this;
	figo->front = 0;
	for (i = 0; i < Org.length(); i++)
	{
		Insert(Org[i]);
	}
	return *figo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: operator =.
//Precondition: the default constructor has to be called already.
//Postcondition: overloads the = with chaining and assigns one list to the other.

WORD & WORD::operator =(const WORD & Org)
{
	if (this == &Org)
	{
		return *this;
	}
	else
	{
		character *p = Org.front;
		while (p != 0)
		{
			Insert(p->symbol);
			p = p->next;
		}
		return *this;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: operator +.
//Precondition: the default constructor has to be called already.
//Postcondition: overloads the + without chaining and puts the WORD b in the back of WORD A (WORD A is the current object).

WORD & WORD::operator +(const WORD Org)
{
	character *p = new character;
	character *x = this->front;
	p = Org.front;
	while (p != 0)
	{
		Insert(p->symbol);
		p = p->next;
	}
	p = x;
	return *this;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: operator <<.
//Precondition: none.
//Postcondition: overloads the << operator.
ostream & operator<<(ostream & out, const WORD & w)
{
	character *p = w.front;

	out << endl;

	while (p != 0)
	{
		out << p->symbol;
		p = p->next;
	}
	out << endl;
	return out;
}