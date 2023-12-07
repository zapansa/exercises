/*
	Write a loop to allow the user to create `num` stars.
	Each iteration of the loop should ask the user for the
	star's name and solar radius, and use that to construct
	a `Star` object.
	
	After you create the `Star`, print "Created star " with
	its name, to announce the birth of a new star.
	
	Notice that we don't need to explicitly call the
	destructor since it automatically gets called when the
	Star goes out of scope, at the end of each iteration.
*/

#include <iostream>
#include <string>

#include "star.h"

int main() {
	int num = 0;
	std::cout << "How many stars? ";
	std::cin >> num;

	for(int i = 0; i < num; i++)
	{
		std::string starname; 
		double starsolarrad; 

		std::cout << "Enter star " << i << "'s name? "; 
		std::cin >> starname;

		std::cout << "What is the solar radius? ";
		std::cin >> starsolarrad;

		Star my_star(starname, starsolarrad);
	}

  	return 0;
}