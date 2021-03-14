/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<pair<int, int>> v;
        stack<pair<int, int>*> s;
        int length = nums.size();
        vector<int> ans(length, -1);
        for (int i = 0; i < length; i++) {
            v.push_back(make_pair(i, nums[i]));
        }
        for (int i = 0; i < 2 * length; i++) {
            while (!s.empty() && v[i % length].second > s.top()->second) {
                ans[s.top()->first] = v[i % length].second;
                s.pop();
            }
            s.push(&v[i % length]);
        }
        return ans;
    }
};
// @lc code=end

