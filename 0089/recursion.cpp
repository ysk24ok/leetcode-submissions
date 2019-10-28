#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    if (n == 0) return {0};
    if (n == 1) return {0, 1};
    vector<int> ret;
    vector<int> v = grayCode(n-1);
    for (size_t i = 0; i < v.size(); i++) {
      ret.push_back(v[i]);
    }
    for (size_t i = v.size(); i > 0; i--) {
      ret.push_back(v[i-1] + (1 << (n-1)));
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> got;
  vector<int> expected;

  got = sol.grayCode(0);
  expected = {0};
  assert(got == expected);

  got = sol.grayCode(1);
  expected = {0, 1};
  assert(got == expected);

  got = sol.grayCode(2);
  // 00 01 11 10
  expected = {0,1,3,2};
  assert(got == expected);

  got = sol.grayCode(3);
  // 000 001 011 010 110 111 101 100
  expected = {0,1,3,2,6,7,5,4};
  assert(got == expected);

  got = sol.grayCode(4);
  // 0000 0001 0011 0010 0110 0111 0101 0100
  // 1100 1101 1111 1110 1010 1011 1001 1000
  expected = {0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8};
  assert(got == expected);
}
