//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the header file for the main hiearchy of program 2. This will include the vehicle class as well as derived classes: motorcycle, _4WD, and super. These functions allow the user to utilize overloaded operators for each class as well as create and adjust instances of each class. Users can add modifications to adjust the stats of the vehicles as well as adjust one special feature unique to each of the derived classes. 

#include <iostream>
#include <cctype>
#include <cstring>
#include <list>

using namespace std;

class vehicle_mod {
	public:
		vehicle_mod();
		vehicle_mod(int set_id);
		bool operator==(const vehicle_mod& to_compare);
		friend ostream& operator<<(ostream& out, const vehicle_mod& source);
		
		void display();
		bool set_mod(int to_set);
		bool compare_id(int to_compare);
		int get_id();
		int get_handling();
		int get_hp();
		int get_road();
		int get_offroad();

	private:
		int mod_id;
		int hp_boost;
		int handling_boost;
		int road_boost;
		int offroad_boost;
};
		

class vehicle {
	public:
		vehicle();
		~vehicle();
		vehicle(char* name_set);
		vehicle(const vehicle& source);
		vehicle& operator=(const vehicle& source); //These operators work the same for all classes in the hierarchy
		bool operator==(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if they have equivalent stats
		bool operator!=(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if they do not have equivalent stats
		bool operator<(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if the first class in the order is worse than the compared vehicle
		bool operator>(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if the first class in the order is better than the compare vehicle
		bool operator<=(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if the first class in the order is worse or equal to the compared vehicle
		bool operator>=(const vehicle& to_compare); //Compares the total_stats member of two vehicle classes to determine if the first class in the order is better or equal to the compared vehicle
		friend ostream& operator<<(ostream& out, vehicle& source); //Calls the display function to display all information relating to the vehicle class
		friend istream& operator>>(istream& in, vehicle& source); //Enters developer mode to allow the user to manually enter all stats for the vehicle
		
			
		void display(); //Displays all information relating to this vehicle
		void display_name(); //Displays just the name of this vehicle
		bool display_mods(); //Displays all the mods enabled on this vehicle thru the mods list
		bool set_name(const char* to_set); //Allows the name of the vehicle to be changed
		bool create_vehicle(const char* name_set); //Creates a new vehicle, automatically giving it a name thru the supplied argument name_set and giving it default stats of 10
		bool set_stats(int h_set, int hp_set, int r_set, int or_set); //Sets all the stats of a vehicle to the corresponding supplied arguments
		bool add_mod(int to_add); //Adds a mod to the vehicle and automatically adjusts stats 
		bool remove_mod(int to_remove);	 //Removes a mod from the vehicle and automatically adjusts stats
		bool compare_name(char* to_compare); //Compares the name of a vehicle with the supplied argument to_compare, if the name is the same, true is returned
		bool check_roll(int stat_check, int roll_check); //Checks whether the stat corresponding to the stat_check argument is greater than or less than the roll_check argument, returns true if greater than

	protected:
		char* name;
		int type;
		int horsepower;
		int handling;
		int road_grip;
		int offroad_grip;
		int total_stats;
		list<vehicle_mod> vehicle_mods;		
};

class motorcycle: public vehicle {
	public:
		motorcycle();
		~motorcycle();
		motorcycle(const motorcycle& source);
		motorcycle(char* name_set);
		motorcycle& operator=(const motorcycle& source);
		bool operator==(const motorcycle& to_compare);	
		bool operator!=(const motorcycle& to_compare);
		bool operator<(const motorcycle& to_compare);
		bool operator>(const motorcycle& to_compare);
		bool operator<=(const motorcycle& to_compare);
		bool operator>=(const motorcycle& to_compare);
		friend ostream& operator<<(ostream& out, motorcycle& source);
		friend istream& operator>>(istream& in, motorcycle& source);	
	
		void display();	
		bool set_motorcycle_type(int set_type); //Lets you choose your motorcycle type (street, dirtbike, etc..), the different motorcycle types each have unique stats

	private:
		int offroad_boost;
		int handling_boost;
		int road_boost;
		int horsepower_boost;	
		char* motorcycle_type;
};

class _4WD: public vehicle {
	public:
		_4WD();
		_4WD(char* name_set);
		_4WD& operator=(const _4WD& source);
		bool operator==(const _4WD& to_compare);	
		bool operator!=(const _4WD& to_compare);
		bool operator<(const _4WD& to_compare);
		bool operator>(const _4WD& to_compare);
		bool operator<=(const _4WD& to_compare);
		bool operator>=(const _4WD& to_compare);
		friend ostream& operator<<(ostream& out, _4WD& source);
		friend istream& operator>>(istream& in, _4WD& source);	
		
		void display();	
		bool set_tire_size(int set_size); //Lets you choose your tire size (standard, Large, Xtra-Large) to give a handling boost	
		
	
	private:
		int offroad_boost;
		int handling_boost;
		int road_boost;
		int horsepower_boost;
		int tire_size;
};

class super: public vehicle {
	public:
		super();
		super(char* name_set);
		super& operator=(const super& source);
		bool operator==(const super& to_compare);	
		bool operator!=(const super& to_compare);
		bool operator<(const super& to_compare);
		bool operator>(const super& to_compare);
		bool operator<=(const super& to_compare);
		bool operator>=(const super& to_compare);
		friend ostream& operator<<(ostream& out, super& source);
		friend istream& operator>>(istream& in, super& source);	
		
		void display();	
		bool apply_nitrous(bool to_set); //Lets you enable nitrous to give a horsepower boost.

	private:
		int offroad_boost;
		int handling_boost;
		int road_boost;
		int horsepower_boost;
		bool nitrous;
};
