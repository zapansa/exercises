#include <iostream>
#include <map>
#include <vector>

#include "plane.h"

int main()
{
    // ---------------------------------------- //

    std::vector<double> weights{3.2, 4.7, 2.1, 5.5, 9.8, 7.4, 1.6, 9.3};
    std::cout << "Printing out all the weights: " << std::endl;

    // Pythonic Solution
    std::cout << "Pythonic Iterator    | ";
    for (double wti : weights)
    {
        std::cout << wti << "  ";
    }

    // Standard .begin(), .end() loop iterator ++wti
    std::cout << "\nStandard Iterator    | ";
    for (auto wti = weights.begin(); wti != weights.end(); ++wti)
    {
        std::cout << *wti << "  ";
    }

    // Declaration style loop iterator it++
    std::cout << "\nStandard Iterator V2 | ";
    for(std::vector<double>::iterator wti = weights.begin(); wti != weights.end(); wti++)
    {
      std::cout << *wti << "  ";
    }

    std::cout << std::endl;

    // ---------------------------------------- //

    std::map<std::string, std::string> abbrevs{{"AL", "Alabama"},
                                               {"CA", "California"},
                                               {"GA", "Georgia"},
                                               {"TX", "Texas"}};
    std::map<std::string, double> populations{
        {"CA", 39.2}, {"GA", 10.8}, {"AL", 5.1}, {"TX", 29.5}};
    std::cout << "\nPrinting out the state populations: " << std::endl;

    // Pythonic Solution - nested loops
    for (const auto [key_abb, val_abb] : abbrevs)
    {
        for (const auto [key_pop, val_pop] : populations)
        {
            if (key_abb == key_pop)
            {
                std::cout << "Population of " << val_abb;
                std::cout << ": " << val_pop << " million";
                std::cout << "\n";
            }
        }
    }

    std::cout << std::endl;

    // ---------------------------------------- //

    std::vector<Plane> fleet; 

    Plane p1 = Plane(); 
    Plane p2 = Plane(150, 75, "New York City");
    Plane p3 = Plane(220, 220, "Atlanta");
    Plane p4 = Plane(75, 75, "Guatemala City");
    Plane p5 = Plane(125, 94, "Medellin");

    fleet.push_back(p1);
    fleet.push_back(p2);
    fleet.push_back(p3);
    fleet.push_back(p4);
    fleet.push_back(p5);

    std::cout << "Printing Full Flights: \n";
    for (const Plane p : fleet)
    {
        // Print Only Full Flights 
        if (p.GetPassengerCount() == p.GetSeatCount())
        {
            std::cout << p.GetPassengerCount() << " passengers flying to " << p.GetDestination();
            std::cout << "\n";
        }
    }
    std::cout << std::endl;

    // ---------------------------------------- //
    
    std::cout << "Printing Reversed Weights:\n";
    for (auto wti = weights.rbegin(); wti != weights.rend(); ++wti)
    {
        std::cout << *wti << "  ";
    }
}
