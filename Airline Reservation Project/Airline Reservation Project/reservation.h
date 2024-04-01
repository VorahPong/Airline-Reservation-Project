#pragma once

#include <iostream>
#include <fstream>			// to open database file
#include <cstdlib>
#include "linked_list.h"	// linked_list class
#include <string>
#include <vector>
#include <algorithm>


class reservation
{
public:
	reservation() {};						// constructor initializes data to database
	char menu();							//reservation system menu  
	void start();							// starts user input
	void search();							// allows user to display specific passenger info
	void insert();							// allows user to make a new passenger reservation
	void remove();							// allows user to cancel a reservation
	void print();							// prints list of all passengers
	void changeFood();						// user can change food preference of passenger
	void changeSeat();						// user can change seat of passenger if available
	void copyDatabase();					// linked_list is initialized to database
private:
	Linked_list mine;						// declare an object of the linked list class
	std::vector<int> seat_numbers_storage;	// store seat numbers

};
