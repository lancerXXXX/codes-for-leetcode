// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem6.h"

using namespace std;
// @before-stub-for-debug-end

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

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> vs(numRows, "");
        for (int i = 0; i < s.size(); i++) {
            int index_in_group = i % (2 * numRows - 2); // index in a group
            vs[index_in_group <= numRows - 1 ? index_in_group : numRows - 2 - (index_in_group - numRows)] += s[i];
        }
        string ans = "";
        for (auto&& i : vs)
            ans += i;
        return ans;
    }
};
// @lc code=end

1157/1157 cases passed (8 ms)
Your runtime beats 90.36 % of cpp submissions
Your memory usage beats 40.25 % of cpp submissions (10.6 MB)