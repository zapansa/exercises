#include <memory>
#include <string>

class Train {
 public:
  Train(int passenger_count, int seat_count, std::shared_ptr<Train> next_carriage)
      : passenger_count_(passenger_count), seat_count_(seat_count), next_carriage_(next_carriage) 
      {
      }

  int GetPassengerCount() const 
  {
    return passenger_count_;
  }

  int GetSeatCount() const 
  {
    return seat_count_;
  }

  std::shared_ptr<Train> GetNextCarriage() const 
  {
    return next_carriage_;
  }

  // ====================== YOUR CODE HERE ======================
  // Define the following recursive member functions, according
  // to the instructions in the README:
  //
  //   1. TotalTrainPassengers
  //   2. MaxCarriagePassengers
  //   3. IsTrainFull
  //   4. AddCarriageToEnd
  // ============================================================

  int TotalTrainPassengers() const;

  int MaxCarriagePassengers() const;
  
  bool IsTrainFull() const;

  std::shared_ptr<Train> AddCarriageToEnd(std::shared_ptr<Train> carriage);

 private:
  int passenger_count_;
  int seat_count_;
  std::shared_ptr<Train> next_carriage_;
};
