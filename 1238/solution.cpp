#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> gray_code = grayCode(n);
    vector<int> ret;
    ret.reserve(gray_code.size());
    size_t idx = 0;
    bool started = false;
    while (ret.size() != gray_code.size()) {
      if (gray_code[idx] == start) {
        started = true;
      }
      if (started) {
        ret.push_back(gray_code[idx]);
      }
      if (++idx == gray_code.size()) {
        idx -= gray_code.size();
      }
    }
    return ret;
  }

  vector<int> grayCode(int n) {
    if (n == 1) return {0, 1};
    vector<int> ret = grayCode(n-1);
    size_t size = ret.size();
    for (size_t i = size; i > 0; i--) {
      ret.push_back(ret[i-1] + (1 << (n-1)));
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> got;
  vector<int> expected;

  // 0 1
  got = sol.circularPermutation(1, 1);
  expected = {1,0};
  assert(got == expected);

  // 00 01 11 10
  got = sol.circularPermutation(2, 3);
  expected = {3,2,0,1};
  assert(got == expected);

  // 000 001 011 010 110 111 101 100
  got = sol.circularPermutation(3, 2);
  expected = {2,6,7,5,4,0,1,3};
  assert(got == expected);
}
