#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <unordered_map>

using namespace std;

class RecentCounter {
 public:
  RecentCounter() : interval_start_at_(1), num_calls_(0), calls_() {}

  int ping(int t) {
    int new_interval_start_at = t - 3000;
    // outside of the interval
    for (int i = interval_start_at_; i < new_interval_start_at; ++i) {
      if (calls_.find(i) != calls_.end()) {
        num_calls_--;
      }
    }
    interval_start_at_ = new_interval_start_at;
    num_calls_++;
    calls_[t] = true;
    return num_calls_;
  }

 private:
  int interval_start_at_;
  int num_calls_;
  unordered_map<int, bool> calls_;
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
