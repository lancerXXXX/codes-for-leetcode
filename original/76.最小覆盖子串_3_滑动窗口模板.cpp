/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto &&i : t) { need[i]++; }
        int l = 0, r = 0, valid = 0;
        int start = 0, len = INT32_MAX;
        while (r < s.size()) {
            char c = s[r];  // 当前字符
            r++;
            if (need.count(c) > 0) {  // 是否添加
                window[c]++;
                if (window[c] == need[c])
                    valid++;
            }
            while (valid == need.size()) { // 是否构成答案(收缩到不符合->寻找下一个答案)
                if (r - l < len) {
                    start = l; len = r - l;
                }
                char d = s[l];// 需要删除字符
                l++;
                if (need.count(d) > 0) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

