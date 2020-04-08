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
  int countElements(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int ret = 0;
    int val = arr[0];
    int count = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
      if (arr[i] == val) {
        count++;
      } else {
        if (arr[i] == val + 1) { ret += count; }
        val = arr[i];
        count = 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> arr;

  arr = {1,2,3};
  assert(sol.countElements(arr) == 2);

  arr = {1,1,3,3,5,5,7,7};
  assert(sol.countElements(arr) == 0);

  arr = {1,1,2,2};
  assert(sol.countElements(arr) == 2);

  arr = {1,3,2,3,5,0};
  assert(sol.countElements(arr) == 3);
}
