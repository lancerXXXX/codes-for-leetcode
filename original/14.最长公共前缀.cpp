// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem14.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        bool flag = true;
        int length = 0;
        for (int col = 0;flag; col++) {
            for (int row = 0; row < strs.size() && flag; row++)
                flag = flag && col < strs[row].size() && strs[row][col] == strs[row > 0 ? row - 1 : row][col];
            length += flag ? 1 : 0;
        }
        return strs[0].substr(0, length);
    }
};
// @lc code=end

