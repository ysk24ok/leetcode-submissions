#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

int main() {
  {
    std::priority_queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    EXPECT_EQ(5, q.top());
  }

  {
    std::priority_queue<int, std::vector<int>, std::less<int>> q;
    q.push(3);
    q.push(4);
    q.push(5);
    EXPECT_EQ(5, q.top());
  }

  {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    q.push(3);
    q.push(4);
    q.push(5);
    EXPECT_EQ(3, q.top());
  }

  {
    auto less = [](const int& left, const int& right) { return left < right; };
    std::priority_queue<int, std::vector<int>, decltype(less)> q(less);
    q.push(3);
    q.push(4);
    q.push(5);
  }

  {
    auto greater = [](const int& left, const int& right) { return left > right; };
    std::priority_queue<int, std::vector<int>, decltype(greater)> q(greater);
    q.push(3);
    q.push(4);
    q.push(5);
    EXPECT_EQ(3, q.top());
  }
}
