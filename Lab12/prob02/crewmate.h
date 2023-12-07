#include "astronaut.h"

// These header guards are necessary to keep your class from being defined
// multiple times when it is included from multiple files.
#ifndef CREWMATE_H
#define CREWMATE_H

class Crewmate : public Astronaut 
{
    private:
        bool isAlive = true; 
        int taskCount = 0; 

    public:
        // Constructors
        Crewmate(); // Default no params
        Crewmate(std::string crew_name, graphics::Color crew_color); // Default 2 params


        // isAlive Stuff
        bool GetIsAlive(); 
        bool SetIsAlive(bool isAlive_); 

        // Task Stuff
        int GetTaskCount();
        void DoTask(std::string task_name);

        // overrides
        std::string const GetIconFilename();
        graphics::Color const GetColor(); 
};

#endif  // CREWMATE_H
