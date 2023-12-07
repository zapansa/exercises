/*
    C++ CSUF Exercises @ Christian S.

    Date: October 27, 2023
    Author: Justine Zapansa
*/

#include "car.h"
#include <iostream>
#include <format>

/*
    For the purpose of this file, and code clarity, nothing will be 
    implemented inline in the header file only in the tandem .cc file. 

    We will be using the :: (scope resolution operator) to qualify 
    names. In this case it is used to seperate the class Car from 
    the constructor Car(). Forming the qualified name Car::Car()

    From this, it tells the compiler that each function belongs to 
    the Car class. 
*/

/* Defining Constructors + Implementation */
Car::Car(){}
Car::Car(const VehicleId id_) : id_(id_){}
Car::Car(const Date release_date_) : release_date_(release_date_){}
Car::Car(const VehicleId id_, const Date release_date_) : id_(id_), release_date_(release_date_){}

/* Defining Getter and Setters + Implementation*/
void Car::setId(VehicleId id) { id_ = id; }
void Car::setDate(Date release_date) { release_date_ = release_date; }

/* Print Function Implementation */
void Car::Print() {

    // Print in format 
    /* Notes, from getId in our Car class, we can get the Id of the car. 
       Now, the Id of the car is associated with the model, vin, plate# 
       If you look in the vehicleid.h file, you can see the getters of each info.

       Summary, we call the getId function then use the '.' operator to get all 
       other info. Think if this as like, acessing object of variables within a 
       a class object of class objects. 

       Analogy, "a folder of folders" :) 
    */
    std::cout << "The model of the car is: " << getId().Model() << "\n";
    std::cout << "The VIN of the car is: " << getId().Vin() << "\n";
    std::cout << "The license plate of the car is: " << getId().LicensePlate() << "\n";

    // Getting the info of the dates
    int day = getDate().Day();
    int month = getDate().Month(); 
    int year = getDate().Year(); 

    // Formatting a string 
    std::cout << "The release date of the car is: " << month << "/" << day << "/" << year << "\n";
}