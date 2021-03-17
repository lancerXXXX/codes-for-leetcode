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
        for (auto&& i : t) {
            um[i] = 0;
        }
        string ans;
        for (int l = 0, r = 0; r < s.size(); ) {
            if (!done()) {
                auto it = um.find(s[r]);
                if (it != um.end()) {
                    it->second++;
                }
                while (done()) {
                    auto it = um.find(s[l]);
                    if (it != um.end()) {
                        it->second--;
                    }
                    if (ans.size() == 0 || ans.size() > r - l + 1) {
                        ans = s.substr(l, r - l + 1);
                    }
                    l++;
                }
                r++;
            }
        }
        return ans;
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

