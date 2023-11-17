
#include <string>

class Plane {
 public:
  Plane() : Plane(121, 121,"Fullerton") {};
  Plane(int seat_count_, int passenger_count_, std::string destination_); 

  int GetPassengerCount() const {
    return passenger_count_;
  }
  void SetPassengerCount(int passengers) {
    passenger_count_ = passengers;
  }
  int GetSeatCount() const {
    return seat_count_;
  }
  void SetSeatCount(int seats) {
    seat_count_ = seats;
  }
  const std::string &GetDestination() const {
    return destination_;
  }
  void SetDestination(const std::string &dest) {
    destination_ = dest;
  }

 private:
  int seat_count_;
  int passenger_count_;
  std::string destination_;
};