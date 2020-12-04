#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>

using namespace std;

class Solution {
 public:
  int kthFactor(int n, int k) {
    stack<int> st;
    int i = 1;
    while (st.empty() || i < st.top()) {
      if (n % i != 0) {
        i++;
        continue;
      }
      int d = n / i;
      if (i < d) {
        st.push(d);
      }
      if (--k == 0) { return i; }
      i++;
    }
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      if (--k == 0) { return v; }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  int n, k, expected;

  n = 12, k = 3, expected = 3;
  EXPECT_EQ(expected, sol.kthFactor(n, k));

  n = 7, k = 2, expected = 7;
  EXPECT_EQ(expected, sol.kthFactor(n, k));

  n = 4, k = 4, expected = -1;
  EXPECT_EQ(expected, sol.kthFactor(n, k));

  n = 1, k = 1, expected = 1;
  EXPECT_EQ(expected, sol.kthFactor(n, k));

  n = 1000, k = 3, expected = 4;
  EXPECT_EQ(expected, sol.kthFactor(n, k));

  exit(EXIT_SUCCESS);
}
