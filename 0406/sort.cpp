#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

bool comp(const vector<int>& lh, const vector<int>& rh) {
  if (lh[0] < rh[0]) return true;
  else if (lh[0] > rh[0]) return false;
  else return lh[1] < rh[1];
}

// time complexity: O(NlogN + N^2)
// space complecity: O(N)
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), comp);
    vector<vector<int>> ret(people.size());
    for (auto& person : people) {
      int taller_people = 0;
      for (int i = 0; i < ret.size(); i++) {
        if (ret[i].size() == 0 && person[1] == taller_people) {
          ret[i] = person;
          break;
        }
        if (ret[i].size() == 0 || (ret[i].size() == 2 && ret[i][0] == person[0])) {
          taller_people++;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> people, expected;

  people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
  expected = {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}};
  assert(sol.reconstructQueue(people) == expected);
}
