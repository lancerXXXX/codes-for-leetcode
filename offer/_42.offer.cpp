#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int current_level_max = 0, global_level_max = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      current_level_max = max(nums[i], current_level_max + nums[i]);
      global_level_max = max(global_level_max, current_level_max);
    }
    return global_level_max;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> va(a, a + 9);
  s.maxSubArray(va);
  return 0;
}
