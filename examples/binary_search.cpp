#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

int binary_search(const std::vector<int>& nums, int target,
                  std::function<bool(const std::vector<int>&, int, int)>& is_ok) {
  int ng = -1, ok = nums.size();
  while (ng + 1 < ok) {
    int mid = (ok - ng) / 2 + ng;
    if (is_ok(nums, target, mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int lower_bound(const std::vector<int>& nums, int target) {
  std::function<bool(const std::vector<int>&, int, int)> is_ok =
      [] (const std::vector<int>& nums, int target, int mid) { return nums[mid] >= target; };
  return binary_search(nums, target, is_ok);
}

int upper_bound(const std::vector<int>& nums, int target) {
  std::function<bool(const std::vector<int>&, int, int)> is_ok =
      [] (const std::vector<int>& nums, int target, int mid) { return nums[mid] > target; };
  return binary_search(nums, target, is_ok);
}

int main() {
  std::vector<int> nums;
  int target;

  {
    nums = {1, 2, 3, 4, 5};
    {
      target = 0;
      EXPECT_EQ(0, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(0, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 1;
      EXPECT_EQ(0, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(1, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 2;
      EXPECT_EQ(1, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(2, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 3;
      EXPECT_EQ(2, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(3, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 4;
      EXPECT_EQ(3, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(4, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 5;
      EXPECT_EQ(4, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(5, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 6;
      EXPECT_EQ(5, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(5, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
  }

  {
    nums = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    {
      target = 0;
      EXPECT_EQ(0, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(0, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 1;
      EXPECT_EQ(0, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(1, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 2;
      EXPECT_EQ(1, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(3, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 3;
      EXPECT_EQ(3, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(6, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 4;
      EXPECT_EQ(6, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(8, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 5;
      EXPECT_EQ(8, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(9, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
    {
      target = 6;
      EXPECT_EQ(9, lower_bound(nums, target));
      EXPECT_EQ(std::lower_bound(nums.begin(), nums.end(), target) - nums.begin(), lower_bound(nums, target));
      EXPECT_EQ(9, upper_bound(nums, target));
      EXPECT_EQ(std::upper_bound(nums.begin(), nums.end(), target) - nums.begin(), upper_bound(nums, target));
    }
  }

  return EXIT_SUCCESS;
}
