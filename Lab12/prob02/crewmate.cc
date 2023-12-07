#include "crewmate.h"

#include <iostream>

/* Constructors */ 
Crewmate::Crewmate()
    : Astronaut("no name", graphics::Color(0, 0, 0)) // initialize base class
{}

Crewmate::Crewmate(std::string crew_name, graphics::Color crew_color)
    : Astronaut(crew_name, crew_color) // initialize base class
{}

/* isAlive Getters, setters */
bool Crewmate::GetIsAlive()
{
    return isAlive; 
}

bool Crewmate::SetIsAlive(bool isAlive_)
{
    isAlive = isAlive_;
}

/* Crewmate task stuff */ 
int Crewmate::GetTaskCount()
{
    return taskCount;
}

void Crewmate::DoTask(std::string task_name)
{
    // Increment task by 1
    std::cout << GetName() << " is doing " << task_name << std::endl; 
    taskCount++;
}

/* Overrides */
const std::string Crewmate::GetIconFilename()
{
    return "ghost.bmp";
}

const graphics::Color Crewmate::GetColor()
{
    graphics::Color shifted = graphics::Color((Astronaut::GetColor().Red() + 256) / 2,
                                              (Astronaut::GetColor().Green() + 256) / 2,
                                              (Astronaut::GetColor().Blue() + 256) / 2);
    return shifted;
}