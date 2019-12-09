#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> groups;
    vector<int> group_size_limit;
    for (int i = 0; i < groupSizes.size(); i++) {
      int size = groupSizes[i];
      int group_id = checkAvailableGroup(groups, group_size_limit, size);
      if (group_id == -1) {
        groups.push_back({i});
        group_size_limit.push_back(size);
      } else {
        groups[group_id].push_back(i);
      }
    }
    return groups;
  }

  int checkAvailableGroup(const vector<vector<int>>& groups, const vector<int>& group_size_limit, int expected_size) {
    for (int i = 0; i < groups.size(); i++) {
      // Group size does not match with expected
      if (group_size_limit[i] != expected_size) continue;
      // no more space to add new person
      if (groups[i].size() >= group_size_limit[i]) continue;
      return i;
    }
    return -1;
  }
};

void print_matrix(const vector<vector<int>>& groups) {
  for (auto& row : groups) {
    for (auto& v : row) {
      cout << v << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<int> groupSizes;
  vector<vector<int>> got;

  groupSizes = {3,3,3,3,3,1,3};
  got = sol.groupThePeople(groupSizes);
  print_matrix(got);

  groupSizes = {2,1,3,3,3,2};
  got = sol.groupThePeople(groupSizes);
  print_matrix(got);

  groupSizes = {2,1,2,2,1,2};
  got = sol.groupThePeople(groupSizes);
  print_matrix(got);
}
