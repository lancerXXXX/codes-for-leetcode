/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

 // @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int back = 0;
        // 12321  // 1221
        while (x > back) {
            back = back * 10 + x % 10;
            x /= 10;
        }
        return  x == back || x == back / 10;
    }
};
// @lc code=end

Accepted
11510/11510 cases passed (8 ms)
Your runtime beats 91.68 % of cpp submissions
Your memory usage beats 84.67 % of cpp submissions (5.8 MB)