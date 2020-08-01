#include "Interval.h"
#include <string>
#include <iostream>



//Constructors
Interval::Interval(int input) { //construct an interval from a int
	this->interval_number = input;
	int tmp_var = input;
	tmp_var = tmp_var % 12;
	while (tmp_var < 0) {
		tmp_var += 12;
	}

	this->positive_interval_number = tmp_var;
}

Interval::Interval(Pitch p1, Pitch p2) { //given two Pitch objects, construct the interval
	int n1 = p1.get_pitch_class();
	int n2 = p2.get_pitch_class();

	int tmp_var = n2-n1;

	this->interval_number = tmp_var;

	
	tmp_var = tmp_var % 12;
	while (tmp_var < 0) {
		tmp_var += 12;
	}

	this->positive_interval_number = tmp_var;
	

}

//Getters
int Interval::get_interval_number() { //return signed int
	return this->interval_number;
}

std::string Interval::get_interval_name() { //return name
	std::string tmpstring = convert_to_name(this->interval_number);

	return tmpstring;
}

int Interval::get_positive_interval_number() { //return rule of nines positive int

	return this->positive_interval_number;

}


//Setters
void Interval::set_positive_interval_number(int input) {
	this->positive_interval_number = input;
}


//Operator overloads
bool Interval::operator==(Interval input_interval1) //If positive_interval_number is equal, return true
{
	if (positive_interval_number == input_interval1.get_positive_interval_number()) {
		return true;
	}
	return false;
}

bool Interval::operator<(Interval input_interval1) //If positive_interval_number is less than that of the operand, return true
{
	if (positive_interval_number < input_interval1.get_positive_interval_number()) {
		return true;
	}
	return false;
}

bool Interval::operator>(Interval input_interval1) //If positive_interval_number is greater than that of the operand, return true
{
	if (positive_interval_number > input_interval1.get_positive_interval_number()) {
		return true;
	}
	return false;
}



//Methods
std::string Interval::convert_to_name(int input)
{
	
	std::string output_string = "";
	if (input == 0) {
		return "U";
	}

	if (input < 0) {
		output_string += "d";
	}
	else {
		output_string += "a";
	}

	input = std::abs(input); //descending intervals already accounted for

	switch (input) {
	case 1:
		output_string += "m2";
		break;
	case 2:
		output_string += "M2";
		break;
	case 3:
		output_string += "m3";
		break;
	case 4:
		output_string += "M3";
		break;
	case 5:
		output_string += "P4";
		break;
	case 6:
		output_string += "TT";
		break;
	case 7:
		output_string += "P5";
		break;
	case 8:
		output_string += "m6";
		break;
	case 9:
		output_string += "M6";
		break;
	case 10:
		output_string += "m7";
		break;
	case 11:
		output_string += "M7";
		break;
	default:
		output_string += "Invalid";
		break;
	}

	return output_string;
}
