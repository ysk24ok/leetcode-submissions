#include <gtest/gtest.h>

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution() {
    mapping = {
      {'2', {'a', 'b', 'c'}},
      {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}},
      {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}},
      {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}},
      {'9', {'w', 'x', 'y', 'z'}},
    };
  }

  vector<string> letterCombinations(string digits) {
    vector<string> ret;
    size_t capacity = 1;
    for (const auto& digit: digits) {
        capacity *= mapping[digit].size();
    }
    ret.reserve(capacity);

    queue<string> q;
    for (const auto& c: mapping[digits[0]]) {
        q.push(string(1, c));
    }
    while (q.size() > 0) {
      if (q.front().size() == digits.size()) {
        ret.push_back(q.front());
      } else {
        const char& next_digit = digits[q.front().size()];
        for (const auto& c: mapping[next_digit]) {
            q.push({q.front() + string(1, c)});
        }
      }
      q.pop();
    }
    return ret;
  }

 private:
  unordered_map<char, vector<char>> mapping;
};


int main() {
  Solution sol;
  string digits;
  vector<string> expected;

  digits = "23", expected = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
  EXPECT_EQ(sol.letterCombinations(digits), expected);

  digits = "", expected = {};
  EXPECT_EQ(sol.letterCombinations(digits), expected);

  digits = "2", expected = {"a","b","c"};
  EXPECT_EQ(sol.letterCombinations(digits), expected);

  exit(EXIT_SUCCESS);
}
