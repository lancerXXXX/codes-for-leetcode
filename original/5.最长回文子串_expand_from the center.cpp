/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        // i = 1
        // "abb"  --> 3  "bbbb"  --> 3
        // "abba" --> 4  "bbbb"  --> 4
        int max_len = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = isPalindrome(s, i, i);
            int len2 = isPalindrome(s, i, i + 1);
            int len = max(len1, len2);
            if (len > max_len) {
                max_len = len;
                left = i - (len - 1) / 2;
            }
        }
        return s.substr(left, max_len);
    }
    int isPalindrome(string& s, int l, int r) {
        for (;l >= 0 && r < s.size() && s[l] == s[r];l--, r++);
        return r - l - 1; // here is not '+1'
    }
};
// @lc code=end

Accepted
176/176 cases passed (16 ms)
Your runtime beats 93.15 % of cpp submissions
Your memory usage beats 93.68 % of cpp submissions (7 MB)