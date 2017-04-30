//Mauricio Da Graca
//Assignment 7
// 11/27/2015

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class BST_Node
{
public:
	string lastname, firstname, address, phone_number;
	BST_Node  *lchild, *rchild;   //left and right children pointers
};



class Clients_Info_BST
{
public:
	Clients_Info_BST(){ root = 0; }
	~Clients_Info_BST();
	bool Empty();
	void Insert(const string & last, const string & first);
	void Insert(BST_Node * & loc_ptr, const string & last, const string & first);
	void insert_Iterate(string item);
	void Remove(const string & last, const string & first);
	void Remove(BST_Node * & loc_ptr, const string & last, const string & first);
	BST_Node * Search(BST_Node *, const string & last, const string & first);
	BST_Node * Search(const string & last, const string & first);
	BST_Node * search_tree_Iterate(string item);
	BST_Node * inorder_succ(BST_Node *);
	BST_Node * parent();
	void Print();
	void Print(BST_Node *);
	int count_node();
	int count_node(BST_Node *);
	int count_node(BST_Node * r, string last1, string first1, string last2, string first2);
	int count_node(string last1, string first1, string last2, string first2);

	void Update(const string & s){ cout << "   Inside Client_Info_BST Update\n"; };

private:
	BST_Node *root; //---state information
};



bool Clients_Info_BST::Empty()
{
	return (root == 0);
}



void Clients_Info_BST::Insert(const string & last, const string & first)
{
	Insert(root, first, last);
}



void Clients_Info_BST::Insert(BST_Node * & loc_ptr, const string & last, const string & first)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new BST_Node;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->lastname = last;
		loc_ptr->firstname = first;
	}

	else if (loc_ptr->lastname + loc_ptr->firstname > last + first)
		Insert(loc_ptr->lchild, last, first);

	else if (loc_ptr->lastname + loc_ptr->firstname < last + first)
		Insert(loc_ptr->rchild, last, first);

	else
		cout << "the item is already in the tree\n";

}



//void Clients_Info_BST::insert_Iterate(string item)
//{
//	BST_Node *parent, *loc_ptr = root;
//
//	BST_Node *loc_ptr2 = new BST_Node;
//	loc_ptr2->lchild = loc_ptr2->rchild = 0;
//	loc_ptr2->info = item;
//
//	if (root == 0)
//	{
//		root = loc_ptr2;
//		return;
//	}
//
//	while (loc_ptr != 0)
//	{
//		parent = loc_ptr;
//
//		if (loc_ptr->info == item)
//		{
//			cout << "Duplicate in tree; do nothing!\n";
//			delete loc_ptr2;
//			return;
//		}
//		else if (loc_ptr->info>item)
//		{
//			loc_ptr = loc_ptr->lchild;
//		}
//		else if (loc_ptr->info<item)
//		{
//			loc_ptr = loc_ptr->rchild;
//		}
//	}
//
//	if (parent->info<item)
//	{
//		parent->rchild = loc_ptr2;
//	}
//	else
//	{
//		parent->lchild = loc_ptr2;
//	}
//}





BST_Node * Clients_Info_BST::Search(const string & last, const string & first)
{
	return Search(root, last, first);
}



BST_Node * Clients_Info_BST::Search(BST_Node * loc_ptr, const string & last, const string & first)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->lastname + loc_ptr->firstname == last + first)
			return loc_ptr;

		else if (loc_ptr->lastname + loc_ptr->firstname > last + first)
			return Search(loc_ptr->lchild, last, first);

		else
			return Search(loc_ptr->rchild, last, first);
	}

	else
		return loc_ptr;
}



//BST_Node * Clients_Info_BST::search_tree_Iterate(string item)
//{
//	BST_Node * loc_ptr = root;
//
//	while (loc_ptr != 0)
//	{
//		if (loc_ptr->info == item)
//			return loc_ptr;
//		else if (loc_ptr->info>item)
//			loc_ptr = loc_ptr->lchild;
//		else
//			loc_ptr = loc_ptr->rchild;
//
//	}
//
//	return loc_ptr;
//}


void Clients_Info_BST::Remove(const string & last, const string & first)
{
	Remove(root, last, first);
}



void Clients_Info_BST::Remove(BST_Node * & loc_ptr, const string & last, const string & first)
{
	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->lastname + loc_ptr->firstname > last + first)
		Remove(loc_ptr->lchild, last, first);

	else if (loc_ptr->lastname + loc_ptr->firstname < last + first)
		Remove(loc_ptr->rchild, last, first);

	else
	{
		BST_Node * ptr;
		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}

		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}

		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->lastname = ptr->lastname;
			loc_ptr->firstname = ptr->firstname;
			Remove(loc_ptr->rchild, ptr->lastname, ptr->firstname);
		}
	}
}



BST_Node * Clients_Info_BST::inorder_succ(BST_Node * loc_ptr)
{
	BST_Node *ptr = loc_ptr->rchild;
	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}

	return ptr;
}



void Clients_Info_BST::Print()
{
	Print(root);
}



