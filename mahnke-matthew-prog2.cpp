//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the implementation of the main hierarchy, including the vehicle base class, motorcycle class, 4WD class, and super class. It will also include the implementation of the vehicle_mod class, which will exist in a list of vehicle mods in the vehicle base class. For more documentation on functions and overall class structure, see "mahnke-matthew-prog2.h"

#include "mahnke-matthew-prog2.h"


//----------vehicle_mod class member functions----------//
vehicle_mod::vehicle_mod() {
	hp_boost = 0;
	handling_boost = 0;
	road_boost = 0;
	offroad_boost = 0;
}	

vehicle_mod::vehicle_mod(int set_id) {
	set_mod(set_id);
}

bool vehicle_mod::operator==(const vehicle_mod& to_compare) {
	if(mod_id == to_compare.mod_id) return true;
	else return false;
}

ostream& operator<<(ostream& out, const vehicle_mod& source) {
	if(source.mod_id == 1)
		out<< "suspension+";
	else if(source.mod_id == 2)
		out<< "exhaust+";
	else if(source.mod_id == 3)
		out<< "diff+";
	else if(source.mod_id == 4) 
		out<< "tune+";
	else if(source.mod_id == 5)
		out<< "lift+";
	else if(source.mod_id == 6)
		out<< "supercharge+";
	return out;
}

void vehicle_mod::display() {
	cout<< "\nMod name: ";
	if(mod_id == 1)
		cout<< "suspension+";
	else if(mod_id == 2)
		cout<< "exhaust+";
	else if(mod_id == 3)
		cout<< "diff+";
	else if(mod_id == 4) 
		cout<< "tune+";
	else if(mod_id == 5)
		cout<< "lift+";
	else if(mod_id == 6)
		cout<< "supercharge+";
	cout << "\nHandling boost: " << handling_boost << "\nHorsepower boost: " << hp_boost << "\nRoad grip boost: " << road_boost << "\nOffroad grip boost: " << offroad_boost << endl;
	return;
}

bool vehicle_mod::compare_id(int to_compare) {
	if(mod_id == to_compare) return true;
	else return false;
}

bool vehicle_mod::set_mod(int set_id) { //Sets the mod based on argument given, automatically attributing stat boosts
	mod_id = set_id;
	if(mod_id == 1) {
		handling_boost = 10;
		offroad_boost = 10;
		road_boost = 0;
		hp_boost = 0;
	}
	else if(mod_id == 2) {
		road_boost = 5;
		hp_boost = 5;
		offroad_boost = 0;
		handling_boost = 0;
	}
	else if(mod_id == 3) {
		road_boost = 10;
		offroad_boost = 10;	
		hp_boost = 0;
		handling_boost = 0;
	}
	else if(mod_id == 4) {
		hp_boost = 5;
		handling_boost = 5;
		road_boost = 0;
		offroad_boost = 0;
	}
	else if(mod_id == 5) {
		handling_boost = 10;
		offroad_boost = 10;
		road_boost = 0;
		hp_boost = 0;
	}
	else if(mod_id == 6) {
		hp_boost = 5;
		road_boost = 5;
		offroad_boost = 0;
		handling_boost = 0;
	}

	return true;
}

int vehicle_mod::get_id() {
	return mod_id;
}

int vehicle_mod::get_handling() {
	return handling_boost;
}

int vehicle_mod::get_hp() {
	return hp_boost;
}

int vehicle_mod::get_road() {
	return road_boost;
}

int vehicle_mod::get_offroad() {
	return offroad_boost;
}

//----------vehicle class member functions----------//
vehicle::vehicle() {
	name = nullptr;
	handling = 20;
	road_grip = 20;
	offroad_grip = 20;
	horsepower = 20;
}

vehicle::vehicle(char* name_set) {
	create_vehicle(name_set);
}

vehicle::~vehicle() {
	if(name) {
		delete name;
		name = nullptr;
	}
}

vehicle::vehicle(const vehicle& source) {
	if(name) delete name;
	name = new char[strlen(source.name) + 1];
	strcpy(name, source.name);
	type = source.type;
	handling = source.handling;
	offroad_grip = source.offroad_grip;
	road_grip = source.road_grip;
	horsepower = source.horsepower;
}

//----------vehicle class overloaded operator implementations----------//
vehicle& vehicle::operator=(const vehicle& source) {
	if(name) delete name;
	name = new char[strlen(source.name) + 1];
	strcpy(name, source.name);
	handling = source.handling;
	offroad_grip = source.offroad_grip;
	road_grip = source.road_grip;
	horsepower = source.horsepower;
	return *this;
}

