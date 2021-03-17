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

#include "../TreeNode.h"
#include "../ListNode.h"

using namespace std;

// @lc code=start
class Solution {
private:
    unordered_map<char, int> ut;
    unordered_map<char, int> um;
public:
    string minWindow(string s, string t) {
        for (auto&& i : t) {
            ut[i]++;
        }
        int l = 0, r = 0 , ans_l = 0, ans_length = 0;
        while (r < s.size()) {
            if (!done()) {
                if (ut.count(s[r]) > 0) {
                    um[s[r]]++;
                }
                while (done()) {
                    if (ut.count(s[l]) > 0) {
                        um[s[l]]--;
                    }
                    if (ans_length == 0 || ans_length > r - l + 1) {
                        ans_l = l;
                        ans_length = r - l + 1 ;
                    }
                    l++;
                }
                r++;
            }
        }
        return s.substr(ans_l, ans_length);
    }
    bool done() {
        for (auto&& i : ut) {
            if (um[i.first] < i.second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

