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
private:
    int i = 0, j = 0;
public:
    bool isMatch(string s, string p) {
        if (i <= s.size() && j < p.size()) {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    j += 2;
                    bool s1 = isMatch(s, p);
                    j -= 2;
                    return s1;
                }
                else
                    return false;
            }
            else {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    j += 2;
                    bool s1 = isMatch(s, p);
                    j -= 2;
                    i++;
                    bool s2 = isMatch(s, p);
                    j += 2;
                    bool s3 = isMatch(s, p);
                    i--;
                    j -= 2;
                    return s1 || s2 || s3;
                }
                else {
                    i++; j++;
                    bool s1 = isMatch(s, p);
                    i--; j--;
                    return s1;
                }
            }
        }
        return i >= s.size() && j >= p.size();
    }
};
// @lc code=end

