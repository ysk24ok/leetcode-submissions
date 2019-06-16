#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> idx_map;
    vector<int> answer;
    for (int i = 0, size = nums.size(); i < size; i++) {
      int first = nums[i];
      int second = target - first;
      auto s = idx_map.find(second);
      if (s != idx_map.end()) {
        int j = s->second;
        vector<int> answer1{j, i};
        vector<int> answer2{i, j};
        answer = i < j ? answer2 : answer1;
        break;
      }
      idx_map[first] = i;
    }
    return answer;
  }
};

int main() {
  Solution * sol = new Solution();

  vector<int> nums{2,7,11,15};
  vector<int> answer = sol->twoSum(nums, 9);
  assert (answer[0] == 0 && answer[1] == 1);

  nums = {3,2,4};
  answer = sol->twoSum(nums, 6);
  assert (answer[0] == 1 && answer[1] == 2);

  delete sol;
}
