//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the header file for the client class, allowing the user to interact with the program and execute all its functionalities. 

#include "DLL.h"

class client {
	public:
		client();

		bool menu(); //Acts as a menu for the user, allowing for the user to interact with all aspects of the program
		bool display_list(int choice); //Displays a list depending on the input; 1 - motorcycles, 2 - _4WDs, 3 - supers

	private:
		list<motorcycle> motorcycles;
		list<_4WD> _4WDs;
		list<super> supers;
};
