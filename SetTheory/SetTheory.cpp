

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "pitch.h"
#include "set.h"
#include "Interval.h"





int main()
{
	
	srand(time(NULL)); //initialize random seed


	std::vector<int> pitches{0,1,2,3,4,5,6,7,8};
	Set s1(pitches);

	s1.randomize_all();

	std::cout << "Randomized set: " <<s1.get_set_string()<<std::endl;
	s1.generate_normal_form();

	//s1.play_all();







}

