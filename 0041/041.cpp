#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    // Swap elements in vector so that element at index i should be i+1
    // e.x. if nums[3] is 2, swap nums[3] and nums[2-1]
    int idx = 0;
    while (idx < nums.size()) {
      int element = nums[idx];
      if (element >= 1 && element < nums.size() && element != idx+1
            && nums[element-1] != element) {
          swap(nums, element-1, idx);
      } else {
        idx++;
      }
    }
    // When element at index i is not i+1, i+1 is the one
    idx = 0;
    while (idx < nums.size() && nums[idx] == idx + 1) {
      idx++;
    }
    return idx+1;
  }

  void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main() {
  Solution* sol = new Solution();
  vector<int> d;
  d = {1,2,0};
  assert(sol->firstMissingPositive(d) == 3);
  d = {1,3,2};
  assert(sol->firstMissingPositive(d) == 4);
  d = {};
  assert(sol->firstMissingPositive(d) == 1);
  d = {1000,-1};
  assert(sol->firstMissingPositive(d) == 1);
  d = {1,1};
  assert(sol->firstMissingPositive(d) == 2);
}
