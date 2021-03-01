/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            auto it = um.find(target - nums[i]);
            if (it != um.end())
                return vector<int> {i, it->second};
            else
                um.insert(make_pair(nums[i], i));
        }
        return vector<int> {-1, -1};
    }
};
// @lc code=end

Accepted
53/53 cases passed (8 ms)
Your runtime beats 75.78 % of cpp submissions
Your memory usage beats 62.64 % of cpp submissions (8.8 MB)