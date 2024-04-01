#include "linked_list.h"
#include <iostream>
#include <iomanip>

//Default constructor
Linked_list::Linked_list()
{
	head = nullptr;
}

Linked_list::Linked_list(Linked_list* alist)
{
	if (alist->head == nullptr)
		this->head = nullptr;
	else {
		this->head = new Node;
		this->head->data = alist->head->data;
		this->head->next = nullptr;
		Node* a_move = alist->head;
		Node* h_move = this->head;

		while (a_move->next != nullptr)//copy the rest if nay
		{
			a_move = a_move->next;
			h_move->next = new Node; //create a new node
			h_move = h_move->next; //move to the new node
			h_move->data = a_move->data;
			h_move->next = nullptr;
		}

	}
}
void Linked_list::linked_list_copy(Node* another)
{
	if (another == nullptr)
		head = nullptr;
	else {
		head = new Node;
		head->data = another->data;
		Node* a_move = another;
		Node* h_move = head;

		while (a_move->next != nullptr)//copy the rest if nay
		{
			a_move = a_move->next;
			h_move->next = new Node; //create a new node
			h_move = h_move->next; //move to the new node
			h_move->data = a_move->data;
			h_move->next = nullptr;
		}

	}
}

//Insert passenger by their last name in alphabetical order
bool Linked_list::insert_node(Node* n)
{
	if (head == nullptr)
	{
		head = n;
		return true;
	}
	else if (head->Last_Name > n->Last_Name)
	{
		n->next = head;
		head = n;
	}
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		while (cur != nullptr && cur->Last_Name < n->Last_Name) //find the position
		{
			pre = cur;
			cur = cur->next;
		}
		n->next = cur;
		pre->next = n;

		return true;
	}
}

//print good looking align display information
void Linked_list::align_menu() {
	std::cout << "ID\t";
	std::cout.width(20);
	std::cout << std::left << "First Name";
	std::cout.width(20);
	std::cout << std::left << "Last Name";
	std::cout.width(20);
	std::cout << std::left << "Address";
	std::cout.width(20);
	std::cout << std::left << "Reservation Number";
	std::cout.width(20);
	std::cout << std::left << "Telephone";
	std::cout.width(20);
	std::cout << std::left << "Seat Number";
	std::cout.width(20);
	std::cout << std::left << "Menu Preference" << std::endl;
}
//Print all Passengers and their information
void Linked_list::print_list()
{
	Node* temp = head;
	align_menu();

	while (temp != nullptr)
	{
		print(temp);

		temp = temp->next;
	}
	std::cout << std::endl;
}

//Destructor
Linked_list::~Linked_list()
{
	if (head == nullptr)
		return;
	else {
		Node* del;
		while (head != nullptr)
		{
			del = head;
			head = head->next;
			delete del;
		}
	}
}


//Print a certain Passenger
void Linked_list::print(Node* temp) {
	std::cout << temp->ID << "\t";
	std::cout.width(20);
	std::cout << std::left << temp->First_Name;
	std::cout.width(20);
	std::cout << std::left << temp->Last_Name;
	std::cout.width(20);
	std::cout << std::left << temp->Address;
	std::cout.width(20);
	std::cout << std::left << temp->Reservation_Number;
	std::cout.width(20);
	std::cout << std::left << temp->Telephone;
	std::cout.width(20);
	std::cout << std::left << temp->Seat_Number;
	std::cout.width(20);
	std::cout << std::left << temp->Menu_Preference << std::endl;
}

//search for a passenger by their ID
Node* Linked_list::search_node(int p_id)
{
	int position = 1;
	if (head == nullptr)
		std::cout << "Not found\n";
	else if (head->ID == p_id) {
		return head;
	}
		
	else {
		Node* temp = head->next;
		while (temp != nullptr && temp->ID != p_id)
		{
			position++;
			temp = temp->next;
		}
		if (temp != nullptr) {
			return head;
		}
		else
			std::cout << "Not found\n";
	}
	return nullptr;
}

//Delete Passenger
bool Linked_list::delete_node(Node* n)
{
	if (head == nullptr)
	{
		return false;
	}
	else if (head->ID == n->ID)
	{
		Node* del;
		del = head;
		head = head->next;
		delete del;
	}
	else {
		Node* pre, * cur;
		pre = head;
		cur = head->next;
		while (cur != nullptr && cur->data != n->data)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur != nullptr)
		{
			pre->next = cur->next;
			return true;
		}
		else
			return false;
	}
}