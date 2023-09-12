#include <iostream>
#include <string>
#include "time_converter.h"


int main()
{
  int military_time = 0;
  std::cout << "Please enter the time in military time: ";
  std::cin >> military_time;

  // TODO: Call your function to convert from military time to regular time
  // and assign its result to regular_time.

  std::string regular_time = MilitaryToRegularTime(military_time);

  std::cout << "The equivalent regular time is: " << regular_time << "\n";
  return 0;
}
