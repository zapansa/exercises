/*
    C++ CSUF Exercises @ Christian S.

    Date: October 27, 2023
    Author: Justine Zapansa
*/

#include "date.h"
#include "vehicleid.h"

/* Useful Notes:
    [1*] Default Constructors
    - https://www.ibm.com/docs/en/zos/2.2.0?topic=only-default-constructors-c

    [2*] Use of "const"
    - The const keyword specifies that a variable's value is constant and
      tells the compiler to prevent the programmer from modifying it
    - https://www.geeksforgeeks.org/const-keyword-in-cpp/
    - https://www.w3schools.com/cpp/cpp_variables_constants.asp
*/

class Car {
    public: // Usually includes contrustors, accessors/mutators, member function 

        // Default Constructor - Empty 
        Car(); // Empty will set to default

        // These Non default constructors will assign to the respected member variable(s).
        Car(const VehicleId id_); // Non default constructor that takes a VehicleId object. 
        Car(const Date release_date_); // Non default constructor that takes a Dare object. 
        Car(const VehicleId id_, const Date release_date_); // Non-default constructor that takes both.

        // VehicleId getter and setters 
        void setId(VehicleId id); // Setter 
        VehicleId getId() const {return id_;} // Getter

        // Date getter and setters
        void setDate(Date release_date); // Setter
        Date getDate() const {return release_date_;} // Getter

        // Member function that takes no poarameters. 
        void Print();

    private: // Usually contains member variables

        // Member Variables of specified types: 
        VehicleId id_; // id_ to store the vehicle identity info
        Date release_date_; // release_date_ to store the car's release date
};