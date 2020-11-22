#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

static vector<string> morse_codes = {
  ".-",
  "-...",
  "-.-.",
  "-..",
  ".",
  "..-.",
  "--.",
  "....",
  "..",
  ".---",
  "-.-",
  ".-..",
  "--",
  "-.",
  "---",
  ".--.",
  "--.-",
  ".-.",
  "...",
  "-",
  "..-",
  "...-",
  ".--",
  "-..-",
  "-.--",
  "--.."
};

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    unordered_set<string> set;
    for (const string& word : words) {
      string representation;
      for (const char& c : word) {
        representation += morse_codes[static_cast<int>(c - 'a')];
      }
      set.insert(representation);
    }
    return set.size();
  }
};


int main() {
  Solution sol;
  vector<string> words;
  int expected;

  words = {"gin", "zen", "gig", "msg"};
  expected = 2;
  EXPECT_EQ(expected, sol.uniqueMorseRepresentations(words));

  exit(EXIT_SUCCESS);
}
