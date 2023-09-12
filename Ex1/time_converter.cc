#include <iostream>
#include <string>
// we have written in atoi so include this
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

/* 
  Input: int
  Out: string 
  Variables: int military_time 
  Desc: This function turns military time in format "0000" -- "1200" into standard time
*/
std::string MilitaryToRegularTime(int military_time) {
  // 'military_time' in the function is an integer and we want to return as a string 
  // hence we want to convert the integer into a string before returning in main func call

  // declare variables
  bool b_AM = true;
  std::string s_AM;

  // get the first two digits - hour
  int hour = military_time/100;

  // get the last two digits of input - minutes
  int minute = military_time % 100;
  
  /* Note 1: midnight 2400 vs 0000
     24 hour time midnight is presented as both 2400 and 0000 in military and emergency 
     if we do not handle that some people are going to type eg. 2430 vs eg. 0030 and 
     mean the same thing, then the output is going to be different. 

     it is gonna be handled here as well as conversion

     otherwise the input 0030 will be presented as 00:30 AM in standard time. 
  */
  if (hour > 12){ // it is 1pm to 12am, 1300 to 2400
    if (hour == 24){ // it is midnight
      b_AM = true; // hence AM
    } else {
      b_AM = false; // otherwise it isnt midnight <11PM hence PM
    }
    hour = hour - 12;
  } else if (hour == 12){
    hour = 12; // it is 12 noon
    b_AM = false; // it is PM
  } else if (hour == 0){ // see Note 1*
    hour = 12;   // it is midnight
    b_AM = true; // it is AM
  } 

  // int to string conversion
  std::string s_hour = std::to_string(hour);
  std::string s_minute = std::to_string(minute);

  // add leading zeros
  size_t n_zero = 2; // digi
  int precision_hour = n_zero - std::min(n_zero, s_hour.size());
  s_hour.insert(0, precision_hour, '0'); // hour
  int precision_minute = n_zero - std::min(n_zero, s_minute.size());
  s_minute.insert(0, precision_minute, '0'); //minute

  // specify am/pm
  if (b_AM) {
    s_AM = "AM";
  } else {
    s_AM = "PM";
  }

  return s_hour + ":"+ s_minute + " " + s_AM;
}
