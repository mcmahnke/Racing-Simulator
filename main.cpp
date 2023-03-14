//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the implementation of main for this program. It only contains a client class object (user_menu) to act as the menu, calling the menu() function. Allows the user to interact with all aspects of the program, including creating and modifying vehicles to race against eachother. For more documentation on how the menu() function works, see "client.h" and "client.cpp"

#include "client.h"

int main() {
	client user_menu;
	user_menu.menu();
	return 0;
}
