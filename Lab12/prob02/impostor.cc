#include "impostor.h"

#include <iostream>

#include "crewmate.h"

Impostor::Impostor()
    : Astronaut("impie", graphics::Color(0, 0, 0))
{}

Impostor::Impostor(std::string impo_name, graphics::Color impo_color)
    : Astronaut(impo_name, impo_color)
{}

void Impostor::Kill(Crewmate crewmate)
{
    crewmate.SetIsAlive(false);
    std::cout << GetName() << " killed " << crewmate.GetName() << std::endl;
}