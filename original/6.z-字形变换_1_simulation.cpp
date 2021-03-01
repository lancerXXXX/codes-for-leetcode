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
        if (numRows == 1)
            return s;
        int group_num = (2 * numRows - 2);
        int col_group = (s.size() / group_num);
        int least = (s.size() % group_num);

        int col_max = col_group * (numRows - 1) + (least > 0) + (least - numRows> 0 ? least - numRows : 0);
        string ans = "";
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < col_max; col++) {
                if (col % (numRows - 1) == 0 && (col * 2 + row) < s.size())
                    ans += s[col * 2 + row];
                else if (col % (numRows - 1) != 0 && numRows - 1 - row == col % (numRows - 1) && ((col - col % (numRows - 1)) * 2 + numRows - 1 + col % (numRows - 1)) < s.size())
                    ans += s[(col - col % (numRows - 1)) * 2 + numRows - 1 + col % (numRows - 1)];
            }
        }
        return ans;
    }
};
// @lc code=end

Accepted
1157/1157 cases passed (28 ms)
Your runtime beats 21.47 % of cpp submissions
Your memory usage beats 93.4 % of cpp submissions (8 MB)

O(n^2)