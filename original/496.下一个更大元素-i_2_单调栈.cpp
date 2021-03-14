/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int, int> m;
        vector<int> ans;
        for (auto&& i : nums2) {
            while (!s.empty() && i > s.top()) {
                m[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        for (auto&& i : nums1) {
            ans.push_back(m[i] == 0 ? -1 : m[i]);
        }
        return ans;
    }
};
// @lc code=end

