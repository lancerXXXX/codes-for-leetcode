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

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0, length = 0;
        while (right < s.size()) {
            char c = s[right]; // 当前处理字符
            window[c]++;
            right++;
            while (window[c] > 1) { // 左指针缩减窗口
                char d = s[left]; // 要删除的字符
                window[d]--;
                left++;
            }
            length = max(length, right - left);
        }
        return length;
    }
};
// @lc code=end

