#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (t_ != t){
      m_ = {};
      createMap(t);
      t_ = t;
    }
    int prev = 0;   // the index where char s[i-1] appears in string t
    for (size_t i = 0; i < s.size(); i++) {
      char& c = s[i];
      if (m_.find(c) == m_.end()) return false;
      // vector v contains the indexes
      // where a character which is the same as char s[i] appears in string t
      vector<int>& v = m_[c];
      prev = binarySearch(v, prev, 0, v.size()-1);
      if (prev < 0) return false;
      prev += 1;
    }
    return true;
  }

  int binarySearch(const vector<int>& v, int index, int l, int r) {
    // Try to find the index or slightly bigger one than the index
    while (l < r) {
      int mid = (l + r) / 2;
      if (index == v[mid]) {
        return index;
      } else if (index < v[mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (v[l] >= index) {
      return v[l];
    } else {
      return (l < v.size()-1) ? v[l+1] : -1;
    }
  }

 private:
  void createMap(const string& t) {
    for (size_t i = 0; i < t.size(); i++) {
      const char& c = t[i];
      if (m_.find(c) == m_.end()) {
        m_[c] = {};
      }
      m_[c].push_back(i);
    }
  }

  string t_ = {""};
  unordered_map<char, vector<int>> m_;
};

int main() {
  Solution sol;
  vector<int> vec;

  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 6, 0, vec.size()-1) == 6);
  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 1, 0, vec.size()-1) == 2);
  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 3, 0, vec.size()-1) == 6);
  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 7, 0, vec.size()-1) == 8);
  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 9, 0, vec.size()-1) == 11);
  vec = {2, 6, 8, 11};
  assert(sol.binarySearch(vec, 12, 0, vec.size()-1) == -1);

  string s;
  string t;

  s = "abc";
  t = "ahbgdc";
  assert(sol.isSubsequence(s, t));

  s = "axc";
  t = "ahbgdc";
  assert(!sol.isSubsequence(s, t));

  s = "aec";
  t = "abcde";
  assert(!sol.isSubsequence(s, t));

  s = "";
  t = "";
  assert(sol.isSubsequence(s, t));

  s = "leeeeetcode";
  t = "yyyylyyyyeyyyyeyyyyyeyyyytyyyycyyyyycyyyyyoyyyyydyyyyyeyyyy";
  assert(!sol.isSubsequence(s, t));
}
