#include "pitch.h"
#include "Interval.h"
#include <vector>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
#include <stdlib.h>
#include <time.h> 


//Not in .cpp: class keyword, variable declarations, public/private, static, friend

//Prefix each function with namespace



//Constructors
	Pitch::Pitch() {
		this->pitch_class = 0;
	}

	Pitch::Pitch(int in) { //constructor using integer as input

		while (in > 11) {
			in -= 12;
		}
		while (in < 0) {
			in += 12;
		}

		this->pitch_class = in;
		
	}

	Pitch::Pitch(std::string in) { //constructor using name (string) as input
		this->pitch_class = convert_name_to_pitch_class(in);
	}


//Getters

	int Pitch::get_pitch_class() {
		return this->pitch_class;
	}

	std::string Pitch::get_pitch_name() {
		return convert_pitch_class_to_name(this->pitch_class);
	}




//Setters
	void Pitch::change_pitch(int new_pitch) { //change pitch using int input
		this->pitch_class = new_pitch;
	}



//Operator overloads
	bool Pitch::operator==(Pitch input_pitch1) //If pitch_class is equal, return true
	{
		if (pitch_class == input_pitch1.get_pitch_class()) {
			return true;
		}
		return false;
	}

	bool Pitch::operator<(Pitch input_pitch1) 
	{
		if (pitch_class < input_pitch1.get_pitch_class()) {
			return true;
		}
		return false;
	}

	bool Pitch::operator>(Pitch input_pitch1) 
	{
		if (pitch_class > input_pitch1.get_pitch_class()) {
			return true;
		}
		return false;
	}


//Methods
	void Pitch::play_pitch() {
		switch (this->pitch_class) {
			case 0:
				PlaySound(TEXT("audio/0.wav"), NULL, SND_SYNC);
				break;
			case 1:
				PlaySound(TEXT("audio/1.wav"), NULL, SND_SYNC);
				break;
			case 2:
				PlaySound(TEXT("audio/2.wav"), NULL, SND_SYNC);
				break;
			case 3:
				PlaySound(TEXT("audio/3.wav"), NULL, SND_SYNC);
				break;
			case 4:
				PlaySound(TEXT("audio/4.wav"), NULL, SND_SYNC);
				break;
			case 5:
				PlaySound(TEXT("audio/5.wav"), NULL, SND_SYNC);
				break;
			case 6:
				PlaySound(TEXT("audio/6.wav"), NULL, SND_SYNC);
				break;
			case 7:
				PlaySound(TEXT("audio/7.wav"), NULL, SND_SYNC);
				break;
			case 8:
				PlaySound(TEXT("audio/8.wav"), NULL, SND_SYNC);
				break;
			case 9:
				PlaySound(TEXT("audio/9.wav"), NULL, SND_SYNC);
				break;
			case 10:
				PlaySound(TEXT("audio/10.wav"), NULL, SND_SYNC);
				break;
			case 11:
				PlaySound(TEXT("audio/11.wav"), NULL, SND_SYNC);
				break;
			default:
				std::cout << "Invalid pitch!" << std::endl;
				break;


		}
		


		
	}

	void Pitch::randomize_pitch() {
		int random = std::rand() % 12;
		this->pitch_class = random;
	}

	void Pitch::add_interval(int input) { //Takes an interval object and adds it. This code might be able to be optimized

		int tmp_pitch_class = this->pitch_class;

		tmp_pitch_class += input;
		tmp_pitch_class = (tmp_pitch_class % 12);
		while (tmp_pitch_class < 0) {
			tmp_pitch_class += 12;
		}

		this->pitch_class = tmp_pitch_class;

	}





//private methods
	int Pitch::convert_name_to_pitch_class(std::string input) {
		if (input == "c") {
			return 0;
		} else if (input == "c#") {
			return 1;
		}
		else if (input == "d") {
			return 2;
		}
		else if (input == "d#") {
			return 3;
		}
		else if (input == "e") {
			return 4;
		}
		else if (input == "f") {
			return 5;
		}
		else if (input == "f#") {
			return 6;
		}
		else if (input == "g") {
			return 7;
		}
		else if (input == "g#") {
			return 8;
		}
		else if (input == "a") {
			return 9;
		}
		else if (input == "a#") {
			return 10;
		}
		else if (input == "b") {
			return 11;
		}
		else {
			return -1;
		}
		
	}

	std::string Pitch::convert_pitch_class_to_name(int input) {
		switch (input) {
		case 0:
			return "c";
			break;
		case 1:
			return "c#";
			break;
		case 2:
			return "d";
			break;
		case 3:
			return "d#";
			break;
		case 4:
			return "e";
			break;
		case 5:
			return "f";
			break;
		case 6:
			return "f#";
			break;
		case 7:
			return "g";
			break;
		case 8:
			return "g#";
			break;
		case 9:
			return "a";
			break;
		case 10:
			return "a#";
			break;
		case 11:
			return "b";
			break;
		default:
			return "";
			break;
		}
	}

