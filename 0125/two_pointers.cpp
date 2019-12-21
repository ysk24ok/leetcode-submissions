#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    bool ret = true;
    while (l < r) {
      while (!isAlphabet(s[l]) && l < r) l++;
      while (!isAlphabet(s[r]) && l < r) r--;
      if (toLower(s[l]) != toLower(s[r])) {
        ret = false;
        break;
      }
      l++;
      r--;
    }
    return ret;
  }

  bool isAlphabet(char c) {
    int diff;
    diff = int(c) - int('a');
    if (diff >= 0 && diff < 26) return true;
    diff = int(c) - int('A');
    if (diff >= 0 && diff < 26) return true;
    return false;
  }

  char toLower(char c) {
    if (int(c) - int('a') >= 0) return c;
    return char(int(c) + 32);
  }
};

int main() {
  Solution sol;
  string s;

  assert(sol.isAlphabet('a'));
  assert(sol.isAlphabet('z'));
  assert(!sol.isAlphabet(' '));
  assert(!sol.isAlphabet(':'));
  assert(!sol.isAlphabet(','));
  assert(sol.isAlphabet('A'));
  assert(sol.isAlphabet('Z'));

  assert(sol.toLower('a') == 'a');
  assert(sol.toLower('z') == 'z');
  assert(sol.toLower('A') == 'a');
  assert(sol.toLower('Z') == 'z');

  s = "A man, a plan, a canal: Panama";
  assert(sol.isPalindrome(s));

  s = "race a car";
  assert(!sol.isPalindrome(s));
}
