/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
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
    string intToRoman(int num) {
        string ans = "";
        pair<int, string> Roma_char[] = {
                                        make_pair(1000, "M"),
                                        make_pair(900, "CM"),
                                        make_pair(500, "D"),
                                        make_pair(400, "CD"),
                                        make_pair(100, "C"),
                                        make_pair(90, "XC"),
                                        make_pair(50, "L"),
                                        make_pair(40, "XL"),
                                        make_pair(10, "X"),
                                        make_pair(9, "IX"),
                                        make_pair(5, "V"),
                                        make_pair(4, "IV"),
                                        make_pair(1,"I") ,
        };
        for (auto&& i : Roma_char) {
            int ch_num = num / i.first;
            num %= i.first;
            for (int j = 0; j < ch_num; j++)
                ans += i.second;
        }
        return ans;
    }
};
// @lc code=end

Accepted
3999/3999 cases passed (8 ms)
Your runtime beats 72.01 % of cpp submissions
Your memory usage beats 95.83 % of cpp submissions (5.7 MB)
