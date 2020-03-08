#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  string generateTheString(int n) {
    string ret(n, 'a');
    if (n % 2 == 1) return ret;
    else {
      ret[n-1] = 'b';
      return ret;
    }
  }
};

int main() {
  Solution sol;
  assert(sol.generateTheString(3) == "aaa");
  assert(sol.generateTheString(4) == "aaab");
}
