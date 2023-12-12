#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_

#include <iostream>
#include <string>

class FoodWastageReport {
  public: 
    std::string getCostlyWasteFoods() { return costlyWasteFoods; }
    double getTotalCost() { return totalCost; }
    std::string getMostCommonReason() { return mostCommonReason; }
    std::string getMostCommonMech() { return mostCommonMech; }
    std::string getStrat() { return strat; }

  private:
    std::string costlyWasteFoods;
    double totalCost;
    std::string mostCommonReason;
    std::string mostCommonMech;
    std::string strat;
};

#endif