bool vehicle::operator==(const vehicle& to_compare) { //Checks if two vehicle's total stats are equal with another
	if(total_stats == to_compare.total_stats) return true;
	else return false;
}

bool vehicle::operator!=(const vehicle& to_compare) { //Checks if a vehicle's total stats are not equal with another
	if(total_stats != to_compare.total_stats) return true;
	else return false;
}	

bool vehicle::operator>(const vehicle& to_compare) { //Checks if a vehicle's total stats are greater than another's
	if(total_stats > to_compare.total_stats) return true;
	else return false;
}

bool vehicle::operator<(const vehicle& to_compare) { //Checks if a vehicle's total stats are less than another's
	if(total_stats < to_compare.total_stats) return true;
	else return false;
}

bool vehicle::operator>=(const vehicle& to_compare) { //Checks if a vehicle's total stats are greater than or equal to another's
	if(total_stats >= to_compare.total_stats) return true;
	else return false;
}

bool vehicle::operator<=(const vehicle& to_compare) { //Checks if a vehicle's total stats are less than or equal to another's
	if(total_stats <= to_compare.total_stats) return true;
	else return false;
}

ostream& operator<<(ostream& out, vehicle& source) {
	source.display();
	return out;
}

istream& operator>>(istream& in, vehicle& source) {
	int t_handling = 0;
	int t_horsepower = 0;
	int t_road = 0;
	int t_offroad = 0;
	cout<< "\nEditing vehicle: ";
	source.display_name();
	cout<< "\nWhat would you like to set handling to?\nEnter here: ";
	in>> t_handling;
	in.ignore(1, '\n');
	cout<< "What would you like to set horsepower to?\nEnter here: ";
	in>> t_horsepower;
	in.ignore(1, '\n');
	cout<< "What would you like to set road grip to?\nEnter here: ";
	in>> t_road;
	in.ignore(1, '\n');
	cout<< "What would you like to set offroad grip to?\nEnter here: ";
	in>> t_offroad;
	in.ignore(1, '\n');
	source.set_stats(t_handling, t_horsepower, t_road, t_offroad);
	cout<< "Editing finished! Current vehicle values: " << source;
	return in;
}
//------------------------------//

void vehicle::display() {
	cout<< "\nVehicle name: " << name;
	 cout<< "\nHandling: " << handling << "\nHorsepower: " << horsepower << "\nOffroad grip: " << offroad_grip << "\nRoad grip: " << road_grip << endl;
	return;
}

void vehicle::display_name() {
	cout<< name;
	return;
}

bool vehicle::create_vehicle(const char* name_set) {
	name = new char[strlen(name_set) + 1];
	strcpy(name, name_set);
	handling = 10;
	horsepower = 10;
	road_grip = 10;
	offroad_grip = 10;
	total_stats = handling + horsepower + road_grip + offroad_grip;
	return true;
}	

bool vehicle::set_name(const char* to_set) {
	if(name) delete name;
	name = new char[strlen(to_set) + 1];
	strcpy(name, to_set);
	if(name != nullptr) return true;
	else return false;
}

bool vehicle::set_stats(int h_set, int hp_set, int r_set, int or_set) {
	handling = h_set;
	horsepower = hp_set;
	road_grip = r_set;
	offroad_grip = or_set;
	total_stats = handling + horsepower + road_grip + offroad_grip;
	return true;
}

bool vehicle::add_mod(int to_add) {
	vehicle_mod temp(to_add);
	vehicle_mods.push_back(to_add);
	handling += temp.get_handling();
	horsepower += temp.get_hp();
	road_grip += temp.get_road();
	offroad_grip += temp.get_offroad();
	total_stats = handling + horsepower + road_grip + offroad_grip;
	return true;
}	

bool vehicle::remove_mod(int to_remove) {
	for(list<vehicle_mod>::iterator i = vehicle_mods.begin(); i != vehicle_mods.end(); ++i) {
		if((*i).compare_id(to_remove)) {
			handling -= (*i).get_handling();
			horsepower -= (*i).get_hp();
			road_grip -= (*i).get_road();
			offroad_grip -= (*i).get_offroad();
			total_stats = handling + horsepower + road_grip + offroad_grip;
			vehicle_mods.remove(*i);
			return true;
		}
	}
	return false;
}

bool vehicle::display_mods() {
	if(vehicle_mods.empty()) return false;
	for(list<vehicle_mod>::iterator i = vehicle_mods.begin(); i != vehicle_mods.end(); ++i) {
		cout<< *i << "  ";
	}
	return true;
}

bool vehicle::compare_name(char* to_compare) {
	if(!strcmp(name, to_compare)) return true;
	else return false;
}

