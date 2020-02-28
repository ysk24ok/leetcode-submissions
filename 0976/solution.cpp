#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());
    for (size_t i = 0; i < A.size()-2; i++) {
      if (A[i] < A[i+1] + A[i+2]) return A[i] + A[i+1] + A[i+2];
    }
    return 0;
  }
};

int main() {
  Solution sol;
  vector<int> A;

  A = {2,1,2};
  assert(sol.largestPerimeter(A) == 5);

  A = {1,2,1};
  assert(sol.largestPerimeter(A) == 0);

  A = {3,2,3,4};
  assert(sol.largestPerimeter(A) == 10);

  A = {2,3,4,5,10};
  assert(sol.largestPerimeter(A) == 12);

  A = {4,5,10,20};
  assert(sol.largestPerimeter(A) == 0);
}
