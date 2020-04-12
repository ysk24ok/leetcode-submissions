#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (const auto& stone : stones) { pq.push(stone); }
    int ret = 0;
    while (!pq.empty()) {
      const int first = pq.top();
      pq.pop();
      if (!pq.empty()) {
        const int second = pq.top();
        pq.pop();
        if (first > second) {
          pq.push(first - second);
        }
      } else {
        ret = first;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> stones;

  // 2,4,1,1,1
  // 2,1,1,1
  // 1,1,1
  stones = {2,7,4,1,8,1};
  assert(sol.lastStoneWeight(stones) == 1);

  // 2,4,1,1
  // 2,1,1
  // 1,1
  stones = {2,7,4,1,8};
  assert(sol.lastStoneWeight(stones) == 0);

  stones = {};
  assert(sol.lastStoneWeight(stones) == 0);
}
