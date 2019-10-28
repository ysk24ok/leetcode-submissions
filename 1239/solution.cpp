#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxLength(vector<string>& arr) {
    if (arr.size() == 1) {
      return arr[0].size();
    } else if (arr.size() == 1) {
      return 0;
    }
    int ret = 0;
    vector<bool> valid(arr.size(), true);
    for (size_t i = 0; i < arr.size(); i++) {
      if (!self_check(arr[i])) {
        valid[i] = false;
        cout << arr[i] << " is not valid" << endl;
      }
    }
    for (size_t i = 0; i < arr.size(); i++) {
      string base = arr[i];
      if (!valid[i]) continue;
      for (size_t j = 0; j < arr.size(); j++) {
        if (!valid[j]) continue;
        if (i == j) continue;
        if (check(base, arr[j])) {
          base += arr[j];
        }
      }
      if (base.size() > ret) {
        ret = base.size();
      }
    }
    cout << ret << endl;
    return ret;
  }

  bool check(string& s1, string& s2) {
    for (auto& c1 : s1) {
      for (auto& c2 : s2) {
        if (c1 == c2) {
          return false;
        }
      }
    }
    return true;
  }

  bool self_check(string& s) {
    for (size_t i = 0; i < s.size()-1; i++) {
      for (size_t j = i+1; j < s.size(); j++) {
        if (s[i] == s[j]) return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<string> v;
  int got;

  v = {"un", "iq", "ue"};
  got = sol.maxLength(v);
  assert(got == 4);

  v = {"un", "iq", "ue", "ho"};
  got = sol.maxLength(v);
  assert(got == 6);

  v = {"cha","r","act","ers"};
  got = sol.maxLength(v);
  assert(got == 6);

  v = {"yy","bkhwmpbiisbldzknpm"};
  got = sol.maxLength(v);
  assert(got == 0);

  v = {"e","tpgynpylqbyqjaf","svkgfmpgftxjjrcxxsog","bxypbbrlckiolfwpqgsoc","kwnelumrnnsryjdeppanuqbsu"};
  got = sol.maxLength(v);
  assert(got == 1);
}
