#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> passed(n, false);
    int count = 0;
    for (int i = 2; i < n; ++i) {
      if (!passed[i]) {
        count++;
        for (int j = i; j < n; j += i) {
          passed[j] = true;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution sol;
  assert(sol.countPrimes(10) == 4);
  assert(sol.countPrimes(0) == 0);
  assert(sol.countPrimes(1) == 0);
  assert(sol.countPrimes(2) == 0);
  assert(sol.countPrimes(3) == 1);
  assert(sol.countPrimes(4) == 2);
}
