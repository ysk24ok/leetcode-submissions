#include <algorithm>
#include <string>
#include <unordered_map>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int ret = 0;
    int num_frogs = 0;
    unordered_map<char, int> accepts;
    for (const auto& c : croakOfFrogs) {
      if (c == 'c') {
        num_frogs++;
        accepts['r']++;
      } else if (c == 'r') {
        if (accepts.find(c) == accepts.end() || accepts[c] == 0) { return -1; }
        accepts[c]--;
        accepts['o']++;
      } else if (c == 'o') {
        if (accepts.find(c) == accepts.end() || accepts[c] == 0) { return -1; }
        accepts[c]--;
        accepts['a']++;
      } else if (c == 'a') {
        if (accepts.find(c) == accepts.end() || accepts[c] == 0) { return -1; }
        accepts[c]--;
        accepts['k']++;
      } else if ( c == 'k') {
        if (accepts.find(c) == accepts.end() || accepts[c] == 0) { return -1; }
        accepts[c]--;
        num_frogs--;
      } else { assert(false); }
      ret = max(ret, num_frogs);
    }
    for (const auto& p : accepts) {
      if (p.second != 0) { return -1; }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string croakOfFrogs;

  croakOfFrogs = "croakcroak";
  ExpectEqual(1, sol.minNumberOfFrogs(croakOfFrogs));

  croakOfFrogs = "crcoakroak";
  ExpectEqual(2, sol.minNumberOfFrogs(croakOfFrogs));

  croakOfFrogs = "croakcrook";
  ExpectEqual(-1, sol.minNumberOfFrogs(croakOfFrogs));

  croakOfFrogs = "croakcroa";
  ExpectEqual(-1, sol.minNumberOfFrogs(croakOfFrogs));

  croakOfFrogs = "roakcroak";
  ExpectEqual(-1, sol.minNumberOfFrogs(croakOfFrogs));

  croakOfFrogs = "crcocraorkakoak";
  ExpectEqual(3, sol.minNumberOfFrogs(croakOfFrogs));
}
