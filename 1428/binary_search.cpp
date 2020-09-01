#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class BinaryMatrix {
 public:
  BinaryMatrix() = default;

  BinaryMatrix& operator=(vector<vector<int>>&& matrix) {
    matrix_ = matrix;
    return *this;
  }

  int get(int x, int y) {
    return matrix_[x][y];
  }

  vector<int> dimensions() {
    return {
      static_cast<int>(matrix_.size()),
      static_cast<int>(matrix_[0].size())
    };
  }

 private:
  vector<vector<int>> matrix_;
};

class Solution {
 public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dim = binaryMatrix.dimensions();
    int ret = dim[1];
    for (int i = 0; i < dim[0]; ++i) {
      ret = min(ret, binarySearch(binaryMatrix, i, dim[1]));
    }
    if (ret == dim[1]) { return -1; }
    return ret;
  }

  int binarySearch(BinaryMatrix& binaryMatrix, int row_id, int n) {
    int left = 0, right = n - 1;
    int ret = n;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      int val = binaryMatrix.get(row_id, mid);
      if (val == 1) {
        ret = min(ret, mid);
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  BinaryMatrix bmatrix;

  bmatrix = {{0,0},{1,1}};
  EXPECT_EQ(0, sol.leftMostColumnWithOne(bmatrix));

  bmatrix = {{0,0},{0,0}};
  EXPECT_EQ(-1, sol.leftMostColumnWithOne(bmatrix));

  bmatrix = {{0,0,0,1},{0,0,1,1},{0,1,1,1}};
  EXPECT_EQ(1, sol.leftMostColumnWithOne(bmatrix));

  bmatrix = {{0,0,1},{0,1,1},{0,0,0}};
  EXPECT_EQ(1, sol.leftMostColumnWithOne(bmatrix));
}
