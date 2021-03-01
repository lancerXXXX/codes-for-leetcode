/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

 // @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return vector<int> {i, j};
        return vector<int> {-1, -1};
    }
};

// @lc code=end

Accepted
53/53 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 85.32 % of cpp submissions (8.7 MB)