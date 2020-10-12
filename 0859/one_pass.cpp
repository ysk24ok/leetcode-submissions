#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  bool buddyStrings(string A, string B) {
    if (A.size() != B.size()) { return false; }
    unordered_set<char> unique_chars;
    vector<int> diff_indices;
    bool is_duplicated = false;
    for (size_t i = 0; i < A.size(); ++i) {
      if (unique_chars.find(A[i]) != unique_chars.end()) {
        is_duplicated = true;
      }
      unique_chars.insert(A[i]);
      if (A[i] != B[i]) { diff_indices.push_back(i); }
    }
    if (diff_indices.size() == 0 && is_duplicated) {
      return true;
    } else if (diff_indices.size() == 2 && A[diff_indices[0]] == B[diff_indices[1]] && A[diff_indices[1]] == B[diff_indices[0]]) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution sol;
  string A, B;

  A = "ab", B = "ba";
  EXPECT_TRUE(sol.buddyStrings(A, B));

  A = "ab", B = "ab";
  EXPECT_FALSE(sol.buddyStrings(A, B));

  A = "aa", B = "aa";
  EXPECT_TRUE(sol.buddyStrings(A, B));

  A = "aaaaaaabc", B = "aaaaaaacb";
  EXPECT_TRUE(sol.buddyStrings(A, B));

  A = "", B = "aa";
  EXPECT_FALSE(sol.buddyStrings(A, B));

  exit(EXIT_SUCCESS);
}
