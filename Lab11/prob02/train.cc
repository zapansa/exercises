#include "train.h"

  int Train::TotalTrainPassengers() const 
  {
    // Condition there is only one carriage in the train 
    // Hence, the next carriage would be null
    if (next_carriage_ == nullptr)
    {
      // Return the passenger count
      return passenger_count_;
    } 
    else 
    {
      // Otherwise, return the current passenger count + recurse
      // Until the next carriage is empty
      return next_carriage_->TotalTrainPassengers() + passenger_count_;
    }
  }
  
  int Train::MaxCarriagePassengers() const 
  {
    // Conditon there is only one carriage in the train 
    // Hence, next carriage would be null 
    if (next_carriage_ == nullptr)
    {
      return seat_count_;
    } 
    else 
    {
      // iterate throught the carriages and return the seat count of max passenger 
      // aka -> return the carriage max of highst # potential passengers 
      int maxAmt = next_carriage_->MaxCarriagePassengers(); // store the result of the next carriage seat amt
      if(seat_count_ <= maxAmt)
      {
        return maxAmt;
      }
      else
      {
        return seat_count_;
      }
    }
  }

  bool Train::IsTrainFull() const 
  {
    // Condition: (1) only one carriage in the train or (2) end of recursive linked list 
    if (next_carriage_ == nullptr) 
    { 
      if (passenger_count_ == seat_count_) // max = passenger count
      {
        return true; // every carriage in this train is full
      } 
      else 
      {
        return false; // return false because the carriage isnt full 
      }
    } 
    else // Condition: n carriages in the train 
    {
      if(passenger_count_ == seat_count_)
      {
        // recurse if the current carriage is full until loop end 
        return next_carriage_->IsTrainFull();
      }
      else
      {
        return false;
      }
    }
  }

  std::shared_ptr<Train> Train::AddCarriageToEnd(std::shared_ptr<Train> carriage) {
    if (next_carriage_ == nullptr) // Base Case 
    {
      next_carriage_ = carriage;
      return 0;
    } 
    else // if the carriage isnt already at the end recurse until it is
    {
      return next_carriage_->AddCarriageToEnd(carriage);
    }
  }