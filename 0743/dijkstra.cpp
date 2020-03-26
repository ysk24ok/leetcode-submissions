#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> distance(N, numeric_limits<int>::max());
    distance[K-1] = 0;
    unordered_map<int, vector<int>> map;
    for (int i = 1; i <= N; ++i) map[i] = {};
    for (size_t i = 0; i < times.size(); ++i) {
      const int& source = times[i][0];
      map[source].push_back(i);
    }
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({distance[K-1], K});
    while (!pq.empty()) {
      const P pair = pq.top();
      pq.pop();
      const int& time = pair.first;
      const int& source = pair.second;
      for (const auto& i : map[source]) {
        const int& dest = times[i][1];
        int new_time = time + times[i][2];
        if (new_time < distance[dest-1]) {
          distance[dest-1] = new_time;
          pq.push({new_time, dest});
        }
      }
    }
    int ret = 0;
    for (const auto& dist : distance) {
      if (dist == numeric_limits<int>::max()) return -1;
      ret = max(ret, dist);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> times;
  int N, K;

  times = {{2,1,1},{2,3,1},{3,4,1}};
  N = 4, K = 2;
  assert(sol.networkDelayTime(times, N, K) == 2);

  times = {{1,2,1}};
  N = 2, K = 2;
  assert(sol.networkDelayTime(times, N, K) == -1);

  times = {{1,2,1},{2,1,3}};
  N = 2, K = 2;
  assert(sol.networkDelayTime(times, N, K) == 3);

  //      1
  //     / \
  //  1 /   \ 4
  //   /     \
  //  2 ----- 3
  //      2
  times = {{1,2,1},{2,3,2},{1,3,4}};
  N = 3, K = 1;
  assert(sol.networkDelayTime(times, N, K) == 3);
}
