/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (auto &&i : s1) { need[i]++; }
        int l = 0, r = 0, valid = 0; // valid: 记录多少个不同的字符
        while (r < s2.size()) {
            char c = s2[r]; // 当前处理字符
            if (need.count(c) > 0) {
                window[c]++;
                valid += window[c] == need[c] ? 1 : 0;
            }
            r++;
            if (r - l == s1.size()) { //窗口最大s1.size()字符 最多能放need.size()个不同字符
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[l]; // 要删除字符
                l++;
                if (need.count(d) > 0) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

