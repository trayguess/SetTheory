#include "set.h"
#include "pitch.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

//Not in .cpp: class keyword, variable declarations, public/private, static, friend

//Prefix each function with namespace

//Constructors


Set::Set(Pitch const input_pitch) { //construct using a single Pitch object
	this->pitches.push_back(input_pitch);

	generate_intervals();
}

Set::Set(int const input_pitch) { //construct using a single integer representing pitch class

	Pitch new_pitch = Pitch(input_pitch);

	this->pitches.push_back(new_pitch);

	generate_intervals();
}

Set::Set(std::vector<Pitch> const input_vector) { //construct using vector of Pitch objects
	for (int i = 0; i < input_vector.size(); i++) {
		this->pitches.push_back(input_vector[i]);
	}

	generate_intervals();
}

Set::Set(std::vector<int> const input_vector) { //construct using a vector of int pitches
	for (int i = 0; i < input_vector.size(); i++) {
		Pitch new_pitch = Pitch(input_vector[i]);
		this->pitches.push_back(new_pitch);
	}
	
}




//Getters
std::string Set::get_set_string() { //returns a string in bracket format [a,b,...z]
	std::string output_string = "[";
	for (int i = 0; i < (this->pitches.size()); i++) {


		output_string += std::to_string(this->pitches[i].get_pitch_class());
		if (i != (this->pitches.size() - 1)) {
			output_string += ",";
		}
		
	}
	output_string += "]";
	return output_string;
}

std::string Set::get_set_string_named() { //returns a string with bracket format, named
	std::string output_string = "[";
	for (int i = 0; i < (this->pitches.size()); i++) {

		output_string += this->pitches[i].get_pitch_name();
		if (i != (this->pitches.size() - 1)) {
			output_string += ",";
		}

	}
	output_string += "]";
	return output_string;
}

std::string Set::get_intervals_string() {
	std::string output_string = "{";
	for (int i = 0; i < (this->intervals.size()); i++) {
		output_string += this->intervals[i].get_interval_name();
		if (i != (this->intervals.size() - 1)) {
			output_string += ",";
		}
	}
	output_string += "}";
	return output_string;
}


//Setters
void Set::add_pitch(Pitch const input_pitch) { //add a pitch to the end using Pitch object
	this->pitches.push_back(input_pitch);
}

void Set::add_pitch(int const input_pitch) { //add a pitch using an integer
	Pitch new_pitch = Pitch(input_pitch);
	this->pitches.push_back(new_pitch);
}

void Set::add_pitch(std::string const input_pitch) { //add a pitch using a name
	Pitch new_pitch = Pitch(input_pitch);
	this->pitches.push_back(new_pitch);
}


//Methods
void Set::play_all() {
	for (int i = 0; i < pitches.size(); i++) {
		pitches[i].play_pitch();
	}

}

void Set::randomize_all() { //Generates random pitches in the pitches vector. No repeats, same size.
	std::vector<int> possible_pitches;
	for (int i = 0; i < 12; i++) { //fill a vector with all pitches 0-11
		possible_pitches.push_back(i);
	}

	random_shuffle(possible_pitches.begin(), possible_pitches.end()); //shuffle

	for (int i = 0; i < pitches.size(); i++) { //Sequentially replace pitches with Pitch objects using our shuffled list
		Pitch tmp_pitch = Pitch(possible_pitches[i]);
		pitches[i] = tmp_pitch;
	}
}


void Set::generate_intervals() { //generates interval vector from current set and updates interval attribute
	intervals.clear(); //start with a blank vector

	for (int i = 0; i < pitches.size()-1;i++) { //Generate a new interval, add it to the vector
		Interval new_interval = Interval(pitches[i], pitches[i + 1]);
		this->intervals.push_back(new_interval);
	}
}

void Set::check_for_repeats() {

}



