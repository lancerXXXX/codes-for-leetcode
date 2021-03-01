/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
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
    int myAtoi(string s) {
        for (int i = 0; i < s.size(); i++) 
            if (s[i] == ' ');
            else if (s[i] == '+' || s[i] == '-' || s[i] >= '0' && s[i] <= '9')
                return calculate(s, s[i] >= '0' && s[i] <= '9' ? i : i + 1, s[i] != '-');
            else return 0;
        return 0;
    }
    int calculate(string& s, int i, bool positive) {
        int num = 0;
        for (; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') 
                if (num <= (INT32_MAX - s[i] + '0') / 10 && num >= (INT32_MIN + s[i] - '0') / 10)
                    num = num * 10 + (positive ? s[i] - '0' : '0' - s[i]);
                else
                    return positive ? INT32_MAX : INT32_MIN;
            else break;
        }
        return num;
    }
};
// @lc code=end

