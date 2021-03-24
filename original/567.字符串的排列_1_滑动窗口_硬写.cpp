// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem567.h"

using namespace std;
// @before-stub-for-debug-end

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
private:
    unordered_map<char, int> template_map;
    unordered_map<char, int> work_map;
public:
    bool checkInclusion(string s1, string s2) {
        for (auto&& i : s1) {
            template_map[i]++;
        }
        int l = 0, r = 0;
        while (r < s2.size()) {
            if (template_map.count(s2[r]) > 0) {
                if (work_map[s2[r]] < template_map[s2[r]]) {
                    work_map[s2[r]]++;
                    if (check()) return true;
                    r++;
                }
                else {
                    while (true) {
                        work_map[s2[l]]--;
                        l++;
                        if (s2[l - 1] == s2[r]) { break; }
                    }
                }
            }
            else {
                r++;
                l = r;
                for (auto&& i : work_map) {
                    i.second = 0;
                }
            }
        }
        return false;
    }
    bool check() {
        for (auto&& i : template_map) {
            if (work_map[i.first] < i.second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

