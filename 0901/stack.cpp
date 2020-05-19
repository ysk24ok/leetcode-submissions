#include <cstdlib>
#include <stack>

#include "gtest/gtest.h"

using namespace std;

class StockSpanner {
 public:
  StockSpanner() : stack_() {}

  int next(int price) {
    int res = 1;
    while (!stack_.empty() && stack_.top().first <= price) {
      res += stack_.top().second;
      stack_.pop();
    }
    stack_.push({price, res});
    return res;
  }

 private:
  stack<pair<int, int>> stack_;
};

int main() {
  StockSpanner ss;
  // stack: (100,1)
  EXPECT_EQ(1, ss.next(100));
  // stack: (80,1), (100,1)
  EXPECT_EQ(1, ss.next(80));
  // stack: (60,1), (80,1), (100,1)
  EXPECT_EQ(1, ss.next(60));
  // stack: (70,2), (80,1), (100,1)
  EXPECT_EQ(2, ss.next(70));
  // stack: (60, 1), (70,2), (80,1), (100,1)
  EXPECT_EQ(1, ss.next(60));
  // stack: (75,4), (80,1), (100,1)
  EXPECT_EQ(4, ss.next(75));
  // stack: (85,6), (100,1)
  EXPECT_EQ(6, ss.next(85));
  exit(EXIT_SUCCESS);
}
