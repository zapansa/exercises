#include <string>

#include "cpputils/graphics/image.h"

#ifndef ASTRONAUT_H
#define ASTRONAUT_H

class Astronaut 
{
    public: 
        Astronaut(std::string astro_name, graphics::Color astro_color); 
        std::string const GetName();
        virtual graphics::Color const GetColor();
        virtual std::string const GetIconFilename();

    private: 
        std::string astro_name; 
        graphics::Color astro_color;  
};

#endif  // ASTRONAUT_H
