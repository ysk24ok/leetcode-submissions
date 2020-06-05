#include <cstdlib>
#include <numeric>
#include <random>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

random_device seed_gen;
mt19937 engine(seed_gen());

class Solution {
 public:
  Solution(vector<int>& w) :
      current_idx_(0),
      call_count_(0),
      dist_(1, accumulate(w.begin(), w.end(), 0)) {
    const size_t m = w.size();
    prefix_sum_.resize(m);
    int total = 0;
    for (size_t i = 0; i < m; ++i) {
      total += w[i];
      prefix_sum_[i] = total;
    }
  }

  int pickIndex() {
    int rand = dist_(engine);
    int left = 0, right = prefix_sum_.size()-1;
    while (left < right) {
      int mid = (right - left) / 2 + left;
      if (rand > prefix_sum_[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }

 private:
  size_t current_idx_;
  size_t call_count_;
  vector<int> prefix_sum_;
  uniform_int_distribution<> dist_;
};

int main() {
  vector<int> w;
  w = {1,0};

  Solution sol(w);
  EXPECT_EQ(0, sol.pickIndex());
  EXPECT_EQ(0, sol.pickIndex());
  EXPECT_EQ(0, sol.pickIndex());

  exit(EXIT_SUCCESS);
}
