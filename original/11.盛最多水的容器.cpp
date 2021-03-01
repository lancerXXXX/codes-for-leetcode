/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_val = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            max_val = max(max_val, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? i++ : j--;
        }
        return max_val;
    }
};
// @lc code=end

