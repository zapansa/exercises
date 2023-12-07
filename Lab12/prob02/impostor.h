#include "astronaut.h"
#include "crewmate.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef IMPOSTOR_H
#define IMPOSTOR_H

class Impostor : private Astronaut
{
    public: 
        // Constructor
        Impostor();
        Impostor(std::string impo_name, graphics::Color impo_color);

        // KILL CREW MATE
        void Kill(Crewmate crew_name);
};

#endif  // IMPOSTOR_H
