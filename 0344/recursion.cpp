#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "leetcode/utils.hpp"

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    if (s.size() == 0) return;
    recursion(s, 0, s.size() - 1);
  }

  void recursion(vector<char>& s, size_t start, size_t end) {
    if (start >= end) return;
    recursion(s, start + 1, end - 1);
    char tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
  }
};

int main() {
  Solution sol;
  vector<char> s, expected;

  s = {'h', 'e', 'l', 'l', 'o'};
  expected = {'o', 'l', 'l', 'e', 'h'};
  sol.reverseString(s);
  assert_vector_equal(expected, s);

  s = {'H', 'a', 'n', 'n', 'a', 'h'};
  expected = {'h', 'a', 'n', 'n', 'a', 'H'};
  sol.reverseString(s);
  assert_vector_equal(expected, s);

  s = {'a'};
  sol.reverseString(s);
  assert(s.size() == 1);

  s = {};
  sol.reverseString(s);
  assert(s.size() == 0);
}