void Set::generate_normal_form() { //Takes existing vectors and calculates the normal form, inserting it into the vector
	if (pitches.size() == 0) { //no pitches? we're already in normal form
		return;
	}

	std::vector<Pitch> pitch_classes = pitches; //populate new vector of pitch classes

	//now we have an Pitch vector of pitch classes: time to write out each ascending order
	std::vector<std::vector<Pitch>> possibilities; //this vector will contain each possible ascending vector

	//now sort this vector
	std::sort(pitch_classes.begin(), pitch_classes.end());

	//then rotate the vector to get each possible starting number
	for (int i = 0; i < pitches.size(); i++) {
		pitch_classes.insert(pitch_classes.begin(), pitch_classes.back()); //take the final pitch and insert it at the beginning
		pitch_classes.pop_back(); //Remove final element as it's now at the front

		possibilities.push_back(pitch_classes); //Add current vector to our possibilities vector
	}
	
	Interval min_interval = Interval(11); //Initialize an Interval object; this will keep track of the lowest found interval
	std::vector<Pitch> min_interval_pitch_vector; //This vector contains the pitches at the current lowest found interval

	for (int i = 0; i < possibilities.size(); i++) { //Find vector with smallest interval
		Interval min_interval_b = Interval(11); //Initialize an second Interval object
		
		Interval new_interval(possibilities[i][0], possibilities[i][possibilities[i].size() - 1]);//create interval object from Pitch objects within posibilities at position i

		if (new_interval < min_interval) { //If current interval is lower, then replace our minimum interval vector
			min_interval_pitch_vector = possibilities[i]; //min_interval_pitch_vector updated with lowest interval found so far
			min_interval = new_interval;  //Update lowest interval tracker (Interval object)
		}
		





		//min_interval_pitch_vector should now contain the correct pitches.
	}


	//Set object vector to min_interval_pitch_vector
	pitches = min_interval_pitch_vector;
	generate_intervals(); //Update intervals


	//Next, get it to 0 base

	//std::cout << "Normal form (version B): " << get_set_string() << std::endl;

}

std::vector<Pitch> Set::get_smallest_interval(std::vector<Pitch> const input_vector) {
	Interval min_interval = Interval(11); //Initialize an Interval object; this will keep track of the lowest found interval
	std::vector<Pitch> min_interval_pitch_vector; //This vector contains the pitches at the current lowest found interval


}



void Set::generate_normal_form_old() { //Takes existing vectors and calculates the normal form, inserting it into the vector
	if (pitches.size() == 0) { //no pitches? we're already in normal form
		return;
	}

	std::vector<int> pitch_classes;


	for (int i = 0; i < pitches.size(); i++) { //populate vector of pitch classes
		pitch_classes.push_back(pitches[i].get_pitch_class());
	}


	//now we have an int vector of pitch classes: time to write out each ascending order
	std::vector<std::vector<int>> possibilities; //this vector will contain each possible ascending vector

	//now sort this vector
	std::sort(pitch_classes.begin(), pitch_classes.end());



	//then rotate the vector to get each possible starting number
	for (int i = 0; i < pitches.size(); i++) {
		pitch_classes.insert(pitch_classes.begin(), pitch_classes.back()); //take the final pitch and insert it at the beginning
		pitch_classes.pop_back(); //Remove final element as it's now at the front

		possibilities.push_back(pitch_classes); //Add current vector to our possibilities vector
	}


	std::vector<int> min_interval_vec;
	int min_interval = 13;

	//Interval min_interval = Interval(11);



	for (int i = 0; i < possibilities.size(); i++) {
		Interval new_interval(possibilities[i][0], possibilities[i][possibilities[i].size() - 1]);//create interval object from pitches

		int min_iterval_b = 13;

		if (new_interval.get_positive_interval_number() < min_interval) { //If current interval is lower, then replace our minimum interval vector
			//std::cout << "tmp_interval<min_interval"<<std::endl;
			min_interval_vec = possibilities[i];
			min_interval = new_interval.get_positive_interval_number();
		}

		//else if (new_interval.get_positive_interval_number() == min_interval) { //if there's a tie with the current minimum, check between first and secont to last
		//	Interval new_interval_b(possibilities[i][0], possibilities[i][possibilities[i].size() - 2]);
		//	


		//}

		//min_interval_vec should now contain the correct pitches.


	}

	//DEBUG_print_vector(min_interval_vec, "min_interval_vec");

	//Repopulate vector with new pitches
	for (int i = 0; i < min_interval_vec.size(); i++) {
		Pitch tmp_pitch = Pitch(min_interval_vec[i]);
		pitches[i] = tmp_pitch;
	}


	generate_intervals(); //Update intervals
	std::cout << "Normal form: " << get_set_string() << std::endl;


}



void Set::DEBUG_print_vector(std::vector<int> input, std::string input_name) {
	std::cout << "Vector " << input_name << " contains: ";
	
	for (int i = 0; i < input.size(); i++) {
		std::cout << input[i]<<" ";
	}
	std::cout << std::endl;
}
