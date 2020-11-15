#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    while (pow(minutesToTest / minutesToDie + 1, pigs) < buckets) {
      pigs++;
    }
    return pigs;
  }
};

int main() {
  Solution sol;
  int buckets, minutesToDie, minutesToTest;
  int expected;

  buckets = 1000, minutesToDie = 15, minutesToTest = 60;
  expected = 5;
  EXPECT_EQ(expected, sol.poorPigs(buckets, minutesToDie, minutesToTest));

  exit(EXIT_SUCCESS);
}
