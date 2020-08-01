#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <mmsystem.h>





class Pitch {

private:
	int pitch_class = -1;

	//Methods
	int convert_name_to_pitch_class(std::string input);

	std::string convert_pitch_class_to_name(int input);


public:
	
	//constructors
	Pitch();
	Pitch(int in);
	Pitch(std::string in);

	//getters
	int get_pitch_class();

	std::string get_pitch_name();

	//setters
	
	void change_pitch(int new_pitch);

	//operator overloads
	bool operator== (Pitch input_pitch1);

	bool operator< (Pitch input_pitch1);

	bool operator> (Pitch input_pitch1);

	//methods
	void play_pitch();

	void randomize_pitch();

	void add_interval(int input);

};