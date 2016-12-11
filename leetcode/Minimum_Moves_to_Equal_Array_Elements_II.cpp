// Copyright [2016] <luming.lv>

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;

int minMoves2(vector<int>& nums) {
  int ans = 0;
  vector<int>::size_type i = 0;
  sort(nums.begin(), nums.end());
  int target = nums[nums.size() / 2];

  for (i = 0; i < nums.size(); ++i) {
    ans += abs(target - nums[i]);
  }

  return ans;
}
