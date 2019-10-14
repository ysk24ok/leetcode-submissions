#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxEqualFreq(vector<int>& nums) {
    // key: num, val: frequency
    unordered_map<int, int> freq;
    // key: frequency, val: count
    unordered_map<int, int> count;
    int ret = 0;
    int max_freq = 0;
    for (int i = 0; i < nums.size(); i++) {
      int& num = nums[i];
      init(freq, num);
      freq[num] += 1;
      init(count, freq[num]);
      count[freq[num]] += 1;
      if (freq[num] > 1) {
        count[freq[num]-1] -= 1;
        if (count[freq[num]-1] == 0) {
          count.erase(freq[num]-1);
        }
      }
      max_freq = max(max_freq, freq[num]);
      // all elements appear once
      if (max_freq == 1) {
        ret = i + 1;
      // all elements appear several times
      } else {
        // except only one number appears once
        // and all other numbers appear the same times
        if (count[1] == 1 && count.size() == 2) {
          ret = i + 1;
        // except only one number appears max_freq times
        // and all other numbers appear max_freq-1 times
        } else if (count[max_freq] == 1 && count[max_freq-1] == freq.size()-1) {
          ret = i + 1;
        }
      }
    }
    return ret;
  }

  void init(unordered_map<int, int>& map, int key) {
    if (map.find(key) == map.end()) {
      map[key] = 0;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {2,2,1,1,5,3,3,5};
  assert(sol.maxEqualFreq(nums) == 7);

  nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
  assert(sol.maxEqualFreq(nums) == 13);

  nums = {1,1,1,2,2,2};
  assert(sol.maxEqualFreq(nums) == 5);

  nums = {10,2,8,9,3,8,1,5,2,3,7,6};
  assert(sol.maxEqualFreq(nums) == 8);

  nums = {1,2,3,1,2,3,4,4,4,4,1,2,3,5,6};
  assert(sol.maxEqualFreq(nums) == 13);
}
