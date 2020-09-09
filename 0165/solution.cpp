#include <gtest/gtest.h>

#include <string>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    const size_t n1 = version1.size(), n2 = version2.size();
    size_t prev1 = 0, prev2 = 0, curr1 = 0, curr2 = 0;
    while (curr1 < n1 || curr2 < n2) {
      while (curr1 < n1 && version1[curr1] != '.') { curr1++; }
      while (curr2 < n2 && version2[curr2] != '.') { curr2++; }
      int v1 = (prev1 < curr1) ? stoi(version1.substr(prev1, (curr1 - prev1))) : 0;
      int v2 = (prev2 < curr2) ? stoi(version2.substr(prev2, (curr2 - prev2))) : 0;
      if (v1 > v2) { return 1; }
      else if (v1 < v2) { return -1; }
      prev1 = curr1 + 1;
      curr1 = prev1;
      prev2 = curr2 + 1;
      curr2 = prev2;
    }
    return 0;
  }
};

int main() {
  Solution sol;
  string version1, version2;
  int expected;

  version1 = "0.1", version2 = "1.1";
  expected = -1;
  EXPECT_EQ(expected, sol.compareVersion(version1, version2));

  version1 = "1.0.1", version2 = "1";
  expected = 1;
  EXPECT_EQ(expected, sol.compareVersion(version1, version2));

  version1 = "7.5.2.4", version2 = "7.5.3";
  expected = -1;
  EXPECT_EQ(expected, sol.compareVersion(version1, version2));

  version1 = "1.01", version2 = "1.001";
  expected = 0;
  EXPECT_EQ(expected, sol.compareVersion(version1, version2));

  version1 = "1.0", version2 = "1.0.0";
  expected = 0;
  EXPECT_EQ(expected, sol.compareVersion(version1, version2));

  exit(EXIT_SUCCESS);
}
