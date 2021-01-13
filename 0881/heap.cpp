#include <gtest/gtest.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    priority_queue<int> q;
    int ret = 0;
    std::sort(people.begin(), people.end(), greater<int>{});
    for (const int& person : people) {
      if (!q.empty() && person <= q.top()) {
        q.pop();
      } else {
        ret++;
        if (person < limit) {
          q.push(limit - person);
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> people;
  int limit, expected;

  people = {1, 2}, limit = 3, expected = 1;
  EXPECT_EQ(expected, sol.numRescueBoats(people, limit));

  people = {3, 2, 2, 1}, limit = 3, expected = 3;
  EXPECT_EQ(expected, sol.numRescueBoats(people, limit));

  people = {3, 5, 3, 4}, limit = 5, expected = 4;
  EXPECT_EQ(expected, sol.numRescueBoats(people, limit));

  people = {3, 2, 3, 2, 2}, limit = 6, expected = 3;
  EXPECT_EQ(expected, sol.numRescueBoats(people, limit));

  exit(EXIT_SUCCESS);
}
