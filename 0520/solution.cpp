#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() == 1) return true;
    bool all_lowercase = false;
    bool all_uppercase = false;
    bool only_first = false;
    if (isLowerCase(word[0]) && isLowerCase(word[1])) all_lowercase = true;
    else if (isUpperCase(word[0]) && isUpperCase(word[1])) all_uppercase = true;
    else if (isUpperCase(word[0]) && isLowerCase(word[1])) only_first = true;
    else return false;
    for (size_t i = 2; i < word.size(); i++) {
      if (all_lowercase && isUpperCase(word[i])) return false;
      if (all_uppercase && isLowerCase(word[i])) return false;
      if (only_first && isUpperCase(word[i])) return false;
    }
    return true;
  }

  bool isUpperCase(char c) {
    int diff = int(c) - int('A');
    if (diff >= 0 && diff < 26) return true;
    else return false;
  }

  bool isLowerCase(char c) {
    int diff = int(c) - int('a');
    if (diff >= 0 && diff < 26) return true;
    else return false;
  }
};

int main() {
  Solution sol;
  assert(sol.detectCapitalUse("a"));
  assert(sol.detectCapitalUse("A"));
  assert(sol.detectCapitalUse("ab"));
  assert(sol.detectCapitalUse("Ab"));
  assert(sol.detectCapitalUse("AB"));
  assert(!sol.detectCapitalUse("aB"));
  assert(sol.detectCapitalUse("abc"));
  assert(sol.detectCapitalUse("ABC"));
  assert(sol.detectCapitalUse("Abc"));
  assert(!sol.detectCapitalUse("aBC"));
  assert(!sol.detectCapitalUse("abC"));
  assert(!sol.detectCapitalUse("AbC"));
}