bool vehicle::check_roll(int stats_check, int roll_check) {
	if(stats_check == 0) {
		return handling >= roll_check;	
	}
	else if(stats_check == 1) {
		return offroad_grip >= roll_check;	
	}
	else if(stats_check == 2) {
		return horsepower >= roll_check;
	}
	else if(stats_check == 3) {
		return road_grip >= roll_check;
	}
	else
		return false;
}

//----------motorcycle member function implementations----------//
motorcycle::motorcycle() {
	handling_boost = 20;
	road_boost = 0;
	offroad_boost = 20;
	horsepower_boost = 0;
	handling += handling_boost;
	offroad_grip += offroad_boost; 
	motorcycle_type = new char[strlen("dirtbike") + 1];
	strcpy(motorcycle_type, "dirtbike");
}

motorcycle::motorcycle(char* name_set): vehicle(name_set) {
	handling_boost = 20;
	road_boost = 0;
	offroad_boost = 20;
	horsepower_boost = 0;
	handling += handling_boost;
	offroad_grip += offroad_boost; 
	motorcycle_type = new char[strlen("dirtbike") + 1];
	strcpy(motorcycle_type, "dirtbike");
}

motorcycle::motorcycle(const motorcycle& source): vehicle(source) {
	handling_boost = source.handling_boost;
	road_boost = source.road_boost;
	offroad_boost = source.offroad_boost;
	horsepower_boost = source.horsepower_boost;
	delete motorcycle_type;
	motorcycle_type = new char[strlen(source.motorcycle_type)];
	strcpy(motorcycle_type, source.motorcycle_type);
}

motorcycle::~motorcycle() {
	if(motorcycle_type) {
		delete motorcycle_type;
		motorcycle_type = nullptr;
	}
}

//----------motorcycle class overloaded operator implementations----------//
motorcycle& motorcycle::operator=(const motorcycle& source)  {
	vehicle::operator=(source);
	handling_boost = source.handling_boost;
	road_boost = source.road_boost;
	offroad_boost = source.offroad_boost;
	horsepower_boost = source.horsepower_boost;
	delete motorcycle_type;
	motorcycle_type = new char[strlen(source.motorcycle_type)];
	strcpy(motorcycle_type, source.motorcycle_type);
	return *this;
}

bool motorcycle::operator==(const motorcycle& to_compare) {
	return vehicle::operator==(to_compare);
}

bool motorcycle::operator!=(const motorcycle& to_compare) {
	return vehicle::operator!=(to_compare);
}

bool motorcycle::operator<(const motorcycle& to_compare) {
	return vehicle::operator<(to_compare);

}

bool motorcycle::operator>(const motorcycle& to_compare) {
	return vehicle::operator>(to_compare);

}

bool motorcycle::operator<=(const motorcycle& to_compare) {
	return vehicle::operator<=(to_compare);

}

bool motorcycle::operator>=(const motorcycle& to_compare) {
	return vehicle::operator>=(to_compare);

}

ostream& operator<<(ostream& out, motorcycle& source) {
	source.display();
	return out;
}

istream& operator>>(istream& in, motorcycle& source) {
	int t_handling = 0;
	int t_horsepower = 0;
	int t_road = 0;
	int t_offroad = 0;
	cout<< "\nEditing vehicle: ";
	source.display_name();
	cout<< "\nWhat would you like to set handling to?\nEnter here: ";
	in>> t_handling;
	in.ignore(1, '\n');
	cout<< "What would you like to set horsepower to?\nEnter here: ";
	in>> t_horsepower;
	in.ignore(1, '\n');
	cout<< "What would you like to set road grip to?\nEnter here: ";
	in>> t_road;
	in.ignore(1, '\n');
	cout<< "What would you like to set offroad grip to?\nEnter here: ";
	in>> t_offroad;
	in.ignore(1, '\n');
	source.set_stats(t_handling, t_horsepower, t_road, t_offroad);
	cout<< "Editing finished! Current vehicle values: " << source;
	return in;

}
//------------------------------//

void motorcycle::display() {
	cout<< "\nVehicle type: motorcycle\nMotorcycle type: " << motorcycle_type;
	vehicle::display();
	return;
}

