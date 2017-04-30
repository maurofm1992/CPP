//Mauricio Da Graca
//homework 5-2 
//Foundations
//06/21/2015

//This is the header file mylist.h. This is the interface for the
//class MyList

#include <iostream>
using namespace std;


namespace mauriciodagraca
{
	template<class ItemType>
	class MyList
	{
	public:

		MyList() {head = NULL}

		MyList(const GenericList&);

		MyList(int max);
		//Initializes the object to an empty list that can hold up to
		//max items of type ItemType.
		~MyList();
		//Returns all the dynamic memory used by the object to the freestore.

		int length() const;
		//Returns the number of items on the list.

		void add(ItemType new_item);
		//Precondition: The list is not full.
		//Postcondition: The new_item has been added to the list.

		void remove(ItemType item);
		//Removes specific item from the list.

		bool full() const;
		//Returns true if the list is full.

		void erase();
		//Removes all items from the list so that the list is empty.

		int find(ItemType item);
		//Finds the item inside the list.

		void operator = (const GenericList &right)
			//overloads the = operator
		{
			// Delete the list.
			erase();

			// Copy the new list over.
			head = nullptr;
			MylistNode *current = right.head;

			while (current)
			{
				add(current->data);
				current = current->link;
			}
		}

		friend ostream& operator <<(ostream& outs,
			const MyList<ItemType>& the_list)
		{
			MylistNode *temp;

			temp = the_list.head;

			while (temp)
			{
				outs << temp->data << endl;
				temp = temp->link;
			}
			return outs;
		}
		//Overloads the << operator so it can be used to output.
		
	private:

		struct MylistNode
		{
			ItemType data;
			MylistNode *link;
		};

		MylistNode *head;

		ItemType *item; //pointer to the dynamic array that holds the list.
		int max_length; //max number of items allowed on the list.
		int current_length; //number of items currently on the list.


	};
}

