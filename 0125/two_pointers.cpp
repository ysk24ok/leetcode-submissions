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
      while (!isAlphanumeric(s[l]) && l < r) l++;
      while (!isAlphanumeric(s[r]) && l < r) r--;
      if (toLower(s[l]) != toLower(s[r])) {
        ret = false;
        break;
      }
      l++;
      r--;
    }
    return ret;
  }

  bool isAlphanumeric(char c) {
    int ascii_code = int(c);
    if (48 <= ascii_code && ascii_code <= 57) return true;
    int diff;
    diff = ascii_code - int('a');
    if (diff >= 0 && diff < 26) return true;
    diff = ascii_code - int('A');
    if (diff >= 0 && diff < 26) return true;
    return false;
  }

  char toLower(char c) {
    int ascii_code = int(c);
    if (48 <= ascii_code && ascii_code <= 57) return c;
    if (ascii_code - int('a') >= 0) return c;
    return char(ascii_code + 32);
  }
};

int main() {
  Solution sol;
  string s;

  assert(sol.isAlphanumeric('0'));
  assert(sol.isAlphanumeric('9'));
  assert(sol.isAlphanumeric('a'));
  assert(sol.isAlphanumeric('z'));
  assert(!sol.isAlphanumeric(' '));
  assert(!sol.isAlphanumeric(':'));
  assert(!sol.isAlphanumeric(','));
  assert(sol.isAlphanumeric('A'));
  assert(sol.isAlphanumeric('Z'));

  assert(sol.toLower('a') == 'a');
  assert(sol.toLower('z') == 'z');
  assert(sol.toLower('A') == 'a');
  assert(sol.toLower('Z') == 'z');

  s = "A man, a plan, a canal: Panama";
  assert(sol.isPalindrome(s));

  s = "race a car";
  assert(!sol.isPalindrome(s));

  s = "0P";
  assert(!sol.isPalindrome(s));
}
