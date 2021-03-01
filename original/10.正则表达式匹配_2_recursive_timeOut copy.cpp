// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem10.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        return isMatchItem(s, p, i, j);
    }
    bool isMatchItem(string& s, string& p, int i, int j) {
        if (i <= s.size() && j < p.size()) {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                if (j + 1 < p.size() && p[j + 1] == '*') 
                    return isMatchItem(s, p, i, j + 2);
                else
                    return false;
            }
            else {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    return  isMatchItem(s, p, i, j + 2) || isMatchItem(s, p, i + 1, j);
                }
                else {
                    return isMatchItem(s, p, i + 1, j + 1);
                }
            }
        }
        return i >= s.size() && j >= p.size();
    }
};
// @lc code=end

447/447 cases passed (44 ms)
Your runtime beats 18.85 % of cpp submissions
Your memory usage beats 97.66 % of cpp submissions (6.1 MB)