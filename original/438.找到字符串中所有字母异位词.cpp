// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> need, window;
        for (auto&& i : p) { need[i]++; }
        int left = 0, right = 0, num = 0;
        while (right < s.size()) {
            char c = s[right]; // 当前处理的字符
            if (need.count(s[right]) > 0) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    num++;
                }
            }
            right++;
            if (right - left == p.size()) {
                if (num == need.size()) {
                    ans.push_back(left);
                }
                if (need.count(s[left]) > 0) {
                    if (window[s[left]] == need[s[left]]) {
                        num--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const* argv[]) {
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
    return 0;
}

