#pragma once
#include <vector>
#include <string>
#include "Interval.h"

class Set
{
private:
	int cardinality = 0;
	bool repeats = false;
	std::vector<Pitch> pitches;
	std::vector<Interval> intervals;

	void check_for_repeats();

	std::vector<Pitch> get_smallest_interval(std::vector<Pitch> input_vector);


	void DEBUG_print_vector(std::vector<int> input, std::string input_name);
	



public:
	//Constructors
	

	Set(Pitch input_pitch);

	Set(int input_pitch);

	Set(std::vector<Pitch> const input_vector);

	Set(std::vector<int> const input_vector);




	//Getters
	std::string get_set_string();

	std::string get_set_string_named();

	std::string get_intervals_string();

	//Setters
	void add_pitch(Pitch const input_pitch);
	void add_pitch(int const input_pitch);

	void add_pitch(std::string input_pitch);


	//Methods
	void play_all();

	void randomize_all();

	void generate_intervals();

	void generate_normal_form_old();

	void generate_normal_form();

	







};

