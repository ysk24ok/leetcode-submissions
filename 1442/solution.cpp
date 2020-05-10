#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    int ret = 0;
    for (int i = 0; i < arr.size(); ++i) {
      int a = -1;
      for (int j = i + 1; j < arr.size(); ++j) {
        if (a != -1) { a ^= arr[j-1]; }
        else { a = arr[j-1]; }
        int b = -1;
        for (int k = j; k < arr.size(); ++k) {
          if (b != -1) { b ^= arr[k]; }
          else { b = arr[k]; }
          if (a == b) { ret++; }
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> arr;

  arr = {2,3,1,6,7};
  ExpectEqual(4, sol.countTriplets(arr));

  arr = {1,1,1,1,1};
  ExpectEqual(10, sol.countTriplets(arr));

  arr = {2,3};
  ExpectEqual(0, sol.countTriplets(arr));

  arr = {1,3,5,7,9};
  ExpectEqual(3, sol.countTriplets(arr));

  arr = {7,11,12,9,5,2,7,17,22};
  ExpectEqual(8, sol.countTriplets(arr));
}
