/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
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
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> vs(numRows, "");
        bool down = false;
        for (int i = 0, ptr = 0; i < s.size(); i++) {
            down = ptr == 0 || ptr == numRows - 1 ? !down : down;
            vs[down ? ptr++ : ptr--] += s[i];
        }
        string ans = "";
        for (auto&& i : vs)
            ans += i;
        return ans;
    }
};

// @lc code=end

1157/1157 cases passed (4 ms)
Your runtime beats 98.5 % of cpp submissions
Your memory usage beats 41.9 % of cpp submissions (10.6 MB)