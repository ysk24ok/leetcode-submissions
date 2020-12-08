#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int, size_t> counts;
    for (const int& t : time) {
      counts[t % 60] += 1;
    }
    int num = 0;
    for (int i = 1; i < 30; ++i) {
      if (counts.find(i) != counts.end() && counts.find(60-i) != counts.end()) {
        num += counts[i] * counts[60-i];
      }
    }
    if (counts.find(0) != counts.end()) {
      num += counts[0] * (counts[0] - 1) / 2;
    }
    if (counts.find(30) != counts.end()) {
      num += counts[30] * (counts[30] - 1) / 2;
    }
    return num;
  }
};

int main() {
  Solution sol;
  vector<int> times;
  int expected;

  times = {30, 20, 150, 100, 40};
  expected = 3;
  EXPECT_EQ(expected, sol.numPairsDivisibleBy60(times));

  times = {60, 60, 60};
  expected = 3;
  EXPECT_EQ(expected, sol.numPairsDivisibleBy60(times));

  exit(EXIT_SUCCESS);
}
