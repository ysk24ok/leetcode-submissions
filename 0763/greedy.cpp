#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    int ends[26];
    for (size_t i = 0; i < S.size(); i++) {
      ends[S[i] - 'a'] = i;
    }
    vector<int> ret;
    int partition_start = 0, partition_end = 0;
    for (size_t i = 0; i < S.size(); i++) {
      int end = ends[S[i] - 'a'];
      partition_end = max(partition_end, end);
      if (i == partition_end) {
        ret.push_back(partition_end - partition_start + 1);
        partition_start = partition_end + 1;
        partition_end += 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string S;
  vector<int> expected;

  S = "ababcbacadefegdehijhklij";
  expected = {9, 7, 8};
  EXPECT_EQ(expected, sol.partitionLabels(S));

  S = "abb";

  exit(EXIT_SUCCESS);
}
