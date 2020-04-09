#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    return create(S) == create(T);
  }

  string create(string str) {
    stack<char> s;
    for (const auto& c : str) {
      if (c != '#') {
        s.push(c);
      } else {
        if (!s.empty()) { s.pop(); }
      }
    }
    string ret;
    while (!s.empty()) {
      ret.push_back(s.top());
      s.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution sol;
  string S, T;

  S = "ab#c", T = "ad#c";
  assert(sol.backspaceCompare(S, T));

  S = "ab##", T = "c#d#";
  assert(sol.backspaceCompare(S, T));

  S = "a##c", T = "#a#c";
  assert(sol.backspaceCompare(S, T));

  S = "a#c", T = "b";
  assert(!sol.backspaceCompare(S, T));

  S = "cc######", T = "###";
  assert(sol.backspaceCompare(S, T));
}
