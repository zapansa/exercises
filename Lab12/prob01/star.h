/*
  Define the following members for the Star class:

  1. One member variable representing the name of the star, 
     and one representing the solar radius of the star.
  2. A constructor, which initializes the name of the star,
     and the radius of the star. The constructor should
     print that the star was born to the terminal.
  3. A destructor that prints to the terminal that the star
     was destroyed (i.e. went supernova), and print how many
     times the volume of the sun that the star was.
  4. An accessor function, `GetName` for the star's name.

*/

#include <iomanip>
#include <iostream>
#include <string>

class Star {
	public:
    	Star(std::string star_name, double star_solar_rad); // Constructor
		~Star(); // Deconstructor
		std::string getName(); // Accessor

	private: 
    	std::string star_name; // Name of star  (1)
    	double star_solar_rad;  // Solar Radius of star (1)

};