void Clients_Info_BST::Print(BST_Node * loc_ptr)
{
	if (loc_ptr != 0)
	{
		Print(loc_ptr->lchild);
		cout << loc_ptr->lastname << loc_ptr->firstname << loc_ptr->address << loc_ptr->phone_number << endl;
		Print(loc_ptr->rchild);
	}
}

Clients_Info_BST::~Clients_Info_BST()
{
	while (root != 0)
	{
		Remove(root->lastname, root->firstname);
	}
}



int Clients_Info_BST::count_node()
{
	return count_node(root);
}


int Clients_Info_BST::count_node(BST_Node * loc_ptr)
{
	if (loc_ptr == 0)
	{
		return 0;
	}

	else
	{
		return 1 + count_node(loc_ptr->lchild) + count_node(loc_ptr->rchild);
	}
}



int Clients_Info_BST::count_node(string last1, string first1, string last2, string first2)
{
	return count_node(root, last1, first1, last2, first2);
}



int Clients_Info_BST::count_node(BST_Node * r, string last1, string first1, string last2, string first2)
{
	if (r == 0)
		return 0;

	else if (r->lastname + r->firstname >= last1 + first1 && r->lastname + r->firstname <= last2 + first2)
		return 1 + count_node(r->lchild, last1, first1, last2, first2) + count_node(r->rchild, last1, first1, last2, first2);

	else if (r->lastname + r->firstname > last2 + first2)
		return count_node(r->lchild, last1, first1, last2, first2);

	else if (r->lastname + r->firstname < last1 + first1)
		return count_node(r->rchild, last1, first1, last2, first2);

	else
		return 0;
}


class Client_Address_Book
{

public:

	Client_Address_Book(){};//default constructor will read data from input file "client_address_data.txt".
	Client_Address_Book(const Client_Address_Book &);//Copy Constructor
	~Client_Address_Book();//Destructor
	void Insert(const string & s);// insert record

	//Insert adds a new Client's information to the hash table

	void Remove(const string & s);//remove record
	//Remove deletes a client from the hash table if it is there; otherwise
	//a message should be printed stating so.

	void Update(const string & s);//update record
	// see example below

	void Print_BST(const string & s);//Print a BST (cell in hash table) inorder to the screen

	void Print_Hash_Table(){ "Inside Client_Address_Book Print_Hash_Table\n"; };
	//function will print hash table to the screen                          

	void Print_Hash_Table_to_File(const string & filename);
	//function will print hash table to output file                                                                                                                                                                                

	bool * Search(const string & s){ "Inside Client_Address_Book Search\n"; return 0; };
	//return true if client found; otherwise false

	unsigned int Hash_Function(const string & s);
	//return the index of the BST in the hash table


	// Hint:  Remember that the insert, remove and search function for Clients_Address_Book will use //     
	//Client_Info_BST’s insert, remove and search respectively.

private:

	int capacity;  //SET THIS VALUE EQUAL TO 27  YOUR DEFAULT CONSTRUCTOR
	Clients_Info_BST   *hash_table; // USING 1 THROUGH 26 or whatever you like
};



Client_Address_Book::Client_Address_Book()
{
	string line;
	fstream myfile("client_address_data.txt");
	while (!myfile.eof() && myfile.is_open)
	{
		getline(myfile, line);
		vector s < string >;
		for (int i = 0; i < line.size(); i++)
		{

		}
	}
	myfile.close();

}//default constructor will read data from input file "client_address_data.txt".

Client_Address_Book::Client_Address_Book(const Client_Address_Book &)//Copy Constructor
{

}
Client_Address_Book::~Client_Address_Book()//Destructor
{

}
void Client_Address_Book::Insert(const string & s)// insert record
{

}
//Insert adds a new Client's information to the hash table
void Client_Address_Book::Remove(const string & s)//remove record
//Remove deletes a client from the hash table if it is there; otherwise
//a message should be printed stating so.
{

}

void Client_Address_Book::Update(const string & s)//update record
// see example below
{

}

void Client_Address_Book::Print_BST(const string & s)//Print a BST (cell in hash table) inorder to the screen
{

}

//function will print hash table to the screen                          
void Client_Address_Book::Print_Hash_Table()
{ 
	"Inside Client_Address_Book Print_Hash_Table\n"; 
}                         

void Client_Address_Book::Print_Hash_Table_to_File(const string & filename)
//function will print hash table to output file                                                                                                                                                                                
{

}

//return true if client found; otherwise false
bool * Client_Address_Book::Search(const string & s)
{ 
	"Inside Client_Address_Book Search\n"; return 0; 
}

//return the index of the BST in the hash table
unsigned int Client_Address_Book::Hash_Function(const string & s)
{

}


int main()
{
	Client_Address_Book My_Book;
	//My_Book.Insert("Bullard Lofton 777 Glades Road 207-2780");
	//My_Book.Remove("Bullard Lofton");

	//My_Book.Update("1 Bullard Lofton  Comb Harry 555 Palmetto Park Road 555-3444");
	//My_Book.Print_BST("B");
	//My_Book.Print_Hash_Table();

	//Client_Address_Book Your_Book = My_Book; //Invoke the copy constructor
	//Your_Book.Print_Hash_Table_to_File(/* the output filename goes here*/);

	return 0;
}
