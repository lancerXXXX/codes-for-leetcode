/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

 // @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        long pre = x, back = 0;
        // 12321  // 1221
        while (x != 0) {
            back = back * 10 + x % 10;
            x /= 10;
        }
        return pre == back && pre >= 0;
    }
};
// @lc code=end

Accepted
11510/11510 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 96.05 % of cpp submissions (5.6 MB)
