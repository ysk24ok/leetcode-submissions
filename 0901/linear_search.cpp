#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class StockSpanner {
 public:
  StockSpanner() : values_() {}

  int next(int price) {
    values_.push_back(price);
    int ret = 0;
    for (size_t i = values_.size(); i > 0; --i) {
      if (values_[i-1] > price) { break; }
      ret++;
    }
    return ret;
  }

 private:
  vector<int> values_;
};

int main() {
  StockSpanner ss;
  EXPECT_EQ(1, ss.next(100));
  EXPECT_EQ(1, ss.next(80));
  EXPECT_EQ(1, ss.next(60));
  EXPECT_EQ(2, ss.next(70));
  EXPECT_EQ(1, ss.next(60));
  EXPECT_EQ(4, ss.next(75));
  EXPECT_EQ(6, ss.next(85));
  exit(EXIT_SUCCESS);
}
