// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem5.h"

using namespace std;
// @before-stub-for-debug-end

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


using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, max_length = 0;
        for (int pre = 0, back = s.size() - 1; pre < s.size(); back--) {
            if (pre > back) {
                pre++;
                back = s.size();
            }
            if (s[pre] == s[back]) {
                if (isPalindrome(s, pre, back))
                    if (back - pre + 1 > max_length) {
                        begin = pre;
                        max_length = back - pre + 1;
                    }
            }
        }
        return s.substr(begin, max_length);
    }
    bool isPalindrome(string& s, int begin, int end) {
        for (; begin < end && s[begin] == s[end]; begin++, end--);
        return begin >= end;
    }
};
// @lc code=end

Time Limit Exceeded
176/176 cases passed (N/A)