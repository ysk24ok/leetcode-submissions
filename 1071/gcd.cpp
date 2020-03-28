#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
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
  string gcdOfStrings(string str1, string str2) {
    int gcd_val = gcd(str1.size(), str2.size());
    string substr1 = str1.substr(0, gcd_val);
    string substr2 = str2.substr(0, gcd_val);
    return (substr1 == substr2 && check(str1, substr1) && check(str2, substr2)) ? substr1 : "";
  }

  bool check(const string& str, const string& gcd) {
    bool is_gcd = true;
    for (size_t i = 0; i < str.size(); i += gcd.size()) {
      for (size_t j = 0; j < gcd.size(); j++) {
        is_gcd &= (str[i+j] == gcd[j]);
      }
    }
    return is_gcd;
  }

  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
};

int main() {
  Solution sol;
  string str1, str2;

  str1 = "ABCABC", str2 = "ABC";
  assert(sol.gcdOfStrings(str1, str2) == "ABC");

  str1 = "ABABAB", str2 = "ABAB";
  assert(sol.gcdOfStrings(str1, str2) == "AB");

  str1 = "LEET", str2 = "CODE";
  assert(sol.gcdOfStrings(str1, str2) == "");

  str1 = "ABCD", str2 = "ABCD";
  assert(sol.gcdOfStrings(str1, str2) == "ABCD");

  str1 = "ABCABCABC", str2 = "ABCABC";
  assert(sol.gcdOfStrings(str1, str2) == "ABC");

  str1 = "ABCDEF", str2 = "ABC";
  assert(sol.gcdOfStrings(str1, str2) == "");
}
