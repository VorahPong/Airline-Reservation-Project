#include "reservation.h"


char reservation::menu()
/*  This is the menu for the user. The menu displays the choices the user has. The user will enter a character, and that character will be returned to be used in the start function of the reservation class.*/
{
	std::string choice;

	std::cout << "\n\t\tMenu\n";
	std::cout << "\t 1\tEnter a reservation\n";
	std::cout << "\t 2\tCancel a reservation\n";
	std::cout << "\t 3\tPrint a passenger list\n";
	std::cout << "\t 4\tSearch for a passenger\n";
	std::cout << "\t 5\tChange Reservation Seat\n";
	std::cout << "\t 6\tChange Reservation Food\n";
	std::cout << "\t 0\tEXIT\n";

	std::cout << "\nEnter your choice: ";
	std::cin >> choice;	// user input

	return choice[0];	// returns user input
}


//Your start function may look like :

void reservation::start()

/* once this function is called, a loop will be created that allows the user to input how they want the list to be manipulated. Functions include insert, remove, print,search, changeSeat, and changeFood. If user enters '0', then the loop will terminate.*/

{
	bool done = false;	// done boolean

	do {

		char choice = menu(); //get the choice from the user
		switch (choice) //this switch compares the choice entered by the user to determine which function to call.
		{
		case '1': insert(); break;
		case '2': remove(); break;
		case '3': print(); break;
		case '4': search(); break;
		case '5': changeSeat(); break;
		case '6': changeFood(); break;
		case '0': done = true; break;
		default: std::cout << "INVALID INPUT" << std::endl;
		}
	} while (!done); // if done, then quit, else continue

	std::cout << "\nThank you for using my simulation." << std::endl;

}

//insert function
//order by last name
void reservation::insert() {
	//take inputs
	std::string p_ln, p_fn, p_ad, p_tp, p_mp; 
	int p_id, p_rn, p_sn; 
	std::cout << "Enter Passenger's ID: "; 
		std::cin >> p_id; 

	std::cout << "Enter Passenger's Last Name: "; 
		std::cin >> p_ln;

	std::cout << "Enter Passenger's First Name: "; 
		std::cin >> p_fn;

	std::cout << "Enter Passenger's Address: ";
		std::cin.ignore();
		std::getline(std::cin, p_ad);

	std::cout << "Enter Passenger's Reservation Number: "; 
		std::cin >> p_rn;

	std::cout << "Enter Passenger's Telepohone: "; 
		std::cin.ignore();
		std::getline(std::cin, p_tp);

	std::cout << "Enter Passenger's Seat Number: "; 
		std::cin >> p_sn;
		if (seat_numbers_storage.size() == 0) {
			seat_numbers_storage.push_back(p_sn);
		}
		else {
			while (true) {
				if (std::find(seat_numbers_storage.begin(), seat_numbers_storage.end(), p_sn) == seat_numbers_storage.end()) {
					seat_numbers_storage.push_back(p_sn);
					break;
				}
				else {
					std::cout << "Passenger's Seat Number is already used\n";
					std::cout << "Enter new Passenger's Seat Number: ";
					std::cin >> p_sn;
				}
			}
		}
		

	std::cout << "Enter Passenger's Menu Preference: "; 
		std::cin >> p_mp;

	std::cout << std::endl;

	//add to linklist
	Node* temp = new Node;
	temp->ID = p_id;
	temp->Last_Name = p_ln;
	temp->First_Name = p_fn;
	temp->Address = p_ad;
	temp->Reservation_Number = p_rn;
	temp->Telephone = p_tp;
	temp->Seat_Number = p_sn;
	temp->Menu_Preference = p_mp;

	mine.insert_node(temp);
}

//search function. Search by ID
void reservation::search() {
	std::cout << "Enter Passenger's ID to find: ";
	int p_id; std::cin >> p_id;
	Node*temp = mine.search_node(p_id);
	if (temp != nullptr) {
		mine.align_menu();
		mine.print(temp);
	}
}

//remove function
void reservation::remove() {
	std::cout << "Enter Passenger's ID to remove: ";
	int p_id; std::cin >> p_id;
	Node* temp = mine.search_node(p_id);
	if (temp != nullptr) {
		for (int i = 0; i < seat_numbers_storage.size(); i++) {
			if (seat_numbers_storage[i] == temp->ID) {
				seat_numbers_storage.erase(seat_numbers_storage.begin() + i);
			}
		}
		mine.delete_node(temp);
		std::cout << "Passenger ID: " << p_id << " has been removed.\n";
	}
}

//print function
void reservation::print() {
	mine.print_list();
}

//Change passenger's food by their ID
void reservation::changeFood() {
	std::cout << "Enter Passenger's ID to change their Reservation Food: ";
	int p_id; std::cin >> p_id;
	Node* temp = mine.search_node(p_id);
	if (temp != nullptr) {
		std::cout << "Change Passenger's Reservation Food to: ";
		std::string p_fd;
		std::cin >> p_fd;
		temp->Menu_Preference = p_fd;
		std::cout << "Passenger ID: " << p_id << " food has been changed.\n";
	}

}

//Change passenger seat but no seat number can be use twice.
void reservation::changeSeat() {
	int p_id;
	int p_ps;
	std::cout << "Enter Passenger's ID to change their seat: ";
	std::cin >> p_id;
	Node* temp = mine.search_node(p_id);
	if (temp != nullptr) {
		for (int i = 0; i < seat_numbers_storage.size(); i++) {
			if (seat_numbers_storage[i] == temp->ID) {
				seat_numbers_storage.erase(seat_numbers_storage.begin() + i);
				break;
			}
		}
	}
	else {
		return;
	}

	bool status = true;
	while (status) {
		status = false;
		std::cout << "Change Passenger's seat to: ";
		std::cin >> p_ps;
		for (int i = 0; i < seat_numbers_storage.size(); i++) {
			if (seat_numbers_storage[i] == p_ps) {
				status = true;
				std::cout << "Seat is already occupied\n";
				break;
			}
		}
	}
	temp->Seat_Number = p_ps;
	seat_numbers_storage.push_back(p_ps);
	std::cout << "Passenger ID: " << p_id << " seat has been changed.\n";
	
}

void reservation::copyDatabase() {

}