#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

#include <map>
#include <string>
#include <vector>
#include "food_wastage_record.h"

class FoodWastageTracker {
  public:
    bool addRecord();
    void deleteRecord();
    void getRecord();
    std::vector<FoodWastageRecord> genReport();

  private:
    std::vector<FoodWastageRecord> genReport;
};

#endif