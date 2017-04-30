//Mauricio Da Graca
//homework 5-2 
//Foundations
//06/21/2015

//This is the implementation file: MyList.cpp
//This is the implementation of the class template named MyList.
//The interface for the class template MyList is in the
//header file MyList.h.

#include <iostream>
#include <cstdlib>
#include "MyList.h" 

using namespace std;

//Uses cstdlib:
namespace mauriciodagraca
{
	template<class ItemType>
	MyList<ItemType>::MyList()
	{
		
	}

	template<class ItemType>
	MyList<ItemType>::MyList(const MyList& list)
	{
		MylistNode *current = list.head;

		while (current)
		{
			add(current->data);
			current = current->link;
		}

	}

	template<class ItemType>
	MyList<ItemType>::MyList(int max) : max_length(max),
		current_length(0)
	{
		head = nullptr;
	}

	template<class ItemType>
	MyList<ItemType>::~MyList()
	{
		erase();
	}

	template<class ItemType>
	int MyList<ItemType>::length() const
	{
		return (current_length);
	}

	//Uses iostream and cstdlib:
	template<class ItemType>
	void MyList<ItemType>::add(ItemType new_item)
	{

		if (max_length && current_length == max_length)
		{
			cout << "The list is full" << endl;
			return;
		}

		MylistNode *temp_ptr;
		MylistNode *item;

		item = new MylistNode;

		item->data = new_item;
		item->link = nullptr;

		if (!head)
		{
			head = item;
		}

		else
		{
			temp_ptr = head;

			while (temp_ptr->link)
			{
				if (temp_ptr->data == item->data)
				{
					cout << "This item already exists. " << endl;
					return;
				}
				temp_ptr = temp_ptr->link;

			}

			if (temp_ptr->data == item->data)
			{
				cout << "This item already exists. " << endl;
				return;
			}

			temp_ptr->link = item;

		}
		current_length++;
	}

	template<class ItemType>
	void MyList<ItemType>::remove(ItemType item)
	{

		MylistNode *previous = nullptr;
		MylistNode *current;

		if (!head)
		{
			return;
		}

		else if (head->data == item)
		{
			current = head->link;
			delete head;
			head = current;
		}

		else
		{
			current = head;
			while (current && current->data != item)
			{
				previous = current;
				current = current->link;

			}

			if (current)
			{
				previous->link = current->link;
				delete current;
			}
		}

	}


	template<class ItemType>
	int MyList<ItemType>::find(ItemType item)
	{
		MylistNode *temp_ptr;
		int position = 0;

		temp_ptr = head;

		while (temp_ptr)
		{
			if (temp_ptr->data == item)
			{
				return position;
			}

			temp_ptr = temp_ptr->link;
			position++;
		}

		return -1;
	}
	template<class ItemType>
	bool MyList<ItemType>::full() const
	{
		return (current_length == max_length);
	}

	template<class ItemType>
	void MyList<ItemType>::erase()
	{
		MylistNode *current;
		MylistNode *next;

		current = head;

		while (current)
		{
			next = current->link;
			delete current;
			current = next;
		}
		current_length = 0;
	}
}
//listsavitch
