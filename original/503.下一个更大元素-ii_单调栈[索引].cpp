/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

 // @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int length = nums.size();
        vector<int> ans(length, -1);
        for (int i = 0; i < 2 * length; i++) {
            while (!s.empty() && nums[i % length] > nums[s.top()]) {
                ans[s.top()] = nums[i % length];
                s.pop();
            }
            s.push(i % length);
        }
        return ans;
    }
};
// @lc code=end

