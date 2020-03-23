#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPrefix(string s) {
    int ret_len = 0;
    size_t size = s.size();
    long hash_prefix = 0, hash_suffix = 0, radix = 26, multiplier = 1, mod = 1000000007;
    for (int i = 0; i < size - 1; ++i) {
      int first = s[i] - 'a', last = s[size - 1 - i] - 'a';
      hash_prefix *= radix;
      hash_prefix += first;
      hash_prefix %= mod;
      hash_suffix += last * multiplier;
      hash_suffix %= mod;
      multiplier *= radix;
      multiplier %= mod;
      if (hash_prefix == hash_suffix) {
        ret_len = i + 1;
      }
    }
    return s.substr(0, ret_len);
  }
  // TODO: TLE
  /*
  string longestPrefix(string s) {
    string ret = "";
    size_t size = s.size();
    for (int len = size-1; len >= 1; --len) {
      //if (s.substr(0, len) == s.substr(size-len, len)) {
      if (check(s, len)) {
        ret = s.substr(0, len);
        break;
      }
    }
    return ret;
  }

  bool check(const string& s, int len) {
    bool ret = true;
    size_t size = s.size();
    for (int i = 0; i < len; ++i) {
      ret &= (s[i] == s[size-len+i]);
    }
    return ret;
  }
  */
};

int main() {
  Solution sol;
  string s;

  s = "level";
  assert(sol.longestPrefix(s) == "l");

  s = "ababab";
  assert(sol.longestPrefix(s) == "abab");

  s = "leetcodeleet";
  assert(sol.longestPrefix(s) == "leet");

  s = "a";
  assert(sol.longestPrefix(s) == "");

  s = "aaaaa";
  assert(sol.longestPrefix(s) == "aaaa");
}
