#pragma once
#include <string>
#include <vector>
#include "pitch.h"


class Interval
{
private:
	int interval_number;
	int positive_interval_number;

	//Methods
	std::string convert_to_name(int input);


public:
	
	//Constructors
	Interval(int input);

	Interval(Pitch p1, Pitch p2);


	//Getters
	int get_interval_number();

	std::string get_interval_name();

	int get_positive_interval_number();

	

	//Setters
	void set_positive_interval_number(int input);

	//Operator overloads
	bool operator== (Interval input_interval1);

	bool operator< (Interval input_interval1);
	
	bool operator> (Interval input_interval1);

};

