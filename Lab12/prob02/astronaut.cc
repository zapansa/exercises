#include "astronaut.h"

Astronaut::Astronaut(std::string astro_name, graphics::Color astro_color)
    : astro_name(astro_name), astro_color(astro_color)
{}

 std::string Astronaut::GetName() const
{
    // return astronaut string
    return astro_name;
}

graphics::Color Astronaut::GetColor() const  
{
    return astro_color;
}

std::string Astronaut::GetIconFilename() const
{
    // Returm filename of icon to draw
    return "astronaut.bmp";
}