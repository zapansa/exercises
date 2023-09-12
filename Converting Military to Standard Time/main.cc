#include <iostream>
#include <string>
#include "time_converter.h"


int main()
{
  int military_time = 0;
  std::cout << "\n[C++ Excercise 1 - Military to Standard time]\n\n";
  std::string inp_exit; 

  while(true){
    while (true)
    {
      std::cout << "--------\n";
      std::cout << "Please enter the time in military time: ";
      std::cin >> military_time;

      if (military_time > 2459)
      {
        std::cout << "Incorrect input. Try again.\n\n";
      }
      else
        break;
    }

    std::string regular_time = MilitaryToRegularTime(military_time);
    std::cout << "The equivalent regular time is: " << regular_time << "\n\n";

    std::cout << "Exit? (Y/N): ";
    std::cin >> inp_exit;
    if(inp_exit == "y"){
      break;
    }
  }
  return 0;
}
