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
    map<pair<int, int>, bool> cache;
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        return isMatchItem(s, p, i, j);
    }
    bool isMatchItem(string& s, string& p, int i, int j) {
        if (cache.find(make_pair(i,j)) != cache.end())
            return cache[make_pair(i,j)];
        if (i <= s.size() && j < p.size()) {
            if (i == s.size() || s[i] != p[j] && p[j] != '.') {
                if (j + 1 < p.size() && p[j + 1] == '*') 
                    cache[make_pair(i, j)] = isMatchItem(s, p, i, j + 2);
                    return cache[make_pair(i, j)];
            }else {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    cache[make_pair(i,j)] = isMatchItem(s, p, i, j + 2) || 
                           isMatchItem(s, p, i + 1, j);
                    return cache[make_pair(i,j)];
                }
                else {
                    cache[make_pair(i,j)] = isMatchItem(s, p, i + 1, j + 1);
                    return cache[make_pair(i,j)];
                }
            }
        }
        return i >= s.size() && j >= p.size();
    }
};
// @lc code=end

Accepted
447/447 cases passed (4 ms)
Your runtime beats 91.43 % of cpp submissions
Your memory usage beats 5.03 % of cpp submissions (16.2 MB)