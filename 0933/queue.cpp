#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr int INTERVAL_LENGTH = 3000;

class RecentCounter {
 public:
  RecentCounter() : q_() {}

  int ping(int t) {
    q_.push(t);
    int s = t - INTERVAL_LENGTH;
    while (q_.front() < s) {
      q_.pop();
    }
    return q_.size();
  }

 private:
  queue<int> q_;
};

int main() {
  {
    RecentCounter counter;
    EXPECT_EQ(1, counter.ping(1));  // 1
    EXPECT_EQ(2, counter.ping(100));  // 1, 100
    EXPECT_EQ(3, counter.ping(3001)); // 1, 100, 3001
    EXPECT_EQ(3, counter.ping(3002)); // 100, 3001, 3002
  }

  {
    RecentCounter counter;
    EXPECT_EQ(1, counter.ping(642));
    EXPECT_EQ(2, counter.ping(1849));
    EXPECT_EQ(1, counter.ping(4921));
    EXPECT_EQ(2, counter.ping(5936));
    EXPECT_EQ(3, counter.ping(5957));
  }

  exit(EXIT_SUCCESS);
}
