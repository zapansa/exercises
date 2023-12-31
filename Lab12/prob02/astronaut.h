#include <string>

#include "cpputils/graphics/image.h"

#ifndef ASTRONAUT_H
#define ASTRONAUT_H

class Astronaut 
{
    public: 
        Astronaut(std::string astro_name, graphics::Color astro_color); 
        std::string GetName() const;
        virtual graphics::Color GetColor() const;
        virtual std::string GetIconFilename() const;

    private: 
        std::string astro_name; 
        graphics::Color astro_color;  
};

#endif  // ASTRONAUT_H
