//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the header file for the node and DLL template classes, allowing for different vehicles from the main hierarchy to be raced on randomized race tracks through the DLL class.

#include "mahnke-matthew-prog2.h"

template<class TYPE>
class node {
	public:
		node();
		node(const TYPE& to_set, int track_set, bool c_set);
		node(int track_set, bool c_set);
		node(const node<TYPE> * source);
	
		void display();	
		bool set_data(const TYPE& to_set); 
		bool roll_stats(); //This function will execute a bit of randomized logic to determine what stat of the car will be checked for this section of the race and how high the check is, then passing this information into the compare_roll() function below
		bool compare_roll(int stat_check, int roll_check); //Takes input from the roll_stats() function, passes this information to the check_stats() function and then returns the result
		bool set_next(node<TYPE> * to_set);
		bool set_prev(node<TYPE> * to_set);
		node<TYPE>* get_prev();
		node<TYPE>* get_next();
		
	private:
		TYPE data;
		int track_type;
		bool corner; //Indicates whether this section of the track is a corner or not, if it is a corner, different stats are checked vs. a usual piece of the track
		node<TYPE> * next; 
		node<TYPE> * prev;
};

template<class TYPE>
class DLL {
	public:
		DLL();
		~DLL();
		DLL(int set_track, int set_length, int set_laps);
		DLL<TYPE>& operator=(const DLL<TYPE>& source);
		DLL<TYPE>& operator+=(const TYPE& source);
			
		bool add_vehicle(const TYPE& to_add); //Sets or changes the vehicle currently racing the track
		bool build_track(int type); //Builds a list to act as the race track; depends on value from the length member
		bool remove_vehicle(TYPE& remove); //Removes the vehicle currently racing the track from the list
		bool delete_track(); //Deletes the entire track
		int race_track(); //Races the track, calling the roll_stats() function on each node. If roll_stats() returns true, that node is passed with relative ease and only 1 second is added to the time, otherwise 2 seconds is added to the time. Returns the value of the member time to indicate how long that vehicle took to race the track
		bool copy_DLL(const DLL<TYPE>& source);

	private:
		int track_type;
		int length; //Indicates whether the track will be short (50 nodes), standard (100 nodes), long (200 nodes)
		int laps; //Indicates the number of times the track will be raced by the vehicle	
		int time; //The total time it takes for a vehicle to race the track, returned by the race_track() function
		node<TYPE> * head;
		bool delete_after_node(node<TYPE> * head); //Supplemental function for the copy_DLL function
		bool add_vehicle(const TYPE& to_add, node<TYPE> * head);	
		bool build_track(int type, int count);
		bool copy_DLL(node<TYPE> * head, node<TYPE> * prev, node<TYPE> * source);
		bool delete_track(node<TYPE> * head);
		int race_track(node<TYPE> * head);
};

#include "DLL.tpp"