bool motorcycle::set_motorcycle_type(int set_type) {
	char temp[50];
	if(motorcycle_type)
		delete motorcycle_type;
	if(set_type == 1) 
		strcpy(temp, "dirtbike");
	else if(set_type == 2)
		strcpy(temp, "streetbike");
	else if(set_type == 3)
		strcpy(temp, "ATV");
	else
		return false;	
	motorcycle_type = new char[strlen(temp) + 1];
	strcpy(motorcycle_type, temp);
	if(!strcmp("dirtbike", motorcycle_type)) {
		handling -= handling_boost;
		offroad_grip -= offroad_boost;
		horsepower -= horsepower_boost;
		road_grip -= road_boost;
		offroad_boost = 20;
		handling_boost = 20;
		road_boost = 0;
		horsepower_boost = 0;
		handling += handling_boost;
		offroad_grip += offroad_boost;
	}
	else if(!strcmp("streetbike", motorcycle_type)) {
		handling -= handling_boost;
		offroad_grip -= offroad_boost;
		horsepower -= horsepower_boost;
		road_grip -= road_boost;
		road_boost = 20;
		handling_boost = 10;
		horsepower_boost = 10;
		offroad_boost = 0;
		handling += handling_boost;
		road_grip += road_boost;
		horsepower += horsepower_boost;
	}
	else if(!strcmp("ATV", motorcycle_type)) {
		handling -= handling_boost;
		offroad_grip -= offroad_boost;
		horsepower -= horsepower_boost;
		road_grip -= road_boost;
		road_boost = 5;
		handling_boost = 20;
		horsepower_boost = 5;
		offroad_boost = 10;
		handling += handling_boost;
		road_grip += road_boost;
		horsepower += horsepower_boost;
		offroad_grip += offroad_boost;
	}
	else return false;
	return true;
}

//---------_4WD class member function implementations----------//
_4WD::_4WD() {
	handling_boost = 10;
	horsepower_boost = 10;
	road_boost = 10;
	offroad_boost = 10;
	handling += handling_boost;
	horsepower += horsepower_boost;
	road_grip += road_boost;
	offroad_grip += offroad_boost;
	tire_size = 0;
}

_4WD::_4WD(char* name_set): vehicle(name_set) {
	handling_boost = 10;
	horsepower_boost = 10;
	road_boost = 10;
	offroad_boost = 10;
	handling += handling_boost;
	horsepower += horsepower_boost;
	road_grip += road_boost;
	offroad_grip += offroad_boost;
	tire_size = 0;
}

//----------_4WD class overloaded operator implementations----------//
_4WD& _4WD::operator=(const _4WD& source)  {
	vehicle::operator=(source);
	handling_boost = source.handling_boost;
	road_boost = source.road_boost;
	offroad_boost = source.offroad_boost;
	horsepower_boost = source.horsepower_boost;
	tire_size = source.tire_size;
	return *this;
}

bool _4WD::operator==(const _4WD& to_compare) {
	return vehicle::operator==(to_compare);
}

bool _4WD::operator!=(const _4WD& to_compare) {
	return vehicle::operator!=(to_compare);
}

bool _4WD::operator<(const _4WD& to_compare) {
	return vehicle::operator<(to_compare);

}

bool _4WD::operator>(const _4WD& to_compare) {
	return vehicle::operator>(to_compare);

}

bool _4WD::operator<=(const _4WD& to_compare) {
	return vehicle::operator<=(to_compare);

}

bool _4WD::operator>=(const _4WD& to_compare) {
	return vehicle::operator>=(to_compare);

}

ostream& operator<<(ostream& out, _4WD& source) {
	source.display();
	return out;
}

istream& operator>>(istream& in, _4WD& source) {
	int t_handling = 0;
	int t_horsepower = 0;
	int t_road = 0;
	int t_offroad = 0;
	cout<< "\nEditing vehicle: ";
	source.display_name();
	cout<< "\nWhat would you like to set handling to?\nEnter here: ";
	in>> t_handling;
	in.ignore(1, '\n');
	cout<< "What would you like to set horsepower to?\nEnter here: ";
	in>> t_horsepower;
	in.ignore(1, '\n');
	cout<< "What would you like to set road grip to?\nEnter here: ";
	in>> t_road;
	in.ignore(1, '\n');
	cout<< "What would you like to set offroad grip to?\nEnter here: ";
	in>> t_offroad;
	in.ignore(1, '\n');
	source.set_stats(t_handling, t_horsepower, t_road, t_offroad);
	cout<< "Editing finished! Current vehicle values: " << source;
	return in;

}
//------------------------------//
void _4WD::display() {
	cout<< "\nVehicle type: 4WD\nTire size: ";
	if(tire_size == 0)
		cout<< "Standard";
	else if(tire_size == 1)
		cout<< "Large";
	else if(tire_size == 2)
		cout<< "X-Large";
	cout<< "\nVehicle name: " << name << "\nHandling: " << handling << "\nHorsepower: " << horsepower << "\nOffroad grip: " << offroad_grip << "\nRoad grip: " << road_grip << endl;
	return;
}

