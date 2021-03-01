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
        if (i <= s.size() && j < p.size()) {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                if (j + 1 < p.size() && p[j + 1] == '*')
                    return(isMatch(s.substr(i), p.substr(j + 2))); //tag 1
                else
                    return false;
            }
            else {
                if (j + 1 < p.size() && p[j + 1] == '*')
                    return isMatch(s.substr(i), p.substr(j + 2))|| // use * for 0
                           isMatch(s.substr(i + 1), p.substr(j));  // use * for 1  
                else
                    return isMatch(s.substr(i + 1), p.substr(j + 1));
            }
        }
        return i >= s.size() && j >= p.size();
    }
};
// @lc code=end

Accepted
447/447 cases passed (204 ms)
Your runtime beats 12.19 % of cpp submissions
Your memory usage beats 6.6 % of cpp submissions (13.9 MB)
