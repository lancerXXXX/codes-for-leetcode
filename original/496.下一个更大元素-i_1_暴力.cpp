/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

 // @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (auto&& i : nums1) {
            bool found = false;
            int temp = -1;
            for (auto&& j : nums2) {
                if (j == i) {
                    found = true;
                }
                if (found && j > i) {
                    temp = j;
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