bool _4WD::set_tire_size(int set_size) {
	if(set_size == 1) {
		if(tire_size == 2) {
			handling -= 5;
			offroad_grip -= 5;
			road_grip += 5;
			handling_boost -= 5;
			offroad_boost -= 5;
			road_boost += 5;	
		}
		else if(tire_size == 3) {
			handling -= 10;
			offroad_grip -= 10;
			road_grip += 10;
			handling_boost -= 10;
			offroad_boost -= 10;
			road_boost += 10;			
		}
		tire_size = set_size;
	}
	else if(set_size == 2) {
		handling -= handling_boost;
		offroad_grip -= offroad_boost;
		road_grip -= road_boost;
		handling_boost += 5;
		offroad_boost += 5;
		road_boost -= 5;
		handling += handling_boost;
		offroad_grip += offroad_boost;
		road_grip += road_boost;
		tire_size = set_size;
	}
	else if(set_size == 3) {
		handling -= handling_boost;
		offroad_grip -= offroad_boost;
		road_grip -= road_boost;
		handling_boost += 10;
		offroad_boost += 10;
		road_boost -= 10;
		handling += handling_boost;
		offroad_grip += offroad_boost;
		road_grip += road_boost;
		tire_size = set_size;
	}
	else 
		return false;
	return true;
}

//----------super class member function implementations----------//
super::super() {
	road_boost = 20;
	horsepower_boost = 20;
	handling_boost = 0;
	offroad_boost = 0;
	road_grip += road_boost;
	horsepower += horsepower_boost;
	nitrous = false;
}

super::super(char* name_set): vehicle(name_set) {
	road_boost = 20;
	horsepower_boost = 20;
	offroad_boost = 0;
	handling_boost = 0;
	road_grip += road_boost;
	horsepower += horsepower_boost;
	nitrous = false;
}

//----------super class overloaded operator implementations----------//
super& super::operator=(const super& source)  {
	vehicle::operator=(source);
	handling_boost = source.handling_boost;
	road_boost = source.road_boost;
	offroad_boost = source.offroad_boost;
	horsepower_boost = source.horsepower_boost;
	nitrous = source.nitrous;
	return *this;
}

bool super::operator==(const super& to_compare) {
	return vehicle::operator==(to_compare);
}

bool super::operator!=(const super& to_compare) {
	return vehicle::operator!=(to_compare);
}

bool super::operator<(const super& to_compare) {
	return vehicle::operator<(to_compare);

}

bool super::operator>(const super& to_compare) {
	return vehicle::operator>(to_compare);

}

bool super::operator<=(const super& to_compare) {
	return vehicle::operator<=(to_compare);

}

bool super::operator>=(const super& to_compare) {
	return vehicle::operator>=(to_compare);

}

ostream& operator<<(ostream& out, super& source) {
	source.display();
	return out;
}

istream& operator>>(istream& in, super& source) {
	int t_handling = 0;
	int t_horsepower = 0;
	int t_road = 0;
	int t_offroad = 0;
	cout<< "\nEditing vehicle: ";
	source.display_name();
	cout<< "\nWhat would you like to set handling to?\nEnter here: ";
	in>> t_handling;
	in.ignore(1, '\n');
	cout<< "What would you like to set horsepower to?\nEnter here: ";
	in>> t_horsepower;
	in.ignore(1, '\n');
	cout<< "What would you like to set road grip to?\nEnter here: ";
	in>> t_road;
	in.ignore(1, '\n');
	cout<< "What would you like to set offroad grip to?\nEnter here: ";
	in>> t_offroad;
	in.ignore(1, '\n');
	source.set_stats(t_handling, t_horsepower, t_road, t_offroad);
	cout<< "Editing finished! Current vehicle values: " << source;
	return in;

}
//------------------------------//

void super::display() {
	cout<< "\nVehicle type: super\nNitrous: ";
	if(nitrous == false)
		cout<< "off";
	else if(nitrous == true)
		cout<< "on";
	cout<< "\nVehicle name: " << name << "\nHandling: " << handling << "\nHorsepower: " << horsepower << "\nOffroad grip: " << offroad_grip << "\nRoad grip: " << road_grip << endl;
	return;
}

bool super::apply_nitrous(bool to_set) {
	if(nitrous == true  &&  to_set == false) {
		nitrous = to_set;
		horsepower_boost -= 10;
		horsepower -= 10;
		return false;
	}
	else if(nitrous == true) return true;
	else if(to_set == false) return false;
	nitrous = to_set;
	horsepower_boost += 10;
	horsepower += 10;
	return true;
}
