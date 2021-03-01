// @before-stub-for-debug-begin
#include <vector>
#include <string>
// #include "commoncppproblem10.h"

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

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        while (i <= s.size() && j < p.size()) {
            if (i < s.size()) {
                if (s[i] != p[j] && p[j] != '.') {
                    if (j + 1 < p.size() && p[j + 1] == '*')
                        j += 2;
                    else
                        return false;
                }
                else {
                    if (j + 1 < p.size() && p[j + 1] == '*')
                        return isMatch(s.substr(i), p.substr(j + 2)) || isMatch(s.substr(i + 1), p.substr(j)) || isMatch(s.substr(i + 1), p.substr(j + 2));
                    else {
                        i++; j++;
                    }
                }
            }
            else {
                if (j + 1 < p.size() && p[j + 1] == '*')
                    return isMatch(s.substr(i), p.substr(j + 2));
                else
                    return false;
            }
        }
        return i >= s.size() && j >= p.size();
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    Solution s;
    cout << " the ans: " << s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
    return 0;
}


Time Limit Exceeded
46/447 cases passed (N/A)