/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pre = 0, back = 0, length = 0;
        unordered_set<char> us;
        while (back < s.length()) {
            if (us.find(s[back]) != us.end())
                us.erase(s[pre++]);
            else
                us.insert(s[back++]);
            length = max(length, (int)us.size());
        }
        return length;
    }
};
// @lc code=end

