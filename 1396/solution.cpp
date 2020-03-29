#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
 public:
  UndergroundSystem() : total_count(), total_time_per_station(), customers() {}

  void checkIn(int id, string stationName, int t) {
    customers[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const pair<string, int>& p = customers[id];
    if (total_time_per_station.find(p.first) == total_time_per_station.end()) {
      total_time_per_station[p.first] = {};
      total_count[p.first] = {};
    }
    total_time_per_station[p.first][stationName] += t - p.second;
    total_count[p.first][stationName] += 1;
  }

  double getAverageTime(string startStation, string endStation) {
    return static_cast<double>(total_time_per_station[startStation][endStation]) / total_count[startStation][endStation];
  }

 private:
  unordered_map<string, unordered_map<string, int>> total_count;
  unordered_map<string, unordered_map<string, int>> total_time_per_station;
  unordered_map<int, pair<string, int>> customers;
};

int main() {
  UndergroundSystem undergroundSystem;
  undergroundSystem.checkIn(45, "Leyton", 3);
  undergroundSystem.checkIn(32, "Paradise", 8);
  undergroundSystem.checkIn(27, "Leyton", 10);
  undergroundSystem.checkOut(45, "Waterloo", 15);
  undergroundSystem.checkOut(27, "Waterloo", 20);
  undergroundSystem.checkOut(32, "Cambridge", 22);
  assert(undergroundSystem.getAverageTime("Paradise", "Cambridge") == 14.0);
  assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.0);
  undergroundSystem.checkIn(10, "Leyton", 24);
  assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 11.0);
  undergroundSystem.checkOut(10, "Waterloo", 38);
  assert(undergroundSystem.getAverageTime("Leyton", "Waterloo") == 12.0);
}
