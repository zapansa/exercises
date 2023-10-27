/*
    C++ CSUF Exercises @ Christian S.

    Date: October 27, 2023
    Author: Justine Zapansa
*/

#include "car.h"
#include <iostream>

/*
    For the purpose of this file, and code clarity, nothing will be 
    implemented inline in the header file only in the tandem .cc file. 

    We will be usinf the :: (scope resolution operator) to qualify 
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
void Car::Print() {}