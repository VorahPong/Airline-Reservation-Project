#pragma once
#include <string>

struct Node
{
	int data;

	int ID, Reservation_Number, Seat_Number;
	std::string Last_Name;
	std::string First_Name;
	std::string Address;
	std::string Telephone;
	std::string Menu_Preference;

	Node* next = nullptr;
};

class Linked_list
{
public:
	Linked_list();
	Linked_list(Linked_list*);
	void linked_list_copy(Node*);
	bool insert_node(Node*);
	bool delete_node(Node*);
	void print_list();			//print all passenger
	void print(Node* temp);		//print a certain passenger
	Node* search_node(int p_id);
	void align_menu(); //print a good display
	~Linked_list();
private:
	Node* head;
};