#include "star.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

Star::Star(std::string star_name, double star_solar_rad) 
    : star_name(star_name), star_solar_rad(star_solar_rad)
{
    std::cout << "The star " << star_name << " was born." << std::endl; 
} 

Star::~Star()
{
    std::cout << "The star " << getName() << " has gone supernova. ";
    std::cout << "It was " << std::setprecision(2) << std::fixed << pow(star_solar_rad, 3);
    std::cout << " times the volume of our sun." << std::endl;
}

std::string Star::getName()
{
    return star_name;
}