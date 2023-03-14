//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the implementation of the client class member function menu(). The menu() function will act as the primary communication menu with the user, allowing them to utilize all aspects of this program. This will include creating vehicle objects from the main hierarchy, editing vehicle objects, generating race tracks, and completing races. 

#include "client.h"

client::client() {
}

bool client::menu() {
	int response = 0;
	char c_response[50];
	while(response != 8) {
		cout<< "\n\n          _/\\______\\__\n_-_-__  / ,-. -|-  ,-.`-.\n   _-_- `( o )----( o )-'\n          `-'      `-'"; //ASCII art found at: https://www.asciiart.eu/vehicles/cars
		cout<< "\nWelcome to SUPER AUTO RACERS! What would you like to do?\n1 - Create a new vehicle\n2 - Modify a vehicle\n3 - Compare vehicles\n4 - Display all vehicles\n5 - Remove a vehicle\n6 - Remove all vehicles\n7 - Race!\n8 - Quit\nEnter here: ";
		cin>> response;
		cin.ignore(1, '\n');
		if(response == 1) { //Creating a vehicle
			response = 0;
			while(response != 1  &&  response != 2  &&  response != 3) {
				cout<< "\nWhat type of vehicle would you like to create?\n1 - Motorcycle\n2 - 4WD Vehicle\n3 - Super car\nEnter here: ";
				cin>> response;
				cin.ignore(1, '\n');
				cout<< "Please enter the name you'd like to give this vehicle: ";
				cin.get(c_response, 50, '\n');
				cin.ignore(5, '\n');
				if(response == 1) {
					motorcycle temp(c_response);
					motorcycles.push_back(temp);
					cout<< "Motorcycle created!" <<endl;
				}
				else if(response == 2) {
					_4WD temp(c_response);
					_4WDs.push_back(temp);
					cout<< "4WD Vehicle created!" <<endl;
				}
				else if(response == 3) {
					super temp(c_response);
					supers.push_back(temp);
					cout<< "Super car created!" <<endl;	
				}
				else
					cout<< "Please enter a response in the range 1-3" <<endl;
			}
		}
		else if(response == 2) { //Modifying a vehicle
			response = 0;
			cout<< "\nWhat type of vehicle would you like to modify?\n1 - Motorcycle\n2 - 4WD Vehicle\n3 - Super car\nEnter here: ";
			cin>> response;
			cin.ignore(1, '\n');
			if(response == 1) {
				if(motorcycles.empty())
					cout<< "No motorcycles exist yet!" <<endl;
				else {
					display_list(response);
					cout<< "\nPlease enter the name of the motorcycle you'd like to modify: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(5, '\n');
					for(list<motorcycle>::iterator i = motorcycles.begin(); i != motorcycles.end(); ++i) {
						if((*i).compare_name(c_response)) {
							while(response != 7) {
								cout<< "\nHow would you like to modify the motorcycle ";
								(*i).display_name();
								cout<< "?\n1 - Change the type of this motorcycle\n2 - Add a performance mod\n3 - Remove a performance mod\n4 - Change name\n5 - Developer console\n6 - Display vehicle information\n7 - Leave this menu\nEnter here: ";
								cin>> response;
								cin.ignore(1, '\n');
								if(response == 1) {
									cout<< "What type of motorcycle would you like to set this motorcycle to?\n1 - Dirtbike (+20 handling, +20 offroad grip)\n2 - Streetbike (+10 handling, +10 horsepower, +20 road grip)\n3 - ATV (+20 handling, +5 horsepower, +10 offroad grip, +5 road_grip)\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1) {
										strcpy(c_response, "dirtbike");
									}												
									else if(response == 2) {
										strcpy(c_response, "streetbike");
									}
									else if(response == 3) {
										strcpy(c_response, "ATV");
									}	
									
									if((*i).set_motorcycle_type(response))
										cout<< "Motorcycle type set!" <<endl;
									else
										cout<< "Motorcycle type not set, please try again." <<endl;
									response = 0;
								}		
								else if(response == 2) {
									cout<< "Which performance mod would you like to add to this vehicle?\n1 - suspension+ (+10 handling, +10 offroad grip)\n2 - exhaust+ (+5 horsepower, +5 road grip)\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1  ||  response == 2) {
										(*i).add_mod(response);
										cout<< "Mod added successfully!" <<endl;
									}
									else
										cout<< "Please enter a response in the range 1-2" <<endl;
									response = 0;
								}
								else if(response == 3) {
									cout<< "All mods currently on this vehicle: ";
									if((*i).display_mods()) {
										cout<< "Which type of mod would you like to remove?\n1 - suspension+\n2 - exhaust+\nEnter here: ";
										cin>> response;
										cin.ignore(1, '\n');
										if((*i).remove_mod(response))
											cout<< "Mod removed successfully!" <<endl;
										else
											cout<< "Mod not found, please try again." <<endl;
									}
									else
										cout<< "None\nAdd a mod and try again!" <<endl;
									response = 0;
								}
								else if(response == 4) {
									cout<< "Please enter the new name you'd like to give this motorcycle: ";
									cin.get(c_response, 50, '\n');
									cin.ignore(5, '\n');
									(*i).set_name(c_response);
									cout<< "Name set!" <<endl;
								}
								else if(response == 5) {
									cout<< "This is the developer console, where you can manually set values for handling, horsepower, road grip, and offroad grip stats. Would you like to adjust these values?\n1 - yes\n2 - no\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1)
										cin>> *i;
									response = 0;
								}
								else if(response == 6) {
									cout<< *i;
								}
								else if(response == 7) {
									break;
								}
								else
									cout<< "Please enter a response in the range 1-6" <<endl;
							}
						}
					}	
				}
			}
			else if(response == 2) {
				if(_4WDs.empty())
					cout<< "No 4WD vehicles exist yet!" <<endl;
				else {
					display_list(response);
					cout<< "\nPlease enter the name of the 4WD vehicle you'd like to modify: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(5, '\n');
					for(list<_4WD>::iterator i = _4WDs.begin(); i != _4WDs.end(); ++i) {
						if((*i).compare_name(c_response)) {
							while(response != 7) {
								cout<< "\nHow would you like to modify the 4WD vehicle ";
								(*i).display_name();
								cout<< "?\n1 - Change the tire size\n2 - Add a performance mod\n3 - Remove a performance mod\n4 - Change name\n5 - Developer console\n6 - Display vehicle information\n7 - Leave this menu\nEnter here: ";
								cin>> response;
								cin.ignore(1, '\n');
								if(response == 1) {
									cout<< "What size tires would you like to put on this 4WD vehicle?\n1 - Standard (no boost)\n2 - Large(+5 handling, +5 offroad grip, -5 road grip)\n3 - Xtra-Large (+10 handling, +10 offroad grip, -10 road_grip)\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if((*i).set_tire_size(response))
										cout<< "Tire size set!" <<endl;
									else
										cout<< "Tire size not set, please try again." <<endl;
									response = 0;
								}		
								else if(response == 2) {
									cout<< "Which performance mod would you like to add to this vehicle?\n3 - diff+ (+10 offroad grip, +10 road grip)\n4 - tune+ (+5 horsepower, +5 handling)\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 3  ||  response == 4) {
										(*i).add_mod(response);
										cout<< "Mod added successfully!" <<endl;
									}
									else
										cout<< "Please enter a response in the range 1-2" <<endl;
									response = 0;
								}
								else if(response == 3) {
									cout<< "All mods currently on this vehicle: ";
									if((*i).display_mods()) {
										cout<< "Which type of mod would you like to remove?\n3 - diff+\n4 - tune+\nEnter here: ";
										cin>> response;
										cin.ignore(1, '\n');
										if((*i).remove_mod(response))
											cout<< "Mod removed successfully!" <<endl;
										else
											cout<< "Mod not found, please try again." <<endl;
									}
									else
										cout<< "None\nAdd a mod and try again!" <<endl;
									response = 0;
								}
								else if(response == 4) {
									cout<< "Please enter the new name you'd like to give this 4WD vehicle: ";
									cin.get(c_response, 50, '\n');
									cin.ignore(5, '\n');
									(*i).set_name(c_response);
									cout<< "Name set!" <<endl;
								}
								else if(response == 5) {
									cout<< "This is the developer console, where you can manually set values for handling, horsepower, road grip, and offroad grip stats. Would you like to adjust these values?\n1 - yes\n2 - no\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1)
										cin>> *i;
									response = 0;
								}
								else if(response == 6) {
									cout<< *i;
								}
								else if(response == 7) {
									break;
								}
								else
									cout<< "Please enter a response in the range 1-6" <<endl;
							}
						}
					}
				}
			}
			else if(response == 3) {
				if(supers.empty())
					cout<< "No super cars exist yet!" <<endl;
				else {
					display_list(response);
					cout<< "\nPlease enter the name of the super car you'd like to modify: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(5, '\n');
					for(list<super>::iterator i = supers.begin(); i != supers.end(); ++i) {
						if((*i).compare_name(c_response)) {
							while(response != 7) {
								cout<< "\nHow would you like to modify the super car ";
								(*i).display_name();
								cout<< "?\n1 - Adjust nitrous\n2 - Add a performance mod\n3 - Remove a performance mod\n4 - Change name\n5 - Developer console\n6 - Display vehicle information\n7 - Leave this menu\nEnter here: ";
								cin>> response;
								cin.ignore(1, '\n');
								if(response == 1) {
									cout<< "Would you like to enable nitrous on this super car?\n1 - yes\n2 - no\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1) {
										if((*i).apply_nitrous(true))
											cout<< "Nitrous enabled!" <<endl;
									}
									else if(response == 2) {
										(*i).apply_nitrous(false);
										cout<< "Nitrous disabled!" <<endl;	
									}
									response = 0;
								}		
								else if(response == 2) {
									cout<< "Which performance mod would you like to add to this vehicle?\n5 - lift+ (+10 handling, +10 offroad)\n6 - supercharge+ (+5 horsepower, +5 road grip)\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 5  ||  response == 6) {
										(*i).add_mod(response);
										cout<< "Mod added successfully!" <<endl;
									}
									else
										cout<< "Please enter a response in the range 1-2" <<endl;
									response = 0;
								}
								else if(response == 3) {
									cout<< "All mods currently on this vehicle: ";
									if((*i).display_mods()) {
										cout<< "Which type of mod would you like to remove?\n5 - lift+\n6 - supercharge+\nEnter here: ";
										cin>> response;
										cin.ignore(1, '\n');
										if((*i).remove_mod(response))
											cout<< "Mod removed successfully!" <<endl;
										else
											cout<< "Mod not found, please try again." <<endl;
									}
									else
										cout<< "None\nAdd a mod and try again!" <<endl;
									response = 0;
								}
								else if(response == 4) {
									cout<< "Please enter the new name you'd like to give this super car: ";
									cin.get(c_response, 50, '\n');
									cin.ignore(5, '\n');
									(*i).set_name(c_response);
									cout<< "Name set!" <<endl;
								}
								else if(response == 5) {
									cout<< "This is the developer console, where you can manually set values for handling, horsepower, road grip, and offroad grip stats. Would you like to adjust these values?\n1 - yes\n2 - no\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1)
										cin>> *i;
									response = 0;
								}
								else if(response == 6) {
									cout<< *i;	
								}
								else if(response == 7) {
									break;
								}
								else
									cout<< "Please enter a response in the range 1-7" <<endl;
							}
						}
						break;	
					}
				}
			}
		}
		else if(response == 3) { //Comparing vehicles with overloaded operators
			cout<< "\nYou will be comparing two vehicles, please choose the type of the vehicles you'd like to compare\n1 - motorcycle\n2 - 4WD vehicle\n3 - super car\nEnter here: ";
			cin>> response;
			cin.ignore(1, '\n');
			if(response == 1) {
				if(motorcycles.empty())
					cout<< "Add a motorcycle and try again!" <<endl;
				else {
					cout<< "All motorcycles: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first motorcycle you'd like to compare: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<motorcycle>::iterator i = motorcycles.begin(); i != motorcycles.end(); ++i) {
						if((*i).compare_name(c_response)) {
							cout<< "Motorcycle ";
							(*i).display_name();
							cout<< " retrieved!\nAll motorcycles: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second motorcycle you'd like to compare: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');
							for(list<motorcycle>::iterator j = motorcycles.begin(); j != motorcycles.end(); ++j) {
								if((*j).compare_name(c_response)) {		
									cout<< "Motorcycle ";
									(*j).display_name();
									cout<< " retrieved!" <<endl;
									if((*i) == (*j)) {
										cout<< "\nThe motorcycles ";
										(*i).display_name();
										cout<< " and ";
										(*j).display_name();
										cout<< " are the same class level";
									}
									else if((*i) < (*j)) {
										cout<< "\nThe motorcycle ";
										(*i).display_name();
										cout<< " is in a lower class than the motorcycle ";
										(*j).display_name();
									}
									else if((*i) > (*j)) {
										cout<< "\nThe motorcycle ";
										(*i).display_name();
										cout<< " is in a higher class than the motorcycle ";
										(*j).display_name();
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			else if(response == 2) {
				if(_4WDs.empty())
					cout<< "Add a 4WD vehicle and try again!" <<endl;
				else {
					cout<< "All 4WD vehicles: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first 4WD vehicle you'd like to compare: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<_4WD>::iterator i = _4WDs.begin(); i != _4WDs.end(); ++i) {
						if((*i).compare_name(c_response)) {
							cout<< "4WD vehicle ";
							(*i).display_name();
							cout<< " retrieved!\nAll 4WD vehicles: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second 4WD vehicle you'd like to compare: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');
							for(list<_4WD>::iterator j = _4WDs.begin(); j != _4WDs.end(); ++j) {
								if((*j).compare_name(c_response)) {		
									cout<< "4WD vehicle ";
									(*j).display_name();
									cout<< " retrieved!" <<endl;
									if((*i) == (*j)) {
										cout<< "\nThe 4WD vehicles ";
										(*i).display_name();
										cout<< " and ";
										(*j).display_name();
										cout<< " are the same class level";
									}
									else if((*i) < (*j)) {
										cout<< "\nThe 4WD vehicle ";
										(*i).display_name();
										cout<< " is in a lower class than the 4WD vehicle ";
										(*j).display_name();
									}
									else if((*i) > (*j)) {
										cout<< "\nThe 4WD vehicle ";
										(*i).display_name();
										cout<< " is in a higher class than the 4WD vehicle ";
										(*j).display_name();
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			else if(response == 3) {
				if(supers.empty())
					cout<< "Add a super car and try again!" <<endl;
				else {
					cout<< "All super cars: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first super car you'd like to compare: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<super>::iterator i = supers.begin(); i != supers.end(); ++i) {
						if((*i).compare_name(c_response)) {
							cout<< "super car ";
							(*i).display_name();
							cout<< " retrieved!\nAll super cars: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second super car you'd like to compare: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');
							for(list<super>::iterator j = supers.begin(); j != supers.end(); ++j) {
								if((*j).compare_name(c_response)) {		
									cout<< "super car ";
									(*j).display_name();
									cout<< " retrieved!" <<endl;
									if((*i) == (*j)) {
										cout<< "\nThe super cars ";
										(*i).display_name();
										cout<< " and ";
										(*j).display_name();
										cout<< " are the same class level";
									}
									else if((*i) < (*j)) {
										cout<< "\nThe super car ";
										(*i).display_name();
										cout<< " is in a lower class than the super car ";
										(*j).display_name();
									}
									else if((*i) > (*j)) {
										cout<< "\nThe super car ";
										(*i).display_name();
										cout<< " is in a higher class than the super car ";
										(*j).display_name();
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			response = 0;
		}
		else if(response == 4) { 
			cout<< "\nDisplaying all vehicles:\nMotorcycles: ";
			if(motorcycles.empty())
				cout<< "None";
			else 
				display_list(1);
			cout<< "\n4WD Vehicles: ";
			if(_4WDs.empty())
				cout<< "None";
			else
				display_list(2);
			cout<< "\nSuper cars: ";
			if(supers.empty())
				cout<< "None";
			else
				display_list(3);
		}
		else if(response == 5) { //Deleting a vehicle
			cout<< "\nPlease enter the type of vehicle you'd like to remove\n1 - motorcycle\n2 - 4WD vehicle\n3 - super car\nEnter here: ";
			cin>> response;
			cin.ignore(1, '\n');
			if(response == 1) {
				if(motorcycles.empty())
					cout<< "Add a motorcycle and try again!" <<endl;
				else {
					cout<< "All motorcycles: ";
					display_list(response);
					cout<< "Please enter the name of the motorcycle you'd like to remove: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<motorcycle>::iterator i = motorcycles.begin(); i != motorcycles.end(); ++i) {
						if((*i).compare_name(c_response)) {
							motorcycles.remove(*i);
							cout<< "Motorcycle removed!" <<endl;
							break;
						}
					}
				}
			}
			else if(response == 2) {
				if(_4WDs.empty())
					cout<< "Add a _4WD and try again!" <<endl;
				else {
					cout<< "All 4WD vehicles: ";
					display_list(response);
					cout<< "Please enter the name of the 4WD vehicle you'd like to remove: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<_4WD>::iterator i = _4WDs.begin(); i != _4WDs.end(); ++i) {
						if((*i).compare_name(c_response)) {
							_4WDs.remove(*i);
							cout<< "4WD vehicle removed!" <<endl;
							break;
						}
					}
				}
			}
			else if(response == 3) {
				if(supers.empty())
					cout<< "Add a super car and try again!" <<endl;
				else {
					cout<< "All super cars: ";
					display_list(response);
					cout<< "Please enter the name of the super car you'd like to remove: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<super>::iterator i = supers.begin(); i != supers.end(); ++i) {
						if((*i).compare_name(c_response)) {
							supers.remove(*i);
							cout<< "Super car removed!" <<endl;
							break;
						}
					}
				}
			}
			response = 0;

		}
		else if(response == 6) { //Removing all vehicles
			cout<< "\nRemoving all vehicles.." <<endl;
			motorcycles.clear();
			_4WDs.clear();
			supers.clear();
			cout<< "All vehicles removed!" <<endl;	
		}
		else if(response == 7) { //Racing!
			cout<< "\nPrepare to race! What type of vehicles will you be racing?\n1 - motorcycles\n2 - 4WD vehicles\n3 - super cars\nEnter here: ";
			cin>> response;
			cin.ignore(1, '\n');
			if(response == 1) {
				if(motorcycles.empty())
					cout<< "Add a motorcycle and try again!" <<endl;
				else {
					cout<< "All motorcycles: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first motorcycle you'd like to enter into this race: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<motorcycle>::iterator i = motorcycles.begin(); i != motorcycles.end(); ++i) {
						if((*i).compare_name(c_response)) {
							int length = 0;
							int laps = 0;
							cout<< "Motorcycle ";
							(*i).display_name();
							cout<< " retrieved!\nAll motorcycles: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second motorcycle you'd like to enter into this race: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');	
							for(list<motorcycle>::iterator j = motorcycles.begin(); j != motorcycles.end(); ++j) {
								if((*j).compare_name(c_response)) {
									cout<< "Please enter the length you'd like the track to be:\n1 - short\n2 - standard\n3 - long\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1) 
										length = 50;
									else if(response == 2)
										length = 100;
									else
										length = 200;
									cout<< "Please enter the number of laps you'd like to complete: ";
									cin>> laps;
									cin.ignore(1, '\n');
									cout<< "And finally, please choose the type of track you'd like to race on:\n1 - road\n2 - offroad\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									DLL<motorcycle> track(response, length, laps);
									track += *i;
									cout<< "\n\nOn your marks...\n\nGet set...\n\nGO!" <<endl;
									int time1 = track.race_track();
									cout<< "First vehicle time: " << time1 << " seconds." <<endl;
									track += *j;
									int time2 = track.race_track();
									cout<< "Second vehicle time: " << time2 << " seconds." <<endl;
									if(time1 == time2) 
										cout<< "It's a tie!" <<endl;
									else if(time1 < time2) {
										cout<< "\n";
										(*i).display_name();
										cout<< " wins the race!" <<endl;
									}
									else {
										cout<< "\n";
										(*j).display_name();
										cout<< " wins the race!" <<endl;
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			else if(response == 2) {
				if(_4WDs.empty())
					cout<< "Add a 4WD vehicle and try again!" <<endl;
				else {
					cout<< "All 4WD vehicles: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first 4WD vehicle you'd like to enter into this race: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<_4WD>::iterator i = _4WDs.begin(); i != _4WDs.end(); ++i) {
						if((*i).compare_name(c_response)) {
							int length = 0;
							int laps = 0;
							cout<< "4WD vehicle ";
							(*i).display_name();
							cout<< " retrieved!\nAll 4WD vehicles: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second 4WD vehicle you'd like to enter into this race: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');	
							for(list<_4WD>::iterator j = _4WDs.begin(); j != _4WDs.end(); ++j) {
								if((*j).compare_name(c_response)) {
									cout<< "Please enter the length you'd like the track to be:\n1 - short\n2 - standard\n3 - long\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1) 
										length = 50;
									else if(response == 2)
										length = 100;
									else
										length = 200;
									cout<< "Please enter the number of laps you'd like to complete: ";
									cin>> laps;
									cin.ignore(1, '\n');
									cout<< "And finally, please choose the type of track you'd like to race on:\n1 - road\n2 - offroad\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									DLL<_4WD> track(response, length, laps);
									track += *i;
									cout<< "\n\nOn your marks...\n\nGet set...\n\nGO!" <<endl;
									int time1 = track.race_track();
									cout<< "First vehicle time: " << time1 << " seconds." <<endl;
									track += *j;
									int time2 = track.race_track();
									cout<< "Second vehicle time: " << time2 << " seconds." <<endl;
									if(time1 == time2) 
										cout<< "It's a tie!" <<endl;
									else if(time1 < time2) {
										cout<< "\n";
										(*i).display_name();
										cout<< " wins the race!" <<endl;
									}
									else {
										cout<< "\n";
										(*j).display_name();
										cout<< " wins the race!" <<endl;
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			else if(response == 3) {
				if(supers.empty())
					cout<< "Add a super car and try again!" <<endl;
				else {
					cout<< "All super cars: ";
					display_list(response);
					cout<< "\nPlease enter the name of the first super car you'd like to enter into this race: ";
					cin.get(c_response, 50, '\n');
					cin.ignore(1, '\n');
					for(list<super>::iterator i = supers.begin(); i != supers.end(); ++i) {
						if((*i).compare_name(c_response)) {
							int length = 0;
							int laps = 0;
							cout<< "super car ";
							(*i).display_name();
							cout<< " retrieved!\nAll super cars: ";
							display_list(response);
							cout<< "\nPlease enter the name of the second super car you'd like to enter into this race: ";
							cin.get(c_response, 50, '\n');
							cin.ignore(1, '\n');	
							for(list<super>::iterator j = supers.begin(); j != supers.end(); ++j) {
								if((*j).compare_name(c_response)) {
									cout<< "Please enter the length you'd like the track to be:\n1 - short\n2 - standard\n3 - long\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									if(response == 1) 
										length = 50;
									else if(response == 2)
										length = 100;
									else
										length = 200;
									cout<< "Please enter the number of laps you'd like to complete: ";
									cin>> laps;
									cin.ignore(1, '\n');
									cout<< "And finally, please choose the type of track you'd like to race on:\n1 - road\n2 - offroad\nEnter here: ";
									cin>> response;
									cin.ignore(1, '\n');
									DLL<super> track(response, length, laps);
									track += *i;
									cout<< "\n\nOn your marks...\n\nGet set...\n\nGO!" <<endl;
									int time1 = track.race_track();
									cout<< "First vehicle time: " << time1 << " seconds." <<endl;
									track += *j;
									int time2 = track.race_track();
									cout<< "Second vehicle time: " << time2 << " seconds." <<endl;
									if(time1 == time2) 
										cout<< "\nIt's a tie!" <<endl;
									else if(time1 < time2) {
										cout<< "\n";
										(*i).display_name();
										cout<< " wins the race!" <<endl;
									}
									else {
										cout<< "\n";
										(*j).display_name();
										cout<< " wins the race!" <<endl;
									}
									break;
								}
							}
							break;
						}
					}
				}
			}
			response = 0;

		}
		else if(response == 8) { //Leaves the program
		
		}
		else
			cout<< "\nPlease enter a response in the range 1-8" <<endl;
	}
	return true;
}

bool client::display_list(int choice) {
	if(choice == 1) {
		for(list<motorcycle>::iterator i = motorcycles.begin(); i != motorcycles.end(); ++i) {
			(*i).display_name();
			cout<< "  ";
		}
		return true;
	}
	else if(choice == 2) {
		for(list<_4WD>::iterator i = _4WDs.begin(); i != _4WDs.end(); ++i) {
			(*i).display_name();
			cout<< "  ";
		}
		return true;
	}
	else if(choice == 3) {
		for(list<super>::iterator i = supers.begin(); i != supers.end(); ++i) {
			(*i).display_name();
			cout<< "  ";
		}
		return true;
	}
	else
		return false;
}
