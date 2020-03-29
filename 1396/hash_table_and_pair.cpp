#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
 public:
  UndergroundSystem() : checkin(), stats() {}

  void checkIn(int id, string stationName, int t) {
    checkin[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const auto& pair = checkin[id];
    string concatenated = pair.first + " " + stationName;
    if (stats.find(concatenated) == stats.end()) stats[concatenated] = {0, 0};
    stats[concatenated].first += t - pair.second;
    stats[concatenated].second++;
  }

  double getAverageTime(string startStation, string endStation) {
    const auto& pair = stats[startStation + " " + endStation];
    return static_cast<double>(pair.first) / pair.second;
  }

 private:
  unordered_map<int, pair<string, int>> checkin;
  unordered_map<string, pair<int, int>> stats;
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
