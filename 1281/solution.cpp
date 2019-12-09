#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    while (n != 0) {
      int digit = n % 10;
      product *= digit;
      sum += digit;
      n /= 10;
    }
    return product - sum;
  }
};

int main() {
  Solution sol;
  assert(sol.subtractProductAndSum(234) == 15);
  assert(sol.subtractProductAndSum(4421) == 21);
  assert(sol.subtractProductAndSum(1) == 0);
}
