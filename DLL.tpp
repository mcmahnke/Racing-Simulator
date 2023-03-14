//Name: Matthew Mahnke
//Date: 2/20/23
//Purpose: The purpose of this file is to act as the implementation for the template classes node and DLL, allowing for full funcionality of DLL as a race track for this program. The template is designed to work with class types motorcycle, _4WD, and super. For more documentation, see "DLL.h"


//----------node class member function implementations----------//
template <class TYPE>
node<TYPE>::node(): track_type(0), next(nullptr), prev(nullptr), corner(false) {
}

template<class TYPE>
node<TYPE>::node(const TYPE& to_set, int track_set, bool c_set): data(to_set), track_type(track_set), next(nullptr), prev(nullptr), corner(c_set) {
}

template<class TYPE>
node<TYPE>::node(int track_set, bool c_set): track_type(track_set), corner(c_set), next(nullptr), prev(nullptr) {
}

template<class TYPE>
node<TYPE>::node(const node * source): track_type(source.track_type), next(source.next), prev(source.prev), corner(source.corner) {
}

template<class TYPE>
void node<TYPE>::display() {
	cout<< "\nCorner: ";
	if(corner)
		cout<< "yes" <<endl;
	else
		cout<< "no" <<endl;
	cout<< "Vehicle Information: ";
	cout<< data;
	cout<< "Track type: ";
	if(track_type == 1) 
		cout<< "road";
	else 
		cout<< "offroad";
	return;
}

template<class TYPE>
bool node<TYPE>::set_data(const TYPE& to_set) {
	data = to_set;
	return true;
}

template<class TYPE>
bool node<TYPE>::roll_stats() {
	int stat = 0;
	int roll = 0;
	int chance = 0;
	if(track_type == 0) return false;
	if(corner == true) { //Checks whether this node of the track is a corner, if it is a corner relevant stats (handling, horsepower) are rolled from 0-39 to check whether the car clears this node.
		chance = rand() & 2;
		if(chance == 0) 
			stat = 0;
		else
			stat = 2;
		roll = rand() % 40;
		return compare_roll(stat, roll);
	}	
	else if(track_type == 1) { //1 = road track type
		chance = rand() % 4; //Rolls for 0-3, if it lands on a 0, 1, or 2, giving this possibility a 75% cahnce, stats relevant to driving on the road (horsepower, road_grip) are rolled at random from 0-39. Otherwise if it lands on 3, stats for stats not relevant to driving on the road (handling, offroad_grip) are rolled from 0-49, making those checks more challenging than the relevant stats.
		if(chance == 3) {
			stat = rand() % 2;
			roll = rand() % 50;
			return compare_roll(stat, roll);	
		}
		else {
			stat = 2 + (rand() % 2);
			roll = rand() % 40;
			return compare_roll(stat, roll);
		}
	}
	else if(track_type == 2) { //2 represents an offroad track
		chance = rand() % 4;
		if(chance == 3) {
			stat = 2 + (rand() % 2);
			roll = rand() % 50;
			return compare_roll(stat, roll);
		}
		else {
			stat = rand() % 2;
			roll = rand() % 40;
			return compare_roll(stat, roll);
		}
	}
	else return false;
}
			
template<class TYPE>
bool node<TYPE>::compare_roll(int stat_check, int roll_check) {
	return data.check_roll(stat_check, roll_check);
}

template<class TYPE>		
bool node<TYPE>::set_next(node<TYPE> * to_set) {
	next = to_set;
	return true;
}

template<class TYPE>	
bool node<TYPE>::set_prev(node<TYPE> * to_set) {
	prev = to_set;
	return true;
}

template<class TYPE> 
node<TYPE>* node<TYPE>::get_next() {
	return next;
}	

template<class TYPE>
node<TYPE>* node<TYPE>::get_prev() {
	return prev;
}			
//----------DLL class member function implementations----------//
template<class TYPE>
DLL<TYPE>::DLL(): head(nullptr), track_type(0), laps(0), time(0), length(0) {
}

