#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class CustomFunction {
 public:
  virtual int f(int x, int y) = 0;
};

class CustomFunction1 : public CustomFunction {
 public:
  int f(int x, int y) override {
    return x + y;
  }
};

class Solution {
 public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> v;
    for (int x = 1; x <= 1000; x++) {
      for (int y = 1; y <= 1000; y++) {
        if (customfunction.f(x, y) == z) {
          v.push_back({x, y});
        } else if (customfunction.f(x, y) > z) {
          break;
        }
      }
    }
    return v;
  }
};

int main() {
  Solution sol;
  CustomFunction1 func1;
  vector<vector<int>> got;

  got = sol.findSolution(func1, 5);
  assert(got[0][0] == 1 && got[0][1] == 4);
  assert(got[1][0] == 2 && got[1][1] == 3);
  assert(got[2][0] == 3 && got[2][1] == 2);
  assert(got[3][0] == 4 && got[3][1] == 1);
}
