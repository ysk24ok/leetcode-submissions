#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    unordered_map<char, size_t> counterB;
    for (size_t i = 0; i < B.size(); ++i) {
      unordered_map<char, size_t> counter = getCounter(B[i]);
      for (const auto& p: counter) {
        counterB[p.first] = max(counterB[p.first], p.second);
      }
    }
    vector<string> ret;
    for (size_t i = 0; i < A.size(); ++i) {
      unordered_map<char, size_t> counter = getCounter(A[i]);
      bool ok = true;
      for (const auto& p : counterB) {
        if (counter.find(p.first) == counter.end() || counter[p.first] < p.second) {
          ok = false;
        }
      }
      if (ok) {
        ret.push_back(A[i]);
      }
    }
    return ret;
  }

  unordered_map<char, size_t> getCounter(const string& str) {
    unordered_map<char, size_t> counter;
    for (const char& c : str) {
      counter[c]++;
    }
    return counter;
  }
};

int main() {
  Solution sol;
  vector<string> A, B, expected;

  A = {"amazon", "apple", "facebook", "google", "leetcode"}, B = {"e", "o"};
  expected = {"facebook", "google", "leetcode"};
  EXPECT_EQ(expected, sol.wordSubsets(A, B));

  A = {"amazon", "apple", "facebook", "google", "leetcode"}, B = {"l", "e"};
  expected = {"apple", "google", "leetcode"};
  EXPECT_EQ(expected, sol.wordSubsets(A, B));

  A = {"amazon", "apple", "facebook", "google", "leetcode"}, B = {"e", "oo"};
  expected = {"facebook", "google"};
  EXPECT_EQ(expected, sol.wordSubsets(A, B));

  A = {"amazon", "apple", "facebook", "google", "leetcode"}, B = {"lo", "eo"};
  expected = {"google", "leetcode"};
  EXPECT_EQ(expected, sol.wordSubsets(A, B));

  A = {"amazon", "apple", "facebook", "google", "leetcode"}, B = {"ec", "oc", "ceo"};
  expected = {"facebook", "leetcode"};
  EXPECT_EQ(expected, sol.wordSubsets(A, B));

  exit(EXIT_SUCCESS);
}
