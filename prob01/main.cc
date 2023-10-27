/*
    C++ CSUF Exercises @ Christian S.

    Date: October 27, 2023
    Author: Justine Zapansa
*/

#include <iostream>
#include "car.h"

int main() {

  /* 
    Create a Car object called `c1` using the default constructor.
  */
  Car c1 = Car(); 
  c1.Print();
  std::cout << "\n";

  /* 
    Create a `VehicleId` object with the following info:
    Model: Honda, ID: 3, License plate: 7B319X4
    Create a `Car` object `c2` using the constructor that
    accepts a `VehicleId` and  pass in the `VehicleId`
    object you just made.
    Call its Print member function. 
  */
  VehicleId vid2 = VehicleId("Honda", 3, "7B319X4");
  Car c2 = Car(vid2);
  c2.Print();
  std::cout << "\n";

  /* 
    Create a `Date` object with the following info:
    Day: 4, Month: 11, Year: 2018
    Create a `Car` object `c3` using the constructor that accepts 
    a `Date` object and pass in the `Date` objectyou just made.
    Call its Print member function.
  */
  Date date3 = Date(4, 11, 2018);
  Car c3 = Car(date3);
  c3.Print();
  std::cout << "\n";

  /* 
    Create a `Car` object `c4` using the constructor that
    accepts a `VehicleId` and `Date` object and pass in
    the `VehicleId` and `Date` objects you created in steps 2 and 3 above.
    Call its Print member function.
  */
  Car c4 = Car(vid2, date3);
  c4.Print();
  std::cout << "\n";

  /* Create an instance of `VehicleId` using the default constructor. */
  VehicleId ins_vid = VehicleId();

  /* Create an instance of `Date` using the default constructor. */
  Date ins_date = Date();

  /* Call the `SetId` member function on `c4` and pass in the VehicleId you just created. */
  c4.setId(ins_vid);

  /* Call the `SetReleaseDate` member function on `c4`and pass in the VehicleId you just created. */
  c4.setDate(ins_date);

  /* Finally, call the print member function for `c4`. */
  c4.Print(); 

  return 0;
}