template<class TYPE>
DLL<TYPE>::DLL(int set_track, int set_length, int set_laps): track_type(set_track), length(set_length), laps(set_laps), head(nullptr) {
	build_track(track_type);
}

template<class TYPE>
DLL<TYPE>& DLL<TYPE>::operator=(const DLL<TYPE>& source) {
	copy_DLL(source);
	return *this;
}

template<class TYPE>
DLL<TYPE>& DLL<TYPE>::operator+=(const TYPE& source) {
	add_vehicle(source);
	return *this;
}

template<class TYPE>
DLL<TYPE>::~DLL() {
	delete_track();
}

template<class TYPE>
bool DLL<TYPE>::copy_DLL(const DLL<TYPE>& source) {
	track_type = source.track_type;
	length = source.length;
	laps = source.laps;
	node<TYPE> * prev = nullptr;
	return copy_DLL(head, prev, source.head);
}

template<class TYPE>
bool DLL<TYPE>::copy_DLL(node<TYPE> * head, node<TYPE> * prev, node<TYPE> * source) {
	if(!source && head) {
		delete_after_node(head);
		prev->set_next(nullptr);
		return true;
	}
	if(!source && !head) return false;
	if(!head) {
		head = new node<TYPE>(source);
		head->set_next(nullptr);	
		head->set_prev(prev);
		prev = head;
		return copy_DLL(head->get_next(), prev, source->get_next());
	}
	node<TYPE> * temp = head->get_next();
	delete head;
	head = new node<TYPE>(source);
	head->set_prev(prev);
	head->set_next(temp);
	prev = head;
	return copy_DLL(head->get_next(), prev, source->get_next());
}

template<class TYPE>
bool DLL<TYPE>::delete_after_node(node<TYPE> * head) {
	if(!head) return false;
	node<TYPE> * temp = head->get_next();
	delete head;
	return delete_after_node(temp);
}

template<class TYPE>
bool DLL<TYPE>::add_vehicle(const TYPE& to_add) {
	return add_vehicle(to_add, head);
}
		
template<class TYPE>
bool DLL<TYPE>::add_vehicle(const TYPE& to_add, node<TYPE> * head) { //Works for the race by setting each node's data to the vehicle currently racing the course so that the proper functions to check whether the node, representing a section of the course, is passed without difficulty or not 
	if(!head) return false;
	head->set_data(to_add);	
	return add_vehicle(to_add, head->get_next());
}

template<class TYPE>
bool DLL<TYPE>::build_track(int type) {
	int count = 0;
	if(head) delete head;
	head = new node<TYPE>(type, false);
	head->set_next(nullptr);
	head->set_prev(nullptr);
	return build_track(type, count);
}

template<class TYPE>
bool DLL<TYPE>::build_track(int type, int count) {
	int chance = rand() % 8;
	node<TYPE> * temp = nullptr;
	if(chance == 7) 
		temp = new node<TYPE>(type, true);
	else
		temp = new node<TYPE>(type, false);
	temp->set_prev(nullptr);
	temp->set_next(this->head);
	if(this->head)
		this->head->set_prev(temp);	
	this->head = temp;
	if(count == length) return true;
	count++;
	return build_track(type, count);
}

template<class TYPE>
int DLL<TYPE>::race_track() {	
	for(int i = 0; i <= laps; ++i)
		race_track(head);
	int ret = time;
	time = 0;
	return ret;
}

template<class TYPE>
int DLL<TYPE>::race_track(node<TYPE> * head) {
	if(!head) return time;
	if(head->roll_stats()) //If a section of the track is passed without difficulty, 1 second is added to the total time
		time += 1;
	else
		time += 2; //Otherwise, 2 seconds is added to the total time
	return race_track(head->get_next());
}

template<class TYPE>
bool DLL<TYPE>::delete_track() {
	return delete_track(head);
}

template<class TYPE>
bool DLL<TYPE>::delete_track(node<TYPE> * head) {
	if(!head) return true;
	node<TYPE> * temp = head->get_next();
	delete head;
	head = temp;
	return delete_track(head);
}
	
