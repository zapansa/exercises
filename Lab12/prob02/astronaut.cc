#include "astronaut.h"

Astronaut::Astronaut(std::string astro_name, graphics::Color astro_color)
    : astro_name(astro_name), astro_color(astro_color)
{}

const std::string Astronaut::GetName()
{
    // return astronaut string
    return astro_name;
}

const graphics::Color Astronaut::GetColor() 
{
    return astro_color;
}

const std::string Astronaut::GetIconFilename()
{
    // Returm filename of icon to draw
    return "astronaut.bmp";
}