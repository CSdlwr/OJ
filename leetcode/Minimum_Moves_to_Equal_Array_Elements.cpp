// Copyright [2016] <luming.lv>

#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int minMoves(vector<int>& nums) {
  int ans = 0;

  int min = 2147483647;

  for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
    if (nums[i] < min) {
      min = nums[i];
    }
  }

  for (vector<int>::size_type i = 0; i < nums.size(); ++i) {
    ans += nums[i] - min;
  }
  return ans;
}

int main() {
  printf("%d\n", INT_MAX);
}
