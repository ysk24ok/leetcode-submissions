#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stack;
    size_t i = 0;
    while (i < asteroids.size()) {
      const int& asteroid = asteroids[i];
      if (stack.empty()) {
        stack.push_back(asteroid);
        i++;
        continue;
      }
      // both moves to the same direction or the left one moves left and the right one moves right
      if ((stack.back() < 0 && asteroid < 0) || (stack.back() > 0 && asteroid > 0) || (stack.back() < 0 && asteroid > 0)) {
        stack.push_back(asteroid);
        i++;
        continue;
      }
      int left_size = stack.back(), right_size = asteroid;
      if (left_size < 0) { left_size *= -1; }
      if (right_size < 0) { right_size *= -1; }
      // right explodes
      if (left_size > right_size) {
        i++;
      // left explodes
      } else if (left_size < right_size) {
        stack.pop_back();
      // both explode
      } else {
        stack.pop_back();
        i++;
      }
    }
    return stack;
  }
};

int main() {
  Solution sol;
  vector<int> asteroids, expected;

  asteroids = {5, 10, -5};
  expected = {5, 10};
  EXPECT_EQ(expected, sol.asteroidCollision(asteroids));

  asteroids = {8, -8};
  expected = {};
  EXPECT_EQ(expected, sol.asteroidCollision(asteroids));

  asteroids = {10, 2, -5};
  expected = {10};
  EXPECT_EQ(expected, sol.asteroidCollision(asteroids));

  asteroids = {-2, -1, 1, 2};
  expected = {-2, -1, 1, 2};
  EXPECT_EQ(expected, sol.asteroidCollision(asteroids));

  exit(EXIT_SUCCESS);
}
